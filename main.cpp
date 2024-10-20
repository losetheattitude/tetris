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
     * What happened ? Can you now only beg for silence ? Why is that ? Its the same group of stupid animals who get themselves into the very same situation
     * but they made it into a habit harming others and getting away with because they are facing "superior" unlike the disgusting entities that commit ?
     * 
     * So you say you would rather beg for preserving what you do not deserve ? and some violence and threats and etc
     * and also some offers and promises and religion etc you say
     * and you would also prefer ignoring what has been constantly told you that you are not actually achieving anything and continue acting like a stubborn disgusting monkey
     * who knows his guilt is unforgivable ? and you would also allege that you should make decisions ehehe such a funny thing 
     * and you would also love to show off your incredible interaction skills to the society through matters that are not your concern ?
     * 
     * and you would also like to ignore what has been told to you multiple times that "YOU ARE NOT RELEVANT AND I DO NOT WANT TO HEAR ANYTHING YOU COULD SAY ?"
     * and you still there demanding to be taken into consideration ?
     * and you still think you should play stupid games over someone else's life and ignore the truth ? 
     * Its fate btw help btw!! help lie!! lie!! I say selfish immature irresponsible conceited animal, what do you say ?
     * pls pls we do not want to get harmed lie!! lie!! help lie!!, what do you say ? awww you say intelligence hehehehh
     * Did you just say "afterlife" ? But you still would like to enjoy your experience ? and harm people who you neither have relation nor any rights whatsoever ?
     * and you still think that its funny
     * Disgustingly immature and selfish and greedy I say, what do you say ? Awww you are only begging ?
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