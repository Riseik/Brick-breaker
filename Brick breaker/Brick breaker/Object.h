#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"

class Object
{
public:
	Object();
	~Object();

	void LoadTexture(std::string);
	void LoadSprite();
	sf::Sprite GetSprite();
	virtual void Move(float, float) = 0;

protected:
	sf::Color m_color;
	sf::Vector2f m_pos;
	sf::Vector2f m_scale;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::string m_TexturePath;
};

