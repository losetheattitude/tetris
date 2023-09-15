#pragma once
#include <raylib.h>
#include "../game.hpp"

class GameScene {
private:
    Game* game;
    Font font;
    char levelText[5];
    char scoreText[10];

public:
    GameScene(Game* game);
    void Play();
    void Draw();
    void DrawLevelComponent();
    void DrawScoreComponent();
    void DrawNextBlockComponent();
    void DrawPause();
    void DrawGameOver();
};