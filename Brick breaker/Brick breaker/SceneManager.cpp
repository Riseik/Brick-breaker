#include "SceneManager.h"

SceneManager::SceneManager()
{
	ball = Ball();
	platform = Platform();
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
	Scene b = Scene();
	sm_Order.push(a);
	sm_Order.push(b);
}

void SceneManager::ChangeScene()
{
	sm_Order.pop();
	CreateNextScene();
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
