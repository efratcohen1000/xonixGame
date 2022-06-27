#include "Wall.h"



Wall::Wall(char c, sf::Vector2f pos, float size)
{
	m_size = size;
	m_loction = pos;
	if (c == '#')
	{
		m_color_wall = sf::Color::Red;

	}

	else if (c == 'E')
	{
		m_color_wall = sf::Color::Green;
	}

	else if (c == 'D')
	{
		m_color_wall = sf::Color::Blue;
	}
	m_texture.loadFromFile("wall.jpg");

	m_image.setTexture(m_texture);
	m_image.setPosition(m_loction.x, m_loction.y);
	m_image.setColor(m_color_wall);
	m_image.setScale(size*0.0135, size*0.016);
}

Wall::~Wall()
{}

void Wall::draw(sf::RenderWindow & window)
{
	window.draw(m_image);
}