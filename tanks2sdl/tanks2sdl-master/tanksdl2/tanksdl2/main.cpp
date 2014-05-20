#include "Project.h"
#include "Graphics.h"
#include "tanks.h"
#include "bullets.h"
#include "StaticTextures.h"
#include "hero.h"
#include "bottanks.h"
#include "Game.h"
#include "SDL_ttf.h"
												
SDL_Renderer *ren; //рендер										
list<bullets*> b;
list<StaticTextures*> tex;
list<tanks*> t;
int Hero_X = 370, Hero_Y = 500;



int main(int argc, char* args[])
{
	srand(time(NULL));
	Graphics grafika; //создаём экземпляр класса, отвечающего за инициализацию СДЛ и нициализуруем его,инициализируем БГ
	game(&grafika);
	

	// завершение работы
	b.clear();
	//tex.clear();
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(grafika.win);
	SDL_Quit();
	TTF_Quit();

	return 0;
}



