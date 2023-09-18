#include <iostream>
#include <raylib.h>
#include <thread>

#include "./src/inputterminal.hpp"
#include "./src/util/clock.hpp"
#include "./src/components/grid.hpp"
#include "./src/scenes/gamescene.hpp"

#include "./src/levels/levelfactory.hpp"
#include "./src/levels/easylevel.hpp"
#include "./src/levels/mediumlevel.hpp"
#include "./src/levels/hardlevel.hpp"

#include "src/exchanger.hpp"
#include "src/storage/basestorage.hpp"
#include "src/transformer/basetransformer.hpp"

int main()
{
    // int **array;
    // for(size_t i = 0; i < sizeof(array); i++)
    // {
    //     array[i][10];

    //     for(size_t j = 0;j < sizeof(array); j++)
    //     {
    //         std::cout << array[i][j] << std::endl;
    //     }
    // }

    // return 0;

    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    InputTerminal terminal = InputTerminal();

    BaseLevel* level = makeLevel(2);
    Grid grid = Grid();


    BaseStorage storage = BaseStorage();
    BaseTransformer transformer = BaseTransformer();
    Exchanger exchanger = Exchanger(&storage, &transformer);


    Game game = Game(&grid, level, &terminal, 0);
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