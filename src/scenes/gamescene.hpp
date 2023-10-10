#pragma once
#include <raylib.h>
#include "../core/game.hpp"
#include "../core/terminal/terminal.hpp"
#include "../core/joystick.hpp"

class GameScene {
private:
    Game* game;
    JoyStick* joystick;
    Font font;
    char levelText[5];
    char scoreText[10];

public:
    GameScene(Game* game, JoyStick* JoyStick);
    ~GameScene();
    
    void Play();
    void Draw();
    void DrawLevelComponent();
    void DrawScoreComponent();
    void DrawNextBlockComponent();
    void DrawPause();
    void DrawGameOver();
};