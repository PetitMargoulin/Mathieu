#pragma once


class Character
{
public:
	Character();
	Character(int skin);
	~Character();
	bool isAlive();
	void kill();


private:
	bool m_alive;
	int m_skin;



};

