#include "game.h"
#include "surface.h"
#include "template.h"
#include <cstdio> //printf
#include <SDL_scancode.h>
#include "player.h"

namespace Tmpl8
{
	Player player;

	float pPosX, pPosY;
	float pSpriteW, pSpriteH;
	float pSpeed;

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		pSpriteW = 25.0f;
		pSpriteH = 25.0f;

		pPosX = 0.0f;
		pPosY = 0.0f;

		pSpeed = 3.0f;
	}

	void Game::KeyDown(int key)
	{
		switch (key)
		{
		case SDL_SCANCODE_LEFT:
			m_Left = pSpeed;
			break;
		case SDL_SCANCODE_RIGHT:
			m_Right = pSpeed;
			break;
		case SDL_SCANCODE_UP:
			m_Up = pSpeed;
			break;
		case SDL_SCANCODE_DOWN:
			m_Down = pSpeed;
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

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{

	}

	void Game::MovePlayer(float deltaTime)
	{
		float newPosX = pPosX + (m_Right - m_Left) * deltaTime * 60.0f;
		float newPosY = pPosY + (m_Down - m_Up) * deltaTime * 60.0f;

		pPosX = newPosX, pPosY = newPosY;
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		deltaTime /= 1000;
		screen->Clear(0xf2f2f2);

		MovePlayer(deltaTime);

		player.DrawPlayer("assets/snowman.png", pPosX, pPosY, pSpriteW, pSpriteH, screen);

	}
};