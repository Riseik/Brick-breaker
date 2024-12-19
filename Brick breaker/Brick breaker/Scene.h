#pragma once
#include "globals.h"
#include "Brick.h"
class Scene
{
private:
	std::vector<Brick*>  s_Bricks ;


public:
	Scene();
	~Scene();
	void LoadScene();
	void CreateBricks();

	std::vector<Brick*>* GetBrick();

};

