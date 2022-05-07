#pragma once

class Collision
{
public:
	//Fucntion to calculate the distance between the player and object centers
	//And returns the distance
	float CalcuateDistance();

	//Functon which will check collsion all frames
	void CheckCollision();

private:
	float distanceX;
	float distanceY;
	float distance;
	bool IsThereCollision = false;
};