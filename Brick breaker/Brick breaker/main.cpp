#include "Gameloop.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    
    Gameloop gameloop(&window);

    return 0;
}