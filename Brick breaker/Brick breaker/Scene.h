#pragma once
#include "AllInclude.h"
#include "Brick.h"
class Scene
{
private:
	std::array<Brick, 40>  s_Bricks ;


public:
	Scene();
	~Scene();
	void LoadScene();
	void CreateBricks();

	std::array<Brick, 40>* GetBrick();


};

