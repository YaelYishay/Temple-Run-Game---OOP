#include "stdafx.h"
#include "Controller.h"

//macro
int width = 1024;
int height = 768;

//activate the game
Controller::Controller()
	:m_game(std::make_shared<Game>(m_window)),
	 m_menu(make_unique<Menu>(make_unique<PlayButton>(m_game), 
		 make_unique<ExitButton>(m_game)))
{	
	m_window.create(sf::VideoMode(width, height),
		"Player Run", sf::Style::Titlebar | sf::Style::Close);
}


void Controller::run(){
	m_menu->activate(m_window);
}

