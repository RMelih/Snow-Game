#pragma once
/*
	#include <iostream>
	#include <sstream>
*
	Sprite* playerSprite2 = new Sprite(new Surface("assets/snowman.png"), 1);
	Sprite* playership = new Sprite(new Surface("assets/playership.png"), 1);

	float playerPosX2, playerPosY2, raduis2;

	void Game::Init()
	{
		playerPosX2 = 50;
		playerPosY2 = 50;

		raduis2 = 2.82094792f;

		deleteSprite = false;
	}

	int number = 0;
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{

		//update the player postion
		playerPosX = newPosX, playerPosY = newPosY;

		// use the Pythagorean Theorem to compute the distance
		float distX = playerPosX - playerPosX2;
		float distY = playerPosY - playerPosY2;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the sum of the circle's
		// radii, the circles are touching!
		if (distance <= raduis + raduis2) {
			deleteSprite = true;
			number = number + 1;
			playerPosX2 = 2500;
			playerPosY2 = 2500;
			playerSpriteW += 15;
			playerSpriteH += 15;
		}

		if (deleteSprite == false)
		{
			playerSprite2->DrawScaled(playerPosX2, playerPosY2, 25, 25, screen);
		}

		//draw player with updated positons and updated sprite width and height
		playerSprite.DrawScaled(playerPosX, playerPosY, playerSpriteW, playerSpriteH, screen);


		char num_char[1 + sizeof(char)];

		std::sprintf(num_char, "%d", number);
		//std::printf("num_char: %s \n", num_char);

		screen->Print(num_char, 250, 250, 0x000000);

	};


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

	//player positions
		playerPosX = 0.0f, playerPosY = 0.0f;

		//player sprite values
		playerSpriteW = 25.0f, playerSpriteH = 25.0f;


		void Game::PlayerMovementBoundary()
	{
		//Check boundary of the player on the screen
		//Checking if player position horizontally is bigger or equal than 0
		if (playerPosX <= 0)
		{
			playerPosX = 0;
		}

		//Checking if player position vertically is bigger or equal than 0
		if (playerPosY <= 0)
		{
			playerPosY = 0;
		}

		//Checking if player position horizontally is bigger or equal than the screen - then width of the player
		if (playerPosX >= (ScreenWidth - playerSpriteW))
		{
			playerPosX = (ScreenWidth - playerSpriteW);
		}

		//Checking if player position vertically is bigger or equal than the screen - then height of the player
		if (playerPosY >= (ScreenHeight - playerSpriteH))
		{
			playerPosY = (ScreenHeight - playerSpriteH);
		}
	}


	PlayerMovementBoundary();


*/
