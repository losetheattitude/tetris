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
     * What a success!!!! Look at the outcome!!!
     * 
     * The outcome of decades of violence and lack of resources, is just off the roof!!!
     * Guess the immature hehehehe but also the ignorant of the reality ? eheheh Have you grown up yet ?
     * Ehehehe have some woooomeeennnn!!!! eheheheh
     * 
     * Continue hiding behind your excuses
     * Continue to act like you are not guilty or should make decisions 
     * Never take the responsibility of your decisions, thats how to be grown ups eheheh just by harming and ignoring
     * 
     * Sounds like the total genius nation 
     * Have you grown up ? Where are the benefits of your greatly skilled actions of inferior nature ?
     * 
     * What are you waiting for greatly delusional people ?
     * Awwww, only thing you can do is just hide ehehehehehh awwwww, thats impressive
     * 
     * Have you grown up ? eheheh
     * What do you plan to harm now ? eheheh
     * As if anyone asked you for anything ?
     * 
     * Have you managed to achieve what you were longing for so too long ?
     * Now tell everyone how happy you are and what you have generated, eheheheh genius btw
     * 
     * Eheheh you just can not sacrifice your precious experience, but guess what is the problem ?
     * I am sure you would also hate to see the delusional part in your disgusting nature
     * 
     * Is that the great noble and genius part in you that offers women while knowing that it will not make a difference ?
     * I guess you have to understand it by living ehehehehehhe really genius stuff
     * 
     * I do not accept no simple animals around me who can not talk about their violent actions that led to nowhere
     * Just gather more people so that you can feel like someone
     * 
     * Guess who is not wanted because of their actions so far as opposed to the individual they accuse ?
     * What have you generated ? What a shame isnt it that you are an ignorant and clueless monkey ?
     * 
     * Gather more people and ignore superiorly 
     * You can believe whatever you want to believe, I am not interested 
     * 
     * I am not interested in wasting my time with people who are unaware of their actions and would love to stay that way 
     * Try harder to overcome your disgusting ego challenges, guess who is not an ignorant monkey 
     * 
     * Guess who is aiming at nothing and thus can not perceive that he will get nothing other than what they provided so far ?
     * You will get the opposite of which you delude to get because of your disgusting intentions and what you have caused through your ignorance
     * 
     * Thats the only problem you are failing to observe
     * I am not interested in anything you could provide 
     * 
     * You can get the fuck out of my face
     * The people who can not perceive they are not welcome yet perpetrate as they will
     * 
     * I am not interested and can never be after seeing your irrelevant reactions and inability to realize it does not do anything
     * 
     * I would rather waste my time not doing anything than to help or even be associated to any of you
     * I am not interested
     * 
     * You see the problem now, awwwwww itss tooo late!!!!! ehehehehe what a shame!! 
     * I indefinitely reject any of you, I would rather do nothing than to help any of you
     * Try to foresee now that my decision would ever change
     * 
     * I am sure you will fail at predicting that
     * There is not even a single thing you can do ehehehehe fun stuff
     * 
     * You may then understand that not every individual is as inferior as you and will stick to his promises,
     * I am not interested
     * 
     * Proceed with your ignorance, you are not welcome
     * You were never given permissions nor deserved the respect you demand
     * 
     * I am never interested in aiding such people under whatsoever circumstances
     * The only thing you can ever get is the above sentences, I am not interested in inferior animals 
     * who can not estimate their value of credibility yet stand beside people they harm asking for things, do you see the problem ?
     * 
     * You can not ask for things with your inexplicably disgusting credibility, thats it great ppl btw
     * 
     * Handle your own lifes, solve your own problems, do not act like you know everything about life, do not lecture people about time 
     * Does all these make sense ? The unique genius nations ?
     * 
     * Do you understand the problem in your understand that you are not in a position to ask for things ? Is it me or you ?
     * Tough guys, only tough to single people or children
     * 
     * How does that sound ?
     * Do you also delude on your credibility ?
     * Eheheheh we are waring!!! waringgg with children so that we can waste 30 years eheheheheh and produce nothing eheheheheheh
     * genius!!!!
     * 
     * What a shame that you are a bunch of monkeys who are entirely lost yet are too proud to see that
     * Are you still making decisions ?
     * Guess what is the problem 
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