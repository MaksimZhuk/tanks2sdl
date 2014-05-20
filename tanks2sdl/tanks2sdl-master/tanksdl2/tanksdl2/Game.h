#pragma once
#include "Project.h"
#include "Graphics.h"
#include "hero.h"

void game(Graphics* grafika);
void get_event(const Uint8 *keyboardState, SDL_Event event, hero* Hero, bool* quit, bool* status);
//void check_gameover(list<tanks*>::iterator h,bool* quit, bool* status);

