#include "Game.h"
#include "Project.h"
#include "hero.h"
#include "StaticTextures.h"
#include "bottanks.h"
#include "Level.h"
//#include "screen.h"
#include "Text.h"
#include <list>
#include "tanks.h"
extern list<bullets*> b;
extern SDL_Renderer *ren;
extern list<tanks*> t;
extern list<StaticTextures*> tex;
extern int Hero_X, Hero_Y;

void check_gameover(list<tanks*>::iterator h,bool* quit, bool* status, SDL_Event* events)
{
	if ( (*h)->am_i_dead() )
		{
			*quit=true;
			*status=true;
			finish_screen(events, quit);
		}
	if ( (t._Mysize==1) && ((*h)->am_i_dead()==false) )
		{
			*quit=true;
			*status=false;
		}
}

void get_event(const Uint8 *keyboardState, SDL_Event* events, hero* Hero, bool* quit,bool* status)
{
	int t = clock();					//���������� ��������� � ����� ��������� ����������� ������ ��������
	SDL_WaitEventTimeout(events, 100);
	t=clock()-t;
	Sleep(abs(100-t));

	SDL_PollEvent(events); //������ ������� �� �������
	SDL_PumpEvents(); 

	if(events->type == SDL_QUIT) 
		{
			*quit=true;
			*status=true;
		}
	if((keyboardState[SDL_SCANCODE_ESCAPE]))   
		{
			*quit=true;
			*status=true;
		}
	//��������� ���������� � ������ ������� ����� ������
	// ������� else, ����� �� ������ �� ��������� 
	if((keyboardState[SDL_SCANCODE_UP]))   
		Hero->moveTo('u');		
	else
		if((keyboardState[SDL_SCANCODE_DOWN]))
			Hero->moveTo('d');
		else
			if((keyboardState[SDL_SCANCODE_LEFT]))
				Hero->moveTo('l');
			else
				if((keyboardState[SDL_SCANCODE_RIGHT]))
					Hero->moveTo('r');
	Hero_X = Hero->Rect.x;
	Hero_Y = Hero->Rect.y;

	if((keyboardState[SDL_SCANCODE_SPACE]))
		Hero->moveTo('f');

}

void game(Graphics* grafika)
{

	Level level1("levels/1_level.txt");
	
	

	//������ ������� ��� ��������� �������
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	bool quit = false;
	bool dead_status = false; //������ ���, ���� ����
	//
	
	start_screen(&event, &quit);

	while(!quit) //����������� ���� ��������� �������
	{
		SDL_RenderClear(ren); //������� �����
		grafika->draw_BG(); //���������� ���
		get_event(keyboardState, &event, &level1.Hero, &quit, &dead_status); //������������  ����� � ������� ������	
		level1.watch_tanks(); //��������� �� ������ ������, ���� ������ � �����.����� � �������. � ������ ������� ���� �������  draw 
		level1.watch_textures();	//��������� �� ���������. �������, ���� ����.
		level1.watch_bullets(); //��������� �� ���� �����. �������, �� ��� ������, ��� �������� ��� ���������
		SDL_RenderPresent(ren); //����� �� �����
		check_gameover(t.begin(), &quit, &dead_status, &event);
	}
	quit=false;
	t.clear();
	b.clear();
	tex.clear();
	if (dead_status!= true)
	{
		message("Level 2, FIGHT!", 200,200, 4);
		SDL_RenderPresent(ren);
		Sleep(1000);
		Hero_X=350;
		Hero_Y=400;
	}
	Level level2("levels/2_level.txt");

	while(!quit & !dead_status) //����������� ���� ��������� �������
	{
		SDL_RenderClear(ren); //������� �����
		grafika->draw_BG(); //���������� ���
		get_event(keyboardState, &event, &level2.Hero, &quit,&dead_status); //������������  ����� � ������� ������	
		level2.watch_tanks(); //��������� �� ������ ������, ���� ������ � �����.����� � �������. � ������ ������� ���� �������  draw 
		level2.watch_textures();	//��������� �� ���������. �������, ���� ����.
		level2.watch_bullets(); //��������� �� ���� �����. �������, �� ��� ������, ��� �������� ��� ���������
		SDL_RenderPresent(ren); //����� �� �����
		check_gameover(t.begin(), &quit, &dead_status, &event);
	}

	quit=false;
	t.clear();
	b.clear();
	tex.clear();
	
	if (dead_status!= true)
	{
		message("Level 3, FIGHT!", 200,200, 4);
		SDL_RenderPresent(ren);
		Sleep(1000);
		Hero_X=460;
		Hero_Y=400;
	}
	Level level3("levels/3_level.txt");
	while(!quit & !dead_status) //����������� ���� ��������� �������
	{
		SDL_RenderClear(ren); //������� �����
		grafika->draw_BG(); //���������� ���
		get_event(keyboardState, &event, &level3.Hero, &quit,&dead_status); //������������  ����� � ������� ������	
		level3.watch_tanks(); //��������� �� ������ ������, ���� ������ � �����.����� � �������. � ������ ������� ���� �������  draw 
		level3.watch_textures();	//��������� �� ���������. �������, ���� ����.
		level3.watch_bullets(); //��������� �� ���� �����. �������, �� ��� ������, ��� �������� ��� ���������
		SDL_RenderPresent(ren); //����� �� �����
		check_gameover(t.begin(), &quit, &dead_status, &event);
	}
	SDL_RenderClear(ren); //������� �������

}