#include "Platform.h"

Platform::Platform()
{
}

Platform::Platform(float x, float y)
{
	m_TexturePath = "ressource/metal_brick.png";
	m_pos = { x,y };
	m_scale = { 0.3f, 0.05f };
	LoadTexture(m_TexturePath);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
}

Platform::~Platform()
{
}

void Platform::Move(float x, float a)
{
	if (x > m_texture.getSize().x * m_scale.x / 2 && x < WINDOW_WIDTH - m_texture.getSize().x * m_scale.x / 2)
		m_sprite.setPosition(x, m_pos.y);
}

