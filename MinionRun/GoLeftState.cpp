#include "stdafx.h"
#include "GoLeftState.h"
#include "JumpingState.h"
#include "DuckingState.h"
#include "GoRightState.h"
#include "RunningState.h"

//handle movements while veering to the left
unique_ptr<State> GoLeftState::handleInput(sf::Event e)
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
