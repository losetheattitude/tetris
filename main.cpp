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

#include "src/core/joystick.hpp"

int main()
{
    /**
     *
     * Event dispatching for Game class to further decouple and facilitate the transmission of internal properties otherwise
     * unamicable to perform so (Composition or inheritance(IExchanger like) ???)
     * Async environment for RemoteTerminal and RemoteStorages consider Disruptor for advancing purposes
     * 
     * MAKIN DECISIONS AYAY MAKIN PERFECT ACTIONS AYAY WE DA BEST WEST AYYYY
     * WHAT A LOVELY OUTCOME !!! DA BEST OF THE BEST AYYY MAKIN DECISION THEY WERE NOT ASKED FOR AYYYY
     * 
     * WUMENNN CARSSS MUNEYY MUNEYYYY GET MUNEYYY WUMENNN WUMEN ENOUGH YAYYYY
     * 
     * DA BEST OF DA BEST EUROPAEN GREAT GUYS OFFFERING WUMEN WUMENNNN MUNEYYY CARSSS AYYYY 
     * LIFE NOT FAIR ayayayay LIFE A GAME NOT A GAME AYYYYY
     * 
     * THE WHOLE KNOWING PERFECT CIVILIZATION DA WEST NUMBA ONE WEST OFFERING MUNEY MUNEYYYY WUMENNN CARSSS
     * FOR VIOLENCE AYYYYYYYYY GENIUS !!! 
     */



    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);
 
    // Grid* grid = new Grid();
    // Level* level = makeLevelSingleton(2);
    // InputTerminal* terminal = n ew InputTerminal();

    Grid *grid = new Grid();
    Level *level = makeLevelSingleton(2);

    // BaseStorage storage = BaseStorage();
    // BaseTransformer formatter = BaseTransformer();
    // Exchanger exchanger = Exchanger(&storage, &formatter);

    Game *game = new Game(grid, level, 0);
    CommandFactory::Init(*game);

    Terminal *terminal = new LocalTerminal();
    JoyStick *joyStick = new JoyStick(terminal);

    GameScene gameScene = GameScene(game, joyStick);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        gameScene.Draw();

        gameScene.Play();
        EndDrawing();
    }

    delete CommandFactory::GetInstance();
    CloseWindow();
}