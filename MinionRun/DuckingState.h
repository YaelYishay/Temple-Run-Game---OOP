#pragma once
#include "State.h"
#include "Player.h"

class DuckingState :
	public State
{
public:
	DuckingState();
	~DuckingState() { ; }

	virtual unique_ptr<State>	handleInput(sf::Event e);
	virtual void				enter(Player& m);

};

