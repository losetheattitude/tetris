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
     * Awwww, thats the reality you have formed now you would rather present great genius violence to avoid that ? Guess what do I want ?
     * 
     * Guess the 500 prior disgusting average animal of your kind, dont you alike ?
     * Just the proof I have indicated  
     * Still think you are making decisions ? ehehhehe you should make decisions genius nation 
     * Disgusting people are still hiding behind excuses of 100 years ? The war time decisions ? 
     * Do you think I want any part of that ?
     * Do you think I want any part of disgusting people that I know what they are ?
     * Do you want to know what things could have been achieved when you were not there to harm people starting from when they are 5 months ?
     * 
     * I am sure you also would love to avoid your "past promises" as you have proven countless times what a disgusting animal you are
     * You still think you should make decisions for adults ?
     * The disgusting average animals WHO I WILL UNDER NO CIRCUMSTANCE EVER ASSOCIATE MYSELF WITH
     * You still delude on my being around people who coerce medicine ? rape children ? 
     * You are going to say "FORGET ABOUT THE PAST!!!!!", guess who is what again 
     * Talk more on the authority that has "given you by the GODS" and the way you misuse them
     * 
     * Fucking disgusting monkeys who think they live forever
     * Now what do you feel like you have gained ? The geniuses ?
     * The never learning disgusting monkeys who enjoy their cheap emotions, thats the only group I will ever want to be around, so simple and elegant
     * Think for a second so simple an individual as such he would instantly say "YESSSSS" to changing locations or womeeen!! over violence
     * 
     * You lack "impressive" amount of credibility and I avoid them like a disease
     * 
     * Its too funny ? You have got 30 years of evidence and you still do what ?
     * You still ask things from someone you have harmed ?
     * 
     * Tell all your bullshit to my face, who knows everything you have perpetrated so far ?
     * Genius nation ? Who offers women for 30 years of unjust violence ?
     * Like the disgusting animal that everyone has been referring to so far ?
     * 
     * The genius nation who still insists on his disgusting violent behavior towards then 5 months old babies now "adults" ?
     * and guess what they offer ? Ehehehe commit violence please!!!! get womeenn genius nation we are!!!
     * The disgusting homo sapiens ? Where is your great violent attitude ?
     * 
     * Are you going to start begging when you know you are guilty as you have done before ?
     * Or you, the genius nation, will start offering things as you have done before ?
     * Now tell me my experience ? The great people ? The great competent people of genius nation who are as credible as the disgusting animal on the street ?
     * 
     * Are you still offering women with your disgusting sapiens brain ? eheheh fo!! fo!!! fo!!!
     * and you do not call it begging ? It does not suit on you because you also delude on your competency ?
     * 
     * Do you want to talk more about my experience and the past ? or you would rather beg like the little animal you are ? aawwww you say genius indeed
     * AWww wait wait, do you want to talk more about the honorable promises ?
     * Or would you want to talk more about violence ? 
     * 
     * IQ, IQ!!! yet look at your behavior
     * Ehehe promise yet look at you!!!!
     * Violence!!! IQ!!!! genius nation!!! LOOK AT YOU
     * 
     * Genius nation must be proud of their disgusting animality ehehhehe
     * Get women please!! just like the animals who have been described in the books, GET WOMENNNNNN yet ehehhe fun stuff
     * 
     * You still believe you should make decisions on behalf of others BECAUSE YOU ARE GIVEN SOME SORT OF GOD POWERS ?
     * Do you also want to remember the past ? In which you have performed really really genius things against 5 months babies and later on adults ?
     * Like the disgusting homo sapiens ? Fear more on your disgusting incompetency, tomorrow it will be someone else but today its you who is going to cause everyone
     * pain
     * 
     * Like the disgusting homo sapiens who still coerce medicine ? coerce disgusting things ? You call it fo ?
     * Now I am sure you also take notes on your "successful outcomes" by doing great violence
     * Are you still digging yourselves a good grave ? Ehehehe everyone should bow!!!!!!
     * 
     * Awww, you would rather offer women and hope that it solves the violence problem, the problem of life that you have zero understanding
     * eheheh call it a game, life a game!!! life a simulation!!! 
     * You never learn ? You as the disgusting homo sapiens ?
     * You still offer women and just wish that it should work ?
     * 
     * Dont you think you are the one missing information ? Awww you havent learnt anything ?
     * You account for your own actions and we are done, There is not a single thing I could ever want from the disgusting animals like you
     * who have done so much good that I can not even picture what a disgusting animal you must be
     * 
     * You still think you are fighting ? Fighting with who ?
     * How about you explain things first ?
     * 
     * Have you forgotten or havent you ever experienced death before ?
     * Awwwwww, you think everyone should bow ehehehehhe, please beg mores
     * 
     * Get yourselves more children thats who you are, what you deserve, what you can achieve
     * gather more people
     * 
     * Whose iq do you think is lacking ? You are the one who can not answer for any of your behavior ? I am the one who is asking the questions ?
     * 
     * Do you still think you are sane enough to make decisions ? or you just are getting yourselves into unnecessary problems ?
     * Are you still begging people that they should say something or another ?
     * 
     * I will not even consider even for a second to involve myself amongst the disgusting inferior animals like yourselves, the genius nation 
     * The genius nation who begs to children, who harms pointlessly and offers materials like the little disgusting animal they are 
     * 
     * The disgusting animal who begs for materials and offers the same when they know they are disgustingly related
     * The same disgusting animal who thinks they should make the decisions THAT ARE NOT THEIR CONCERN, the genius nation
     * 
     * The genius nation who brags when they harm children
     * The genius nation who harms children through doctors
     * 
     * You are still talking about IQ while hiding behind every possible little thing ?
     * 
     * Gather more people to display your great skills, indeed its most perplexing, you all are the most intelligent group I have ever interacted !!! yes!!!
     * Ehehe we do not care!!! we threat and gather and harm!!!!! thats who we are!!
     * 
     * What are you waiting for ? Are you sure you know how to use things ?
     * and you still demand credibility ?
     * 
     * You have got 100000000 questions you can not answer thats your problem, and thats why you avoid including me into your disgusting conversations
     * because you will get destroyed, you did something you should not have and you are still begging through offers as you have done countless times
     * 
     * You still bring up fate ? I am telling you that I will not even step inside the same room with any of you, you still offer women ? 
     * 
     * DO YOU EVEN KNOW HOW TO LISTEN AND LEARN AND CHANGE ?
     * Do you even understand what you are doing or you would love to avoid and harm anything that could be a threat to you ?
     * Do you even follow ? Ehehehe he does this everytime!!! eheheh because he really loves to do it!!
     * Like a 5 months old love to do many things you did to him ?
     * 
     * Eheheh he loves to explain the situation you are perpetrating 
     * Are you still deluding that I should want to be around the inferior animals who do not understand anything ?
     * Just like you have not done it in the past, you are still the disgusting animal who would only love to harm and hopefully nobody says anything ?
     * While you are harming physically ?
     * 
     * I do not want to see any disgusting animal around you
     * The animals who do not listen therefore failing to perceive the problem, I do not have the slighest intention to waste my time around you
     * 
     * Do you still request credibility ? Do you still compare violence with "WOOOMEENNNNNNN" ? The genius people ?
     * Ehehehe find more children, you are only good at that
     * 
     * Find some time for physics as well, read your stupid history
     * 
     * Still trying to look around for more bullshit ? Start from the very beginning you will see, you are just an average animal who takes himself for something
     * they are not
     * 
     * Are you still offering women ? Start from the very beginning of your disgusting behaviors
     * That is not called past, that is called who you are
     * 
     * I do not care even if you think you own the world, I have no intention to waste my time with disgusting animals such as yourselves
     * 
     * Accountability is somehow made to be forgotten by you ? The understanding of "responsibility" ? The decision making of one's own ?
     * The oppression you dare to say ? To what you can not even talk openly ?
     * Thats the type I do not want to nor consider to waste my time with, continue blaming and ignoring
     * 
     * Who got the education now ? Who lacks the education ? 
     * 
     * Do you still receive the same answers while you can not answer the very simple questions ?
     * Who got the education now ? Do you believe I am as low as you that I will start bending because you can present some stupid violence ?
     * Are you still deluding on things ? ahhh I am not surprised 
     * 
     * I am not surprised because I also know the years prior disgusting behavior of yours, the genius people indeed
     * Are you still after the same narrative ? Violence solves everything ? What did it solve so far ? Who got the education ?
     * Still looking around for proof ? When you are the one who is causing all the harm and seek for the responsible ?
     * 
     * Are you still on the same narrative ? Eheheh he is not aware ?
     * Are you still chasing the same stupid inefficient thinking pattern ?
     * 
     * IT DOES NOT WORK and I do not want to waste my time with irresponsible people, make no mistake, you are the one who is irresponsible
     * Look what you have done with what is NOT GIVEN TO YOU, indeed the most genius nation
     * 
     * Need more excuses for doing something you would love to ?
     * You do not realize you havent done anything other than just saying a few things, what a pattern
     * Still looking for excuses when you have years of proof ? eheheh like the real genius you are
     * 
     * Still daring to hide your disgusting animality ?
     * Have a look at what you are, ehehe you would rather "enjoy" your disgusting inferiority by excuses as you have done so in the "past"
     * 
     * Need more disgusting excuses that only your minds can produce and believe at the same time ?
     * Dont you still understand that you are chasing money because you are doing what you want ? Do you think I care slighest about the money ?
     * You disgusting animals ? Will you start accounting for your disgusting behavior ? or start learning how to listen to people ?
     * 
     * Awwww, you are so deep in your disgusting animality you say ? Awwww you say its too funny ?
     * Awwww, its too late!! we are too deep being the disgusting animals we claim others to be!!!! please!! get money!!! ehehe
     * we do not understand shit about life!! get money!!!! get women!! GENIUS PEOPLE!!
     * 
     * The level of genius that I would not even consider one piece of material from them, you are at that disgusting level
     * Do you understand killing innocent children is bad ? The genius nation ?
     * How about 30 years of evidence ? eheheheh please please!!!!
     * 
     * Do the genius nation understand innocent unrelated children can not be made to serve your disgusting purpose ?
     * A few months of feeling that you won ? The genius nation ? ehehehhe your geniuses must be really proud of you
     * 
     * Eheheheh, first learn some physics then delude on your competency at decision making
     * you are disgusting inferior animals that I would not consider wasting my time, you do what you have to do
     * 
     * Do it from out of my vicinity, pay close attention to begging to children that you harm unfairly
     * You are indeed one of the rare genius ehehehehe, such a decision nobody can ever argue
     * 
     * What do you think you are waiting for ? What am I waiting for ?
     * I have already told you that even if you were the god himself, I would not consider any of you around me who has been here for too long
     * and have inflicted only pain
     * 
     * Do not even think about engaging in any shape or form, I am simply not interested in your stupid behavior
     * Talk more on violence instead of hiding like the disgusting animal you are that I will not consider wasting my time neither helping nor lying for
     * 
     * Talk more on "racing" with children
     * Do you even know how to listen and watch ? Watch the evidence of 30 years ? Listen to the person who is telling the truth all the time ?
     * 
     * Awww you can not do that!!! because you are so deep in your own disgusting shit that you would all have to disappear from earth ehehehhhe
     * You are too deep in your own behavior starting from years ago and keeping your disgusting animality consistent, YOU HAVE ARRIVED TO NOWHERE
     * 
     * But anyways, lets be the consistent disgusting animal we are so far, that get us to nowhere!!!
     * Ehehehehe MORE VIOLENCE!!!!!!! please we developed eheheh life simulation life not fair!!!
     * 
     * Do you even know the corresponding actions when you commit such a thing ? What makes you think you are entitled to do that ? ehehhe "get women ?"
     * 
     * Who told you I accept women over violence ? Keep in your disgusting mind
     * Awwww I know now, you just need to torture kids, you need more kids ehehhehe you just like begging and torturing kids then "leave here!!" 
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