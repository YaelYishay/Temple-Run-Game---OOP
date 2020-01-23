#pragma once
#include <iostream>
#include "Game.h"

// Command Interface
class Button
{
public:
	Button(std::shared_ptr<Game> g) :m_game(move(g)) { ; }
	~Button() { ; }
	virtual void execute() = 0;
	virtual bool contains(Event e) {
		return m_position.contains(e.mouseButton.x, e.mouseButton.y);
	}

protected:
	std::shared_ptr<Game> m_game;
	IntRect m_position;
};

