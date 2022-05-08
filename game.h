#pragma once
#include "template.h"

namespace Tmpl8 {

	class Surface;
	class Game
	{
	public:
		//Construcator
		Game();

		void SetTarget(Surface* surface) { screen = surface; }
		void Init();
		void Shutdown();
		void Tick(float deltaTime);
		void MouseUp(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseDown(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseMove(int x, int y) { /* implement if you want to detect mouse movement */ }
		void KeyUp(int key);
		void KeyDown(int key);

		void DrawBackground();

		//Change player sprite min max values if there a breached
		void PlayerSpriteValues();

		//Check if player is on screen
		void PlayerMovementBoundary();

		//Get the raduis from a player circle
		float GetRaduisCirclePlayer();

		//Get the raduis from a the current spawn object on screen
		float GetRaduisCircleObject();

		//Functon which will check collsion all frames
		bool ReturnCollsionValue();

		//Function which check collision and makes changes after the collsion
		void CollisionResponse();

		//Function which is responive for the game score
		void ScoreGame();

		//Function which is responcive for the health of the player
		void HealthGame();

	private:
		Surface* screen;

		//player movemnt varaibles
		float movementLeft;
		float movementRight;
		float movementUp;
		float movementDown;
		float playerSpeed;

		//varaibles for player postion, width and height and speed
		float playerPosX;
		float playerPosY;
		float playerSpriteW;
		float playerSpriteH;
		float playerSpriteMinW;
		float playerSpriteMinH;
		float playerSpriteMaxW;
		float playerSpriteMaxH;

		//game score
		int score;

		//player health
		int minPlayerHealth;
		int maxPlayerHealth;
		int currentPlayerHealth;
		int playerHealthIncreaseValue;
		int playerHealthDeacreseValue;
		float healthSpriteValueW;
		float healthSpriteValueH;

		//Fucntion to calculate the distance between the player and object centers
		//And returns the distance
		float CalcuateDistance();
	};

}; // namespace Tmpl8