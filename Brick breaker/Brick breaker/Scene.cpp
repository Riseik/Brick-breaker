#include "Scene.h"


Scene::Scene()
{
	
}

Scene::~Scene()
{

}

void Scene::LoadScene()
{

}

void Scene::CreateBricks()
{
	for (int i = 0; i < NUMBERBRICK; i++) {
		s_Bricks[i] = Brick(10, 10);
	}

	
}
