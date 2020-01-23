#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
using std::vector;

class Player;
enum UserInput
{
	PRESS_UP,
	PRESS_DOWN,
	RELEASE_UP,
	RELEASE_DOWN,
	PRESS_RIGHT,
	PRESS_LEFT,
	SPACE
};

using std::unique_ptr;

class State
{
public:
	State() { ; }
	virtual ~State() { ; }
	virtual unique_ptr<State>	handleInput(sf::Event e) = 0;
	virtual void				enter(Player& ) = 0;

protected:
	vector<sf::Sprite> m_sprite;
	sf::Vector2f m_position;
};

