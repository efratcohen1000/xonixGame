#include "Screen.h"



Screen::Screen() :
	m_shape(sf::Vector2f{ 500,500 }), m_rec(sf::Vector2f{ 200,50 }), m_isNoClose(true), m_menu(sf::Vector2f{ 1800, 100 })
{	
	m_font.loadFromFile("sansation.ttf");
	m_texture.loadFromFile("screenOpen.PNG");
	m_image.setTexture(m_texture);

	sf::RenderWindow window(sf::VideoMode(500, 500), "Packman");
	while (window.isOpen())
	{
		//sf::SoundBuffer beginningSoundBuffer;
		//if (!beginningSoundBuffer.loadFromFile("pacman_beginning.wav"))
		//	return 0;
		//sf::Sound ballSound(beginningSoundBuffer);
		sf::Event event;
		while (window.pollEvent(event))
		{
			sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
			/*אם לחץ על לחצן דל התחלת משחק*/
			if (mousePosition.x <= 340 && mousePosition.x >= 140
				&& mousePosition.y <= 490 && mousePosition.y >= 440)
			{
				window.clear();
				window.close();

			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
				m_isNoClose = false;
			}
			if (mousePosition.x <= 340 && mousePosition.x >= 140
				&& mousePosition.y <= 430 && mousePosition.y >= 390)
			{
				window.close();
				m_isNoClose = false;

			}
		}

		window.clear();

		window.draw(m_shape);
		window.draw(m_image);
		//window.draw(m_rec);
		window.display();
	}

}


Screen::~Screen()
{}

bool Screen::isNoClose()
{
	return m_isNoClose;
}

void Screen::menuShow(sf::RenderWindow& windowPlay, int level, int score, int life)
{
	m_text.setFont(m_font);
	m_text.setCharacterSize(50);
	m_text.setPosition(100, 25);
	m_text.setFillColor(sf::Color::White);
	m_menu.setPosition(0, 0);
	m_menu.setFillColor(sf::Color::Black);
	windowPlay.draw(m_menu);

	m_text.setString("Level: " + std::to_string(level)
		+ "    Score: " + std::to_string(score) + "   Life:  " + std::to_string(life)) ;
	windowPlay.draw(m_text);
}

void Screen::showScore(sf::RenderWindow& window)
{
	window.draw(m_text);
}



