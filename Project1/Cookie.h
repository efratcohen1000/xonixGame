#pragma once
#include "StaticObject.h"
#include "Packman.h"
class Cookie :
	public StaticObject
{
public:
	Cookie(char c, sf::Vector2f pos, float m_size);
	~Cookie();
	void draw(sf::RenderWindow & window);
	bool colideIsIn(sf::Vector2f pos);
	double getNewSpeed();
	bool colide(MoveObject * o);
	bool is_eaten() { return m_eat; } 
private:
	sf::Color m_color_cookie;
	bool m_eat;
	int m_time;
	double m_speed;
};


