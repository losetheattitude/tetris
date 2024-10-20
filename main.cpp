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
     * Please assault people so that we can prove our honorable conduct!!!! hehehe
     * 
     * Please lie!! lie!! lie!!!eheheh assault!! harm!! pls!!! we need our precious experiences!!
     * try to explain your conduct eheheh I say, what do you say ?ehehehe please please lie !! lie!!! we intelligent!!
     * Awwww, you say, have some womeeeennn!!!! but then we come after you eheheh physically harm!!!! ehehehe pls pls lie!! intelligence pls!!!
     * Have some womeeenn!!!
     * 
     * You would rather beg for what you do not deserve is what you are saying ? Awww you say "hopefully he does the same ? eheheh pls pls pls"
     * Are you still begging ?
     * Forget about the past!!! please!!!! assault!! forget about the past!! liee!! help!! lie!!!
     * Please we want harm!! lie!! forget the past!!! please! and you offer women you say ? 
     * Talk more about violence and religion and virtue eheheh also some intelligence then proceed with your beggings
     * Talk a little bit more about VIOLENCE I say, what do you say ? forget about the past!! please!! please!!! forget about the past!!
     * I say irresponsible immature monkeys ? What do you say ?
     * Awww you offer womenn ? you say ? and what happened back then ? eheheheh please please!! lie lie!!
     * 
     * What was the experience btw ? ehehe no resources!!! please!!! no resources!!! lie!! lie!!! pls!!! ehehe violence!!! pls!!
     * Everytime though you reduce to your own nature somehow ? talk more aobut violence instead of asking for lies, you can then understand ehehhe fun right ?
     * You feel like you are doing something very useful you say ? ehehe that may be the problem
     * and you solicit lies after years and years of evidence both proving your inferiority and lies ?
     * Eheheh have some woooomeeeennnn!!!!! Forget about the past!!! ehehehe have some womeeen!!
     * 
     * Talk more about resources and their correlation to your honorable aim 
     * Say this for us!! do this and you get this!! ehehe intelligence!! intelligence!!! we try to prove points to you, is what you say ? 
     * Be silent!!!! eehe lie lie lie!!! get women!! get violence!!
     * Awww you just say you are irrelevant immature people who have nothing to do other than harming and being proud of such ?
     * You take that for a job and call it a good aim ? and start asking for lies immediately ? you see the pattern ?
     * and you even go as far as calling your irrelevant actions "purposeful ?"
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