#pragma once
#include "StaticTextures.h"
#include "Project.h"
#include "tanks.h"
#include "bullets.h"
#include "hero.h"
#include <list>
using namespace std;
struct resp
{
	SDL_Point respawn;
	int type;
};

class Level
{
	friend class tanks;
private: void scan_file(const char * a);
		 void add_tanks();
		 list<resp*> respawn;
//		 list<tanks*> t;
		 
public:
	void watch_textures();
	void watch_tanks();
	void watch_bullets();
	double t_step;
	hero Hero;
	Level(const char* a);
	~Level();
};

