#include "Level.h"
#include "Project.h"
#include "hero.h"
#include "StaticTextures.h"
#include "bottanks.h"
#include "objects.h"
#include <fstream>
extern list<bullets*> b;
extern SDL_Renderer *ren;

void Level::scan_file(const char* a)
{
	SDL_Point point;
	point.x=0;
	point.y=0;
	ifstream in; 
	in.open(a);
	char d;
	int x=0,y=0;
	while(in>>d)
	{
		
		if(d=='$')
		{
			point.x=x;
			point.y=y;
			respawn.push_back(new SDL_Point(point));
		}
		if(d=='@')
			tex.push_back(new StaticTextures(20, IMG_LoadTexture(ren,"image/block_9.png"), text_H,text_W, x, y));
		if(d=='1')
		{
			y+=text_H;
			x=0;
			x-=text_W;
		}
		x+=text_W;
		
	}
	
}

void Level::add_tanks()
{
	for(list<SDL_Point*>::iterator i=respawn.begin(); i!=respawn.end(); i++)
		t.push_back(new bottanks(10, 20, (rand() % 4)*90, IMG_LoadTexture(ren,"image/battlecity_enemy1.png"), tank_H, tank_W, (*i)->x, (*i)->y));
}

Level::Level(const char* a)
	:Hero(10, 5, 90, IMG_LoadTexture(ren, "image/battlecity_playerA1.png"), tank_H, tank_W, 90, 100) 
{
	scan_file(a);
	t.push_back(&Hero); 
	add_tanks();

}


Level::~Level()
{
}

void Level::watch_textures()
{
	list<StaticTextures*>::iterator m;
	for(list<StaticTextures*>::iterator i=tex.begin(); i!=tex.end(); i++)
	{
		(*i)->Draw();
		if((*i)->am_i_dead())  // проверка на удаление текстуры
		{ 
			m=i;  
			m++;
			tex.erase(i);
			i=m;
			i--;
		}
	}
}
void Level::watch_tanks()
{
	list<tanks*>::iterator k;
	for(list<tanks*>::iterator i=t.begin(); i!=t.end(); i++)
	{
		(*i)->Draw();
		if((*i)->am_i_dead())  // проверка на смерть танка
		{ 
			k=i;  
			k++;
			t.erase(i);
			i=k;
			i--;
		}
	}

}

void Level::watch_bullets()
{
	list<bullets*>::iterator j;
	for(list<bullets*>::iterator i=b.begin(); i!=b.end(); i++)
	{

		(*i)->Draw(); //функция отрисовки (сичтает смещение и подаёт в буфер)
		if((*i)->dead_check() || (*i)->strike(&tex,&t))  // проверка на вылет за экран и на попадание в объект(пока что танки)
		{ 
			j=i;  
			j++;
			b.erase(i);
			i=j;
			i--;
		}			 
	}
}