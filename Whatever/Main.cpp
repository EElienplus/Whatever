#include "Game.h"
#include "raylib.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Utils.h"

class Whatever : public Game {
public:
    Player player1;
    PhysicsState playerPhysics;

    void init() override {
		player1.textureOriginal = downscaleTexture(LoadTexture("assets/player.png"), 2);
		player1.texture = player1.textureOriginal;
		player1.x = 100;
		player1.y = 100;
		player1.width = player1.texture.width;
		player1.height = player1.texture.height;
	}

    void update() override {
        // Update physics and movement first
        enableGravity(player1, playerPhysics, 900.0f, 800 - player1.height);
        enableMovement(player1, playerPhysics);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(player1.texture, static_cast<int>(player1.x), static_cast<int>(player1.y), WHITE);
        EndDrawing();
    }
};

int main() {
    int screenWidth = 1200;
    int screenHeight = 800;
    std::string title = "ggGame :3";

    Game::createWindow(screenWidth, screenHeight, title);

    Whatever game;
    game.init();
    game.run();  
	game.exit();

    return 0;
}
