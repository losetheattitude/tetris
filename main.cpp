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
     * Eheheheh problem solvers ehehehehe the genius people from the western society !!! Waaowwwwww, making decisionss !!!!! assumptions of
     * never ever seen kind before !!! 
     * 
     * Perfect job !!! YOU CAN GET THE FUCK OUT OF MY FACE !!
     * 
     * Stupid disgusting animals who thinks they can solve everything with medicine and coercion, What makes you think ?
     * WONDERFUL JOB !!! WONDERFUL ACTIONS AND INCOMPARABLE OUTCOME !!! You have done a great job !!!  Definitely !!
     * 
     * Useful as yourselves !!! The great genius nations !!
     * Bravo !!! A wonderful outcome built by not delusional people who would love to ignore consistently !! Because "THE PAST IS PAST !!"
     * 
     * You see the great decisions !!! OMFG !!! You must be the best of da best from the universe !!
     * Very very genius decision making performance FROM THE WEST !! Not delusional at all !! Only a few ten years !!!
     * Get wumen muney !!
     * 
     * Foolin foolin genius nations !!! FROM DA WEST !!
     * What a beneficial and useful outcome built by the very genius western disgusting animals !!!
     * 
     * Foolin medicine sleeping coercing sleeping TO CHILDREN eheheheheh, Australia ahhahah australiaa eheheheh good job !!
     * Germany eheheh france hehehehe england Great genius nations !!! Together for making absolutely nothing !!
     * 
     * Only a few ten years of nothing !! Not marvel at all !! Not delusional at all !! Perfect !!
     * 
     * The true geniuses of the universe !! Makin decisions and assumptions for other people who they do not care !!
     * What a lovely outcome indeed !! GO GALS!!! You are the best !! OF THE BEST !! I AM NOT INTERESTED
     * 
     * Little disgusting animals !! Nice job !!
     * 
     * The true and only genius nation on the surface of earth !! THE WEST MAKING GREAT DECISIONS and trying miserably to hide !!
     * OMFG !! what could be the problem !!! Wonderful actions and the outcomes !!!! Waaaowww
     * 
     * Eheheheh just a few ten years, its fine so long as nobody knows !!! Its okay !!! forget about the past !! eheheheh genius west!!
     * A wonderful job and outcome indeed !! Great ppl
     * 
     * Ehehe medicine etc ehehe coercion eheheheh scary eheheheh a few ten years etc ehehehe
     * Definitely good job !!
     * */ 

   

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