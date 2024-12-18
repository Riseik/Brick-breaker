#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Score
{
public:
	Score();
	void AddScorePoint();
	void ChangeLevel();
	void LoadFont();

private:
	sf::Text m_textScore;
	sf::Text m_textLevel;
	int m_score = 0;
	int m_level = 0;

};

