#include <algorithm>
#include <stdio.h>
#include "bottanks.h"
#include "tanks.h"
#include "StaticTextures.h"
extern SDL_Renderer *ren;
extern list<StaticTextures*> tex;
extern list<tanks*> t;
extern int Hero_X, Hero_Y;

bottanks::bottanks(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y)
	:	tanks(_he, _s, _a,_Texture,_h,_w, _x, _y,'B')
{

}


bottanks::~bottanks(void)
{
}

void bottanks::Draw()
{
	randmove();
	SDL_Point p;	
	p.x=tank_W/2;
	p.y=tank_H/2;
	SDL_RenderCopyEx(ren, Texture, NULL,&Rect,double(angle), NULL, SDL_FLIP_NONE);

}



void bottanks::randmove()
{
	double current_t = clock()/double(CLOCKS_PER_SEC);
	int r=rand() % 6;
	if (r==2)
	{
	
		if(current_t-t0 > 0.5)
		{
			fire();
			t0 = clock()/double(CLOCKS_PER_SEC);
		}
	}
}