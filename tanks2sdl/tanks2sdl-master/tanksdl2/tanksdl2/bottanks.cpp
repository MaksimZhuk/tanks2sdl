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

void bottanks::bottanks_step() 
{
	int n = text_N;
	int a[text_N][text_N];
	pair <int, char> step[4];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 0;


	for(list<StaticTextures*>::iterator iter = tex.begin(); iter != tex.end(); iter++)
		a[(*iter)->Rect.y / (text_H)][(*iter)->Rect.x / (text_W)] = MAX_INT;

	for(list<tanks*>::iterator iter = t.begin(); iter != t.end(); iter++)
		a[(*iter)->Rect.y / (text_H)][(*iter)->Rect.x / (text_W)] = MAX_INT+1;
	a[Hero_Y / text_H][Hero_X / text_W] = 1;
	int k = 1;
	bool flag = 0;
	while (!flag)
	{
		flag = 1;
		for (int i = 0; i < n; i++)
			for (int j =  0; j < n; j++)
				if (a[i][j] == k)
				{
					if (a[i-1][j] == 0) a[i-1][j] = k + 1;
					if (a[i+1][j] == 0) a[i+1][j] = k + 1;
					if (a[i][j-1] == 0) a[i][j-1] = k + 1;
					if (a[i][j+1] == 0) a[i][j+1] = k + 1;
					flag = 0;
				}
		k++;
	}
	
	step[0].second = 'u';
	step[1].second = 'd';
	step[2].second = 'l';
	step[3].second = 'r';
	for(list<tanks*>::iterator iter = t.begin(); iter != t.end(); iter++)
		if ((*iter)->Rect.x != Hero_X && (*iter)->Rect.y != Hero_Y)
		{
			int i = (*iter)->Rect.y / text_H, j = (*iter)->Rect.x / text_W;
			step[0].first = a[i-1][j];
			step[1].first = a[i+1][j];
			step[2].first = a[i][j-1];
			step[3].first = a[i][j+1];
			sort(step, step + 4);
			for (int var = 0; var < 4; var++)
			{
				if (step[var].first == 1)
				{
					(*iter)->moveTo(step[var].second);
					break;
				}
				if (step[var].first != MAX_INT && (*iter)->moveCheck(step[var].second)) 
				{
					(*iter)->moveTo(step[var].second);
					break;
				}
			
			}
			step[0].second = 'u';
			step[1].second = 'd';
			step[2].second = 'l';
			step[3].second = 'r';
		}	
}