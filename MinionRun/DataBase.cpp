#include "stdafx.h"
#include "DataBase.h"

void DataBase::loadMusic()
{
	m_gameMusic.openFromFile("music/menuMusic.ogg");
	m_gameMusic.setLoop(true);
	m_coinSound.openFromFile("music/coinCollect.ogg");
	m_menuMusic.openFromFile("music/gameMusic.ogg");
	m_bridgeSound.openFromFile("music/bridge boom.ogg");
	m_rockMusic.openFromFile("music/rock collision.ogg");
}

void DataBase::loadImages()
{
	m_youLose.loadFromFile("images/gameOver.png");
	m_youWin.loadFromFile("images/you win.png");
	m_menu.loadFromFile("images/menu.png");
	m_background.loadFromFile("images/bg.png");

	//get running textures
	for (int i = 0; i < 4; i++) {
		m_runingPlayer.emplace_back(Texture());
		m_runingPlayer[i].loadFromFile("images/runingState/" + std::to_string(i) + ".png");
	}

	//get jumping textures
	for (size_t i = 0; i < 4; i++) {
		m_jumpingPlayer.emplace_back(Texture());
		m_jumpingPlayer[i].loadFromFile("images/jumpingState/" + std::to_string(i) + ".png");
	}

	//get ducking textures
	for (size_t i = 0; i < 4; i++) {
		m_duckingPlayer.emplace_back(Texture());
		m_duckingPlayer[i].loadFromFile("images/duckingState/" + std::to_string(i) + ".png");
	}

	//get objects for background
	for (int i = 0; i < 4; i++) {
		m_objects.emplace_back(Texture());
		m_objects[i].loadFromFile("images/objects/" + std::to_string(i) + ".png");
	}

	//get collectable textures
	for (size_t i = 0; i <5; i++) {
		m_collectables.push_back(Texture());
		m_collectables[i].loadFromFile("images/collectables/" + std::to_string(i) + ".png");
	}
}

//SINGELTONE c-tor
DataBase::DataBase()
{
	this->loadImages();
	this->loadMusic();

	m_font.loadFromFile("fonti.ttf");
	
}

//sole insatnce of singletone
DataBase& DataBase::instance()
{
	static DataBase inst;
	return inst;
}
