#pragma once
#include <vector>
#include "DataBase.h"
#include "Factory.h"
#include "Coin.h"
#include "Player.h"
#include "CollisionHandling.h"
using namespace sf;
using std::make_shared;

using std::shared_ptr;

class Line
{
public:
	Line(int);
	~Line() { ; }
	void convert(int, int, int);
	void draw(RenderWindow&);
	Vector3f getCenter()const { return m_center; }
	void setClip(float c) { m_clip = c; }
	bool hasCollect()const;
	unique_ptr<Collectables> getCollect() { return move(m_collect); }
	bool collides(const unique_ptr<Player>& player);

private:
	void setCollect(int);
	void drawObject(RenderWindow&,double)const;
	unique_ptr<Collectables> m_collect;
	shared_ptr<Texture> m_texture;
	vector<Texture> m_objects;
	Vector2f m_objX;    // objects position
	double m_collectX;  // collect x position
	Vector3f m_center; //3d center of line
	float z,  //screen coord
		  m_scale,
		  m_clip;

};

