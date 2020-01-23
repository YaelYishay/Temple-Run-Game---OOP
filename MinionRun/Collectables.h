#pragma once
#include <iostream>
#include <memory>
#include "DataBase.h"
#include <string>
#include "Player.h"
#include "Object.h"

class Factory;
using sf::Sprite;
using std::shared_ptr;

enum ObjectIndex
{
	BOOST, TREASURE, COIN, ROCK,BRIDGE
};

class Collectables :public Object
{
public:
	std::shared_ptr<sf::Texture> getTexture() { return m_pic; }
	void draw(RenderWindow & , float , sf::Vector3f , float , double );
	bool collides(const unique_ptr<Player>& player);

protected:
	shared_ptr<sf::Texture> m_pic;
	int m_destX;
	int m_destY;
	int m_destW;
	int m_destH;


};