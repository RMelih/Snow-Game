#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include "SDL_scancode.h"
#include <iostream>

namespace Tmpl8
{
	//Create player sprite
	Sprite playerSprite(new Surface("assets/snowman.png"), 1);


	//Checking if a key is pressed
	void Game::KeyDown(int key)
	{
		switch (key)
		{
		case SDL_SCANCODE_LEFT:
			m_Left = 1.0f;
			break;
		case SDL_SCANCODE_RIGHT:
			m_Right = 1.0f;
			break;
		case SDL_SCANCODE_UP:
			m_Up = 1.0f;
			break;
		case SDL_SCANCODE_DOWN:
			m_Down = 1.0f;
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
			m_Left = 0.0f;
			break;
		case SDL_SCANCODE_RIGHT:
			m_Right = 0.0f;
			break;
		case SDL_SCANCODE_UP:
			m_Up = 0.0f;
			break;
		case SDL_SCANCODE_DOWN:
			m_Down = 0.0f;
			break;
		default:
			break;
		}
	}

	//Function to get the raduis of a circle
	float Game::GetRaduisCircle(float circleSpriteWidth)
	{
		//Calcuate the raduis with the formule raduis: square root area / pi
		raduis = sqrt(circleSpriteWidth / 3.14f);

		return raduis;
	}

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		//player positions
		playerPosX = 0.0f, playerPosY = 0.0f;

		//player sprite values
		playerSpriteW = 25.0f, playerSpriteH = 25.0f;
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
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		//change deltatime to s insteads of miliseconds
		deltaTime /= 1000;

		//Clear the screen every frame with the light gray background color:0xf2f2f2
		screen->Clear(0xf2f2f2);

		//Checking and update player postion if it goes out of screen
		PlayerMovementBoundary();

		//player movement
		float newPosX = playerPosX + (m_Right - m_Left) * deltaTime * 60.0f;
		float newPosY = playerPosY + (m_Down - m_Up) * deltaTime * 60.0f;

		//update the player postion
		playerPosX = newPosX, playerPosY = newPosY;

		//draw player with updated positons and updated sprite width and height
		playerSprite.DrawScaled(playerPosX, playerPosY, playerSpriteW, playerSpriteH, screen);
	}
};