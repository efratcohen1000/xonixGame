#include "Drundom.h"



Drundom::Drundom(char c, sf::Vector2f pos, sf::Color color_shedon, float size) :
	m_color_shedon(color_shedon)
{
	m_loction = pos;
	m_homeLoction = pos;
	m_texture.loadFromFile("shedon.PNG");

	m_image.setTexture(m_texture);
	m_image.setPosition(m_loction.x, m_loction.y);
	m_image.setColor(m_color_shedon);
	m_image.setScale(size*0.0127, size*0.012);
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


Drundom::~Drundom()
{
}

void Drundom::draw(sf::RenderWindow & window)
{
	m_image.setPosition(m_loction.x, m_loction.y);
	window.draw(m_image);
}


void Drundom::move(Board &b, Packman &p)
{
	sf::Vector2f pos = m_loction + m_d;
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
	else
	{
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

}
bool Drundom::colide(MoveObject * o)

{
	const type_info& objectType = typeid (*o);
	if (objectType == typeid (Packman))
	{
		dynamic_cast<Packman*>(o)->updateLife();
		dynamic_cast<Packman*>(o)->returnToHome();
	}
	return false;

}

