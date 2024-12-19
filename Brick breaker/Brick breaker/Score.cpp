#include "Score.h"

Score::Score()
{
	m_textLevel.setPosition(20,50);
	m_textScore.setPosition(WINDOW_WIDTH - 150,50);
	m_textTitle.setPosition(WINDOW_WIDTH / 2 - 100, 20);


	/*
	m_TextList->push_back(m_textLevel);
	m_TextList->push_back(m_textScore);
	m_TextList->push_back(m_textTitle);
	*/

	LoadFont();
	LoadText();
	m_TextList.push_back(m_textTitle);
	m_TextList.push_back(m_textLevel);
	m_TextList.push_back(m_textScore);

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
	
	if (!font.loadFromFile("ressource/SquareOne.ttf"))
	{
		std::cout << "Error loading text font\n";
	}

	m_textScore.setFont(font);
	m_textLevel.setFont(font);
	m_textTitle.setFont(font);
}

void Score::LoadText()
{
	m_textLevel.setString("Level : " + m_level);
	m_textScore.setString("Score : " + m_score);
	m_textTitle.setString("BRICK BREAKER");

	m_textTitle.setFillColor(sf::Color::Red);
}

std::vector<sf::Text> Score::GetScoreList()
{
	return m_TextList;
}


