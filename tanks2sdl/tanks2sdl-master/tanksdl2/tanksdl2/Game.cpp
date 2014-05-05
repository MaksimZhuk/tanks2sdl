#include "Game.h"
#include "Project.h"
#include "hero.h"
#include "StaticTextures.h"
#include "bottanks.h"
#include "Level.h"
extern SDL_Renderer *ren;
extern list<tanks*> t;

void get_event(const Uint8 *keyboardState, SDL_Event* events, hero* Hero, bool* quit)
{
	int t = clock();					//���������� ��������� � ����� ��������� ����������� ������ ��������
	SDL_WaitEventTimeout(events, 100);
	t=clock()-t;
	Sleep(abs(100-t));

	SDL_PollEvent(events); //������ ������� �� �������
	SDL_PumpEvents(); 

	if(events->type == SDL_QUIT) 
		*quit=true; 
	if((keyboardState[SDL_SCANCODE_ESCAPE]))   
		*quit=true; 	
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

	if((keyboardState[SDL_SCANCODE_SPACE]))
		Hero->moveTo('f');

}







void game(Graphics* grafika)
{

	Level level1("levels/1.txt");
	

	//������ ������� ��� ��������� �������
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	bool quit = false;
	//


	while(!quit) //����������� ���� ��������� �������
	{
		SDL_RenderClear(ren); //������� �����
		grafika->draw_BG(); //���������� ���
		get_event(keyboardState, &event, &level1.Hero, &quit); //������������  ����� � ������� ������	
		level1.watch_tanks(); //��������� �� ������ ������, ���� ������ � �����.����� � �������. � ������ ������� ���� �������  draw 
		level1.watch_textures();	//��������� �� ���������. �������, ���� ����.
		level1.watch_bullets(); //��������� �� ���� �����. �������, �� ��� ������, ��� �������� ��� ���������
		SDL_RenderPresent(ren); //����� �� �����
	}
	SDL_RenderClear(ren); //������� �������

}