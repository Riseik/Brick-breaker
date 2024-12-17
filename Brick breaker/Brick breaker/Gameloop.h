#pragma once
#include "const.h"
#include "sfml.h"
#include "Platform.h"
//include la classe scene
//include la classe object

class Gameloop
{
public:
	Gameloop(sf::RenderWindow* window);
	void SetSprites(); // sera supprim� lors du merge des objets
	void Loop();
	void ManageEvents();
	void Draw(); // sera remplac� par un appel � la fonction draw de chaque objet


private:
	sf::RenderWindow* window;
	Platform* p = new Platform(WINDOW_WIDTH / 2, WINDOW_HEIGHT - WINDOW_HEIGHT / 10);
	sf::CircleShape shape; // sera supprim� lors du merge des objets
};

