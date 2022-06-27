#pragma once

#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#else
#error "Unrecognized configuration!"
#endif
#include <SFML/Graphics.hpp>
class Screen
{
public:
	Screen();
	~Screen();
	bool isNoClose();
	void menuShow(sf::RenderWindow& window, int level, int score, int life);
	void showScore(sf::RenderWindow& window);
private:
	sf::Time m_timer;
	sf::RectangleShape m_shape;
	sf::RectangleShape m_rec;
	sf::Texture m_texture;
	sf::Texture m_texture_button_exit;
	sf::Sprite m_image;
	sf::Texture m_texture_button;
	sf::Sprite m_image_button;
	sf::Sprite m_image_button1;
	sf::RectangleShape button1;
	sf::Text m_name;
	sf::RectangleShape m_menu;
	sf::Text m_text;
	sf::Font m_font;
	float m_s;
	bool m_isNoClose;

};

