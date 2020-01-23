#pragma once
#include "Obstacle.h"

class Bridge :public Obstacle
{
public:
	Bridge() { m_pic = std::make_shared<sf::Texture>(DataBase::instance().getCollect(BRIDGE)); }
	~Bridge() { ; }

private:
	static bool m_registerit;
};

