#include "Gameloop.h"

Gameloop::Gameloop(sf::RenderWindow* window)
{
	this->window = window;
	gl_sceneManager = new SceneManager();
	Loop();
}

void Gameloop::Loop()
{
	while (window->isOpen()) {
		ManageEvents();

		b->Move();
		b->CheckScreenCollision();
		b->CheckPlatformCollision(gl_platform->GetSprite());

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
			gl_platform->Move(worldPos.x, 0);
		}
	}
}

void Gameloop::Draw()
{
	//window->draw(shape);
	window->draw(gl_platform->GetSprite());
	for (int i = 0; i < NUMBERBRICK; i++) {
		window->draw(gl_sceneManager->GetActualScene()->GetBrick(i)->GetSprite());
	}
	//gl_sceneManager.GetActualScene()->DrawBrick(window);
	
	window->draw(gl_platform->GetSprite());
	window->draw(b->GetSprite());
}
