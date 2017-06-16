#pragma once
#include <SFML\Graphics.hpp>
#include <string>

using namespace std;
class Button
{

public:

	Button(string name, int x, int y, int height, int width, sf::RenderWindow* window);
	~Button();
	bool isPressed();
	void draw();

private:
	bool m_pressed;
	int m_height;
	int m_width;
	int m_x;
	int m_y;
	sf::RenderWindow* m_window;
	string m_name;
	sf::RectangleShape rect;
};