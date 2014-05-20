#pragma once
#include "Graphics.h"
extern SDL_Renderer *ren;

Graphics::Graphics(void)
{
	instal_sdl();
	backgroundT = IMG_LoadTexture(ren, "image/background.png");
	rect.x = 0;   //�������� ������� �� �
	rect.y = 0;   //�������� ������� �� Y
	rect.w = X_disp; //������ �������
	rect.h = Y_disp; //������ �������
}


Graphics::~Graphics(void)
{
}
void Graphics::instal_sdl()
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}
	int request = SDL_GetDesktopDisplayMode(0,&displayMode);

	win = SDL_CreateWindow("Tanks!", 340, 35, X_disp, Y_disp, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}
}

void Graphics::draw_BG()
{
	SDL_RenderCopy(ren, backgroundT, NULL, &rect);
}