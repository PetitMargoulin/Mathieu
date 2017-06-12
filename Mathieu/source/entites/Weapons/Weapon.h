#pragma once
class Weapon
{
public:
	Weapon(int life, int ammo);
	~Weapon();
	bool isExist();

private:
	bool m_ammo;
	bool m_exist;
	int m_life;
};