#pragma once
#include "objects.h"

class StaticTextures :	public Objects
{
	friend class bullets;
public:
	void explosion();
	void Draw();
	bool am_i_dead(); // вернёт true если здороья ноль или меньше, в остальных false
	StaticTextures(int _he,SDL_Texture* _Texture,int _h,int _w, int _x, int _y);
	~StaticTextures(void);
private:
	int health;
};

