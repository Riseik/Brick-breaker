#pragma once
#include "Object.h"


class Platform : public Object
{
public:
	Platform();
	Platform(float x, float y);
	~Platform();
	void Move(float, float) override;
};

