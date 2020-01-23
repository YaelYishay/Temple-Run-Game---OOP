#include "stdafx.h"
#include "Booster.h"
#include "Factory.h"

//make a booster object(special power to player)
bool Booster::m_registerit = Factory::registerit("Booster", []()-> std::unique_ptr<Collectables> {return std::make_unique<Booster>(); })
;