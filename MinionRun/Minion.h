#pragma once
#include "State.h"
#include "Subject.h"
#include "DataBase.h"
#include "dynamicObject.h"
using sf::Sprite;
using sf::RenderWindow;

class Minion :Subject, public dynamicObject
{
public:
	Minion();
	~Minion() { ; }
	virtual void handleInput(UserInput input);
	void setGraphics(vector<Sprite> spriteState){ m_minion = spriteState; }
	void draw(RenderWindow& window, float deltaTime);
	void setX(int x) { m_x += x; }
	void setZ(int z) { m_z += z; }
	int x()const { return m_x; }
	int y()const { return m_y; }
	int z()const { return m_z; }

private:
	unique_ptr<State> m_state;
	vector<Sprite> m_minion;
	int m_index = 0;
	int m_x;
	int m_y;
	int m_z;

};

