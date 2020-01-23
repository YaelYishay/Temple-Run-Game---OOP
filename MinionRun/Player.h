#pragma once
#include "State.h"
#include "DataBase.h"
#include "Object.h"
using sf::Text;
using sf::Sprite;
using sf::RenderWindow;
using sf::Vector2f;


class Player :public Object
{
public:
	Player();
	~Player() { ; }
	virtual void handleInput(sf::Event e);
	void setGraphics(vector<Sprite> spriteState);
	void draw(RenderWindow& window, float deltaTime)const;

	void setX(int x) { m_x += x; }
	void setLives(int i) { m_lives += i; }
	void setScore(int i);
	int x()const { return m_x; }
	int getLives( )const { return m_lives; }
	Vector2f getPosition()const { return m_position; }
	bool is_jumping() { return m_jump; }
	void setJump(bool state) { m_jump = state; }
	bool is_ducking() { return m_duck; }
	void setduck(bool state) { m_duck = state; }

private:
	unique_ptr<State> m_state;
	vector<Sprite> m_player;
	Vector2f m_position;
	bool m_jump = false;
	bool m_duck = false;
	int m_score = 0;
	int m_lives = 3;
	int m_x = 0; 
};

