#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include "background.h"

namespace Tmpl8
{
	//Create background object
	Background background;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		//Draw background image scaled with starting and ending postion on the screen
		//And with current width and height of the screen
		background.DrawBackground("assets/sky.png", 0, 0, ScreenWidth, ScreenHeight, screen);

	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{

	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{

	}
};