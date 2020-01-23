#pragma once
#include "Prize.h"
class Coin :public Prize
{
public:
	Coin() { m_pic = std::make_shared<sf::Texture>(DataBase::instance().getCollect(COIN)); }

private:
	static bool m_registerit;
};


