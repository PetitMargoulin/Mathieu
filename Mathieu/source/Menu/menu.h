#pragma once
#include <SFML\Graphics.hpp>
#include "Button.h"


typedef struct
{
	Button play;
	Button settings;
	Button quit;
} allButton;

void initMenu(sf::RenderWindow* window, allButton* a);
void drawMenu( allButton* a);
void mouse(allButton* a);