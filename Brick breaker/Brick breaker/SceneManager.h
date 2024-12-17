#pragma once
#include "AllInclude.h"
#include "Ball.h"
#include "Platform.h"

class Scene;
class SceneManager
{
private:
	std::queue<Scene> sm_Order;
	Ball ball;
	Platform platform;



public:
	SceneManager();
	~SceneManager();
	void CreateNextScene();
	void ChangeScene();
	Brick* GetBrick();
	Platform* GetPlatform();
};

