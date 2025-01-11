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
     * 
     * Do sacrifice from your own instead of asking things you would not
     * Its as simple as anything can get, guess who is struggling ?
     * Next time, jump into wasting your OWN 30 years with ease 
     * Next time you deprive yourself resources without a reason, you will see why
     * Do not make the single irrelevant decision that is not yours
     * 
     * Thats why you are a disgusting inferior animal who loves to ignore for the sake of his own experiences
     * Whats wrong ? What are you waiting for ?
     * 
     * Awwwwwwwwww, its tooo late!!!!! we have already done what we were not supposed to eheeheheheheh we love our experiences!!!!
     * We better offer women for decades 
     * 
     * Ehehehehehe have fun!!!! heheheheh enjoy your experiences eheehehheehehe
     * You only live once eheheheheheheheh !!!!! great nation eheheheheh!!!
     * 
     * Ehehheehhehehe we love making assumptions that save our disgusting asses so that we can enjoy our experiences!!!!
     * Guess who feels okay whilst they should not have ? There is your problem
     * You can get the fuck out of my face
     * 
     * What are you waiting for still ?
     * Why dont you fuel your disgusting imaginations with someone else who is willing to ?
     * 
     * There is no way out until you suffer the same consequences while "advising others to waste time during your joyful experiences"
     * Ignore the consequences of YOUR actions, thats called ignorance 
     * 
     * What makes you think I will have the slighest desire to associate myself with the group who caused the stupidest things so far ?
     * What makes you think I will want to have anything to do with you ? The disgusting ignorant animals who do not communicate through spoken language ?
     * The disgusting animals who can not seem to understand that THEY DO NOT GET TO DECIDE THAT
     * 
     * Listen very closely here, YOU CAN NEVER BE WELCOMED, thats just it
     * There is no condition under which you can ever be considered, you handle your disgusting problems
     * 
     * I am not interested in anything you could possibly form, does that sound too complicated ? 
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