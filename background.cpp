#include "background.h"

void Background::DrawBackground(char* backgroundFile, int sPosImg, int ePosImg, int width, int height, Tmpl8::Surface* screen)
{
	//Creating sprite background with the backgroundfile
	Tmpl8::Sprite background(new Tmpl8::Surface(backgroundFile), 1);

	//Using the template 'DrawScaled' function to draw the background sprite
	background.DrawScaled(sPosImg, ePosImg, width, height, screen);
}