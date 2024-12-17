#include "Platform.h"

Platform::Platform(float x, float y)
{
	m_TexturePath = "ressource/metal_brick.png";
	m_pos = { x,y };
	m_scale = { 0.3f, 0.05f };
	LoadTexture(m_TexturePath);
}

void Platform::Move(float x, float a)
{
	m_sprite.setPosition(x, m_pos.y);
}

