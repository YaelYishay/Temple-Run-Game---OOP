#pragma once
#include "State.h"
#include "Player.h"

class RunningState :public State
{
public:
	RunningState() ;
	~RunningState() { ; }
	virtual unique_ptr<State>	handleInput(sf::Event e);
	virtual void				enter(Player& m); 

};

