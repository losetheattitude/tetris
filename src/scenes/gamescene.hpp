#pragma once
#include <raylib.h>
#include "../core/game.hpp"
#include "../core/terminal/terminal.hpp"

class GameScene {
private:
    Game* game;
    Terminal* terminal;
    Font font;
    char levelText[5];
    char scoreText[10];

public:
    GameScene(Game* game, Terminal* terminal);
    ~GameScene();
    
    void Play();
    void Draw();
    void DrawLevelComponent();
    void DrawScoreComponent();
    void DrawNextBlockComponent();
    void DrawPause();
    void DrawGameOver();
};