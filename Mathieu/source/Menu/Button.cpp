#include "Button.h"

Button::Button(string name ,int x, int y ,int height, int width, sf::RenderWindow* window )
{
	m_pressed = false;
	m_x = x;
	m_y = y;
	m_height = height;
	m_width = width;
	m_window = window;
	m_name = name;
	rect.setSize(sf::Vector2f(m_width, m_height));
	rect.setPosition(sf::Vector2f(m_x, m_y));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(10);
	rect.setOutlineColor(sf::Color(252, 252, 252));
	m_text.setFont(m_font);
	m_text.setString(m_name);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(20);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(sf::Vector2f(m_x + 50, m_y - 50));
	
}

Button::~Button()
{
}

bool Button::isPressed()
{
	return m_pressed;
}

void Button::draw()
{
	
	m_window->draw(rect);
	m_window->draw(m_text);
}
