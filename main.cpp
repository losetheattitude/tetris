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
     * Guess who is still making decisions that are not their place
     * Guess who is still demanding respect while they are unable to see that they do not deserve it 
     * 
     * That is not the problem but just try to guess who is not interested ?
     * Guess who never considers jeopardizing his experiences ? eheheh
     * 
     * I am not interested in your selfish dispositions, thats the only thing you can ever hear
     * Because you know you are guilty
     * 
     * How about you continue enjoying your experiences from out of my vicinity and keep your delusion on the highest level possible
     * I am not interested
     * 
     * As long as you see the problem of you, the people who takes themselves for to be so great and big they attempt at everything,
     * its okay that you also ignore your ignorance, I can never be interested in such quality
     * 
     * Guess who is not interested in immature people who acts like they had to
     * Why suddenly are you taking the life to be so serious ? Awwww, is that the pattern again ?
     * 
     * What makes you think I could ever want to do anything with such a lowness on the scale that can not account for his own behavior ?
     * 
     * The most credible people on the surface of earth is still asking things from people they harm intentionally ?
     * Whats wrong ?
     * 
     * Guess who is still crossing personal boundaries and asking things from people they commit ?
     * Awwwww, havent you forgotten ? Ehehehehe why are you still making promises the joint genius nation ?
     * 
     * Why arent you constantly accusing with bullshit ? Awwwwww, you just stopped for a brief time eheheheheh
     * Are you still making offers ? ehehehe where have you been ?
     * 
     * Guess in this story who can never be wanted ? Try to ignore your part then it may make sense
     * Are you still making offers ? What is the problem ?
     * 
     * What have you now gained ? The genius nation ehehehe ?
     * Are you still making offers ?
     * 
     * Eheheheheh its so easy to trick people with fake offers ehehehh
     * What a genius nation 
     * 
     * What have generated ? Nothing ?
     * Why dont you talk more about life and time ?
     * 
     * Immature people can continue enjoying their experiences, I am not interested
     * You are welcome to ignore your decades of inexplicable actions and their consequences as if its nothing
     * Thats definitely fine
     * 
     * You are more than welcome to get the fuck out of my face indefinitely
     * Guess who is on such a level of immaturity and irresponsibilty that they can never be trusted and respected
     * 
     * I am not interested in anything you can offer or form or claim
     * Yeah, thats life and fate ehehe
     * 
     * Grant yourselves the amount of seriousness that you do not remotely deserve and continue with your selfishness, I am not interested
     * Now is the time where you justify your actions through making others look disgusting, guess who is not interested
     * 
     * You can continue enjoying your experiences
     * Really really helpful and useful stuff indeed
     * 
     * Now it is the time where you hide your disgusting nature
     * Ehehehe what we do produces significant value for us!!! its really important that we harm people and prevent them from experiencing ehhehehehe 
     * 
     * Make assumptions for your own life
     * As you can tell that you are less than nobody, you can never be welcome
     * 
     * I am not interested in your predefined events, do you understand what that means ? I do 
     * Guess who is crossing the boundaries eheheheheh
     * 
     * 
     * Guess who is not interested in hearing bullshit excuses eminating from selfish incompetency
     * You are effectively nobody, so why dont you already act on your great skills because as you can guess, I have no intention to waste my time with you
     * under whatsoever circumstances
     * 
     * You can fuel your imagination with truthful things
     * You are still making decisions ?
     * 
     * What excuses do you still propose ?
     * What are you aiming at ? Whats the problem in waiting ?
     * 
     * Why are you still waiting ?
     * You have generated nothing but you also wait on for something ? WHAT ARE YOU WAITING FOR ?
     * 
     * 
     * What are you waiting for genius nation ?
     * Why arent you producing anything with your inexplicable actions so far ? 
     * 
     * I have told what I wanted to tell, you can never be wanted with your disgusting nature
     * You are the entity who thinks wasting 30 years with "violence" and "lack of resources"
     * so you can continue deluding yourselves, I am not interested
     * 
     * Get the fuck out of my face and get your hands on to more children you can skillfuly abuse
     * Thats your capacity of ignorance
     * 
     * Really realllyy skillful people, talk more about highly achieving violence that is of your nature
     * Incredibly successfull people, just coerce others and try to observe the outcomes, do it within your own circle and you will see why
     * 
     * Such a great and productive and instructive aim that you have set, anyone would be proud
     * Handle your own problems and "live your own life", does that really surprise you ?
     * 
     * Eheheh have you grown up ? awwww, wait have you woken up ?
     * What a success!!!!
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