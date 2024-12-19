#include "Ball.h"

Ball::Ball()
{
	m_TexturePath = "ressource/TennisBall.png";
	m_pos = { BALL_POS_X,BALL_POS_Y };
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
		float relativePosition = ((m_pos.x - spritePlatform.getPosition().x) / (sizePlatformX / 2));
		float speedIncrease = 0.5f;
		m_speed.x = m_speed.x + speedIncrease * relativePosition;
		if (m_speed.x > 0.5f)
			m_speed.x = 0.5f;
		if (m_speed.x < -0.5f)
			m_speed.x = -0.5f;
	}
}

//bool Ball::CheckBrickCollision(Brick* brick)
//{
//	//if (m_sprite.getGlobalBounds().intersects(brick->GetSprite().getGlobalBounds()) )
//	//{
//	//	//m_speed.y = -m_speed.y;
//
//	//	/*int sizePlatformX = brick->GetSprite().getTexture()->getSize().x * brick->GetSprite().getScale().x;
//	//	float relativePosition = ((m_pos.x - brick->GetSprite().getPosition().x) / (sizePlatformX / 2)) / 2;
//	//	float speedIncrease = 0.1f;
//	//	m_speed.x = m_speed.x + speedIncrease * relativePosition;
//	//	if (m_speed.x > 0.1f)
//	//		m_speed.x = 0.1f;
//	//	if (m_speed.x < -0.1f)
//	//		m_speed.x = -0.1f;*/
//	//	std::cout << "hit\n";
//	//	return true;
//	//}
//
//	float ballX = m_pos.x;
//	float ballY = m_pos.y;
//	float ballW = m_texture.getSize().x * m_scale.x;
//	float ballH = m_texture.getSize().y * m_scale.y;
//
//	float brickX = brick->GetSprite().getPosition().x;
//	float brickY = brick->GetSprite().getPosition().y;
//	float brickW = brick->GetSprite().getTexture()->getSize().x * brick->GetSprite().getScale().x;
//	float brickH = brick->GetSprite().getTexture()->getSize().y * brick->GetSprite().getScale().y;
//
//	if (ballX < brickX + brickW && ballX + ballW > brickX && ballY < brickY + brickH && ballH + ballY > brickY)
//	{
//		float overlapX;
//		float overlapY;
//
//		if (ballX < brickX)
//			overlapX = ballX + ballW - brickX;
//		else
//			overlapX = brickX + brickW - ballX;
//
//		if (ballY > brickY)
//			overlapY = ballY + ballH - brickY;
//		else
//			overlapY = brickY + brickH - ballY;
//
//		if (overlapX < overlapY)
//			m_speed.y = -m_speed.y;
//		else
//			m_speed.x = -m_speed.x;
//
//		return true;
//	}
//
//	return false;
//}


bool Ball::CheckBrickCollision(Brick* brick)
{
    sf::FloatRect ballBounds = m_sprite.getGlobalBounds();
    sf::FloatRect brickBounds = brick->GetSprite().getGlobalBounds();

    // Vérifier si la balle entre en collision avec la brique
    if (ballBounds.intersects(brickBounds))
    {
        float ballCenterX = ballBounds.left + ballBounds.width / 2;
        float ballCenterY = ballBounds.top + ballBounds.height / 2;
        float brickCenterX = brickBounds.left + brickBounds.width / 2;
        float brickCenterY = brickBounds.top + brickBounds.height / 2;

        // Cas où la balle touche les deux côtés horizontalement (gauche et droite)
        if (ballCenterX > brickBounds.left && ballCenterX < brickBounds.left + brickBounds.width)
        {
            if (ballBounds.top + ballBounds.height > brickBounds.top && ballBounds.top < brickBounds.top + brickBounds.height)
            {
                m_speed.y = -m_speed.y; 
            }
        }

        // Cas où la balle touche les deux côtés verticalement (haut et bas)
        if (ballCenterY > brickBounds.top && ballCenterY < brickBounds.top + brickBounds.height)
        {
            if (ballBounds.left + ballBounds.width > brickBounds.left && ballBounds.left < brickBounds.left + brickBounds.width)
            {
                m_speed.x = -m_speed.x; 
            }
        }

        return true;
    }

    return false;  
}




void Ball::Move()
{
	m_pos = { m_pos.x + m_speed.x, m_pos.y + m_speed.y };
	m_sprite.setPosition(m_pos);
}

void Ball::Move(float x, float y)
{
    m_pos = { x, y };
    m_sprite.setPosition(m_pos);
}
