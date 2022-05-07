#include "spawner.h"
#include "vector"
#include <iostream>
#include "spawnobject.h"
#include "timer.h"
#include "template.h"

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

void Spawner::InitObjects()
{
	//Here you can change objects params
	spawnObject1.SetSpriteFile("assets/Crate.png");
	spawnObject2.SetSpriteFile("assets/Icebox.png");
	spawnObject3.SetSpriteFile("assets/Igloo.png");
	spawnObject4.SetSpriteFile("assets/Tree2.png");
	spawnObject5.SetSpriteFile("assets/Stone.png");

	//Add objects to vector contatiner
	SpawnObjects.push_back(currentObject);
	SpawnObjects.push_back(spawnObject1);
	SpawnObjects.push_back(spawnObject2);
}

//Function which return a random object from the vector container
SpawnObject ReturnRadomSpawnObject()
{
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
	currenPosX = IRand(ScreenWidth - currentObject.GetSpriteW());
	return currenPosX;
}

//Return random height number within the screen boundarys
float Spawner::ReturnRandomPosY()
{
	currenPosY = IRand(ScreenHeight - currentObject.GetSpriteH());
	return currenPosY;
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
		currenPosX = ReturnRandomPosX();
		currenPosY = ReturnRandomPosY();
	}

	//Reset the timer back to 0 after sprite lasting time has passed
	if (timer.TotalTimeSeconds() > currentObject.GetSpriteLastingTime())
	{
		timer.Reset();
	}

	//Draw the current object
	currentObject.DrawObject(currentObject.GetSpriteFile(), currenPosX, currenPosY, currentObject.GetSpriteW(), currentObject.GetSpriteH(), screen);
}