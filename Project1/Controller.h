#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "Demon.h"
#include "Board.h"
#include "Packman.h"
#include "Screen.h"
class Controller
{
public:
	Controller();
	~Controller();
	void runGame();
	sf::Vector2f act(sf::Event e);
	void draw(sf::RenderWindow& window);
	void clear();
	void checkAndMove(sf::Vector2f& pos, sf::Vector2f& d);
	void eventReact(sf::Event event, sf::Vector2f& d);
private:

	Screen m_screen;
	std::vector<Demon*>m_demon;
	Packman m_packman;
	Board m_board;
	sf::RenderWindow m_window;
	int m_numOfLevel;
};