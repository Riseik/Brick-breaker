#pragma once
#include "Object.h"
#include "globals.h"

class Ball : public Object
{
public: 
	Ball();
	~Ball();
	void CheckScreenCollision();
	void CheckPlatformCollision(sf::Sprite spritePlatform);
	bool CheckBrickCollision(sf::Vector2f posBrick, sf::Vector2i sizeBrick);
	void Move();
	void Move(float, float) override;

private:
	sf::Vector2f m_speed = { BALL_SPEED_X, BALL_SPEED_Y };
};

