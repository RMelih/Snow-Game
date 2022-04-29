#include "player.h"
#include "template.h"

void Player::DrawPlayer(char* playerSprite, float posX, float posY, float width, float height, Tmpl8::Surface* screen)
{
	//Creating sprite background with the backgroundfile
	Tmpl8::Sprite player(new Tmpl8::Surface(playerSprite), 1);

	//Check boundary 
	if (posX <= 0)
	{
		posX = 0;
	}

	if (posY <= 0)
	{
		posY = 0;
	}

	if (posX >= (ScreenWidth - width))
	{
		posX = (ScreenWidth - width);
	}

	if (posY >= (ScreenHeight - height))
	{
		posY = (ScreenHeight - height);
	}

	//Using the template 'DrawScaled' function to draw the background sprite
	player.DrawScaled(posX, posY, width, height, screen);
}