#pragma once
#include "Prize.h"

class Treasure :public Prize
{
public:
	Treasure() { m_pic = std::make_shared<sf::Texture>(DataBase::instance().getCollect(TREASURE)); }

private:
	static bool m_registerit;
};
