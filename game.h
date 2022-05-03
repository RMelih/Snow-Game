#pragma once

namespace Tmpl8 {

	class Surface;
	class Game
	{
	public:
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

		//Get the raduis of a circle sprite
		float GetRaduisCircle(float circleSpriteWidth);

	private:
		float m_Left = 0.0f;
		float m_Right = 0.0f;
		float m_Up = 0.0f;
		float m_Down = 0.0f;

		//varaibles for player postion, width and height
		float playerPosX, playerPosY;
		float playerSpriteW, playerSpriteH;

		//varaibles for calculating raduis
		float circleSpriteWidth, raduis;

		Surface* screen;
	};

}; // namespace Tmpl8