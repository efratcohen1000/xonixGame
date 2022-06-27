#pragma once
#include "Demon.h"
#include "Board.h"
#include "Packman.h"
class Dsmart :
	public Demon
{
public:
	Dsmart(char c, sf::Vector2f pos, sf::Color color_shedon, float size);
	~Dsmart();
	void draw(sf::RenderWindow & window);
	void move(Board &b, Packman &p);
	bool colide(MoveObject * o);
private:
	sf::Color m_color_shedon;
	int m_size;
	sf::Vector2f m_d;
};