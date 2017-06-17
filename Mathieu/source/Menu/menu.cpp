#include "menu.h"

void initMenu(sf::RenderWindow* window, allButton* a)
{
	Button play("PLAY", 50, 50, 50, 200, window);
	Button settings("SETTINGS", 50, 100, 50, 200, window);
	Button quit("QUIK", 50, 150, 50, 200, window);
	
	a->play = play;
	a->settings = settings;
	a->quit = quit;
	

}

void drawMenu( allButton* a)
{
	a->play.draw();
	a->settings.draw();
	a->quit.draw();
}

void mouse(allButton* a)
{
	a->play.mouseOn();
	a->quit.mouseOn();
	a->settings.mouseOn();
}
