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
}

Platform::~Platform()
{
}

void Platform::Move(float, float)
{
}

