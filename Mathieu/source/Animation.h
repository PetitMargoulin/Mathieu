#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

#define log(x) std::cout << x << std::endl

class Animation
{
public:
	Animation(sf::Sprite* sprite, std::vector <sf::Vector2f> const& positions, float speed);
	bool isAnimating();
	void start();
	void stop();
	void setDir();
	void next();
private:
	sf::Sprite* m_sprite;
	std::vector <sf::Vector2f> m_positions;
	bool m_animating;
	int m_indexObjectivePos;
	sf::Vector2f m_currentPos;
	float m_speed;
	float dir_x;
	float dir_y;
};