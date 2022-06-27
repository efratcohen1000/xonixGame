#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
class Wall :
	public StaticObject
{
public:
	Wall(char c, sf::Vector2f pos, float size);
	~Wall();
	void draw(sf::RenderWindow & window);
	bool colide(MoveObject * o) { return false; }
private:
	sf::Color m_color_wall;
};
