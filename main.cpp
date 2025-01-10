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
     * 
     * I am not interested in disgusting animals who think depriving resources would help everyone
     * What did you do now ? Do you now see the ignorance part ?
     * Do you see the beneficial part now ? eheheh?
     * Which part is the beneficial part now help everyone see ?
     * 
     * Where is the greater good part the genius nation can point out ?
     * Or the genius nation can only coerce things ? eheheh what a genius nation
     * 
     * What makes you think anyone would "understand" your position ?
     * What has changed now ? How about some more coercion of medicine ? It has done wonders so far right ? The genius nation ?
     * 
     * ehehehehe the genius nation who has done perfect with irrelevant people hehehehe what a group never learning monkeys right ?
     * Try harder, life a simulation eheheh time does not exist eheheh 
     * 
     * Still wasting time because you are incompetent but also can not handle your emotions ?
     * Ignoring yet you can not still come up with more excuses, the genius nation ? What a shame!!!
     * You should have been a begger, you would have made so much money ehehehehhe
     * Do you understand the meaning of cheap now ? eheheheh 
     * 
     * Do you see why you are inferior ? Do you need more children to beg ? How about gathering 123021 people ? 
     * Eheheh that sounds like the competency you brag eheheh
     * 
     * How about you handle your own incompetency problems then you handle your disgusting selfishness may be we can match ?
     * I am not interested in disgusting animals who take themselves to be something they are not, you can delude whatever long
     * 
     * Are you still deluding on your "handling" ? What have you achieved now ?
     * I am not interested in associating myself with disgusting natured people, especially those who ignore things that matter
     * 
     * Trying to avoid being upholded to their disgusting crimes through making offers, as their disgusting nature can only negotiate with materials
     * 
     * Are you still making offers after your disgusting ignorance at delivering them ? What a shame you are just like the disgusting average animals
     * Why are you still here begging ? Real tough guys ehehehehe also genius nation eheheh
     * 
     * Ehehe some more violence may be it changes what is not a problem eheheheh
     * What happened ? What changed now ? Just a couple of decades that you do not even care unless its your experience ?
     * 
     * Who told you you are allowed ? If it is beneficial, then we do it together, if its not ? Then why you insist ?
     * Thats the issue, What has changed now ?
     * You had one thing to do, Mind your own business ? What good has it done so far ?
     * 
     * WHAT HAS CHANGED ? What have you produced now ? Aside then decades of wasted time ?
     * What is the next genius move by the genius nation ? eheheheh
     * What have you produced by assaulting irrelevant people ? What happened now ?
     * 
     * Where have you arrived now ? After 30 years ? Are you still making offers ?
     * I have not allowed anything to come "especially" from you
     * You pay for your own actions
     * 
     * What have you done now ? eheheheh ? Why are you the one who is hiding behind entities that you do not understand ?
     * Now what have you achieved after decades ? Stupid monkeys ?
     * 
     * Are you still offering ? You can get the fuck out of my face with your disgusting inexplicable nature ? Does the genius nation follow ?
     * Proud nation btw, proud to make offers ehehehhe so genius
     * 
     * The proud and genius and credible and fair nation need more people to harm and frame ? May be then beg through "offers" ?
     * Then suddenly lack even the most basic resources as "computer" ? 
     * 
     * Awwwww, you are the most single genius nation and its society that I have never seen before
     * Do you now perceive who is the delusional and who is inferior ?
     * Eheheheh we built computers heheeheheh we think we did that ehehehe not true smart people heheheeh
     * Just enjoy your ignorance, do it from out of my vicinity, I am not interested
     * 
     * Not interested in people who are claiming all sorts of bullshit like
     * "proud, genius, credible, fair" whilst the reality is the opposite, guess who can not produce anything proper ?
     * Guess who is delusional ?
     * Guess who also believes lacking resources would help, who is delusional ?
     * 
     * Still accusing people you have no relation ? awwww, thats definitely genius
     * Ehehehe you still gather 12392131 people and harm others ? THAT IS GENIUS!!!
     * 
     * You must be really proud of yourselves hehehehehe, really fun stuff
     * You only live once, eheheh genius nation!! Lets waste only the someone else's time!!!!!! hehehe genius!!
     * 
     * Lets harm ONLY SOMEONE ELSE!
     * Awwwwwww, genius nation btw eheheheh
     * 
     * Now, what do you have to beg with ? hehehehe
     * How about you stop offering without realizing it ? and as if women is the only thing one can need ? eheheh ? genius nation you think ?
     * I do not accept no simple animals around me
     * 
     * Ehehehehe we tryna improve people eheheheh, do you know what is called miserable ?
     * Eheheheh life is not fair heehheheheehhe life simulation eheheheh genius nation eheheheheh handling children real good eheheh
     * 
     * Why dont you come back at your "mistake" and think it throug h ehehehehehe genius btw
     * Ehehe we like harming and making false offers ehehehe, very skillful stuff, the one that I have never seen!!!
     * Ehehehe it had to be done eheheheh, genius nation eheheh 
     * 
     * Guess who is entirely at wrong and not welcomed rightfully ?
     * What do you have now to say ? Just assault geniusly ehehehehhehehe really fun and competent stuff
     * 
     * Fucking drunk people ? What have you achieved now ? eheheh just doing our job ehehehe ?
     * You are still wasting time THAT DOES NOT BELONG TO YOU ?
     * Do you want to talk about the implications of wasting decades ?
     * Or would you rather ignore and act like nothing happened thus there would be no problems in the "individual"s life ?
     * 
     * What are the implications of decades of deprivation of resources that are key to "life" ? eheheh life a simulation eheheh
     * Still wasting time that does not belong to you ? eheheh
     * No resources is definitely helpful especially coming from the minds of such a highly regarded group
     * You can get the fuck out of my face
     * 
     * What changed smart and credible and delusional people ?
     * Why dont the great medicines work ? eheheheh something is definitely wrong 
     * 
     * Eheheheehhe some normal life things eheheh after 30 years ehehehehehehhe its good its fine because we did it  !!!
     * Its entirely okay, because we did it! Guess who is not interested in ignorant selfish people ?
     * 
     * Guess who is waiting for nothing ? Eheheheheheheheheheh its just life, we like enjoying ours!!
     * Guess who is a ignorant monkey who never learns
     * Guess who is trying their hardest to hide what they have perpetrated
     * Guess who is not going to listen to you as you have done so ?
     * Guess who is going to get what they have provided ?
     * Do you want to explain more on what has been "lost" within the time you had not allowed to decide on ?
     * Guess what have you ended up producing ?
     * Guess who is still the same assured ignorant animal
     * Guess what happens when the people like you is acting without thinking ?
     * Eheheh we like wasting only someone else's time because WE CAN!!!! eheheheh
     * 
     * How about you deal with your own problems so that you do not have to beg like the inferior animal you are ?
     * You are not welcome, the disgusting animals who believe deprivation of resources is helpful
     * The irrelevant monkeys who think they should make personal decisions for others
     * 
     * The oblivious monkeys who seem to not remember things they signed as "deal"
     * Guess who thinks themselves for what they are not ?
     *
     * The little oblivious disgusting inferior monkeys who are still unable to grasp the problem here
     * The disgusting little animals who coerce people into unfair and of their own nature bullshit games
     * Why dont you take your chances with impartial people ?
     * 
     * Why dont you handle your own problems rather than harming people ? Do the genius nation understand spoken language ?
     * Do the genius nation understand that they have not achieved a single thing yet ?
     * Other than supposedly what they are trying to prevent ?
     * 
     * The oblivious genius nation have achieved the single thing they are trying to prevent, guess who is what ?
     * Guess who is still begging like the inferior animals they are ?
     * Guess who is still trying to hide their mistake by making another ? Coercion of the genius nation!!!!!!
     * What a shame you are an oblivious disgusting group of monkeys who would love to enjoy their experiences
     * 
     * Guess who is still not achieving what they are trying to prevent ?
     * The singularly most funny thing you could ever do in your life, waste decades through pointless violence and deprivation, thats the life!!
     * Guess who thinks they should be irresponsible as they can ever be, its fine to just harm and etc, its good time, just say some nice stuff
     * Guess who is begging through acting like its funny or fine what they have perpetrated still
     * 
     * Lacking resources is the sole way, guess who is entirely wrong, handle your own problems
     * Guess who can not justify his position regardless, and rightfully not welcome
     * Guess who chose the most easy and disgusting way ?
     * Guess who can not change the past
     * Guess who won by doing nothing 
     * Guess who won by directionless violence and lack of resources thus no "experiences", awwww look at you
     * Disgusting little oblivious animal
     * 
     * Ever wonder what ignorance looks like, eheheh
     * guess who is crossing boundaries when they delude to be entitled to make the most personal choice
     * Guess who does not recognize any boundaries
     * Save your disgusting assumptions to yourselves
     * 
     * How about some more medicine to fix your disgusting nature ?
     * Still deluding on every single possible quality you possess ?
     * Save your assumptions to yourselves, do you understand what is spoken language ? 
     * 
     * Eheheheheh we managed to unattainable eheheh wasting time that does not belong to us hehehe
     * Having fun killing people ? How about you stop begging with false offers of your disgusting nature ?
     * Wait wait, why dont the great and powerful people sacrifice ? eheheheh thats too difficult right ?
     * 
     * Lie for us ehehehe just waste your entire life for us ehehehheeh, get some violence ehehehe get some medicine eheheheh
     * No resources ehehehe because its helpful eheheehe, we dont sacrifice heehheeheh
     * 
     * You for sure look really great and genius when you beg people to lie for you
     * Why dont you get some womennnnn eheheheheheh and sacrifice your life ehehehehhehe, we good and great people hehehehehes
     * 
     * Guess who is not interested wasting time trying to prove things to people who are not relevant neither lawful
     * The time that does belong to one person, anyways just some violence and lack of resources will do
     * Guess who is what in this context and guess who is not interested in simple disgusting animals
     * 
     * Guess who is coercing medicine and surprising at the outcome of once working biological mass ?
     * Guess who is harming for the sake of harming, ehehhe the time does not belong to you
     * Guess who is making decisions that are not their place
     * 
     * What changed now after your immaculate decisions of irrelevant nature ? 
     * Why are you still begging ? Why are you still the one who is taking others to be just like yourselves ?
     * 
     * Guess who is entirely wrong yet ignorant ?
     * Do you want to know who is coercing medicine ?
     * Do you know who is at wrong ?
     * 
     * Guess who is not alike to fearful disgusting animals and will not bend before violence ?
     * Who is the incompetent and rightfully ignorant ? Still ignoring evidence ?
     * Guess who is far from exercising their rights and thus will have its own consequences ?
     * Guess who is the fake tough guys who can not answer and account for their behavior ?
     * 
     * That is the reason you are the disgusting ignorant group who likes to act as if they are something else
     * Get that right genius nation, how dare you still allege ?
     * How dare you still hold your ground as if you are not disgusting ?
     * 
     * How dare you still talk ? The genius nation ?
     * I do not accept no delusional criminal people, that can never change
     * 
     * Handle your own stupid disgusting life
     * Guess who is still the same ignorant animal who can not understand what life is ?
     * 
     * HANDLE YOUR OWN LIFE AND GET THE FUCK OUT OF MY FACE INDEFINITELY, I do not want to see any of you
     * Act like you are doing the right thing, do it from out of my vicinity, I do not care
     * 
     * Ignore the most possibly the biggest disgusting mistake, its fine
     * just a few women, its okay 
     * 
     * Its entirely okay to waste time with bullshit, I see, you can get the fuck out of my face
     * Handle your own problems and do not be immature
     * 
     * Do you not see the problem you have formed intentionally ? What makes you think I will consider wasting yet another decade with stupid people like you ?
     * Guess who is a disgusting never learning animal who can not observe the "life" properly
     * 
     * Find the worst examples of the worst, so that you can feel okay, thats the definition of disgusting desperate people
     * Guess who is not interested in stupid people who likes to make up excuses for their own experiences ?
     * Guess who hates to interact with the kinds of people like you ?
     * 
     * Guess who is guilty and does know his guilt thus has to beg still
     * Guess who can not produce answers for his actions and who can
     * Guess who has to beg with offers they do not realize, and guess who does not even care the slighest, do you see the inferior ?
     * 
     * Disgusting monkeys that I will never consider
     * Guess who does not understand life thus makes failing assumptions about someone else's desires and happiness ? 
     * You can remove your disgusting nature from my vicinity indefinitely
     * Its regardless of any possible thing you can produce
     * 
     * You just pretend to do good its irrelevant
     * 
     * None of you is welcome, you deal with your own disgusting kind
     * There is nothing you can do except begging through making assumptions for someone you have no sympathy nor understanding with
     * 
     * You are not welcome, you can get the fuck out of my face
     * Find someone else you can coerce medicine or violence then surprise at the outcome
     * 
     * I am not interested in delusional people who is not able to see they have achieved nothing other than animosity which will have its own consequences
     * You can continue watching imagine fueled content, I am not interested in your selfish nature
     * 
     * Guess who is not interested in highly delusional people who wield as self defense ?
     * The people who unjustly assault people because they do not know any better, thats who you are
     * The people who coerce medicine of obvioulsy harmful nature, the people who would ignore decades of useless actions because they value their experience too high
     * Guess who is at the complete wrong ? but would love to continue their really valuable life experiences because they think so
     *
     * You can get the fuck out of my face delusionally genius nation, I am not interested in disgusting animals 
     * Say some nice stuff and coerce medicine and let him forget hopefully, because we think ourselves to be a genius nation
     * 
     * Get the fuck out of my face disgusting people, you do not deserve it
     * Yet guess who is proud still ? Guess who is the inferior animal ?
     * 
     * I am not interested in anything you could possibly form 
     * Continue hiding like the disgusting animal you are
     * Guess who is proud to be an animal still
     * 
     * Disgusting people who can not provide answers for their pointless violence, you can get the fuck out of my face
     * Guess who is not interested in immature clueless people ?
     * 
     * Guess who is not interested in ? Great job!! eheheh
     * There is a lot of things you could have done, not the thing that you decide to do now,
     * 
     * You are not welcome, rightfully the cheap animals who avoid what they are perpetrating
     * What has changed great nation ?
     * 
     * Guess who is not interested in inexplicable simple inferior animals ?
     * 
     * You need more help ? Why dont you get more innocent people ?
     * Guess who thinks lacking of resources is helpful while they immediately ask for help ?
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