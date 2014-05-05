#include "Project.h"
#include "Graphics.h"
#include "tanks.h"
#include "bullets.h"
#include "StaticTextures.h"
#include "hero.h"
#include "bottanks.h"
#include "Game.h"
												
SDL_Renderer *ren; //������										
list<bullets*> b;
//list<tanks*> t;



int main(int argc, char* args[])
{
	srand(time(NULL));
	Graphics grafika; //������ ��������� ������, ����������� �� ������������� ��� � ������������� ���,�������������� ��
	game(&grafika);
	

	// ���������� ������
	b.clear();
	//tex.clear();
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(grafika.win);
	SDL_Quit();

	return 0;
}



