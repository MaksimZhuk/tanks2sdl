#pragma once
#include <algorithm>
#include "tanks.h"
#include "Project.h"
#include "Objects.h"
#include "bullets.h"
#include "Level.h"
#include "hero.h"
#include "StaticTextures.h"
extern SDL_Renderer *ren;
extern list<bullets*> b;
extern list<StaticTextures*> tex;
extern list<tanks*> t;
extern int Hero_X, Hero_Y;


tanks::tanks(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y, char _whos)
	:	Objects(_Texture,_h, _w, _x,_y, _whos),	health(_he), speed(_s),angle(_a)
{
	t0 = clock()/double(CLOCKS_PER_SEC);
}

tanks::~tanks(void)
{
}


void tanks::explosion()
{
	SDL_Rect exp;
	exp = Rect;
	exp.w = exp.h;	
	SDL_RenderCopy(ren, IMG_LoadTexture(ren, "explosion.png"), NULL, &exp); // 
}


void tanks::Draw() {}

void tanks::fire()
{
	
	int xb, yb;
	switch (angle) {
	case 0:
		{
			xb = Rect.x + (double(tank_W) / 2.0) - (double(bullet_W) / 2.0);
			yb = Rect.y;
		} break;
	case 90:
		{
			xb = Rect.x + double(tank_W);
			yb = Rect.y + (double(tank_W) / 2.0) - (double(bullet_H) / 2.0);
		} break;
	case 180:
		{
			xb = Rect.x + (double(tank_W) / 2.0) - (double(bullet_W) / 2.0);
			yb = Rect.y + double(tank_W);
		} break;
	case 270:
		{
			xb = Rect.x;
			yb = Rect.y + (double(tank_W) / 2.0) - (double(bullet_H) / 2.0);
		} break;
	}
	b.push_back(new bullets(SPEED_BULLETS, angle, IMG_LoadTexture(ren,"image/fire.png"), bullet_H, bullet_W, xb, yb, whos));
}

bool tanks::am_i_dead()
{
	if (health > 0) return false;
	explosion();
	return true;
}



bool tanks::moveCheck(char dir)
{
	if (dir == 'u') 
	{
		int X = Rect.x, Y = Rect.y - speed;
		for(list<StaticTextures*>::iterator iter = tex.begin(); iter != tex.end(); iter++)
			if ( ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
		for(list<tanks*>::iterator iter = t.begin(); iter != t.end(); iter++)
			if (((*iter)->Rect.y != Rect.y && (*iter)->Rect.x != Rect.x ) && ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
	}
	if (dir == 'd') 
	{
		int X = Rect.x, Y = Rect.y + speed;
		for(list<StaticTextures*>::iterator iter = tex.begin(); iter != tex.end(); iter++)
			if ( ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
		for(list<tanks*>::iterator iter = t.begin(); iter != t.end(); iter++)
			if (((*iter)->Rect.y != Rect.y && (*iter)->Rect.x != Rect.x ) && ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
	}
	if (dir == 'l') 
	{
		int X = Rect.x - speed, Y = Rect.y;
		for(list<StaticTextures*>::iterator iter = tex.begin(); iter != tex.end(); iter++)
			if ( ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;	
		for(list<tanks*>::iterator iter = t.begin(); iter != t.end(); iter++)
			if (((*iter)->Rect.y != Rect.y && (*iter)->Rect.x != Rect.x ) && ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
	}

	if (dir == 'r') 
	{
		int X = Rect.x + speed, Y = Rect.y;
		for(list<StaticTextures*>::iterator iter = tex.begin(); iter != tex.end(); iter++)
			if ( ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
		for(list<tanks*>::iterator iter = t.begin(); iter != t.end(); iter++)
			if (((*iter)->Rect.y != Rect.y && (*iter)->Rect.x != Rect.x ) && ((*iter)->Rect.y + text_H > Y && (*iter)->Rect.y < Y + text_H) && ( (*iter)->Rect.x + text_W > X && (*iter)->Rect.x < X + text_W  ))
				return 0;
	}
	return 1;
}

bool tanks::moveTo(char dir)
{

	double current_t;
	//if (current_t-t0<0.2)	Sleep((0.2-(current_t-t0))*1000);
	if (dir == 'u') 
	{
		if ( moveCheck(dir))
			Rect.y -= speed;
		angle = 0;		
	}
	if (dir == 'd') 
	{
		if (moveCheck(dir))
			Rect.y += speed;
		angle = 180;	
	}
	if (dir == 'l') 
	{
		if (moveCheck(dir))
			Rect.x -= speed;
		angle = 270;		
	}

	if (dir == 'r' ) 
	{
		if (moveCheck(dir))
			Rect.x += speed;
		angle = 90;
	}
	if (dir == 'f') 
	{
 		current_t = clock()/double(CLOCKS_PER_SEC);
		if(current_t-t0 > 0.4)
		{
			fire();
			t0 = clock()/double(CLOCKS_PER_SEC);
		}
	}
	//angle = angle % 360;
	//t0=clock()/double(CLOCKS_PER_SEC);
	return 1;
}

