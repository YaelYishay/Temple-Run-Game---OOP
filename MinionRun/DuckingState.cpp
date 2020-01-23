
#include "stdafx.h"
#include "DuckingState.h"
#include "RunningState.h"
#include "GoLeftState.h"
#include "GoRightState.h"
#include "JumpingState.h"

DuckingState::DuckingState()
{
}

//handle player movements while ducking
unique_ptr<State> DuckingState::handleInput(sf::Event e)
{
	switch (e.key.code) {

	case sf::Keyboard::Space:
		return std::make_unique<JumpingState>();
		break;
	case sf::Keyboard::Up:
		return std::make_unique<RunningState>();
		break;
	case sf::Keyboard::Down:
		return std::make_unique<RunningState>();
		break;
	case sf::Keyboard::Right:
		return std::make_unique<GoRightState>();
		break;
	case sf::Keyboard::Left:
		return std::make_unique<GoLeftState>();
		break;
		// Stay in this state.
	default:
		return NULL;
	}
}

// ducking implemintation
void DuckingState::enter(Player & m)
{
	m_sprite.emplace_back(Sprite(DataBase::instance().loadDuckingPlayer(3)));
	m_sprite[0].setPosition({ m.getPosition().x, m.getPosition().y + 80 });

	m.setGraphics(m_sprite);
	m.setduck(true);
}
