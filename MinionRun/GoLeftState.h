#pragma once
#include "State.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class GoLeftState :
	public State
{
public:
	GoLeftState(){ ; }
	~GoLeftState() { ; }
	virtual unique_ptr<State>	handleInput(sf::Event e);
	virtual void				enter(Player& m) { m.setX(-200);}

};

