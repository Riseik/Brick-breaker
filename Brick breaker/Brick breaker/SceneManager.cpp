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
	sm_Order.push(Scene());
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
