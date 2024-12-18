#pragma once
#include "AllInclude.h"
#include "Platform.h"
#include "SceneManager.h"

//include la classe scene
//include la classe object

class Gameloop
{
public:
	Gameloop(sf::RenderWindow* window);
	void SetSprites(); // sera supprimé lors du merge des objets
	void Loop();
	void ManageEvents();
	void Draw(); // sera remplacé par un appel à la fonction draw de chaque objet


private:
	sf::RenderWindow* window;
	Platform* gl_platform = new Platform(WINDOW_WIDTH / 2, WINDOW_HEIGHT - WINDOW_HEIGHT / 10);
	sf::CircleShape shape; // sera supprimé lors du merge des objets
	SceneManager* gl_sceneManager;
	Ball* gl_Ball;
};

