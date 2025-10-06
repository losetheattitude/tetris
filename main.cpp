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
     * Bravo !!!! You have done a wondaful job !!! what a great achivement and lovely chance with also some great great wise assumptions and decisions !!
     * Stupid disgusting animals indeed, wumen wumen muney muney puwer get cars mansion yayyyy we do not care!!! ayyy
     * 
     * Medication genius ppl ayyy marvel delusions ayyy
     * Definitely way to go, lovely chance genius nation, wise ppl etc, CAN GET THE FUCK OUT OF MY FACE
     * Makin assumptions, ehehehe YOLO !!! OMFGGG DA NUMBA ON WEST MAKING DECISIONSS !!! Lovelyyy
     * 
     * Quiet successful actions by the genius nation of da universe the great wise western civilization marvel imaginations great professional workers !!
     * Lovely actions indeed, What else could you be doing !! AYYYYY
     * 
     * Definitely genius ppl !! Woowww
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
    CommandFactory::Init(*game);

    Terminal* terminal = new LocalTerminal();
    JoyStick* joyStick = new JoyStick(terminal);

    GameScene gameScene = GameScene(game, joyStick);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        gameScene.Draw();

        gameScene.Play();
        EndDrawing();
    }

    delete CommandFactory::GetInstance();
    CloseWindow();
}