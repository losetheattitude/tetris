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
     * There is no possible reality in which I could ever waste another second with any of you, 
     * you have to really incentivize like you all always do, ehehehe VIOLENCE!!!! the life !!!!
     * 
     * Remind yourselves the past you avoid like the disgusting animals you are
     * The education that you have beggingly promised ? The really honorable promises that you begged ?
     * and you still here to be taken serious ? ehehheh memory reboot, forget the past heehehheh please eheheheh
     * get women!!!! get womeen!!! we still delude on what the other person is valuing ?
     * And you still want to be taken into consideration ? You still have not waken up ? I DO NOT CARE
     * I DO NOT WANT TO SEE ANY DISGUSTING ANIMALS WHO TAKE THEMSELVES TO BE SOMETHING THEY ARE NOT
     * 
     * Thats all
     * Life you take so easy, hopefully one day you also realize what a mistake "THAT WAS" eheheheh
     * 
     * Hopefully you one day realize that every one borns like you do and does not know any prior information
     * thats how you get yourself into trouble by being the disgusting animal that you are and were 
     * Beg more eheheh, he craves womennn!!!! he craves women!!!! offer women!!!!! heheheheheheh
     * we seek no trouble!!! eheheheheh please!!!
     * 
     * You still mistake the person before you and offer still women for physical disgust ?
     * Do what you have to do, I WILL NOT EVEN MOVE MY FINGER FOR AN INCH
     * eheheheh fun life and fate life eheheh and ehehehhe good ppl, be sure thats the only thing I want to be around
     * 
     * eheheh bring more people please!!! this woman or that one should definitely solve A PROBLEM THAT ALREADY DOES NOT EXIST
     * A PROBLEM FABRICATED BY COERCION OF 5 MONTHS BABIES, you still think I do not remember the promises ?
     * 
     * Good nation you say ? I say I even remember the most insignificant detail ?
     * Do you want to talk more about your competencies ? or offer some woman who you also delude to be a solution ?
     * You see the problem now ?
     * 
     * Do you want to remember the past ? I EVEN REMEMBER THE MOST INSIGNIFICANT PART I SAY, WHAT DO YOU SAY ?
     * YOU STILL DELUDE ON YOUR NATION ? YOUR PROFICIENCY ? YOUR USEFULNESS ? YOUR REASON ?
     * Still offering some random women ? The delusion you do not say ?
     * 
     * You do not understand the reason you disgust people into depression ?
     * Still offering women for your disgusting existence around me ?
     * 
     * Do you need more proof ? Have a look at the footage that is available for years 
     * You see the reason why you put people into depression or harm physically and emotionally ? You still delude on offering women ?
     * Do you even use your brain when interacting with me ? You say what ? You say crazy ? I say desperate disgusting monkeys ?
     * Like the average animal ?
     * 
     * Is your really really genius idea is to offer women ? Hoping that it would entirely solve a fabricated problem from the beginning ?
     * Disgusting you are not you say ? You see the thief in the room ?
     * You have got enough proof but you just want to avoid and harm, hoping that you get a war ?
     * Do you want to talk about your credibility and the prior promises of "GOOD EDUCATION" ? and still want to be taken serious ?
     * 
     * You now offer what exactly ? awwww you are the most credible and honorable people of all time that I would not even waste another second considering ?
     * Is that why you also delude on women or your competency or your humanity ? 
     * Do you even know what that means ? Luckily I remember so you do not have to delude on your humanity as well
     * 
     * Why do you still waste time on not acting your greatness ? The great nation ?
     * What are you exactly waiting for ? Eheheh the good education we provide!!! please choose us! we good family!!!
     * 
     * still deluding on harming should change things for the good ?
     * eheheh ? harming increases IQ!!!!! DUMBEST PEOPLE OF ALL THE TIME
     * Hence the disgusting animal I WOULD NOT EVEN CONSIDER WASTING ONE SECOND
     * 
     * Do what you have to do, make yourselves more drama, thats why your life is boring and you make others' worse
     * Thats the reason I WOULD NOT EVEN CONSIDER YOU FOR A SECOND
     * 
     * Ehehehe ? Still laughing or deluding on women ?
     * Is that why you are so simple that I am disgusted with your minds ?
     * Awww havent you dig yourselves a disgusting situation ? eheheh some violence would solve it ? WHY ISNT IT SOLVING IT ?
     * May be you are the problem right ?
     * 
     * Awwwww, the reason you are the disgusting animal you are is because you already noticed the disgusting situation
     * you wantingly dig yourselves ?
     * 
     * Do you even have anything to say other than "IT DID NOT HAPPEN" ?
     * Do you even understand that YOU CAN NOT COERCE ME ? You can only negotiate with grace ? You still offer women ?
     * 
     * The most basic right to harm someone because you do not understand or you are afraid ?
     * Are you the ones who see the bigger picture now ? Are you sure ?
     * 
     * How low are you going to dig ? You still deluding because you are a disgusting animal and everything you have done so far proves it ?
     * Against my trying to stay alive ?
     * 
     * Find more children and force them to eat their own shit ? why not honorable and great genius nation ?
     * Do you want to talk more about the past ? The genius nation ? 
     * 
     * I do not even a second to waste with the simple animals who do not understand anything, THATS YOU IN THIS STORY
     * Stupid animals who think violence against anyone should increase their ability and hide behind the most disgusting ideas JUST LIKE THE ANIMAL THEY ARE
     * The genius animals indeed
     * 
     * What do you think is going to happen ? Awwwwwww, you already know you have dug yourselves a pit ? eheheh please please!!!
     * Pay for your own actions and most surprisingly you say, "WOMENNNNN!!!!", thats the understanding I have always avoided
     * You lose things you can not afford to, and we are all good, or just live your life!!!! ehehheheh
     * With the little understanding you have built, that could be the only thing I want around 
     * 
     * 
     * TRY TO THINK FOR WAYS TO CONVINCE THE VERY INDIVIDUAL YOU HAVE HARMED CONTINUOUSLY THROUGH LIES AND ACTIONS, Guess who remembers ?
     * Guess who takes himself for a tough guy by harming defenseless kids then adults ?
     * You think you are right because you bring out "WAR TIME" decisions ? and you call yourself what ?
     * 
     * TALK MORE ON YEARS THAT HAVE PASSED, awwww you would rather employ your immaculate minds and say "womeennnnn!!!!!!"
     * Do you even follow ?
     * 
     * Guess what I could want considering you the average disgusting animals wanted and have perpetrated ?
     * Use your brain ? eheheh no no!! we the genius nation want more harm to people!!! please!!!!
     * You offer what ? ehehehheh woomeeeeennnnn!!!!!!!!!!!!
     * eheheheh get money!!!!!! get money when you are 50 ehehehehehhe please!!!!!!!! genius nation!!!!!!
     * 
     * Hey you all look reallly reallly clever when you sit behind a screen and try to interpret someone else workflow eheheh
     * Just not the disgusted average animal behavior, no need for proofs
     * 
     * Do you even understand what could have been accomplished within such a long time frame ? and have a look at your genius nation, I guess you are not one
     * Are you still behind your disgusting allegations that you have perpetrated against 5 months babies and still standing before me ? The disgusting animals ?
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