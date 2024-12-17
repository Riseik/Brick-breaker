#pragma once
#include "AllInclude.h"
class Brick;
class Scene
{
private:
	std::array<Brick,40> S_bricks;


public:
	Scene();
	~Scene();
	void LoadScene();
	void CreateBricks();




};

