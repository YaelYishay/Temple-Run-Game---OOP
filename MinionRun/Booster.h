#pragma once
#include "Collectables.h"
#include "Prize.h"

class Booster :public Prize
{
public:
	Booster() { m_pic = std::make_shared<sf::Texture>(DataBase::instance().getCollect(BOOST)); }

protected:
	static bool m_registerit;
};

