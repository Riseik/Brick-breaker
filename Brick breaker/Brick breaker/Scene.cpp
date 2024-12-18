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
		for (int i = 0; i < (WINDOW_WIDTH / BRICK_WIDTH)-1; i++) {
			s_Bricks.at(i).Move(x, y);
			x= i*BRICK_WIDTH;
		}
		y += j*BRICK_HEIGHT;
	}
}

Brick* Scene::GetBrick(int pos)
{
	return &s_Bricks.at(pos);
}

void Scene::DrawBrick(sf::RenderWindow* window)
{
	for (Brick a : s_Bricks)
		window->draw(a.GetSprite());
}
