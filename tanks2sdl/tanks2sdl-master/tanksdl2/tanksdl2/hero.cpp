#include "hero.h"
#include "tanks.h"
#include "Project.h"
extern SDL_Renderer *ren;



hero::hero(int _he, int _s, int _a, SDL_Texture* _Texture, int _h, int _w, int _x, int _y)
	:tanks(_he, _s, _a, _Texture, _h, _w,  _x, _y, 'H')
{
	t0 = clock()/double(CLOCKS_PER_SEC); // время после последнего выстрела 
}


hero::~hero(void) {}



void hero::Draw(void)
{
	//SDL_Point p;
	//p.x = tank_W / 2;   // зачем перменная p, если она не используется ?? *Это у тебя в квадратных текстурах не используется, а в прямоугольных поворачивать так то надо относительно чего то
	//p.y = tank_H / 2;
	SDL_RenderCopyEx(ren, Texture, NULL, &Rect, double(angle), NULL, SDL_FLIP_NONE);	
}
