#include "Brick.h"

Brick::Brick(float x, float y)
{
	m_TexturePath = "metal_brick.jpg";
	m_pos = { x,y };
	m_scale = { 80,40 };
	LoadTexture(m_TexturePath);
}

Brick::~Brick()
{
	m_health = NULL;
}

bool Brick::BrickDamage()		//reduis la vie de la brick et renvoie true si elle doit etre detruite
{
	m_health--;
	if (m_health <= 0)
		return true;

	return false;
}

void Brick::Destroy()			//APPELLER CETTE FONCTION APRES AVOIR RETIRER L'OBJET DE LA SCENE LIST
{
	delete[] this;
}


void Brick::Move(float x, float y)
{
}
