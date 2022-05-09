#include "surface.h"

class SpawnObject
{
public:
	/*
		Constructor:
		increaseValue , decreaseValue: the increment or decrement value of the player sprite by collision or no player collision
		increaseValueScore, decreaseValueScore: the increment or decrement value, of the object for the player score
	*/
	SpawnObject()
	{
		spriteFile = "assets//snowflake/snowflake (1).png";
		spriteW = 25.0f;
		spriteH = 25.0f;
		spriteLastingTime = 5.0f;
		increaseValue = 3.0f;
		decreaseValue = 3.0f;
		increaseValueScore = 1.0f;
		decreaseValueScore = 1.0f;
	};

	//Setter
	void SetSpawnObject(char* spriteFile, float spriteW, float spriteH, float spriteLastingTime, float increaseValue, float decreaseValue);
	void SetSpriteFile(char* spriteFile);
	void SetSpriteW(float spriteW);
	void SetSpriteH(float spriteH);
	void SetSpriteLastingTime(float spriteLastingTime);
	void SetIncreaseValue(float increaseValue);
	void SetDecreaseValue(float decreaseValue);
	void SetIncreaseValueScore(float increaseValueScore);
	void SetDecreaseValueScore(float decreaseValueScore);

	//Getters
	char* GetSpriteFile();
	float GetSpriteW();
	float GetSpriteH();
	float GetSpriteLastingTime();
	float GetIncreaseValue();
	float GetDeacreseValue();
	float GetIncreaseValueScore();
	float GetDeacreseValueScore();

	//Draws single object
	void DrawObject(char* objectSprite, float posX, float posY, float spriteW, float spriteH, Tmpl8::Surface* screen);

private:
	char* spriteFile;
	float spriteW, spriteH;
	float spriteLastingTime;
	float increaseValue, decreaseValue;
	float increaseValueScore, decreaseValueScore;
};
