#include "surface.h"

class SpawnObject
{
public:
	//Constructor
	SpawnObject()
	{
		//Starting values for the SpawnObject
		spriteFile = "assets/Crystal.png";
		spriteW = 25.0f;
		spriteH = 25.0f;
		spriteLastingTime = 5.0f;
		increaseValue = 1.0f;
		decreaseValue = 1.0f;
	};

	//Setter
	void SetSpawnObject(char* spriteFile, float spriteW, float spriteH, float spriteLastingTime, float increaseValue, float decreaseValue);
	void SetSpriteFile(char* spriteFile);
	void SetSpriteW(float spriteW);
	void SetSpriteH(float spriteH);
	void SetSpriteLastingTime(float spriteLastingTime);
	void SetIncreaseValue(float increaseValue);
	void SetDecreaseValue(float decreaseValue);

	//Getters
	char* GetSpriteFile();
	float GetSpriteW();
	float GetSpriteH();
	float GetSpriteLastingTime();
	float GetIncreaseValue();
	float GetDeacreseValue();

	//Function which draws single spawn object
	void DrawObject(char* objectSprite, float posX, float posY, float spriteW, float spriteH, Tmpl8::Surface* screen);

private:
	//varible for the sprite file
	char* spriteFile;
	//variable for the width and height of the object
	float spriteW, spriteH;
	//variable for how long the object is going to last on screen max
	float spriteLastingTime;
	//variable for the increase and deacrese value by for example: colliison with the player 
	float increaseValue, decreaseValue;
};
