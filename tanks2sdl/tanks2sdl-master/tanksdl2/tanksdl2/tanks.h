#pragma once
#include "Objects.h"
#include "Project.h"

class tanks : public Objects
{
friend class bullets;
friend class Level;
protected:
	int health; //здоровье
	int speed; //скорость
	int angle; //угол, от вертикали по часовой в градусах
	void fire(); //выстрел (создание новой пули и задание ей направления и скорости)
	void explosion(); //взрыыыыыыв
	double t0;
public:
	void bottanks_step();
	bool am_i_dead(); // вернёт true если здороья ноль или меньше, в остальных false
	bool moveTo(char dir); //отвечает за движение
	bool moveCheck(char dir); // проверяет можно ли ехать в этом направлении
	tanks(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y,char _whos); //конструктор
	~tanks(void);
	void Draw(void); //отрисовка, у наследников меняется
};

