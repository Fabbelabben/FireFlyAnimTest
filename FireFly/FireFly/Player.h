#pragma once
#include "Entity.h"
#include "Animation.h"

class Player : public Entity
{
public:
	Player(float positionX, float positionY);
	~Player();
	void updateEntity(sf:: Time timePerFrame);
	void drawEntity(sf::RenderWindow *window);
private:
	Animation plyr;
	float moveSpeed;
	sf::Listener playerListener;
};

