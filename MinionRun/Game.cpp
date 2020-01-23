#include "stdafx.h"
#include "Game.h"

//manage the game
Game::Game(RenderWindow & w)
	:m_window(w),
	m_player(std::make_unique<Player>()),
	m_track(std::make_unique<Track>(m_player)),
	m_youLose(DataBase::instance().loadYouLose()),
	m_youWin(DataBase::instance().loadYouWin())	
{
}

//play loop
void Game::play()
{
	//initialize music,events,clock
	DataBase::instance().getGameSound().play();
	Event e;
	m_clock.restart().asSeconds();

	//manage playing loop
	while (m_window.isOpen() && 
		m_track->run(m_window) 
		&& m_player->getLives() >= 0) {

		m_player->draw(m_window, m_clock.getElapsedTime().asSeconds());
		m_window.display();

		while (m_window.pollEvent(e)) {

			switch (e.type)
			{
			case Event::Closed:
				m_window.close();
				break;
			case Event::KeyPressed:
				if (e.key.code == Keyboard::Escape)
					m_window.close();
				m_player->handleInput(e);
			}
		}
		setJump(e);
		setduck(e);
		m_window.clear();
	}

	DataBase::instance().getGameSound().stop();
	DataBase::instance().getMenuSound().play();

	if (!m_track->run(m_window))
		this->GameOver(m_youWin);

	this->GameOver(m_youLose);
}

//manages the game over screen
void Game::GameOver(Texture te)
{
	Event event;
	Sprite sp;
	sp.setTexture(te);

	while (m_window.isOpen()) {

		m_window.draw(sp);

		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				m_window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					m_window.close();
				break;
			}
		}
		m_window.display();
	}
}

//set screen display for next screen print
void Game::setJump(sf::Event e)
{
	if (m_player->is_jumping()) {
		static int timer = 0;
		if (timer == 6) {
			m_player->handleInput(e);
			m_player->setJump(false);
			timer = 0;
		}
		timer++;
	}
}

//set screen display for next screen print
void Game::setduck(sf::Event e)
{

	if (m_player->is_ducking()) {
		static int timer = 0;
		if (timer == 6) {
			m_player->handleInput(e);
			m_player->setduck(false);
			timer = 0;
		}
		timer++;
	}
}