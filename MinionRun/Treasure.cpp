#include "stdafx.h"
#include "Treasure.h"
#include "Factory.h"

//make a treasure object (prize of 400 coins)
bool Treasure::m_registerit = Factory::registerit("Treasure", []()-> std::unique_ptr<Collectables> {return std::make_unique<Treasure>(); })
;