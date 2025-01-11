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
     * I will never be interested in what you can offer ? Does that sound good ?
     * 
     * Continue deluding on your qualities or your really accurate observations, I am not interested 
     * You can get the fuck out of my face with your highly accurate excuses, I am not interested
     * 
     * You can continue feeling like you are doing great, I AM NOT INTERESTED
     * I am not interested in ignorant groups, you can continue deluding, from out of my vicinity
     * 
     * Guess who can neither fix nor produce an outcome ?
     * You can be never wanted 
     * Why arent you getting results ?
     * 
     * Why your genius plan that involves violence and waste of time does not produce results ?
     * Why does not your genius plan work ? What are you missing ?
     * 
     * Guess what are you missing ? You CAN NOT MAKE DECISIONS THAT ARE NOT YOUR PLACE then to offer the most basic physical interaction for decades
     * Take that approach for your own life, I am not interested 
     * 
     * Take that approach for your own lives, I AM NOT INTERESTED IN WASTING MY TIME WITH PEOPLE WHO DO NOT KNOW WHAT THEY ARE DOING
     * Yet another thing you are missing, nobody would ever consider none of you, just take a look at your doings
     * What a shame you are still the same animal, guess who is not interested rightfully ?
     * 
     * You can never be wanted, your ignorance and irresponsibility is leaking all over, I do not want none of that indefinitely
     * Play games with your own lives, try not to pay attention to your incompetency, you will be fine
     * 
     * You will guess nothing will change as well, just get the fuck out of my face I am not interested
     * What a shame that you are still proud or sure on your devices, guess who is not wanted despite their really important resources that they wield as weapon
     * 
     * Waste your own time while knowing that you are the one who has crossed the every single personal boundary, therefore the disgusting ignorant animal
     * 
     * Guess who is not interested in your fake attitude ? Say some nice stuff its fine since its not our time that we destroy
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