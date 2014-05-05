#pragma once
#include "Objects.h"
#include "Project.h"

class tanks : public Objects
{
friend class bullets;
protected:
	int health; //здоровье
	int speed; //скорость
	int angle; //угол, от вертикали по часовой в градусах
	void fire(); //выстрел (создание новой пули и задание ей направления и скорости)
	void explosion(); //взрыыыыыыв
	double t0;
public:
	bool am_i_dead(); // вернёт true если здороья ноль или меньше, в остальных false
	void moveTo(char dir); //отвечает за движение
	tanks(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y,char _whos); //конструктор
	~tanks(void);
	void Draw(void); //отрисовка, у наследников меняется
};

