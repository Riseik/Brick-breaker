#include "Ball.h"

Ball::Ball()
{
	m_TexturePath = "ressource/TennisBall.png";
	m_pos = { 250,250 };
	m_scale = { 80,40 };
	LoadTexture(m_TexturePath);
}

Ball::~Ball()
{
}

void Ball::Move(float x, float y)
{
	m_sprite.move(x, y);
}
