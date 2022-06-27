#include "Packman.h"



Packman::Packman():
	m_score(0)
{
	m_texture.loadFromFile("packman.PNG");
	m_life = 3;
	m_image.setTexture(m_texture);
	m_speed = 1;
	m_dTime = 0;
}

Packman::~Packman()
{}

void Packman::move(sf::Vector2f pos, Objects* o)
{
	int t = m_c.getElapsedTime().asSeconds();
	if (t < m_dTime)
	{
		pos.x *= m_speed;
		pos.y *= m_speed;
	}
	else
		m_speed = 1;

	pos = m_loction + pos;
	if (o == nullptr)
	{
		setPosition(pos);
		return;
	}
	//בודק עם ווקטור הסטטי
	if (o->colide(this))
		setPosition(pos);

}

void Packman::draw(sf::RenderWindow & window)
{
	m_image.setPosition(m_loction.x, m_loction.y);
	m_image.setColor(m_color);
	m_image.setScale(m_size*0.01, m_size*0.01);
	window.draw(m_image);
}

void Packman::setPosition(sf::Vector2f pos)
{
	m_loction = pos;
}

void Packman::setColor(sf::Color color)
{
	m_color = color;
}

void Packman::setSize(float size)
{
	m_size = size;
}

///מיקום פקמן
sf::Vector2f Packman::getLocPackman()
{
	return  m_loction;
}

void Packman::eat(int time, double speed)
{
	m_speed *= speed;
	m_dTime = m_c.getElapsedTime().asSeconds() + time;
	
}
bool Packman::colide(MoveObject * o)
{
	updateLife();
	returnToHome();
	return true;
}
//bool Packman::colideIsIn(sf::Vector2f pos)
//{
//	return(m_image.getGlobalBounds().contains(float(pos.x ), float(pos.y  )) ||
//		m_image.getGlobalBounds().contains(float(pos.x + m_size ), float(pos.y + m_size ))
//		|| m_image.getGlobalBounds().contains(float(pos.x  ), float(pos.y + m_size))
//		|| m_image.getGlobalBounds().contains(float(pos.x - m_size), float(pos.y)));
//}
