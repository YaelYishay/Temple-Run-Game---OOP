#include "stdafx.h"
#include "Rock.h"
#include "Factory.h"

// abstract class for rocks and bridges
bool Rock::m_registerit = Factory::registerit("Rock", []()-> std::unique_ptr<Collectables> {return std::make_unique<Rock>(); });