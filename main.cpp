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
     * not the homo sapiens who can not predict what their   would entail, the sapiens who delude on what they have caused is "GOOD", whats my experience like ? eheheh
     * Thats most useful for everyone, the same sapiens who take everyone for themselves
     * the sapiens who appear and act entirely childish ehhehehe, pls pls pls 
     * the very same sapiens who their superior would not even consider wasting one second with them, take a look at the history assess your stupidity
     * simplicity is definitely the way to go ehehhe, chase more simple emotions ehehhehe violence we like harm eheheh pls pls lie forget ehheh
     * eheheheh look how clever we are !!! ehehhehe we think nobody gets it heheheheheh pls pls hhehe
     * 
     * This is as far as it could even go in engagement wise, you are just insignificant people to me
     * eheheh women btw
     * 
     * the dare eheheh, we good, we friend, we doing good, eheheheh
     * the disgusting dare though
     * the disgusting delusion of "WOMEN" should solve, guess what, thats the problem
     * first you talk about coercions then you talk more about your delusions
     * thats most skillful indeed! its infinite chopping time for me, regardless of your dear intentions
     * guess what you would do when someone does not want to play your stupid games ? eheheheheh 
     * most fearful indeed! disgusting beggers
     * you communicate human language or ITS A PARTY!!! ehehehehhe pls pls pls, thats the sapiens part of yours
     * eheheh take life for game more, dumb animals, threats btw
     * wasting something we do not even know!!!!!! sapiens not INDEED!!
     * Its just for the sake of "ehehehehe", violence good, threats nice!! we like harm!!
     * regrets ehehehehehhe
     * 
     * The most simple thing yet we still wait and expect some other to do "WHAT" ?
     * women and cars ehehehe time an illusion !!!! no emotions, "WE DO NOT EMOTION!!!"
     * life so simple!!!! eheheh we not emotional we see everything!!!
     * 
     * You delude on others stupidity and DO NOT SURPRISE AT THE OUTCOME EVENTUALLY ONE WAY OR OTHER, you will wish it was a joke
     * Talk more about time think more on violence and try to foresee what would one do under your stupid disgusting directionless behavior, I do not even care
     * about your lives or your believes or your opinions, until you are in the same position. There can be no remedy
     * 
     * You understand whatever you have done so far HAVE ACHIEVED NOTHING BUT ANIMOSITY, so really really congrats
     * still threat, "YOU ATE IT!! YOU ATE IT!!!" Collect more untruthful "evidences" and hope that you do not get hurt while doing your stupidity to people
     * who you do not understand,
     * 
     * Were you the good people ? Were you the sane group who had what it takes to "DECIDE" ? Look at your stupid decisions and their outcomes and what they have produced
     * Were you what ?  Eheheheh we take it baack!!! ehehhe pls pls 
     * eheheheh medicine btw, eheheh medicine pls !! eehhhehe good ppl
     * I want no disgusting animals around me
     * 
     * 
     * I HAVE NO INTENTION TO WASTE MY TIME WITH WHATEVER YOU COULD POSSIBlY FORM ? Do you even follow great religion and great nation and great people ?
     * May be you can actually notice what a stupid animal you are this way, still offering women and smiling expecting no problems at all ?
     * The very simple people who anyone would love to repel as the lack of understanding is on the nonexistent level
     
     * You still do not understand the part where what you would not consider baring IS GOING TO HAPPEN ? Awww, that would be too bad for you all ? Why anyone should care ?
     * eheheh you are the one who is offering materials still ? see the problem ? See the problem in your understanding that IT DOES NOT HAVE ANY EFFECT ON ME ? Why ?
     * DO YOU SEE THE PROBLEM BRO ? eheh anyways still wasting should be reasonable and efficient, thats the uncontrollable and unaccountable people who provides
     * all sorts of untruthful excuses for their disgusting behavior 
     * OBLIVIOUS STUBBORN ANIMALS WHO CAN NOT GET THAT THEY WONT ARRIVE TO ANYWHERE WITH THAT "BEHAVIOUR", only stupid outcomes as you have right now
     * The sapiens who take animations for what they do not mean, you see what you have achieved ? NOTHING, but you are still the one offering materials
     * Thats success indeed, begging success, begging to children eheheh religious most indeed
     * Arent you disgusted and afraid ? Aww thats why you take violence for precaution ? eheheh fun stuff religious people
     * 
     * So you fucking provide excuses for what a 5yo kid done and choose not to trust ? WHO IS THE KID ?
     * You do not trust but request trust ? ehehhehe ? we just want to keep everything communicated thats why you can not live on your own eheh,
     * we like harming etc ? as you have done so ?
     * 
     * You got no better idea then root fear to who they have failed ?
     * Bro you keep saying return go do this that, you have no idea how the world works ? no money no resources no tools no cars no relation no trust ?
     * You advise being conservative over hobbies and do talk about trust ?
     * 
     * to engage with life you need the basic resources, if your job is to convince to bullshit that nobody buys, we all can not get along at all
     * Is this the way to fool fucking dumb monkeys ? RESOURCE TO FUCKING GO OUT eheheh
     * I understand but why not just let them do it as a simple transaction and get it done with, I do not like soliciting anything from anyone
     * 
     * excuses excusessssssss all I have heard, what do you think that tells you ?
     * Have a look at 30 years of evidence you can attain THROUGH EVERYWHERE, its called fucking footage
     * You already know I remember all the bullshit you already just have told and I also remember the great fucking life I have had, thanks to all the people around me so far ?
     * 
     * Do you even understand what I am saying ? The fucking computer I have used was 10 years old ? Do you even begin to understand or is this a specific kink ?
     * we like seeing people fail ? or do not like what they are doing ? are you the ones who were cooking bad food ?  Thats not how to be foe if you were the one
     * 
     * Bro the problem you have given is, "I NEED TO MAKE MYSELF BELIEVE THAT I CAN NOT DO CERTAIN THINGS WhILE KNOWING THAT I FUCKING DESTROY EVERYONE ON EVERYTHING
     * BUT I SHOULD NOT HAVE A PROPER COMPUTER" ? You do not see the inaccuracy in your thinkings ?
     * 
     * Stop with your delusions you will see nobody will receive anything other than benefit, I already told you you have 30 years of proof but somehow
     * you just can not deal with your egos ?
     * 
     * I am telling you this is how you fabricate problems, nobody WANTS THAT, just as an opinion
     * 
     * I kindly request from you all to see what you have failed fucking many decades ago and waste so much time that you can not even acknowledge anymore
     * because that puts you into such a position that Its entirely unreasonable inexplicable 
     * 
     * so far they have behaved like the very childs they are and came 1230213921 people against one with "drugged" ehehehhehehehehehheehheheheehehh
     * fucking dumb monkeys, I could not care less 
     * 
     * Just reverse all that bullshit back then and they have also fucking promised to lose a limb!!!
     * Thats what I have promised I remember it 
     * 
     * I see it as transaction because it was introduced like one to me but guess what I have received so far ? bullshit ?
     * so why not gather people and ask them what they have done and what they have promised etc etc
     * 
     * You know they have forced everything and more than once I have not eaten what they have offered and guess what ? they have eheheh violently forced ?
     * so is it also a kink to watch someone alone go against dumb monkeys ? how about some tools ?
     * 
     * Eating things in hospital, so that I could "save" myself from ? What you all doing ?
     * Eheheh, you had all the chances and you think this is winning ?
     * 
     * You see I DO NOT CARE WHAT THEY THINK, some violence as offers because they are afraid as the little animal they are ?eheheh 
     * 
     * Btw, we have forcefully brought someone into a house and try to save our asses ? through what ? "THEY DO NOT WANT YOU TO DO THAT!!!!"
     * 
     * Could not care less, bring more medicines ehehehhe pls pl sp slps lspl
     * 
     * No I am pissed thats why, I am not letting my brain think when I want to think over other things
     * 
     * Yeah thats what you call skillful ? Continue with your life until you get some random harm and eheheheheh what ? 
     * Do not make offers bro, I have heard how many ? Do you want to know ? And what is the realityy ? 
     * 
     * There is no way before people explain what they have done so far while they were begging to a 5 yo kid to lie for their religion
     * 
     * The most great religion and nation of all the world, ? lets see what they have to say
     * 
     * You know you have allowed it then provide as "reason" ? you do not trust ME ?
     * 
     * Bro I remember everything about what you have said, and you still chase through religion ?
     * 
     * You know that I know you are talking with someone who has no options, it does not how it works
     * Can you just tell me the very simple reason of not having a proper computer then you can request trust and do not lend trust despite all the
     * cheap violence so far 
     * 
     * 
     * Can you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computerCan you just tell me the very simple reason of not having a proper computer
     * Can you just tell me the very simple reason of not having a proper computer
     * Can you just tell me the very simple reason of not having a proper computer
     * 
     * Do you see the flaw in your conduct ?
     * You pay thousands for hoes ? And I have used 10 years the same computer ?
     * How come does that make sense if I break everything ? 10 years of usage ? and nothing significant can be done with the fucking compputer ?
     * 
     * I DO NOT LIKE BEGGING, IN ANY SHAPE OR FORM WHETHER THAT BE LYING OR ADVICING,
     * 
     * Its not so difficult to do all those things you see ?
     * Its just a simple motion, you go buy it or get money and buy it, its fucking a few thousands and you provide for excuse what you have brought around me ?
     * 
     * THE PAPER IS ALL YOU NEED ? WHAT DO YOU THINK COULD HAPPEN ?
     * LIKE ?
     * A CHUNK THAT PREVENTS YOU FROM GETTING A PROPER PC ?
     * YOU DO BAD THINGS WITH PC ? WHAT ? YOU JUST SAID YOU BROKE ? What was the problem ?
     * 
     * Why dont you grow up guys ?
     * Do you even want to have a relation ? no such a thing on earth can repair what you have caused intentionally so far 
     * How quick do you think I will forget, Your medicines DO NOT AFFECT ME THE WAY YOU WANT THEM
     * 
     * You know this is probably the 10. time you just say you would do things ? may be it was them etc etc, but I know the life I had, its just great bro
     * 
     * Do you even understand the position I am in ? Or is it just what you want ?
     * 
     * Last time I havent even touched my nose in the hospital they have again gathered with the utmost skillful behavior and guess what ? forcefully "made me taste" ?
     * Do you not see the problem yet ?
     * 
     * So it has taken 30 years and unaccountable many actions that you or they will surely regret ?
     * TO DETERMINE WHAT WHILE YOU HAD 30 YEARS OF EVIDENCE ? Do you all like beating children and surprising at the equal outcome ?
     * While also forcing that children stay in the same room and attack each other ? Is that the great reason and noble aim etc ? how about 30 years of evidence ?
     * 
     * 30 years and you still delude and fail and fail over and over again ? Do you call it success ? Thats the point I am making ? IT IS DEFINITELY THE FAILURE OF
     * WHOEVER IS PERPETRUATING Because it has achieved literally nothing but hey ? You all just great or what ?
     * 
     * They have been told at least 100000000000000000 times and what do you think I should want now ?
     * Wouldnt you also consider the very same harm, like loosing a limb or some shit as THEY HAVE HONORABLY AND RELIGIOUSLY PROMISED TO DO SO
     *  
     * Going literally no where!!!
     * Begging you do not say ?
     * Talk more on your actions not what would you do, talk more on what you deserve with your violent actions
     * Talk more on what you have "achieved"
     * and you still "promise" when there is 30 years of evidence of your disgusting nature ?
     * Do you still think you are family ? There is 30 years of evidence I say, what do you say ? eheheh no resources you say ?
     * Why now suddenly there are so much money!!!! ehehehehh get money!!! plsss!!!
     * 
     * You have 30 years of evidence each of which I REMEMBER, what are you asking now ?
     * Tell me now whats the equivalent of 30 years, AND TELL ME WHAT YOU HAVE ACHIEVED
     * 
     * There can be no even the most insignificant connection, so instead of begging like the little animals you are, live your own life
     * Talk more on VIOLENCE AND THE GREAT LIFE YOU HAVE BEGGED WITH PROMISES ? You do not remember because its your disgusting act ?
     * Because it tells on your disgusting nature ?
     * 
     * Please restart!!!! we good, the best parents ever we will be ehhehehe thats how we do our jobs as well, pplease!!!! eheheh
     * How about you start thinking about how to change "the past" ? or whats the problem in all your thinking ? Do you still delude I would have even the slighest
     * thing with any of you ?
     * 
     * There is not a single thing you can do to fix it
     * 
     * you know thats just fear ? You are fearful just like the little animal you are ?
     * Just like the disgusting animal who takes fooling children for skill ? Like the disgusting little animal who takes violence for skill ?
     * Violence with 1000000 people against one ?
     * 
     * And the only way is to "Offer" eheheh offer because we are disgusting, you say ?
     * 
     * With which disgusting dare YOU ARE STILL TALKING ? 
     * Say some good stuff!! say some good stuff!!!! and he will feel fine!! 
     * 
     * And you are still, "YOU ARE GOING TO THIS PLACE BECAUSE WE MADE YOU A THREAT ehehehhe through pointless harm and we can not let you go
     * because you are better than us ? hheehhe please pleasee, we like harm you say ?"
     * 
     * and you are still offering material with your inferiority ?
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