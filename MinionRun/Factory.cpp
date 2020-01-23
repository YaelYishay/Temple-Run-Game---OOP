#include "stdafx.h"
#include "Factory.h"
#include "Collectables.h"
#include "Obstacle.h"

// create a function to map of collectables
std::unique_ptr<Collectables> Factory::create(const std::string& name) {
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second();
}

// add  a function to map of collectables
bool Factory::registerit(const std::string& name, std::unique_ptr<Collectables>(*f)()) {
	getMap().emplace(name, f);
	return true;
}
