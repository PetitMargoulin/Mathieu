#include "Weapon.h"

Weapon::Weapon(int life, int ammo)
{
	m_life = life;
	m_exist = true;
	m_ammo = ammo;
}

Weapon::~Weapon()
{
}

bool Weapon::isExist()
{
	if (m_life == 0)
	{
		m_exist = false;
	}
	return m_exist;
}
