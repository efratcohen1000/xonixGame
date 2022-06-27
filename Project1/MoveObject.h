#pragma once
#include "Objects.h"
class MoveObject :
	public Objects
{
public:
	MoveObject();
	virtual ~MoveObject();
	void virtual draw(sf::RenderWindow & window) = 0;
	void setHomeLocation(sf::Vector2f pos) { m_homeLoction = pos; }
	void returnToHome() { m_loction = m_homeLoction; }
	bool virtual colide(MoveObject * o) = 0;
protected:
	sf::Vector2f m_homeLoction;
};
