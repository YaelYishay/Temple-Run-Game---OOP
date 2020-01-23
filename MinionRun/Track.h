#pragma once
#include "Line.h"
#include "DataBase.h"
#include "Player.h"

class Track
{
public:
	Track(std::unique_ptr<Player>& m);
	~Track() { ; }
	bool run(RenderWindow &);

private:
	void draw(RenderWindow &)const;
	void drawRoad(RenderWindow &)const;
	void drawLines(RenderWindow & )const;
	void drawQuad(RenderWindow &, Color ,float,float,float,float,float,float) const;
	
	unique_ptr<Player>& m_player;
	vector<unique_ptr<Line>> m_lines;
	Sprite m_sBackground;
	Texture m_bg;

	float m_width = 1024; //width screen
    float m_height = 768; // height screen
	int	m_size = 1500;  // size track
	int m_startPos = 1; //first line printed 
};
