#pragma once
#include "State.h"
#include "Player.h"

class JumpingState :public State
{
public:
	JumpingState();
	~JumpingState() { ; }
	virtual unique_ptr<State>	handleInput(sf::Event e);
	virtual void				enter(Player& m);

};

