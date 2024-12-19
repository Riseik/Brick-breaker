#include "Ball.h"

Ball::Ball()
{
	m_TexturePath = "ressource/TennisBall.png";
	m_pos = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	m_scale = { 0.01f, 0.01f };
	LoadTexture(m_TexturePath);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

Ball::~Ball()
{
}

void Ball::CheckScreenCollision()
{
	if (m_pos.x + m_texture.getSize().x * m_scale.x / 2 + m_speed.x > WINDOW_WIDTH || m_pos.x - m_texture.getSize().x * m_scale.x / 2 < 0)
		m_speed.x = -m_speed.x;
	if (m_pos.y + m_texture.getSize().y * m_scale.y / 2 + m_speed.y > WINDOW_HEIGHT || m_pos.y - m_texture.getSize().y * m_scale.y / 2 < 0)
		m_speed.y = -m_speed.y;
}

void Ball::CheckPlatformCollision(sf::Sprite spritePlatform)
{
	if (m_sprite.getGlobalBounds().intersects(spritePlatform.getGlobalBounds()) && m_speed.y > 0)
	{
		m_speed.y = -m_speed.y;

		int sizePlatformX = spritePlatform.getTexture()->getSize().x * spritePlatform.getScale().x;
		float relativePosition = ((m_pos.x - spritePlatform.getPosition().x) / (sizePlatformX / 2))/2;
		float speedIncrease = 0.1f;
		m_speed.x = m_speed.x + speedIncrease * relativePosition;
		if (m_speed.x > 0.1f)
			m_speed.x = 0.1f;
		if (m_speed.x < -0.1f)
			m_speed.x = -0.1f;
	}
}

void Ball::Move()
{
	m_pos = { m_pos.x + m_speed.x, m_pos.y + m_speed.y };
	m_sprite.setPosition(m_pos);
}

void Ball::Move(float, float)
{
}
