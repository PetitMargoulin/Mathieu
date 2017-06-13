#include "Animation.h"

Animation::Animation(sf::Sprite* sprite, std::vector <sf::Vector2f> const& positions, int speed)
{
	m_sprite = sprite;
	m_positions = positions;
	m_indexObjectivePos = 0;
	m_speed = speed;
}

bool Animation::isAnimating()
{
	return m_animating;
}

void Animation::start()
{
	m_animating = true;
}

void Animation::stop()
{
	m_animating = false;
}

void Animation::setDir()
{
	dir_x = m_positions[m_indexObjectivePos].x - m_currentPos.x;
	dir_y = m_positions[m_indexObjectivePos].y - m_currentPos.y;
}

void Animation::next()
{
	this->setDir();
	log(m_indexObjectivePos);
	if (m_animating)
	{
		m_sprite->move(sf::Vector2f(dir_x * m_speed, dir_y * m_speed));
		m_currentPos = sf::Vector2f(dir_x * m_speed, dir_y * m_speed);

		std::cout << "m_currentPos: (" << m_currentPos.x << "," << m_currentPos.y << ")" << std::endl;
		std::cout << "m_positions: (" << m_positions[m_indexObjectivePos].x << "," << m_positions[m_indexObjectivePos].y << ")" << std::endl;
		if (m_currentPos == m_positions[m_indexObjectivePos])
		{
			if (m_positions.size() == m_indexObjectivePos - 1)
				m_animating = false;
			else
				m_indexObjectivePos++;
		}
	}
}

