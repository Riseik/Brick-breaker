#pragma once
#include "AllInclude.h"
#include "Platform.h"
#include "SceneManager.h"

#include "Ball.h"
//include la classe scene
//include la classe object

class Gameloop
{
public:
	Gameloop(sf::RenderWindow* window);
	void Loop();
	void ManageEvents();
	void Draw(); // sera remplac� par un appel � la fonction draw de chaque objet


private:
	sf::RenderWindow* window;
	Platform* gl_platform = new Platform(WINDOW_WIDTH / 2, WINDOW_HEIGHT - WINDOW_HEIGHT / 10);
	sf::CircleShape shape; // sera supprim� lors du merge des objets
	SceneManager* gl_sceneManager;
	Ball* gl_Ball;
	Platform* p = new Platform(WINDOW_WIDTH / 2, WINDOW_HEIGHT - WINDOW_HEIGHT / 10);
	Ball* b = new Ball();
};

