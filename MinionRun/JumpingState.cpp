#include "stdafx.h"
#include "JumpingState.h"
#include "RunningState.h"
#include "GoLeftState.h"
#include "GoRightState.h"
#include "DuckingState.h"


JumpingState::JumpingState()
{
}

//handle movement while jumping
unique_ptr<State> JumpingState::handleInput(sf::Event e)
{

	switch (e.key.code) {

	case sf::Keyboard::Space:
		return std::make_unique<RunningState>();
		break;
	case sf::Keyboard::Up:
		return std::make_unique<RunningState>();
		break;
	case sf::Keyboard::Down:
		return std::make_unique<DuckingState>();
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
		break;
	}
}

//implement the jumping motion
void JumpingState::enter(Player & m)
{

	m_sprite.emplace_back(Sprite(DataBase::instance().loadJumpPlayer(3)));
	m_sprite[0].setPosition({ m.getPosition().x, m.getPosition().y - 300 });

	m.setGraphics(m_sprite);
	m.setJump(true);
}




