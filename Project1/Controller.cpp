#include "Controller.h"
#include <iostream>
using std::cout;

Controller::Controller()
	:m_packman(), m_demon(), m_window(sf::VideoMode(1800, 1000), "Packman"), m_numOfLevel(0)
{
	m_board.loadBoard(m_window);
	m_board.readFile(m_packman, m_window, m_demon);
}

Controller::~Controller()
{}

void Controller::runGame()
{
	sf::Vector2f pos(m_packman.getLocPackman()), d(0, 0);
	while (m_window.isOpen() && !(m_packman.isGameOver()) && m_numOfLevel != 4)
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			eventReact(event, d);
			m_screen.showScore(m_window);
		}
		checkAndMove(pos, d);
	}
}

sf::Vector2f Controller::act(sf::Event e)
{
	sf::Vector2f direct(0, 0);
	bool crash = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direct = { 0,-1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direct = { 0, 1 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direct = { 1,0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direct = { -1,0 };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		direct = { 0,0 };
	}
	return direct;
}

//-------------------------------------------------
void Controller::draw(sf::RenderWindow& window)
{
	m_board.draw(m_window);
	//נרצה שיודפס תחילה הלוח עליו הפקמן והשדונים
	for (auto& c : m_demon)
		c->draw(window);
	m_packman.draw(window);
}

void Controller::clear()
{
	for (auto &d : m_demon)
		delete d;
	m_demon.clear();
	m_board.deleteAll();
}

void Controller::checkAndMove(sf::Vector2f& pos, sf::Vector2f& d)
{
	pos += d;

	//בודק במערך הסטטי האם הוא יכול לזוז 
	m_packman.move(d, m_board.getStaticObj(pos));


	//בודק מול ווקטור השדונים האם הוא יכול לזוז
	for (int i = 0; i < m_demon.size(); i++)
		if (m_demon[i]->colideIsIn(m_packman.getLocPackman()))
			m_packman.move(pos, m_demon[i]);
	for (int i = 0; i < m_demon.size(); i++)
	{
		m_demon[i]->move(m_board, m_packman);
	}
	//בודק מול ווקטור השדונים האם הוא יכול לזוז

	pos = (m_packman.getLocPackman());
	m_window.clear();

	m_screen.menuShow(m_window, m_board.getNumOfLevel(), m_packman.getScore(), m_packman.getLife());
	m_screen.showScore(m_window);
	//score
	if (m_board.isAte())
		m_packman.setScore(m_board.numOfDemon()*2);

	
	

	draw(m_window);
	m_window.display();


	if (m_board.isLevelOver())
	{//delete demond+board 
		if (m_board.isAte())
			m_packman.setScore(m_board.numOfDemon()*50);
		clear();
		m_board.newLevel(m_packman, m_window, m_demon);
		m_numOfLevel++;
	}
}

void Controller::eventReact(sf::Event event, sf::Vector2f& d)
{
	m_board.draw(m_window);
	//ballSound.play();
	if (event.type == sf::Event::Closed)
		m_window.close();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		d = act(event);
	}
}
