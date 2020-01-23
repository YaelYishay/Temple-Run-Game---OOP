#include "stdafx.h"
#include "Coin.h"
#include "Factory.h"
//make coin object for player to collect and gain points
bool Coin::m_registerit = Factory::registerit("Coin", []()-> std::unique_ptr<Collectables> {return std::make_unique<Coin>(); })
;