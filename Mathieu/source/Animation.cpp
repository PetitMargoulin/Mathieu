#include "Animation.h"

Animation::Animation(sf::Sprite* sprite, std::vector <sf::Vector2f> const& positions, float constSpeed)
{
	m_sprite = sprite;
	m_positions = positions;
	m_indexObjectivePos = 0;
	m_constSpeed = constSpeed;
	m_onOrigin = true;
	m_currentPos = sf::Vector2f(0, 0);
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
	dir_x = m_positions[m_indexObjectivePos].x;
	dir_y = m_positions[m_indexObjectivePos].y;
	m_distance = sqrtf(powf(m_positions[m_indexObjectivePos].y, 2) + powf(m_positions[m_indexObjectivePos].x, 2));
	m_speed = m_constSpeed / m_distance;
}

void Animation::next()
{
	if (m_animating)
	{
		if (m_onOrigin)
			this->setDir();
		m_sprite->move(sf::Vector2f(roundf(dir_x * m_speed), roundf(dir_y * m_speed)));
		m_currentPos = m_currentPos + sf::Vector2f(roundf(dir_x * m_speed), roundf(dir_y * m_speed));
		m_onOrigin = false;

		std::cout << "m_currentPos: (" << m_currentPos.x << "," << m_currentPos.y << ")" << std::endl;
		std::cout << "m_positions: (" << m_positions[m_indexObjectivePos].x << "," << m_positions[m_indexObjectivePos].y << ")" << std::endl;
		if (m_currentPos == m_positions[m_indexObjectivePos])
		{
			if (m_positions.size() <= m_indexObjectivePos + 1)
				m_animating = false;
			else
			{
				m_indexObjectivePos++;
				m_onOrigin = true;
				m_currentPos = sf::Vector2f(0, 0);
			}
		}
	}
}

