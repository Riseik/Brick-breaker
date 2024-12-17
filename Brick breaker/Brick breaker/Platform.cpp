#include "Platform.h"

Platform::Platform(float x, float y)
{
	m_TexturePath = "metal_brick.jpg";
	m_pos = { x,y };
	m_scale = { 100,50 };
	LoadTexture(m_TexturePath);
}

