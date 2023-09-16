#include <iostream>
#include <raylib.h>
#include <thread>

#include "./src/levels/levelfactory.hpp"
#include "./src/scenes/gamescene.hpp"
#include "./src/levels/easylevel.hpp"
#include "./src/levels/mediumlevel.hpp"
#include "./src/levels/hardlevel.hpp"
#include "./src/inputterminal.hpp"
#include "./src/util/clock.hpp"

int main()
{
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    InputTerminal terminal = InputTerminal();

    BaseLevel* level = makeLevel(2);
    Game game = Game(level, &terminal);
    GameScene gameScene = GameScene(&game);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        gameScene.Draw();

        gameScene.Play();
        EndDrawing();
    }

    CloseWindow();
}