#include "Object.h"

Object::Object()
{

}

Object::~Object()
{

}

void Object::LoadTexture(std::string path)
{
	if(!m_texture.loadFromFile(path))
		std::cout << "Error loading texture\n";

	else
		LoadSprite();

}

void Object::LoadSprite()
{
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_pos);
	m_sprite.setScale(m_scale);
}

sf::Sprite Object::GetSprite()
{
	return m_sprite;
}


