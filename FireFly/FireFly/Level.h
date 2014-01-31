#pragma once
#include "EntityList.h"
#include "Player.h"
#include "Mal.h"

class Level
{
public:
	static Level &getLevel();
	void startLevel0();
private:
	Level();
	~Level();
	void operator=(const Level &level);
	static Level level;
};
