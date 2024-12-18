#include "Scene.h"
#include"AllInclude.h"

Scene::Scene()
{
	CreateBricks();
}

Scene::~Scene()
{

}

void Scene::LoadScene()
{

}

void Scene::CreateBricks()
{
	int x = 0;
	int y = 0;
	for (int j = 0; j < NUMBERBRICK / (WINDOW_WIDTH / BRICK_WIDTH); j++) {
		for (int i = 0; i < WINDOW_WIDTH / BRICK_WIDTH; i++) {
			Brick b = Brick(x, y);
			s_Bricks.at(i) = b ;
			x= i*BRICK_WIDTH;
		}
		y += j*BRICK_HEIGHT;
	}
}

std::array<Brick, 40>* Scene::GetBrick()
{
	return &s_Bricks;
}
