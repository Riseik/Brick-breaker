#pragma once
#include "Object.h"


class Platform : public Object
{
public:
	Platform(float x, float y);
	void Move(float, float) override;
};

