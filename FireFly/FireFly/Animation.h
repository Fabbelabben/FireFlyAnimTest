#pragma once
#include "Loading.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Animation
{
public:
	
	Animation(Textures::ID fileName,
				unsigned int spriteWidth,
				unsigned int spriteHeight,
				unsigned int numberOfSprites,
				unsigned int framesPerSprite,
				unsigned int spriteRow,
				unsigned int xOffset,
				unsigned int yOffset);

	Animation(const Animation& animation);

	sf::Sprite getCurrentSprite() const;
	void setPosition(const sf::Vector2f& position);
	void resetAnimation();
	void updateAnimation();
	bool endOfAnimation() const;

	~Animation();
private:
	sf::Clock frameClock;
	sf::Time loop;
	sf::Sprite mSprite;
	sf::Texture mTexture;
	unsigned int mSpriteWidth;
	unsigned int mSpriteHeight;
	unsigned int mNumberOfSprites;
	unsigned int mFramesPerSprite;
	unsigned int mCurrentSprite;
	unsigned int mCurrentFrame;
	unsigned int mSpriteRow;
	bool mEndOfAnimation;
};

