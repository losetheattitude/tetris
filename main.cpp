#include <iostream>
#include <raylib.h>
#include <thread>

#include "./src/scenes/gamescene.hpp"
#include "./src/levels/easylevel.cpp"
#include "./src/levels/mediumlevel.cpp"
#include "./src/levels/hardlevel.cpp"
#include "./src/inputterminal.hpp"
#include "./src/util/clock.hpp"

int main()
{
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    InputTerminal terminal = InputTerminal();

    Clock levelClock = Clock();
    EasyLevel easy = EasyLevel(&levelClock);
    MediumLevel medium = MediumLevel(&levelClock);
    HardLevel hard = HardLevel(&levelClock);

    Game game = Game(&hard, &terminal);
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