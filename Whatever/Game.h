#pragma once
#include <string>

class Game {
public:
    static void createWindow(int width, int height, const std::string& title); 
    virtual void update();  
    virtual void init();
    virtual void exit();
    virtual void draw();

    void run();
};
