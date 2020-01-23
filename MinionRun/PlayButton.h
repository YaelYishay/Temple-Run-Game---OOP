#pragma once
#include "Button.h"

class PlayButton :public Button
{
public:
	PlayButton(std::shared_ptr<Game> g) :Button(g) { m_position = { 728, 400, 150, 50 }; }
	~PlayButton() { ; }
	virtual void execute()override {
		m_game->play();
	}

};

