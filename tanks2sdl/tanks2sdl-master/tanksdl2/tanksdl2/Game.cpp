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
	int t = clock();					//добиваемся плавности и чтобы нормально срабатывала кнопка закрытия
	SDL_WaitEventTimeout(events, 100);
	t=clock()-t;
	Sleep(abs(100-t));

	SDL_PollEvent(events); //достаём событие из очереди
	SDL_PumpEvents(); 

	if(events->type == SDL_QUIT) 
		*quit=true; 
	if((keyboardState[SDL_SCANCODE_ESCAPE]))   
		*quit=true; 	
	//считываем клавиатуру и подаем команду танку игрока
	// добавил else, чтобы не ездили по диагонале 
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
	

	//создаём объекты для обработки событий
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	SDL_Event event;
	bool quit = false;
	//


	while(!quit) //бесконечный цикл обработки событий
	{
		SDL_RenderClear(ren); //очищаем буфер
		grafika->draw_BG(); //отправляем фон
		get_event(keyboardState, &event, &level1.Hero, &quit); //обрабатываем  клаву и события игрока	
		level1.watch_tanks(); //пробегаем по списку танков, куда входит и герой.Ходим и умираем. У разных классов своя функция  draw 
		level1.watch_textures();	//пробегаем по текстурам. Умираем, если надо.
		level1.watch_bullets(); //пробегаем по всем пулям. Убиваем, во что попали, или исчезаем при отдалении
		SDL_RenderPresent(ren); //вывод на экран
	}
	SDL_RenderClear(ren); //Очистка рендера

}