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
     * There is no such a thing as memory reboot, you pay for your own actions and things that you said you will but you havent, then you continue living your
     * own disgusting life and do not engage ever with thing you are not even closely alike
     * You lose your really precious limbs "that you religiously promised to" eheheh funny religious people who is afraid of violence and so wield it as leverage
     * 
     * As you can guess, it will be %10000000000000000000000 chance violence for dumb religious people
     * eheheh we talk like this, we good efficient professional doctors eheheheh pls pls money pls life we want live eheheh
     * fucking worthless beggars
     * 
     * Remind yourselves the begging promises you make to a child and teen and adult, then start talking about why you are so right etc
     * and still think you should make decisions because you have this or you are right because etc etc
     * 
     * You would hate to remember your beggings to little children eheheh lifes over lifes good we fair we good we just
     * remind yourselves the "skillful coercions as well" eheheh, may be you should not ask for lies "FROM ME" eehehe, fun stuff right, I would say disgusting cheap animals
     * eheh, may be you should first talk about coercions to which you later on provide as "proof" for your violence ? not cheap btw, and definitely the family is important
     * like you value religion and honest as well
     * 
     * talk more about your prior actions before you start talking as if you are a sane honorable individual who needs to be taken serious
     * also remember not to beg more next time
     * beg more to keep it on the low and do not include anyone who can fuck up your incompetent lies, fucking stupid monkeys, religion btw indeed 
     * talk more about the life ehehehe beg with materials as thats who you are, most religious
     * 
     * Most skillful indeed, we re your family!!!! plss family!!!! eheheh, we represent god!! we good religion ehhehehe pls pls 
     * most skillful indeed you can decide to harm, fucking dumb animals
     * most skillful as well that you think you should make irrelevant decisions because you are some sort of religious entity ehehehhe 
     * eheheh do you love your life ? just as I thought what you are, you are a desperate fearful animal who takes violence for threat or education, what a correlation eheh
     * 
     * Try to lie to people before me, who knows what is what
     * That is indeed most skillful that you fool entirely average people and gather 100 people against one individual you have not
     * even the most irrelevant understanding with, eheheh life btw eheheh
     * eheheh it must feel really great hehehehe, not homo sapiens eheheh
     * not the never learning homo sapiens who chases emotional disgust without even knowing it ehehheheheh pls pls pls we like harm ehhehe
     * eheh forget about the past heheh pls pls heheheh, ehehehe violence violence hehehe stay silent heheh forget about the past, (wait!! he is not as afraid
     * as we are like the inferior homo sapiens we are ?) not the homo sapiens that think they can compensate everything heheheh
     * eheheh not the homo sapiens who think they are doing something, they can not even explain other than saying irrelevant things ehehhehe pls pls pls pls ehehhe
     * ehehhehe
     * 
     * not the homo sapiens who think they play games until they are told somehow THEY ARE WRONG
     * not the homo sapiens who think playing nonexistent stupid games over others lifes is "badass" and people are afraid because of it, guess what ?
     * not the homo sapiens who disthink that they do not enjoy but its a necessity ehhehehe I am definitely relevant to whatever you are doing as you are not animals
     * not the homo sapiens who can not predict what their actions would entail, the sapiens who delude on what they have caused is "GOOD", whats my experience like ? eheheh
     * Thats most useful for everyone, the same sapiens who take everyone for themselves
     * the sapiens who appear and act entirely childish ehhehehe, pls pls pls 
     * the very same sapiens who their superior would not even consider wasting one second with them, take a look at the history assess your stupidity
     * simplicity is definitely the way to go ehehhe, chase more simple emotions ehehhehe violence we like harm eheheh pls pls lie forget ehheh
     * eheheheh look how clever we are !!! ehehhehe we think nobody gets it heheheheheh pls pls hhehe
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