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
		if (pause) {

		}
		else {
			if (!start) {
				int x = gl_platform->GetSprite().getPosition().x;
				int y = gl_platform->GetSprite().getPosition().y - gl_platform->GetSprite().getTexture()->getSize().y*0.05f;
				b->Move(x,y);
			}
			else
			{
				b->Move();
				b->CheckScreenCollision();
				b->CheckPlatformCollision(gl_platform->GetSprite());
				if (gl_sceneManager->GetActualScene()->GetBrick()->size() != 0) {
					for (int i = 0; i < gl_sceneManager->GetActualScene()->GetBrick()->size(); i++) {
						Brick* brick = gl_sceneManager->GetActualScene()->GetBrick()->at(i);
						if (brick != nullptr && b->CheckBrickCollision(brick)) {
							if (brick->BrickDamage()) {
								gl_sceneManager->GetActualScene()->GetBrick()->erase(std::remove(gl_sceneManager->GetActualScene()->GetBrick()->begin(), gl_sceneManager->GetActualScene()->GetBrick()->end(), brick), gl_sceneManager->GetActualScene()->GetBrick()->end());
								brick->Destroy();
								break;
							}
						}
					}
				}
				else {
					gl_sceneManager->ChangeScene();
					start = false;
					b->Move(BALL_POS_X, BALL_POS_Y);
				}
			}

			window->clear();
			Draw();
			window->display();
		}
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

		if (event.mouseButton.button == sf::Mouse::Left && !start)
		{
			start = !start;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				pause = !pause;
			}
		}
	}
}

void Gameloop::Draw()
{
	//window->draw(shape);
	window->draw(gl_platform->GetSprite());
	for (Brick* brick : *gl_sceneManager->GetActualScene()->GetBrick()) {
		window->draw(brick->GetSprite());
	}
	//gl_sceneManager.GetActualScene()->DrawBrick(window);

	window->draw(gl_platform->GetSprite());
	window->draw(b->GetSprite());
}
