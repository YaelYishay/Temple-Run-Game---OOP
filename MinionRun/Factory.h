#pragma once
#include <memory>
#include <string>
#include <map>
class Obstacle;
class Collectables;

typedef std::map<std::string, std::unique_ptr<Collectables>(*)()> mymap;

class Factory
{
public:
	static std::unique_ptr<Collectables> create(const std::string& name);
	static bool registerit(const std::string& name, std::unique_ptr<Collectables>(*)());


private:
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
};




