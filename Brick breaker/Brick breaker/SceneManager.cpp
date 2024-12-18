#include "SceneManager.h"

SceneManager::SceneManager()
{
	ball = Ball();
	platform = Platform();
	test = new Brick();
	CreateNextScene();
}

SceneManager::SceneManager(Ball* ballpt , Platform* platformpt)
{
	ball = Ball();
	platform = Platform();
	CreateNextScene();
}

SceneManager::~SceneManager()
{
}

void SceneManager::CreateNextScene()
{
	Scene a = Scene();
	sm_Order.push(a);
	sm_Order.back().CreateBricks();
}

void SceneManager::ChangeScene()
{
	sm_Order.pop();
	sm_Order.front().LoadScene();
}

Ball* SceneManager::GetBall()
{
	return &ball;
}

Platform* SceneManager::GetPlatform()
{
	return &platform;

}

Scene* SceneManager::GetActualScene()
{
	return &sm_Order.front();
}
