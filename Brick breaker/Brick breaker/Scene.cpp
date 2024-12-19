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
	for (int i = 0; i < NUMBERBRICK; i++) {
		if (x >= WINDOW_WIDTH) {
			x = 0;
			y += BRICK_HEIGHT - BRICK_HEIGHT * 0.1f;
		}
		s_Bricks.at(i) = new Brick(x, y);
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

Brick* Scene::GetBrick(int pos)
{
	return s_Bricks.at(pos);
}

void Scene::DrawBrick(sf::RenderWindow* window)
{
	for (Brick* a : s_Bricks)
		window->draw(a->GetSprite());
}
