#pragma once
#include "Obstacle.h"

class Rock :public Obstacle
{
public:
	Rock() { m_pic = std::make_shared<sf::Texture>(DataBase::instance().getCollect(ROCK)); }
	~Rock() { ; }

private:
	static bool m_registerit;
};

