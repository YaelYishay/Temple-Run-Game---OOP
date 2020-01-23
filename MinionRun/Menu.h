#pragma once
#include "PlayButton.h"
#include "ExitButton.h"
#include "DataBase.h"
#include <algorithm>

// Invoker Class
class Menu
{
public:
	Menu(unique_ptr<Button> b1, unique_ptr<Button> b3);
	~Menu() { ; }
	void activate(RenderWindow&);

private:
	sf::Music m_sound;
	Texture m_menu; 
	vector<unique_ptr<Button>> m_buttons;
	void draw(RenderWindow&)const;
	void buttonPressed(Event);
};