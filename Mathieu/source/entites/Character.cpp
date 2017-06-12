#include "Character.h"

Character::Character()
{
	m_alive = true;
	m_skin = 1;

}

Character::Character(int skin)
{
	m_alive = true;
	m_skin = skin;

}

Character::~Character()
{
}

bool Character::isAlive()
{
	return m_alive;
}

void Character::kill()
{
	m_alive = false;
}
