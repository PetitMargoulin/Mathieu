#include "Block.h"

Block::Block(sf::RenderWindow* win, float x, float y, float w, float h, type t)
{
	window = win;
	m_width = w;
	m_height = h;
	m_type = t;
	this->initSprite();
	this->setPosition(sf::Vector2f(x, y));
}

Block::~Block()
{
}

void Block::initSprite()
{
	float widthTexture = 58.f;
	float heightTexture = 58.f;

	switch (m_type)
	{
	case ground:
		if (!m_texture.loadFromFile("ressources/textures/Basic_Sprites.jpg", sf::IntRect(58, 64, widthTexture, heightTexture)))
			log("error");
		m_texture.setSmooth(true);
		m_sprite.setTexture(m_texture);
		m_sprite.setScale(sf::Vector2f(1, 1));
		m_sprite.scale(sf::Vector2f(m_width / widthTexture, m_height / heightTexture));
	//case wall:
		
	}
}

void Block::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
	m_x = pos.x;
	m_y = pos.y;
}

void Block::draw()
{
	window->draw(m_sprite);
}
