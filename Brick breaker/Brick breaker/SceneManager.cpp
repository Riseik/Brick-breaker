#include "SceneManager.h"

SceneManager::SceneManager()
{
	ball = Ball();
}

SceneManager::~SceneManager()
{
}

void SceneManager::CreateNextScene()
{
}

void SceneManager::ChangeScene()
{
}

Ball* SceneManager::GetBall()
{
	return &ball;
}

Platform* SceneManager::GetPlatform()
{
	return &platform;

}
