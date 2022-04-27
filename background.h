#pragma once
#include "surface.h"
#include "template.h"

class Background
{
public:
	/*
		Function to draw background image with image file,
		starting and the ending postion of the image,
		width and height of the image
		and the surface screen
	*/
	void DrawBackground(char* backgroundFile, int sPosImg, int ePosImg, int width, int height, Tmpl8::Surface* screen);

private:

};