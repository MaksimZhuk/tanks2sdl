#pragma once
#include "Project.h"


class Objects
{
public: 
	char whos; //����������, �������������� ������� N, H, B �������������� (�����������, �����, ���) �����, ��� ���������� ������� �����
	SDL_Rect Rect; //���������� � ������ � �������
	SDL_Texture* Texture; //��������
public:
	Objects(SDL_Texture* _Texture, int _h,int _w, int _x, int _y, char _whos);
	~Objects(void);
	virtual void Draw(void);
	virtual bool am_i_dead();// ����� true ���� ������� ���� ��� ������, � ��������� false
};

