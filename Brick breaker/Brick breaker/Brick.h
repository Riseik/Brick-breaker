#pragma once
#include "Object.h"


class Brick : public Object
{
public:
	Brick();
	Brick(float, float);
	void DestroyBrick();
	void Move(float, float) override;

private:
	int m_health;
};

