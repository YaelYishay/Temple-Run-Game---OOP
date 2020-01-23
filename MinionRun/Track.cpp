#include "stdafx.h"
#include "Track.h"
const int TRACK_END = 1450;

//initialize track with background,player and lines contaninng objects
Track::Track(unique_ptr<Player>& m)
	:m_player(m),
	m_bg(DataBase::instance().loadBackground()),
	m_sBackground(m_bg)
{
	for (int i = 0; i < m_size; i++)
		m_lines.emplace_back(std::make_unique<Line>(i));

	m_bg.setRepeated(true);
	m_sBackground.setTextureRect(IntRect(0, 0, 5000, 812));
	m_sBackground.setPosition(-2000, 0);
}

//run the track
bool Track::run(RenderWindow &window)
{
	if (m_startPos >= TRACK_END)
		return false;

	this->draw(window);
	m_startPos++;

	return true;
}

//draw the entire track

void Track::draw(RenderWindow & window) const
{
	window.draw(m_sBackground);
	drawRoad(window);
	drawLines(window);
}

// implemnt the road to draw
void Track::drawRoad(RenderWindow & window)const
{
	float maxy = m_height;
	static int Z = 0;
	Z += 200;

	for (int n = m_startPos; n < m_startPos + 300; n++)
	{
		//convert to screen cord
		m_lines[n%m_size]->convert(m_player->x(),1500, Z);
		
		m_lines[n%m_size]->setClip(maxy);

		if (m_lines[n%m_size]->getCenter().y >= maxy) continue;
		maxy = m_lines[n%m_size]->getCenter().y;

		Color road = (n / 3) % 2 ? Color(107, 107, 107) : Color(105, 105, 105);
		Color grass = (n / 3) % 2 ? Color(0, 151, 136) : Color(0, 149, 130);
		Color roadSide = (n / 3) % 2 ? Color::Black : Color::White;

		float x1 = m_lines[n % m_size]->getCenter().x;
		float y1 = m_lines[n % m_size]->getCenter().y;
		float w1 = m_lines[n % m_size]->getCenter().z;
		float x2 = m_lines[(n - 1) % m_size]->getCenter().x;
		float y2 = m_lines[(n - 1) % m_size]->getCenter().y;
		float w2 = m_lines[(n - 1) % m_size]->getCenter().z;

		drawQuad(window, grass, 0.f, y2, m_width, 0.f, y1, m_width);
		drawQuad(window, roadSide, x2, y2, w2*1.2, x1, y1, w1*1.2);
		drawQuad(window, road, x2, y2, w2, x1, y1, w1);

	}
}

//implemnt the lines to draw(while each line contains the objects)
void Track::drawLines(RenderWindow & window)const
{
	for (int n = m_startPos + 300; n > m_startPos; n--) {

		if (n == m_startPos + 6)
			if (m_lines[n%m_size]->hasCollect() && 
				m_lines[n%m_size]->collides(m_player))
				processCollision(*m_player, *m_lines[n%m_size]->getCollect());

		m_lines[n%m_size]->draw(window);
	}
}

//draw the road,grass and sidewalks

void Track::drawQuad(RenderWindow & window, Color c, float x1, float y1, float z1, float x2, float y2, float z2)const
{
	ConvexShape shape(4);
	shape.setFillColor(c);
	shape.setPoint(0, Vector2f(x1 - z1, y1));
	shape.setPoint(1, Vector2f(x2 - z2, y2));
	shape.setPoint(2, Vector2f(x2 + z2, y2));
	shape.setPoint(3, Vector2f(x1 + z1, y1));
	window.draw(shape);
}



