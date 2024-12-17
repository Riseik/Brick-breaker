#pragma once
#include "Object.h"


class Brick : public Object
{
public:
	Brick(float, float);
	~Brick();

	bool BrickDamage();
	void Destroy();
	void Move(float, float) override;

private:
	int m_health;
};

