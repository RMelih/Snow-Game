#include "spawnobject.h"
#include "vector"

//Setters
void SpawnObject::SetSpawnObject(char* spriteFile, float spriteW, float spriteH, float spriteLastingTime, float increaseValue, float decreaseValue)
{
	this->spriteFile = spriteFile;
	this->spriteW = spriteW;
	this->spriteH = spriteH;
	this->spriteLastingTime = spriteLastingTime;
	this->increaseValue = increaseValue;
	this->decreaseValue = decreaseValue;
}

void SpawnObject::SetSpriteFile(char* spriteFile)
{
	this->spriteFile = spriteFile;
}

void SpawnObject::SetSpriteW(float spriteW)
{
	this->spriteW = spriteW;
}

void SpawnObject::SetSpriteH(float spriteH)
{
	this->spriteH = spriteH;
}

void SpawnObject::SetSpriteLastingTime(float spriteLastingTime)
{
	this->spriteLastingTime = spriteLastingTime;
}

void SpawnObject::SetIncreaseValue(float increaseValue)
{
	this->increaseValue = increaseValue;
}

void SpawnObject::SetDecreaseValue(float decreaseValue)
{
	this->decreaseValue = decreaseValue;
}

//Getters
char* SpawnObject::GetSpriteFile()
{
	return spriteFile;
}

float SpawnObject::GetSpriteW()
{
	return spriteW;
}
float SpawnObject::GetSpriteH()
{
	return spriteH;
}

float SpawnObject::GetSpriteLastingTime()
{
	return spriteLastingTime;
}

float SpawnObject::GetIncreaseValue()
{
	return increaseValue;
}

float SpawnObject::GetDeacreseValue()
{
	return decreaseValue;
}

//Draws the object
void SpawnObject::DrawObject(char* objectSprite, float posX, float posY, float spriteW, float spriteH, Tmpl8::Surface* screen)
{
	Tmpl8::Sprite sprite(new Tmpl8::Surface(objectSprite), 1);

	sprite.DrawScaled(posX, posY, spriteW, spriteH, screen);
}
