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
	Texture2D textureOriginal; // P�vodn� textura pro flipov�n�
};

