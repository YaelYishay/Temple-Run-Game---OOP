#include "stdafx.h"
#include "Bridge.h"
#include "Factory.h"

//make a bridge object to collide with player
bool Bridge::m_registerit = Factory::registerit("Bridge", []()-> std::unique_ptr<Collectables> {return std::make_unique<Bridge>(); });