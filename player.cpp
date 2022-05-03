#include "player.h"
#include "template.h"
#include "SDL.h"

void Player::CheckInputKey()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//Looking for a keypress
		case SDL_KEYDOWN:
			//Checking if key is pressed and which keys
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				m_Left = 1.0f;
				break;
			case SDLK_RIGHT:
				m_Right = 1.0f;
				break;
			case SDLK_UP:
				m_Up = 1.0f;
				break;
			case SDLK_DOWN:
				m_Down = 1.0f;
				break;
			default:
				break;
			}
			break;
			//Checking if key is released and which key */
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				m_Left = 0.0f;
				break;
			case SDLK_RIGHT:
				m_Right = 0.0f;
				break;
			case SDLK_UP:
				m_Up = 0.0f;
				break;
			case SDLK_DOWN:
				m_Down = 0.0f;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Player::PlayerMoveBoundary()
{
	//Check boundary of the player on the screen

	//Checking if player position horizontally is bigger or equal than 0
	if (posX <= 0)
	{
		posX = 0;
	}

	//Checking if player position vertically is bigger or equal than 0
	if (posY <= 0)
	{
		posY = 0;
	}

	//Checking if player position horizontally is bigger or equal than the screen - then width of the player
	if (posX >= (ScreenWidth - spriteW))
	{
		posX = (ScreenWidth - spriteW);
	}

	//Checking if player position vertically is bigger or equal than the screen - then height of the player
	if (posY >= (ScreenHeight - spriteH))
	{
		posY = (ScreenHeight - spriteH);
	}
}

void Player::MovePlayer(float deltaTime)
{
	//player movement
	float newPosX = posX + (m_Right - m_Left) * deltaTime * 60.0f;
	float newPosY = posY + (m_Down - m_Up) * deltaTime * 60.0f;

	//update the player postion
	posX = newPosX, posY = newPosY;
}