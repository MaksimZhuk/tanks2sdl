#pragma once
#include "StaticTextures.h"
#include "Project.h"
#include "tanks.h"
#include "bullets.h"
#include "hero.h"
#include <list>
using namespace std;
class Level
{
private: void scan_file(const char * a);
		 void add_tanks();
		 list<SDL_Point*> respawn;
		 list<tanks*> t;
public:
	void watch_textures();
	void watch_tanks();
	void watch_bullets();
	list<StaticTextures*> tex;
	hero Hero;
	Level(const char* a);
	~Level();
};

