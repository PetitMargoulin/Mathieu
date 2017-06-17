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
	if (!m_font.loadFromFile("ressources\\Font\\arial.ttf"))
	{
		cout << "Nop" << endl;
		//error;
	}
	m_text.setFont(m_font);
	m_text.setString(m_name);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(10);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(sf::Vector2f(m_x + 20, m_y + 50));
	
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

void Button::mouseOn()
{
	
	int x = sf::Mouse::getPosition(*m_window).x;
	int y = sf::Mouse::getPosition(*m_window).y;
	if (x > m_x && x < m_x + m_width && y > m_y && y < m_y + m_height)
	{
		rect.setFillColor(sf::Color::White);
		m_text.setFillColor(sf::Color::Black);
	}
	if (!(x > m_x && x < m_x + m_width && y > m_y && y < m_y + m_height))
	{
		rect.setFillColor(sf::Color::Transparent);
		m_text.setFillColor(sf::Color::White);
	}
}
