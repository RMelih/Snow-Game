#include "spawner.h"
#include "vector"
#include "spawnobject.h"
#include "timer.h"
#include "template.h"
#include "game.h"

// create vector of objects
std::vector<SpawnObject> SpawnObjects;

//Create objects
SpawnObject currentObject; //SpawnObject which holds the current object
SpawnObject spawnObject1;
SpawnObject spawnObject2;
SpawnObject spawnObject3;
SpawnObject spawnObject4;
SpawnObject spawnObject5;

//Create a Timer
Timer timer;

//Create game class reference
Tmpl8::Game game;

void Spawner::InitObjects()
{
	//Here you can change objects params
	spawnObject1.SetSpriteFile("assets/Crate.png");
	spawnObject2.SetSpriteFile("assets/Icebox.png");
	spawnObject3.SetSpriteFile("assets/Igloo.png");
	spawnObject4.SetSpriteFile("assets/Tree_2.png");
	spawnObject5.SetSpriteFile("assets/Stone.png");

	//Add objects to vector contatiner
	SpawnObjects.push_back(currentObject);
	SpawnObjects.push_back(spawnObject1);
	SpawnObjects.push_back(spawnObject2);
	SpawnObjects.push_back(spawnObject3);
	SpawnObjects.push_back(spawnObject4);
	SpawnObjects.push_back(spawnObject5);
}

//Getters
float Spawner::GetObjectCurrentPosX()
{
	return currentPosX;
}

float Spawner::GetObjectCurrentPosY()
{
	return currentPosY;
}

float Spawner::GetObjectCurrentWidth()
{
	return currentObject.GetSpriteW();
}

float Spawner::GetObjectCurrentHeight()
{
	return currentObject.GetSpriteH();
}

//Function which return a random object from the vector container
SpawnObject ReturnRadomSpawnObject()
{
	//random seed to get new object every run
	srand(time(NULL));

	//Get a random interger number based on vector container size
	int random = rand() % SpawnObjects.size();
	//assign the the random spawnobject to a new spawObject
	SpawnObject randomObject = SpawnObjects[random];
	//return the the random object
	return randomObject;
}

//Return random width number within the screen boundarys
float Spawner::ReturnRandomPosX()
{
	currentPosX = IRand(ScreenWidth - (int)currentObject.GetSpriteW());
	return currentPosX;
}

//Return random height number within the screen boundarys
float Spawner::ReturnRandomPosY()
{
	currentPosY = IRand(ScreenHeight - (int)currentObject.GetSpriteH());
	return currentPosY;
}

//Gets a random object, posX, posY en resets the time
void Spawner::GetNewObject()
{
	currentObject = ReturnRadomSpawnObject();
	currentPosX = ReturnRandomPosX();
	currentPosY = ReturnRandomPosY();
	timer.Reset();
}

//Returns the isObjectCollided bool value
bool Spawner::ReturnIsObjectCollided()
{
	return isObjectCollided;
}

void Spawner::DrawObjects(Tmpl8::Surface* screen)
{
	//Add Timer tick function
	timer.Tick();

	//Update the current object after objects lasting time has passed with a random object from vector container
	//Update the current object postion with random positions
	if (timer.TotalTimeSeconds() > currentObject.GetSpriteLastingTime())
	{
		currentObject = ReturnRadomSpawnObject();
		currentPosX = ReturnRandomPosX();
		currentPosY = ReturnRandomPosY();
	}

	//Reset the timer back to 0 after sprite lasting time has passed
	//Change the isObjectCollided bool value to true
	if (timer.TotalTimeSeconds() > currentObject.GetSpriteLastingTime())
	{
		isObjectCollided = true;
		timer.Reset();
	}
	//Change the isObjectCollided bool value to false
	else isObjectCollided = false;

	//Draw the current object
	currentObject.DrawObject(currentObject.GetSpriteFile(), currentPosX, currentPosY, currentObject.GetSpriteW(), currentObject.GetSpriteH(), screen);

}