#pragma once
#include "Object.h"


class Brick : public Object
{
public:
	Brick(float, float);
	void DestroyBrick();
	void Move() override;

private:
	int m_health;
};

