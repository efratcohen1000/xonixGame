#include "Dsmart.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>


Dsmart::Dsmart(char c, sf::Vector2f pos, sf::Color color_shedon, float size) :
	m_color_shedon(color_shedon)
{
	m_loction = pos;
	m_homeLoction = pos;
	m_texture.loadFromFile("shedon.PNG");

	m_image.setTexture(m_texture);
	m_image.setPosition(m_loction.x, m_loction.y);
	m_image.setColor(color_shedon);
	m_image.setScale(size*0.013, size*0.012);
	m_size = size;
	m_d = { 0, 0 };
	int numrun;
	numrun = rand() % 4;
	switch (numrun)
	{
	case 0:
		m_d.y = 1;
		break;
	case 1:
		m_d.y = -1;
		break;
	case 2:
		m_d.x = 1;
		break;
	case 3:
		m_d.x = -1;
		break;
	}
}

Dsmart::~Dsmart()
{}

void Dsmart::draw(sf::RenderWindow & window)
{
	m_image.setPosition(m_loction.x, m_loction.y);
	window.draw(m_image);
}



void Dsmart::move(Board &b, Packman &p)
{
	sf::Vector2f pos = m_loction;
	int numrun;
	srand(time(NULL));
	numrun = rand() % 4;
	if (numrun % 2 == 0)
	{
		if (m_loction.x < p.getLocPackman().x)
			pos.x++;
		else
			pos.x--;
	}
	else
	{
		if (m_loction.y < p.getLocPackman().y)
			pos.y++;
		else
			pos.y--;
	}

	StaticObject *o = b.getStaticObj(pos);
	if (o == nullptr || o->colide(this))
	{
		m_loction = pos;
		if (p.colideIsIn(pos))
		{
			p.colide(this);
			returnToHome();
		}
	}

	
}

bool Dsmart::colide(MoveObject * o)
{
	const type_info& objectType = typeid (*o);
	if (objectType == typeid (Packman))
	{
		dynamic_cast<Packman*>(o)->updateLife();
		dynamic_cast<Packman*>(o)->returnToHome();
	}
	return false;

}