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
     * Stateful joystick (indeterminate due to current command and future observer pattern implementation) to grant player 
     * limited reversing ability (checkpoints to connotate). Requires mapping of opposite commands
     * IsState queries in the game class dont comply with Open-Closed principle 
     * 
     * Do you compare what is usual to what can not even be named as acceptable ? The holiday ? Do you know what it means to be an adult ?
     * I am not referring to myself, your doings is the precise opposite of being an adult
     * 
     * How do we free ourselves from our disgusting decisions and promises in a way that wont turn us into something worse than we already are ? eheeheh
     * The pure intelligence together with unseen character development and so on. The greatness!! Enjoying what they can not openly talk about!! 
     * The claims though ? !!! ehehegh, Have no other preoccupation to stimulate their inferiority, so why not ?
     * 
     * Dont even assume I have forgotten any of yours' behavior. Thats what sort of people like you call a talent, infallibly through out the world
     * I have seen so ample that I dont even have to think twice. You are just the precise inferior I have witnessed everywhere
     * So thanks for your hassles so far and Imma pass for eternity. You are building whats not yours ?
     * 
     * Are you still wasting others' time while you selfishly entertain your boring life with your stupid games that have no adverse effects
     * but to others ?
     * 
     * Are you still looking around for an answer or someone to tell you what to do ? Do you still desperately trying to make it
     * appear like it is all my choice ? Your sole solution ?
     * 
     * Do you want to explain the past ? Or would you like to ignore your disgusting inferiority ? Guise it with whatever you can reach at that
     * moment of presenting ? Disgusting sick pieces of craps
     * 
     * Are you so incapable as to not include the very individual into the bullshit environment that you have happened to be situated at just 
     * so you will have the slighest undeserved advantage of appearing righetous for an insignificant moment ? 
     * It is impossible to justify your vile inclanations when around the "subject" ? Isnt that right ? So what are you still talking about ?
     * You just need to be around people like you and feel a little stimulation whether that be freeing from a guilt or something else through
     * totally bullshit means like cultivating a group that will say anything and feel great about your incomparable intelligence. Go on to your jerk offs
     * 
     * Thats not how it is done. I have never been the one who wanted to be involved with such lowness on the scale as you. As it is more than apparent
     * every single time, you are there to demand you taken into consideration :d Fucking monkeys
     * 
     * I do not want any of yours relations or link or connections or whatsoever. Just proceed deluding on things you can not harm and can not receive harm
     * 
     * "We just dont know whether we right or wrong, we just hope we dont get hurt and indulge!!!", thats the vibe, greattt!! If you havent done nothing wrong
     * you have nothing to get offended from. Thats my vibe
     * 
     * Keep telling yourselves whatever you delude to become some day in 24. century or something. With your level of development it will take nothing less than
     * Debate, reason, comprehension etc bla bla yeahhh bro, I got you all, you good you can delude without me please, I free you all from baring the burden of
     * I, whatever that entails
     * 
     * Abundance of the manifestations of your minds is apparent and that tells your regularity as well. You are the incarnation of what is usual. 
     * Dont pretend otherwise
     **/  



           
  
    InitWindow(500, 620, "Raylib Tetris");  
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