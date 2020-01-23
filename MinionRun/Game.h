#pragma once
#include "Player.h"
#include <memory>
#include "Track.h"

// Receiver Class
class Game 
{
public:
	Game(RenderWindow& w);
	~Game() { ; }
	void play();
	void exit(){ m_window.close();}

private:
	void GameOver(Texture);
	void setJump(sf::Event e);
	void setduck(sf::Event e);
	Clock m_clock;
	RenderWindow& m_window;
	unique_ptr<Player> m_player;
	unique_ptr<Track> m_track;
	Texture m_youLose;
	Texture m_youWin;

};

