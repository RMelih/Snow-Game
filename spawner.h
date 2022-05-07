#include "surface.h"
#include "template.h"

class Spawner
{
public:
	//Consturctor Spawner
	Spawner()
	{
		currenPosX = 250.0f;
		currenPosY = 250.0f;
	}

	//Function which Initliasiles the objects at the start of the game
	//Needs to be called in Game::Init function on game.cpp file
	void InitObjects();

	//Function to return random positions where object is going to be drawn
	float ReturnRandomPosX();
	float ReturnRandomPosY();

	//Function which draw the objects
	void DrawObjects(Tmpl8::Surface* screen);

private:
	//varibles for spawner postions
	float currenPosX, currenPosY;
};

