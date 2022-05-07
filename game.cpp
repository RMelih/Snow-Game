#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include "SDL_scancode.h"
#include <iostream>
#include "spawner.h"


namespace Tmpl8
{
	//Create player sprite
	Sprite playerSprite(new Surface("assets/snowman.png"), 1);

	//Create spawner object
	Spawner spawner;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		//initliase all object in the spawner
		spawner.InitObjects();
	}

	//Checking if a key is pressed
	void Game::KeyDown(int key)
	{
		switch (key)
		{
		case SDL_SCANCODE_LEFT:
			movementLeft = playerSpeed;
			break;
		case SDL_SCANCODE_RIGHT:
			movementRight = playerSpeed;
			break;
		case SDL_SCANCODE_UP:
			movementUp = playerSpeed;
			break;
		case SDL_SCANCODE_DOWN:
			movementDown = playerSpeed;
			break;
		default:
			break;
		}
	}

	//Checking if a key is released
	void Game::KeyUp(int key)
	{
		switch (key)
		{
		case SDL_SCANCODE_LEFT:
			movementLeft = 0.0f;
			break;
		case SDL_SCANCODE_RIGHT:
			movementRight = 0.0f;
			break;
		case SDL_SCANCODE_UP:
			movementUp = 0.0f;
			break;
		case SDL_SCANCODE_DOWN:
			movementDown = 0.0f;
			break;
		default:
			break;
		}
	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{

	}

	void Game::PlayerMovementBoundary()
	{
		//Check boundary of the player on the screen
		//Checking if player position horizontally is bigger or equal than 0
		if (playerPosX <= 0) playerPosX = 0;

		//Checking if player position vertically is bigger or equal than 0
		if (playerPosY <= 0) playerPosY = 0;

		//Checking if player position horizontally is bigger or equal than the screen - then width of the player
		if (playerPosX >= (ScreenWidth - playerSpriteW)) playerPosX = (ScreenWidth - playerSpriteW);

		//Checking if player position vertically is bigger or equal than the screen - then height of the player
		if (playerPosY >= (ScreenHeight - playerSpriteH)) playerPosY = (ScreenHeight - playerSpriteH);
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{

		//change deltatime to s insteads of miliseconds
		deltaTime /= 1000;

		//Clear the screen every frame with the light gray background color:0xf9f9f9
		screen->Clear(0xf9f9f9);

		//Checking and update player postion if it goes out of screen
		PlayerMovementBoundary();

		//player movement
		float newPosX = playerPosX + (movementRight - movementLeft) * deltaTime * 60.0f;
		float newPosY = playerPosY + (movementDown - movementUp) * deltaTime * 60.0f;

		//update the player postion
		playerPosX = newPosX, playerPosY = newPosY;

		//draw player with updated positons and updated sprite width and height
		playerSprite.DrawScaled(playerPosX, playerPosY, playerSpriteW, playerSpriteH, screen);

		//Draw the spawner
		spawner.DrawObjects(screen);
	}
};