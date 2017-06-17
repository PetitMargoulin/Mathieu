#include "Collider.h"



Collider::Collider(int x, int y, int w, int h, type t)
{
	m_rect = { x, y, w, h };
	m_type = t;
}


Collider::~Collider()
{
}

void Collider::update(int x, int y, int w, int h)
{
	m_rect = { x, y, w, h };
}

sf::IntRect Collider::box() const
{
	return m_rect;
}

Collider::type Collider::whatType() const
{
	return m_type;
}
