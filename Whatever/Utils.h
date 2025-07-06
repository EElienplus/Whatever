#pragma once
#include "raylib.h"
#include "Player.h"

// Jednoduchá fyzika pro pohyb a skákání
struct PhysicsState {
    float velocityX = 0.0f;
    float velocityY = 0.0f;
    bool onGround = false;
};

inline Texture2D downscaleTexture(Texture2D tex, int factor) {
    Image img = LoadImageFromTexture(tex);
    ImageResize(&img, tex.width / factor, tex.height / factor);
    Texture2D result = LoadTextureFromImage(img);
    UnloadImage(img);
    return result;
}

inline Texture2D upscaleTexture(Texture2D tex, int factor) {
    Image img = LoadImageFromTexture(tex);
    ImageResize(&img, tex.width * factor, tex.height * factor);
    Texture2D result = LoadTextureFromImage(img);
    UnloadImage(img);
    return result;
}

// Opraveno: horizontální pøevrácení
inline Texture2D flipTexture(Texture2D tex) {
    Image img = LoadImageFromTexture(tex);
    ImageFlipHorizontal(&img);
    Texture2D result = LoadTextureFromImage(img);
    UnloadImage(img);
    return result;
}

inline void enableGravity(Player& player, PhysicsState& phys, float gravity, float groundY = 0.0f) {
    phys.velocityY += gravity * GetFrameTime();
    player.y += phys.velocityY * GetFrameTime();

    if (player.y >= groundY) {
        player.y = groundY;
        phys.velocityY = 0.0f;
        phys.onGround = true;
    }
    else {
        phys.onGround = false;
    }
}

// Doporuèeno: pøidat do Player promìnnou facingRight (bool)
inline void enableMovement(Player& player, PhysicsState& phys, float moveAccel = 2500.0f, float maxSpeed = 450.0f, float friction = 0.85f) {
    bool movingLeft = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
    bool movingRight = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);

    // Flip pouze pøi zmìnì smìru
    if (movingRight && !player.facingRight) {
        if (player.texture.id != player.textureOriginal.id) UnloadTexture(player.texture);
        player.texture = flipTexture(player.textureOriginal);
        player.facingRight = true;
    }
    if (movingLeft && player.facingRight) {
        if (player.texture.id != player.textureOriginal.id) UnloadTexture(player.texture);
        player.texture = player.textureOriginal;
        player.facingRight = false;
    }

    if (movingLeft) {
        phys.velocityX -= moveAccel * GetFrameTime();
    }
    if (movingRight) {
        phys.velocityX += moveAccel * GetFrameTime();
    }
    if ((IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && phys.onGround) {
        phys.velocityY = -450.0f;
        phys.onGround = false;
    }
    if (phys.velocityX > maxSpeed) phys.velocityX = maxSpeed;
    if (phys.velocityX < -maxSpeed) phys.velocityX = -maxSpeed;
    if (!movingLeft && !movingRight) {
        phys.velocityX *= friction;
        if (fabs(phys.velocityX) < 1.0f) phys.velocityX = 0.0f;
    }
    player.x += phys.velocityX * GetFrameTime();
}