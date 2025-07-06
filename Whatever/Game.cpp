#include "Game.h"
#include "raylib.h"
#include <iostream>

void Game::exit() {
    std::cout << "Game exited." << std::endl;
	CloseWindow(); // Close the window and unload resources
}

void Game::createWindow(int width, int height, const std::string& title) {
    InitWindow(width, height, title.c_str());
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Default Draw() Method Content", 20, 20, 20, DARKGRAY);
    EndDrawing();
}

void Game::update() {
    // Game Logic
}

void Game::init() {
    std::cout << "Game initialized." << std::endl;
}



void Game::run() {
    while (!WindowShouldClose()) {
        update(); // Call the update function every frame
    }
}
