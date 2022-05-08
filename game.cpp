#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include "SDL_scancode.h"
#include <iostream>
#include "spawner.h"
#include <math.h>
#include "spawnobject.h"
#include <string>

namespace Tmpl8
{
	//Create player sprite
	Sprite playerSprite(new Surface("assets/snowman.png"), 1);

	//Create spawnobject
	SpawnObject spawnobject;

	//Create spawner object
	Spawner spawner;

	//Construcator
	Game::Game()
	{
		//player sprite values
		playerSpriteW = 20.0f;
		playerSpriteH = 20.0f;
		playerSpriteMinW = 12.0f;
		playerSpriteMinH = 12.0f;
		playerSpriteMaxW = 36.0f;
		playerSpriteMaxH = 36.0f;

		//player positions
		playerPosX = ScreenWidth / 2;
		playerPosY = ScreenHeight / 2;

		//player movemnt varaibles
		movementLeft = 0.0f;
		movementRight = 0.0f;
		movementUp = 0.0f;
		movementDown = 0.0f;
		playerSpeed = 2.5f;

		//game score
		score = 0;

		//player health
		minPlayerHealth = 0;
		maxPlayerHealth = 3;
		currentPlayerHealth = 3;
		playerHealthIncreaseValue = 1;
		playerHealthDeacreseValue = 1;

		screen = screen;
	}

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

	//Change player sprite min max values if there a breached
	void Game::PlayerSpriteValues()
	{
		//Max values
		if (playerSpriteW >= playerSpriteMaxW) playerSpriteW = playerSpriteMaxW;

		if (playerSpriteH >= playerSpriteMaxH) playerSpriteH = playerSpriteMaxH;

		//Min values
		if (playerSpriteW <= playerSpriteMinW) playerSpriteW = playerSpriteMinW;

		if (playerSpriteH <= playerSpriteMinH) playerSpriteH = playerSpriteMinH;
	}

	//Get the raduis from a player circle
	float Game::GetRaduisCirclePlayer()
	{
		//formule to calcute the raduis = square root area / pi
		return sqrt(playerSpriteW / 3.14f);
	};

	//Get the raduis from a the player
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
		if (CalcuateDistance() - 20.0f < GetRaduisCirclePlayer() + GetRaduisCircleObject()) {
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
		////Increase the score
		//Increase the player sprite width and height if it collids with object
		if (ReturnCollsionValue() == true)
		{
			spawner.GetNewObject();
			currentPlayerHealth += playerHealthIncreaseValue;
			score += spawnobject.GetIncreaseValueScore();
			playerSpriteW += spawnobject.GetIncreaseValue();
			playerSpriteH += spawnobject.GetIncreaseValue();
		}

		//Deacres the score
		//Decrease the player sprite width and height if it fails to collids with object
		if (spawner.ReturnIsObjectCollided() == true)
		{
			score -= spawnobject.GetDeacreseValueScore();
			currentPlayerHealth -= playerHealthDeacreseValue;
			playerSpriteW -= spawnobject.GetDeacreseValue();
			playerSpriteH -= spawnobject.GetDeacreseValue();
		}
	}

	//Player health
	void Game::HealthGame()
	{
		//Set min and max value to player health
		if (currentPlayerHealth <= minPlayerHealth) currentPlayerHealth = minPlayerHealth;

		if (currentPlayerHealth >= maxPlayerHealth) currentPlayerHealth = maxPlayerHealth;

		//de the health sprite based on reaming health
		for (int i = minPlayerHealth; i < currentPlayerHealth; i++)
		{
			spawnobject.DrawObject("assets/snowman.png", 35 + i * 50, ScreenHeight - 40, spawnobject.GetSpriteW(), spawnobject.GetSpriteH(), screen);
		}
	}

	//Update the score
	void Game::ScoreGame()
	{
		//print to a string
		char text[1];
		sprintf(text, "%i", score);

		//Set score to a min value of 0
		if (score <= 0) score = 0;

		//Draw the score to screen
		screen->Print(text, ScreenWidth - 75, ScreenHeight - 35, 0x000000, 2);
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		//change deltatime to s insteads of miliseconds
		deltaTime /= 1000;

		//Clear the screen every frame with the light gray background color:0xf9f9f9
		screen->Clear(0xffffff);

		//player movement
		float newPosX = playerPosX + (movementRight - movementLeft) * deltaTime * 60.0f;
		float newPosY = playerPosY + (movementDown - movementUp) * deltaTime * 60.0f;

		//update the player postion
		playerPosX = newPosX, playerPosY = newPosY;

		//Draw the spawner
		spawner.DrawObjects(screen);

		//Change player sprite values
		PlayerSpriteValues();

		//Check Collision
		CollisionResponse();

		//Checking and update player postion if it goes out of screen
		PlayerMovementBoundary();

		//draw player with updated positons and updated sprite width and height
		playerSprite.DrawScaled((int)playerPosX, (int)playerPosY, (int)playerSpriteW, (int)playerSpriteH, screen);

		//Draw the score
		ScoreGame();

		//Draw the health
		HealthGame();
	}
};