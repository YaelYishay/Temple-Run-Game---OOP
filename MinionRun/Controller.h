#pragma once
#include "Player.h"
#include "Menu.h"
#include "Game.h"

using std::unique_ptr;
using std::make_unique;

// The client
class Controller
{
public:
	Controller();
	~Controller() { ; }
	void run();

private:
	RenderWindow m_window;
	std::shared_ptr<Game> m_game;
	unique_ptr<Menu> m_menu;
};

