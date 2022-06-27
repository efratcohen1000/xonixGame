#include "Board.h"

#include <string>
#include <stdlib.h>
#include <time.h>
using std::cerr;
using std::ifstream;
using std::fstream;
using std::endl;

Board::Board() :
	m_level(1), m_num_of_demon(0), m_isAte(false)
{}

Board::~Board()
{}

void Board::loadBoard(sf::RenderWindow& window)
{
	m_size = m_level * 5;
	int numsRect = m_level * 5;
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setPosition(100, 50);
	m_size = float(800 / m_size);
	for (int i = 0; i < numsRect; i++)
		for (int j = 0; j < numsRect * 2; j++)
		{
			sf::Vector2f s(m_size, m_size);
			sf::RectangleShape rect(s);
			rect.setFillColor(sf::Color::Black);
			rect.setOutlineThickness(3.0);
			rect.setOutlineColor(sf::Color::Black);
			sf::Vector2f p(float(100 + j * m_size), float(105 + i * m_size));
			rect.setPosition(p);
			window.draw(rect);
		}
}

void Board::newLevel(Packman& p, sf::RenderWindow& window, std::vector<Demon*>& demons)
{
	m_level++;
	loadBoard(window);
	readFile(p, window, demons);
	//לזמן את readFile
}

void Board::readFile(Packman& p, sf::RenderWindow& window, std::vector<Demon*>& demons)
{
	
	static ifstream m_file("level.txt");
	if (!m_file.is_open())
		cerr << "The file failed to open" << endl;

	sf::Vector2f d(0, 100);

	//כל פעם לקרוא את הקובץ מהקובץ טקסט 
	//לפי הסימנים יש לבדוק  איזה סוג תוו מדובר לפי סוג התו יש 
	//להדפיס את התמונה המסויימת פקמן שדון חומה או עוגיה
	startNumOfCookie = 0;
	char c;
	int i = 0, j = 0;
	int index_static = 0;
	while (i < m_level * 5 && !m_file.eof())
	{
		if (j > (m_level * 10))
			j = 0;
		c = m_file.get();
		sf::Vector2f pos(0, 0);
		if (c == '\n')
			i++;
		pos.x = j * m_size + d.x + 100;
		pos.y = i * m_size + d.y + 5;
		//קליטת הקיר והעוגיה
		if (c == '#' || c == 'E' || c == 'D')
		{
			m_static_obj.push_back(new Wall(c, pos, m_size));
	
		}
		else if (c == '*' || c == 'I' || c == 'K')
		{
			m_static_obj.push_back(new Cookie(c, pos, m_size));
			startNumOfCookie++;
		}
		//קליטת הפקמן 
		else if (c == ' S' || c == 'W' || c == '@')
		{
			p.setPosition(pos);
			p.setHomeLocation(pos);
			if (c == 'S')
				p.setColor(sf::Color::Blue);
			else if (c == 'W')
			{
				p.setColor(sf::Color::Green);
			}
			else
			{
				p.setColor(sf::Color::Red);
			}
			p.setSize(m_size);
		}
		index_static++;
		j++;
		//קליטת השדונים
		//יש שדון אחד חכם השאר רנדומלים
		//לשנות את סדר הדפסת השדונים החכמים והרנדומלים באופן רנדומלי
		sf::Color m_color_shedon;
		if (c == '%' || c == 'T' || c == 'G')
		{
			if (c == '%')
			{
				m_color_shedon = sf::Color::Red;
			}
			else if (c == 'T')
			{
				m_color_shedon = sf::Color::Blue;
			}
			else if (c == 'G')
			{
				m_color_shedon = sf::Color::Green;
			}
			int numrun;
			srand(time(NULL));
			numrun = rand() % 4;
			if (numrun != 1)
				
				demons.push_back(new Drundom(c, pos, m_color_shedon, m_size));
			else
				demons.push_back(new Dsmart(c, pos, m_color_shedon, m_size));
			m_num_of_demon++;
		}
	}
}

void Board::deleteAll()
{
	//לסגור את הקובץ WINDOW נראה לי בCONTROLLER
	//הcontroler יזמן את הפונקציה הנ"ל וימחק את הלוח.
	for (auto& c : m_static_obj)
		delete(c);
	m_static_obj.clear();
}

int Board::numOfDemon()
{
	return m_num_of_demon;
}

void Board::draw(sf::RenderWindow & window)
{
	for (auto& c : m_static_obj)
		c->draw(window);
}

//אם יש התנגשות בין אובייקט סטטי לאובייקט זז
StaticObject* Board::getStaticObj(sf::Vector2f pos)
{
	for (int i = 0; i < m_static_obj.size(); i++)
		if (m_static_obj[i]->colideIsIn(pos))
			return m_static_obj[i];
	return nullptr;
}

bool Board::isLevelOver()
{
	m_isAte = false;
	numOfCookie = 0;
	for (auto& c : m_static_obj)
	{
		const type_info& objectType = typeid (*c);
		if (objectType == typeid(Cookie))
			if (!(dynamic_cast<Cookie*>(c))->is_eaten())
				numOfCookie++;
		//score
		if (startNumOfCookie - 1 == numOfCookie)
		{
			startNumOfCookie = numOfCookie;
			m_isAte = true;
		}
	}
	return (numOfCookie == 0);
}

