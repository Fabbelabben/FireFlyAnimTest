#include "Animation.h"
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>


Animation::Animation(Textures::ID texture,
						unsigned int spriteWidth,
						unsigned int spriteHeight,
						unsigned int numberOfSprites,
						unsigned int framesPerSprite,
						unsigned int spriteRow,
						unsigned int xOffset,
						unsigned int yOffset) :
mNumberOfSprites(numberOfSprites),
mFramesPerSprite(framesPerSprite),
mSpriteWidth(spriteWidth),
mSpriteHeight(spriteHeight),
mCurrentFrame(0),
mCurrentSprite(0),
mSprite(Loading::getLoading().GetTexture(texture)),
mEndOfAnimation( false )
{
	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(0,0, spriteWidth, spriteHeight));
	mSprite.setOrigin( static_cast<float>(xOffset), static_cast<float>(yOffset) );
}

Animation::Animation(const Animation& animation) :
		mNumberOfSprites(animation.mNumberOfSprites),
		mFramesPerSprite(animation.mFramesPerSprite),
		mCurrentFrame(animation.mCurrentFrame),
		mCurrentSprite(animation.mCurrentSprite),
		mSpriteHeight(animation.mSpriteHeight),
		mSpriteWidth(animation.mSpriteWidth),
		mTexture(animation.mTexture),
		mSprite(animation.mSprite),
		mEndOfAnimation(animation.mEndOfAnimation)
{
}

Animation::~Animation(void)
{
}

sf::Sprite Animation::getCurrentSprite() const{
return mSprite;
}

void Animation::setPosition(const sf::Vector2f& position) {
mSprite.setPosition(position);
}

void Animation::updateAnimation()
{
	unsigned int left = mSpriteWidth * mCurrentSprite;
	unsigned int top = 0;
	mSprite.setTextureRect(sf::IntRect( left, top, mSpriteWidth, mSpriteHeight ) );
	++mCurrentFrame;
	if( mCurrentFrame >= mFramesPerSprite )
	{
		++mCurrentSprite;
		mCurrentFrame = 0;
		if(mCurrentSprite == mNumberOfSprites )
		{
			++top;
			mCurrentSprite = 0;
			mCurrentFrame = 0;
			if(top == mSpriteRow)
			{
				top = 0;
				resetAnimation();
//				mEndOfAnimation = true;
			}
//			else
//			{
//				mEndOfAnimation = false;
		}
		
	}
}

void Animation::resetAnimation(){
	mCurrentSprite= 0;
	mCurrentFrame = 0;
	mNumberOfSprites = 0;
}


bool Animation::endOfAnimation() const{
	return mEndOfAnimation;
}
	
	
	
	
	
//	loop = sf::milliseconds(frameTime);
//	if(frameClock.getElapsedTime() > loop)
//	{
//		frameClock.restart();
//	}