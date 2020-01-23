#include "stdafx.h"
#include "Collectables.h"

//print all collectable objects to screen 
void Collectables::draw(RenderWindow & window ,float m_clip, sf::Vector3f m_center, float m_scale ,double m_collectX) 
{

	// get the texture of specific objext
	Sprite s;
	s.setTexture(*m_pic);

	// get width and hight of the object
	int w = s.getTextureRect().width;
	int h = s.getTextureRect().height;

	// calculate the position, hight and width for reposition
	float destX = m_center.x + m_scale * m_collectX * 1024 / 2;
	float destY = m_center.y + 4;
	float destW = w * m_center.z / 266;
	float destH = h * m_center.z / 266;

	m_destX = destX;
	m_destY = destY;

	destX += destW * m_collectX;
	destY += destH * (-1);

	float clipH = destY + destH - m_clip;
	if (clipH < 0) clipH = 0;
	if (clipH >= destH) return;

	m_destH = destH;
	m_destW = destW;

	s.setScale(destW / w, destH / h);
	s.setPosition(destX, destY);
	window.draw(s);
}

// check if two game objects on the same line of screen collide
bool Collectables::collides(const unique_ptr<Player>& player)
{
	sf::IntRect collect = { m_destX ,m_destY, m_destW, m_destH };
	if(m_destX +50 < player->getPosition().x ||
		m_destX > player->getPosition().x + 150)
		return false;

	return true;
}
