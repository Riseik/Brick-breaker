#include "Score.h"

Score::Score()
{
	m_textLevel.setPosition(20,200);
	m_textScore.setPosition(400,200);
	m_textTitle.setPosition(WINDOW_WIDTH / 2, 50);

	m_TextList.push_back(m_textLevel);
	m_TextList.push_back(m_textScore);
	m_TextList.push_back(m_textTitle);

	LoadFont();
	LoadText();
}

void Score::AddScorePoint(int point)
{
	m_score += point;
	m_textScore.setString("Score : " + m_score);
}

void Score::ChangeLevel()
{
	m_level++;
	m_textLevel.setString("Level : " + m_level);
}

void Score::LoadFont()
{
	sf::Font font;
	if (!font.loadFromFile("ressource/InlandersDemo.otf"))
	{
		std::cout << "Error loading text font\n";
	}

	m_textScore.setFont(font);
	m_textLevel.setFont(font);
}

void Score::LoadText()
{
	m_textLevel.setString("Level : " + m_level);
	m_textScore.setString("Score : " + m_score);
	m_textTitle.setString("BRICK BREAKER");
}
