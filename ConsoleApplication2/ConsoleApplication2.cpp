#include <raylib.h>
#include <iostream>
#include <vector>


using namespace std;



class AimCursor {
public:
	float width, height;
	void draw() {
		DrawRectangle(GetMouseX() + 20, GetMouseY() , 20, 1,WHITE);
		DrawRectangle(GetMouseX() - 40, GetMouseY() , 20, 1, WHITE);

		DrawRectangle(GetMouseX() , GetMouseY() + 20, 1, 20, WHITE);
		DrawRectangle(GetMouseX() , GetMouseY() - 40, 1, 20, WHITE);

	}


};


class Player {
public:
    int x, y;
    int speed;
	int radius;

	void Draw() {
		DrawCircle(x, y, radius, WHITE);
	}
	void Update() {

		if (IsKeyDown(KEY_UP))
		{
			y = y - speed;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			y = y + speed;
		}
		if (IsKeyDown(KEY_LEFT))
		{
			x = x - speed;
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			x = x + speed;
		}

	}


};

class Ammo {
	public:
	int x = { 0 };
	int y = { 0 };
	int direction_x = { 0 };
	int direction_y = { 0 };
	int radius = { 1 };
	int speed = { 1 };
	Color color = Color{ 255, 0, 0, 255 };

	void AmmoMove() {

		//double angle = atan2( GetMouseX() - player.x, GetMouseY()-player.y );

		//x += 10 * (cos(atan2(y - 200, x - 300)));
		//y += 10 * (sin(atan2(y - 200, x - 300)));

		//x = speed * cos(angle);
		//y = speed * sin(angle);

		//x += cos(angle);
		//y += sin(angle);

		x += speed * (direction_x - 600)/100;
		y += speed * (direction_y - 400)/100;

		

	}
	void draw() {
		DrawCircle(x, y, radius, color);
	}
};

std::vector<Ammo> ammo;

void shootAmmo(int x, int y) {
	ammo.push_back({
			x,
			y,
			GetMouseX(),
			GetMouseY(),
			3,
			10,
			{
				0,
				255,
				255,
				255
			}
		});

}


Player player;
AimCursor aimcursor;




int main()
{
	


	cout << "Starting the game" << endl;
	const int screen_width = 1200;
	const int screen_height = 800;
	InitWindow(screen_width, screen_height, "Shooter!");
	SetTargetFPS(60);

	player.x = screen_width / 2;
	player.y = screen_height / 2;
	player.radius = 20;
	player.speed = 10;




	while (WindowShouldClose() == false) {
		BeginDrawing;

		//update
		player.Update();
		//checkcollision

		//Draw
		ClearBackground(BLACK);
		player.Draw();
		aimcursor.draw();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			shootAmmo(player.x,player.y);
			
		}
		for (int i = 0; i < ammo.size(); i++) {
			ammo[i].AmmoMove();
			ammo[i].draw();
		}
		EndDrawing();
	}


	CloseWindow();
	return 0;

}

