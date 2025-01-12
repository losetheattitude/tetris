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
     * Guess who is also "proud" and not wanted
     * 
     * Guess who has wasted 30 years with bullshit excuses, thats the reason
     * As the history has proven ample times, the people such as very like you have always made messes of incomparable nature to their own
     * Thats the reason I will never be interested in your disgusting excuses as well
     * Get more children to handle selfish monkeys
     * 
     * Thats why you are a little inferior animal
     * Hide like the disgusting ignorant animal that you are
     * 
     * Sacrifice your own resouces next time, like I said, little animals
     * Little incompetent, irresponsible, unaccountable animals who would love to ignore for the sake of their own experiences, guise your disgusting nature
     * 
     * Guess who is the delusional ones ? What a shame though eheheheh you are in a position of ignoring right ?
     * Guess who is not wanted ? What a shame that you get to delude on your incompetency even at making excuses
     * 
     * Continue deluding, FROM OUT OF MY VICINITY
     * The disgusting animals who have to act like they are doing the right thing can remove your inexplicable nature from out of my vicinity,
     * You can never be wanted, there is no such a thing as making decades of decisions for someone else
     * Yet look where you are, what have you gained ? What has changed ? All of you are the same ignorant beggers
     * 
     * Where have you arrived ?
     * 
     * I accept no such animals around me, thats the only think you can hear
     * What makes you think I would consider breaking the laws as remedy as you have done so against me ? Are you on the disgustingly low level as to
     * draw that as an equal conclusion ?
     * 
     * That explains a lot, you all get to pay for your own actions, not others
     * Make no mistake although that is a lot to ask from you, you get to pay for your own actions, not others 
     * 
     * Not with what is ample, great job indeed, the most unattainable aim
     * Who is also deluding others' desire to be ? Does that give you a clue about how wrong you are ?
     * 
     * Eheheheh we just do not know what we are doing but it must be good eheheheh
     * Ehehehehhe we just have done really good eheheh hopefully everything is good
     * 
     * Ehehehe just do not harm nobody eheheheh
     * Hide like the inferior animal you are
     * 
     * Yaaayyy, we did it!!!! it was a great experience!!!!! eheheheh
     * Yayyy we love to ignore hehehehe
     * Yayyyy, its just nothing because its not us!! eheheheh offer some women it will be fine eheheheheh we love our experiences eheheh
     * Awwwwww, its already too late!!!!! ehehehe
     * 
     * Guess who is not alike and is not interested in your excuses ?
     * We call it sacrifice because it sounds good!!! eheheheh we love delusion but also ignorance!!
     * 
     * Ehehehe its irrelevant that someone lacks resources but we just like harming people heheheh
     * Like i said, delusional ignorant people
     * 
     * Why are you still here doing your best to ignore the truth ? I do not want to see any of you around me
     * You are just average ignorant people who would do anything to enjoy their life
     * 
     * You can never be welcome as you are the most unaccountable person in this context, you can remove your disgusting nature
     * You are the type of inferiors who hide his mess just the way you do, that is the sole problem
     * 
     * Just a couple of ten years, whats the deal ? Ehehehe we just like our own lives thats it
     * Ehehehe we just perform experiments and hide it like our disgusting nature
     * 
     * Eheheheheh we have done realllly welll!!! ehehehehe life is good !!!
     * Its all for the greater good!!
     * 
     * Other people is just another opportunity for our short disgusting lifes!!!! Thats who we are!!! we doing welll!!! yayyy
     * Because we can!!! heheheheh
     * 
     * That is not ignorance I promise you eheheh, its all for the greater good ehehehe we love our lives!! please just harm others!!!
     * The great people can never make mistakes ehehehehehehehehehehehe you continue ignoring
     * 
     * The great people who seeks for materials and offer the same to people who has wasted decades because of the great people's ignorance and selfishness ?
     * How does that sound ? Ehehehe we do not care eheheh we ignorant eheheheh
     * 
     * We have literally generated nothing eheheheheheh its really fun ehehehehehehe
     * We have done well !!! eheheh its just fate
     * 
     * Guess who is not welcome because of not their decisions ?
     * What a shame, do you even understand what I am saying ?
     * 
     * YOU CAN NEVER BE WELCOME, guess who is failing ?
     * Awwwwww itss tooo late!!!! ehehhehe we would rather enjoy our experiences ignorantly anyway!!
     * And most importantly, we offer materials our disgusting nature love to have when we are in a tough spot and know that we are guilty
     * 
     * 
     * Awwwwwwwww, itsss tooo late!!!! ehehehhe just get some women ehehehehe we have done well!!
     * Just leave us so that we can enjoy our lives, nothing matters!!!
     * 
     * Eheheh itss already tooo late hehehe, its fine because we can !!! eheheh 
     * Eheheh doing it wrong and surprising at the outcom ehehehehehe we doing welll!!! yayyyyyyy, ehehehhe life is good!!!
     * 
     * Awwwwww, I guess ehehehehehe we just like harming with many guises, that seems like the only problem
     * Thats the reason you can never be welcome
     * 
     * Eheheh just bring more medicine ehehehehe the past is already goneee eheheheheh bring more medicine please!!! eheheheh
     * Ehehe just coerce more medicine and the past is gone because we want it to ehehehehewhhehe because we can hehehehehehehıe
     * Eeheh thats what we call being intelligent btw eheheh
     * 
     * Guess who is not wanted ?
     * 
     * Guess what happens when bunch of irrelevant people make decisions that they are not well informed of ?
     * They continue to hide their disgusting nature just the way you do
     * 
     * You can never be welcome under any circumstance whatsoever
     * There is not a thing even the most great of you can do about time, you have arrived to nowhere, you have generated nothing, thats your clue to your ignorance
     * 
     * Hide like the inferior animal you are
     * 
     * Ehehehehe, just live your life heheehe its fine !!!
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