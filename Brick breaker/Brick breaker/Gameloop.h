#pragma once
#include "const.h"
#include "sfml.h"
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
	sf::CircleShape shape; // sera supprimé lors du merge des objets
};

