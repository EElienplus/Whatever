#include "Object.h"
#include "raylib.h"
#include "Utils.h"
#include <iostream>

Object::Object() {
    // Inicializace prom�nn�ch, p��padn� texture = {0};
}

Object::~Object() {
    UnloadTexture(texture);
}

void Object::draw() {
	if (isVisible && isActive) {
		DrawTexture(texture, x, y, WHITE);
	}
}