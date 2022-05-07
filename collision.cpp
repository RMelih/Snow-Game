#include "collision.h"
#include "game.h"
#include "spawner.h"
#include <iostream>
#include <math.h>

//Create a reference to the game class
Tmpl8::Game game;

//Create a refence to the spawner class
Spawner spawner;

//Calculate the distance between the player and object centers
//And return the distance
float Collision::CalcuateDistance()
{
	distanceX = game.GetPlayerPosX() - spawner.GetObjectCurrentPosX();
	distanceY = game.GetPlayerPosY() - spawner.GetObjectCurrentPosY();
	distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));
	return distance;
}

void Collision::CheckCollision()
{
	distanceX = game.GetPlayerPosX() - spawner.GetObjectCurrentPosX();
	distanceY = game.GetPlayerPosY() - spawner.GetObjectCurrentPosY();
	distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

	if (distance <= game.GetRaduisCirclePlayer() + game.GetRaduisCircleObject()) {
		IsThereCollision = true;
		std::cout << "sggd" << std::endl;
	}
	else
	{
		IsThereCollision = false;
	}

	std::cout << game.GetPlayerPosX() << std::endl;

}