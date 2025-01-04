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
     * I have told you that nothing has even changed a bit ? So now what do you think is going to happen after your actions ?
     * Try to use your superior guessing abilities again ?
     * 
     * I am telling you that not even a thing has changed ? So where did you arrive now ?
     * 
     * What happened now ? How many years have you superiorly decided although nothing was being granted to you ?
     * 
     * What has changed after years of irrelevant actions ? Why arent you talking sense ? What happened to your genius ?
     * Who gained what after 30 years ? A decision that was not even discussable ?
     * 
     * You know what, why dont you gather 2123013 people and do more harm to see if its helpful still ?
     * Guess who will never be interested in people like you ?
     * Guess who would never consider a group that can not account for its behavior ?
     * Guess what has not changed ?
     * 
     * The most useless thing you could have ever done, and guess who is not surprised at your incompetency at hiding your true intentions ?
     * What are you doing ? ehehehe ? Guess who is not interested in helping out selfish people ?
     * 
     * No resources is definitely the way to go, its most helpful as your allegations are too
     * Do you want to be reminded to your prior actions or you would just love to ignore them as well ? 
     * What is it called when someone is ignorant but also ignores his own actions that harm innocent people ?
     * How come you take others to be as cheap as you ? the genius nation you say ?
     * Did you now manage to recognize your nature btw ? Handlers of the children, ehehe coercion is just good!!
     * 
     * Illegal btw ehehehhe, enemies enemies ehehhehe illegal btw hehehehe
     * Intelligent and developed ehehehe and credible hehehehe smart genius nation ehehehehe
     * Definitely what you also delude yourselves to be, eheheh
     * lets gather 10230012 people and assault single individual ehehhehehe, intelligent and developed and eheheheheh genius eheheh
     * Most scary stuff, really really scary stuff, as scary as your intelligence and development and genius eheheheheheh
     * 
     * Fucking immature ignorant kids, I am not interested in
     * directionless stupid animals, why are you begging to avoid your intentional actions ? thats how to be what ? eheheeheh
     * Most successful, its just really difficult to achieve what you achieved ehehehe, guess who is not interested ?
     * 
     * Guess who is not interested in insecure people who failingly hide their disgusting nature ?
     * The most disgusting group of people that I have ever interacted with so far ? Are you still looking around ?
     * 
     * Just guess who is not interested in interacting with insecure inferior animals ?
     * How about some coercion of medicines and feel good afterwards about your ability to handle children ?
     * 
     * Ehehehe, he needs to be educated ehehehe, how about we ignore years of evidence and eheheh some violence because we think we are good animals eheheh
     * How about some selfishness and ignorance with some genius nation ehehehehehehehhehehehe
     * 
     * I do not accept any of you around me, the very inferior animals who can not comprehend that you do not get to make that decision
     * You still do not realize your mistake ? Or you would just rather enjoy your experiences and ignore your disgusting actions ?
     * How about you try harder to come up with bullshit for your actions ? How about you explain your conduct before impartial people ?
     * Instead of deluding on your competency ?
     * 
     * How about you deal with your own problems and do not act like you know what you are doing ?
     * How about you get the fuck out of my face 
     * You are still not arriving to nowhere ? ehehehehe genius nation you said ?
     * 
     * Get the fuck out of my face with your inexplicable disgusting actions that you hide behind obscure entities
     * Immature people who does not understand that they are not wanted nor do they see they are not achieving anything
     * Guess who is not genius nation ?
     * Guess who does not communicate through spoken language ?
     * Guess who does not abide by the "rules" that they brag about and still deludes on their qualities
     * Do you want to talk about decades of actions that are caused by intentional misconduct ? eheheh calm down!!
     * 
     * What do you want to talk about now ? Your wiseness or fairness or skillfulness ? do you see the delusion ?
     * How about you ignore years of evidence and try to justify your impossible actions ?
     * Do you have something accurate to say ? The genius nation ?
     * Why dont you gather 102312321 people and attack your surroundings ?
     * 
     * Do you see the ignorance and incompetency ? I am sure you do not see that as well
     * How about you advise people to calm down while you commit the unspeakable ? How does that sound ?
     * Do you now see the incompetency even at failing at your job ?
     * How about you talk more about time as if you understand or care about shit ?
     * Isnt it too funny that you offer what your disgusting nature would love to have ?
     * 
     * Are you planning to explain and account for your own behavior the genius nation ? or just like harming irrelevant people ?
     * Reallly realllyy competent and wise and skillfull and scary people, what are you waiting for ? eheheheh
     * 
     * How about you pay for your own actions and get the fuck out of my face ?
     * The great competent and skillful and what else were you saying ? Genius nation eheheheh
     * 
     * Are you still making offers ? With which disgusting audacity ? 
     * Do you want to talk about your credibility first ?
     * Where did you arrive now ? You were saying illegal ?
     * How about you get the fuck out of my face while knowing that you have wasted irreparable amount of time ?
     * You already know its not okay, so better prepare to pay for your own actions then handle your own problems
     * 
     * Why dont you talk about your own actions that have no reason ?
     * What are you waiting for ? disgusting animals ?
     * 
     * Still not achieving anything other than cheap actions ? who could be wrong ?
     * Where is the great outcome of your reasonable and obligatory actions ?
     * 
     * Why is nobody observing the achievement of your actions that you were not granted in the first place ?
     * Heyyy, the great nation eheheh genius nation ehehehe ? What did you now achieve ?
     * Do you still need help ? eheheheheh ? Help us!!! eheheh
     * 
     * Stupid disgusting animals, you still look around for guilty party ? eheheh ?
     * How about you pay for your actions and get the fuck out of my face ?
     * 
     * What did you now achieve ? Eheheh I guess its too late you are going to say ? What a disgusting stupid animal you are ?
     * Are you still predicting the happiness of someone you are actively harming ?
     * 
     * What is the new major aim now ? hehehehehe its just a couple decades!!!!! its nothing!!
     * We just offer the normal things, and suddenly its fine!!!
     * How about you handle your own problems ?
     * 
     * Are you still deluding on your achievements ?
     * What exactly have you accomplished now ?
     * Guess who is not alike to you ? I am not interested in anything you could possibly form ? How many times do you think you need to hear that ?
     * 
     * Ehheheheh just dont do anything and heheh waste your life hehehehe 
     * What a shame you are still a disgusting monkey who offers the most basic material which should have been already there!
     * 
     * Making the mistake of "guessing" miserably that I will start suddenly begging like you do ?
     * How about some medicine ? eheh ? You have achieved the unachievable!!!! yeyyyy eheheh genius nation btw!!!
     * 
     * Try to guess who is not interested in a couple group of people who has nothing better to do than to harm people ?
     * Guess who is delusional on think the most normal things would change the perspective of decades ?
     * Now again, what did you achieve ? Guess who is not interested in delusional people ?
     * Guess who can not account for their behaviors ?
     * 
     * Guess who can not explain no resources with "eheheh the violence obligatory" 
     * Do you want to talk about your violence motivated actions ?
     * What are you waiting for to happen ? Ehehehehehe ? why not more children for you to HANDLE ?
     * 
     * Whats the aim in your stupid behavior ? How about you demonstrate how great you are through violence heheheheh ?
     * I do not have time for directionless people, I am not interested, you can get the fuck out of my face
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