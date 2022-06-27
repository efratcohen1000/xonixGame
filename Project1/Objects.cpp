#include "Objects.h"

Objects::Objects()
{}

Objects::~Objects()
{}

bool Objects::colideIsIn(sf::Vector2f pos)
{
	return(m_image.getGlobalBounds().contains(float(pos.x), float(pos.y)) ||
		m_image.getGlobalBounds().contains(float(pos.x+m_size), float(pos.y+m_size)));	
}