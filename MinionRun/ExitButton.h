#pragma once
#include "Button.h"

class ExitButton :public Button
{
public:
	ExitButton(std::shared_ptr<Game> g) :Button(g) { m_position = { 728, 490, 150, 50 }; }
	~ExitButton() { ; }
	virtual void execute()override {
		m_game->exit();
	}

};

