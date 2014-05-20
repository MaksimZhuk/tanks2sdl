#include "Level.h"
#include "Project.h"
#include "hero.h"
#include "StaticTextures.h"
#include "bottanks.h"
#include "objects.h"
#include <fstream>

extern list<bullets*> b;
extern SDL_Renderer *ren;
extern list<StaticTextures*> tex;
extern list<tanks*> t;
extern int Hero_X, Hero_Y;


void Level::scan_file(const char* a)
{
	resp p;
	p.respawn.x=0;
	p.respawn.y=0;
	p.type=0;
	ifstream in; 
	in.open(a);
	char d;
	int x=0,y=0;
	t_step = clock()/double(CLOCKS_PER_SEC);
	while(in >> d)
	{
		
		if(d=='$')
		{
			p.respawn.x = x;
			p.respawn.y = y;
			p.type=1;
			respawn.push_back(new resp(p));
		}
		if(d=='#')
		{
			p.respawn.x = x;
			p.respawn.y = y;
			p.type=2;
			respawn.push_back(new resp(p));
		}

		if(d=='@')
			tex.push_back(new StaticTextures(20, IMG_LoadTexture(ren,"image/block_9.png"), text_H,text_W, x, y));
		if(d == '!')
			tex.push_back(new StaticTextures(150, IMG_LoadTexture(ren,"image/block_9_!.png"), text_H,text_W, x, y));
		if(d=='1')
		{
			y += text_H;
			x = 0;
			x -= text_W;
		}
		x += text_W;		
	}
	in.close();
}

void Level::add_tanks()
{
	for(list<resp*>::iterator i=respawn.begin(); i!=respawn.end(); i++)
		{
		if ((*i)->type==1)
			t.push_back(new bottanks(10, 3, (rand() % 4)*90, IMG_LoadTexture(ren, "image/battlecity_enemy1.png"), tank_H, tank_W, (*i)->respawn.x, (*i)->respawn.y));
		if ((*i)->type==2)
			t.push_back(new bottanks(10, 6, (rand() % 4)*90, IMG_LoadTexture(ren, "image/battlecity_enemy2.png"), tank_H, tank_W, (*i)->respawn.x, (*i)->respawn.y));
		}
	}

Level::Level(const char* a)
	:Hero(10, 5, 0, IMG_LoadTexture(ren, "image/battlecity_playerA1.png"), tank_H, tank_W, Hero_X, Hero_Y)  //respaun Hero
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
	list<tanks*>::iterator k = t.begin();
	
	(*k)->bottanks_step();	

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