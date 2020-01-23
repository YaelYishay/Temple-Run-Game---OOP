#pragma once
#include "State.h"
#include "Player.h"

class GoRightState :
	public State
{
public:
	GoRightState() { ; }
	~GoRightState() { ; }
	virtual unique_ptr<State>	handleInput(sf::Event e);
	virtual void				enter(Player& m) { m.setX(200); }

};

