#include "stdafx.h"
#include "Player.h"
#include "RunningState.h"

//manages player settings

//initialize player position and state
Player::Player()
	:m_position{ 512, 520 }
{
	m_state = std::make_unique<RunningState>();
	m_state->enter(*this);
}

// handle player movements from user input
void Player::handleInput(sf::Event e)
{
	unique_ptr<State> state_ = m_state->handleInput(e);
	if (state_)
	{
		m_state = std::move(state_);
		m_state->enter(*this);
	}
}

//set the texture for the current state
void Player::setGraphics(vector<Sprite> spriteState){
	m_player = spriteState;
}

// draw player setting including player sprite,score,lives
void Player::draw(sf::RenderWindow& window, float deltaTime) const
{
	Text text("SCORE " + std::to_string(m_score) + "  LIVES " + std::to_string(m_lives), DataBase::instance().getFont());
	text.setPosition({ 150,10 });
	text.setCharacterSize(50);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Magenta);

	window.draw(text);

	static float lastDraw = 0;
	static int index = 0;
	
	window.draw(m_player[index % m_player.size()]);

	if (deltaTime - lastDraw < 1 / 7.f)
		return;

	lastDraw = deltaTime; 
	index++;

}

void Player::setScore(int i)
{
	m_score += i; 
	if (m_score < 0) {
		m_lives--;
		m_score = 0;
	}
}
