#pragma once
#include "MoveObject.h"
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include<memory>
class Packman :
	public MoveObject
{
public:
	Packman();
	~Packman();
	void move(sf::Vector2f pos, Objects* o);
	void draw(sf::RenderWindow & window);
	void setPosition(sf::Vector2f pos);
	bool isGameOver() { return (m_life == 0); }
	void setColor(sf::Color color);
	void updateLife() { m_life--; }
	void setSize(float size);
	sf::Vector2f getLocPackman();
	void eat(int time, double speed);
	bool colide(MoveObject * o);
	int getScore() { return m_score; }
	int getLife() { return m_life; }
	void setScore(int score) { m_score += score ; }
	//bool colideIsIn(sf::Vector2f pos);
private:
	
	double m_speed;
	int m_life;
	int m_score;
	int m_direction;
	int m_dTime;
	sf::Color m_color;
	sf::Clock m_c;
};

