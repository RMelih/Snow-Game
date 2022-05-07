#pragma once
#include <math.h>

namespace Tmpl8 {

	class Surface;
	class Game
	{
	public:
		//Construcator
		Game()
		{
			//player positions
			playerPosX = 0.0f;
			playerPosY = 0.0f;

			//player sprite values
			playerSpriteW = 25.0f;
			playerSpriteH = 25.0f;

			//player movemnt varaibles
			movementLeft = 0.0f;
			movementRight = 0.0f;
			movementUp = 0.0f;
			movementDown = 0.0f;
			playerSpeed = 2.5f;

			screen = screen;
		}

		void SetTarget(Surface* surface) { screen = surface; }
		void Init();
		void Shutdown();
		void Tick(float deltaTime);
		void MouseUp(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseDown(int button) { /* implement if you want to detect mouse button presses */ }
		void MouseMove(int x, int y) { /* implement if you want to detect mouse movement */ }
		void KeyUp(int key);
		void KeyDown(int key);

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

		//Fucntion to calculate the distance between the player and object centers
		//And returns the distance
		float CalcuateDistance();
	};

}; // namespace Tmpl8