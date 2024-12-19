#include "Scene.h"
#include "globals.h"

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
	for (int i = 0; i < NUMBERBRICK; i++) {
		if (x >= WINDOW_WIDTH) {
			x = 0;
			y += BRICK_HEIGHT ;
		}
		s_Bricks.push_back( new Brick(x, y));
		x += BRICK_WIDTH;
	}
	//for (int j = 0; j < 10; j++) {
	//	for (int i = 0; i < (WINDOW_WIDTH / BRICK_WIDTH)-1; i++) {
	//		int pos = i + (j * ((WINDOW_WIDTH / BRICK_WIDTH) - 1));
	//		s_Bricks.at(pos) = new Brick(x, y);
	//		x= i*BRICK_WIDTH;
	//	}
	//	y += j*BRICK_HEIGHT;
	//}
}

std::vector<Brick*>* Scene::GetBrick()
{
	return &s_Bricks;
}
