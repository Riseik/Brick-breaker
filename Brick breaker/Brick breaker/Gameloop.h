#pragma once
#include "const.h"
#include "sfml.h"
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
	sf::CircleShape shape; // sera supprim� lors du merge des objets
};

