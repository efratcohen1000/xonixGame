#pragma once
#include <SFML/Graphics.hpp>
class MoveObject;
class Objects
{
public:
	Objects();
	virtual ~Objects();
	void virtual  draw(sf::RenderWindow & window) = 0;
	virtual bool colideIsIn(sf::Vector2f pos);
	bool virtual colide(MoveObject * o) = 0;
protected:
	float m_size;
	sf::Vector2f m_loction;
	sf::Texture m_texture;
	sf::Sprite m_image;
};
