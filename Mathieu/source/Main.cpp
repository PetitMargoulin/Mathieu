#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include "animation\Animation.h"
#include "entites\map\Block.h"
#include "Menu\Button.h"

#define log(x) std::cout << x << std::endl

void moveSprite(sf::Sprite* spriteTest1, sf::Sprite* spriteTest2, float dt);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	window.setFramerateLimit(600);
	sf::Event event;

	Button bPlay("Nonjour mon petit Mathieu", 200, 100, 200, 200, &window);

	sf::Texture textureTest1;
	sf::Sprite spriteTest1;

	sf::Texture textureTest2;
	sf::Sprite spriteTest2;

	if (!textureTest1.loadFromFile("ressources/textures/Simple_Green_Texture.jpg", sf::IntRect(10, 10, 32, 32)))
		log("error");
	textureTest1.setSmooth(true);

	if (!textureTest2.loadFromFile("ressources/textures/Simple_Red_Texture.jpg", sf::IntRect(10, 10, 32, 32)))
		log("error");
	textureTest2.setSmooth(true);
	
	spriteTest1.setTexture(textureTest1);
	//spriteTest1.setTextureRect(sf::IntRect(10, 10, 32, 32));
	spriteTest1.setPosition(sf::Vector2f(10, 50));

	spriteTest2.setTexture(textureTest2);
	//spriteTest2.setTextureRect(sf::IntRect(10, 10, 32, 32));
	spriteTest2.setPosition(sf::Vector2f(50, 10));

	//A simple example of creating an animation
	std::vector <sf::Vector2f> pos;
	pos.push_back(sf::Vector2f(50, 0));
	pos.push_back(sf::Vector2f(50, 50));
	pos.push_back(sf::Vector2f(-50, 50));
	pos.push_back(sf::Vector2f(-50, 0));
	pos.push_back(sf::Vector2f(0, -100));
	Animation* animTest = new Animation(&spriteTest2, pos, 250.f);

	Block* myBlock = new Block(&window, 20, 400, 40, 40, Block::ground);
	Block* myBlock1 = new Block(&window, 70, 400, 80, 20, Block::ground);
	Block* myBlock2 = new Block(&window, 20, 500, 100, 100, Block::ground);
	Block* myBlock3 = new Block(&window, 140, 500, 10, 10, Block::ground);

	sf::Clock gameClock;
	float dt;

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

		dt = gameClock.restart().asSeconds();	//Delta time between 2 frames
		animTest->next(dt);	//Do the next step of the animation
		moveSprite(&spriteTest1, &spriteTest2, dt);

		window.clear();
		window.draw(spriteTest1);
		window.draw(spriteTest2);
		myBlock->draw();
		myBlock1->draw();
		myBlock2->draw();
		myBlock3->draw();
		bPlay.draw();
		window.display();
	}

	return 0;
}

void moveSprite(sf::Sprite* spriteTest1, sf::Sprite* spriteTest2, float dt)
{
	float speed = 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		spriteTest1->move(sf::Vector2f(0, -speed * dt));
		spriteTest2->move(sf::Vector2f(0, -speed * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		spriteTest1->move(sf::Vector2f(0 * dt, speed * dt));
		spriteTest2->move(sf::Vector2f(0, speed * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		spriteTest1->move(sf::Vector2f(-speed * dt, 0));
		spriteTest2->move(sf::Vector2f(-speed * dt, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		spriteTest1->move(sf::Vector2f(speed * dt, 0));
		spriteTest2->move(sf::Vector2f(speed * dt, 0));
	}
}