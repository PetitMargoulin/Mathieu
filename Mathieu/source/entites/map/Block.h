#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

#define log(x) std::cout << x << std::endl

class Block
{
public:
	typedef enum
	{
		ground,
		wall
	} type;

	Block(sf::RenderWindow* win, float x, float y, float w, float h, type t);
	~Block();
	void initSprite();
	void setPosition(sf::Vector2f pos);
	void draw();
private:
	sf::RenderWindow* window;
	float m_x;
	float m_y;
	float m_width;
	float m_height;
	type m_type;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};