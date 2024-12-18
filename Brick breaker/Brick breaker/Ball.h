#pragma once
#include "Object.h"

class Ball : public Object
{
public: 
	Ball();
	~Ball();
	void Move(float, float) override;

};

