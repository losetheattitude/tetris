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
     * There is no possible reality in which I could ever waste another second with any of you, 
     * you have to really incentivize like you all always do, ehehehe VIOLENCE!!!! the life !!!!
     * 
     * Remind yourselves the past you avoid like the disgusting animals you are
     * The education that you have beggingly promised ? The really honorable promises that you begged ?
     * and you still here to be taken serious ? ehehheh memory reboot, forget the past heehehheh please eheheheh
     * get women!!!! get womeen!!! we still delude on what the other person is valuing ?
     * And you still want to be taken into consideration ? You still have not waken up ? I DO NOT CARE
     * I DO NOT WANT TO SEE ANY DISGUSTING ANIMALS WHO TAKE THEMSELVES TO BE SOMETHING THEY ARE NOT
     * 
     * Thats all
     * Life you take so easy, hopefully one day you also realize what a mistake "THAT WAS" eheheheh
     * 
     * Hopefully you one day realize that every one borns like you do and does not know any prior information
     * thats how you get yourself into trouble by being the disgusting animal that you are and were 
     * Beg more eheheh, he craves womennn!!!! he craves women!!!! offer women!!!!! heheheheheheh
     * we seek no trouble!!! eheheheheh please!!!
     * 
     * You still mistake the person before you and offer still women for physical disgust ?
     * Do what you have to do, I WILL NOT EVEN MOVE MY FINGER FOR AN INCH
     * eheheheh fun life and fate life eheheh and ehehehhe good ppl, be sure thats the only thing I want to be around
     * 
     * eheheh bring more people please!!! this woman or that one should definitely solve A PROBLEM THAT ALREADY DOES NOT EXIST
     * A PROBLEM FABRICATED BY COERCION OF 5 MONTHS BABIES, you still think I do not remember the promises ?
     * 
     * Good nation you say ? I say I even remember the most insignificant detail ?
     * Do you want to talk more about your competencies ? or offer some woman who you also delude to be a solution ?
     * You see the problem now ?
     * 
     * Do you want to remember the past ? I EVEN REMEMBER THE MOST INSIGNIFICANT PART I SAY, WHAT DO YOU SAY ?
     * YOU STILL DELUDE ON YOUR NATION ? YOUR PROFICIENCY ? YOUR USEFULNESS ? YOUR REASON ?
     * Still offering some random women ? The delusion you do not say ?
     * 
     * You do not understand the reason you disgust people into depression ?
     * Still offering women for your disgusting existence around me ?
     * 
     * Do you need more proof ? Have a look at the footage that is available for years 
     * You see the reason why you put people into depression or harm physically and emotionally ? You still delude on offering women ?
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