#include "tanks.h"
#include "Objects.h"
#include "bullets.h"
#include "StaticTextures.h"
extern SDL_Renderer *ren;
extern list<bullets*> b;


tanks::tanks(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y, char _whos)
	:	Objects(_Texture,_h, _w, _x,_y, _whos),	health(_he), speed(_s),angle(_a)
{
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

void tanks::moveTo(char dir)
{

	double current_t;
	//if (current_t-t0<0.2)	Sleep((0.2-(current_t-t0))*1000);
	if (dir == 'u') 
	{
		Rect.y -= speed;
		angle = 0;		
	}
	if (dir == 'd') 
	{
		Rect.y += speed;
		angle = 180;	
	}
	if (dir == 'l') 
	{
		Rect.x -= speed;
		angle = 270;		
	}

	if (dir == 'r') 
	{
		Rect.x += speed;
		angle = 90;
	}
	if (dir == 'f') 
	{
 		current_t = clock()/double(CLOCKS_PER_SEC);
		if(current_t-t0 > 0.5)
		{
			fire();
			t0 = clock()/double(CLOCKS_PER_SEC);
		}
	}
	//angle = angle % 360;
	//t0=clock()/double(CLOCKS_PER_SEC);
}