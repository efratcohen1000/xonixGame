#include "Cookie.h"



Cookie::Cookie(char c, sf::Vector2f pos, float size)
{
	m_eat = false;
	m_size =size;
	m_loction = pos;
	if (c == '*')
	{
		m_color_cookie = sf::Color::Red;
		m_speed = 1;
		m_time = 0;
	}
	else if (c == 'I')
	{
		m_color_cookie = sf::Color::Green;
		m_speed = 0.9;
		m_time = 7;
	}
	else if (c == 'K')
	{
		m_color_cookie = sf::Color::Blue;
		m_speed = 1.2;
		m_time = 14;
	}
	m_texture.loadFromFile("cookie.PNG");
	m_image.setTexture(m_texture);
	m_image.setPosition(m_loction.x, m_loction.y);
	m_image.setColor(m_color_cookie);
	m_image.setScale(size*0.0127, size*0.013);

}


Cookie::~Cookie()
{}

void Cookie::draw(sf::RenderWindow & window)
{
	window.draw(m_image);
}

bool Cookie::colideIsIn(sf::Vector2f pos)
{
	return(m_image.getGlobalBounds().contains(float(pos.x + (m_size/2)), float(pos.y + (m_size/2))));
}

double Cookie::getNewSpeed()
{
	return 0.0;
}

bool Cookie::colide(MoveObject * o)
{
	const type_info& objectType = typeid (*o);
	if (objectType == typeid (Packman))//eat())
	{//delet the cookie 
		m_eat = true;
		m_texture.loadFromFile("empty.PNG");
		m_image.setTexture(m_texture);
		m_image.setScale(0,0);
		dynamic_cast<Packman*>(o)->eat(m_time, m_speed);
		return true;
	}
	return true;
}