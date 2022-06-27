#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "StaticObject.h"
#include<memory>
#include"Wall.h"
#include "Cookie.h"
#include "Demon.h"
#include "Drundom.h"
#include "Dsmart.h"
#include "Packman.h"
#include <SFML/Graphics.hpp>
class Board
{
public:
	Board();
	~Board();
	void loadBoard(sf::RenderWindow& window);
	void newLevel(Packman& p, sf::RenderWindow& window, std::vector<Demon*>& demons);
	void deleteAll();
	void readFile(Packman& p, sf::RenderWindow& window, std::vector<Demon*>& demons);
	int numOfDemon();
	void draw(sf::RenderWindow& window);
	StaticObject* getStaticObj(sf::Vector2f pos);
	bool isLevelOver();
	int getNumOfLevel() { return m_level; }
	bool isAte() { return (m_isAte);}
private:
	std::vector<StaticObject*> m_static_obj;
	int m_level;
	int m_num_of_demon;
	int m_size;
	int numOfCookie;//
	int startNumOfCookie;//
	bool m_isAte;
};