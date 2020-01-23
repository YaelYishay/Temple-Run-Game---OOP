#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <SFML\Audio\Music.hpp>

using std::unique_ptr;
using std::vector;
using sf::Texture;
using sf::Sprite;
using sf::Font;
using sf::Music;

class DataBase
{
public:
	~DataBase() { ; }
	static DataBase& instance();
	Texture& loadYouLose() { return m_youLose; }
	Texture& loadYouWin() { return m_youWin; }

	Texture& loadMenu() { return m_menu; }
	Texture& loadBackground() { return m_background; }
	Texture& loadRuningPlayer(int i) { return m_runingPlayer[i]; }
	Texture& loadDuckingPlayer(int i) { return m_duckingPlayer[i]; }
	Texture& loadJumpPlayer(int i) { return m_jumpingPlayer[i]; }
	Texture& loadObject(int i) { return m_objects[i]; }
	Texture& getCollect(int i) { return m_collectables[i]; }
	Font& getFont() { return m_font; }
	Music& getCoinSound() { return m_coinSound; }
	Music& getMenuSound() { return m_menuMusic; }
	Music& getGameSound() { return m_gameMusic; }
	Music& getBridgeSound() { return m_bridgeSound; }
	Music& getRockSound() { return m_rockMusic; }

private:
	void loadMusic();
	void loadImages();
	DataBase();
	Texture m_menu;
	Texture m_background;
	Texture m_youLose;
	Texture m_youWin;

	Font m_font;
	Music m_bridgeSound;
	Music m_coinSound;
	Music m_menuMusic;
	Music m_gameMusic;
	Music m_rockMusic;
	vector<Texture> m_runingPlayer;
	vector<Texture> m_duckingPlayer;
	vector<Texture> m_jumpingPlayer;
	vector<Texture> m_objects;
	vector<Texture> m_collectables;
	vector<Sprite> m_sp;

};

