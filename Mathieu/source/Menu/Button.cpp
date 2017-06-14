#include "Button.h"

Button::Button()
{
	m_pressed = false;
}

Button::~Button()
{
}

bool Button::isPressed()
{
	return m_pressed;
}
