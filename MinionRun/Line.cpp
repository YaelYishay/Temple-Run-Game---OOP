#include "stdafx.h"
#include "Line.h"

//set lines and the background displayed on each line
Line::Line(int i)
	:z(i*200.f), m_collect(nullptr)
{
	m_clip = 768.f;

	if (i < 300 && i % 20 == 0) { m_objX = { -1, 0.25 }; m_texture = make_shared<Texture>(DataBase::instance().loadObject(1)); }
	if (i > 300 && i < 800 && i % 20 == 0) { m_objX = { -1 ,0.25 }; m_texture = make_shared<Texture>(DataBase::instance().loadObject(2)); }
	if (i > 800 && i < 1000 && i % 20 == 0) { m_objX = { -1, 0.5 }; m_texture = make_shared<Texture>(DataBase::instance().loadObject(2)); }
	if (i > 200 && i % 100 == 0) { m_objX = { 0.25, 0.5 }; m_texture = make_shared<Texture>(DataBase::instance().loadObject(0)); }
	if (i > 1030 && i < 1500 && i % 20 == 0) { m_objX = { -1, 0.5 }; m_texture = make_shared<Texture>(DataBase::instance().loadObject(3)); }

	this->setCollect(i);
}

//convert 3d coordinants to 2d coordinants
void Line::convert(int camX, int camY, int camZ)
{
	float camD = float(0.84); //camera depth

	m_scale = camD / (z - camZ);
	m_center.x = (1 + m_scale * (0 - camX)) * 1024 / 2;
	m_center.y = (1 - m_scale * (0 - camY)) * 768 / 2;
	m_center.z = m_scale * 2000 * 1024 / 2;
}

//draw the objects onto the line
void Line::draw(sf::RenderWindow & window)
{
	if (m_texture) {
		drawObject(window, m_objX.x);
		drawObject(window, m_objX.y);
	}
	if (m_collect)
		m_collect->draw(window, m_clip, m_center, m_scale, m_collectX);
}

bool Line::hasCollect()const
{
	if (m_collect)
		return true;
	return false;
}

//get collectable that has been collided with
bool Line::collides(const unique_ptr<Player>& player)
{
	return m_collect->collides(player);
}

//set the collectables on each line
void Line::setCollect(int i)
{
	if (i < 300 && i % 20 == 0) {
		m_collectX = -0.7;
		m_collect = std::move(Factory::create("Coin"));
	}

	if (i % 300 == 0) {
		m_collectX = 0.7;
		m_collect = std::move(Factory::create("Treasure"));
	}

	if (i > 213 && i % 40 == 0) {
		m_collectX = -1.2;
		m_collect = std::move(Factory::create("Booster"));
	}

	if (i % 103 == 0) {
		m_collectX = -1.5;
		m_collect = std::move(Factory::create("Treasure"));
	}

	if (i > 213 && i % 40 == 0) {
		m_collectX = -1.2;
		m_collect = std::move(Factory::create("Rock"));
	}

	if (i % 103 == 0) {
		m_collectX = -0.9;
		m_collect = std::move(Factory::create("Bridge"));
	}

}

// draw background objects(trees houses etc)
void Line::drawObject(RenderWindow & window, double pos)const
{
	Sprite s;
	s.setTexture(*m_texture);

	int w = s.getTextureRect().width;
	int h = s.getTextureRect().height;

	float destX = m_center.x + m_scale * pos * 1024 / 2;
	float destY = m_center.y + 4;
	float destW = w * m_center.z / 266;
	float destH = h * m_center.z / 266;

	destX += destW * pos;
	destY += destH * (-1);

	float clipH = destY + destH - m_clip;
	if (clipH < 0) clipH = 0;
	if (clipH >= destH) return;

	s.setScale(destW / w, destH / h);
	s.setPosition(destX, destY);
	window.draw(s);
}



