#pragma once
#include "Project.h"

class Objects
{
protected: 
	char whos; //показывает, принадлежность объекта N, H, B соответственно (нейтральный, герой, бот) нужно, для отключения френдли фаера
	SDL_Rect Rect; //координаты и ширина с высотой
	SDL_Texture* Texture; //текстура
public:
	Objects(SDL_Texture* _Texture, int _h,int _w, int _x, int _y, char _whos);
	~Objects(void);
	virtual void Draw(void);
	virtual bool am_i_dead();// вернёт true если здороья ноль или меньше, в остальных false
};

