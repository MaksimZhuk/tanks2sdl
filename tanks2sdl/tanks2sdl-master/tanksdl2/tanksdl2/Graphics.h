#pragma once
#include "Project.h" //инициализирует СДЛ
class Graphics
{
private:
	SDL_Texture *backgroundT;
	SDL_Rect rect;
	void instal_sdl();
public:
	void draw_BG();
	SDL_Window *win;
	SDL_DisplayMode displayMode;
	Graphics(void);
	~Graphics(void);
};

