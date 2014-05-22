#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <cstring>
#include <time.h>


void instal_text_mode();			//включает текстовый режим библиотеки SDL2
TTF_Font* load();					//загружает шрифт(лежит в папке проета)
void draw_message(TTF_Font* font, const char* a, int x, int y, int size); //выводит сообщение
void start_screen(SDL_Event* events, bool* quit,bool* status);
void finish_screen(SDL_Event* events, bool* quit);
void message(const char* a, int x, int y, int size);