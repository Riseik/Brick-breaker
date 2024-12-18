#include "Score.h"

Score::Score()
{
}

void Score::AddScorePoint()
{
}

void Score::ChangeLevel()
{
}

void Score::LoadFont()
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error loading text font\n";
	}

	m_textScore.setFont(font);
	m_textLevel.setFont(font);
}
