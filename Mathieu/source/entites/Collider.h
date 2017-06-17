#pragma once
#include <SFML\Graphics.hpp>

class Collider
{
public:
	typedef enum
	{
		wall,
		ground,
		character,
		weapon
	} type;
	Collider(int x, int y, int w, int h, type t);
	~Collider();
	void update(int x, int y, int w, int h);
	sf::IntRect box() const;
	type whatType() const;
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	sf::IntRect m_rect;
	type m_type;
};

