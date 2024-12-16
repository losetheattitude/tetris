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
     * I do not want to see people like you around me, its just that and also your disgusting delusions
     * that are causing you to believe into stupid approaches
     * 
     * You know how to listen ? ehehe The greatest achievement of all!!! eheheh need more children ?
     * You all are just nobody to me, so why waste more time ? I do not accept any of you around
     * Simple afraid animals, do what you have to do
     * The never learning animals who do not know how to listen, make sure I would be willing to waste another second with you
     * You are officially nobody and there is nothing you could do to change that
     * Do delude on your inexplicable behaviors being acceptable and people would die to be around you and your disgusting actions
     * 
     * Find more stupid people as you who will consider coercing medicine and lacking of every single resource as a precaution. fucking disgusting monkeys
     * delusional monkeys, guess what ? eheheh do what you have to do with your delusions, I am not interested in your disgusting behavior you can not account
     * still offering the most disgusting lifestyle and jerking off to your competency ? Get the fuck out of my face 
     * 
     * Literally do what you have to and get the fuck out of my face, dumb animals
     * You have nothing in your hands ? still looking around waiting for help ?
     * You feel like you have achieved something ? eheheh thats the problem
     * The problem of you being a stupid directionless stubborn disgusting animal, and whether you think you own the world, I do not want any of that around me
     * Are you so delusional to the extent that I will ever consider wasting my time with such a group that has caused so much ? eheheh its fun!!!
     * 
     * You see when you "decide" whats not within your boundaries, you always get this result, which is I do not want to see any simple animal around me, DO WHAT YOU HAVE TO DO
     * still jerking off to your inferiority ?
     * Do you think you are mature enough to make "that decision" or are you just trying to show off ? Guess what ?
     * 
     * WHAT DO YOU HAVE IN YOUR HANDS NOW ? Are you still begging ?
     * Thats a great skill, now you can get the fuck out of my face with your really good offers as "WOMEENNNNN!!!"
     * 
     * Do you even know how to listen ? Still wondering whether this is a mistake or not ?
     * ehehehe turning back is no option!!!! ehehehehhe we like guising our disgusting feelings and project them onto others with
     * inexplicable excuses, eheheh dragging people into "games" ehehehh
     * 
     * eheheheh dragging people ehehehehh fo!! eheheh being foes!!! ehehehhe dragging children eheheheh calm down!! its only 30 years heheheh please!!
     * we like making decisions that are not our place and look around for responsible people!! ehehhe fo!!!
     * 
     * Awwww what do we do now ?? Still deluding on your actions being okay because you will "grant" people to do things ?
     * Arent you the simple disgusting animals ? Do you still delude on my relief on the "freedom" ?
     * 
     * Do you understand what is being told to you ? or you are just a simple disgusting animal ?
     * I am not interested in anything you could possibly form hence your credibility
     * 
     * Hence the disgusting animals that arrived no where 
     * Heyyyyy ?? hehehehhehehe whats wrong ?
     * Hey ? why arent you talking sense ? eheheh you thought it should be fine ?
     * You avoid to explain what you have enjoyingly committed ? 
     * 
     * I am telling you, you have no credibility to negotiate with, thats all for me
     * Eheehheheheheh 30 years and now you can have some things, BE GRATEFULLL!!!!! eheheh its that easy, hopefully everything goes really well
     * 
     * I want no simple disgusting animals around me, the insecure disgusting animals who take being the cheapest form of human for a skill
     * ehehe instead of baring some responsibility, why not continue enjoying our lives!!!! act like no such thing happened
     * 
     * Are you paying for your own actions or will you be the disgusting irresponsible animal ?
     * Still cheaping ? how about you beg for more lies 
     * no no!! how about you gather 110231231 people and try to prove everyone what a competent group you are ???
     * Still delude on your actions being "entirely normal" ? Thats the problem, its a indiscussable thats why its a loop
     * You know see, why you are a disgusting simple animal who likes to beg with many guises
     * 
     * Do you see now why you are a disgusting animal ? Who can not even explain where it has arrived
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