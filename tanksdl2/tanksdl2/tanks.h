#pragma once
#include "objects.h"
#include "bullets.h"
#include "StaticTextures.h"
class tanks : public Objects
{
	friend class bullets;
protected:
	int health; //��������
	int speed; //��������
	int angle; //����, �� ��������� �� ������� � ��������
	void fire(); //������� (�������� ����� ���� � ������� �� ����������� � ��������)
	void explosion(); //����������
public:
	bool am_i_dead(); // ������ true ���� ������� ���� ��� ������, � ��������� false
	void moveTo(char dir); //�������� �� ��������
	tanks(int _he, int _s, int _a,SDL_Texture* _Texture,int _h,int _w, int _x, int _y,char _whos); //�����������
	~tanks(void);
	virtual void Draw(void); //���������, � ����������� ��������
};

