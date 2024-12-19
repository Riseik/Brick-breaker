#pragma once
#include "globals.h"
#include "Brick.h"
class Scene
{
private:
	std::array<Brick*, NUMBERBRICK>  s_Bricks ;


public:
	Scene();
	~Scene();
	void LoadScene();
	void CreateBricks();

	Brick* GetBrick(int pos);
	void DrawBrick(sf::RenderWindow* window);

};

