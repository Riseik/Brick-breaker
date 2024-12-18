#pragma once
#include "const.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Score
{
public:
	Score();
	void AddScorePoint(int);
	void ChangeLevel();
	void LoadFont();
	void LoadText();

private:
	sf::Text m_textTitle;
	sf::Text m_textScore;
	sf::Text m_textLevel;
	std::vector<sf::Text> m_TextList;
	int m_score = 0;
	int m_level = 0;

};

