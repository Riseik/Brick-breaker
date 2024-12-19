#pragma once
#include "globals.h"
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
	std::vector<sf::Text*> GetScoreList();

private:

	std::vector<sf::Text*> m_TextList;
	sf::Text m_textTitle;
	sf::Text m_textScore;
	sf::Text m_textLevel;
	sf::Font font;

	int m_score = 0;
	int m_level = 1;

};

