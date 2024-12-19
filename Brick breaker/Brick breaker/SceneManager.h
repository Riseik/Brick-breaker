#pragma once
#include "globals.h"
#include "Scene.h"
#include "Ball.h"
#include "Platform.h"

class SceneManager
{
private:
	std::queue<Scene> sm_Order;
	Ball ball;
	Platform platform;



public:
	SceneManager();
	SceneManager(Ball*, Platform*);
	~SceneManager();
	void CreateNextScene();
	void ChangeScene();
	Ball* GetBall();
	Platform* GetPlatform();
	Scene* GetActualScene();
};

