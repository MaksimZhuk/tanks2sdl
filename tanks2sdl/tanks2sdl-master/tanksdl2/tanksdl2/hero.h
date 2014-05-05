#pragma once
#include "tanks.h"
class hero :
	public tanks
{
	friend class bottanks;
protected: 
	

public:
	void Draw(); //отрисовка
	hero(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y);
	~hero(void);
};

