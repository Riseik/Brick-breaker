#include "Brick.h"

Brick::Brick(float x, float y)
{
	m_pos = { x,y };
	m_scale = { 1,1 };
	LoadTexture(m_TexturePath);
	LoadSprite();
}

void Brick::DestroyBrick()
{

}

void Brick::Move()
{
}
