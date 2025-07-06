#pragma once
#include "raylib.h"

class Player
{
public:
    float x;
    float y;
    int width;
    int height;
    Texture2D texture;
    bool facingRight = true;
	Texture2D textureOriginal; // Pùvodní textura pro flipování
};

