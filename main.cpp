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
     * The fact that you delude on your actions being okay while the reality is completely opposite of that, the disgusting animals hence
     * 
     * I guess the disgusting animals should try their chances with more children, thats what you can handle
     * seek for more children inferior disgusting animals, offer children material as your disgusting nature allows such a "behavior"
     * 
     * Are you still offering things ? You have arrived to nowhere by wasting 30 years of what you do not own and taking that for a skill ?
     * Yet you still claim you are not a disgusting little animal ? How about you seek for more children ? and stay on your own disgusting inferior level ?
     * 
     * I do not accept no animals like you around me whatever disgusting excuse you think you have, I DO NOT CARE
     * still the same animals without a proper explanation, delude that I would love to be around you
     * 
     * Get more children to be proud about, waste a few decades and pray that everything goes really well
     * From out of my vicinity, I do not care about your titles or your delusions of whatever nature
     * 
     * The great people with great titles who chases children, make sure I would even consider a second to see you for what you are not, thats called delusion
     * Just the inferior disgusting animal that is rife everywhere!!! Thats all, I do not want to waste my time with any of you
     * 
     * Just like the animal you are who deludes to avoid his responsibilities
     * Go for more children, you do not need no explanation because you are the very disgusting animal who is rife
     * 
     * The immature disgusting animals who takes regular actions to be a gift to others, you see why you are delusional ?
     * Still the same disgusting animals who can not see that THEY HAVE ARRIVED TO NOWHERE yet what a pride they have
     * 
     * Still the disgusting same animals who provides the worst examples to cover their disgusting nature
     * Who can not see that they have arrived to nowhere yet WHAT A PRIDE! ehehehehehehhe
     * 
     * The disgusting animals who still think that I would even consider to waste my time with such abominations
     * The disgusting animals who still talk about afterlife and offer materials still
     * 
     * Who can not explain anything that they have perpetrated so far, only the avoidance that merely works with its own kind
     * Who takes his actions to be funny when the reality is the quite opposite of that, what a miserable animal right ?
     * Who still offers what their inferior nature craves for, when the time they have wasted is incomparable to basic materials yet eheheh fun stuff
     * Who still hides behind his disgusting guise instead of accounting for his own behavior just like the "responsible" humanbeing that they delude to be
     * 
     * Who takes life for a game when its not his own, very good
     * Who takes everything to be a okay when its not his own, I do not want any of that around me
     * You only understand when its your time to waste your years, then it will occur you what a disgusting animal you are
     * 
     * Its your time to waste your years without resources then we talk about the rest
     * Then we talk about my experience which you have intentionally ruined, guess what ? are you still offering women ?
     * Why is it that you take others to be on the same disgusting level as you ?
     * That is the type I DO NOT ACCEPT AROUND ME, whoever you think you are, its regardless, I will pass on all of you
     * 
     * Those you do not recognize their boundaries and bend against any crime they have committed, thats the real talented people right there
     * The disgusting animals who do not realize what they are doing has not been working, guess what ?
     * Who still waste time to enjoy their precious experiences while advicing otherwise, and expecting others to understand their really enjoyable experiences
     * 
     * Arriving to nowhere yet being intentionally unaware of it, what a good combination
     * You do not know how to listen ? and you also like abusing ?
     * 
     * Do you still think you are fooling or do you realize what you got into ?
     * Like the inferior animal who knows only to hope for the best ? How about you get more children and jerk off to your own experiences ?
     * Still after offering the most normal things after years of stupid conduct of your own nature ? Get more children and start yapping about fate
     * 
     * I do not accept anything that comes from any of you, make everything harder see who is losing
     * I have no intention to waste my entire life with selfish people like you, I do not care whether you delude you provide something valuable 
     * 
     * You are providing nothing, and still asking for incomparable things from people you have only selfish interests over
     * Thats why
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