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
     * Event dispatching for Game class to further decouple and facilitate the transmission of internal properties otherwise
     * unamicable to perform so (Composition or inheritance(IExchanger like) ???)
     * Async environment for RemoteTerminal and RemoteStorages consider Disruptor for advancing purposes 
     * Stateful joystick (indeterminate due to current command and future observer pattern implementation) to grant player 
     * limited reversing ability (checkpoints to connotate). Requires mapping of opposite commands
     * IsState queries in the game class dont comply with Open-Closed principle
     * 
     * Guess who is not wanted ? And can never be so ?
     * You better find more children to waste 30 years and be proud about yourselves
     * 
     * Are you done jerking off ?
     * 
     * What a shame isnt it ? You have wasted 30 years with nothing in your hands except violence and coercion and medicine ?
     * Where did you arrive now ?  Ehehehhe you have done good job raising something you do not even understand eheheheh
     * 
     * Guess what comes after and who can never be trusted ?
     * Do you happen to see the problem now ? Awwww, you must have forgotten
     * 
     * Awwww you are so far from understanding that you are enjoying your life even when you are having that fancy conversations 
     * while others have to sit decades and do nothing while also subject to violence and coercion and medicine ?
     * 
     * Eheheheheh not a failure,
     * Guess who is not as disgusting as you are ?
     * 
     * Have you achieved the unattainable aim of true noble nature ? or you are just on a mission to ignore your actions ?
     * Where have you arrived now ?
     * 
     * Do you see the drama now ? ehehehe 
     * How come you claim to understand time when you are so free from your actions consequences let alone what life is about ?
     * And what a shame that you still offer materials that you value so high, what are the problems ? Do you have what it takes to see ?
     * What is the problem ?
     * 
     * Do you understand why you should not make decisions ?
     * Still ignoring and doing what you are told ?
     * 
     * Do you understand why violence is bringing more or are you just happy enough with your ignorance and try to enjoy your experiences ?
     * 
     * Ehehehe real life btw where we do what we want eehehehehehehe
     * How about you start dealing with your own problems ?
     * 
     * Do you really believe that someone would suddenly be so thankful for nothing ?
      **/ 

 










    InitWindow (500, 620, "Raylib Tetris");
    SetTargetFPS(144);               
         
    // Grid* grid = new Grid();  
    // Level* level = makeLevelSingleton(2); <    
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