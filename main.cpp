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
     * and suddenly you become the most stupid animal by thinking that "forget about the past" should solve everything, is that the great understanding of life ?
     * So you still claim that you understand life ? Isnt that cute ? Eheheh I call that being a simple stupid animal, you still offering ?
     * And go on to brag about your nonexistent what ? eheheh extremely fun stuff indeed, especially the part where you delude that you are entitled to make decisions
     * that are not related to you and hope that it be okay
     * as you can guess though with your unseen intelligence, I want no animal around me like that
     * 
     * Especially the part where you delude on your justification of irrelevant decisions of malign nature and "still making offers" ? ehehehe 30 years eheheh fun stuff
     * pls no harm, pls we want live!!! no harm ehehe 
     * Please please, forget about the past, this is the we do not know what time that we have been telling you the same!!!! pls pls pls!!! do not harm!!! we like our experiences!!
     * Please harm eheheh you beg ? and you still delude that it should be fine that you commit so much and people goes eheheh yes please!!!
     * And you count on my "forgetfullness" ? ehehe please do this! say this!!! hit her!!! please!!
     * More medicine pls!!! ehehehe medicine!! eheheheh
     * I say disgusting monkeys, what do you say ? Awww you beg through offers as you have done so ? but you just can not account for your actions ?
     * Awww, you also wish that people forget ? The very same inferiors who count on others' harm eheheheh
     * and when the time comes, provides no reasonable explanations other than trivial irrelevant immature excuses ? and still demand that they be taken serious ?
     * eheheh forget about the past please!!!!!!! time does not exist! we take ourselves to be the single creature that understand the life!!! and we still call it fate!
     * 
     * Still after the same narrative that even your inferior nature knows that its insubstantial ?
     * And you demand credibility also ? ehehehehhe what a shame, afterlife afterlife!! lie!! lie!! pls
     * Are you trying to guise your unaccountable actions now ?
     * 
     * Are you still begging so that your disgusting nature would stay hidden ?
     * I say I do not accept your stupid excuses to delude on your entitlement of what is not your concern ? What do you say ?
     * Awwwwww itsss toooo laaatee!!!! please!!! its a lot easier to make some offers btw ehehehe its kinda of life and fate at the same time heheheheh pls pls
     * lie lie!! lie!!lie!!
     * Ehehehe we made lying into a huge habit that we take for intelligence!!!! is what you say ? I say animals ?
     * I say animals who like harming, what do you say ? eheheh pls lie!! lie! lie!!lie!! we like insulting!! lie!!
     * 
     * Itss too late!!! eheheh we informed educated immature animals still think we should make decisions!! please!!! get women!!!
     * Lie!! lie!!! we want to enjoy!! lie!! please!! we good ppl!!
     * eheheh its your time!! please!! do not hurt!! no harm!! forget the past! please!!! lie!!!
     * calm down!! calm down!! we want to harm pls!! lie!! eheheh great nation ehehehe please!
     * 
     * Do you want to talk about what ? ehehe honor!! religious!! family!!! justice!!! which one do you think you possess ? eheheheh fun right ?
     * Lie!! lie!! please!!! lie!!! we enemy!! lie!!!
     * 
     * Please please forget about the past, do not mention pls!!! eheheheh
     * hehe you havent achieved anything other than causing mayhem ehehehhe pls pls lie!! get women!!! lie!!
     * you like harming ? but also "forget about the past" ?
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