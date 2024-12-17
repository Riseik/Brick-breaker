#include "Brick.h"

Brick::Brick()
{
}

Brick::Brick(float x, float y)
{
	m_TexturePath = "metal_brick.jpg";
	m_pos = { x,y };
	m_scale = { 80,40 };
	LoadTexture(m_TexturePath);
}

void Brick::DestroyBrick()
{

}

void Brick::Move(float x, float y)
{
}
