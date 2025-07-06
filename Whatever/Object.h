#pragma once
#include "raylib.h"

class Object
{
public:
    int x;
    int y;
    int width;
    int height;
    bool isActive = true;
    bool isVisible = true;
    bool hasCollision;
    Texture2D texture;

    Object();              // Konstruktor
    ~Object();             // Destruktor

    void draw();
};