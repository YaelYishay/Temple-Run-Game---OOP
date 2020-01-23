#include "stdafx.h"
#include "RunningState.h"
#include "JumpingState.h"
#include "DuckingState.h"
#include "GoLeftState.h"
#include "GoRightState.h"

RunningState::RunningState()
{
}

//handle movements while running   
unique_ptr<State> RunningState::handleInput(sf::Event e)
{
	switch (e.key.code) {

	case sf::Keyboard::Space:
		return std::make_unique<JumpingState>();
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
	}
}

//implement running state
void RunningState::enter(Player & m)
{

	for (int i = 0; i < 4; i++) {
		m_sprite.emplace_back(Sprite(DataBase::instance().loadRuningPlayer(i)));
		m_sprite[i].setPosition(m.getPosition());
	}
	m.setGraphics(m_sprite);

}




