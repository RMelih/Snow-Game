#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include "SDL_scancode.h"
#include <iostream>
#include "spawner.h"
#include <math.h>
#include "spawnobject.h"

namespace Tmpl8
{
	//Create player sprite
	Sprite playerSprite(new Surface("assets/snowman.png"), 1);

	//Create spawnobject
	SpawnObject spawnobject;

	//Create spawner object
	Spawner spawner;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		//initliase all object in the spawner
		spawner.InitObjects();

		//Check if at the start of the object collidies with player
		//if so get new object with new values
		if (ReturnCollsionValue() == true) spawner.GetNewObject();

	}

	//Get the raduis from a player circle
	float Game::GetRaduisCirclePlayer()
	{
		//formule to calcute the raduis = square root area / pi
		return sqrt(playerSpriteW / 3.14f);
	};

	//Get the raduis from a the current spawn object on screen
	float Game::GetRaduisCircleObject()
	{
		//formule to calcute the raduis = square root area / pi
		return sqrt(spawner.GetObjectCurrentWidth() / 3.14f);
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
	//Setting the movement values back to 0
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

	//Check boundary of the player on the screen
	void Game::PlayerMovementBoundary()
	{
		//Checking if player position horizontally is bigger or equal than 0
		if (playerPosX <= 0) playerPosX = 0;

		//Checking if player position vertically is bigger or equal than 0
		if (playerPosY <= 0) playerPosY = 0;

		//Checking if player position horizontally is bigger or equal than the screen - then width of the player
		if (playerPosX >= (ScreenWidth - playerSpriteW)) playerPosX = (ScreenWidth - playerSpriteW);

		//Checking if player position vertically is bigger or equal than the screen - then height of the player
		if (playerPosY >= (ScreenHeight - playerSpriteH)) playerPosY = (ScreenHeight - playerSpriteH);
	}

	//Calculating the distance between the player and the spawned object
	float Game::CalcuateDistance()
	{
		float distanceX = playerPosX - spawner.GetObjectCurrentPosX();
		float distanceY = playerPosY - spawner.GetObjectCurrentPosY();
		float distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));
		return distance;
	}

	//Check if there is a collison
	//update the isThereACollision bool
	bool Game::ReturnCollsionValue()
	{
		if (CalcuateDistance() <= GetRaduisCirclePlayer() + 5 + GetRaduisCircleObject() + 5) {
			return true;
		}
		else
		{
			return false;
		}
	}

	//Checks collsion
	//Gets new object after it collidies with a object
	void Game::CollisionResponse()
	{
		if (ReturnCollsionValue() == true)
		{
			spawner.GetNewObject();
			std::cout << "collision detected" << std::endl;
		}
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

		//player movement
		float newPosX = playerPosX + (movementRight - movementLeft) * deltaTime * 60.0f;
		float newPosY = playerPosY + (movementDown - movementUp) * deltaTime * 60.0f;

		//update the player postion
		playerPosX = newPosX, playerPosY = newPosY;

		//Draw the spawner
		spawner.DrawObjects(screen);

		//Check Collision
		CollisionResponse();

		//Checking and update player postion if it goes out of screen
		PlayerMovementBoundary();

		//draw player with updated positons and updated sprite width and height
		playerSprite.DrawScaled((int)playerPosX, (int)playerPosY, (int)playerSpriteW, (int)playerSpriteH, screen);

	}
};