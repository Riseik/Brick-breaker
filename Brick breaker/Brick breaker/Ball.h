#pragma once
#include "Object.h"
#include "AllInclude.h"
#include "Brick.h"

class Ball : public Object
{
public: 
	Ball();
	~Ball();
	void CheckScreenCollision();
	void CheckPlatformCollision(sf::Sprite spritePlatform);
	bool CheckBrickCollision(Brick* brick);
	void Move();
	void Move(float, float) override;

private:
	sf::Vector2f m_speed = { BALL_SPEED_X, BALL_SPEED_Y };
};

