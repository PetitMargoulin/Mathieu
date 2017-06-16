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
}
