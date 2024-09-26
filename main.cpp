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
     * You already know the difference between excuses and the truth, so you can provide as many "random noises as you woud like" so long as you have 
     * default people around you
     * 
     * What insults are you talking about when the reality is on the scene with its most obscene form ? I really do not have desire to waste my time
     * more with you as you are not objective
     * This last time, this the last time  eheheh
     * 
     * only delusional ones can think what is regular for a gift, or rather they would love to wish
     * so is there your assistance for your future guesses
     * 
     * Nobody can make such a thing seem acceptable, try harder may be you wont get into trouble
     * Awwww, 29 years eheheheh, we havent even felt anything, WHATS THE PROBLEM ?
     * You wont get away from such a thing by doing what already got you to this point
     * And you suddenly start offering things or thanking ? You can not make decisions on behalf of something you do not understand ?
     * Whats the problem again ? And you do it with such a stupid approach that, you think saying "he is the only one who can survive this"
     * or "thats fate" should suddenly make everyone including me believe that ? Or are you just deluding about the future ?
     * Are you trying harder than you should or are you just "obsessed or stubborn" ?
     * Do you understand the meaning behind accusing of such a terrible thing ?
     * You already know what a disgusting scandal it actually is, so the proof of your refrain 
     * Awww, you need to produce bullshit for wider audiences ? Not a single individual ? Waaaaowww, what could be the problem ehehhee ?
     * Wooomeeeeeen!! Yet another bullshit of cheap approach. You will for sure do that, arent you ?
     * Awwww, you do not realize 29 years eheheh, awww we can not face the reality of our "intentions" and their consequences, so why not lie more ?
     * eheheh cars etc ehehehe women etc ehehehe, More womeen btw! wait wait, we havent even felt anything how come it has been 29 years eheheh
     * So, what could be the next for what we even havent realized we did ? That is really foreseeing should feel like 
     * You not selfish you saying ? I have no time for you can not tell you enough then, what was the problem again ?
     * No no, noone is responsible for such a thing!!! nooo, we give wooomeeeen!! Wait you do not even do that ? 
     * Then it definitely is something really really fun, eheheh just more harm to see what happens eheheh
     * 
     * ehehe, according to our calculations, this sort of thing should turn every single individual into a monster so that we could 
     * have something to worry about eheheh, no stupid games indeed! Awww, is this the part where you beg so that you can harm others ?
     * That is intelligence btw eheheh
     * 
     * That is abuse and what you think for fun does not make it otherwise unless you start acting the way you are supposed to, ehehe
     * no accountability and so much harm ehehehe!! disregarding your "irrelevant noises" and harming, is the summary of your "justified" position
     * Are you fucking stupid ? You already know the answer, just remind yourselves the random noises you once made, that will tell you why people choose 
     * to call them random
     * If you dont approach friendly, then there could be no other than just violence and everytime you reduce to begging and still act like the cheap animal you are
     * That can not be coincidence, eheheh this time it the last time pls, hehehe women hehehe, no no eheheh pls ueheheh
     * we no animal pls, good ppl btw, better wake up so you can actually understand what it means to do what you are avoiding
     * Awww, its so much late we really do not know eheheh, although we had all the information and cautions coming from
     * all parties of impartial nature, but we still love to act like we know what to do and enjoy the experience eheheheh its fun really
     * pls lie for us, hopefully nothing bad happens, we really love begging though, thats facts eheheh lie some more and harm, see what happens heheh
     * 
     * Naaahh, time does not exist, life a simulation so we lie, why not ? ehehe some womeeeen!!! and you fine, what is violence anyway ? eheheh time is illusion
     * Waste more time why not ? eheheh hopefully though there wont come a day eheheh
     * If you dream to have others afraid of violence, you already know what it is
     * And you wield women as weapon they become objects, so why not follow your most short term right ? That is definitely the intelligence part
     * Who needs growing up again ? eheheh not us pls bro, time does not exist btw, life a simulation, we seek voluntary conflict I guess ?
     * 
     * You do not remember the conditions ? That because you have followed your most short term gratification, thats the point of inexplication
     * And now, you have still no explanation, because ? you are a never learning simple animal whose movements are deterministic.
     * Tell me the opposite, you selfulfill your own "future", still deluding ? That can not be the problem
     * Your miserable fears can not be the problem, still begging for your own experiences ? Yes, that is not the problem, you can self fulfill your empty life
     * Do you want to assess the sincerity of your "irrelevant approaches" ? Get womeeen!! get this, you will get that, lie pls
     * why dont you grow up ? Instead talk about some violence ? Awwww, "forgive me" hehehe its so easy and fun, lifes good bro
     * 
     * All the indications are pointing the direct opposite of what you are "alleging" but you would still love to enjoy your life ehheeh
     * Still looking for solutions or bullshit ? Thats not the problem, and you suddenly think saying "I am sorry!!!" would do what ?
     * 
     * ehehe, why dont you just go fly somewhere or just do something ? eheheh its really easy, ehehe life a simulation btw
     * Tell me the worth of your values, you do not see the point where you are completely wrong ?
     * still thinking "greatly" that offering things you would not would suddenly solve the issue because you are after the same thing and so should others as well ?
     * You are really the most credible group of people I have ever seen!!! thank you, whatever you could say should definitely mean so much ehehe
     * 
     * Still producing bullshit to cover your inferior nature ? and you suddenly start thinking that offering material should solve the problem ?
     * So where is the correlation of "pain matures and have some womeeeen ?" So you have somehow assumed the role of "educator" ? With that approach of such a uniqueness ?
     * And you say you are miserably afraid so you just randomly harm then to beg as thats in your core nature ? Then you suddenly start saying have some womeen ?
     * 
     * What a shame that you can not see, you are the type that world is suffering from.
     * You are the type that the world is suffering from ? You still say women or cars ? but you still brag about applying irrelevant pain ?
     * In which stupid world are you living ? Imma pass the world in which you enjoy and advise others to lead pain inflicted externally
     * Stupid people, to even say the least. You can delude all you want, do it after you pay for your actions of 29 years 
     * You dreamt it would be solved so easily I am sure, who is the irresponsible, uncredible yet "delusional" animal ?
     * You can not be just that, since you have not even made a single decision that is not your place right ?
     * And you still disgustingly offer women ? Where were you all this time ? Awwww, now you are in tight situation, so you act really intelligently eheheheh
     * Do you have the audacity to think about fixing ? And you say "you are trying to help ? or trying to teach ?"
     * And you suddenly start begging ? Back!! we take it back!! plsss, you know thats the precise definition of "being a stupid kid"
     * 
     * Look at your own actions and infer the need of education on your part, you would be the very thing you brag about if you had the intelligence to see that
     * Still begging that "HE ATE IT!!!! eheheheh oyster heheheh eheh its so funny bro, we good, great intelligent ppl ehehe"
     * 
     * Existential threat!! existential threat hehehehe!!, you do not get to decide, wait wait its have some womeeeeeennnn!!! plsss
     * and you still beg for silence ? Awww, 29 years is nothing come on, please trust and help us!!! we give womeeeennnnn!!!
     * You see our credibility right ? Thats unmatchable!!! You do not get to decide whether something continues or not
     * 
     * You still seek for appliable yet nonsense bullshit ? Trust us pls, we deliver we good, he ate it, he was like this, he did it! ehehhe
     * Really good luck explaining your perfect reasonless brains, and all you can say, is meaningless noises ?
     * And you beg silence ? But you still want to enjoy your experiences ? eheheh
     * So you sure you are not biased eheh, btw get woomeeeenn!!! get carss!!! its funny somehow ehhehe
     * 
     * Please be calm, now that we can have some form of harm, be calm and use your brain!! eheh
     * Pleasee, assess our great conduct calmly!! because it reallly really is apparent that its disgusting
     * So you think it would be a blessing ehehehe, thats really a good guess, with all the information I have,
     * I can confidently say that you are in a tough situation, Immature people do have that skill to themselves
     * What makes you think one would consider going back into a group which have made so disgusting actions they can not account for ?
     * Btw, tell me the worth of your existence hehehe, not incompetency really
     * using your brain you can only tell "carsss!!! womeeeen!!!" thats no coincidence
     * 
     * You know what they say about people like you, eheheh, like the type that offers wooomeeeeen!!! for what they are afraid to tell about what they are
     * committing intentionally, like the type that takes what is certainly not funny for funny so that they could hide like the animal they are
     * Please, lie for us for a few days, then we can harm more heheheh
     * 
     * Pain as education!!! we clearly lack all of that which we praise
     * Please forgive us!!! we are not the same individual that harmed for the sake of harming!!!! we want to have fun!! heeheheh have some womeeennn!!!!
     * But do not tell them the previous attempts of ours that are such a scale on the intelligence eheheheh pls
     * 
     * Now, talk about your great noises ? Aww, you prefer calling it medicine!!!! fate!!!!
     * You still dare calling it fate what you are intentionally committing ? going against the will of an individual with the most stupid things ?
     * medicine!! You still would call it life ? ehehehhe its so fun, we just follow the stupid people, and believe and do whatever they say, we aint no animals ehehe
     * Do you want to tell people how many times have you said the same things ?ehehehe it really is funny
     * You just get harmed and detriment for no reason eheheh
     * 
     * How come you feel like you can make decisions that are not your concern ? I do not care what you think as you can guess
     * perfectly, before all that, answer for the violence that you somehow perfectly think again that it is necessary
     * 
     * You used your perfect brain and arrived to the conclusion that one would need pointless violence and you did used it again
     * to say that you can not just experience life ? And you used your perfect brain again to use medicine for what you are doing joyfully ?
     * And you complain the situation you are in ? But you are doing it for your selfish purposes of experience ?
     * And you still look around for solutions ? or you would rather ask "forgiveness" from those you havent practiced ?
     * And you still hold stupid conversations for the very selfish experience that you would hate to ruin ? The very same urge 
     * Under no circumstances can you make me do anything other than I want, so better luck next time
     * And you still beg for random noises ? That you take for a skill ? Heyy, please lie and say this or otherwise we would be ruining our experiences ehehehe
     * Okay okayyy, pls now help lying us eheheheh we really intelligent ppl, you will waste as you have done so, thats why I just do not have the intention for
     * fooling around, now tell me the experience I have had, instead of offering the same stupid things like crazy over and over 
     * That should be the intelligent eheheh, how come you talk normally ? talk more about 29 years and some violence hehehe its really fun 
     * awww, before you forget your super intelligence approach and offer some woooomeeeeenn!!! Awwww, thats a blessing of begging
     * You can get the fuck out of my face, wait waitt, you would rather call it education eheheh, wait wait, tell me the worth of your credibility
     * or you just have to grow up or simply talk about the violence that you somehow think for a skill
     * Ehehehe, this heaven, we good ppl, we tryna help, you get good things pls eheheh, you get women!!! you get womeeen!!! pls
     * stop doing that  eheheheh, get some women eheheh we did so many things pls
     * 
     * You are just wasting time without a proper reason, and I have got nothing else other than bullshit to say to any of you. Its not that difficult
     * Public threat!!! existential threat!!!! we do no harm!! he does!! plss. Its just so simple, forget about the "past"!!! we good!! worry about the future!!
     * Carss!!!! womeeen!! 29 years of intentional bullshit and you can just forget about it!!!  10 yo kid and we just think it should be okay to say "forget aehehhe"
     * wait wait, gather more people eheheh more harm !!! eheheh its fun, btw we think we are sophistacted enough to talk about life!!!! fate!! its fate!!!
     * We are the one who is harming others!!! and suddenly start begging and thinking it for a skill
     * 
     *  ehehehhe the amount of stupid patterns you display... Certainly a strong indication of utmost intelligence, not even talking about your desperate excuses
     * to cover what you already know about your incompetent selves
     * Its past!! its in the past!! its history!! a few years ealier is also history!! pls!!! we do no harm to nobody!!! he is bad!! he illegal!! ehehehhe
     * 
     * ehehehhe the amount of stupid patterns you display... Certainly a strong indication of utmost intelligence
     * Only a slight feeling of "immature spoiled stupid kid" who can not assess unbiased information properly
     * Hey look, we tryna help and fix something eheheheh, we competent ppl, talk about the violence, talk about the conditions that you honorably pledged
     * Awww, wait what did you achieve again ? Awww, you have breached the law for no apparent and beneficial purposes ? and you think begging is a skill ?
     * And when it comes to explain, as you already know that its inexplicable, you say we lie!!! we intelligent ppl!!! we lie and harm citizenss!!! yess
     * Aww, you would rather say woomeeeenn!! 
     * 
     * If you were the type that you now think really intelligently posed to be, you would have already communicated
     * 
     * well enough to the point that you know you are acting like a stupid reasonless animal instead of just harming for the sake of harming eheheheh its funny
     * And you still dare calling people violent when you are the one causing harm eheheh, yes detrimental lifestyle can solve your every problem of existential nature
     * You are just after the right pursuit, be sure about that
     * 
     * Just tell me the effective achievement of what you are miserably afraid of telling people or assuming responsibility as an individual eheheh funny, its life
     * its simulation eheheh we good
     * 
     * I have no intention to waste my time with stupid aimless people like you who can produce nothing but bullshit to guise their disgusting nature
     * Awww, you must have forgotten eheheh, forgive us!!! please Not immature people indeed, you still dreaming ?
     * Sat down watching without neither a purpose nor a reason ? I have no time for any of you, whether you think violence can change that or not,
     * its up to you to find out, poem indeed!
     * 
     * Just keep deluding, out of my vicinity, dare talking about education but quite averse to notice his stupidity in his actions, no problem at all
     * talk about competency in supposedly every field expect a few eheheh
     * Talk about how generous and visionary and reasonable etc, you only need dumb people around you who is also a beggar
     * eeheheh we tryna solve world problems ehehehheh pls help lie us eheheh
     * now try to solve the problem you have formed intentionally, I wonder how intelligent you really are when you are against a real problem eheheh
     * you prefer begging no surprise at all, woomee eeennn!!! You are rich!! pls help us, we do goodd, we solve problems pls, 
     * Get a car!!! get some womeeennn!!! help us lie!! plss we are innocent good citizens !!!
     * we tryna educate, we tryna solve world problems, we good ppl, we intelligent, we do not cause any harm!!! heheheh its funn, lifes a simulation
     * pls lie for us!!! get cars!!! get womeeeenn!! we have provided 123912321 womeeenn!!! plss trust us!!! plsss
     * Dumb people indeed, no no we harm nobody!! we tryna help others!! plss, we cause no harm!!! eheheh lie for us!!! get cars!! wooomeeeeeeenn!!
     * we aint no dumb animal!! plsss
     * 
     * How come you think funny for what a disgusting thing ? Is it because you are doing it ? Some sort of special group of people ? ehehehe
     * 
     * Now talk about the violence and preceding beggings of promise nature, then we can talk about what to do
     * Or just simply grow up and get the fuck out of my face, awww you would rather accuse 10yo kids with what you coercefully made them into ?
     * No no, you are %100000000 right, now you can get the fuck out of my face to doing whatever you were, no you are not the problem
     * You are only wasting my time, you have always, and you are now as well, thats the reason
     * 
     * Whats the problem again ? How come you think you can make irrelevant noises ? How come you think you act only detrimental and expect others to understand ?
     * Or would you say "womeeeennnn!!" or you just avoid the responsibility of the most possibly worst thing on earth ?
     * How come you feel relieved ? Bro get the fuck out of my face, waste your own time
     * Wait, you still try your best to achieve what ? and you have no explanation for the entire time of an individual that you have neither
     * interest nor relation with ? Just that you are a spoiled immature kid ? And you hate when people go against your ideas ?
     * 
     * And you still produce whatever you can come up with, not that they are true but you delude something to be the solution to a non existent problem ?
     * What do you think a biological creature could be looking for other than what you are looking for ? But somehow
     * you lack the courage to simply provide what any other does need ? And you just say, he could just die!!! I DO NOT CARE ?
     * That can not be the problem along side your great acts of violence ? You only need to look at the "result"
     * but as you can tell, if you can not already see the problem that means you are not meant to, thats why I keep saying, PAY ATTENTION TO YOUR OWN LIVES!!
     * You are only harming to harm!!!
     * 
     * Obviously, anybody would want so instead of prompting question just act on what you "insincerely offering", or you would like to
     * just do it at the last moment so that you can "defend" your doubtful position
     * 
     * Your thinking of "fooling" someone through making him believe not to his own senses but to your uncredible words should
     * be the way to go!!! clearly intelligent although I am not buying it. I can see what I am and have been dealing with
     * So better leave your stupid attitude and do what you are supposed and promised to properly instead of taking being cheap for skillful
     * 
     * How come you still talk ? You are the most uncredible and immature people that I would not even consider for a second to waste my time with
     * Oyster!! he ate it !!! Like the spoiled dumb little kids that ignore the truth and keeps alleging the same stupid thing,
     * and look at the "last time" justification of your "disgusting honor", hey we gave so many womeeeen!! we credible we good ppl
     * fucking dumb crowds, just as the everyone has been describing
     * 
     * Coercion plays out just as this instance does, when the "perpetrators" are amiss, there is no problems. You see the problem ?
     * 29 years is just okay because we have done something that we shouldnt have!!! so get womeeenn!!
     * Btw, talk about the violence and correlate it with the "life" instead of begging like the animal you are with bullshit
     * approaches as "failure, he did it !!!". Instead talk about your productive and informative approach so far, and correlate with what it has solved 
     * You will quickly find out the answer to be the nothing! but guess what, you lack all the "substance" for an animal to become a human 
     * so you will avoid acknowleding your mistake, delude about how great you are
     * 
     * Eheheheh, just a joke, 29 years its nothing, hopefully we get no harm!! just the average animal of 20. century
     * Just the average animal who deals with the reality that they can not be okay with through his vile reflection
     * Just some violence!!! some lies!! some inept approaches because why not ? But we can not really accept it eheheheheh
     * funny and intelligent people and also all the good qualities !!! now tell me that you are not the most deludeful dumb animals
     * 
     * But you really do not and can not account for your actions ? eheheheh we take it back!!! we really intelligent and good ppl!!!
     * And expect no same natured people! Thats the great reasoning, and expect everything to be solved just the way you delude and dream
     * them to be solved, whats the problem do you think ? You are not, thats for sure
     * Have some wooomeeeenn!! whats the problem ? And you still dare talking about others' supposedly self inflicted failures. Interesting indeed
     * 
     * How come you are the one who is trying to go against the reality but also applying great violence ? and you are the ome who is still thinking
     * that watching illegally should be okay alongside with violence and all the things you would love to run away ? ehehe its funny
     * 
     * Noo, you should also live detrimental lifestyle because... because welll, because its like yesss, we no problem
     * Hey, when the time comes say a few good things and we move on to our precious experiences, we do not care what happens ehehehe intelligent btw
     * 
     * Its illegal!!! 29 years is just a joke, we tryna help and have fun!! we hate to assume such a responsibility!!! so we just tryna have fun eheheh
     * Its just illegal but we also would love to watch illegally, apply some random violence and force people into detrimental lifestyle!!! thats the great people
     * eheheheh, have some womeeeenn!! thats really good
     * 
     * Ehehehe its a little bit late but we believe we did something wrong ? That sounds like a really really dumb animal to me ? 
     * Wait wait, we thought everyone was doing something while we were as well ? So now it makes sense to waste our times with people we have no relation
     * or understanding of his life with ? And you dare talking about cars ? You know it means you are being overly irresponsible,
     * and what do you think is the outcome of such an irresponsibility would be ? Awww, you would rather avoid with stupid excuses until the point that
     * something awefulll!!! happens, tell me your are not a child, why do you think one would be content to commit ?
     * see the problem ? you still want people talk things out ? Can you talk people out the really clever actions ? 
     * 
     * You know there could be no going back, as you have alreay agreed eheheheh 
     * What could be the solution ? Womeeeeennnn!! we understand, we good, we tryna help, we solve problem
     * Just try to explain your actions, and we can get to the talking afterwards
     * Womeeenn!!!! just one right before things get complicated, eheheheh its really fun, life a simulation btw
     * so it must be totally okay to beg and harm later on eheheh awww that was the part that was intelligent eheheheh
     * 
     * eheheh, stop that!!! you can not post those !!!! we good ppl, we cause no disasters
     * Tell me your credibility again ? pls lie for us, wait wait, we were about to say, lets show them how violent we are!!!
     * 
     * Now are you going to start asking for help from who you are harming without a reason ? You see where the cheap is coming from ?
     * and you still offer for your disgusting actions, cars ??? or woomeeeeennn ?
     * You understand the coercion right ? You understand the irresponsibility right ? Awww, you love to allege with whatever eheheh
     * You see how you failingly dealing with reality ? Why do you think things get complicated and gets broken ?
     * Now you have 30 years of wasted time with some stupid random violence of your own reflection
     * Now you can only coerce as you have done before in order to guise and where did it lead you to so far ?
     * Its just fate btw, including random violence as well and afterwards begging as well ?
     * eheheh we take it back! back!! no its just a small mistake, still talk about life ?
     * I just do not really like you, because you are immature kids, I am sorry to show you the reality
     * look for bullshit to be proud of eheheh what was it again ? yesss, you no selfish
     * you do not get to decide when you are harming for the sake of harm, that is bullshit as the prior actions of yours 
     * You see the problem is whether someone does good, its that you DO NOT DO HARM, fucking stupid monkeys
     * 
     * You ate it!!1 oyster eheheh thats why we harm!! please help lie us, eheheheheh plsplspls we good, I swear
     * What a shame that you are an oblivious animal, awww how about 29 years ? Welll, thats just life ehehhehe we intelligent
     * Thats not being a kid, I assure you. 29 years ? ehehehe its just meant to be that we seek reasonless trouble because of our insecurity
     * You still think you are acting on your insecurities ? Its just meant to be ? Its life ? Its simulation ? We great ? 29 years ? eheh woooomeeeenn!!!
     * Now the situation is, you have built yourselves a huge pile of disgusting bullshit that you have no idea how to unveil. Waaowwwww, have some woomeeeeenn!!!
     * Offtopic!!! offtopic!! dont tell people what a disgusting animal we are!!! It was just a small mistake!!! eheheheh we harm 29 years eheheh
     * 
     * You get unconditional violence as thats the exact reflection of your reason, the delusion of "making the most stupid decisions on behalf of others"
     * is a must, that is the type I do not want around me.
     * 
     * You understand the against will actions does not have any substitution so whether you think offering what others are acquiring normally should make
     * a difference or not, that is only what you wish the reality to be
     * That is the point of irrationality that you would regret stepping into tomorrow if not today, talk about regular life experiences for extreme detrimental ones,
     * you will see the point, I have all that it takes to see the difference VOLUNTARILY
     * 
     * Think about medications etc ehehehe, we tryna help we tryna solve world problems, Get some womeeeeennnnn!!! thats how intelligent we are,
     * we only see what we dream then get surprised at the possible outcomes eheheheh we just do not understand, we want enjoy our lifes!!
     * How come you take killing for a joke ? Warr!!!!! woooomeeeennn!!! get carss!!! ?
     * Heyy, people tell us what to do!! we are not bad ppl !! plss lie for us!! you got 123123021 womeeeeen!!!
     * 
     * Just the last time, we give one woooomeeeennn!! we tryna play games we tryna help ppl!!! plss
     * you know I can tell the difference between who I am with so better stop playing stupid games
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