#include "Gameloop.h"

Gameloop::Gameloop(sf::RenderWindow* window)
{
	this->window = window;
	Loop();
}

void Gameloop::Loop()
{
	while (window->isOpen()) {
		ManageEvents();

		b->Move();
		b->CheckScreenCollision();
		b->CheckPlatformCollision(p->GetSprite());

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

		if (event.type == sf::Event::MouseMoved) {
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
			sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
			p->Move(worldPos.x, 0);
		}
	}
}

void Gameloop::Draw()
{
	window->draw(p->GetSprite());
	window->draw(b->GetSprite());
}
