#include "stdafx.h"
#include "Menu.h"

//create menu (using  command design pattern)
Menu::Menu(unique_ptr<Button> b1, unique_ptr<Button> b3)
	:m_menu(DataBase::instance().loadMenu())
{
	DataBase::instance().getMenuSound().play();
	m_buttons.emplace_back(move(b1));
	m_buttons.emplace_back(move(b3));
}

//activate menu and handle menu
void Menu::activate(sf::RenderWindow& window)
{

	sf::Event e;

	while (window.isOpen()) {

		window.clear();
		draw(window);

		if (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::MouseButtonReleased:
				buttonPressed(e);
				break;
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Keyboard::Escape:
				window.close();
				break;
			default:
				break;
			}
			window.display();
		}
	}
}

//draw the menu window
void Menu::draw(sf::RenderWindow& window)const
{
	sf::Sprite menu;
	menu.setTexture(m_menu);
	window.draw(menu);
}

// implementation of buttons on the menu
void Menu::buttonPressed(sf::Event e)
{
	std::for_each(m_buttons.begin(), m_buttons.end(), [&e](const auto& i) {
		if (i->contains(e))
		{
			DataBase::instance().getMenuSound().stop();
			i->execute(); }
	});
}
