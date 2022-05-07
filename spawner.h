#include "surface.h"
#include <iostream>

class Spawner
{
public:
	//Consturctor Spawner
	Spawner()
	{
		//Random postion for the object at the start of the game
		currentPosX = 250.0f;
		currentPosY = 150.0f;
	}

	~Spawner()
	{
		std::cout << "Destructor" << std::endl;
	}

	//Function which Initliasiles the objects at the start of the game
	//Needs to be called in Game::Init function on game.cpp file
	void InitObjects();

	//Function to return random positions where object is going to be drawn
	float ReturnRandomPosX();
	float ReturnRandomPosY();

	//Functions to return object current position
	float GetObjectCurrentPosX();
	float GetObjectCurrentPosY();

	//Functions to return current object sprite width and height
	float GetObjectCurrentWidth();
	float GetObjectCurrentHeight();

	//Gets new random object
	void GetNewObject();

	//Function which draw the objects
	void DrawObjects(Tmpl8::Surface* screen);

private:
	//varibles for spawner postions
	float currentPosX, currentPosY;
};

