#pragma once
#include "surface.h"

class Player
{
public:
	//Player constructor
	Player()
	{
		posX = 0.0f;
		posY = 0.0f;
		spriteW = 25.0f;
		spriteH = 25.0f;
		raduis = 3.9f;
	}

	~Player() {}

	void CheckInputKey();

	void PlayerMoveBoundary();

	void MovePlayer(float deltaTime);

	//public variables for de player postions and sprite width and height
	float posX, posY, raduis;
	float spriteW, spriteH;

private:
	//variables for player postion
	float m_Left = 0.0f;
	float m_Right = 0.0f;
	float m_Up = 0.0f;
	float m_Down = 0.0f;
};