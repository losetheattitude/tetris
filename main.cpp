#include <iostream>
#include <raylib.h>
#include <thread>

#include "./src/core/terminal/localterminal.hpp"

#include "./src/core/clock.hpp"
#include "./src/components/grid.hpp"
#include "./src/scenes/gamescene.hpp"

#include "./src/levels/factory.hpp"
#include "./src/levels/easylevel.hpp"
#include "./src/levels/mediumlevel.hpp"
#include "./src/levels/hardlevel.hpp"

#include "src/exchanger/exchanger.hpp"
#include "src/levels/level.hpp"
#include "src/formatter/formatter.hpp"

int main()
{ 
    /**
     * 
     * 11 files will be included as well, Its those files who are serving it
     * 
    */

    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    // Grid* grid = new Grid();
    // Level* level = makeLevelSingleton(2);
    // InputTerminal* terminal = new InputTerminal();

    Grid* grid = new Grid();
    Level* level = makeLevelSingleton(2);

    // BaseStorage storage = BaseStorage();
    // BaseTransformer formatter = BaseTransformer();
    // Exchanger exchanger = Exchanger(&storage, &formatter);

    Game* game = new Game(grid, level, 0);
    LocalTerminal* terminal = new LocalTerminal();

    // GameScene* gameScene = new GameScene(game, terminal);
    GameScene gameScene = GameScene(game, terminal);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        gameScene.Draw();

        gameScene.Play();
        EndDrawing();
    }

    CloseWindow();
}