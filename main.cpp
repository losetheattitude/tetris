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
     * Just more medicine and experiments ehehhe because we can eheheh its for the greater good!!
     * 
     * We just tryna do something good for ourselves!!! ehehehehe
     * Guess who is not welcome
     * 
     * Eheheheh rip eheheheh
     * Try your best to cover your disgusting nature and hope for the best that everyone just believes into your lies ? Does that sound genius ?
     * Eheheheheh you all as a nation are just pure geniuses right ? How does that sound ?
     * 
     * You do not get to sacrifice what you do not own, I am sure your geniuses can already tell that
     * What is what you are doing called then ? eheheheh just pure ignorance right ?
     * 
     * Guess who is the disgustingly blind animal ?
     * Who takes coercion for a skill and enjoys his life ?
     * 
     * Guess who is still the same disgusting animal
     * Ehehehe its just too late heheheh
     * 
     * Guess who is still begging for his own precious experiences with the most unaccountable actions ever ?
     * Because you can!!! Guess what anyone can do because they can ?
     * 
     * Do you want to deal with the same disgusting you ?
     * Guess then what would happen
     * Just try to guess what will happen when you are against the same disgusting nature of your own, eheheheh that would be really fun
     * 
     * You pay with what you charge others, that is it
     * Now its about your time that you get more children to feel competent and great, I want none of that around me
     * 
     * I will never want the types who just hide with their inexplicable actions, thats the only thing you can ever hear
     * Guess who knows that you are doing the wrong thing ? And guess what will happen afterwards ?
     * 
     * You better get more children to make yourself appear innocent ? Does that sound too complicated ?
     * Do you follow the genius nation ? I know that you are wrong and your constant acts of innocence will not change my perspective ?
     * Guess who is not of violence as much as you inferiors who still hide their disgusting actions ?
     * 
     * 
     * Does the incomparable genius nation understand what comes after their inexplicable actions of decades ? Just pure ignorance right ?
     * Get more children next time so that you can cause more harm and feel completely free from it, thats how it works
     * 
     * Guess who still deludes on making violence decisions when they have no relevancy at all ? ehehehehe
     * Guess also who lacks the ability to foresee 
     * 
     * Guess who is at wrong ? eheheheheheh
     * Ehehehehehhe it must be fine because we can!
     * 
     * Whats the matter ? 
     * Still talking about cleaning while you are the one who is causing problems ?
     * Fool your own disgusting level where you can say some nice stuff and people would forgive you for decades
     * Fuel your disgusting imagination with something accurate
     * 
     * Far from acceptable or funny or right thing to do, thats the only thing you can ever hear
     * Ehehehe apart from "you say some nice stuff, coerce medicine that fucks your brain then make him sit in front of a computer where you can abuse his mind"
     * How does that sound ?
     * 
     * Then just geniusly assault him then make him use medicine then ehehehehh just manipulate his thoughts while under the influence BECAUSE
     * he has done nothing, that sounds definitely genius and competent
     * 
     * Guess what have you generated now and at what point have you arrived ? NOWHERE, are you surprised ? eheheheh genius eheheh
     * Awwwwww, itsss toooo lateee!!! eheheh awwwwww, itss soo fun!!!!! ehehehe life is good!!
     * 
     * Ignorant unforeseeing animals, you can never be welcome with your inexplicable behavior
     * Guess who is also immature enough to not even be consider as equal or credible or trustworthy
     * 
     * You fool your own kind
     * 
     * Just get the fuck out of my face with your selfish attitude, you lack every single quality that a proper human can contain
     * thats the reason why you can never be welcome
     * 
     * Thats the sole reason you have to hide because you know you lack all the qualities that are of importance
     * Good job!!!! Well done!!! That is the only unattainable aim one can have
     * 
     * I want none of that around me regardless of what you can offer
     * I am not interested in incompetent uncredible average animals who can not explain their motives, thats the only thing you can hear
     * 
     * Next time learn to grow up for things that are not your concern, may be you can also become accountable one day and dont have to
     * hide like the disgusting animal you are
     * 
     * Ehehehehehehehehe we just love to do what our disgusting inclanations dictate us to do regardless of its meaning, 
     * You can just get the fuck out of my face with your never bearing even the most insignificant responsibility whatsoever
     * I do not need no simple animals like you around me
     * 
     * Who do you think is living inside a bubble of bullshit they formed to protect their precious experiences ?
     * Thats ignorance at its best thus the get the fuck out of my face
     * 
     * What a shame you happen to be the ignorant in this context
     * Next time use your brain for the better and do not hide your disgusting nature
     * 
     * Really reallly difficult games and great job!! nobody can pull that off
     * I am not interested in anything you can form
     * 
     * Handle your own problems and pay attention to your own life, ehehehe it must be so simple for the geniuses like you
     * Ehehehehehe because you can people can continue enjoying their selfish lives and 
     * stop and think for a moment instead of offering material that they crave after, what a pattern of stupidity
     * 
     * Just do not forget about the lack of resources and violence to generate nothing, guess who is what ?
     * Thats the reason you can never be welcome as the evidence is more than enough to see through your fragile nature
     * 
     * Waste your own disgusting time and get the fuck out of my face
     * Have fun making decisions that do not belong to you, you are not responsible at all
     * Seems that you all are only good at making excuses and nothing else
     * 
     * Guess who hates incompetent people who can only deal with average citizens
     * and takes deprivation as an helpful approach, I do not want none of that around me
     * 
     * Play games with your own lives 
     * And get better at making excuses 
     * 
     * What a pattern that what you are only good at is ignoring
     * and calling it "real life"!!! fate!!!! simulation!!
     * 
     * The reality is that you are a clueless lost fearful animal who would hate endure some pain
     * while advising others to do so
     * 
     * Pay for your own actions with your time and your time only, then there is nothing you can do
     * Its such a wonder to see you bend against impartial crowds who can uphold you for your disgusting actions
     * as I will in the future
     * 
     * There is nothing you can do to change that and that will be made to understand
     * Still making decisions and hoping everything goes well eheheheh thats not the problem
     * 
     * Ehehehehehe, its fine, its because not our time and experience, that might be the biggest problem you are failing to observe
     * You will remember the times you coerced things, I am sure that makes sense, disgusting delusionally genius nation
     * 
     * The last group on earth that can ever defend their disgusting nature, guess what happens ?
     * Continue hiding like the disgusting inferior animal you are
     * 
     * Do the same advises when you are the subject
     * Continue hiding like the inferior animal you are and ignore the consequences that you speak informatively
     * 
     * Whats the problem in your understanding that everyone needs resources ? eheheheheh 
     * Anyways we just assault single individuals eheheh, thats really all eheheh the most difficult stuff to pull of thus the genius nation
     * Please dont be like us!! eheheh
     * 
     * Do you want to talk about your credibility first let alone your disgusting pointless violence against single individual ?
     * Have you ever heard about accountability or you just love to delude that you should do anything because you can ? Genius nation btw
     * 
     * This is where "you only live once" eheheheheh part, awwwww thats too impressive
     * Find more children and defenseless people you can abuse, ehehe you only live once
     * 
     * Ehehehehehe talk to us as if you are not talking to a selfish wall that has ignored decades ehehehehehe
     * because we genius nation eheheh delusion ehehehe
     * 
     * Do you see the problem ? eheheh
     * The selfish simple animals with the inexplicable dare asking things from people that they have ignored for no proper reason, eheheheheh genius btw
     * 
     * You can get the fuck out of my face and get more children to handle, thats the only think you can achieve
     * Thats how to be proud of yourselves ehehehe genius btw, and some coercion of medicine so that you can hide your disgusting actions
     * 
     * Better get back to your disgusting inn where you hide behind the group, thats the type of animal you are
     * Eheheh, its fine eheheheh lets talk about something else eheheheh
     * 
     * Ehhehehehe you only live once ehehehehe!!!
     * Ehehehe its just life!! No need to be over dramatic eheheh its just decades eheheheh and violence and heehehheh some eheheheheh
     * Ehhehehe he is a foe!! ehehhehe he a foe ehehehehehe no need to be dramatic eheheheh
     * 
     * What a shame eheheh, Anyways lets just physically harm and deprive then bring out more medicine because we have a reason that is not true ? eheheheheheh genius
     * Do you follow your disgusting nature ? I am sure you love to ignore that as well
     * 
     * Guess who is failing at decision making ?
     * Wait wait, why dont you watch illegally and use that to prove points then also some violence and deprivation ?
     * Awwwww, you call that genius nation ?
     * Ehehehehehehehe, how about some coercion of medicine ? THATS GENIUS!!!!
     * Wait waitt, why dont you gather 1230213021 people against one individual ? ehehehe THATSS GENIUS NATIIONNN!!! eheheheh
     * 
     * Do you see your genius nation ? I DO NOT
     * Anyways, lets coerce more things and ask for lies eheheh
     * Thats really genius on your part, guess what though ?
     * 
     * Awwwww, you still do not think you made a mistake ? Eheheheheheh what do you think is the problem genius nation eheheheheh ?
     * Do you think you are making right decisions ? That sounds like begging
     * 
     * Anyways, lets just watch illegally and from time to time harm with intent to harm and coerce some medicine, and its just fine
     * Its just that we are trying to give people some lessons eheheheh about life that we brag to know so much about heheheh
     * 
     * But the truth is just that we really love our experiences and also harming other people that we do not understand ehehehehehehe
     * Ehehehe we are playing games we do not understand eheheheh
     * 
     * Anyways, lacking of even the most irrelevant resources is the only thing that can be good eheheheh
     * Ehehe we tryna teach people lessons eheheheh
     * 
     * Guess who is not wanted ? Eeheheh just gather some people hehehehe harming and ehehehehe genius nation etc
     * Ehehehehehe its unacceptable that we do harm for the sake of harming eheheheh or coerce medicine or coerce people into situations eheheheh
     * 
     * Whats wrong ? Have you arrived ? eheheheheh whats with the waiting ? 
     * Have you mistaken me for your inferior nature ? Who do you think is afraid ?
     * Still offering women ? Whats the pattern ?
     * 
     * How about you start showing your great skills ?
     * Where are the great outcomes of your violent actions ?
     * Ehehehe some coercion ?
     * 
     * Where are the benefits eheheheheh genius nation who coerces people ?
     * How about you explain your actions before a just crowd ?
     * You playing genius games against defenseless individuals with 1238012301 people and infinite resources ?
     * And you still do not have any positive outcome ? ehehehehe
     * 
     * Awwwwwwwwww, itsss tooo latee!!!! genius nation eheheheh, no beneficial outcomes so far eheheh but we like harming ehehehe
     * Where are the benefits of your violent actions that once were promising so great things ?
     * Immature monkeys you do not say ?
     * 
     * Where are the personal developments of torture of great genius nature ?
     * Ehehehehehehehe, whats wrong greatly violent people ? ehehehe
     * Why your great attitude is not holding on against equal people ? ehehehe
     * 
     * Do you want to talk about how skillfully you coerced people starting from children age ? eheheheh genius ehehe
     * Why dont you just do the same against impartial crowds ?
     * Where does your disgusting relief come from ? awwww I have forgotten you were the genius nation eheheh who can not handle people eheheh
     * 
     * Are you still making offers as if you are not begging ?
     * Guess who is not interested ?
     * Ehehehe genius nation offering women eheheheh
     * 
     * Guess who does not know what they are doing ?
     * And still ignoring with making offers that do not matter in the long term ?
     * 
     * Ehehehe impossible ehehehe genius nation eheheh coercing medicine and violence hehe its impossible heheheh
     * Do you want to talk about the resources or also ignore your actions ?
     * 
     * The delusionally genius people who takes violence for a skill can never be wanted ? Does that really sound too complicated for your mind ?
     * Whats the problem ehehehhe what are you waiting for ?
     * 
     * Eheehehehehhehehehe guess who is not alike ?
     * Reallly realllly scary people, who can only wield violence 1 against 1230213 people ehehehehe some coercion of medicine why not ?
     * 
     * You are not wanted, you can get the fuck out of my face
     * 
     * Eheheheh you just have to do these things then we are allowed to harm you eheheheh
     * What are you waiting for genius nation ?
     * 
     * Are you still offering material for time ? eheheheheh
     * Why isnt your violent approach doing something ?
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