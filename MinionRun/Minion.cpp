#include "stdafx.h"
#include "Minion.h"
#include "RunningState.h"


Minion::Minion()
	:m_state(std::make_unique<RunningState>()), m_x(0),m_y(1500), m_z(0)
{
	m_state->enter(*this);
}

void Minion::handleInput(UserInput input)
{
	unique_ptr<State> state_ = m_state->handleInput(input);
	if (state_)
	{
		m_state = std::move(state_);
		m_state->enter(*this);
	}
}

void Minion::draw(sf::RenderWindow& window, float deltaTime)
{
	static float lastDraw = 0;
	static int index = 0;
	
	window.draw(m_minion[index % m_minion.size()]);

	if (deltaTime - lastDraw < 1 / 9.f)
		return;

	lastDraw = deltaTime; 
	index++;

}
