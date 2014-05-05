#include "StaticTextures.h"
extern SDL_Renderer *ren;

StaticTextures::StaticTextures(int _he,SDL_Texture* _Texture,int _h,int _w, int _x, int _y)
	:
	Objects(_Texture,_h, _w, _x,_y, 'N'),	health(_he)
{
}


StaticTextures::~StaticTextures(void)
{
}

bool StaticTextures::am_i_dead()
{
	if (health>0) return false;
	explosion();
	return true;
}
void StaticTextures::Draw()
{
	SDL_RenderCopyEx(ren, Texture, NULL,&Rect,0.0, NULL, SDL_FLIP_NONE);

}
void StaticTextures::explosion()
{
	SDL_Rect exp;
	exp=Rect;
	exp.w=exp.h;	
	SDL_RenderCopy(ren, IMG_LoadTexture(ren,"explosion.png"), NULL, &exp);
}