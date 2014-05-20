#include "Text.h"
#include <iostream>
#include "Project.h"
using namespace std;

extern SDL_Renderer *ren;

void instal_text_mode() //инициализируем текстовые службы
{
	if (TTF_Init()<0)
		{
		std::cout<<"Unable to initialize SDL_ttf:"<< TTF_GetError()<<std::endl;
		exit(-1);
		}
}

TTF_Font* load()		//загружаем шрифт 
{
	TTF_Font* font = TTF_OpenFont("font.ttf", 52);
	if (font == NULL) 
	{  
		std::cout<<"Unable to load font:"<< TTF_GetError()<<std::endl;
	}
return font;}


void draw_message(TTF_Font* font, const char* a, int x, int y, int size)
{
	SDL_Color White = {234, 10, 54};  
	SDL_Surface* surfaceMessage = NULL;
	surfaceMessage = TTF_RenderText_Solid(font, a, White);
	SDL_Texture* Message = NULL;
	Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = x;
	Message_rect.y = y;
	Message_rect.w = sizeof(a)/sizeof(char)*30*size;
	Message_rect.h =30*size;
	
	SDL_RenderCopy(ren, Message, NULL, &Message_rect);
}

void start_screen(SDL_Event* events, bool* quit)
{
	instal_text_mode();
	TTF_Font* font=load();

	while(true)
	{
		SDL_RenderClear(ren);
		draw_message(font, "Start!", X_disp/2-100, Y_disp/2-100, 2);
		draw_message(font, "Quit", X_disp/2-100, Y_disp/2+100, 1);
		SDL_RenderPresent(ren);

		SDL_PollEvent(events); //достаём событие из очереди
	    SDL_PumpEvents(); 
		if(events->type == SDL_MOUSEBUTTONDOWN){
			if ( ( (events->button.x>X_disp/2-100) && (events->button.x<X_disp/2+6*30*2-100) ) && ( (events->button.y>Y_disp/2-100) && (events->button.y<Y_disp/2+30*2-100) ) )
				break;
			if ( ( (events->button.x>X_disp/2-100) && (events->button.x<X_disp/2+4*30*2-100) ) && ( (events->button.y>Y_disp/2+100) && (events->button.y<Y_disp/2+30*2+100) ) )
			{
				*quit=true;
				break;
			}

		}
	}

}

void finish_screen(SDL_Event* events, bool* quit)
{
	TTF_Font* font=load();

	while(true)
	{
		//SDL_RenderClear(ren);
		draw_message(font, "Loser!", X_disp/2-100, Y_disp/2-100, 2);
		draw_message(font, "Quit", X_disp/2-100, Y_disp/2+100, 1);
		SDL_RenderPresent(ren);

		SDL_PollEvent(events); //достаём событие из очереди
	    SDL_PumpEvents(); 
		if(events->type == SDL_MOUSEBUTTONDOWN){
			
			if ( ( (events->button.x>X_disp/2-100) && (events->button.x<X_disp/2+4*30*2-100) ) && ( (events->button.y>Y_disp/2+100) && (events->button.y<Y_disp/2+30*2+100) ) )
			{
				*quit=true;
				break;
			}

		}
	}

}
void message(const char* a, int x, int y, int size)
{
	TTF_Font* font=load();
	draw_message(font, a, x, y, size);

}