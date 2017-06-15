#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include "animation\Animation.h"

#define log(x) std::cout << x << std::endl

void moveSprite(sf::Sprite* spriteTest1, sf::Sprite* spriteTest2);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::Event event;

	sf::Texture textureTest1;
	sf::Sprite spriteTest1;

	sf::Texture textureTest2;
	sf::Sprite spriteTest2;

	if (!textureTest1.loadFromFile("ressources/textures/Simple_Green_Texture.jpg"))
		log("error");
	textureTest1.setSmooth(true);

	if (!textureTest2.loadFromFile("ressources/textures/Simple_Red_Texture.jpg"))
		log("error");
	textureTest2.setSmooth(true);
	
	spriteTest1.setTexture(textureTest1);
	spriteTest1.setTextureRect(sf::IntRect(10, 10, 32, 32));
	spriteTest1.setPosition(sf::Vector2f(10, 50));

	spriteTest2.setTexture(textureTest2);
	spriteTest2.setTextureRect(sf::IntRect(10, 10, 32, 32));
	spriteTest2.setPosition(sf::Vector2f(50, 10));

	//A simple example of creating an animation
	std::vector <sf::Vector2f> pos;
	pos.push_back(sf::Vector2f(50, 0));
	pos.push_back(sf::Vector2f(50, 50));
	pos.push_back(sf::Vector2f(-50, 50));
	pos.push_back(sf::Vector2f(-50, 0));
	pos.push_back(sf::Vector2f(0, -100));
	Animation* animTest = new Animation(&spriteTest2, pos, 0.5);


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space && !(animTest->isAnimating()))
				{
					animTest->start();
				}
			}
		}

		animTest->next();	//To do the next step of the animation
		moveSprite(&spriteTest1, &spriteTest2);

		window.clear();
		window.draw(spriteTest1);
		window.draw(spriteTest2);
		window.display();
	}

	return 0;
}

void moveSprite(sf::Sprite* spriteTest1, sf::Sprite* spriteTest2)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		spriteTest1->move(sf::Vector2f(0, -0.2f));
		spriteTest2->move(sf::Vector2f(0, -0.2f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		spriteTest1->move(sf::Vector2f(0, 0.2f));
		spriteTest2->move(sf::Vector2f(0, 0.2f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		spriteTest1->move(sf::Vector2f(-0.2f, 0));
		spriteTest2->move(sf::Vector2f(-0.2f, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		spriteTest1->move(sf::Vector2f(0.2f, 0));
		spriteTest2->move(sf::Vector2f(0.2f, 0));
	}
}