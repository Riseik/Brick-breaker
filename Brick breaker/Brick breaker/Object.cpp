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
	{
		std::cout << "Error loading texture\n";
	}
}

void Object::LoadSprite()
{
	m_sprite.setTexture(m_texture);
}

sf::Sprite Object::GetSprite()
{
	return m_sprite;
}


