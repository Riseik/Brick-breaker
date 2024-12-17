#include "Gameloop.h"

Gameloop::Gameloop(sf::RenderWindow* window)
{
	this->window = window;
	SetSprites();
	Loop();
}

void Gameloop::SetSprites()
{
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);
}

void Gameloop::Loop()
{
	while (window->isOpen()) {
		ManageEvents();

		window->clear();
		Draw();
		window->display();
	}
}

void Gameloop::ManageEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				shape.setFillColor(sf::Color::Red);

		if (event.type == sf::Event::MouseMoved)
			window = window; // à remplacer par setpositionplayer
	}
}

void Gameloop::Draw()
{
	window->draw(shape);
}
