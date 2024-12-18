#pragma once
#include "Object.h"


class Brick : public Object
{
public:
	Brick();
	Brick(float, float);
	~Brick();

	bool BrickDamage();
	void Destroy();
	void Move(float, float) override;

private:
	int m_health = 1;
};

