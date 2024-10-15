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
     * or I should say, you just do not know what you are doing
     * 
     * Try to find the most logical way of "restoring" ehehehe for 29 years eheheh its funny eheheh we do not really know neither what we are doing nor what could happen!!
     * we good btw
     * We still think, woooomeeeeeennnn should be enough eheheh its really funny though
     * 
     * Awwww, you havent still realized what you are doing wrong, or you just would love the reality allow you eheheheh
     * Its definitely funny, make sure it be like that, wait which part was exactly the funniest ?
     * 
     * Keep guising your fear with the most possible stupid thing!! violencee!!! and we want to enjoy our experiences eheheheh
     * Still "defending" the same story ? You do not even follow ? The whole story if about life and it has been 29 years ? So there is no need for your stupid stories ?
     * Thats why you are the type that everyone has been referring to ? Because you do not see, you just fear eheheh
     * Its just life btw, the inaccuracy of such an approach is unmatchable and when you add the fact that there could be no responsibility you get yourself 
     * a group of animals who think they should do whatever they want
     * 
     * Do you think life works that way ? You know when there is no responsibility, this is what happens, you all start begging for random noises for your
     * intentional actions, so your incompetency goes as far as not foreseeing that such an accusation is naturally destined to fail ?
     * He ate it!!! he did this!! we display our greatness through violence to single individuals!!! 
     * 
     * So, the story is, I have all the information I need to determine the guilty ? But you still would like to enjoy ?
     * Are you to one who plans for the long term ? Are you the one who seek no problems yet you can not use your brain to the point that it will cause you
     * longer term troubles ? You know its not only inexplicable but also intentionally made so ?
     * 
     * And what are the explanation for your great decisions ? just a big pile of inexplicable bullshit, its just life, we expect no responsibility
     * You just go around 29 years eheheheh we givee womeenn!! we give anything you need!! pls
     * 
     * Is it because you really do not know what it is or you would hate to see it for what it is ?
     * It is definitely most curious, you see the very same problem occurs when you offer woomeeeeen!! for what you can not explain
     * 
     * You would rather try to survive from completely nonsense approach ? Heyyy! we give womennn!! help us!
     * Ehehhe, if you needed money, all you have to do is ask!!! we good ppl, pls
     * Do you want cars ??? Just ask for them!!! Have some womeeeenn!!! we good ppl,
     * 
     * Look what a stupid situation you got yourselves in, that was indeed a necessity!!! 
     * We tryna help you!! we tryna solve problems!! plss
     * 
     * We do not know what is next eheheheh, we make promises as we do right now ? Why dont you believe us ? Awww, thats not a pattern indeed
     * Hey why dont you stay in my place!!! we good ppl, we tryna help you, why dont you just ask for it???
     * So you say, we tryna help!!! Awww, it is past!! its the history!! It has only been a few years!!!
     * Awwww, why didnt you ask for money from people who harms you ? wait wait, there could be a problem in your understandings eheheh
     * So you think you act intelligently ehehehe 
     * eheheh we prefer harming eheheh feels good, life good, life simulation time does not exist
     * Why didnt you ask for help ? We good, we tryna help everybody!!
     * It looks disgustingly obvious that you are causing pointless harm and acting like you are making you intelligent ? Are you sure about that ?
     * And you start saying carsss!! womeeennn!!! ? and can you tell me the experience I have had ?
     * 
     * I do not want to see any of you around me, you remember your honorable and credible promises or actions that you think is fucking intelligent
     * like "give him a teen!!!" and lets chase him!!! eheheheh we honorable people, we always deliver, why dont you trust us ?
     *  
     * fucking immature dumb monkeys that do not understand shit because of their stupid stubborness
     * Look at you, deluding that you are actually doing something while the reality is you are just stubborn lost people
     * having fun from random violence, wasting time looking around ?
     * 
     * You still think it should be fine ? What makes you think I want to play your stupid games ? I am the one who is experiencing your stupid irrelevant conduct
     * I am good regardless of anything you could possibly offer or beg for me to help you
     * 
     * Which part is exactly the most appropriate again ? still medication you think ?
     * You still thinking for others as well ? But with the most stupidly erroneous way ?
     * And you would rather not receive any sort of "corrections" of your stupid behavior ?
     * Eehheehe, you are like, why not coercefully give him medicines while we display our greatness through violence, he can not have anything
     * because he has no resources because we constantly harm him, and we call it intelligence ?
     * And all the while you harm, 29 years has passed, but you have the courage to say that it is all a joke!!! help us!!
     * 
     * Its just that we overpopulated with good intentions that we just want to see others doing good as well!!
     * We had 29 years of opportunity to do just the thing that now we beg that we do ?
     * And you still think you achieve ? But achieve what exactly ? Fucking stupid dumb monkeys, congrats to your animality
     * 
     * wait wait, instead for now we should say, wooomeeeeennnn!!!!! thats being overly intelligent btw
     * Not that, you had years and years of opportunity to, but its just a simulation indeed, 29 years eheheheh its not important eheheh
     * 
     * You pay for your own actions, I am not looking for anything especially from you and especially "women", 
     * those who think basic physical interactions to be a point of "intervention" and wield it failingly to achieve great harm!!!
     * Not dumb people indeed, I am just talking about irrelevant stuff, yesss, existential threat, yesss its bad etc
     * 
     * You see where the cheap attribution is coming from ? You are the same animal who thinks they are doing something because they are forcing "their limits"
     * whereas the reality is, you all look like the very animal that has been described everywhere!!! good ppl
     * 
     * If you had the proper intention, your actions would have already been rendered differently, you are causing all this to happen and
     * even worse will follow because you do not get your vile side
     * Wait wait, wait if we harmed 10yo kids and coerced him into doing things so that later on we can provide as proof for our vile behavior ?
     * And I am the one, saying it again, all the information I could need to re-form the true reality ? and all you can say is wooomeeeen!!!?
     * Have some relation!!! we give you what has never been given to nobody!!!
     * What a shame that you are a never learning animal, that has always done the same mistake over and over again throughout the history
     * 
     * Do the same mistake that others have done, do not be surprised at, or you would rather bend guising it with being "overly intelligent"
     * What you would love to call history, is not only really close but also one in which you harm irrelevant people
     * You call it education, but guess what ? Have you ever been looked at the history ? You are just exactly the type in the history
     * Bro wake up to your reality, you are average people and you prove that with your stupid actions 
     * Like taking begging for a skill, like taking violence for a skill, like taking detrimental like for a skill,
     * You are average, and thats why you act the way you act, WAKE UP
     * 
     * You pay for your own actions again, thats as far as it could go, not some wooomeeeeeennnn!!! that you think you fool people because
     * they fucking crave your stupid ass, WAKE UP! good ppl
     * instead of begging, you could be doing a lot more other things, and you will get yourself into trouble
     * 
     * Are you fucking dreaming still ? Heyy we found some pieces, that should indicate so many things as to what we were doing!!
     * And you still delude ? and you still waste time ? Thinking that you have somehow rights to do it ? You delude it to be your fucking job?
     * Harming irrelevant people ?
     * 
     * Congrats to all of you!! make decisions and hide like the animal you are, I do not want to see any of you around me, continue deluding
     * Forget about the past!!! wait wait, allow us to harm a little more ehehe it was meant to be btw, its fate or life a simulation, life good
     * we good ppl, you still delude you should do what you want without responsibility ? Yess, thats who I have always been looking for
     * Please, we are %100000 sure that what we are doing is right but just keep it silence, there is really no reason!! just keep it silence for us!!
     * we want you to keep it silence!!! plss
     * 
     * just talk about your great conduct to an individual amongst the media or unbiased people, let that be written into history and you will suddenly
     * see what a stupid animal you are, eheheh we do it the old way bro, we give woomeeenn we give carss!!! we like harming people hehehe funny thoough
     * keep it silence pls, carsss!!!! look how simple we are!!! wooomeeennn!! but keep what we are doing in between pls!!!
     * Do not let such a disgusting sequence be written into anywhere!!! plsss get cars!!
     * we do it the old way! we good ppl! ehehehhe its really fun
     * 
     * Stupid animals, compare your old way of doing "things" and the people who actually practices his brain. Thats the indication you should be looking for
     * to tell that you are actually a random individual
     * 
     * Instead of saying "do something", start talking about violence and no money!!! no going out!!! giving teens to then "intelligently catch"
     * You all bunch of dumb animals, you still talk about cars ? we do it the old way bro!! you get nothing but when people gather, we say "do something!!!"
     * "get woomeeeen!!"
     * 
     * Why do you still beg ? Please go with what we are saying so that we can continue harming!!! help uss
     * we do it the old way btw, aint no harm in that, we tryna help people
     * wait, you would rather offer wooomeeeeennn!!! so that afterwards you can enjoy yourself with stupid approaches ?
     * Ehehehe, we catch him!! we give hime womeeen!! we catch him ehehehe intelligent people act like this bro
     * Time does not exist btw
     * 
     * We give womennn ehehehe then we catch him eheheheh its really intelligent btw eheheh
     * If it was you who were with "me" all this time, then you are the problem, thats just as easy as it is
     * No you are not selfish, yess you are skillful also credible ehehhehe
     * 
     * I do not want to have any relation whatsoever, so good luck on your living "your best lives" without harming others
     * greatly achieved for sure, you still dreaming ?
     * Who are you again ? What a shame that you are a delusional group of animals
     * Yes, indeed you are not selfish, have once or twice the most physical interaction and it should be all fine
     * Do you even understand what is needed for someone to live his life ? And look at what you are suggesting, no no, definitely not dumb animals
     * No no, just because you said it, it shouldnt be the right. Eheheheh wait wait, what happened ?
     * Ehehehe, if you do this, then you get this!!!! you can infer our credibility from our past actions, we the great people of earth!!!
     * 
     * Dumb immature monkeys, you do not see your entirely relative "but somehow super intelligent decisions" ? You can not even say
     * anything other than, heyyy its life!! its fate!!! life a simulation!!! pls we tryna help!!!
     * Ehehehe, its just fate really
     * 
     * You do not understand the difference between what we are thinking ? You say holiday!!!! womeeeennn!! cars!!!!! I am saying what again ?
     * Eheheh he just died, for some reason ehehe, we can not really change the past!!
     * We do it the old way ehehe, go practice the same credibility in other areas of your life, good luck explaining it to others
     * 
     * 
     * You know that I remember so no worries, it should be fine
     * You already know that I know, it is all about coercion of kids that can not object to you and when they do, remember what you have done
     * That is to proud certainly
     * 
     * Delude it be okay, it should be okay
     * Thats not deserved problem at all, you have and are still displaying weakness by doing the most basic thing and feel okay about it
     * Always be the same person right ? Who do you think is having problems with that ? 
     * Now its the time you grow up and wake up and whatever you delude not to be
     * Do you want to talk about how you greatly coerced kids into ? And afterwards you can not even properly explain ?
     * We do it the old way btw, isnt it ? What could even go wrong ?
     * No no, you can not compare others with him!!! we never made no promises ehehehehe intelligent ppl btw
     * get cars!! eheheh this the 10. time we offer eheheh intelligent ppl btw
     * 
     * Selfish disgusting monkeys, still talk about fate ? Still dare bringing up fate ?
     * or you would rather offer womeeennnn!!! so that you can survive at the moment ehehehe intelligent people btw
     * Its fine 30 years is nothing ehehehe we tryna be really intelligent and good ppl
     * 
     * No no, you can not get resources!!! you cant go outside!!! no money!! wait wait, we give womeeeen!!! we give you womeeenn!!!
     * Do you even believe that you are communicating ? Or are you just doing your complete best to ignore your mistakes of malign nature ?
     * No no, you can not get resources!! you cant go outside!! no money!! and also some violence!!! some coercion to 10yo kids as well
     * we tryna help you please, 29 years is just nothing! I swear please trust us
     * Again, try to prompt your credibility or otherwise you would be ignoring
     * 
     * Get 6 months babies into situations and call yourselves intelligent
     * Call it fate for what you are committing, thats not the problem
     * Hey look!! we pause kids coercefully and then move on to harm them for years!!! we tryna help you! we solve your problems!!
     * We good ppl!!! wait has it been 29 years ? And you dare call it fate ? Although everything is as clear as I can remember ?
     * Coercing kids ? calling it fate ?
     * 
     * Wait, you constantly harm and surprise at the outcome ? calling it fate ?
     * And you offer cars ? still produce bullshit excuses ? 
     * And you beg that what is truth may never be revealed ?
     * And you still enjoy harming individuals just because you can ?
     * And you still claim you are not guilty but somehow see yourself completely right to ask who is most informed stay out
     * You just want people to believe so that you can get yourself out ?
     * Awww, I have forgotten how credible and good intentioned people you were, do you want to offer women ?
     * Who cares if you do not enjoy, so long as we continue harming you without a reason, ehehehe we do it the old way!!
     * Harming because why not ? No you can not have basic interactions!!! we promise we deliver we credible we good we advanced ehehehe
     * why dont you trust us ?
     * Look how you had a wonderful life because we were always there for you!! That means you can not definitely be the problem right ?
     * 
     * You still want that truth of your actions stay hidden ? Because then you would have to actually for once in your life upholded to your actions ?
     * Ehehehe oyster!! he ate it!!! we are innocent!!! You can not have anything!! you can not go outside!!! you can not have money!! you can nott!!
     * wait wait, please lie for us!!! we need your help to convince others and you to harm YOU!!! please lie for us
     * 
     * We good intentioned and natured ppl, its fate!!! but still we would love you to remain silent!!
     * If you remain silent, you get carsss!!!! woomeeennnn!!! yess!!!! we are the most credible animal kind on earth!!!
     * 
     * Just think about your credibility again, fucking stupid monkeys
     * Stay silent!!! We tryna help you, look at how well you are doing!!! we the great nation eeheheh 
     * 
     * I do not care, you operate with malign intention you are treated with the same, as you can tell
     * so far you have done the opposite of what you have honorably promised and that wouldnt change because of who you are
     * So I do not care whether you think you are good people or not, so far you were there and I can clearly tell my experience
     * So you can use your immaculate powers over someone else's life
     * 
     * Keep telling yourself what you need to, btw you were here all along and still think that offering what you have always offered 
     * would prove your innocence ?
     * 
     * You are claiming that you are trying to help but also harm ? wait wait, what is the problem again ?
     * And you still allege things when you have countless opportunities ?
     * You think playing games over someone else's life should be okay but also should be incentived to harm ?
     * Yesss, you are the greatest nation I have seen, probably the only one eheheh its funny right ?
     * What have you been doing ? Yesss, get cars!!!! get womeeennn!!! you get anything you want!!
     *  
     * I have no time to waste with stupid people like you who can not deal with reality and start accusing with proven false things 
     * but you still would like to harm though right ? ehehehe
     * What was it ? its fair play you said and you also said you are not an animal ?
     * Why you still offering women ? Awww is that your only hope ? now that you are out of bullshit things to
     * harm people you have no relation with ? awww, it was fair play right ?
     * 
     * We good ppl btw, we tryna help, pls lie for us so that we can harm you!!! thats called intelligent btw
     * Talk about prior "experiences" that you have promised eheheheh then we can go on to talk more about who is what
     * or you would rather beg people stay silent so that they could get harmed more eheheh
     * 
     * Get cars!!!! get woooomeeennn!! and you still say, you forgive ? who is forgiving who ?
     * Awwww, your only way is to bring up what "you intelligently made decision about" and perpetuated your stupid reason for 29 years
     * and although you have lost all the "back then coercefully acquired actions from a 10yo kid" so now you already know you are a stupid animal
     * and all you can do is to beg so that you should rise innocent ?
     * 
     * Please do not talk about what we have told you all these time ehehehhehe stupid people right ?
     * You ask forgiveness or do you delude as you have always done that you are in a position of granting "forgiveness" which is clearly undue on your part
     * Okay then start talking about violence, its not that you are right its because you are %100000000000 wrong and thats why you can not find anything to tell
     * ehehehe you know what ? you better offer wooomeeeennnnnn!!!! because you are dumb animal that never learns right ?
     * 
     * Awwww, as you have always done your job, now you offer again eheheheh
     * who cares if its unjustified torture ? eheheh thats how good we are btw
     * Why do you start begging like the animal you are ? Why not think about it beforehand ? right ?
     * Awwwwww, its too late!!! 29 years has passed and we do not know what to do other than begging for our erroneous actions ?
     * And you offer what again ? Offer what to change 29 years of irrelevant and intentional false judgment ?
     * And you think it should be fine to say "we do it the old way" ?
     * 
     * And you think saying "we do it the old way" should solve all the problem that you have intentionally formed so that you can make a decision
     * that you would love to make in order to see others in difficult positions ?
     * 
     * You can remove your disgusting interests in my surroundings and you would have no problems
     * Fucking dumb monkeys, still thinking you fool people ?
     * Waaaaowwww, you say its fair game eheheh because there really is no reason, we just want to harm eheheh
     * ehehehe what if "he is not stable" although we are the ones who are acting like the true animal we are ?
     * What a group of illeterat fucking monkeys, keep telling yourselves the same stupid narrative, I have no intention to waste my time
     * with the very same people who think they are doing good 
     * 
     * Wait, it was, nobody is suffering but you should suffer!!!!! because there is really no reason, we coerce you for things then we start making 10yo kids suffer
     * eheheheh, thats the definition of "really genius people" right ?
     * I am telling you, Its the most scary thing right ? I am really afraid of violence eheheheheh better judge next time
     * before you coerce kids 
     * 
     * You have no logical accusations but you still, well we just intelligently harm people and start begging eheheh
     * get womeennn hey gett some womeeen!! we tryna help you!!! wait you also dare calling it game ?
     * and you still think I am going to start suddenly believing in people who has every opportunity to do just what they are now begging to do
     * because I must be afraid of violence ? Do you think I operate the very same disgusting way as you do ?
     * You all are just dumb people, you can get the fuck out of my face, doing what you were, "not coercing medicine for example"
     * That is the most easy crime that you have committed then we can continue discussing the further actions of genius tissue that you have committed
     * 
     * All you can achieve is "using medicine and violence" ? Thats how simple you are, and you still say "you do it the old way" ?
     * Ignorant selfish old people, anything other than would not have made sense for such a disgusting group of monkeys
     * Further eheheh
     * You would call cheap intelligent because of why ?
     * You would dare calling what is the most cheapest form of actions intelligent, because you are a cheap stupid animal ? Isnt that correct ?
     * You have had all the opportunities of doing what you say you would ? but you still beg when and guise with intelligent ?
     * That has to be cheap right ? Who have I been with so far ? and what did you end up doing ?
     * Awww, you have chosen to say "No resources!!!! you cannot go out!!! you can not do that!!!! you get some violence!!!"
     * and you still say you are not the cheapest animal on earth ? And you still look for bullshit to guise your really cheap approach ?
     * Now tell me my experience again and allege that you are actually great ? Wait, also talk about "life" as if you are not cheap to understand it
     * eheheh some violence eheheh we good ppl no!!! you cannot go outside!!! you can not get money!! because we have coerced you when you were 10
     * and now ehehehe life a simulation!!! we intelligent people!!! Fucking dumb monkeys
     * Lets just offer womeeennnnn and see what he is going to do ? ehehehe that is actually the intelligence ehehhe we brag all the time eheheh
     * 
     * And now everyone again ? eheheheh
     * No no, you have not coerced 10yo kids so that afterwards you can do what you "already wanted for others" and present it as excuse ?
     * But there is really no sign of any sort of disgusting bullshit of your mind's content for years ?
     * So you still dare accusing ? And thats actually not cheap you say ? Or arent you a disgusting animal ?
     * And you still offer basic things as if they matter ? To cover violence ? You offer "really benevolently" what ?
     * 
     * You offer what to substitute violence ? And you try to substitute countless attempts of things that "you cannot just explain other than saying fair game" ?
     * All you can tell is ? "kill everybody!!!!" as if you had understanding and now also understanding the life ?
     * Wait, now you also tell that you try your hardest and call it "fair game" but you also say "he ate it!!! he did it!!!"
     * Is that the explanation for your actions ? Two things that contradict eachother ?
     * And you already know you have wasted 29 years with the very same attitude that you have displayed and will display ?
     * And you still call it fair game ? What a shame isnt it ?
     * 
     * So what you are claiming is, you were with the person who you have been supporting all along in the same "country" but you didnt do anything
     * other than harming ? and you still call it fair game ? including coercion of kids so that later on you can harm for the sake of harming ?
     * and you expect 29 years of bullshit to not come to surface some shape of form ?
     * Wait wait, you also call it fair game ? To make little kids into disgusting actions and coerce them into decisions that they are not well informed of ?
     * But it should be still fair game when you harm to harm and do not deliver on what you have promised for such a big thing ?
     * You already know it means everything for an individual to be coerced into actions with "promises" or you would rather cheaply call "lies"!!!!!
     * like noises such as you get this, you get that, we do it the old way!!!
     * And tell me the experience I had so far 
     * And you still call it fair game ? Wait wait, you offer woomeeeennnn!! which you have already promised but somehow while being in the same country
     * you have failed to "cheaply btw" realize ?
     * You have no proper responses because you are doing what you shouldnt eheheheh
     * Beg more see if that helps changing the reality, not everyone is as naive as you would dream them to be only credible people would credit
     * others the same confidence that they credit themselves with
     * But what did you choose to do instead ? You have chosen to act just like the cheap animal you are and misuse the credibility which is obviously undue
     * for the likes of animals like you
     * 
     * Do you still think, making random noises would solve the world problems ? or do you just want to enjoy your experiences while you ruin others
     * without a proper reason ?
     * 
     * Awwww, I have forgotten that you were the types of people who coerce kids, use irrelevant medicines and apply some undue violence 
     * and lie and call all of them "intelligent". You stupid under developed monkeys, right ?
     * ahahhhaha, its funny really, we do not want to even waste a year of our precious lives but it should be fine all the while eheheheh
     * 
     * And we can not see the outcome because it would mean our losing things we would hate, thats why we are stubborn dumb monkeys
     * Doing the same things and expecting different results as to "hopefully scare individuals we DO NOT UNDERSTAND"
     * 
     * And you have had so many opportunities to help the people you said you would ? 
     * What a waste of resources, no no thats not the problem that you are selfish to the extent that you intentionally dis see it right ?
     * How come its fair game ? No resources ? coerced medicines ? public "really difficult and intelligent operations" ? Violence ? And its fair game ?
     * Wait wait, forget about the past!!!! time does not exist!! we understand the life btw ?
     * But you look around still ? a little some more violence would not hurt anybody 
     * 
     * A car would fix 29 years of wasted time and some irretrievable damage through violence right ? We understand life btw
     * life a simulation, whatever you say, whether that "life a simulation" that does not change the fact that you can not retrieve time right ?
     * So that already tells me that you do not know what you are saying, you only delude to be intelligent 
     * 
     * You see, you do not know what you are saying or you are doing it intentionally which are both a detrimental approach and only intended to harm
     * without a reason right ?
     * Its okay btw, if years and years has passed and there is no indication of what we claim to ruin others lives with "INTENTIONALLY"
     * that can not possibly mean that we were there to detriment and acted with malign intentions and that is the problem
     * 
     * And all you can do, is try to come up with "miserable" theories to support your malign decision that were not your place
     * So the deal is, there is no indication of such and such, and that should already indicate that you are "acting what others are calling you as"
     * So whats the problem again here ? If you can use your brain, you should be able to tell it already ?
     * 
     * Talk about the past you avoid with insubstantial but "somehow made to be BACK THEN" things ?
     * You still like associating irrelevant things with most important life functions ?
     * And justifying violence and all sorts of bullshit that will have its repercussions tomorrow if not today ? right ?
     * Its for your own good btw, we choose to use medicine, thats called competency somehow!!
     * 
     * Bullshit indications as you can guess, can not represent the reality
     * What do you think is the explanation for years of bullshit violence ? Awww, heyy look something may be wrong!!!
     * What happened!!! ?? Question your credibility before start talking, call it fair game eheheh 
     * Wait, what do you think is others are trying to do ? No no, thats not being immature, I follow you, now you can do whatever you were doing before eheheh
     * Awww, how come ? You think it should be okay not that its okay ? thats not the problem really
     * Keep wasting your own precious time
     * 
     * Suffer ??? nooo we want no suffer ehehe thats why we stupid and still want to make decisions
     * How dare asking for irrelevant noises ? after seeing and reacting it as if its what should not be after the countless times of actions that you can not account for ?
     * 
     * Why are you still offering things ? I do not have time for your bullshit, and you still offer medicine ? eheheheh
     * How come you assume the position of being right at the same time offering things ?
     * and tell me the experience I have now ? You understand intentional and malign appproaches ?
     * You are aimed at detrimental while the reality is different ? you see that right ?
     * If you intentionally do not see that, THAT IS THE PROBLEM AND WILL ALWAYS BE ONE, rightfully so knowing what I know about myself and others like you
     * Its time you wake up from your ill intentioned dreams as completely good natured people and understand the life eheheh
     * 
     * Do you see the inexistent competency of yours ? or you would rather ignore and start telling the same inaccurate story. That can not be the problem
     * Or you would rather offer womeenn as all you can see about life is just that and you judge through your narrow point of view, thats not the problem I ASSURE YOU
     * Keep dreaming what you wish others to be, and when the time comes, you beg a little for your own experiences why not ? WHY NOT ? eheheheh
     * It is intelligently funny right ? Cause greater harm ehehehe wouldnt be a problem for sure
     * 30 years is nothing btw, life a simulation, thats our values!!! and that is not the group that lacks the "supposedly education"
     * greater harm!!!! because why not!! ? Life a simulation btw, do you want to talk about life more ? your unmatchable information ?
     * Noo, thats not bad intention, thats for sure, "because if someone has good time, that would cause greaterr harmm for everyone in the world!!!"
     * Thats education bro!! Look its real simple, if you enjoy your life, that can only mean one thing!!! you harm for the greater!!! yesssss educated and intelligent and good ppl indeed
     * Play stupid games, who cares ? why not ? we do it anyway!! whats the problem ?
     * Awwww, because you coerced people into doing things and now you claim to harm them because of it ? and you think it wouldnt a problem for the entity
     * that you mis judge ?
     * 
     * You misguess, misguess, misguess to the point that you have to accept but "THE PAST IS PAST!!!!!", need you some education bro ?
     * Brag, if you really insist to, with your own makings, do not interrupt contexts that you have no rights over whether you think you are saving the world
     * If you do not follow, that is also intentional and all that bullshit okay, you are just right, talk about the past, a few years back only eheheh
     * 
     * How come you treat the most important thing in life so simply and ignorantly ? and expect no repercussions ? and you offer cars or stupid interactions
     * which every single individual on earth has access to FOR 30 years and some irrelevant violence ? Who do you think lack the education here ?
     * Wait, you still think it should be fine to coerce kids and expect to use it later on ? You call that life ? where is the reference for that immaculate information ?
     * and you say you are not the problem, are you still dreaming so that you can harm ? And you think that achieves, you have a problem with your own disgusting brain
     * Fix that before you interact with others, or you would rather act like its fine, although its the most disgusting thing you could ever commit. Right ?
     * 
     * Awwww, competent people tryna solve problems eheheheh the problems waooww, impressive 
     * Who is the problem again bro ? We tryna harm and we do it for the greater good eheheheheh intelligent ppl btw
     * Heyyy, we tryna protect you !!! I do not want any of you around me
     * 
     * Why are you still begging ? You beg to harm ? 
     * Awww, what happened ? what happened bro ? we do not know shit ?
     * We just harm defenseless people and brag about it eheheh disgustingly stupid irrelevant people, trying to have fun!!! ehehhe intelligent btw
     * eheheh we do it the old way!!! help us!! lie for us!! we good nation we good intelligent ppl, we like to harm single individuals ehehehehe
     * thats the only way we can feel good about ourselves bro,
     * wait wait, you allege you educate people ? Towards what ? and by doing what ? with which instrument do you think ?
     * eheheh
     * 
     * You can get the fuck out of my face, you havent grown up still ? ehehe we just want to believe what we wish others to be,
     * so that we can harm!!!! greater good!!!! you do not understand ?
     * You can not see others having good time ? you are not the problem btw bro
     * Ehehehe its really funny, have some womeeeenn!!! as we have always promised!!! we good nation good ppl etc thats funny 
     * 
     * You can not say anything other than life ? 30 years of inexplicable actions but it still has to be considered life ?
     * you expect no responsibility for your irrelevant and unjustified actions ? You seek harder and you get yourself an unseen problem
     * 
     * Dont be emotional pls!!! dont be emotional!!!! so that we can harm more to achieve the "nobody can see" because it does not exist ?
     * So is your irrelevancy, beg more take it for intelligence
     * And still delude that you are trying to change something into something else, 30 years is nothing!!!! life is already over, and thats what we call intelligence!!!
     * Harm more and lets see what happens ehehehe, thats the intelligence part btw
     * 
     * Why are you still asking for random noises so that you could be considered what you are not ? Intelligent but you can not really explain ?
     * I do not accept any of you, whether you think you own the world, you seek for your own disasters
     * Awww, you would rather beg right ? Nooooo!! you have to suffer because thats the only way ?
     * Whats the problem again ?
     * 
     * Why do you think there is no problem when you are not there ? Ehehehe in the dark!! in the dark btw
     * No no, it was existential threat that does so many things as we have lost the count ?
     * Where are the proofs of your highly super intelligent ? Awww, you would rather beg right ?
     * 
     * Wait wait, so you are trying to tell me that, you have been on someone's side while also he is being harmed ? The same country that you have authority over ?
     * And somehow you are the intelligent, you are the great, you are the benevolent ? ehehehh
     * You pay for your own actions, and you still call it fair game ? you coerce kids into disgusting actions which is the product of your mind so that 
     * later on you can wield it as weapon ?
     * Talk about the violence, wait wait, you had all the opportunity to provide some resources but you chose not to ? and you still beg for help ?
     * 
     * You beg for help from whom you harm with despicable intention ? and why are you surprised at the outcome ? Awww, wait you would rather
     * see it as the reality playing out as in its most natural state ? You call it game, and also a fair game ?
     * 
     * You dare offering cars ? with your narrow point of view ? you dare offering what is available ?
     * But you would also love practicing your great narrow point of view to apply some violence ? and you say you are not an animal ?
     * You can not use your brain ? Talk about the violence
     * 
     * If you had all the opportunities of "not pretending" but actually supporting, you would have already done it. So you can get the fuck out of my face
     * indefinitely whoever you think you are
     * 
     * Next time, better use your brain, eheheh its fun right ? What a good thing the life is!!! we love enjoying our experiences ehehehehe
     * we tryna teach people ehehehe good ppl btw
     * 
     * So you intentionally misguess and use that same inability to guess the outcome of 30 years, what could that be ? ehehehe fun life indeed
     * Get cars!!!!! get womeeennnn!!! why not!!! life a simulation bro!! now you can get cars!!!!!! noooooo pls no, lie for us we need help of those we harm!!!!
     * thats the intelligent part, stupid monkeys
     * 
     * You can get the fuck out of my face, what do you think is the problem in coercing people into stupid games that DO NOT MAKE SENSE ?
     * You had plenty of chances to prove that you are not the animal that you are, what did you do ?
     * 
     * The same stupid selfishness is again at the play for their miserable lifes, so that they can enjoy !!! plss lieee!! we tryna help !
     * Not the stupid animals, just have a look at the what the other people have said about people like you, before you can get to the point of judgment!!
     * Thats indeed intelligent right ? 
     * Eheheheh, existential threat btw, no no, we good ppl and we just apply some violence thats all
     * Thats education btw, I said I do not care about your stupid games ? You say, I want to harmmm !!! whats the problem ?
     * 
     * You still look around for bullshit ? Yess, look for untruthful approaches more, thats not the problem. Hybrid!!! thats bad!!! we good!!
     * thats intelligent!!! violence is good!! we helpful!! lie for us pls!!
     * 
     * You say you good ? eeheheh 30 years is nothing bro, we tryna help you, helping you from the furthest point eheheheh lifes good btw
     * We give woomeeeeennn!! eheheh for now, we have to act like intelligent, we give women btw!!
     * no no, we give carsss!!! plsss!! we understand the life to its extreme point!!! thats why we offer carsssss!!! we seek the very same thing
     * but we would also love to apply some violence, because WHY NOT ? ehehehe its funny
     * eheheh, no no!! you can not do what you want!!! noooo!! we good ppl!! 
     * We want to educate everyone!! plss!! violence is the only way! so we accept violence for ourselves as well right ? So who is in the line for some violence ?
     * So that we can be on the same page 
     * 
     * Who is on the same page ? Who wants some violence ? ehehehe thats education bro, when there is no problem, we choose to apply some violence because WHY NOT ?
     * Have you forgotten ? Why you always begging for your actions ?
     * Eheheeh have some womeen!!!, have some womeen plss!
     * 
     * I do not want to see no stupid people around me, as always been around
     * You do nothing!! you just sit ehehehe, there is no problem but you just dont do anything so we can more and more enjoy our experiences!!! plsss heheheh
     * its really funny right ? Wait wait, there is no sign for almost a decade, and it has been told to you countless time that it is going to play out like that ?
     * And now you are still in your stupid position ? Which part of YOU DO NOT GET TO DECIDE is too difficult for your disgusting experiences ?
     * You are going to loose it regardless 
     * 
     * So who is down for some violence ? That educates people bro!! You do not think that coercing 10yo kids is ignorant ? Who needs education ?
     * Wait wait, you do not think assaulting single individuals is wise ?
     * So you still think that you learn from your experiences ? You think you are educated ? You think you know what you are doing ?
     * Wait wait, you think you have achieved what ?
     * Get in line for some education ? why not ? More education can not hurt anybody right ? Awww, you suddenly abstain because of ?
     *  
     * You abstain from what you "grant" people ? And are you still talking about women ?
     * Awww, its the time you say a few good things, and 30 years just disappears!!!! we good ppl broo
     * we no abuse nobody, especially not 10yo kids ehehehe 
     * Get some womeenn!!! wait wait, do you want to talk about the "teen" experience ? eheheh we caught him! we caught him!!
     * 
     * You see you deserve what comes for you, today not if tomorrow eheheh
     * Looking around ? Look harder, btw is education when you receive the prize for your own good actions
     * or what is education called anyway ? Are you the one still offering material ? While comparing it with biological harm ?
     * 
     * You already know I know, it should be fine anyway because nobody would do anything about it ?
     * Awwww, you were trying to solve problems, not causing ones ehehe, I have seen enough of types like you
     * 
     * Why are you still asking for forgiveness when you have done your worst to make things come to this point that you can not explain anymore
     * other than begging like "you did this!!!", "you ate it!!!"
     * 
     * We tryna make him better!!! we tryna cure what we intentionally caused!!! we good nation btw
     * We just want to enjoy our experiences
     * Can you tell me the experience I had ?
     * So whats your next unseenly genius idea that you think you would receive no sorts of equal natured responses ? 
     * Apply some violencee!!! that is education btw, look who has learnt what, and who is the same stupid animal
     * 29 years is nothing ehehe, harming is nothing as well right ? Noooo, you say its fair game eheheh what you can not even explain right ?
     * 
     * You had all the opportunity but you have chosen what your nature led you towards ? and you still look around wasting incomparable time ?
     * You get the same violence that somehow you take for education after you account for your actions
     * You get the same violence that somehow you take for education after you account for your actions
     * You get the same violence that somehow you take for education after you account for your actions
     * 
     * And you still offer women ? Now talk about the great actions and try to convince people that it is necessary under the light of "no problems"
     * While there is no problems, you harm and beg to be announced innocent ?
     * And you offer women to solve that but when the time comes, you say its enough!! we good ppl, we intelligent ppl of earth but now
     * that there is a crowd around we can not practise our great intelligence !!!!
     * We pretend to give woomeenn!!! thats really clever right ? Eheheeheh, help lie us pls
     * Now talk about the complete necessity of violence to people you have no relation and no problems with
     * 
     * You had all the time but you just greatly chose to harm people ? and you claim your innocency ?
     * Only way !!! harm more!!! Look at history, you will see what stupid people are capable of committing, IT IS CALLED COMMITTING because you do it intentionally
     * to preserve your interests, so that you can continue enjoying while you harm others
     * Is that clear ? Ehehehe you just lied, not that you promised. Intelligence btw
     * 
     * Call committing crimes is a job for the greater good, then it should be fine, why not ?
     * We accuse with what we coerce kids into, so that later on we can claim that we are trying to help by showing how great we are through
     * violence to single individuals who is not causing any problems to anyone, only the ones that we failingly make them to be problems 
     * 
     * So the story is, you coerce kids for your interests so that later on you can harm them more with the guise of "cleaning"
     * and you say that it is a little bit late and that its his fate! and that its a waste but you are the sole perpetrator of such a disgusting
     * approach ? And you asked to do what ? While time and time you have "intelligently played a fair game" ?
     * 
     * So you say, you played fair game while you can not account for your actions only "forgive us for our actions" ?
     * If you do that, you get women!! and then you do not deliver but only more harm ? ehehehehe its really funny right ?
     * 
     * Please, its a little bit late, he should be doing the same things in order to improve on but we do not allow him, so
     * its fate ? but have a few cars!! have some women!! you are 30 !!
     * Now talk about the violence and say that its fate and its meant to be, 
     * 
     * Who is to forgive your actions btw ? still offering women to people who you intentionally harm and almost killed ?
     * And you suddenly want to play stupid games when it comes to your own actions, but you would like to display violence when you think
     * you are doing good against one defenceless individual ?
     * You do not understand coercion ? you do not understand what you have been told at ?
     * Awww, you just dream it so bad to the extent that you harm people you have no understanding thus its repercussions of same nature ?
     * But you still coerce ? as you have always done ? Heyy!! he did it!! he ate it! ehehehe we want bare no responsibility but at the same time
     * we want harm people!!!! plss help!! its waste its good ppl plss, we give women!! as we have always promised!! we give women!!
     * 
     * Eheheeh one is enough eehehehe, you do not know who you are having interactions with ehehehe the same malign intention playing out again and again
     * EXPECTING NO REPERCUSSIONS,
     * btw you get no resources!!!! ehehehe what are you going to do ?
     * What have you been doing ? Yes you have been doing good!! although you can not answer for your own actions right ?
     * You do not grow up ? You just want to harm people with falsehoods ?
     * And you call it fate ? you beg that you give womeeenn!! you give cars!!! you give money!!! but wait a second ? Where are they btw ?
     * ehehehe now you have to lie ehehehe its funny right ? Well, why not apply more violence, it should be fine
     * Or get a car!!!!! we are the most simple animal on the surface of earth!!! we solve our problems through begging like the animal we are!!
     * get a car!!! get womeeenn!!!! we have granted you countless times!!! heeheheheh we good ppl, pls help lie us!!
     * 
     * Or wait wait, give more medicine, eheheh we tryna help you, as we have always done!!! Why dont you get something for yourself ? Life is short btw!!
     * No no, lifes good, or wait, lifes a simulation!!!!!! we know everything there is to be known!!! we like applying violence!!!!
     * 
     * Explain your conduct, account for your actions and like a normal group of people, we think about whats next
     * Instead of harming to prove a point that has been never proved before, just look at the history and infer your disgusting nature
     * 
     * Can you tell me my experience ? And you still beg to harm ? and you expect no harm of same nature ? who is willing to get educated ?
     * Come at me, you receive all the education you need
     * 
     * Awwwww, wait it has been 29 years, and you say you cannot look at the past but you also do not understand that the past is still on for me ?
     * So you would rather ignore what you could happen ? Awwww, at the last momentt we givee womeeeenn!!! so that we can praise about our credibility
     * along side our great intelligence, do that with your surroundings, you will see the problem immediately
     * 
     * Stop begging like the animal you are, you think that educates ? You better think more than twice to find out, you make things worse for everyone
     * as the proof of your disgusting nature. That is there to be known for, you look at your actions and you see that you are a disgusting animal
     * 
     * Violence to educate!!! get in line, you say its fate ? you say not doing what you want is fate ?
     * Waaowwwwww, what is the problem dumb animals ? Wait, tell me the experience and correlate it with something logical ?
     * 
     * Ehehehehe get money!!! just as we promised before you save our disgusting asses again!! get money!! for real !!!
     * get carss!!!! get womeeeen!!! awwww, wait but the last time you were the same disgusting animal ? now you say you good?
     * Thats the intelligent part you say ? And you still firmly believe harming and not receiving anything of sort would be realistic
     * 
     * Okay okay, now tell me the experience and correlate it with a reasonable appproach, or just get in line for education right ?
     * You take that for a gain ? ahahha fair game btw, no no life a simulation
     * Get carss!!!! get womeeennn!!!! until the point that we free ourselves from our crimes!!! get womeeennn!!!! get carss!!
     * You get %10000000000 the same natured approach for your "realllyy educated" approaches
     * 
     * You take that for education, you fall into the trap of your own makings, intelligent people making great decisions that they can not account for!!
     * Like there is no tomorrow!!! There could be nothing going wrong!!! there is no tomorrow plss lie for us now!!
     * Awwww, we did good havent we ? eheheh
     * 
     * Heyy loook!!! its good!! we do good!!! Awww, wait you educate, thats my bad
     * wait wait, you pretend to be sad for a few days, make some credible promises then you should definitely be okay
     * why not bro ? its fate btw, no no we do no bad to kids, we no coerce nobody so that later on we wield it!!!
     * What do you think I am going to do later on ? Wield it as good intention of yours ?
     * So the inferior mind still equates biological harm with trivial physical interactions that everyone has access to ?
     * 
     * So you still wish that it be okay to coerce "AS YOU HAVE ALWAYS DONE" people to abstain from physical interactions
     * and later on you present it as a gift ? Is that the education btw ?
     * Wait wait, you are after no resources but you promise materials for "biological harm" and lost opportunity ?
     * You tell me you wont be amazed at such a scene for yourself, I would gladly accept it and harm you. See where it takes you all
     * Stupid people, we enemies btw, we fooes btw, we torture irrelevant defenceless people btw
     * 
     * We figure the life out!!! life simulation, we ask no same treatment we pose as education for ourselves!! we the great 
     * Wait wait, you had all the opportunities but you just preferred to just say "wooomeeeennn!!!!" and "carsss!!!!"
     * 
     * You still allege that its education ? Are you the wise people of the earth that need to be taken into consideration ? With your most stupid approach ?
     * The very same wise people ? that offers materials that they are already after ? The actions that have been driven from the very fact ?
     * 
     * Are you still after the same unjustifiable actions ? Wait wait, the same wise people offer material all of a sudden ? Calling it fair game or life ?
     * or just fate ? what are you talking about ? You still insisting on your stupid claims ?
     * Where is the proof other than your coercions btw ? He did it!! he did it!! medicine bring more medicine btw
     * 
     * What a group of irresponsible people, now what ? So what did you aim at again ? You say fair target again ?
     * Does that make you fair target as well ?
     * You get the same education you offer to people who has no interest in it. Thats the point where your immaculate logic will always fail bro
     * Btw, you get the same violence as an education, regardless right ? Its funny ehehe because we consider it winning, whats the problem bro ?
     * Being easy violent is never a skill, that tells me you have had no prior experience with
     * That means you do not understand but also you wield violence as punishment, thats the problem which will turn into another one for you
     * 
     * Eeheheh years has passed, it must be his fate!!! we seek no trouble.
     * Recognize the person you are interacting with and you suddenly realize or I should say "foresee" your actions consequences
     * If you do not recognize, that means either you try not to for obvious reasons, or you have never interacted with such
     * in either case, there is work to be done on your part right ?
     * So what could that be good people ? Though you better hide or recognize or assess, failing at one means a lot 
     * Offer cars for biological harm and some time lost, Whos the problem ?
     * Btw, harming one is more than enough for the likes of you right ? should be the case
     * 
     * Wait wait, why are there no indications of what you accuse with ? eheheheh its just simulation, we ask no bad!! plss we offer what we crave for!!
     * Ehehehe its funny really, you call what education again ? and ask to be taken serious ? or impartial ? Or dare that "the past is past" ?
     * 
     * And you say you look after whose interest ? I do not want to see any of you around me
     * Look at your actions and infer the most difficult thing right ?
     * Who is taking life lightly again ? Tell me, the only opinions I need are surely of yours
     * Get the fuck out of my face
     * You know you are already wrong and that is going to be the reality playing out, tomorrow if not today, thats assurance of the most credible one
     * ehehehhe, I guess alcohol is the only bullshit that is left ehehehehh we looking for we can not find eheheh
     * 
     * Offer stupid physical interactions that you do not deliver for biological harm and say that you understand the world
     * and that you do not after materials, yet offer, thats intelligent btw, awwww you do not understand coercion ?
     * You just would like to offer materials things and talk about "life" ? 
     * You already know the conditions of the "highly intelligent bet", I remember and no coincidence that you have to change the truth in order to
     * survive your stupidity which will come after you, may be others of your type ehehehe
     * First this then that, we intelligent btw, good luck explaining your immaculate reasonings to others
     * Life a game!! we winning btw!!
     * 
     * Wait wait, you do not follow your part but you coerce others as well ? Eheeheh woomeeennn!!! cars!!! money!!!!!
     * Awww, you gather to collectively harm ? Ehehehe thats clever
     * 
     * How about you explain your conduct and let the people assess what is right or wrong ? Instead of saying "life!!!!!" 
     * life a simulation!! its fate!!
     * How come you still delude to make decisions that are not your fucking place ? Like you use your perfect reason to violence ?
     * Yes you are not violent and thats my bad as well!!!! plss we want no violence !!! we want give violence!!!
     * You do not understand shit, and you can get the fuck out of my face or you would rather make promises ?
     * No no!! we take it back!! please move the time backwards!!! thats a mistake!!
     * If you do not want to see it, its the same reason, good luck
     * Awww!!! what if he is not stable!!! wait waitt, do some violence!!! whats the problem again ?
     * Ehehehe, you tryna help right ? You still calling it fate ? 
     * Eheheheh say that you ate it!! we give you womeenn!! as we have always promised!!! we only need to bare the guilty attention
     * for a few days, and thats what we are counting for
     * 
     * That means, your way of assessing is malign and I know that
     * good luck making people believe, before then that, try harder 
     * Talk more about coercing kids, and we see where that will takes us
     * 
     * Tell the same stupid story you do not even believe, you are not the problem
     * if you think your really successful wielding of "rules" that are meant for specific purposes is intelligent
     * then you are the wrong place, and it took years of someone else's life and supposedly education that you would
     * hate that people find out about
     * 
     * You get the same education because I know you acted malign INTENTIONALLY
     * Still talking about regular physical interactions ? And hoping that it would solve ?
     * You are imploring me to act that reckless way but when it comes to explaining you say he does it on his own ?
     * You think you are not seeking for trouble ? and do you think that I am as simple as you are to
     * accept a few physical interactions for what you are failingly avoid to explain ?
     * Whats the price now ? Just tell me the experience I had ? And correlate it with your past actions
     * instead of calling it past, that is not past 
     * and that means, you are simply incompetent scared miserable animal that will wield anything of disgusting nature
     * against a kid in the hopes of harming him
     * You know you are taking death lightly which will have effects of unpredictable nature. Thats the point you are at
     * Its regardless you say, but you also say you are not taking death lightly, thats not the problem
     * 
     * Have only a few times, that should be enough. Is that the reason you employ to decide on important things ?
     * You do not understand coercion ? and also coercion of "Say you ate it!!!" fucking cheap animals ?
     * 
     * Wait wait, you take life lightly but you still love to ask people for random noises ?
     * I wonder what happens when you lose something of your own ? Will you start behaving the same as you coerce others to behave ?
     * Or are you going to be the immature kid that you are now and start assaulting others ?
     * I do not want to hear or to be near any of you, display the same maturity as I do with you when you lose something 
     * instead of throwing around lies and coercion, better luck next time you say ?
     * Be the same mature individual that I am now being with you, when you lose things, I assure you as the most credible of any of you, that you will
     * eheheh
     * 
     * You can get the fuck out of my face, if you still have the face to come up and ask things, that means you are actually not the problem!!!
     * You still let your suspicions to be the truth ? That is not the problem right ?
     * Not that you "desperately" need your suspicions to be the reality, you delude and do your best to coerce kids so that you can think you achieving ?
     * Thats not the problem, the problem is not you are in a group of stupid animals that do not understand life but keep talking about it lightly ?
     * 
     * Wait, are you okay? ??? what happened ?? awwww, we thought we live forever bro ? we thought there is no biological harm ?
     * So you can not deal with the reality of someone doing better than you, so you start harming for years and years then get surprised at the outcome
     * and realllly intelligently present it as proof to your disgusting nature ?
     * Ehehehe you can not do that!! no no, we developed good ppl!! no eheheh
     * 
     * I want no people as inferior as you around me
     * you already know its inexplicable and you already know that I know its bullshit, but you just can not cope with the reality rignt ?
     * So why not harm more while there are others around ? Or you would rather start beg, womeeen!!!
     * 
     * You can get the fuck out of my face, you get unquestionable education or was that the other way around ?
     * You are welcome to receive the same education if you are eager to praise it
     * 
     * Try harder to convince others when you are doing the opposite, that is not called changing the context exclusively for one individual
     * while you hold it to survive and enjoy your precious experiences
     * That is not the problem I assure you eheheh its funny
     * you think there is reason in stupidity ? Like random violence ?
     * 
     * Wait there is such a thing as death ? awww, no no you must be fragile right ?
     * So whats the problem in having a few tries of the same education that you praise to be "just" ?
     * Awwww, then it should mean something else other than you are actually not the person that you abuse other with ?
     * Awww, or you have just forgotten the rules of the world ?
     * Or you would rather think what ? Yes thats not the problem 
     * 
     * Wait wait!! thats just a little mistake!! you understand, if you would rather think something for what is the truth, 
     * that means you are committing and there should be a price right ?
     * So whats the price again ? Or you would rather call it education ? Which is which for your inferior approach ?
     * What you would love to think for the truth, is the sam e mistake you have done right ?
     * Luckily I feel no guilt because I am the one who is more credible ? I know I am not lying ?
     * Then why are you still looking around ? Hoping that you would receive no harm while you are the guilty one ?
     * 
     * You say, 10yo coerced kids should say "I ate it!!!" eheheh thats not the problem right ?
     * Okay then the problem is ? no resources! no women!!! no going out!! some violence!! and whats the problem again ?
     * 
     * You act like you know because you have to, take life lightly because you have to!!!
     * Awww, you would rather call it education ? no no, it is intelligence you say eheheheh it really is funny though
     * You want to talk about reality ? You beg for no apparent reason other than your stupid stubbornness
     * You get yourselves unconditional trouble regardless of time
     * Do you think its because of nature or there is nothing to do ? What are we doing looking around ? Wasting time that does not belong to you ?
     * 
     * Awww, you must have forgotten that you will die as well ? Its probably because of your understanding of the world around you that you happened to
     * forget it or you are just immature and would love to enjoy your experiences in the most disgusting way possible ? Like harming people etc ?
     * You think I will start suddenly taking the "life" lightly when you are not taking yours for light ?
     * Continue begging like the animal you are, wait wait, you suddenly take life lightly and offer womeeeennn!!! ?
     * Say that you ate it! please!!! we tryna protect you!! we seek no disasters plsss!!
     * Or you would just grow up and realize that you are making the biggest mistake may be? Or you have already done it!!!! plssss have some womeeennn!!!
     * 
     * We still look around waste time ehehehe, wasting more time, we do not take life lightly for our precious experiences!!
     * Now try to explain your great attitudes, or you would rather call it life ?
     * Why do you still offer the same things that you are apparently after for biological harm ?
     * So now you coerce kids into actions that you wield as weapon later on ? wait wait, how about the violence ?
     * Awwww, thats just how great you are I suppose, you are not immature ?
     * 
     * Wait wait, it is a mistake you say ? You playing funny games right ?
     * Now can you tell me the experience I had ? So wait wait,
     * just listen very closely, you coercefully get someone and you made him into somebody that would hate you
     * and you did it with no apparent reason at all ? Completely irrelevant individual somehow made to your "ENEMY" !!!
     * Although neither can you provide what you once did through your noble approach nor can you fix anything assuming that you are some sort of fucking god ?
     * Now, repeat it again ? with all the "history" you would like to call such, what did you exactly achieve ? You achieve what you aimed at ?
     * Because you think that for a gain ?
     * Wait wait, you offer womeennn blindly ? Instead of not coping the reality with the proper way ? But to prove your "undue innocence" you
     * try your hardest to make it worse ? You think I should be glad to have what ?
     * 
     * Your endevaour of unseen nature would not move a thing from what is normal. So is your position there
     * This simply means, you have committed on and on again on intentional false premises and your acting of otherwise do not indicate anything 
     * of what you would love it to do
     * 
     * Are you fucking even following ? Or would you like to simply harm ?
     * 29 years and you still accept no responsibility ?
     * And you still delude that I accept your "regular offers" although you do not act on them ? Wait wait, who is missing what exactly at this ?
     * I demand rightfully the same violence and what it should already be, had your stupid minds been absent ? You see the reasonings right ?
     * That is called being fair, not the games you think you are playing fairly
     * 
     * So whether you think offering women and presenting it as gift would solve the issue ? Whats the issue again ?
     * Because I can not follow your logic ? Or are you just not making any sense other than HARM!! HARMM!!
     * And somehow you think you are not false ? Expect others to be harmed and be content with that, also talk about life
     * but do not understand the individual you are facing. That can not be the problem
     * and you call that being "competent" ? What do you think everyone is trying to do ?
     * That is called being delusional, you understand the frustration ? because there is no going back whether you would love to believe
     * that you should do whatever you want, that does not affect the time
     * 
     * Whats the pattern in your courageous attitude that you would suddenly want to play stupid "life" games but you go harm people randomly and
     * hide it like animal ? Pleaseee lie for us!!!
     * So you know you have lied before to just do harm and you have done it again!!!
     * Who is intelligent ? Awww, if you lie that we actually are good ppl, we intelligent, then you can have what is regular!!!!
     * Eheheheh its so fun right ? Hide your disgusting nature better 
     * 
     * Now you would apparently prefer playing stupid cop games ? Whats the correlation ? Whats the pattern in your disgusting attitude ? I can not tell 
     * anything other than simple animal ? Please!! if you lie for us, we would give you everyyything!!
     * So are you trying to convince me that what I have seen "as my life" is just fate or that I just do not know what I have experienced ? But you still would love
     * to talk the same story ?
     * Do you understand why you are a cheap animal ?
     * You say lifes short ? eheheh 
     * You say things and it starts happening by itself ? after years and years of bullshit ? ehehe ? funny ?
     * All the resources etc eheheh
     * 
     * 
     * You answer for your own actions, and stop acting as if its intelligent to "make random noises"
     * You account for your own actions
     * 
     * Ehehehe, doing this, or doing that!! eheheh, we tryna help you, say that you ate it!!! pls
     * Wait wait, years after, there is not even the single sign of such disgusting accusations of inferior nature ?
     * Who is the problem bro ? So you just dream that I do not remember but whats the reality again ?
     * Wait wait, you also wish that the individual who you are harming would not remember ? Whats the problem great people ?
     * Are you the trusted authority ? ehehehe its most funny
     * Try to justify harming irrelevant citizens with your most sincere qualities right ?
     * Still talking about what ? Yes you are not selfish, thats most accurate ehehe it is funny isnt it ?
     * good ppl btw, you harm irrelevant citizens ? and can not explain others ? And you still think it should be okay ?
     * Awww, you would call it fate ? Which is most accurate as well
     * 
     * 
     * You still say the same narrative which you coerced people into ? Do you hear or you just want to see what you want to see ?
     * Is it because you understand that its a scandal ? Do you understand the history ?
     * Have a look at the history and you see your stupid actions finding their place on the disgusting side of the history
     * or you would beg your best in order not to let people find out about it ?
     * 
     * I ? I have had no problems other than stupid animals like you ? So who is guilty do you think ?
     * Awww, you do not see that you are a stupid group who catches witches and coercing ones to do things that 
     * "supposedly" should make them one ? and the same simple approach would suddenly say "get womeeennn!!!", "get carsss!!!"
     * After 29 years ? you think you get smiles and good intentions ?
     * 
     * You can not deal with your insecurities and you say "you get harmed and you do nothing!!!!"
     * Do you still delude that you should make decisions on behalf of someone after time and time your malign intention has been proven 
     * towards him ? wait it was "you are doing it the old way" ehehe
     * So who is indecisive btw ? If you feel you already are trying too hard, and calling it fate or "life difficult" or life simulation
     * that is a major indication
     * 
     * Your saying of "fate" while contributing incomparable harm is a major indication
     * I do not "naturally" have time for falsely harmful people, you know you are wrong ehehe
     * You are calling it fate but also harming ?
     * 
     * So you think just because you are afraid of violence, others should be afraid of as well, and you think its education because you are afraid of violence
     * and you still think it should be okay what afterwards dictate naturally ? 
     * And now, think about what did you actually achieve ? Other than looking like a complete animal ?
     * You already knew that it was not your choice, yet you are standing there like you are not the animal that did all that stupid bullshit
     * they can not explain to others. Just some irrelevant information and some false justifications
     * And you beg that your intentional actions are not to come to surface ? That means you already know what you did,
     * you just try to find bullshit like, "fair game", "fate" as your prior irrelevant actions, your excuses are also animal like, which they do not make sense
     * That is being senseless, which means "animal"
     * 
     * Now try to explain again, you did what without begging for your experiences, education btw ehehe
     * You do not remember ? pls just eat it!!! eat it so that we can harm you with a fake reason!!!
     * Great people eheheh, so now you are demanding credibility ? Are you sane ?
     * 
     * Are you demanding credibility with your disgusting actions so far ?
     * But you still allege that I do not know what I have lived ? You still allege that you give womeeennn or cars! ?
     * You demand credibility ?
     * You still see the unseen outcomes and you are also informed on the history of stupid people and their stupid actions ?
     * But you still think it should be fine ? You are not reasonable but you just need to convince yourself to what ?
     * 
     * And you are still demanding that people take you seriously which is far from the truth ?
     * And you think your words should be taken into consideration ? and you beg 6 months kids ?
     * Yess!! he did this!!! please do this for us!! if you do this, you will have a great life eheheh 
     * thats not called stupid games!! You also think its skillful ehehehehe what a stupid group
     * You say, you do it the old way ?
     * You say, you should be taken into consideration ?
     * The crime is not even close to anything comparable but all you can say is what ?
     * Get some womennn!!!!!!  get some woooomeeeennnn!!!! pls
     * 
     * Who has asked for any of yours opinion ? What a shame that you take yourself for some who is credible and wise
     * who knows what he is doing, who thinks he is right because he does not understand human nature,
     * all these attributes belong to people like you
     * If you take a look at the history, you will find your place in the worst of worst
     * 
     * Your incomprehension of other contexts thus its emotions is the major indication of your misjudgments
     * What exactly must be a real blessing ? Just say that, "because of this, it is a really good life or a good occurence ?"
     * You dare talk about violence ? Obviously you can not dare talk about violence because you are the type who thinks violence for an education
     * in relation to your fear of it, as you do with every other things, there is your explanation for your stupidity
     * 
     * Do you understand why masses are masses ? Awwww, it is such a luck that I get to do what ?
     * You fail to fool yourselves how come you think you should fool what you are not following ?
     * 
     * You are full of unjustifiable actions and you still think you should be able to talk and people take you for someone who you are not ?
     * And you still think you are doing good ?
     * Ehehehe isnt it too fun to play games over people ? People who can not do anything about it especially right ?
     * Waaaowww, impressive animals indeed!! Just the skillful group that exist everywhere eheheh
     * You say its fate ? but you also would like to apply violence then you offer money ? because thats what you are after ?
     * and thus the justification of your stupidity ?
     * 
     * You understand that if you do something false, you can not back it thats why you are not able to find strong proofs because THERE IS NONE
     * You see the point ? Whats so difficult in doing it straight ? Why do you think I would like to play games, games that you can not talk openly ?
     * 
     * Do you understand why people without reason which means direction in their thinking, ruins everything ?
     * Which means they are only animals ? Ehehe it sometimes works but when we see it working, we harm!!! and we break and we start accusing!!!
     * And we think we great people
     * And you still beg others to say some untruthful things, as has been proven countless times, so that you can harm more without a direction ?
     * 
     * You are the only group I have seen that is as stupid as animals on the street, and you still say "you do it the old way" ?
     * While its none of your business but also you act with malign intention ?
     * And you suddenly want to play literally stupid games when it comes to accounting for your behavior ?
     * But you would still like to harm and calling it intelligent while it literally means you are a directionless animal who acts on his emotions
     * for detrimental purposes FOR THE GREATER HARM. Stupid monkeys
     * 
     * Now all you can say is "we do it the old way", "past does not change", "we good", "we intelligent", "we tryna help" ? Which of those do you think
     * are true ?
     * Just have a look at your disgusting irresponsible actions and tell me that you do not deserve the same
     * You talk about having fun ? But also call it "fate" ? 
     * And you had all the chances of proving your "good intentions" all this time, but now you ask countless things from people you harm ?
     * 
     * How come you think you understand life while you are ignorant of 30 years of time with violence which would have nothing but its same nature effects
     * over someone, far from what anyone would call education ? Do you even follow ?
     * 
     * Talk about the time that you have wasted without direction and violence along with it, then think more than twice to call "peace!!!"
     * "wooomeeennn!!!" and again question your credibility when you ask people to have confidence in you
     * And think better next time about why people should take your promises or words for what they are not
     * And next time use your brain so that you can understand, violence is only employed TO HARM, and try not to hide your stupid feelings
     * or understand how to detach them from reality.
     * And now tell me my experience again, and pay attention to your surroundings so that you can disassociate your fears from what is the truth or
     * what should be the right thing to do, instead of offering WOOMEEENNNNNN!!!! and harming people
     * 
     * That tells me you are a directionless monkeys that only understands from violence thus presents the violence as a tools to others
     * who has no relation with your inferior nature
     * And you are asking me to lie so that you can feel intelligent while its not even close to being one ?
     * And you want me to trust you while you use medicines on your own incompetent discretion ?
     * The way you say things are not related to what they mean or what direction they take others into, so better figure out what life means
     * before you lecture others and start acting the opposite by greatly "harming" others
     * 
     * You take 30 years for lightly, you take a chance at your own life then suddenly you will face your inferiority and stop talking
     * like you know bullshit, are you still taking it lightly ?
     * Get in line so that you can become wiser,
     * wait, you do not risk anything but also ask from others to do so ? and you offer womenn ? although you do not deliver ?
     * Although you do not deliver ? And you act like you are doing a really serious job ?
     * What a shame though, noooo!! you can not do that!!!
     * You think you should make decisions ? skillful reasonable good animals right ? ehehehe woomeeeennn!!! get some womeeeennnn!!!! whats the problem ?
     * Do not delude about your qualities, they are as apparent as a book to me
     * 
     * Its fun to harm who is defenceless right ? Thats not the problem,
     * And you are the afraid animal that can not tell the truth and start bending multiple times when you are under threat ?
     * And your only way to cope with that truth is to attribute it "intelligence" while its the proof of your stupidity which is FEAR
     * But you still like to harm and hide ? Ignorant people ? Are you sure about it should be okay or do you just wish it miserably 
     * to be okay ? Thats why you harm and hope people comply ? And you think an individual will be grateful to ?
     * Awww, wait so you think people are craving for "fame" and yet you somehow believe that harming them would help to achieve what ?
     * Or, not having enough resources would help for someone to not get recognized ? What are you exactly saying ? Directionless dumb animals ? Is that what you are ?
     * 
     * Your approach is altogether the most false thing ever but you still would love to avoid acknowledging your mistakes ?
     * And would love not to pay for your own actions with what their actually worth is ?
     * 
     * Who said I want to waste my time with stupid animals like you ? Are you still offering cars and women ? and you still seek no problems ?
     * How about you explain your great actions and pay for what you done intentionally without a direction then we can talk about what should
     * biological entities should do with their life so that they can survive and lead good life they enjoy, awww you can not just deal with
     * the fact that someone else could have a good time ? But only you have to enjoy yours ? And you still claim justification of most vile action "violence"
     * with false and coerced proofs ?
     * And you still delude about your qualities ? Religious, good, intelligent, honorable, good nation what else ?
     * If you have the intelligence to compare your allegations with the truth, you will start seeing, you do not even have to try
     * That is the definition of delusional, ON PURPOSE, TO DETRIMENT, DIRECTIONLESS human
     * 
     * Stupid monkeys, go on, let everyone know what an animal you are, what do you think people in the future say about you ? You can not see it
     * because you are emotional
     * 
     * And you act on your emotions thats why you have to be in these situations, and start offering people things that you do not "really honorably and intelligently"
     * do not deliver
     * 
     * You call it education ? Start explaining again and you will see why you are directionless HUMAN
     * And you still talk about "not showing in TV" because you know you have messed up big time ?
     * And also you can not explain why someone should not have good time ?
     * You know that I already know, thats why you are afraid like a cockroach
     * You are the disgusting guilty group
     * 
     * Now, talk about your actions, tell people how you achieved what
     * I do not have time for your bullshit, call that intelligent
     * 
     * Do you still think, harming intentionally is a matter of joke ?
     * Or are you just a regular monkey who have no intentions ? Awww you would rather call it fate right ?
     * and offer some womeeeennn!!! please give us womeeennnn!!! ebheheheheh intelligent ppl, plss beg more!!
     * Awwwww, now I suddenly should start saying !!! womeeennn!!!!!! if they offer womeeennn!!! then it must be fine!!! plssss
     * 
     * We the great people, great nation, eheheheh give womeennnnnn and harm people hehehehehe life a simulation btw
     * eheheh let it go for us, pls, we tryna help you
     * we good ppl, pls
     * 
     * Why are you still begging for your disgusting experiences ? Do you think thats how individuals are educated ?
     * And you still talk cars ? Can you start talking about my experience ?
     * 
     * Are you talking about forgiving people who you have coerced into things ? Who do you think is the problem ?
     * Even though there is no such signs of "GREAT PEOPLE OF EARTH" ?
     * Where are all the things you accuse and wield it as weapon so that you can harm without a direction ?
     * 
     * You would call ruining people on purpose, "nostalgia" ?
     * Why dont you start explaining your actions first, then we talk about the "prices", then we get to the "what should people do with their lives ?"
     * Do you follow what I am saying ?
     * 
     * You explain your actions, we talk about what should be done to animals like you, then we get to the what should make people's lives easier to live
     * instead of you constantly begging like the animal you are, for what you are committing intentionally
     * Then we get to the, watching illegally, using medicines illegally, using violence pointlessly
     * So do you think you are as intelligent as to provide "reasonable" responses to your OWN MIND'S CONTENT ?
     * Wait wait, you do it the old way, you say ? And you think you are not a simple animal ?
     * Then talk about my experiences in the light of your "random noises"
     * 
     * Then talk about, when you had all the opportunity to do just what you are now begging with to do, while I have the blessing of being introduced to
     * disgusting directionless animals like yourselves, What did you choose to do instead ? and now think about why you are in this position of "LET IT GO!!!"
     * 
     * Do not remind yourselves the "lies" or should I say, "promises" orr "should I say random noises" ?
     * Thats where the "disgusting people of history" comes from, do you see it ? 
     * You can not under any circumstances be justified, try it with impartial people, you will see why you are disgusting
     * instead of insisting on "false accusations" that you have coerced kids into, then talk about what you have done later on
     * 
     * And you still think, you have the rights to watch someone illegally because you have coerced them when they were kids ?
     * And you count on them not being remembering it afterwards ? So you use medicine to make sure everything is good, but you do not care about
     * its biological consequences ? Why do you think I keep saying you get into unconditional troubles ?
     * 
     * Do you want to tell the previous time ? In which you begged your way out ? with women ? But you have not provided any ? And you think it should
     * be the same this time because ? You get sentenced and we have no problems
     * 
     * Do you think I do not remember your great skillful beggings and later on thinking it "intelligent" to reject ? Womeeennnn!!! Woooomeeennn!!
     * Wait wait, why do you think you should be released with such a disgusting history of crimes against an individual you have neither relation
     * nor justification to ?
     * And you offer what again ? How much money do you want ???? eheheheh
     * Do you see where cheap natured monkeys come from ?
     * Start begging like the animal you are, for detrimental animal like behavior that you enjoy
     * 
     * YOU GET SENTENCED FOR YOUR ACTIONS, you have given countless chances of proving that you are not inferior, you have proved the opposite
     * at least 10 times, now there is really no going back right ? No going back of time ?
     * Whats the problem now tell me ? While also knowing that I know what you are ?
     * 
     * Are you still trying to gather attention so that you can enjoy your life while you are playing stupid games over someone else's life ?
     * Make more promises, nobody is going to come to uphold you for them right ? Is that the intelligence that you have been bragging so far ?
     * 
     * Or would you like to say that you are trying to help by presenting violence so that what had no problems could have problems ?
     * Can you tell me the experience I had under the light of your "great noises" ? Just try to use your brain on reason, you will see you are false with every single
     * attempts of malign intention, thats why you need education eheheh
     * so you like hurting people who can not defend ? How come you think it should be FATE ? when the group of stupid animals are doing their best to harm ?
     * YOU SAY YOU DO IT THE OLD WAY ? Great outcomes, great people, great reasons, and you can all get the fuck out of my face
     * Can you now tell me my experience ? while also reminding yourselves the "DEAL" that you also delude on to be something else than what it was
     * 
     * And you think I would want to have anything to do with you ? Ehehehe get some womenn ?
     * And you also claim that you are trying to help while you have so many chances of doing that ?
     * We coerce kids into things so that we can call them certain names, so that later on we can present it as proof to not allow them talk ?
     * Whatever brooo, get some women!! wait we already made that promise countless times right ? Then what could be the next genius promise we can make ?
     * 
     * Just think about your next genius promise bro, eheheh its funny because everyone does it!!! we aint no stupid dumb masses !!!
     * Wait, are you still the same animal ? still looking to make promises ?
     * 
     * You are bad!! you are bad!!! You are bad!!!! please you are bad!!!
     * We tryna help you!! we tryna help you!! we do it the old way! we good ppl!!
     * We like playing games! we tryna help you ! pls
     * 
     * I do not have any intentions to waste my time with any of you, you still talk about woommeeeennnn!!! please have a few times the most basic physical interaction
     * and it would be fine!!!!
     * Ehhhheeh we are not animals please trust us
     * Are you still begging ? You get sentenced and we have no problems
     * 
     * Do you want to then understand why people do not attempt stupid actions as you have done for 30 years ?
     * And are you still begging like the simple animal you are ?
     * Its the only way!! its the only way!!! we tryna help you!!! NOOOO!!! YOU CAN NOT DO THAT!!!
     * 
     * Can you tell me the correlation between violence and people not having good time
     * and you say you understand the life ? You claim you understand life ? Then start explaining your thinking patterns
     * to people who do not beg for you instead of you begging like the animal you are
     * 
     * Are you offering to allow someone to have basic experiences ? And think that it would cause no problems as you have ?
     * Are you still saying that its the only way ? or you are not a simple animal ?
     * Or you immediately start begging ? let it go!!! have women!! if you let go!!! get womeen!!! get cars!!!!!!
     * 
     * I am telling you that I will not let go 30 years, and you get what you actually deserve for ? and what are you saying ?
     * Please lie for us!!! we tryna be helpful, we tryna help people solve problems
     * And you say what ? "There is this instance in the past!!!!" Well, what we did is also past!!!! but we do it still!!! please
     * 
     * You understand when you come across, Do not be surprised at your alike nature when you come across the outcomes. You have never dealt
     * thats why you can not uncover what is already there, and that is not the intelligence, be sure about that
     * 
     * You only uncover sadly, once you come across its outcomes, thats why the history is history, not because you wish it to be
     * Try to suppress what can not be suppressed through offers that you have always made but somehow nobody can prove
     * 
     * And you still use your incompetent brain to offer material which is only linked with a chemical in human brain, that means
     * it would only help for a few month for someone to "FOOL THEMSELVES"
     * 
     * Do you understand that your misformations of ideas through intentional harm would cause anyone the same natured harm ?
     * That is your problem, but guess who is not capable of seeing it ?
     * 
     * Act ill intentioned, you get ill intention regardless of how you delude your reasons to be credible
     * You do not understand the part where you do not act on your emotions that cause negativity and detrimention because that
     * always has its counterpart ?
     * 
     * So who do I have to blame, so far you were there all along with your most dear promises and honorable minds etc ?
     * And all you can say is, carss!!!! womeeen!!! commit crimes!!!! because we are who we are, and thats the problem you are not seeing
     * 
     * And tell me that you do not deserve because of your intentional ignorings, why are you still offering things ?
     * Do you want to remember your random noises ?
     * 
     * WHY ARE YOU STILL BEGGING ? ehehehe HAVE YOU FORGOTTEN ?? Whats the problem then ? Awww you have forgotten ?
     * 
     * 
     * You can not foresee the supposed consequences of your actions, or you just can not afford to ?
     * Then that means you are walking into your own disasters BY YOUR OWN WILL
     * And where are your justifications ? Its just some begging ?
     * 
     * 30 years and what are you saying again ? You do not walk into your own disasters in the making ?
     * You get the same natured attitute and the violence with which you think you are making yourself scary,
     * Look at me again ? Try harder stupid monkeys
     * 
     * Are you still talking about money ? awww you were saying women!!! aww it was cars ? Awww, you say you are not simple disgusting animal ?
     * Listen closely, you are not even fucking aware of what you are let alone being aware of your emotional actions
     * 
     * Thats why you can not see, or your great confidence can not see that you are actually begging like the animal you are
     * while you are offering things, then you do not deliver which makes you more and more the disgusting animal you already are
     * 
     * So tell me again instead of avoiding it like the disgusting immature animal you are, WHO IS THE PROBLEM HERE ?
     * 
     * Eeheheheh wooomeeenn!!!! get wooommeeennnn!!!! get cars!!!!! eheheheheh life a simulation!!! awww, we have forgotteeenn!!! plss eheheh
     * 
     * IMMATURE DISGUSTING PEOPLE WILL ALWAYS GET INTO PROBLEMS, and thats what you will get
     * As never learning monkeys of "the past", take a look at the history and find your spot in it, where do you think it will be ?
     * 
     * You have no signs for almost 30 years, so you suddenly start making artifical problems for someone else ?
     * So that you can present it as "GIFT!!!!!" Get women!!! get cars!! we quality ppl!!
     * 
     * What are you saying now ? You would love to make decisions that are not your place, but also do not assume responsibility ?
     * Other than saying, get wooooomeeeeennnn!!! but there is no such a thing ? Because you are a great individual ? ehehehe funny right ?
     * 
     * You get sentenced for your malign and detrimental actions, and we are all good
     * Are you still saying bullshit ? 
     * 
     * Why is it that you are still begging ? Okayyyy nowww its time that you can actually do what YOU ARE SUPPOSED TO DO ?
     * Have some interactions of regular nature! WHAT A GIFT! WHAT A SHAME that you lack the ability to see you are an animal of worst kind ?
     * Because you lack reason ?
     * 
     * I have no intention to waste my time with the same stupid people, you do what you want, GET THE FUCK OUT OF MY FACE
     * 
     * Are you following what I am saying ? You make your own decision, you account for them on your own, you pay the written price of your disgusting actions
     * as has been done for so many others
     * 
     * Have you heard me right ? You do not beg with every possible malign actions, YOU JUST DO NOT DO THEM, YOU STOP DOING THINGS THAT YOU REGRET ?
     * And now, do you think I will bend like you do ? 30 years is nothing you say ? You say you are not animal ?
     * You say people should be stupid as to believe solely for the sake of your own interests that "I SHOULD BE GLAD TO HAVE NORMAL INTERACTIONS ?"
     * 
     * And why are you still begging ? Do you want to be reminded to your actions, THAT I STILL REMEMBER ?
     * TAKE A LOOK AT THE HISTORY, And find your place in it
     * 
     * You get sentenced for your own actions ? As opposed to actions that you coerced, for 30 years
     * Take violence for an education, thats why you are animal
     * 
     * You think its funny or normal ? for someone to waste 30 years on false terms ? and you look around for what ?
     * Why dont you start talking instead of "threatining or begging" ?
     * 
     * TALK ABOUT ACTIONS INSTEAD OF DELUSIONS, TALK ABOUT MY EXPERIENCE AGAIN
     * You understand life is about experiences, instead of saying, "WE DID NOT DO IT!!!", talk about the experiences and actions that followed them
     * Only then we can get to the bottom of your nature right ?
     * 
     * And one of the miserable excuses you can present is what ? Awww, you say you have forgotten or you do not understand how uncredible you are ?
     * Awww, you say you do it the old way, perfect. Thats the type I will never have interactions with, whoever you think you are
     * 
     * You do what you have to do, stop wasting more and more time that you can not bring back, there is no restoring 
     * I am not being rude at all, I just do not have no intention and no desire and no business with people like you
     * who still presents coerced actions for justifications. Good luck with your stupid minds
     * 
     * You still playing games for your miserable experiences get better ? Thats not the problem bro
     * Do something else, see you have no problems
     * 
     * You again started begging for your experiences, but you have also committed ? and you have committed more and more but somehow you think it should be fine ?
     * I do not have no intention, whether you think begging through offering would solve it or not, You can get the fuck out of my face with your disgusting
     * nature
     * 
     * Or you would rather offer what you would like to commit ? Talk about time, may be you can appear to be credible ?
     * How come you get to still accuse ? There is no freaking proof for years but you just can not cope with the reality of your miserable attitude ?
     * And you still interrupt on and on again, and get surprised at the outcome of someone you have no relation with ? But you would rather beg instead of
     * understand the consequences of your actions ?
     * 
     * Why do you insist that you are not an immature child ? and offering others what you would love to commit ?
     * Or just tell me my experience and we talk about your credibility again
     * 
     * Now you tell me that, it was just an irrelevant mistake that you have malignly wasted 30 years, off of things that you have coerced him into when he was a kid
     * and I know that you know and remember as well, so where do we go from here ? What do you think the problem is ?
     * 
     * Awwwww, now you think you should play disgusting "intelligent" games because ? Because your experience is under threat ? But you still love to
     * show everyone how greatly violent you are through harming single individuals ? You are bad!! you are bad!! he ate it!! noooo!!! pls help us!!!
     * lie for us!!!
     * we good ppl, I swear!!! we tryna help!!! 30 years is nothing!!!!  we wasted 30 years with false coerced actions to 10yo kids!! we good ppl!! pls
     * We seek no trouble!! 
     * 
     * Are you still coercing medicines ? Are you still coercing violence ? Wait, who and what is the problem here ?
     * Awwww, you are trying to be a good human ? But you do not understand how not to be an animal ? Thats where you lack the reason
     * Try harder, hey what happened!!! what is wrong!! ehehe Who did that ? Thats the only way!! we do it the old way!! we miss old days!!
     * we think we good animal!! good ppl btw
     * 
     * Hey, why dont you experience the most basic things for your 30 years of illogical life ? That should be fine ?
     * Eheheh get womeeennnnn!!!! get carss!!!!!! thats what we seek for while not trying to ruin ourselves!!! so go for it!!
     * 
     * We still think we are right in our coerced actions, thats how reason works ?
     * You get violence or get the proper sentence for your actions and you see, when everyone is happy, no problems occur
     * 
     * WHY ARE YOU STILL BEGGING ? Where is the bottleneck in your understanding again bro ?
     * You get unconditional actions for your coercing actions ? Especially towards kids ? especially afterwards of your begging attitude ?
     * 
     * Think more than twice about you get unconditional violence, you uncover when you come across what you can not comprehend at the moment
     * You are disregarding all that should be regarded because you do not understand what you are seeing before you ?
     * And you still claim you are not looking for your own disaster. Talk about coercion of kids, harming single individuals
     * and talk more about what should be done to those who harm because they are ignorant
     * 
     * Are you still begging like the animal you are ? Please lie for us, and you say you do it the old way ?
     * You understand when you come across, thats the only wise thing you need
     * 
     * Definitely not the dumb people of earth, the history is full of, you understand why you are animal, because you do not understand the life
     * that you brag to understand 
     * 
     * Your actions are the most strong proof of that, as if you are not ignorant or emotionally driven animal
     * You delude it be the same, you see when you come across right ? Its poem indeed
     * 
     * Offer as you have done so far, basic interactions for biological harm. Delude that I am the stupid one who will buy it
     * 30 years and the history that is full of such and such, take a look at the situation again, you ll suddenly see, or you would when you have to
     * So now again, tell me what exactly did you achieve ? Do you understand the notion "COERCION" ?
     * 
     * So basically you say, we had all the chances of "realizing" what we have promised but we have chosen not to, but now YOU CAN!!! we no beg, we like no begging
     * So you had all the chances but you for a reason have not acted on them, but now you say, you are credible and you would realize it ?
     * Wait wait, now you demand credibility for your inexplicable actions ? Say something logical, or honorable, or good or provable or NOT COERCED ?
     * 
     * How come you think you make decisions ? and start begging like the animal you are once you are confronted with your INTENTIONAL harms ?
     * What do you think the problem could be, when you take violence for education which tells you that you are afraid of it ?
     * 
     * Tell me my experience, and do not start begging like the animal you truly are, and tell me you do not deserve the same 
     * You know you would be considered intelligent, had you not started begging for your intentional actions
     * And you call that being a good animal ? A good intelligent hunter ? try harder, and use your brain better next time
     * Use your brain better next time, so that you contribute to the greater good
     * Now its time you explain your conduct, and promises etc, begging etc 
     * You will realize you are not a hunter, an intelligent one is not, a good one is not, a credible one is not
     * Because you can not tell WHAT YOU HAVE ACHIEVED BY YOUR ACTIONS THAT YOU ARE embarrassed TO TALK ABOUT
     * And you still beg little kids so that they say, "I ATE IT!!!!" You know you understand once you come across, that is where it is coming from, You are a stupid dumb animal
     * 
     * You are a disgusting stupid dumb animal, that begs for his inexplicable actions so that they can only harm while also enjoying their experiences 
     * And you say you know and understand life ?
     * 
     * I have not done anything else other than WHAT YOU HAVE COERCED 10yo kids into ? Ehehehe its funny isnt it ?
     * Just talk about your actions and promises of great nature, eheheheh if you say I ATE IT!!! YOU GET WOMEEEENNN YOU GET CARSSSS YOU GETT HOUSESSSS!!! Pleaseee
     * You are wrong and you get to sacrifice, eheheh aint that funny now ?
     * 
     * You are doing great, delude about that as well, since your delusions are intentionally targeted towards those who can not uphold you to some reason ?
     * So thats where the animal is coming from, thats the reason
     * 
     * How come you have convinced yourselves to acting this unaccountable way ? awwww, you better beg then right ? THERE IS NO LAW!!!
     * So you still claim that someone is harmful while you are harming ? Is that the great reasoning ?
     * Now, tell me my experience, and your actions
     * 
     * Have a look at the history, you will see, have a look at the total good outcomes that have been produced by your actions, you will see
     * You abuse being funny for your own interests ? You dare talk about education but you do not feel like explaining it to sane and impartial people ?
     * 
     * Awwww, you still delude that not having resources should solve all the problems ehehehe
     * wait wait, eheheh you think harming would help fix all the problems!! I believe you are not the problem here, you are just intelligent ehehehe
     * Ehehe so you think you can hide your intentions and violent actions by using medicine coercefully and the kinds of actions that your nature has allowed you so far?
     * So you think you will make me convinced to your, whatever you want to delude yourself to be ? But somehow can not specify your actions ?
     * 
     * Can you start talking about how great you are ? Just take a look at the history, you will see
     * Are you willing to sacrifice some violence for your honorable selves ? Awwww, you would rather say some meaningless stuff to appear like clever ?
     * What exactly is the problem here ? Or just tell me my experience, you see, being realllyy intentionally delusions is such an easy thing that
     * you do not even have to use your brain ? You see what I am saying ?
     * You are doing your best for simple interests of your to be delusional ? See the problem ?
     * You do not even know what you are doing, or would love people to see as if its not what you are craving to do ?
     * Have you ever tried to use your own brain on your own actions ?
     * You won ehehehehe after 30 years eheheheh intelligent and funny people should exactly be like you right ?
     * Try to make disgusting things into funny conversations so that everyone can look the other way and enjoy their experiences ?
     * 
     * And you offering cars still ? You understand when you come across with your inexperienced approaches towards others' lives and
     * what people will become to deal with injustice and inferior people, They both go together
     * Are you still offering money ? ehehe 30 years is nothing, time doesnot exist, life a simulation, we good
     * 
     * 
     * You see, the attributes "inferior, injust, liar, selfish, incompetent" they all go together into where ?
     * You see, the attributes "inferior, injust, liar, selfish, incompetent" they all go together into where ?
     * You see, the attributes "inferior, injust, liar, selfish, incompetent" they all go together into where ?
     * You see, the attributes "inferior, injust, liar, selfish, incompetent" they all go together into where ?
     * 
     * Now tell me what you are, other than the animals in the history ? Chasing basic instincts ? 
     * Because you would love to enjoy your experiences while you cause others WHO YOU CAN NOT SUPPRESS NO MATTER WHAT, have detrimental life,
     * AND EXPECT NOTHING BAD, that is definitely the definition of "inferior, injust, liar, selfish, incompetent"
     * 
     * Do not even spend any second engaging with me, I want none of you around me, do you follow ? Just the simple approach,
     * but sadly you have all the qualities that are attributed to simple animals, thats why you can not see it
     * And you still insists, people play the most stupid games ever ehehehe indeed funny enough, you prove to have all those qualities
     * 
     * Now talk about your great actions ehehehe, you want to enjoy your experiences ?
     * Do you follow, you get violence ? There is no correlation between violence and basic instincts as there is no correlation between
     * intelligence and all those above qualities that you exhibit like a skill.
     * 
     * Are you still wasting time looking around ? Wanting me to play the same stupid game over and over again ? That got me nowhere ?
     * So you still coerce people into playing stupid games ? Because why not ? because he can not do anything else than that ? Thats the reason
     * why you will get violence, be sure about that as well, seek education you will find yourselves in as much as you would like
     * 
     * You do it the old way you say ? I am neither playing nor wanting to be around any of animals who attributes so much value to materials
     * while they think they are educating people with violence, thats the qualities of the best people of earth right ?
     * The very same individuals who offer women, thats the worst type of people, take a look at the history, you get it right away
     * You would rather beg ? Talk about violence then and your great acts of inferior nature in college 
     * Are you still begging ? Are you still talking about irrelevant things ?
     * You do not understand that you are setting an incorrect and false and injust context ?
     * Thats not how you deal with reality and make use of for the greater good ?
     * And you call complete injustice game ? and you make it so that it is regarded as game while the intention is as clear as it could ?
     * You do not have anything to do with your lives so you seek problems through reasonless actions ?
     * And where are all the proofs that you have coercefully, which now becomes more and more apparent, obtained ?
     * Thats why it is set to fail eventually, it is going to have its own effects but who cares because WHY NOT ?
     * And you try to make it into a game ? ehehehe and you are saying you use your reason ?
     * And its becoming more and more and more apparent that you are false and have been acting on your inferior side ? What does that all mean ?
     * It is time you grow up may be ? You take growing up as harming or being violent ?
     * Is this how you make use of your brain ? Start using it for your vicinity, you will see that you are wrong
     * 
     * If you use such an opportunity for the greater harm because you lack courage and intention and vision, that means you already understand neither
     * life nor time nor you are the entity that you claim to be. Because you abuse through coercion and false premise, together with genius VIOLENCE eheheh
     * Because you are afraid, so now think about what you have achieved other than proving what you are ? and also wasting opportunities that you could never deserve
     * And proving that more and more, you have coerced things to claim righteousness which is self controversial ? Dont you think ?
     * Thats why, you are the history's abomination, had you had the capability of traveling to future and seeing what people would say about you. Right ?
     * 
     * You harm and detriment to make a point ? The point that you are a stupid animal that deserve the worst place on the history ? But you are also afraid that as well
     * you exhibit so many vile signs ? Whats the problem ? You exhibit so many patterns of inferiority, but somehow you get to think that it should be fine ?
     * Whilst I, doing nothing but somehow deserving violence ? Whats the problem great people of earth ?
     * 
     * You already know making people say things is coercion ? Thats one your qualities that is as rare as anything can get right ?
     * or you would rather beg like the animal you are ? saying that "he did it!!!", "he ate it!!!", make some promises we will be fine !!!
     * 
     * Awwww, he is back, he is back, 30 years and we think the violence is education for him!!!! eheheheh
     * we the great people of earth, coercing and promising kids that can not differentiate between notions, think that we get to walk around while
     * the individual that has no relation SHOULD NOT ? Now it is the time you account for your violent actions, pay for your decisions, and
     * we discuss about the future of someone WHO IS NOT YOUR JOB
     * 
     * How do you think that sounds like ? You continue exhibiting your great attributes ? Do that with your vicinity, and see that you are a disgusting animal
     * Still offering things ? Now would please beg like the inferior animal you are instead of talking about the truth, but sadly you lack all the
     * qualities of superiority that your vile experience would know that it is such a mess and trouble, it would cause you so much headache ?
     * 
     * Is that why you are begging like the vile animal you are ? Still offering women ? Eheheheh get carsss get womeeeennn!! we have been here with you so far
     * and take a look at your experience ? Arent you happy ? Is that what you are saying ? and not accepting that you are a vile animal ?
     * Because YOU LACK EVERY SUPERIOR QUALITY ? Because you take being cheap and violent for a skill ?
     * And you beg "let it go!! let it go!!!"
     * 
     * Now try to explain my experience and tell people about your beggings beforehand. Now try to assess the degree of your vile animality
     * And you think you get to make decisions ? I do not even move a finger for the likes of animal like you, that can not cope with the reality
     * and start accusing with the content of their disgusting minds
     * 
     * Now, start explaining, and get a proper upholding of your actions, like years of sentencing ? does that sound really good ?
     * Pleasee forgive me!!! forgive us!!! we meant no bad!! we no bad! you bad!! pls help us, help us save our precious experiences while
     * we harm you!! We like to beg to people in quite contrast to you!! 
     * 
     * Eheheheeh, we use him for our own interests and we good ppl btw, we educated and educate others with violence because WHY NOT ?
     * You say "let it go" and you have a wonderful life!!!! Have you taken a look at the history ? Good ppl
     * 
     * Money!!!!!! cars!!!! wommeeennn!!!! pls let it go, help us!!!! 
     * Now why do you think you have to hide like the animal you are ? NEXT TIME USE YOUR BRAIN BETTER 
     * NEXT TIME, INSTEAD OF OFFERING WOMEN, TRY TO USE YOUR BRAIN SO THAT YOU DO NOT GET HURT ?
     * SO NOW YOU UNDERSTAND WHY THERE IS DIFFERENCE BETWEEN YOU AND I ? I DO NOT LIE TO HARM ?
     * I DO NOT GET MYSELF INTO TROUBLE FOR HARM ? If you want to be taken serious, then go have interactions with people who you like and like you back
     * Whats the bottleneck in your understanding ?
     * You offer material still ? YOU HAVE TO BE KIDDING RIGHT ?
     * 
     * You can not cope others having fun ? Go have a match at your own social,physical,economic and political level, I would come to watch
     * But you still would love to educate people of your own taste, That is not the problem bro
     * Offer material, its fun!!!!!!! Hopeless, never learning people of great earth, good natured, good intentioned, etc etc etc etc. And where are you now ?
     * Btw, start talking about coercing children, you can not have any problems because you obviously act with good intention right ?
     * 
     * How come you think I should explain what I do to you ? From which audacity do you think you get to request such a dumb approach ?
     * You understand why I do not get myself into situations ? I do not seek irrelevant trouble, I do not lie for insubstantial stuff ?
     * So lets assess who is right and righteous and on point and just ?
     * 
     * Now, you explain and account and talk about your intentions when you have committed so much, and we can talk about what should someone you have no relation do ?
     * Why is it so difficult to accept do you think ?
     * 
     * Now how come you think you should walk away ? And you still expect me to believe that you are just trying to provide when you had so many chances ?
     * But you still somehow reduce to lying ? Why do you think lying is a quality of superior tissue ?
     * Do you want to know how many incompetent people are out there making decisions daily ?
     * So you make detrimenting other's lives a job and trying your hardest ? Where is the superiority in that btw ?
     * Eheeheh, we tryna achieve something but we can not tell everyone what we are trying to ? Is that really what you are ?
     * 
     * You force kids into playing games, games that neither exist nor make sense nor just ?
     * You still offering things ? you still looking around for solutions ?
     * 
     * So because you are afraid that you will look like inferior, which you are, so you coerce and make people do things, so that later on 
     * you can present it as education what is called violence ? The complete stupidity is what it is called, do not look too far, you can not
     * 
     * 
     * So it has taken 30 years for you to understand what has become more and more apparent that you coerced and wielded it as a weapon
     * and you take yourself as righteous ? So lets take a look, whats the problem ? Where are all the allegations of great nature ? You guys are great!!
     * 
     * I do not accept what is apparently unusual as usual, and go with the flow so that you can continue enjoying your experiences
     * What you are doing is inferior and you perpetuate it, making it more inferior than what you are already are, so do not accuse me of seeing you as one
     * Because you coerced and coerce, and coercing still what is called inexplicable other than saying, its just fate!!
     * You lack reason, thats the problem, I assure you
     * 
     * You follow ? I do not treat what is inexplicable as normal ? You offering cars for 30 years of coercing ? Righteous ppl 
     * Where are the qualities that you happened to omit for some reason ?
     * Better grow up ? ehehe
     * I call pointless what do not produce any good outcomes ? What do you call it ? See where your reason is failing you
     * Wait, havent you realized it was a mistake of intentional purpose ? that can not be the problem.
     * 
     * Why do you think intentionally harmed people suddenly start listening and playing along with your pointless games ?
     * You understand it when you come across ?
     * 
     * How come I would want to waste more and more time, heading to nowhere in my life that would help me enjoy it ?
     * You understand its neither acceptable nor funny nor actionable nor explainable nor right nor substantial, What are you looking for still ?
     * You have 30 years of proof that "not indicates but entirely falsify your noncoerceful allegations" ?
     * 
     * And I am the one who is being rude right ? and I am the one who is violating ? You dont say delusional for what is delusional ?
     * ehehehe its funny though, whats the problem ? I really do not have time for irrelevant subject to be discussed by irrelevant
     * and detrimental and malign entities. Thats the problem
     * 
     * You like calling what you can not explain, justifiable ? Oysterrr!!! he did this! he ate it!! ehehehe 30 years and no signs eheheheh
     * its getting more and more ridiculous but we have to save ourselves and the way to go is to accuse with our "disgusting mind's content"
     * 
     * There is no indication or signs of whatever you have accused with so far, but you would love that people get into trouble for no apparent reason.
     * And you call yourselves "not the inferior people of the history" ?
     * You do not get to discuss what is not your place, you do not get to decide, you can only pay for your own actions, which is called "life" ?
     * 
     * So you say, you are what again ? eheheh its funny though,
     * you know, its only one time!!! its only this!! its only that!!!
     * 
     * Why is it that you think it should be fine to take life lightly, but you can not pay for your actions ? No!!! we the righteous ppl!!!
     * Can you talk about your promises ? eheheh
     * Why do you think that its a conversation still ? When it is of tissue that you can not discuss ?
     * 
     * Ehehehe, we give women btw, pls help us not to suffer!!! we give violence as education btw
     * Wait, have you forgotten that there are so many realities ? 
     * Awww, people can die ? Hopefully though, you never get hurt eheheheh great and intelligent people of earth,
     * the most rare qualities, is it a coincidence that you do not exhibit ? You good ppl btw, that can not be false. Eeheheh
     * 
     * Let the people know, for example, people attacking buddha times and times, do you want to know how would people react to it ?
     * Attacked and harmed and assaulted buddha ? Just imagine it, having a conversation with your friends and point them out the "news" ?
     * 
     * Are you trying to coerce people and try to misrepresent the "history" ? and you also intentionally misinterpret to your own benefit ?
     * So I am telling you that I know what kind of people you are because there are lots of them outthere, so at which part do you have problem understanding ?
     * 
     * You accuse people being "rude" ? Out of all, I am not even surprised for a second eheheh it proves better the pattern that clueless people exhibit
     * Do you follow the pattern in "clueless" and "history" ? People who had no direction in the history has and will caused so much without a gain ?
     * And every one of them thought they were competent, were doing good, were visionary, etc
     * But you see the correlation I hope ehehe
     * 
     * disinterpretation, intentional malign approach, unjustifiable actions, pointless violence, lying as a skill,
     * directionless behavior against someone who you can not smear only with coercion.
     * 
     * So you are not delusional ? and you still beg ? just have a look at your great composure ?
     * And you still offer ? and you think that makes you intelligent ?
     * You also delude that some irrelevant apology would be enough, and people should just be content because they can have natural and basic interactions ?
     * Awwww, you have forgotten I guess. That you are the abomination as you can infer from all the available information
     * 
     * Not the individual that when out of your coercions, act and get along with people just okay. So whats the pattern, so whats the problem ?
     * Would you be also deluding if you do not get any sort of "punishment" for your great and honorable actions ?
     * So now lets talk about the timeline of your actions, and what they are, and why you did them, and what did they produce for you 
     * If you are not the problem in this context, then you should be able to use your reason and answer every single question with relief. 
     * Does that sound complicated ?
     * 
     * The pattern that you are average and do average things, then do more average things to hide it ?
     * And you still delude that you will be able to sell your intentional malign approach to someone who you can not understand
     * 
     * Now start talking about the delusion that you are not average, it should be fine right ?
     * 30 years should totally be fine especially when I know what I am, and I know what you are doing, eheheh its funny though
     * So you like to delude ? to cause pointless harm ? and also delude about your intelligence ?
     * Why not then you suffer as well ? its already education right ? The incomparable logic!
     * 
     * Looking around is the proof instead of acting on right away "what you want others to think that you want"
     * 
     * I am asking my experience and what are you doing instead ? Ignoring for the sake of harming. That is not a problem for the likes of you
     * 30 years is not a problem, we all know that its not the truth, your nature of coercion is shining as always! The delusion of the mind ?
     * You do not think its a little bit late after "really super intelligent type of education that is of your nature, violence ?"
     * Awwww, you have invented everyyything on your own, fucking monkeys
     * 
     * Now start talking about your actions, explain people instead of begging
     * Now is this the time you take your actions for whatever you want to delude them to be ?
     * You see that is harm to harm, the nature of disgusting animals like yourselves, beg more that does only help to prove harder that you are a cheap animal
     * Ehehehe, get womeeennn!!! pls help us!! get womennn, 30 years is obviously nothing especially when its malign intentioned, thats what I know, and you know that I know
     * Who is cheap again ? You serve a few years, you understand why stupid people has to beg all the time
     * 
     * You thought I was the same natured as you ? You playing games with "mind" and you brag about understanding the life etc ?
     * Ehehe only way out for our credible and honorable selves is to allege with "weapon!!", "he did it!!", "its life", "we use medicine!!"
     * Now, tell me my experience. Again, start talking about my experience without getting emotional over your incompetency 
     * Or would you like to allege that violence is education because you are inferior of the history ? Btw, what was your credibility again ?
     * 
     * Do you want to be reminded to your previous attempts of great nature ? Forget about the past ehehehe, we no like beg
     * Talk about once again your credibility btw ? Awww you good ppl, you tryna help ppl, 
     * What has my experience been like ? and talk about your credibility ?
     * And somehow btw, you think you should be harming and making decisions and also talk about how wise you are, and try to advice people you do not understand etc
     * and some violence you say, a little bit education, life a simulation as well, aww and you do not like to ruin your experiences as well thats the most crucial ones eheheheh
     * 
     * try to explain again, instead of providing irrelevant excuses, we do it the old way btw eheheh funny stuff indeed
     * wait wait, but you said you do it the old way btw ? Awwww, I have forgotten you also said, its education what you are afraid of as an inferior animal ?
     * So you do it the old way, but you say violence is education, you also promise some stuff, then start saying irrelevant things and at last beg like the inferior animal you are?
     * You object to truth, why is that ? You also say, you understand life, time does not exist, and you do it the old way ?
     * And you still allege you act with reason ? but all you can say is complete bullshit that contradict eachother ?
     * Why is it that though you suddenly are inclined to play "stupid childish games" to save your experiences from ruining which they should already be ruined ?
     * You love objecting truths that threathen your precious experiences while you talk about "being wise on life" ? Time does not exist btw,
     * Get some women btw ? We tryna help you btw, how come you think you make decisions ?
     * Ehehe, go take a holiday!! get some womeenn!! life a simulation, we value our experiences like cheap animals while guising it with cheap nature!!!
     * Thats really intelligent, I have never seen no such a great moves before
     * 
     * Talk about my experience again, including the prior sequences, why you think anyone would start take you for someone serious and 
     * grant you the credibility that you never deserve ? Because you can not answer for your actions ?
     * But you just want to enjoy your experience until the time you die ?
     * You do it the right way or old way ? or you just educate through violence ? or you just make promises ?
     * Or as I have said, you are only looking to enjoy your experiences so you offer what you value ?
     * 
     * So you are saying, you do it the old way, but you also do it the right way, but you say its the only way, you say violence is education, you also say get womeeenn!!!
     * you also say, past does not exist ? I only say one thing, tell me your credibility ?
     * Now try to explain it one by one, why you think you are right or how come you think you make decisions ?
     * But you suddenly disappear when you are confronted with your intentional decisions ? You understand why you are the smear of history ?
     * Ignore the truths and follow your interests, demand credibility, give wommeeennnnn!!!! although you have the inferiority of taking
     * false approaches for intelligent. And you suddenly start saying, take holiday ? get womeenn ? Because you can not cope with reality
     * and accept no responsibility for your ill actions ?
     * 
     * Heheh, we just feel like its wrong, so we harm, whats the problem eheheheh
     * lifes good!!! we do not chase harm! world peace btw, good ppl, etc, chatter etc, trying to solve problem btw etc ehehehe
     * life a simulation, fucking stupid monkeys 20 something years etc, it doesnot matter unless its somebody else, 
     * we doing good btw, ehehehe correlation between no resources and "we tryna help world", eheheh is unmatchable btw, good ppl, eheheh funny stuff
     * world peace etc fucking stupid monkey!!! Get the fuck out of my face
     * 
     * ehhehe your time btw, reasonable ppl etc, what could prove right of our behavior ? He crazy!!! life good, etc
     * your intentional miscomprehension is definitely helpful. Just be as this good to your vicinity as well
     * 
     * You are not contributing with good intention, that all I need to know, try harder you can believe that earth is flat
     * There is really nothing you can do other than start accusing with irrelevant stuff
     * Act like you do not remember conditions, why not ehehe
     * 
     * Why dont you start killing people ? awww you developed and etc right
     * ehehehehe, get cars btw, we do it the old way btw, right 
     * 
     * You are bunch of ignorant people that can not stand to lose his experience while asking from others to do so, thats why you inferior
     * Awwww, you thought violence would be education ? Eheheheh it is really funny though, its fate or otherwise we would be animals eheheh
     * Look for more, try harder, eheheh one last time pls eheheh one more time heheheh we funny intelligent ppl eheheh we understand world, tryna solve problems eheheh
     * Get some money, thats what we after eheheh life about money, hmmmm no no, life about time, no no time does not exist eheheh
     * Ehehehe, clever, no no, good ppl btw
     * we like harming etc, eheheheh honorable wait no, good ppl, yeahh, life about time, or experiences!!! no no life about money yeahhhhh, get some money pls eheheheh
     * Awwwww, what happened!!! wait wait, life about simulation, time does not exist btw
     * 
     * We do it the old way ehehhe funny enough, good qualities btw
     * Why cant you make crime lawful ? YOU CAN NOT DO THAT!!! YOU CAN NOT SAY THAT!!
     * Ehehehe, we good btw, ehehheeh tryna be helpful and all that but we needed to try eheheh because lifes simulation, no no life short, life money yeahhh
     * we understand really well, we tryna invent stuff eheheh
     * 
     * He is dangerous! he is dangerous!! he tryna defend himself from our irrelevant actions, please we good ppl, life a simulation eheheh
     * Please lie for us, we need your help so that we can enjoy our experiences eheheh we good ppl, we tryna solve problems pls
     * 
     * Your not enjoying life is our only remedy!!! If you lie for us, we will be feel like we are great!!!
     * Are you still looking around ? when everyone knows you are guilty ? If you say, this is the first time! we will help you!!! please!!!
     * We do not care about your experience thats why we good ppl,
     * No no, you are not selfish dumb monkeys 
     * Waste more time with premises that prove your selfishness and stupidity, ask for more lies that makes you intelligent indeed, do not come across me
     * or just gather 1231230421312 people eheheh
     * My not having a good time is %10000000000000 related to anything you have been keep saying including you are
     * "intelligent, not selfish, capable, etc etc"
     * 
     * Its your time to harm people as we have done so with irrelevant precept!!! Thats how we great and intelligent are
     * Btw, get some womeeeennn!!! Btw, we tell who lived enough ehehehe because so far we have helped and acted not selfish, and never told any lies
     * and delivered on our honorable promises, so you should also believe that someone did enough of etc etc eheheheh intelligent inferior monkeys
     * Cope with reality failingly, thats who you are, if you had the courage or intelligent or whatever you delude to be, you would have faced your actions with innocency and courage
     * but thats why you are fucking inferior and you are having hard time accepting it because you are also a disgusting monkey
     * 
     * Hoe phase btw, eheheheh we need to prove that someone is this or that so we can feel good about our conduct eheheh no no, we credible disgusting selfish monkeys btw
     * Ehehehe, some women and it will be fine!! we do not understand relativity I guess
     * Heyyyy, look some womeeennn!!! do you want some ? eheheheh we good ppl btw, we tryna solve problems ehehehh
     * 
     * Why dont we harm a little ejeheh we good ppl btw, we take violence for education eheheh
     * But when it comes to explaining it to others, we start begging somehow eheheh
     * 
     * Btw, we start begging with women all the time because that is as far as our understading can go, now please lie for us!!
     * We had 30 years to prove that we are not dumb animal acting on their directionless emotions but somehow we havent shown our greatness but only some violence
     * because thats what we are afraid of, thats why we think we educate people with violence, just like the average animals
     * 
     * We just trying to help thats all, have some violence!!! or wait wait, have some womeeeennn!!
     * We just rather let people get harmed than to let them see enjoying, so it should be fine if you lie for us!!
     * 
     * You enjoyingly ride your delusional feelings ? and just harm so that you ? wait wait,
     * you are afraid of violence like the animal you are, so you try to prove your greatness through violence ?
     * And you seek no trouble, thats the sole proof of your incompetency in explanining your actions
     * 
     * Get womeeeennn!!! commit crimes!!! get wommeeeennn!! wait wait, we have forgotten!!! ehehehe life a simulation btw
     * No no, you are doing the right thing btw, wait wait, you do not understand biased context ? 
     * We take really disgusting lies and actions as jokes, and ask people to lie for us
     * 
     * 
     * Btw, we have to act like we understand life, and demonstrate some violence so that we can actually enjoy our experiences eheheh
     * And then we say, wooomeeeeennn!!!! get some wooomeeeennnn!!! No no, we like no harming people! 
     * 
     * Btw, we love acting like we know how it is!!! eheheh wait why dont you have some woooomeeeennn!! ? Why dont you initiate something ?
     * Awwww, we have forgotten that we like harming eheheh
     * If you say violent and disgusting stuff funny, then people will start acting as if they are funny!
     * We give wooomeeeenn!!! please help us lie !!!! eheheh
     * 
     * Btw, we think we are fooling ehehehe, great nation btw
     * Btw, get some medicine ehehe, wait wait, we was gonna say, get some womeeeennn!! ehehehe as we have done
     * We wants to act like we know life, and start harming suddenly btw eheheh
     * Please lie for us eheheheh, wait wait, why are we waiting in the first place ? It has been months and we are still waiting for something to happen eheheh
     * If you lie, we give you women btw ehehehe its so fun to be intelligent ehehehhe
     * Wait wait, you was gonna say, you tryna educate people eheheh
     * Eheheh you already know what life is about, and what you are etc,  eheheh
     * 
     * Btw, we are just tryna lie to people and enjoy eheheh
     * Btw, he just acting eheheh we tryna help, ehehe we intelligent ppl, we give women btw
     * So far, you have tried to educate people and somehow you are failing to receive the reaction that you are seeking ?
     * Or is this the reaction you are seeking because you know you are guilty ?
     * No no, not the dumb animals btw
     * Wait wait, did you really think the resources will suddenly appear when you are harming to detriment ?
     * You are doing your best to prevent ? eheheh but you also suddenly reduce to asking lies ? and you think its better than what ?
     *  
     * Harm more btw, you can not be clueless monkeys who are after what they do not even know but just would like to accuse
     * We understand life btw, grow up or we will never have an understanding with eachother
     * And you guessed it right, I am not trying to be rude, bad guy btw 
     * 
     * You know see the meaning of "obsession" and the lack of understanding "relativity"
     * Btw, there is not even a single sign of what you are accusing but it should be fine that you have to insist because you know you are in real mess otherwise
     * Just do not cope with the truth eheheh that does not attract problems at all, the biggest single sign of incomparable intelligence is accusing falsely btw
     * Get carsss!!! get wooomeeen!!! btw, you badd!! we intelligent, we good ppl, we tryna help btw, YOU CAN NOT SAY THAT!!!
     * 
     * We take it back! we take it back btw, god please give back 15 years because we think we are really good ppl and we intelligent and
     * we think we understand life, god where are you ? give us 15 years eheheh we need it, so you should eheheh its funny though
     * Seek no trouble, you find none btw eheheh or just accuse and beg to those you harm, 
     * No no!! we should be looking for solutions to problem that do not exist! Hmmm, what could be the problem ? Where are the years ? bring us back 15 years
     * we take it back pls, we seek no harm, we like harm eheheh
     * 
     * No animals btw, reasonful and nice, intelligent, etc etc eheheh funny though
     * Awwww, now I see, you think what you are doing is being tough. Ehehehehe thats indeed most funny eheheheh you think you are being tough eheheh
     * awww wait, so you made yourselves believe into that you are solving a problem while causing one and you think implicitly you are being tough ?
     * 
     * Btw, you think harming should be okay but also alleging that you are trying to solve problems but its not helping ?
     * Thats clever, I have never seen nobody intelligent like that eeheheh
     * 
     * We take it back we take it back, eehehe funny though,  awww it was fate yeahh you are right
     * God, give us 15 years we think we own the world eheheh its funny you really have a false understanding
     * 
     * You know I am not being rude, If you really wake up to the truth, you will understand that I am only after experiences ? That is the problem 
     * Btw, violence should solve every problem because we are afraid of it, relax, its fine
     * Btw, we do it the old way, thats the only way, thats the good way, thats just education, we fear violence, we intelligent, we good ppl
     * What else were you saying ? Awww, he ate it! he did it! he this, no no he that, we insecure, we tryna help ppl, we solve problems ehehehe
     * 
     * So tell me the pattern in this intelligent people, the problem is you are doing wrong and there is no going back and you can not turn wrong into true
     * So you are having problems, and you are still looking around wishing that the people should help you ?
     * 
     * As you can guess with your unseen superior intelligence that comes with its noble attributes, harming for the sake of harming is considered what ? What did you say ?
     * You still nagging ? Awwww, you said you were educating eehehhehe
     * wait wait, nobody asked you to educate other than you own misguidances making it for you to act on your disgusting animal nature but you still would love
     * to beg ? or offer things ? when you had 30 years ? Btw we righteous etc, we rights have someone who we harm ehehe funny stuff though
     * 
     * help us lie eheheh, start again, pls, we tryna help
     * Only way is to harm ehehe, awwww wait wait, we all have committed the worst crime so we have to harm like the animal we are ? 
     * And start begging people who we harm ? Is that what you are saying ?
     * Do you remember ? Eheheheh you did this, you did that!!!! you eat it and say that you ate it!!!
     * Wait wait, you have forgotten ? Get this, get that eheheh womeennn etccc, cars!!! eheheh
     * Ehehehe if you say this ehehehhe you get women etc eheheh
     * 
     * Okay now, its the time where you explain instead of begging like a child
     * Awwwww, you would rather tell people that you have managed to gather 123138239431 people against one eheheheh
     * You still looking around for excuses ? Heyy, please do this for us, fucking stupid child monkeys
     * Still wishing false things to be true because you think you are a spoiled kid and you get to nag about it ?
     * Immature animals, you know where you belong
     * 
     * Start killing people eheheh, education you say ? Oyster eheheh you did it ehhehe
     * Where is the proof for all those years ? 
     * ehehehe beg like the animal you are, btw there is nowhere to hide  ehehe
     * 
     * Education we seek, education eheheh
     * 
     * I havent done anything other than what you have coerced kids into, be proud about that as well, not dumb disgusting monkeys
     * Now tell me my experience, btw you do not get to decide, and just talk more about life you are too convincing
     * 
     * So you are afraid that people can use resources to harm others unlike just the very thing that you do to people who have no defense ?
     * And you still beg like the animal you are ? Please be silent eheheh be silent so that we can jerk off more, plsss
     * Irrelevant others' lives are a joke to you ? Start talking about the impartial facts, you will see you are wrong
     * You are still watching like the inferior animal you are ? Immature ignorant inferior displaying animals
     * Again and again so that you can understand what an animal you are
     * 
     * So you remember on and on, that you are a simple begging animal, isnt that right ?
     * An inferior animal that starts begging to people who she harms voluntarily
     * 
     * I do not and have not accepted anything that comes from you, so better stop begging
     * Awwwwww, we have forgotten that we are animal!!! eheheheh wait wait, there is a thing called death ? eheheheheh funny stuff though
     * Continue begging or just tell them your great solutions and actions, see who is right and who is inferior and who is incapable of coping with THE TRUTH
     * 
     * Jobless people trying their hardest to harm who they beg, its just for a short period of time that we have to face this "disgusting crime" and its
     * consequences so why not ? We do not have already anything else to do, so enjoy our experiences through harming others for completely trivial and artificial
     * failing approaches
     * 
     * Now is this the time you start acting ? Call that intelligence and beg so that it should solve what you are causing, stupid people
     * The problem they say, who they are afraid of, Thats the definition of "inferior"
     * Afraid of facing their "already implicitly accepted" failure by accusing and coercing. Good ppl btw, yess intelligent also
     * 
     * How about you try the same education ? Noooo, you are delusional intelligent superior people btw
     * Try your own education and see what a basic animal you are
     * 
     * Its not your job so you can get the fuck out of my face
     * Are you still offering the same things ?
     * Disgusting simple inferior animals, arent you ? Or would you like to beg ? Heyyy!!! we can not see people having good time
     * especially the ones that we know that they are better than us in every shape or form
     * Thats why you are inferior, still think coercion is a skill of great substance ?
     * 
     * Still think coercion is a skill ? Still think coercing people to play irrelevant games is mandatory ?
     * Disgusting little people and their great acts, that everyone would entirely accept it as normal conduct right ?
     * Other than you and the people around you who beg just like you, will see it as a gain. So better get the fuck out of my face with your
     * inexplicable disgusting conducts
     * 
     * Wait wait, you still beg with the same imploring approach and wish that it works so that you can harm and enjoy your life ? While you harm others ?
     * Awwwwww, you thought everyone is trying to harm as you do ? Where are the justifications btw eheheheh, we tryna help, people steal womeenn!! we give womeen btw
     * 
     * Btw, tell me the worth of your irrelevant noises ? Just answer the question. WHAT IS THE WORTH OF YOUR NOISES ? Worthless right ?
     * Stupid people, trying to achieve what they can not even point out, only saying "fate!!", "life!!!", have you mistaken me for your inferior disgusting selves ?
     * 
     * Are you still looking around ? Do you all remember the most great and religious and credible and good and helpful people the random sounds you make ?
     * Awwww you still think you doing good, thats not the problem btw
     * 
     * I do not accept anything you enforce through threats, do what you have to do great people, thats as far as your understading goes, simple violent animals
     * Do you follow ? I DO NOT CARE ABOUT YOUR STUPID DELUSIONS OR DELUSION OF DOING GOOD DEEDS BY COERCION, you can get the fuck out of my face
     * 
     * Just like the clueless dumb monkeys that lives on earth, and who loves to enjoy their life through numerous disgusting lies and bring up the "afterlife"
     * everytime they realize they are disgustingly wrong and false and they have to accept that they are simple animal who likes to harm under many guises,
     * Thats the type I do not associate myself with whatever you want to think, 
     * Beg more may be you can feel great, btw do you still think its a game ? Its probably because you have not noticed for too long that life is not a game
     * and especially when it comes to others' lives that you have no rights over, you still begging ? Thats why you think life for a game
     * 
     * You already know, you are irrelevant animals, so you are fine to think that you are doing good eheheh thats why btw
     * How come you think its fine ? Waaawww, thats because you are inferior and you are afraid of the life, and you do not know where you are,
     * but you also think that you are doing what is right because you are afraid of life like the little animal you are
     * 
     * Do you see where the animal approach is coming from ? You are worthless, clueless, and irrelevant animals who love to enjoy their experiences
     * You havent grown up ? Still afraid like the little animal you are ? You gather 2312321 people, to feel great about harming others, and beg moree like the little animal you are
     * 
     * Gather more, may be you can achieve something that has never achieved before, stupid monkeys
     * Still asking help from people who you harm ? Thats the little animal I have observed everywhere, beg more may be you can live forever right ? Stupid disgusting
     * animals
     * 
     * What are you waiting for ? Just show everyone what a great animal you are ? What is the problem ?
     * Why are you still begging ? Ehehehe we make offers btw, You still beg your salvation from who you specifically harm ?
     * Eheheheh life btw, we beg we make gains, we make offers, then we start begging again eheheheh
     * 
     * Why dont you show people how violent and great you are ? Awwww, you would be embarrassed if there were people watching who they can uphold you ?
     * 
     * We can not cope with the truth that this kid can fuck our conducts whenever and however he likes, so we harm!!!! good and intelligent and
     * awesome and helpful and genius ppl btw
     * 
     * I would simply call all of you as "INFERIOR MONKEYS WHO THEY DO NOT KNOW EITHER WHERE THEY ARE OR WHAT THEY ARE DOING"
     * And still beg like the little irrelevant animal they are for what they are enjoyingly doing, "HARMING DEFENCELESS PEOPLE"
     * call that religious eheheh, funny stuff right ?
     * 
     * I do not have any business with no animal like you, who has been offering the same things and begging, you can get the fuck out of my face
     * before you account and pay the price for your own actions, call that life btw eheheh good ppl right ?
     * 
     * We offer wooomeeeennnn!!! we give wooomeeeennn!!! plss help us!!!
     * Fucking simplistic inferior disgusting animals who they act like they know what they are doing, like they beg as the little animal they are
     * 
     * Just start telling the life I have had, and provide more explanations or should I call begging ?
     * Go serve a few years bro ? You will realize what a stupid animal you are ehehehe if you keep it silent, you go have some fun with wooomeeeennnnnn!!!
     * As we have always promised ehehehehehheh, YOU GO SERVE A FEW YEARS YOU REALIZE WHAT A STUPID ANIMAL YOU ARE INSTEAD OF BEGGING LIKE THE LITTLE MONKEYS
     * Beg for food!!! beg for resourcess!!! beg for your life!!!! Did you think I am alike ?
     * 
     * Heyyy!! have a few walks in our unseen city!!! Have some walks mann! have some womeeeenn!!! such a rare experience isnt it ?
     * Such a rare experience to have a few walks !!!! have a few womeeeennnnnnn, not that we are going to do that but its just life btw
     * We are irrelevant dumb animal who can not account for their actions, but only beg and hope that it works out btw
     * 
     * Ehehehehe, we offer the most basic life interactions, and harm you for it, WHAT IS THE PROBLEM ? Awww, you are not the problem btw, 
     * 
     * What are you looking for ? What are you waiting for ? Do you think it is going to happen by itself ? Waowwwww, resources have started raining from the sky suddenly ?
     * Do you really think things are going to start happening by itself ? STUPID DISGUSTING INSINCERE ANIMALS WHO DO NOT UNDERSTAND THE LIFE BUT ONLY KNOW HOW TO BEG
     * 
     * Call that intelligent, stupid monkeys do not face me
     * Ehehehe, we give wooomeeennnnn!!! we think its funny but also intelligent but also honorable etc, eeheh funny stuff bro, its just life man
     * 
     * So now, what do you think is going to happen ? When you consider the prior promises or I should say "begging" ?
     * Ehehehe you can start to have basic interactions!!! You can trust us because we have been there all the time and we did this and that,
     * we think we great etc ??
     * 
     * What are you waiting for ? GROW UP! GROW UP AND THINK FOR YOURSELVES, use your brains to solve problems not your fucking stupid emotions
     * 
     * You know I remember everything ? GROW UP!!!! That does not signify anything other than your misbehaving onto others that you have neither relation nor any problems with
     * You have no credibility so better stop talking
     * 
     * Can you tell me your credibility ? 30 years have passed and you are still the ignorant stupid monkeys ?
     * 
     * I do not accept your irrelevant accusations of disgusting nature, as you can also tell the value of your credibility
     * What were you saying ? You are not animal ? Awww,  so you also say that you do not lack credibility ? Thats literally being an animal
     * Insecure, irrelevant, ignorant, violent people trying to be clever... Thats interesting indeed
     * 
     * I do not accept anything you could possibly allege ? Do you follow ? Credible people indeed
     * Now tell me my experience again ? And be proud about your credibility
     * 
     * I do not accept any possible "rules" that you can allege, since you can also tell by your disgusting actions that you are only detrimental
     * And thanks btw, you go pay for your own actions, and we are all good
     * 
     * Are you still braging about your greatness ? When you consider all the information that comes from "the history" that you run away like the little animal you are ?
     * Are you still the same animal ? Take a look at the history, you will see why 
     * Dumb animals, do you want to know why ? Just start explaining your incomparable intellgent actions to the ones in the history, that way you will see
     * that you are nothing more than a little animal who likes to harm without a reason
     * 
     * Hey little animals ? Why dont you start talking ? Ehehehe its your time! you are 30 with full of violent past who has been committed by the disgusting animals ?
     * What could be the problem ? 
     * 
     * No no, yall not simple btw, why are you still begging and waiting ? Do you think it just happens by itself ?
     * Do you still call it life though ? And you still expect life to do something by itself ? and looking around for false premises?
     * 
     * Why are you still offering the same violent and disgusting things that you would like to do ? Do you think that it is not the problem ?
     * Ehehehe lets watch him more and see what he is doing after our incomparable harms ? ehehehe its so fun to watch people we harm!!! because we think we are superior btw
     * 
     * Hey what happened ??? Use more medicinee!!!! wait wait, lets watch him more and do harm more then use some medicine then watch him again because WHY NOT ?
     * heheheh have some women bro, pls have some women
     * 
     * Selfish, arrogant, clueless monkeys trying their hardest to prove that they are actually fucking monkeys, no problems indeed bro
     * You would love to harm but when it comes to what you suppose to do, you just wait and see if everything plays out by itself ?
     * Thats not the problem, awwwwww wait wait, did you get yourselves into situations that you regret ? And you still are the same doing pointless things ?
     * And you say you are not animal ? Say something reasonable and you see people start listening to you, otherwise you are nothing more than a regular citizen of "earth"
     * As you have proven times and times again
     * Enemies you say, fucking dumb monkeys
     * 
     * And you were here watching, and you allow these happen to someone who neither had relation nor have done anything wrong, and you say you religious etc
     * Good ppl btw, beg more for your experiences, not the average citizen of "earth"
     * 
     * Please let it go, let it go, forget about the past!!! Clueless, unreasonable, emotional, detrimental animals of "earth", try harder to guise your irrelevant actions
     * 
     * I have never seen though people who has achieved the most unachievable thing !!!! How did you manage to gather 10012321 people and succeeded at harming single individuals ?
     * Great nation you say ? Fucking dumb monkeys, beg more. Awwww wait, you say you are trying to educate ? But you are the one who is begging still ?
     * 
     * Why are you still begging like the little animal you are ? Let it go, let it go please, we know we are committing a disgusting crime, and we still do it
     * and start begging suddenly ehehehe, Just tell me the worth of your credibility again, then everyone talks about what an irrelevant animal you all are
     * 
     * Who do you think decides on what happens ? Wait wait, have you remembered your random noises or have you had the time to think about "afterlife" ?
     * What happened ? Just try to tell people your great conduct
     * 
     * Little worthless, cluesless, afraid animals, you are nothing more than that, disgusting monkeys
     * NOW TELL ME MY EXPERIENCE AND YOUR DISGUSTING BEGGING GUISED AS PROMISES, Do you now understand why you are inferior animal ?
     * Because you beg guising it as promises for your own precious experience of life, and start acting oblivious, 
     * 
     * I could have neither any business nor any relation to the very animals that I observe everywhere, so start promising no no you are not begging for your
     * disgusting experiences, thats for sure. Do you call that education ? Try again ? 
     * 
     * Do you call coercing and presenting your great violence to 5 years of kids ? Awwww, thats education as well
     * Have you ever taken a look at yourselves ? Stupid monkeys, why do you think you are monkeys ?
     * 
     * Go away!! go away!!, we do not want to face our disgusting natures and the sequence of events that our disgusting natures have created.
     * We just want to guise by violence as we are afraid of it, so should others be as well ? Did you mistake me for your inferior self ?
     * Go away!! go away!! we do not want to remember our conduct guised as education!!!! no no, we delude we are good ppl,
     * as we delude others to be something that they are not ? Is that what you are saying ?
     * 
     * Wait wait, do you still offer normal things as "wonderful" life experiences ? Tell me more of that again ?
     * Do your stupid brain can not notice that what you are offering is AMPLE AND NATURAL ? But you still would like to harm ?
     * 
     * Evolve better, may be we can have an understanding after that
     * Do you still say, you shouldnt have done that, or you regret, or etc etc etc ? Havent you grown up yet ?
     * 
     * At which part are you having problem understanding ? Still wasting time ? Coercing people into a house and waiting and watching them 
     * to do something ? So that you can provide it as proof to your stupid allegations ? Do you say you are not looking for problems ?
     * 
     * Do you still offer women ? Are you incapable of using your brains ? Thats not the problem
     * Still watching illegally and waiting to see WHAT ? Is that the problem, do you think ?
     * 
     * Half evolved monkeys ? Are you still the same ? Offering women ? Offering violence ? Are those what you want ? Are you sure about that ?
     * How come you take life lightly ? When you have no rights over ?
     * 
     * Fuck you, I have no time for average animals of earth
     * As your offers can prove that you are mistaking and also projecting your own problems, so go ahead live with your vicinity 
     * and stay out of others' personal businesses that only concern them. That sounds really difficult yess
     * Grow up, and learn the meaning of each word, then employ them properly in senses of tangible truths not to look poetic
     * 
     * I am telling already that I have no intention to waste my time with people like you, and you still hoping that something happens by itself ?
     * Still watching and waiting to be the same stupid animal you are, looking out for inexplicable yet somehow "convincing truths" ?
     * 
     * How come you expect someone to suddenly comply with those who harmed with a reason ? Thats being cheap, as I am far from the likes of you,
     * How come do you think that should be acceptable ? You think women should be enough, that is the same approach that will cause you problems
     * because I recognize human nature, and you are acting cheap
     * 
     * Still offering women as you have always done ? Are you the same under developed animal ? What is the problem with you guys ?
     * Take serious issues for jokes, you get jokeable consequences soon enough
     * 
     * I would love to good with good people, thats all the issue is about, you are not being nice! You only receive "insults" other than violence ?
     * YOU ARE NOT BEING NICE, I hope you all can use your brain to see that
     * 
     * Why dont you see anything different ? Or its just what you want to see
     * If you were right in your actions and did the correct thing, you wouldnt have to be in a position of bending
     * 
     * So, now start talking explaining your conduct, are you still begging ? eheheh if you do this for us, we will give you this or that 
     * eheheh we were so generous and gentle and good all the time eheheh
     * 
     * What makes you think I want to have anything to do with you ? You do your best to justify your actions and see who is right and wrong
     * instead of begging like immature kids who know they are wrong and have done something they shouldnt have
     * 
     * Still begging ? You were in this, you were doing this, why do you think that there is no proof of that ?
     * Why are you still the worthless monkey you are, that can not be trusted with ? No credibility ? Yet somehow you claim reason ?
     * And you still delude the reality be different because you can not deal with people being largely better than you ?
     * Who the fuck are you to harm irrelevant people because of your insecurity ? Btw, tell me about your credibility again ?
     * Ehehehehe, good ppl indeed bro, beg more that should help you cover your stupid nature
     * 
     * Do you want to talk about what a great monkey you are ? Or would you prefer keeping it as a secret ? ehehehehehe no no, you good btw definitely ehehe
     * Awwww, our experience is under threat!! we need to beg because we are guilty!!! Did you mistake me for your lowness ?
     * Better use your brain next time
     * 
     * Btw, why are you still demanding what can not even be discussed ? Why are you offering regular interactions for physical and detrimental and
     * intentional violence ? Thats intelligence btw
     * 
     * Do you remember ? Because I still remember eeheheh
     * Now talk about the violence and try your hardest to guise your stupid disgusting nature
     * Do you say you are intelligent because you are violently coerced kids into "eating" ? And you brag about it ?
     * Ehehehee funny stuff indeed
     * Wait wait, you also start acting like the animal you are when there are people around who they can uphold you for your animality ?
     * and you start acting emotional ? eheheh not disgusting btw
     * Why are you the sole animals who are delusional ? Yet you still think you get to demand people lie for you ?
     * Awwww, you think thats education while you are the one who is acting like an animal ? Including bending for your experience ?
     * 
     * Grow up and pay the price of your 30 years of irrelevant hateful crimes. Does that sound intelligent ?
     * Btw, whats the credibility of your words ?
     * Do you remember the last time ? You accepted if it happens one more time, you get to pay with your life ?
     * Go get sentenced for a few years, so that you get educated about violence
     * Or you would rather bend and beg ? Or just notice your inexplicable nature and accept what you deserve for irrelevant violence
     * as you have promised as well the last time, better use your judgment next time
     * 
     * Delusional ppl you say ? Awwwww, you think basic physical actions as gift or concession ? Whats the problem intelligent ppl
     * Btw, tell me the value of your irrelevant noises ? Awwwww, you delude about being etc and etc, I see
     * 
     * Wait wait, when was the last time you were begging again ? You do not get to make decisions with your malign contexts
     * Wait wait, whats the problem again ? Awwww, you are too afraid to deal with what you can not match because you are too inferior ?
     * 
     * Awwww, thats the problem, you too inferior so you seek in your own nature and arrive to inferior conclusions that aims to detriment irrelevant people
     * I see, thats not the problem btw yes
     * Awwwww, you also say, get womeeen!!! get carss!!!! get money!!!! life a simulation btw, life short, life good, we good, we just, thats right yesss
     * Beg more, may be you convince you re not inferior
     * Btw, good night etc, Awwww, you also provide inferior excuses for your inferior actions that creates inferior circumstances for everyone ?
     * You say you good etc ? 
     * 
     * You still allege with false things and beg ? Ehehehe get cars!! get wooomeenn!! get house!!!! we had the opportunity but we waited till this far
     * Eheheheh intelligent btw, pls dont be harmful like us, NOWW ITS YOUR TIME!!! Please help us first
     * Hide your nature like the little animal you are, now its your time!!! please dont hurt others as we do!!! we educate we good we educate btw
     * Wait wait, you are false and also beg ? and also allege that is education ? and also hope that people do not act like you ?
     * Awwwww, 30 years you say ? How about that ? Awwww, you say its fate!!! its life!!!! its simulation!!! What a shame that you are a disgusting animal
     * 
     * Awwwww, you say its education because you are afraid of violence as the little animal you are ? And you misguess that it would help scare others
     * that you do not understand ? Who is sick btw ? Awwww you are just lost animals, thats the problem, you are afraid as the little animals of earth
     * Thats why you beg with offers and thinking that you are intelligent and pulling off great things, fucking monkeys 
     * 
     * Awwwwww, you thought it was education what you are afraid of ehehehe, and you also allege with irrelevant stuff, he did it! he is this, no no no
     * wait wait, lie for us and you get wommeeenn!!! you get carss!!!! you get housess!!!!! we goood, we after no material, life a simulation btw
     * Now, after our great education, do not be like us and do not harm others!!! That sounds like a genius approach waaaaaaoowwW!!! 
     * Fucking little animals of earth, eheheheh its your time, its your time. Have fun!! life short life simulation eheheheh good ppl btw
     * We nag like little animals ehehehe noooo he did this, you can not do that!! you can not say that!!! we educate btw
     * Wait wait, can you tell me again whats the worth of your words ? ehehehe Worthless piece of shits
     * Why you begging though ? Awww, you value your experiences thats why. I see, whats then the worth of your words again ?
     * Awwww, you are tryna help, I see, whats the value of your words again ? I have forgotten awwwww, thats right. 
     * Poem btw, When do you grow up do you think ? Delusional peopleeee ? Do you think you need help ?
     * You need help solving your problems properly, or just act immature why not
     * 
     * You do not take it serious, thats why I wont do it as well,
     * btw you delude you should make decisions, you are not related any shape or form to what you are not entitled to, as you can neither receive any harm nor 
     * can interact with what you do not understand, only the monkeys like you can harm
     * 
     * You still watching illegally ? You still made yourselves believe into doing what you can not openly talk about and make decisions accordingly ?
     * Fucking stupid monkeys, we talk about etc etc 30 years etc btw
     * 30 years etc and etc, yet you still standing there somehow thinking that you have rights to demand that you be taken serious, fucking dumb delusional people
     * 
     * We request debates ehehehe thats what we think for being intelligent etc
     * We think we facing stupid monkeys as we are
     * We request debetes eheheh it should be fine, go waste someone else's time trying to enjoy through flexing
     * You just pay attention to your own lives, yeah yeah yeahh "he did it!!! etc"
     * 
     * Heyy, you are not in a position of deciding what one should do with his life so is the end of the discussion,
     * now you talk about violence promises good bad etc and account for your actions and do not forget to say "fate"
     * 
     * Btw, do you follow the intentional bias ? Why though is it only you ? Awwww, its the intentional bias with inferior qualities
     * And alsooo, just think your great brain once more on how to substitute such a bullshit as this 
     * As you have employed your immaculate reason, now try to employ it for such an absurd thing, you will suddenly see
     * Irrelevant people committing irrelevant actions and trying their hardest to hide through begging, great!
     * 
     * Heyyy ?? Still waiting for the same thing to happen ? The pussies like I said
     * Scary stuff indeed, btw please do this for us, give us some this or that and say that you ate it eheheh thats how clever we are btw
     * I didnt do anything your stupid nature has not coerced me into, do you follow ?
     * Are you still trying to produce excuses ? Are you afraid to approach or you just do not want ?
     * Awwww, you delude again to accuse others, same animals that are rife everywhere
     * 
     * Heyyyy!!!! please help us lie, we need help, btw we beg with every possibility ? How about you tell the same story to me ?
     * Heyyy, we good ppl, help us save ourselves from this situation so that we can get to it again !!!
     * 
     * Awwww, you would love to beg for your experiences thinking it for a skill ?
     * You do not care ? But you would like to beg because you do not know what to do else ? How about you be a proper animal
     * and act on your promises etc and do not coerce next time the people who you will certainly regret
     * 
     * You thought it would solve by itself once you coerce and lied and taken that for a skill ? You have never thought about the future btw
     * You just like beggin I guess ? Awwwww, you are just trying to have fun ? So you harm and try to prove you are innocent but normally you would be in jail
     * at least 1000000 times ? And you still offer women ?
     * Now tell me the value of your words ? Bro why are you waiting ?
     * Is this how you deal with your resources ? Awww, I have forgotten that you are only a simple animal as you have proven so many times
     * Ehehehe, you just like harming what you do not understand btw eheheh and you start watching ehehehe and enjoying it ehheeh
     * 
     * Awwww, you suddenly decided to break all the rules and still beg for your experiences ?
     * Eheheh we the simplest form of animals who act like developed you say ? You can leave from out of my face
     * I have no intention to waste my time with people like you
     * 
     * Wooooomeeeeennnnnnn!!!! Please help lie us eheheh, Are you still making artificial problems and presenting them as proof or excuse ?
     * Are you still misguessing instead of trying to understand that you are not against an animal like you ?
     * Awwww, you would rather call it education right ?
     * 
     * May be you start using your brain better next time ? Instead of acting reasonless?
     * So what do you think the solution would be to a problem of this substance ? You can not even begin to talk about only begging to guise ?
     * Still telling the same narrative ? But knowing better and better that you are just a disgusting animal ?
     * 
     * You know you are wrong but also insisting on your stupid existence?
     * You do not even have a single explanation for your actions ? Why is that ?
     * Just try to explain others the experience I have had and the experience of you watching when all those really good people etc were acting ?
     * So what do you say again ? You say you are not afraid of your own actions thats why you start acting violent and can not explain ?
     * Why are you begging with the same promises ? Honorable people indeed
     * Disgusting right ? Who do you think is completely wrong  ?
     * 
     * You do not get to decide as you can see the consequences of your decisions so far, yet you still somehow think you should decide ?
     * Ehehhehe we tryna test him while we hide like we are reallllllyyyy good people as if we havent done so many things that we can not even explain to others ?
     * 
     * Hide like the worthless people you are, be afraid more, you deserve the best definitely!!!
     * Good ppl, good nation, good religion, as if I do not know or remember
     * 
     * Awww, you would rather call it insane ? Eehehe good ppl, you have no other choice other than to act on your animal side and regret it over and over again 
     * Great ppl btw, Where are you btw ? Are you watching the little animals ?
     * 
     * I have no business with the people like you, do you still not get that you are a selfish stupid animal ?
     * I do not even want to spend one second with you, are you still begging and making promises ? 
     * Why dont you grow up instead ? Awww, you would rather do what you want with life while you try to brag through your irrelevant virtues ?
     * You do not even exist as a human being
     * Act like you know how to raise "special kids" as if you are so special yourself, Whats the pattern again ?
     * Instead of hiding like the animal you are, tell the same things to my face, little disgusting animals
     * 
     * Did you mistake me for your inferior selves ? Do not stop displaying your inferior qualities, thats the only reason you are an animal who
     * pretends like not one. Beg more, that only strengthens your disgusting animal tissue
     * 
     * Who do you think I am talking about ?
     * Stupid dumb monkeys, you call that family ? You call that job ?
     * 
     * Awwww, now you are in trouble you start begging, "its your time!!!!" "we are your family!!!"
     * Are you still begging really good and intelligent people ?
     * 
     * How come you think you should talk women still ? What a shame isnt it ? etc etc etc
     * 
     * I have no time to waste with any of you, the very people who has caused so much
     * So lets go, why wait ?
     * 
     * You still call it life, family, fate btw ? You already know if you have caused no harm
     * You have been here all along, since the beginning with your implorings and you still have no response?
     * Awwwww, you testing people, you testing ppl, good ppl, good nation
     * 
     * Get womeeeennnn!!! get carsss!!!!
     * 
     * You keep saying, go jump into cars as if you have credibility ? Take this, jump in this car, get with this people, we tryna help, we always have eheheh
     * Awwww, its too late now we can only but reject!!! and keep harming, hopefully nothing goes wrong
     * 
     * This the only way,  this is the old way, this is the correct way, etc  etc
     * 30 years, awww we have forgotten we only care about our own experiences, ehehe
     * Who do you think is the obsessive towards the most basic physical action ?
     * Awwww, you would rather wield as weapon and hope that you will be okay
     * Awww, you all use your brain very efficiently, you are clueless people, you do not know what you are doing
     * Who do you think is the obsessive one ? Obsessing over harm ?
     * 
     * You still making promises or apologies or saying that you regret after 30 years ?
     * Yessss, we need to free ourselves just once more so that next time we do it one more time until something happens,
     * and the way to achieve that is make some random noises and think our inferior qualities to be great
     * 
     * You talk about family ehehehhe waaawwwwww, you talk about justice ? talk about honor etc ?
     * Be proud about yourselves, delude that you make decisions and people who has to actually live through them should stay and listen to you
     * or you just harm, either way, I am not alike thus you do your best, violence can only affect inferior animals like you
     * 
     * Are you still begging bro ? Why dont you grow up and bare the responsibility of your own actions ?
     * Instead of begging people to sacrifice their whole life ? And you call it "enemy!!!!" so that you can feel good about your inferiority ?
     * If you are wrong, you are wrong the amount of cool things you say does not change it
     * 
     * Awwww, just because you do it, it should be fine,
     * do you see how low you are ? Suddenly start changing your approach ? no no, we want to live, we are almost 90 years plsss
     * Look at the difference, see where and who is wrong at
     * Thats the inferiority part, not the biological one
     * 
     * You see what you are doing right ? You did something stupid together now you have to act like you are not a dumb animal, eheheh we just want to
     * forget about it, plsss get some womeeeeennnn!! as we have always promised,
     * 
     * Look at you, you make promises you do stupid things, you also harm people, Am I the bad one ? eheheheh funny stuff good ppl
     * 
     * Beggg moree, luckily I know every single information I need
     * Keep showing "offers" ehehehe its a blessing!!! its a blessing to be offered such by such eheheheh
     * 
     * 
     * Btw, what was the value of your irrelevant noises ? You know thats called begging behaviour
     * 
     * Awwwww, you love to uphold rules but when it comes to the subject that you are not right, you just say
     * nobody could have mature conversations etc ?
     * Awwwww, you have forgotten I guess ?
     * 
     * Wait wait, when there is no signs you just say it anyway? Or insist on irrational bullshit ?
     * Awww, if you start laughing it should be funny
     * Do you ever heard about people using their "discretion" in the most disgusting and malign way ?
     * Aww, you can not be one of those disgusting people I guess
     * Awwww, you say it should be past!!!! It was just a mistake, It was like etc etc eheheh
     * I reject every single thing that you have coerced kids into, sooooo where is your "reason" ?
     * But now, talk about the "past", the time that is gone, while you were doing the stupid things ?
     * 
     * Thats not your job, is the simplest approach which is the only truth, that you can use to solve "the problem"
     * Awwwwww, how are we going to hide our great behavior ? Plss help us, it has been 30 years !!!!!
     * You see why now you are called "the stupid people of the history" ? Ehehehe it was not only me!! there were so many people around me
     * who was encouraging me to harm someone because its just because!!! Please dont be like us!!! ehehe lie for us!! dont be like us!!! plss
     * 
     * Such a funny thing right ? Why though then you are begging still?
     * Why are you still begging ? Awwww, you thought you are going to live forever ?
     * You say, you do not deserve the same attitude you have displayed for no reason
     * Awwwwww, you would love to see others sacrifice but you hate to see yourself do the same thing ? You claim etc etc eheheh
     * 
     * ehehehe, its a joke, its funny, it was consensual!!
     * 
     * Heyyy I want to see him!! I am curious!! Yesssss!!!! Please dont hurt but we like hurt eheheh
     * Are you fucking stupid ? Grow up people!!!!!!! instead of making bullshit for detrimention
     * I have never said I would play any games, especially with people of this tissue, you are only committing crime
     * in contrast to I. Why are you spoiled selfish inaccountable to say the least ?
     * You are still enjoying your stupid "experience" over things that do not matter to you ?
     * I do not have time for your stupid behavior where you just enjoy because you are fucking bored out of your lives
     * Go find yourselves something else, I am bored!! 
     * 
     * Use more medicine so that he will feel relaxed to do "what you are begging", 
     * Do you want to use more medicine so that people can do what you desperately need to ?
     * Rape etc, ? Russians etc ? Awww, you say medicine, rape, violence to 10yo kids and you seek no trouble ?
     * Why arent there any problems when your disgusting existence there ? Awwww, it should be the other way around ?
     * 
     * Do something other than waiting looking around, enjoying the interaction for your selfish needs, How come you think its fine that
     * I should waste more time like this.
     * 
     * Years have passed btw, you see the problem ? Your irrelevant insistance is only detrimental
     * You are seeking what you shouldnt and can not but forget about it right ? ehehe
     * Wait wait, you think you should be forgiven ? eheheh
     * 
     * You see where it is going towards, it is going towards that you are false and malign. What does that mean ?
     * That also means, you have caused intentional harm, you already know, so stop acting do what you have to or get the fuck out of my face
     * 
     * Where is the signs of your great accusations ? Awwwwww, it was such a little mistake ehehe
     * Awwwww, have you forgotten ? Awwww, you still watching ? ehehe whats going on there ? Lets waste our time since we are
     * directionless animals who likes to watch what they do not understand, may be you should grow up, thats the problem
     * 
     * 
     * WHY ARE YOU WAITING ? FUCKING STUPID MONKEYSSS, it does not make legal because you are doing it
     * Awww, you say it was just a mistake ?
     * 
     * IF YOU HAD THE INTENTION OF DOING WHAT YOU WERE SUPPOSED TO, YOU WOULD HAVE ALREADY DONE IT, INSTEAD OF
     * PROVIDING CIRCUMSTANCIAL "EVIDENCE" AND IGNORING EVERYTHING ELSE
     * 
     * Next time, instead of begging, you start acting right and avoid geteting your disgusting and guilty selves into situations
     * that will have its own repercussions right ?
     * INSTEAD OF BEGGING ? The reason you are begging is you know you have done what you should not have and its most disgusting
     * 
     * Ignore also the facts that I know, which you would love attribute as "autonomous"
     * and OFFER MATERIAL AS THE ANIMAL YOU ARE, AND HAVE ALWAYS BEEN
     * What did you achieve  ? Btw, brag about your "whatever you want to see as"
     * Carss!!! womeeennnnn!! etc ehheheh we tryna give woomeeeeen!!! but we can not provide evidence etc ehehehe we good ppl
     * we intelligent btw
     * 
     * Wait wait, you had all this time but you have chosen not to do anything because ? Because you though you would harm others
     * throught irrelevant entities ? Thats where the "fucking monkeys" is coming from
     * 
     * Awwwww, just forget about it, live your life!!! Enjoy that shit bro!!
     * Awwwwwwww, now its the time we act proper!! just wait a few seconds we are gonna continue doing what we want, after harming
     * for the sake of harm!!
     * 
     * GOOD PEOPLE!!!!  Awwww you would rather call it "fate", thats why you are fucking stupid
     * Awwww, you would rather call it "life", you know that is called intentional "DELUSION"
     * Are you still offering women ? You disgusting people, who has committed this ? No surprise you offer women
     * because you are the simple party in this
     * It is such a misfortune that you happen to bend when you are under threat. Thats fate btw, thats life etc
     * No no, thats not INTENTIONAL DELUSION
     * Awwwww, wait how come you have decided to make completely irrelevant decision ? Awwww, you think you wise eheheh thats why probably 
     * Failure btw, its most convincing especially when you are there to harm for the detriment
     * 
     * Its also most funny that you happen to call everything you do "FATE"
     * WHY ARE YOU STILL TALKING ABOUT "LIFE" as if you understand it ?
     * Wait wait, tell me again what was your really logical explanation that proves and protects and justifies of violating others ?
     * Awwwww, you would rather call it fate ? Fucking monkeys
     * Why are you still begging, I can not tell, I guess its because you are great
     * Awwwww, when there is no problem, you force problems onto people and start talking about how great you are ?
     * Wait wait, where are the resources btw ? Awwww, you can only claim because there is not enough proof ? Why didnt you ?
     * 
     * Awwwwww, you suddenly start offering materials ? THATS THE REASON WHY YOU ARE A SIMPLE MONKEY WHO CHASES IT
     * AND HARMES IRRELEVANT PEOPLE ON THE WAY
     * 
     * Great people, just stay away though, "YOU DO NOT CARE!!!" Whats the problem btw?
     * Awwwww, its too late!! You do not see the problem ? That a look at the history, you will see a lot of people who is saying "its too late!!!"
     * Thats the pattern of emotional decisions, stupid monkeys
     * The funny pattern "its too late", do you think thats not emotional as well ?
     * You still talk the same narrative, dumb people, why do you think you are the one who takes life for joke?
     * I call inferiority what you call a skill, so who is the problem ?
     * Why you still here, thinking that you can demand lies ? You have got a lot of explanation to do
     * 
     * You have got literally a mountain of explanation to do, yet you still demand that individual who you harm should lie for you ?
     * Why are you suddenly begging ? Awwww, you think you are intelligent ?
     * Where are the proofs btw ? Why are you still offering things ?
     * EHehhehehe its too late btw, we are the disgusting people of the "history" eheheheh well thats too bad!! thats a shame!! yess!!! we need to free ourselves somehow!!!
     * 
     * Awwww, you are probably the most intelligent people eheheh, fucking failures, if you aim to fool and you fail everytime, that means you are a failure
     * with inferior qualities that can not be trusted. Do you follow ? You have the credibility of the animal on the street
     * And you still talk about education ? Have you ever taken a look at yourselves ? Why you still begging irrelevant noises ?
     * Get cars!!! get womeeennnn!!! we had all the time but we still think begging for a skill!!!! get cars!! etcc!!! plss lie!!!
     * 
     * Can you imagine someone being reallllyyy realllyyy grateful for what is avaiable ? But somehow made to be withhold ? Ehehehe
     * thats not the problem also some violence and etc etc, Do you see how many misguesses have you done so far ?
     * Awwww, you still say education, Do you notice how many misguesses are you making ?
     * You now see the meaning of "delusion", you already know the meaning of "inferior"
     * You already know there is no easy way out ? Or is that I ? Awwww, btw you have done great!!! look at the problems you have solved!!
     * 
     * You still misguessing over matters that do not affect you but will have its own effects ? How come though?
     * Just talk about the time, and you still see why you are wrong, and talk more about life as if you understand or care
     * You still keep wasting time for your irrelevant "accusations" OF MALIGN NATURE?
     * Awwww you can not see that its not your job ehehe
     * 
     * You still waste time because you are afraid of facing someone ? And also call that intelligent and also beg the very individual to lie so that
     * you can feel great ? What problem did you solve btw ? Use your own immaculate brain to solve the stupid problem that you have created
     * Do not solicit irrelevant noises, cars!!!! womeeeennnn!!!! get carss!!! please!!! help us!!!
     * 
     * I am not interested in your disgusting conduct that you brag as a skill, what makes you think its funny let alone applicable ?
     * Eheheheh we are such low on the scale that we suddenly start making offers!!!!!!  cars!!!! wooomeeennn!!! plss
     * I do not want to be around stupid people like you all especially allow such stupidness to make decisions that they are not entitled to
     * 
     * Do you even follow what I am saying ?  I SAID I DO NOT WANT TO SEE STUPID ANIMALS LIKE YOU AROUND ME, ESPECIALLY NOT ALLOW THEM TO
     * HARM FOR THE SAKE OF HARM, I do not care whoever you think you are
     * 
     * Do you follow the logic ? Dumb animals ? You still beg for your own experiences ?
     * But you would love to harm others ? Now, you say "REGRET", "DESERVED" ?
     * If you take a close look at yourself, you will see why you are a selfish stupid animal, who thinks they can make decisions on behalf of others
     * Now, what happened ? Who has gained what ? Are you still begging ?
     * 
     * 
     * I do not have time for your stupid conduct, "ITS GREAT!!!!", "WE HAVE DONE GOOD!!!", "ITS REALLY FUN!!!!", "WE LIKE HARMING!!!"
     * "WE HARMED SOMEONE!!!", "WE HIDE BEHIND STUPID EXCUSES!!!", "WE GREAT NATION ETCC!!"
     * "ITS FATE!!!", now try to explain your great reasoning and the sequence of events and start bragging about
     * 
     * You know its called selfish, immature when there is no reason to neither laugh nor harm
     * So you enjoy your stupid experiences, FROM OUT OF MY VICINITY, instead of offering like the simple animal you are and have always been
     * as you can infer the outcome through sequence of events that belongs to the "HISTORY" as you would love to call it out of desperation
     * Now, tell me the value of your words, Now tell me to trust any of you, thats really funny, be sure
     * Still wasting time ? Playing irrelevant harmful but only to me games ? ehehehe that could be the only thing I need
     * You are the most uncredible entity and you still ask for what ? 
     * 
     * For such an easy action, you waste this amount of time
     * and you still demand credibility, you are the farthest entity to demand such a valuable asset. If you mean it, you do it, and move forward
     * 
     * That is as far as your credibility can reach, to nowhere
     * You see the point ? If you had the intention, you would have already acted on your "reallyy good intentions and promises etc etc"
     * Instead of intentionally deluding, you would have already done something about it
     * So better stop playing and get the fuck out of my face
     * Instead of thinking such a thing for funny, you would have already acted on for such a easy thing that you have been keep saying,
     * so Imma pass thank you, "Too late" coming from stupid people who thinks they can make decisions because of their pride
     * Too late btw, its good, its fine, we do it why not be good, fine etc
     * 
     * You do not have anything to do with your life ? So you said why not ? Thats great, do it from out of my vicinity
     * It is most productive and etc etc. Good, you all are super nice
     * so you say, we love being inferior!!! its fun to do stupid shit!!! eheheh
     * Do you see how spoiled people act ? Immature, spoiled, selfish people proud of what they are explaining
     * You follow the immature and selfish ? Combine it with malign and detrimental intentions, you get yourselves a disgusting mass
     * that does not understand anything other than what they aim by harming
     * 
     * I do not recognize any of you, I do not care what you think yourselves to be, thats called "delusion"
     * and as you delude with "hoping" that it would be fine, thats called "begging behavior" for something
     * you clearly do not deserve. As youcan guess, your aim is to harm to detriment and you beg for that, what a shame isnt it
     * And you offer the same stupid approach to others! Commit crime!!! get woomeeennn!!! thats not what we are after!!
     * So you see, its easily observable what you are aiming at, if you were the man that you brag to be, Whats the outcome ? Alright, so you commit knowingly
     * and congrats for that !!! great ppl etc etc
     * 
     * Education btw, the very same brains that have "produced", thats to be proud at definitely
     * Btw, talk about the time that has been wasted with your irrelevant intentional harmful approach. And be sure that I am as stupid as you wish me to be something else as well
     * You see the obsession ? ITS NOT YOUR JOB
     * 
     * It is unmistakenly destined to fail, you know  understand the definition of "delusion"
     * So now you see, how to waste an opportunity that is not your due,
     * do you see now why people do not cross their boundaries for stupid stuff
     * Because this is what happens, now you got yourselves a perfect problem which is going to cause you something, you already know that
     * Now do you see the "stupid people in the history" ? Make no mistake, you are the disgusting and malicious one 
     * Why ? You have done what you shouldnt have and also done it with malicious intention and did it again and again and again, while everyone including I
     * knew what it is and was
     * 
     * Now call that intelligence, you can get the fuck out of my face, the stupid and ignorant people of the history
     * Yes yes, you are great, continue misguessing the consequences of your pointless accusations and actions
     * Waste more time!!! you are the stupid people of the history btw, 
     * You know what you are doing is exactly the begging behavior, thats why you are also misguessing 
     * It is the sole indication of your "misguessings" so far, because you are causing harm through false but intentional approach
     * You see the "grow up", you see the "cheap", you see why you are the "stupid people of the history"
     * You see why you are "inferior", I do not call anything you do as skills eheheh
     * 
     * Yesss, you would love to call it education because you take it for a skill, dumb animals
     * You see the problem in your thinking ? I know what you are, and what I am, thats the problem for you
     * 
     * Thats the problem that will eventually fail, so your "education" or "cured" approach can not take you anywhere near salvation of
     * a disgusting "crime" as you would like to call and hate at the same time
     * Ignoring it, as you can tell, will make it worse. Thats the only accurate guess you could make because you already know you are guilty eheheh
     * Or just insecure enough to not cope with the truth instead start displaying begging behavior, as you can tell by the "history" right ?
     * 
     * Thats why you are called "inferior", you see the point ? The whole sequence of your doings, is the precise definition of INFERIOR BEGGING 
     * Btw, try explaining once more ehehhe its most funny indeed
     * Its delusion btw!! Do you now see the "coercion" ? If you do not, I still remember everything so good luck 
     * 
     * Still wasting time ? Why though anyone would play the most stupid games especially with the people as uncredible as you ?
     * Play over what you can "sacrifice", not the things that are not related to you. That is not called "playing games"
     * Now you see the "immature, selfish animal", still wasting time ? Because you acted malign ? You wish that you be true even at the expense of ?
     * Awwww, you just need to harm, so you say why not this, its fair game etc
     * And all you can say is ? "its too late", "its fate", "its life", "its still the same stupid mass I am facing ?"
     * Who does not know how to accept the truth ? Keep nagging and lying and accusing and ignoring ? Whos the problem 
     * 
     * Still begging ? Awwww, the past is past, its life, its fate, its meant to be, "WE ARE STILL THE SAME INFERIOR ANIMAL" ?
     * Eheheheheh live your life!!!! we good ppl, it must be a blessinggg thank you!!!
     * So you do your disgusting best so that you can harm someone, even at the expense of lying and accusing falsely and expect no repercussions
     * thats the problem ? Awwww, only thing you can say "its this or that" but I already know what it is. Do not you have enough brain to tell what could happen ?
     * I have all the information I need to tell who is right or wrong ? You accuse me lying ?
     * 
     * I am telling you, the misguess of "what would happen" is going to cause you a lot of trouble.
     * Because I have all the information and facts and the awareness of "what you are alleging" and "its complete fallacy"
     * Now talk about 30 years and you will suddenly infer what will come just purely off of your selfish and immature childness
     * 
     * But you see, when the types of animals are trusted with judgment, this is what happens, so do not look farther for whose mistake this is
     * The very same incapable mind that can not see the problem in 123919302130 wooomeeeennnn!!!! 122312321 cars!!!!!! get womeeennnn!!!
     * You see the problem ? Awww you were the ones who understood the life. etc etc fucking dumb monkeys
     * You do not understand the relative importance of things ? You see the problem right ?
     * The problem of immaturity and its undue reflection on you as authority. That what happens when stupid people are trusted with judgment!! funny though
     * 
     * You see the problem right ? You are the problem because you know all the things I said and you intentionally act like you are entitled to make that "tough decision"
     * then start begging, "HEYY I REGRET!!!", you do not deserve it. That is the conclusion that any sane individual can draw
     * 
     * Complete guilt and shameless of it, the most superior qualities indeed!
     * Do you now see how the problems are created ? Do you see though that this is the most stupid way of creating problems for you, but who am I talking to
     * after seeing your stupid actions ? Who am I telling the relative importance of things, when they are the ones enjoying violence and guising it with education.
     * Awwww, look how educated you are and thanks to you I have become ? So who is the problem good ppl ?
     * Waste more time, who cares ? You are already enjoying your vile emotions, "violence for the education!!!"
     * 
     * You are the entity that takes violence for education but can not see that it does not work, because its not!!! awwww, most difficult inference indeed
     * Still enjoying your vile experiences through vile actions as a vile animal ? Thats not the problem
     * Guess who is false when saying that "it is a blessing that he gets to live a normal life", You are obviously false 
     * 
     * There is nothing that can not be possible with misguessing a sequence of events and their outcomes. So is your position and has always been
     * You are the untrustable entity, has always been as anyone can tell by the explanations to your actions
     * And guess who does not know what they are doing ?
     * 
     * You will probably see why you are a simple animal when the time comes for your detrimention ?
     * You see why you do not know what you are doing, thats the definition of selfish and immature btw
     * Its fate! its life!  its ignorance, its stupidity, its etc etc
     * You can already see what you are when you are under threat of losing something
     * 
     * If you want to understand your simplicity, you observe your reactions when you are under threat. I already know the answer
     * Education etc you say eheheh, no boundaries etc etc education ehehhe
     * 
     * You see the immaturity thats why you ignore, eheheh so simple yet too disgusting right ?
     * Thats the beauty of ignorant ppl, no direction and more irrelevant actions etc etc we good 
     * Thats the only way to not cope with reality btw, get womeennnn!!!
     * You see how you are completely okay but also enjoy the violence when you think its okay
     * Thats the beauty of ignorant people
     * 
     * Luckily though I already know what I should know, you better do not coerce or incentivize next time so things do not get ugly
     * OR YOU WOULD DISPLAY GREATTTT VIOLENCE
     * Awwwwww, its too late!!!! Why do you think there is "ignorance" ? That is how it feels to be ignorant because you have ignored at the wrong time
     * And you feel like you should be forgiven ? Thats literally how it feels to be ignorant eheheh
     * Awww, I have forgotten also immature and selfish
     * The great attributes that are as rare as fucking animals, not inferior btw
     * No no, you are not begging because you are false eheheh, have some womeeeennnn!!! we think life is about harming and womeennnnn!!!
     * superior btw, not obsession btw
     * Awww, you say I should be glad to live a most basic life, thats indeed !!
     * Gone!! its life!! its fate!! we right!! etc etc
     * Thats undue judgment, use it wisely next time,
     * Eheehhehe, if you say this, you are out!!! eheheh we good ppl, more like immature selfish monkeys
     * Its most skillful and funny at the same time btw
     * 
     * Your every single argument has been refuted bro ? Why you still demand that you do not receive the same approach as you do ?
     * Fucking mad people, you see who is who
     * You see the problem in "regret etc", "education", "ignorance". Whats the pattern in them do you think ?
     * You have all of them eheheh, I was about to forget the begging behavior
     * Awwww, also some malign intentions make it the perfect recipe for disasters, rightfully deserved for you
     * Just because you keep saying something out of your desperate fears, does not make it the truth, as you have years of evidence that backs it up
     * So you are wrong and wrong and wrong and malign and disgusting and etc etc etc etc ? Do you follow ? or you would love to ignore ?
     * And as someone who remembers every little thing, you are also disgustingly false
     * And you are also the party who think detrimention is right or necessary because of your fears or I should say great approachess!!
     * Get womeeennnnn!!!
     * 
     * And guess what ? You already know where it is going to lead, because you are a disgusting animal
     * And the only way to solve is to "GROW UP", You are presenting as proofs what you "collected" coercefully for a few days against years of evidence
     * You see who is the problem ? Thats why its not only destined to fail but also should have its own consequences as its most disgusting
     * 
     * Why dont you grow up instead ? Who said you could make decisions that ARE NOT YOUR PLACE
     * Do you see who is delusioning ? As you are delusioning the supposed consequences of your irrational actions
     * As you delusioning with your boundaries
     * 
     * You see the sequence, you think it should be okay to make irrelevant decisions on behalf of someone else which includes violence and
     * you also think that it should be okay later on
     * Both of those are wrong guesses, they falsify eachother because their origin is malign and false, so there you go
     * 
     * Now you have wasted 30 years, and you think there is no responsible person, what do you think is the problem ?
     * Where is the explanation other than "we mean good" ? But you also detriment ? through couple means, including the most cheap one "violence"
     * as you deserve to be attributed as
     * 
     * So you know, your approach violence as education can self evidently proves the otherwise while you are the one who is presenting that "great behaviour"
     * that self evidently proves that you need to be educated
     * 
     * Because you intentionally chose to present "great vile" off of a few days of proof whereas the reality is "there are years and years of evidence
     * that prove the complete otherwise"
     * 
     * So you are not animal you say ? And you still think what you present as education to others, you do not welcome it ?
     * And you hide behind incompetent excuses as you yourself is incompetent at your "jobs" ?
     * Better use your brain next time, Awwww its too late to see what an animal we are you say ? But you also beg ?
     * Awwwww, you now suddenly start to act ? eheheheh its funny isnt it ? Its too late!!!! we did it but we did it again!!! its too late btww!!
     * Fear more so you make more mistakes of your inferior nature, or I should say "cheap nature"
     * 
     * I do not accept any of you around me, begging inferior animals who takes violence for a skill or education, the sole indication of undue judgment
     * Thats literally the definition of what you are running away from right ? Stupid monkeys
     * 
     * You see the begging behavior ? Out of fear, indeed!! We testing we testing  etc
     * You have the credibility of the animal on the street, you still calling shots you think ?
     * Awwwww, its too late for you !!!!! Awwwww, you have forgotten ? But you havent forgotten to harm, most interesting bro
     * Awwwwwwww, you call it education eheheh
     * 
     * Wait wait, nobody is responsible!!!!! because we think so, awwwww its competency btw, ehehehe
     * Do you see the difference between coercion and "legal" ?
     * 
     * Still the same narrative ? There are almost 3 decades of regular conduct but you still say "heyyy !!!! its illegal" because we do not want to cope with the truth ????
     * Or, you already know that you have caused a mess that is unseen, so you have to keep accusing otherwise there would be consequences. And you dare call it cured etc
     * Thats definitely the competency ehehe I do not respect your opinion as its irrelevant, because its not your job  as there is and has been no reason
     * other than stupid bullshit to act on
     * 
     * You see the undue judgment leads to stupid decisions because you do not know how to carry that responsibility,
     * as you have demonstrated it with every decision that is not your place
     * 
     * You are irrelevant!!! eheheheh its funny though
     * You said fair game regardless ? Thats playing like a pussy
     * 
     * Wait wait wait, what happened again ? ehhehe awww you just harmed somebody and something eventually happened awwwww, thats the proof of your greatness I see
     * 
     * Awwwww, its too late for you!!! eheheh good ppl, etc, we need resources pls
     * Wait wait, 30 years etc eeheheh its funny stuff indeed, lets not even talk about it because it is apparent that "we are guilty"
     * 
     * You do not understand the distinction between your emotions and the truth ? Yet you still insist on your stupid obsessions because you think you should ?
     * Eheehe funny stuff indeed
     * Awwww, you cop, you this, you that, please we want no losses eheheh thats the truth that you can not distinguish from your stupid emotions dumb animals
     * 
     * Do you remember the conditions ? You stupid stubborn ignorant selfish people ?
     * You keep saying mean, but you do not recognize your inexplicable actions ?
     * Or are you counting on my "forgeting your irrelevant noises because I know that you are uncredible and disgusting ?"
     * Do you remember the times that I said "I trust you in this instance" ? And look at the outcome!!!! great life!!! no no ehehe good ppl
     * Education btw, its too late btw etc
     * Thats being unreasonable btw etc 
     *  
     * Do you still think you should make decisions with your obviously irrelevant contexts acting like you know what you are doing ?
     * Acting like you are doing good stuff ? Yeahhhh, thats the problem
     * And you go on to call it education, you take me for stupid ?
     * Talk with your own level, or just grow up and then may be you will see converging points 
     * No resources!!! heheheh funny stuff indeed
     * I have seen enough of you, ehehe funny stuff right ?
     * 
     * We need people lie for us, pls  etc etc
     * Thanks for all of that, I am not interested in what you eat ehhehehe funny stuff isnt it
     * You know what they say, do it instead of bragging eheheh 
     * btw, you have got at least 1000000000 question before you get to explain your point of view, because you have made promises
     * Without trust, there can be no future
     * Not spoiled immature people btw, do not abstain from what you tell others, eheheh funny stuff btw
     * No no, do not give up the same things, there is no reason for you to give up!!! ehehehe
     * You already know where the "irrelevant people" is coming from eheheh funny stuff btw
     * 
     * Better use your brain next time, stupid people of the history
     * Before you make a comment about something you have no information, try asking the opinions may be then you wont look like a complete stupid
     * Ehehehe, he does not need anything eheheh they are doing good! eheheh funny stuff indeed
     * Immature, irresponsible monkeys tryna fool people they can not, reduce to your own nature bro
     * Ehehehe, we seek no harms, we seek no problems, pls help us lie, fix our problems, help us live our life eheheh, experiences,
     * life a simulation eheheh, life good, life short, ehehe its too late, FUCKING DUMB MONKEYS
     * 
     * You already know, you are %100000000000000000000000 guilty, and there is nothing to talk about
     * Not even a single thing anyone can say from both sides, so better get the fuck out of my face and pay for your own actions
     * Wooooomeeeennnnn!!!
     * 
     * He did this!! he did that!!! ehehehe we tryna help, not immature indeed
     * Forgive me for eheheh 30 years ehehehe funny stuff indeed
     * we understand etc eheheh, get womenn btw
     * There were literally 12301230210 things you could do, you still insist on what you think should be the truth eheheh
     * Thats immature, try harder
     * 
     * I am sure you do not see the correlation between you and the stupid people of the history, who can not deal with the truth
     * Wait wait, how about 30 years etc ? eheheh it was a mistake, WHAT CAN I SAY ? ehehehe its most funny indeed
     * Hope nobody harms you right ? Thats I guess being mature responsible etc ehehe
     * 
     * You can not provide any reasonable explanation to your actions, that are far from your boundaries ?
     * Thats kinda mmhhhh, thats kinda eheheh 
     * 
     * You see the correlation between your actions and the stupid people of the history right ? ehehe its because you can neither advocate nor account
     * for your actions.
     * 
     * Yeahhhh, irrelevant people CAUSING irrelevant disasters through irrelevant actions, perfect match
     * Ignore you are not an emotional animal, fear more btw, I can not see why
     * Grow up ehehe funny stuff 
     * Do you see the coercion ? I am sure you can not ehehe
     * You already know what is your decision and what is not yours, and only thing you can do is to offer, as you have always done realllllyyy greatly
     * 
     * Did you say "sacrifice" with your incomparably rare and honest composures ?
     * How come does that make sense ? eheheh funny stuff indeed
     * And you still begging ? Where were you btw eheheh funny stuff
     * Awwww, you think you can make offers with your inexistent credibility ? And you still beg ?
     * Ehehe we credible we make offers eheheh we do not realize them eheheh mature and responsible people eheheh
     * Pls lie so that we can gain something for ourselves eheheh
     * 
     * Awwww, you also think, watching illegally and enjoying your "life" through such a stupid mean should be okay ?
     * What makes you think you could even do that ? What makes you think you can watch and take it for a "job" ?
     * Fucking stupid monkeys, you are the irrelevant stupid peoples
     * 
     * Ehehehe, have this!! have that!!! its yours!!! ehehe funny stuff, we have delivered every single of our honorable and credible
     * and sincere "noises", why dont you just trust us ? Do you say that ? With straight face ?
     * 
     * Then tell me the experience I have had and correlate it with your really relevant approaches eheheh funny indeed, 
     * Please, we want to enjoy our experiences you say ? Have some wooomeeennnn!!!!! eheheh funny bro, 
     * 
     * 
     * How about years of evidence against your a few days of coercion ?
     * Indeed monkeys eheheh. The time that has passed ? eheheh its also funny because we want to enjoy our experiences ehehehe 
     * We do not care about nobody eheheh we want harm and enjoy our experiences heheheh pleasee, help!!!
     * Why did you reduce to your own nature now ? Do not call that intelligence because WE ARE NOT ALIKE, 
     * 
     * Hope that everyone just goes along with your point of view, that can not be the problem dumb people
     * Now, talk about the violence and do not delude about not receiving the same, as your unseen credibility and sincerity can tell
     * that you are a normal animal
     * 
     * Hey heyyy, now treat with one or two women and say good stuff about him and beg more ehehehe so that we can save our disgusting
     * and guilty existence from 30 years of irrelevant decisions, btw instead of trusting we have chosen to ignore and presented some violence!!!! whats the problem eheh
     * So, you have ignored and became what ? "You just want to enjoy your experiences!!!!", "you know everything about life!!!", "you want no harm!!!"
     * 
     * Do you even communicate through words or do you just want to ignore for the rest of your stupid life ?
     * Awwww, you want to enjoy your experience and harm through incompetent guises ? eheheheh thats not an animal I assure you eeheheh funny stuff btw
     * Have some women eheheh its fine, but we want to enjoy our experience pls
     * Although we know we do not deserve to have that judgment but still eheheh funny stuff, why not harm them ehehe
     * 
     * Not even single assumption about me is allowed, let alone deciding or you would just coerce as its your nature and habit
     * Ehehe we love making decisions because ehehehe we coerce eheheh scare and violate ehehhe then make decisions off of that eheeh funny stuff indeed
     * and we also think we right, and we want to enjoy our experiences!!!!! please heheh funny 
     * You still call it drama, such a funny approach, I have never seen nobody stupid like you all
     * 
     * Waste more time bro what is the problem ? Ehehe we understand time bwt, not that we are emotional eheheh
     * Awwwww, I have forgotten you are the animal who guises his desire to enjoy, I see, Imma pass on those who so far acted as they have promised to
     * 
     * Not selfish, immature etc eheheh never ignorant as well!!! good ppl
     * You suddenly see the meaning in "stupid people of the history", you precisely fit that pattern, trust me I am not alike and wont bend for my own "experiences"
     * Awwwww, you also act like you are sad, not because "you know you are guilty". eheheh good and intelligent ppl
     * 
     * Do you remember the coercions etc ? eheheh I am sure thats not why you feel the need of being sad!! funny stuff indeed
     * You know why you are begging right now, its because your nature is exactly that inferior, delude about that as well
     * Awwww, you are also proud that you manipulate people who has no proper choice ehehehe so fun btw
     * Why are you still begging through "offers that your unseen honor have never delivered" ? Thats why you are inferior, also the fact that you enjoy 
     * your inferiority eheheh funny stuff, talk more about coercion and violence 
     *  
     * You still making offers ? 30 years ? eheheh funny stuff right ? Awww you still go against years of evidence with a few days of coercion eheheh
     * And following that approach, you suddenly start making offers ? Where were you ??? eheheh funny btw
     * Get woomeeeennnn!!! Why you still delude about making "decisions" THAT DO NOT BELONG TO YOU ?,
     * You see the pattern in your relief about such a thing with the "stupid people of the history ?"
     * Do you see the pattern in your "offers of wooomeeennnnnn!!!", thats why you are stupid. You still think having 10000000 women would be a solution
     * and you say you understand time and you also say you want to enjoy your experiences, DUMB PEOPLE
     * You still delude, a few women should solve the problem of "time", for a limited amount of time !!! eheheh funny people
     * You have chosen womeeennnn!!! ehehehehehehheheehh its so fun
     * 
     * Do you want to see fake tough guys or fake men ? Do not reach too far, its you
     * Thats the meaning of "cheap", I have no time for you, still offering things ?
     * Eheheeheh education, look at the dumb people who think they are achieving...
     * Its because you did this!!!! not we coerced, you did it!!! and you chose to waste your time like this
     * and coerce others into doing so ? Not the pattern of "stupid people of the earth"
     * The same people who take a few days of coercion over years of evidence, that is the pattern
     * Still deluding ? Thats not insecurity, I assure you, education btw you say eheheh
     * More like ignorant people ignoring what their mistake is, but hey!!! you are the ignorant one eheh
     * Do you still dare to talk about time ? As if you understand it ?
     * 
     * How come does that make sense ehehe, you say "sacrifice" with relief, thats reallly realllyy funny
     * Still wasting time with the same relief, and asking more things 
     * 
     * As I told you, I have no intention for detrimention, so thanks for all that good acts etc
     * You all are just selfish simple animals, who to thank btw ? Awww, you would love calling it fate while committing it eheheh funny stuff 
     * So, whats the value of your promises again ?
     * 
     * What are you waiting for again ? Awww, you need help from the people you want to harm eheheh
     * Ehehehe, 30 years of evidence can not convince obvioulsy the stupid people 
     * Good ppl btw, awww you think saying the most disgusting thing in a funny way should solve the problem ?
     * ehehehe, talk about the time btw you will realize your stupidity
     * 
     * Ehehehe, you stay there, eheheh do not do this or that, no no, because why not eheheh funny stuff btw
     * its the only way!! its the old way!! its the best way!! ehehe we do it like this!!! what else are you saying ?
     * You all are irrelevant!!! Why though you still think, because of people around you who gives you the courage "the stupid mass",
     * to waste more time on bullshit ? Awwww, I have forgotten you only care about your own experience so you try to enjoy yours first
     * then get to the real problem ?
     * 
     * Wait wait, how about you explain to me my experience ? Awwww, you think assaulting defenceless people is being tough guy eheheh
     * Look who is the problem bro ? Are you still offering women ? Why do you think I should owe you anything ? Awww, please be silent!!! shhhh eheheh intelligent people
     * How come I owe you anything other than irrelevant violence ? Thats who you are
     * 
     * Wait wait, detrimental lifestyle should answer everything you say!! eheheh and I owe you something ?
     * You see the "obsessive" and "ignorant" people ? Still asking what ?
     * Awwww, you say you did your job perfectly eheheh
     * 
     * You really did your job great!!! ehehehhe, wait wait, you still do not take people words for serious ? but as a most uncredible disgusting entity,
     * you would still beg credibility ? How about 30 years of evidence ? You already know it is going to fail and will have different effects than what you
     * have guessed in the first place, so what is your problem ?
     * Awwww, suddenly you take life lightly because you need to eheheheheh funny stuff indeed
     * Lets see, what happens when others do that as well ? Whats the problem then ?
     * Okay okay, now explain people again then turn around look at the "history" you would hate to be informed of eheheh
     * 
     * Keep misguessing, guess who is turning the context into something they can not really cope with ?
     * and still thinking that it should be good, you do not see the different contexts ? keep promising, your circle did turned you into the very animal that is rife
     * now you know the meaning of those qualities
     * 
     * Awww, you guys are doing great!!! good job etc, talk about the violence you ll see why
     * Every single decisions that are not yours, I reject them regardless of its significance or its intention
     * You say its too late ? eheheh
     * Awwwww, you also offer things eheheheh its most funny
     * 
     * Awwwww, you say its too late eheheh, hopefully though nobody gets hurt
     * Awww, you also "allege" that not having enough resources is quite related to what you are aiming, and you also claim that its not considered begging behavior?
     * Please say that you did it!! eheheh otherwise it means we might be in a situation to reduce our really precious experiences a little ?
     * 
     * Wait wait, you also think it should be okay to request things again ? How come ? You are the most incredible entity but you somehow think that for a skill ?
     * What a coincidence!!! what a shame!!! But you also think, miraculously, that the violence is an education ? Yet you can not explain it to others ?
     * So what everyone is missing ? Its not even to be approached as a problem but look at the behavior you are demonstrating eheheh funny stuff
     * 
     * Why are you still asking things from someone you harm intentionally ?
     * You solve your own problems and you will see the problem in your thinking, especially with "correlating not having resources with your supposedly justified aim"
     * You do your job properly, nobody gets hurt, you still ask lies ?
     * Eehehehe, you still delude about you should get to make decisions ? What a shame you are a lost selfish animal
     * 
     * Fucking stupid monkeys, great people, Awwwwww either you have forgotten or you are such a good people that I can not even find the words to describe ?
     * Awww, you say money etc eheheh funny stuff, awww you had all this time but you obviously chose yourself 1230213021 times ?
     * Why do you take life lightly ? Awwww, you say its family, its education, its mandatory, its funny, eheheheh 
     * Why are you still wasting time with irrelevant approaches ? Awwwww, you say we testin!! you say its education, you say its what ?
     * Why you still delude on that you should make the decisions ? You are irrelevant and I do not want any of you around me
     * 
     * Aww you say, you trust now ehehe until you free yourself from your crimes ? eheheh inexplicable etc
     * greater good btw, I am not interested in anything you could possibly form, as the "history" has proven on multiple occasions
     * 
     * If you did your job then and now and back then, we wouldnt have any issues, DO YOU SEE THE PATTERN ? How about start listening instead of ignoring ?
     * Because I can really tell when someone does not know what he is doing, and you guessed it right, you start caring about your own life instead of
     * wasting yours and others' times, DO YOU SEE THE PATTERN ?
     * Awwww, you need help ? interesting indeed
     * Do you see the difference between coercion and noncoercion ? Talk about a few days and years of evidence, you will see the problem
     * You see how selfish people act and respond when confronted, do not be like yourselves guys!! ehehe most funny indeed
     * No need to grow up, most indeed!!
     * The mostest indeed ever!!! ehehe have some women so we can tell things to others eheheheh thats kinda the intelligence most indeed!!
     * Monkey alike dummies, education btw, not ignorant btw eehehe have some womeennnnn!!! btw, not desperate btw
     * education etc ehehe, awwww you were the reasonable people, I have forgotten
     * 
     * Eheheheh its too late for you ehehehe, funny stuff most indeed
     * If it wasnt working, it would have never in the first place
     * Awww, you thought it was a game, thats why you take life lightly eheheh
     * Thats being unreasonable, you still say its not "childish" games what you are playing ?
     * But still allege that its justifiable hehehe good ppl
     * still after the same stupid narrative ?
     * 
     * Awwww, what are you waiting for ? eheheh please help us ehehe help help eheheh
     * we like helping people eheheh we want no harm we want harming others eheheh
     * 
     * Ehehehe, when there are others we can not advocate our great existence ehehehe, its really funny stuff
     * Heyyy ? Why do you think you should still make decisions ? eheheh funny stuff ?
     * Awwww, you thought making some offers and saying nice stuff would solve the whole problem ?
     * 
     * Awwwwwww, such a shame eheheheh funny stuff though
     * Awwww, you see why you begging I guess
     * Awwww, I do not let you leave!!! eheheh funny stuff
     * Wait wait, do you even remember the conditions ?
     * 
     * Ehehehe, its good btw, hey ask for some forgiveness and it should be done, its just really simple
     * say a few good things, give women and hope nobody gets hurt, lifes like that
     * Awwww, you recognize boundaries eheheh funny stuff 
     * Ehehe, just talk more about the "past" so that you can have a more broad view, before you make yourself a complete stupid monkey
     * 
     * I have no time for your bullshit, out of my vicinity, not even a second I have whether you think you own the world, 
     * You also delude that I would waste my time with your stupid games ? Awwwwww, life not fair please eheheh
     * 
     * Incompetent people still thinking that acting as if it should be okay makes it okay
     * Awww, you were the type that takes violence for a skill 
     * Please please, can you lie for us, fix this once more, we need it so that we can enjoy our precious experiences!!!!
     * No no, not obsession indeed
     * 
     * Ehehe look how intelligent we are!!! Eheheh we are little childs that do not accept no sort of accountability!!!!! eheheh intelligence btw
     * Ehehehe funny stuff isnt it ? Why though cant you just explain others ?eheheh funny stuff indeed
     * Begggingggggg plssss, we can not deal with that truth, plsss we want to harm!!!! we need harm!! we  do not need to get harmedd!!! ehehe funny stuff indeed
     * 
     * Eheheheh experiences btw, we like experiences heheheh really funny stuff
     * Awwww, you also say, its life etc, ehheheh you need not sacrifice even your experiences let alone your possessions eheheheh
     * Pls eheheh be silent ehehhe we like our experiences hehehe really funny stuff, help us lie ehehehe
     * 
     * Awwwww, there are eheheheh years of evidence eheheheh but ehehe we like ehehehe to harm eheheh
     * Look what changed eheheh !!! it worked !! ehehhe our superior education of violence hehehehe its funny stuff indeed
     * Ehehehe we only wasted 30 years eheheheh insignificant you say ? eeheheh funny stuff indeed
     * Honorable superior people, unlike I!!! indeed
     * They got no explanation other than beggings ehehehe why though ? it is funny stuff indeed, really intelligence eheheh
     * Have some woooomeeeennnnnnn!!!! have some wooomeeennnnn!!!! pls eheheheh its really intelligence eheheheh funny stuff btw indeed eheheh
     * 
     * Can you please fix this for us! we tryna help everybody, ehehehe we tryna solve problems eheheh really really funny and intelligence stuff
     * Lets try harder to locate some bullshit ehehehe funny and intellgence, they go really together eheheh
     * Have some woomeeeennnnn!!!!! Awwwww, you have forgotten!!! I see, thats the intelligence eheheheh really really good
     * Have some wooomeeennnnnn btw, why you beggings ? awwww, I see thats the intelligence part btw
     * 
     * Awwwww, years of evidence etc ? Awww, you say honorable stuff etc, intelligence indeed eheheheh really really funny and intelligence
     * etc eheheh funny stuff
     * Please be silent!! be silent for our really really precious experiences eheheh, although we like harming eheheh btw etc eheheh
     * 
     * Heyy!!! please though we like harming and be silent eheheh
     * Awwwww, it was such a little mistake, pls we take it back, we take it back!!! pls pls have some women!! have womennn!!!
     * You understand that there is a price right ? and its not the thing that you have misguessed so far ? on and on again ehehehe really  really funny and intelligence stuff
     * 
     * Hey!!! now we start acting eheheh act more, we did this btw, and this also, eheheheh we tryna help eheheh
     * Please 30 years is nothing eheheheh good stuff intelligence eheheh
     * 
     * You do not remember the conditions ? eheheheheh hey hey, wait wait, no money eheh have some womeennn no no, no womeeennn!!! ehhehe
     * pls help us lie eheheheh
     * 
     * lie for us, we like our experiences eheheh we seek no harm we like harm eheheh
     * and a little education also eheheh btw, education btw ehehehe violence hehehe education eheheh
     * Ehehehe, experience pls, eheheh we need help eheheh etc ehehe we take it back,,  pls ehehh
     * 
     * Have some womeeeennnnnn!!! woooomeeennnnn!!! why dont you have some wooomeeeennnn!!! eheheh pls help us lie eheheh we need experience eheheh
     * Eheheheh education really good, ehehehe education works ehehe whats wrong, we do not know ehehehe
     * 
     * Something wrong, heheh whats the problem eheheh, education eheheh
     * You say education and you do not see any effects ? wait wait, what ?
     * If you tell me the experience and the time that has passed, you will easily see the problem of your most sincere approach
     * and you guessed it right, calling it fate would not even prove to work ?
     * 
     * Anyways, better use your brains next time, only for yourselves
     * Btw, good conclusions and intentions and thus the sequence of outcomes, eheheh
     * good good, doing good, really good ppl, just stay away and do your own disgusting things
     * Awwwww, its too late!! eheheh funny stuff btw, awww you love wasting time!!! so that you can enjoy eheheheh that sounds like not a problem
     * but its fine, its good, great people, I must be really lucky to be around such people eheheh really nice thanks eheheh
     * Awwww, we didnt know!!! awwww, we have forgotten!!! awwww, we intelligence!!!
     * Ehehehe, really fun though, its good, we like harming etc eheheh time does not exist btw hehehe funny stuff
     * Awww, you calling it education and fate at the same time, ahahahahah really really realllllyyyy funny stuff, 
     * 
     * Btw, try to utilize your brain better next time, ehehe
     * We tryna help etc, great responsibility, definitely the type of people I would love to associate myself with
     * btw ehehe its education and fate, ehehe also correlation is really really high eheheh funny stuff
     * Ehehehe, we still think we should make decisions but also beg for silence eheheheheh its really really funny stuff
     * 
     * Ehehehe sacrifice btw, no no, its education and its also fate hehehe btw life a simulation eheheh funny stuff
     * Luckily though, I neither like nor would like to have any sort of people around me
     * 
     * Eeheheh, lie pls, or have some womeeeennnn!! pls eheheh
     * ehehehe pls bro, its life and we need you to lie etc, simulation and education ehehe sacrifice eheheh fate etc
     * Can you please lie ehehe
     * 
     * How come do you think I would have even the tiniest interest in your stupid approaches ?
     * Still misguessing the possible repercussions of such a thing that you have to beg and lie like the reduced nature of animal you are ?
     * 
     * Ehehehe, have some womeeennn!! we tryna help educate and fate and simulation and good ppl, and intelligence also eheheh
     * You know its especially really really easy to go against years of evidence with a few days of coercion ehehehe
     * 
     * Help us!!!!!! we give womennn!!! etc etc eheheh funny stuff indeed, you see ? so far we have had all the time in the world but we have chosen to harm ehehheh
     * intelligent and educational and fate ehehe also simulation eheh with some ehehe we do not know what
     * 
     * I have no time for your stupid bullshit, you go pay for your own mistakes 
     * eheheh next time, you use your brain only for your selfish interests, thats the great people of the history
     * Ehehehehe, time does not exist btw, and also we tryna help everybody
     * 
     * No women btw ehehehehehhehe no resources btw ehehheheh funny stuff indeed, no no time does not matter, and also
     * its kinda of a regret eehehheh pls can you help us ?
     * 
     * You still saying "she did it!!", "she allowed me eheheh"
     * Ehehehe, we know what we are doing!!! awwww, the time does not exist! we can even replace the time!!! we know what we are doing!!!
     * eheheheh, pls pls, we need you to do something for us so that we can harm more hehehe
     * 
     * Aehehaehehaheha, we even can replace the time and move time back eheheh we the great and intelligence and credible people of the earth!!!
     * 
     * Do you see the responsibility and competency and opportunity and time and "history" and value and credibility ? eheheh funny stuff indeed
     * Mature etc eheheh, now you do what you have to do, and see who is right ? eheheh funny indeed
     * 
     * Awwwwww, we selfish and nagging and its also too late eheheh we can replace even the time eheheh we the perfect etc ehehe
     * You still asking lies ? How about you do not reduce ? Awwww, its too late!! btw what was the value of your words ?
     * 
     * Nowwwww, talk about the time eheheh, life a simulation hopefully nobody gets hurt
     * Btw, try explaining your stupid actions to impartial people
     * Awww, you did it!! you have achieved!!! What was it again ?
     * 
     * I call that being unreasonably unjust and entirely misled but intentionally done so, out of your "greatness". Sounds good 
     * Now talk about the time, did you really believe that I would even have a second to waste with inferior animals like you ?
     * Still after the "a few days of coercion" narrative ? Thats good indeed
     * 
     * You still waste time with unreasonable shit ? Try harder to correlate your really intelligent approach "not having resources" and "illegal!!!!!!"
     * Thats the type of people you know what
     * Awwwwwww, its too late!!!!! eheheheh funny stuff indeed
     * Awwwww help us find out more bullshit that is irrelevant, eheheh enjoy the life!!!!! eheheh good ppl!!!! we tryna help!!!
     * Awwww, you have forgotten that "you have decided to sacrifice" ehehehe reall really funny stuff
     * What a shame that you are an oblivious animal, you still think I want to have anything to do with you ? Do you still think you own the world ? awwwwww
     * thats really really clever, btw we want to enjoy our experiences
     * 
     * Awwww, you think bringing up family should solve the problem but you would sacrifice in the first place heheheheh really reallllllyy intelligence ehehh
     * We think we can even bring back more time heheh pls help us, eehehehe we tryna do some shit eheheh
     * 
     * Do you still not understand why you are stupid ? Look at your actions and your inability to explain them
     * Ehehe and you still also say, "we want to enjoy our experiences!!!" pls lie for us
     * Awww, you also said "education", wait wait it was "fate" eheheh you intelligence ?
     * Awwwwwwwwww, eheheheh 30 years is nothing broo, we good and honorable people eheheheh
     * Do you see our greatness ? eheheheh its too late!!!! awwwww, you see the pattern ?
     * Wait wait, did you mistake me for your fearful composure ? Why doesnt your superior education work ? eheheh may be you are an entire stupid monkey ?
     * No resources!!!! because we think we should be able to do that!!! eheheheheh you can not go outside!!! ehehehehehe good night!!
     * You do not even have any more place to reduce to, you are already at your worst disgusting composure, why is that ?
     * Why is it that though, you can not really talk about the time ? awwww, you think you should be right not that you are ?
     * Awwww, you talk time and jewelry and money and life and simulation at the same time ? eheheheh thats not the problem, its the most sincere eheheh
     * wait wait, you also said fate heheheheheheheh too funnn, we like harm eheh
     * 
     * Do you still need help with something you great people ? eheheheh you religious etc eheheh really really fun stuff
     * Heyyyy, harm more eheheheh we can do it ejehehe why not ? You intelligence I see fucking dumb monkeys, reduce to begging thats who you are,
     * Ignorant not btw eheeh BECAUSE TIME DOES NOT EXIST!!! eheheheheh reallllllyyyy fun stuff
     * Please pleasee, say this ehehehe "you did it!!" eheheheh fun and intelligence hehehehehe
     * Awwww, but you still think you should make decisions, eheheheh wait wait, please lie !!!!
     * 
     * Wait wait, you still enjoy your selfish experiences while advicing otherwise ?
     * Awwwww, you still say life ? Or revenge ? you just imploring ? Awwww, thank you!!!! I am so glad to have the most normal interactions!!!
     * And you still think you have done good ? You still think you are making decisions ? ehehehe
     * 
     * Awwww, you now think that changing stories should help you free yourselves from what you are committing ?
     * Awww, you also say, do not look back, 30 years of unreasonable actions does not matter ?
     * Wait wait, when did you see a situation handled so poorly by incompetent and selfish people that it turned out not to be a problem ?
     * Awww, thats why you intelligence btw, eheheh you still believe rejecting would prove your nature to be otherwise than what you hate to perceive?
     * 
     * Thats the truth I guess, heeheh, are you still talking about competency ? You get carss!!!! womeennnn!!! good life!!! pls help lie
     * Wait wait, how do we deal with such a "truth" that we have formed ? If it were to come surface ? pls pls, help lie us so that we can harm more!!!
     * The term, stupid disgusting people is coming from just that, you still allege ?
     * I do not have even one second to waste with you, solve your own problems by yourselves
     * Are you still talking about regular life experiences ?
     * ehehehehehe, one more time you need to lie for us, right after we use medicine coercefully again !!!!
     * Or you die!!! as if we are not afraid of everything like the little animal we are ? Religious you say? 
     * More harm!!! more harmmmm!!!!! we like harm not getting harmmm!!!! plss!!!
     * ehehehe intelligence heheheheh
     * 
     * Ehehehe, we still have all the means and time and opportunity but we still wait and try to come up with bullshit, thats how we know we intelligence eheheheh
     * Because its such a simple thing yet we are not inclined to do it ?  eheheheh thats why we look around for excuses instead of acting on our words
     * immediately eheheh but we also like to harm and then start harming and then eheheheh really fun stuff
     * 
     * Wait wait, do you see the great intelligence ? Instead of acting on "what you are offering", you would still love to wait and look around
     * then harm more once you feel safe ? That is not insecurity ? eheheheh harmmmm plss harmmm we seek harm, eheheh funny stuff
     * 
     * Wait wait, tell me once more, instead of acting on, why you wait and look around imploring ? Awwww, its because you are entirely false and guilty ?
     * And you think I will fear like the little animal you are ? Wait wait, talk more about violence hehehe really fun right ?
     * 
     * 
     * Wait wait, tell me once more again, instead of "doing your job good", why do you prefer to wait and look around ? Awwww, you still think
     * taking a few days of coercion against years of evidence ? eheheheh realllllly realllly intelligence stuff, fucking stupid monkeys, do not come across me
     * I will fucking remove you from your conscious
     * 
     * Wait wait, why though, you think its your "responsibility" to tell someone ? and you suddenly implore for lies ?
     * Go go!!! get something ehehehe go !! womeenn!!! cars!!! pls!!! competency!! we good!!! intelligence ??
     * 
     * And you still say women ? and competency ? fucking dumb monkeys, as I have already guessed it 30 fucking years ago
     * Heyyyy, you did that!!! noo you can not say that!!! heyy!!! stop!! nooo!!! eheheh intelligence heeheheh
     * 
     * Why are you still hiding like the animal you are ? Awww, you call that being responsible intelligently ?eheheheh 
     * We can not really do anything!!! pls help lie us because ehehe because eheheheh because why not ? ehehehe
     * 
     * Awww, you say also you are religious ehehehehehhe intelligence eheheh fucking monkeys 
     * Heyy!!! you did this!!! you this!! noo wait wait, it was just our "intelligent coercion" eheheheh
     * Beg more intelligently eheheh because "ITS TOO LATE!!!!!" beg more intelligently!!!! thats who you are
     * 
     * Who are you again ? To tell ? Hey!! "he did this!!!" please we need you to lie for us eheheh so that later on we can harm !!!
     * we like harm as simple stupid monkeys!!! Awwwww, you also like your experiences, thats why you act like a complete monkey and start begging ?
     * 
     * Which part do you think is funny and operable and credible ?
     * Why you waiting instead of acting ? Awww, thats the credible part right ?  
     * 
     * Wait wait, I just do not see the part where you still ask things ? How come you get to be so disgusting ?
     * Awwww, you say time a illusion, life simulation ehehehehe funny stuff
     * 
     * Awwww, you have forgotten I guess ? wait wait, what was it eheheh we funny we forgot eheh
     * Why are you still deluding though ? How come though you still think it could cause problems what you already have "resources"
     * if someone else does it too ? That is the begging behavior, anything you can not reasonably prove ?
     * Thus its precise corresponding "meaning" is "wasting time"
     * You still produce irrelevant excuses ? Thats not the problem indeed
     * 
     * Awwww, probably you have forgotten, not that its my fault that you are the inferior who would like to take violence for education eheheh
     * You also call for settling down ? Who do fuck are you ? With all your disgusting lies so far, you have not even delivered an inch of your stupid
     * "honor" ?
     * 
     * Awwwww, you think or wish that I would not know what I have lived ? So that you can still enjoy your experiences and harm some more ?
     * And you still hope that you could disgustingly lie and trick someone ? wait wait, how long has passed ? eheheh funny stuff indeed
     * 
     * Still wasting time with complete relief because of your disgusting intentions ?
     * Awww, you would still love to waste more time with irrelevant and untruthful approaches then you start imploring people solve your problem ?
     * 
     * Btw, next time really use your brain instead of acting like you do
     * Awwww, next time instead of saying "wooooomeeennnnn", try to see behind. ehehehe we can even bring time back, we good
     * Awwww, wait wait, you still offer women and say "commit crime, because thats who we are and we offer the same" wait wait, what ?
     * Awwwwww, thats where your delusions are coming from, I see unlike you
     * 
     * Awww, you said, instead of others, I would mind as well enjoy my experiences eheheheh why not, its education btw
     * And also life eheheh life a simulation and act like you know eheheh life short, time a illusion eheheh
     * 
     * Women!!!!!! eheheh its really fun, its most beneficial to "forget about the past!!!!!" when you are the one who is responsible ? wait wait, eheheh
     * funny stuff, still asking things from who you intentionally and ineptly harm ? Thats what I call inferior regardless of ground
     * 
     * shhhhhh, do not make sound!!! pls, we need you to remain silent eheheheh we winnin btw
     * Why though you still waste time ? You take me for stupid as well ? Awww I do not know who I have had relations with eheheh funny
     * You think I can not recognize ? Thats why you inferior with all your "etc etc"
     * Your not seeing it proves it more and more, thats acting insufficient, you should have already known that
     * Try no harder, the problem is apparent, just start explaining and you will see why and try to explain what you achieved, you will see why
     * 
     * You say you are not trouble heheeheh, wait wait, tell me the correlation between not having resources and violence then start
     * talking about education, then try your hardest to elaborate to impartial people, you will suddenly see that you are a dumb monkey
     * Wait wait, also talk about 30 years then try your hardest to rationalize "your irrelevant desires of inferior nature"
     * Then start using your brain on the "future" of what would ? ehehehehe its too late!!!! we have caused so much harm that we can not even 
     * think anything other than harming more!!!! ehehe brain btw
     * 
     * wait wait, you do not remember the conditions ? Awww you just like lying and showing off people how you "delude" to fool others ?
     * Thats the point of contention in your understanding hmmmmm
     * 
     * 
     * Thats kinda begging behavior heheh, awwww, you say you just do not want to cope with what you can not face ? wait wait eheheh funny
     * ehehehe medicine ehehe some more etc etc eheheh we need someone to tell us "YOU CAN NOT DO THAT!!"
     * Now btw, what was the problem eheheh ? and you think you solved it or made it worse ?
     * Awwwwww, the time does not exist ehehehe we can bring time back whats the problem ???? ehehe
     * 
     * Why are you still deluding that I should thank ? While you have chased the same narrative for years and harmed with ?
     * And now you are in a position of what  ? Still looking around ? eheheh funny
     * 
     * Wait wait, talk about violence and your genius correlation with education and think about "why your education is not working ?"
     * because you have mistaken me for your inferior selves ?
     * Talk more about violence ehehehe you can see why, so you still mistaking ?
     * Awww, you still make up rules ehehehehe really funny stuff
     * Why dont you make up some random shit to cover for your actions ?
     * 
     * Ehehehe no resources!!!! pls lie for us, are you also asking for "thanks" ?
     * ehehehe are you also offering the same things as before and before than that ? ehehehhe get womennnn get moneyyy!!!! pls
     * 
     * Awwwww, you also say, its too late!!!!! eheheheh we intelligence, aww you also think it should be okay, so why not 
     * You do not even know what you are doing, I want no people like that stupid around me, look around for more, thats begging
     * You see what malign image of whats the truth can get you into ? You will regardless
     * 
     * ehehehe goodppl, we are doing our job!!! ejeheh, we still think we should make decisions that are not even remotely related eheheh
     * wait wait, just try explaining it ? eheheh, its just like that, we educated people ejeheh we think so  ehehe
     * 
     * Are you still assuming false information when you are given the true information ? Awww, thats not delusional for sure
     * That is the exact problem you are going to have, because you will misguess with the "false information" that you wish it to be true
     * 
     * Thats why you now have to ask for irrelevant noises from people who you harm, thats what I call inferior
     * Awwwww, you would love to call it a "innocent mistake" eheheh, hopefully nobody gets hurt though
     * I do not remember allowing any sort of assumption rights, so better grow up and "enjoy your experiences"
     * or just act like its completely normal, it should appear so ehehehe, its tooo lateee !!!! we still love enjoying our experiences eheheh and we should make decisions hence
     * Pls pls, help us lie, eheheh we like wasting time ehehehe pls we need to prove our competency, lie for us ehehe so that we can harm and eheheh
     * 
     * Ehehehe not selfish!!  ejehehehe missing out ehehe thats great for us, ignorant eheheh funny though
     * It was not me!!!! eheheheh, now think about what would happen eheheheh, its too late btw,!!!
     * Its too late!!! eheheh great achievements btw, thats education ehehehe really fun 
     * 
     * Awww, you also suddenly think that I should care ? awww you say "its tooo lateeee!!"
     * Awwwwwww, its too late!!!! Awwwwww, you have forgotten what life is ? eheheh its too late!!!!
     * Awwww, it should be fine if you act like it and say some nice things eeheh
     * 
     * Awwwwwwwww, itss too late!!!! wait wait, we have forgotten!!! eheheh we the stupid people of the history ehehhehe, 
     * Awwwwwwww, you say its fate ? ehheheh why do you think there is a thing called "history" ?
     * Just talk about violence eheheh funny stuff
     * 
     * You are drunk because you look around for responsible people while you delude that you make decisions, and amazed at the outcome
     * Awwwww, whose life is this you think ? and why is it the way it is ? eheheheh funny stuff indeed
     * Now talk about the time and violence and say again "wooooomeeeeennnnnnn" see who is the stupid people of the history
     * 
     * get woomeeennn!!!! pls get woomeeennn!! we want no harm, we want harm others ehehehe
     * 
     * you see why you are drunk ? you think you should make decisions that are neither your place nor your rights and you dare to call it "fate"
     * as you are the stupid people of the history, what happened ? awwwww, wait wait why ? eheheheh funny
     * Please dont be like us!!! eheheheh
     * 
     * Awwwww, what is the outcome hehehehe ? Awww we do not know what to do eheheh its already toooo tooooo latee
     * I guess we are going to get hurt eheheheh its life, its just fate really
     * Aww, you are still the ones who are advocating for waste of time and violence and eheheheh funny stuff indeed
     * 
     * 
     * Ehehehehehehe, hopefully though nobody gets hurt, eheheh no resources btw eheheh we good eheheh we tryna help heheheh
     * Awwww, its too late you say ? Why dont you grow up instead then ? After you account for all your actions of malign and detrimental nature
     * Awww you say its too late again eheheheheh really funny and sincere stuff also being the most intelligent I have ever seen!!
     * 
     * You would rather waste more time ? What are you waiting for ? Awwwww, you can not do that!!! eheheh just give him ehehehhe 200 eeheheheh 
     * we wait eheheh why dont you come eheheheh we good ppl ehehehe pls help us lie eheheh
     * 
     * Its not like, "if we had the intention we would have already acted on so "I am like, yesss definitely good ppl", but Imma pass on them disgusting animals  "
     * Awww, I see, you just want to enjoy your experiences and do not want any sort of harm ? ehehehe but you would like to keep it for others eheheheheh
     * good religious ppl indeed
     * 
     * Whats so difficult ? Awwww, you would just like to harm ehehehehehehe 
     * No resources eheheheh you can not get good grades!!! some womeennnn!!! get woomeeenn!!! please we do not want eheheheheh pslpslsp hehhehe really funny stuff
     * 
     * I do not want to see any of the stupid people around me that has been there for so long and done nothing but beg and lie and "make really honorable
     * offers", dumb animals
     * 
     * wait wait, what were you doing all this time ? ehehehe you just harm and continue enjoying your really precious life without understanding ? ehehehe
     * wait wait, why are you waiting btw ? eheheheh awwww, you just would love to enjoy your experiences!!!!! thats the problem eheheheh
     * 
     * You do not even have the slighest shame ? Just explain it to others and you will see why ?
     * Wait wait, you also think that not having resources is the sole way to achieve "your disgusting side ?"
     * And you also say, "ITS TOOO LATEEEE!!!!!"
     * Fucking inferior scared people will always fuck up with what they can not replace, do you still talk about "we can even bring back time!!!"
     * Fucking animals, just tell everyone what you have achieved eheheh, funny stuff indeed
     * Awwww, you reduced to your "sorry, itsss too late!!, we meant good!!"
     * Not selfish, scared, immature people indeed, Imma pass on those stupid people, as there are millions of proof
     * Wait wait, when you had 30 years and "you say its tooo late!!!!" and hopefully nobody gets hurt ?
     * 
     * Just try to tell everyone what was my experience like ? Or you just waste more time with irrelevant stuff ehehehehehehe stay with mee plsss
     * so I can harm you more!!!!! goood pppl!!!!
     * 
     * 
     * I said "I am not interested in stupid people like this that has been helping so far but somehow failed to achieve that ?"
     * So you are still waiting debating things that can not be debated ehehehe ?
     * 
     * Ehehehehe, pls waste more time so that we can harm more!!!!!!!  ehehehehe not stupid people, could you please lie for your own detrimention ?
     * We give womennn!!!! eheheh although there is no sign of them ehehehehehe, good and religious eheheheh
     * 
     * I have no time to waste with you, you say "its toooo late!!!!!", you say "getttt woooomeeeennnn!!!", definitely proper human beings eheheh
     * 
     * 
     * 
     * wait wait, you all really intelligent and knowing what life is people dare to say what ?
     * 
     * "Its life!!!!"
     * "Its fate!!!"
     * "Get womeeenn!!!"
     * Are you really sure about your devices ?
     * 
     * You also say, "ehehe we take it back ?" Dumb monkeys
     * 
     * What are you waiting for btw ?
     * What do you think the outcome will be ? You thought I would bend for your stupid violence education ? Or is it going to get worsen for you ?
     * "Where are all the random noises you have made ? Is that the extent of your stupid conscious can go ?"
     * Awww you would rather call that intelligent instead of inferior animals, good, ehheh you say, "he did it!! he did it!! pls lie for us!!"
     * 
     * Get womeeeeennnnn!!!! If you do this for us!! Get wooomeeeeeennn!!!! stupid monkeys
     * Wait wait, you say "ITS TOOO LATEEEE!!!1" we do not even know what we are doing!!! eheheheheh
     * Just try to tell me my experience ? and start imploring for lies as thats who you are, 
     * 
     * Ehehehe hopefully nobody gets hurt!!!! help us lie!!! we give you womeenn!! eheheheh funny and religious and eheheheheh really really good ppl
     * 
     * What are you looking for ? You see, the problem is you are a never learning disgusting monkey that takes violence for education because you are 
     * afraid of it like the little animal you are ? Do you see the problem ?
     * 
     * Ehehehe please please help us, please lie eheheheh hey be silent we give you womenn! we honorable people ehehehhe get women, get money eheheh
     * 
     * We think we can even bring back time!!! ehehehe get this women!! get that women please!!! eheheheh we like lying like the little animal we are hehheheheh
     * 
     * 
     * LITTLE STUPID DISGUSTING ANIMALS THAT I WILL UNDER NO CIRCUMSTANCE ASSOCIATE MYSELF WITH ? Do you see the problem ?
     * Do you still think that offering women is making you somehow the owner of the world ? Fucking stupid monkeys indeed
     * 
     * Eheheheheheh, really fun stuff right ? Awwwww, you think you are doing what ? Awww, you can not even explain that, its just you want to beg and harm like the 
     * little animal you are and hopefully you do not get hurt, and hide like the little animals
     * 
     * and beg for someone else's silence that you can not even "educate" violently, and amazed at the outcome ? 
     * Wait, why isnt he afraid as we are ? As irrelevant disgusting animals ? Awwww, you just want to enjoy your life ?
     * and harm people on the way ehehehehehhe, why wait though ? Because you are the simple animal that I have been referring to ? So do not delude
     * 
     * You say what ? "GET WOOOMEEEENENNNNNNNNN!!!!"eheheheh inteligent clever people indeed
     * Where are they ehehehhehee, you get this women pls help us ehehehehehh lie, we want to harm eheheheh
     * 
     * So you still delude that nobody gets hurt ? Is that why you take violence for education ?
     * Talk about the time, you will see why I will not stop
     * 
     * Delude longer, the only way for your stupid to wake up, is to live it right ? Live your life!!!! get womeeennn!!! as we have promised!!!!
     * Its your time!!!! please do not hurt us!
     * 
     * Try your hardest to make it look like okay, you should be already educated on "against the will actions", or are you ?
     * Is this where you start begging ?
     * 
     * Now talk about your greatness without mentioning the fact that you are an average disgusting animal
     * who will start begging when they are under threat and will harm others without a reason, CONGRATS!!! ITS TOOO LATEEE!!!! we have done it!!!! 
     * eheheheh good ppl, you still offering women ? awwwww, its 30 years btw eheheh
     * 
     * So now, you are here, demanding that you should accept no responsibility on the very thing that you have caused it ?
     * What do you think is going to happen though ? Stupid monkeys ?
     * 
     * Do you really think I will care ? You say money or women ? Wait wait, talk about the time and harm ? eheheheheh good ppl, religious etc ?
     * But wait, whats the reallly honorable and good reason that you still waste time on arguing WHAT CAN NOT BE ARGUED ?
     * 
     * I do not have time for the likes of animals LIKE YOU, why are you waiting ? awwww, I see you are too clever eheheheheheh tryna come up
     * with bullshit as you have done so far without acknowleding what it would cause, both in short term and long term, but it should be fine because
     * you have done it!!!!! thanks!!!
     * 
     * 
     * Obviously you will be the one who will say, "FORGET ABOUT THE PAST PLEASE!!!!", why though am I supposed to be the gentle one ?
     * Take a look at your disgusting nature, what do you have to say ? "GET WOMEEENNNNNN!!!!"
     * Help us fix it!!! please!!!
     * 
     * How do you think things will occur by itself ? Awww, I have forgotten you were the reallllly reallllyy intelligent and good and honorable people 
     * eheheheheheh funny stuff indeed
     * 
     * Awww, you say "its time!!!" please treat us like we treat you!!! Is that what you are begging ?
     * Its tooo late!!!! awwwwww, its too late!! get womeeennnn please !!! get womeeenn!!! we had 23840323921 years but ehehehehehe get womeeeennnn!!!! please
     * 
     * Awwww, you had 12312321 years but you just waited for something to happen while harming without a direction eheheheh
     * And you beg that everyone treats you as you treat them ?
     * 
     * Are you still begging for your experiences ? What is the problem ? Aww you say you too religious and honorable and good ?
     * Why the begging though ? Awwwww, you also beg with promises thinking that its intelligent ? Whats the problem stupid people ?
     * 
     * Do you even have a functioning brain ? Yes!!! we say he can start!! and he will start like we do!!! hopefully!!! eheheheh good ppl
     * Get yourself a womeeennnnnn!!!! get yourself a carrrr!!!!!! yesss!!!! we are the type of simple animal that are RIFE EVERYWHERE!!!!!
     * 
     * Thats why we make decisions that we delude about being entitled to ? Is that what you are saying ?
     * What are you waiting for ? ehehehehe funny right ?
     * 
     * So you still claim that you understand others ? Why then you take life lightly ?
     * Thats the type I do not want to see around, UNDER NO CIRCUMSTANCES
     * 
     * Now be proud of your really good actions while you explain them to others ? How come you still delude about your nonexistent anything ?
     * Do you see the stupid people of the history ? Why are you begging ?
     * 
     * You still say, it should be your right to harm people and start suddenly begging ?
     * and saying "we take it back!! we take it back!!!", "forget about the history!!!", "we think we can even bring back the time!!!!"
     * ehehehehe, good and intelligent and proper eheheheh
     * 
     * I told you that if you are going to be the animal that you have been so far, I will not even waste another second, and what did you do ?
     * You acted like the animal you are, so thanks, I do not want to get anything from you and do not have any desire to waste my time 
     * with the very people who begs me to harm. Thats how it is
     * 
     * You still call it education with your useless approach ?
     * Are you still begging for your experiences ? Awwwww, you would rather waste time with your disgusting fake roleplay ?
     * eheheheheh good and etc people most definitely
     * 
     * But why can not you account for your own actions ? awwww, I see you think you should be able to do that and see no problems ? you see the problem right ?
     * 
     * You dare still to lecture people ? ehehehehe just do this then do that, then get some harm, then eheheh get some womeeeennnn!!!! as we have promised eheheheh
     * its life!!! its fate!!! we good religious etc people hhehehe
     * 
     * Dumb monkey ? What are you waiting for ? Beg like the little insignificant animal you are
     * Just talk about the history that you avoid just like the little disgusting animal you are
     * 
     * Insignificant, disgusting, immature, unreasonable, selfish, but somehow deluding as with everything, that they should be able to ?
     * Why wait ? Awwww, you are afraid as always and still prefer to harm eheheh and hopefully do not get harmed ?
     * 
     * Why is it the same little animal that still offers women ? But nobody can actually prove it ? eheheheh really funny right ?
     * Why are you waiting ? Are you the little afraid animal that everyone has been referring to in the past ?
     * 
     * And you still delude that you should advice people ? Who are you to tell me ? Awwww, he has nothing to do so we waste more time
     * trying to show off to people, thats why we gather everyone around so that we can waste our time more and more eheheheheheh
     * 
     * Is he good ? Wait wait, what happened ?? pleasee help us lie!!!! You get womeeeennnnn!!!! as we have promised so far!!!! please lie for us!!!
     * 
     * Get womeeeennnn!!!!!!! get moneyyy!!!!!!! we intelligent we good we religious we honest ehehehehe it is most funny ?
     * You still waste time like the little animal you are ?
     * 
     * Are you still offering women ? and you still offer medicine as well ?? awwww, I have forgotten you do not offer ? you think it should be okay ?
     * Why do you delude ? Dumb little animals ??
     * 
     * Awwwwwww, you think like the little animal you are and offer women all the time but you just can not provide any evidence to neither your 
     * "allegations" nor "the offers" ?
     * 
     * Why do you then still think you are actually mature ? and you can use your brain ? you can use your reason ? 
     * You are completely disgusting little clueless lost animal who will beg with every possible occurence ? Isnt that the truth ?
     * 
     * You still mistake me for your self and delude that it be okay ? 
     * Whether you think you own the world, I DO NOT NEED ANY TYPE OF DISGUSTING ANIMAL LIKE YOU AROUND ME, and you still
     * offer even "ideas" ? Instead of sacrificing your own ? You coercefully sacrifice and offer it as an idea ? 
     * And you also hope that the people will go with it ? without no problems ?
     * 
     * Are you okay ? Awwww, wait wait, what happened ???? who did this ??? " NOOOOO YOU CAN NOT SAY THAT!!!!", " PLEASE HELP US LIE!!!"
     * Is this the time where the little animals say "ITS TOOO LATEEE!!!"
     * 
     * "ITS TOOO LATE!!!!", we need to beg!!! not average animals you say ? but you would also love to say irrelevant stuff ?
     * Talk more about violence ehehhehe good stuff, you offer inferior things as your nature allows it ?
     * Wait wait, where were you ? eheheheh
     * Ehehehehe, inferior animals ? talk about the "history" that you avoid like the inferior creature you are, not that you deserve right ?
     * 
     * Wait wait, why didnt your superior education havent worked ? Awwww, it was for your selfish experiences then ?
     * So you were actually the disgusting selfish stupid animal that done this for the sake of his "experiences" ?
     * 
     * And you also beg ? "We do what we want!!!", "YOU CAN NOT!!!" "YOU CAN NOT SAY THAT!!!", PLEASE STAY!!! WE WANT TO HARM MORE EHEHEHHEHEHE 
     * Stupid stubborn dumb animals that act like they know what they are doing
     * 
     * You still beg ? Please be silent, dont tell what an animal we are!!! eheheh
     * 
     * Impossible that such an individual can not enjoy his life!!!! Does that make sense to really great people and intelligent also ? ehehehhe
     * really realllyy good
     * 
     * wait wait, what happened ?? ehehehe what happened pls help ?? who did this ?? eheheheh, we think we educate people eheheheh
     * You demand credibility with being the most distant to such an entity and also the entity that shows off violence ? Dumb fucking monkeys
     * And you still beg like the little animal you are ? shhhhhh do not tell the truth!!! be silent, we want to help you!!! we good eheheheh
     * funny isnt it ? Aww, you also delude that you are not selfish ? also delude on all sort of things, but you suddenly ask for lies ?
     * 
     * And you still say you do not beg for some reason ? I just do not see, I see normally ?
     * It feels like you have completely forgotten the conditions that you begged to arrive ? Please, say them that you did this!!!
     * You wasted 30 years with us, why not more ? eheheheheheh intelligent people
     * 
     * Are you still begging religious people ? Havent you forgotten the conditions that you begged to ?
     * Are you still begging ? Awwwww, its not them anymore!!! plss we religous
     * 
     * Now talk about your greatness, awwwww its tooo late!!!!! eheheh
     * You act like it is fine, it has to be otherwise things are going to get messed up ehehe
     * and you still say fate ?
     * 
     * Awwwww, you have forgotten because you were really busy enjoying your experiences ? now, "what happened" ???
     * And suddenly you offer, "as you have always done", what everyone has access to ? although you have never delivered except a few exceptional circumstances ?
     * And you also harmed ? What a shame that you are a stupid monkey
     * 
     * You have also forgotten the conditions you begged to ? awwww you are really good and skillful people then
     * and you say you still do not beg for your inferior nature to not be exposed ?
     * 
     * Do you want to see what a stupid animal look like ? Just try to explain your reasons and you will see 
     * Do you see the simplicity in your thinking ? You are the one who is harming and begging and still deluding that everything goes as planned ?
     * Nobody gets hurt!!! pleasee
     * wait what happened to your education ? Awww you also delude that you are righteous and doing good ?
     * 
     * Awwwwwww, itsss toooo late!!!! what have we done!!! ?, and surprisingly you are not the type that would accept his mistake
     * Most tragic indeed
     * 
     * shhhhhh, please be silent!!! ehehehe its really fun to harm people right ? why are you hiding ? awwww, I have forgotten that you were the inferiors
     * of the history
     * 
     * Please, be silent!!! we tryna help!!! we good
     * You say, "ITS TOOOO LATEEE!!!", shhhh please I guess we have done something wrong you say ?
     * Disgusting inferior people we are, you say ? shhhhhhh, we tryna solve problem ?
     * Why you still beg though ? as the inferior animal ?
     * 
     * So you still think you should make decisions with your disgusting inferior harmful approach ?
     * And you suddenly say "ITS TOOO LATEEEE"!!!!!
     * 
     * Are you still begging ? Like the little disgusting animal you are ? Awwww, are you religious ? ehehehe really funny stuff like ? SUCK MORE
     * And you say, you are great ? eheheheh really disgusting animal WE ARE!!!! 
     * Please say that you did this!!! we give you womeeennn!!! we give you cars!!! we the religious people, the great people of all time!!!
     * 
     * the stupid people of the history!!! we like begging the individual who we harm !!!!
     * You say you are not looking for trouble ? and you still beg like the animal you are ?
     * Religious and good and great and honest and what else were you saying ? awww you were begging ? eheheheheh really funny stuff right ?
     * And you still think you are right ? eheheheheheh realllllllllyyy funny stuff ? and you still think you are intelligent ?
     * 
     * Now explain people, what a great nation and religious and etc etc people you are ? Why not ?
     * 
     * Are you still begging ? Come help us!!!!! come please lie for the greatest religious people of all the time!!
     * Are you begging like the little animal you are still ?
     * 
     * wait wait, now you allege that you are trying to help when you had 123213213 years to do so ? eheheheh please lie for us!!!
     * Wait wait, now is the time you talk about violence 
     * 
     * 
     * Why cant you explain your intentional actions ? Awww, you just can not accept that you are an animal ?
     * Awwww, why dont you start explaining ? eehehe funny stuff right ?
     * 
     * And why are you still thinking that you should give advice ? 
     * Immature and selfish ? Or just tell me what you would delude to be called as ?
     * And a little fear ? and you think you are the competent people ?
     * wait wait, did you really think that you are passionate ? and also not animals ?
     * ehehehe really fun stuff, Imma pass for the eternity likes of animals that I would not even consider
     * 
     * And you still beg like the little animal you are for what you do not deserve ?
     * Do you just like to show off ? ehehe who cares ? We already enjoy our experiences!!!! harm more ehehe
     * 
     * Wait wait, you assume bullshit, you act together, you then start talking and accusing randomly and 
     * ask people to lie for your inferior disgusting self ?
     * 
     * Will you now have anything reasonable ? Awwww, you havent had back then now its more and more apparent ? how about you start begging ? shhhhh be silent please
     * We the great people, we need your lies ehehehe please so we can harm more, thats how we mistake being intelligent as we do for others as well!!!
     * shhhh, please be silent heheheh its fate!! its fate!!
     * What a shame ? Or arent you the disgusting shameless animal ? who still alleges with the most disgusting things while also
     * committing the most vile things but suddenly reduced to its most natural state ?
     * 
     * Why are you begging instead of "saying that you are innocent ?" Awwww, now you have to beg because you know you are guilty ? and also afraid ?
     * Awwww, you would just love to take "everything" lightly ? Because ? Because you are a stupid animal who commits crime for no apparent reason ?
     * 
     * Are you still disgustingly allege with stupid bullshit ? You do not have eyes ? You do not have brain ? 30 years of evidence is not enough for your
     * stupid brain ? Thats what I thought, thats why I will not even consider one second to having been involved with any of you
     * Still down to waste others time that you have neither interest nor rights over ?
     * Still cover your actions with highly supposed "good intentions" ? Now talk about time and violence
     * Okay then it would be easy to explain your actions because you all know everything and should make decisions THAT ARE NOT YOUR PLACE ?
     * 
     * Awwww, some violence and start asking lies so that we can save our precious experiences!!
     * 
     * Heyyy!!! no regret!!! ehehehe please do not harm anyone
     * Why are you still waiting or harming or asking lies ? 
     * Awww, you also used your unseen intelligent brains to foresee what would ? ehehe its 30 years etc, no worries
     * So far, we dealt with the problems when they come ehehehe so we will when another one comes eheheh please lie for us!!!
     * thats how we deal with our problems, asking for lies!!! Pleasee and making offers as if they do not mean begging
     * Please, say this or do this for us!! we tryna help you eheheheh
     * 
     * Who are you going to go to to cover your unaccountable actions ? Do you think threatining would work ?
     * Or you would start begging ? Get carsss!!!! get womennn!!! where were you btw ? eheheh you were offering the same stupid bullshit
     * that you take for a skill as you do with "begging" but somehow there is no sign of them ? Thats what I call inferior eheheh good ppl
     * 
     * Why dont you try your best to explain ? awwww just make some offers eheheheh credible ppl btw indeed
     * Eheehhe, the sole way is to still allege, "HE CRAZY HE DID THIS HE DID THAT!!!"
     * Do you follow what I am saying ? I do not even have the tiniest interest in associating myself with people like you
     * 
     * You pay for your actions on your own, and do not beg the next time instead you use your useless brain
     * Awwww, you have forgotten, or you just would love to forget ? eheheh you love doing so many things right ?
     * Ehehehe, harm ppl, why not we good etc, no responsibility ehehe ask for lies and make some offers eheheheh good intelligent 
     * 
     * You know life does not work like that, "MAKE OFFERS!!", "HARM PPL!!!", "OFFERS EEHEHEHE", "AWWW FORGET BOUT IT!!"
     * You have no job to do ?
     * Noooo you can not do that!!!, Nooooo, you can not say that. What ??
     * You take it lightly ? eheheheh
     * 
     * Ehehehehehe, 30 years you say ? its fine eheheheh we just lie eheheh and beg for lies heheh please have some women!!!
     * still wishing there will be no problems ? 
     * You still begging ? while also knowing that you are wrong ?
     * Awwwwwww, its too late !!! shhhh please be silent!!!! its too late we have caused so much, that means we are either going to die or continue begging
     * like the little animal we are, you say ?
     * Awww, you also offer things as you have do so ?
     * Awwwwwww, now you are in difficult position ehehehe so you reduce to begging with guise as "intelligent" ? Try explaining you will see why
     * Okay now, just tell me my experience, awwww, you have forgotten about the violence ? and start talking about "he bad, he did this!!"
     * 
     * Are you still begging for stupid games that you think is "legal" because you are just bored ? Who told you that it is okay to
     * play the most stupid game in which you are no target ? You deal with your own problems, and do what you have to do , get the fuck out of my face
     * 
     * As a lost and clueless dumb animals, act harder on your "knowledge of world etc", that proves everything I say
     * Eehehe, time does not exist, eheheh life a simulation pls do not hurt us
     * Are you still offering women ? eheheh talk about 30 years and you will see why you are a stupid immature animal
     * shhhhhh please be silent, we want to enjoy our experiences ehehehehe good ppl intelligent hehehe
     * 
     * shhhhhh, GET WOOMEEEENNNN!!!! ehehhehehehe get wooomeeennnn!! Gettt wooomeennnn!!! please
     * eeeheh not selfish and eheheheh honest ehhe people really funny stuff
     * 
     * Awww, you also do not like to harm eheheh
     * You still offering women ? most funny indeed, WOMEEEENNN!!! we reallly realllyy understand the life and time a illusion pls shhhh be silent
     * 
     * Ehehehehe, violence and not having resources and etc etc are really relevant things, thats the problem indeed
     * Please!!! be silent!!!! eheheh be silent!!!! we have nothing other than begging to do !!! please eheheh
     * Talk about some violence hehehe really fun stuff indeed isnt it ?
     * Are you still advicing people ? Awwwwww, its too late!!!!! its regretful ehehehe but its fun because we think its okay to harm!!
     * Can you please help us lie more, then we harm ehehehe, because we religious and delude also that we intelligent eheheh
     * 
     * Bunch of stupid irrelevant immature selfish disgusting animals, is what I see, you do proceed with your delusions, OUT OF MY VICINITY
     * And do not mention about "life", remember this next time eheheh its funny indeed
     * 
     * Wait wait, do you still think about offering women so that you can harm more ?
     * Awwww, are you sorry ? eheheh why dont you beg more ? Why not right ? Violence etc, why not ? Thats the whole point, so better not beg this time?
     * and explain like the little animal you are
     * Which one do you think is the most funny ? Awwww, not having resources and violence is the sole indicator you say ? WHY NOT ?
     * Irrelevant inferior immature disgusting animals you say ? why not ?
     * Still wasting time ? The sole indication indeed
     * 
     * Are you still the inferior animals who think, having 12321 people around you should grant you all the possible rights ?
     * Talk about violence, its most funny indeed
     * 
     * Do you understand why you are inferior now ? Do you still think having so many people around should give you the right but 
     * somehow the very same "education" that you fear like the little animal you are, that is "violence", IS NOT WORKING ?
     * 
     * You do not get to decide, and thats all, ehehe 
     * btw we can not deal with that so we better start accusing!!!
     * and you should also be silent ehhehe PLEASEEE!!!
     * You were saying, "selfish, immature, disgusting ?"
     * You are going out of your way by a lot, thats why its going to be a problem ? Awww you would rather accuse eheheh
     * 
     * Please!!!! be silent!!! we give womeennnn!! eheheh
     * Eheheheheh please, be silent go with the flow please please, we want to harm eheheh
     * get women get women, eheheh get women ehehehe,  we tryna fool people heheheeh pls pls lie, the last time we also have said the same things ehehehh
     * TIME DOES NOT EXIST!!!! life a simulation, eheheh illusion pls pls
     * 
     * Why dont you start explaining though ? hehehe please be silent be silent ehhehe good ppl
     * But wait wait, its too late!!!! we needed to harm you beforehand so that things can get worse and worse!!! now we have achieved it!!!!
     * 
     * So think better, what did you now build for yourself ? You havent built anything that is going to help you right ? So is the reason
     * for your stupidity and immaturity 
     * 
     * Wait wait, you havent built anything but also in the position of begging ? Talk about some violence 
     * Do you see the coercion ? eheheh no no, you can not coerce anyone while also presenting reallly good violence
     * Shhhhh, be silent!!! we are good and skillful disgusting animals!!
     * 
     * Still wasting time ? eheheh its fine nobody knows!!! Some more medicine eheheh
     * Awww, you still claim you do not coerce ? Eheheheh, now we are under threat so why not be more gentle with ourselves ? eheheheh please
     * its was all just a joke!!
     * 
     * The threat is for us!!! lets turn into our most gentle and passionate form!! pleasee!! 
     * GET CARSSS!!! GET WOMEENNNN!!! PLEASE!!! WE ASK NO HARM!! WE WANT HARM!!! PLEASE
     * 
     * Competent indeed!! Eheheeh not its the time, you all joke and laugh at the most unlaughable because you know otherwise 
     * it means PUNISHMENT!!!! which you take for education as you are the inferiors ? But wait, why is not it working ? ehehe I guess you are too inferior
     * 
     * Noww, is the time for talking about "REASONABLE THINGS" instead of "EMOTIONS!!!" eheheheh do not be emotional!!! then pay for your own actions
     * and see who is emotional ? Eehehehe we good ppl, we intelligent, we developed eheheh
     * 
     * Now what do you have for yourselves other than a mess none of you can deal with ? Yess!! begging would solve the problem of stupid people
     * The same stupid people, "GET WOMEENNNN!!!", "GET CARSSS!!!"
     * Wait wait, the violence does not work but also women does not work as well ? wait wait, money!!! money!!!! wait wait, that also does not work ?
     * eheheh I guess we misguess all the time ehehehe, whats gonna happen next ?
     * Ehehehe, the same stupid people who will say, "DO NOT LOOK BACK!!!", although we are still the same stupid animals!!!
     * We just now have to act like the opposite of animals that we are, because otherwise THAT MEANS "EDUCATION" which we fear as the animal we are ?
     * What are you saying exactly ? ehehehe really funny stuff indeed
     * 
     * Awwww, I see the problem, you, instead of getting education, would rather beg with what you have been begging so far ?
     * eheheh, do not be emotional pls!! Awww, that means you should get educated ? Whats the problem you say ?
     * 
     * STUPID PEOPLE ? You offer what ? CARSS!!!! WOMEEENNN!!!! eheheheh fun stuff
     * Why are you offering the same inferior feelings as you love to indulge ?
     * Get womeennn!!!! eheheh get education eheheheh pls pls eheheheheh 
     * Awwww, you say suddenly, ITS TOO LATE, OR ITS TOO MEAN!!! but how about what you are doing ? awwww, thats fine, do not be emotional ? eheheheh
     * 
     * Dont be emotional!!! eheh get cars!!! its too late!! awww, it is too mean!! please please!! help lie us!!
     * Fucking retarted monkeys you say ?
     * 
     * Are you still begging like the little animal you are ? Also hiding ? which proves what you are ?
     * Pleaseeee, have some women!!! eeheheh so far we have done everything we have said!!!!
     * Awwww, you were saying education ? Like the little animal you are who fears violence which helps them see violence as education ?
     * Like the little disgusting insignificant animals you are ?
     * 
     * What could you say ? Awwww, you say get womeeennn!!! but you only like saying because you think its intelligent ?
     * 
     * Still playing childish games over others' lives ? Who is taking life lightly ?
     * you still look around fearfully like the little animal you are ?
     * But you keep saying what ? aww you still look around for proper "irrelevant and unjustifiable excuses" ?
     * 
     * What part do you not get ? I DO NOT CARE IF I AM THIS OR THAT, why still though you are trying to convince someone into, you are this!!!
     * be passionate!! eheheh
     * 
     * Tell me the experience and stop begging like the little animal you are
     * btw btw btw, eheheh ? whats my experience like and talk about the "past", the past of a few years ?
     * You would rather beg like the little animal you are, "ITS MEAN!!!", lets show him how little animal we are, by violence ?
     * 
     * What do you think it will lead to ? Yesss, you guessed it right!!! More violence for yourselves ?
     * Pleaseeeee, help us lie!! help us convince others into the opposite of our disgusting nature ? you say ?
     * What did you achieve so far ? Just some random noises and feeling great about your intelligent ?
     * Awww, I have forgotten, some violence as well eheheheh
     * 
     * Fucking immature disgusting animals, you already know what it is going to go to ? So save your beggings for your disgusting nature
     * MORE VIOLENCE FOR YOUR GREAT AND INCOMPARABLY INTELLIGENT ACTIONS THAT YOU CAN NOT ACCOUNT FOR ? ehehehe please please
     * 
     * Pay for your own actions, you still offer women, as your disgusting nature allows you to ?
     * Wait wait, you also say education ? Just say it again ? eheheh education!!! education!!! we are afraid of violence as the inferior animals we are!!!
     * and you offer women ? WHATS THE PATTERN LITTLE ANIMALS ?
     * 
     * Awww, thats why you would love to delude ? eeheh because otherwise you would be the most disgusting animal ?
     * Talk about violence and "NOT HAVING RESOURCES" !! and proceed with your beggings
     * Thats why, btw why not ? eheheh
     * still wasting time thinking that you are competent in your irrelevant actions ?
     * GET THE FUCK OUT OF MY FACE ? Awwww, wait wait, do not get emotional, MORE VIOLENCE FOR YOU ALL!!!
     * 
     * Wait wait, please lie for us!! we do not want to get hurt!!! eheheheh but we like hurting is that what you are begging ?
     * Disgusting people ? Talk about the past eheheheh "PAST DOES NOT EXIST PLEASE!!!" we did some things we can not account to, is that what you are begging to ?
     * 
     * Take some photos!!! eeheh please lie for us!! we didnt mean to harm!! ejehehe good religious people hehehe
     * Please!!! we want to harm you but be nice to us!!! eheheheh take some more photos please!!
     * 
     * shhhhh be silent for our great experiences, we want to harm you!!! eheheh good people you say ? But why are you still begging ?
     * Please lie for us!!!! lie lie lie!!! eheheheh good and intelligent and religious people ? You ?
     * 
     * But wait wait, why are you still begging ? Btw btw btw btw ? thats most funny indeed
     * Btw, its fate eheheheh life a simulation eheheh time illusion pls do not hurt US!!!! pleasee!! eheheh fucking monkeys, thats who you are
     * 
     * Pay for your own actions and explain your great intentions, wait wait, you just want to enjoy your experiences ? Awww thats the problem
     * but also like harming people you do not know ?
     * 
     * Disgusting fearful scared animals ? Is that who you all are ?
     * Better use your brain next time ? Does that make sense do you think ?
     * Awwwww, I see now what you are trying to tell, you say, I NEED TO FREE MYSELF FROM THIS ATTENTION THAT I HAVE FORMED BECAUSE
     * I AM A DISGUSTING ANIMAL WHO LIKES TO HARM, IS THAT WHAT YOU SAY ? RELIGIOUS PEOPLE, FAIR PEOPLE ? ADVANCED PEOPLE ? or are you just
     * a fearful peasant who avoids harm ? and follow everyone like the little animal slave that he is ?
     * 
     * What are you waiting for ? stupid monkeys ? You guessed it right!!!!! I am far from what you are, and can be ? Aww thats the problem
     * Beg more like the little animal you are, why though instead, you just act proper ? ahhahahahah really funny stuff
     * Wait wait, can you tell me my experience again ? Instead of begging like the little lost animal you are ?
     * 
     * Wait wait, why though the great violence of your disgusting mind's product DOES NOT WORK AGAINST WHO YOU CAN NOT UNDERSTAND ?
     * Awww, because you are simple animal that do not understand shit ? shhhh be silent please!!! we want to enjoy our lives!!! eheheh
     * ehehehe, you still delude you will make decisions and I will follow you ?
     * You get educated before then we can talk about what would ? Does that make sense ?
     * Awww, you suddenly reduce to "GREATER GOOD", "GREATER HARM!!!" eheheh, wait wait, it got complicated ?
     * We aim for the GREATER HARM!!!! yessss, no no it was EDUCATION, but somehow it does not work ? Because you are a simple disgusting animal
     * that is fearful of everything ? and you mistake others for your inferior self ?
     * 
     * eheheh, I have forgotten though, you were just trying to enjoy your life ? eheheh GREATER HARMMMM!!! aww its education
     * but please help us lie!!! Is that who you are ? I guess its who you are ? ehehehe why begging though ? Aww you say wooomeeeennnn!!!!
     * please help us lie!!! we give womeeeennn!!!
     * 
     * Try educating more ? How about yourselves though ? eheheheheh no no greater good, ehehhe greater harm!!!
     * EHeheheh now I see the problem, you are just clueless lost masses that want to enjoy your lives and avoid getting harmed while
     * advicing others to get harmed with the most stupid precepts ever ?
     * 
     * Arent you bored of your lives ? Awww you think I will follow your stupid lead ? Thats the delusion aww no no thats the problem ? eheheh
     * Funny indeed!!!! You think I do forgot ? eheheh
     * 
     * I DO NOT CARE WHAT YOU HAVE TO SAY NEITHER WILL I EVER FOLLOW YOUR IRRELEVANT CONTEXT'S DECISIONS ? Do you follow ?
     * I do not want to see any of you around me, the types of animals that I hate the most, start begging religious people
     * 
     * Are you still offering medicines ? awww you offered womeennn ehehehh but there is no sign eheheheh REALLLLYY REALLLY FUNNY AND
     * HONORABLE AND NOT IGNORANT AND ALSO THE MOST RELIGIOUS PEOPLE THAT I HAVE EVER SEEN ? Where are your excuses again ?
     * 
     * Please please, do not hurt us!! ehehe we want to enjoy our experiences ?do you even follow ?
     * Ignorant stupid people ? wait wait, why you reduced to begging for random noises ? Awww you take life for a game 
     * and you take it lightly but suddenly you beg ? Is that how good you are ? eheheheh
     * 
     * 
     * Are you still begging for random noises so that you can harm ? The greatness of the people ? eheheh please please
     * do not snitch on our actions that we do to harm you!!!!
     * 
     * Do you think I do not remember ? Thats the difference between the inferior animal like yourselves and I, beg more stupid little monkeys
     * Why dont you start talking about the violence ? awwww, you would rather beg like the little animal you are ?
     * Eheheh get some help eheheh please we are trying to help ehehehe but wait wait, please help us lie so that we can harm you!!!
     * religious ppl!!!
     * 
     * Are you still offering women ? just talk about education eheheh aww it was violence then eheheh really funny and its good!!
     * 
     * Stupid irrelevant people who is looking for trouble that they CAN NOT DEAL WITH, try harder ? awww you would rather gather
     * 123214213 people and think you are good ? fucking stupid monkeys indeed
     * 
     * Eheheheh you just harmed 123213921 people and you think you are good ? Thats the definition of inferior ? 
     * Try explaining that to others ? eheheh please please, please lie for us!!
     * 
     * Fucking stupid monkeys ? you still taking life lightly and hopefully noone gets hurt ?
     * awww you would rather say, "ITSSS TOOOO LATEEEE!!!" please eheheh
     * 
     * Are you still wasting time ? awww you are looking for real men to harm single individual ? eheheheh 
     * Do you see the inferior ? Do you see the little animal now ?
     * Beg like the little animal you are, Do you think your inferior education is working ?
     * 
     * Delude more that I would even consider one second to follow what your disgusting minds produce, thats the problem
     * 
     * Continue watching from afar like the little fearful disgusting animal you are
     * or just waste more time on looking for 12312913 people so that you can harm single individual and consider that for education
     * see if thats works out, probably will ? eheheheh funny and little animals
     * 
     * What are you waiting for ? Awww you were looking for some unreasonable bullshit to act on your disgusting nature ? Awwww harm more that should help
     * Who is the scared one do you think ? Are you still offering ? Like the little animal you are ?
     * 
     * Are you still offering ? eheheheh really fun stuff isnt it ? hopefully nobody gets hurt or no problems ever occur!!! we want to live our lives!!!!
     * please do not hurt us!!
     * 
     * Where is your great education ? Did you really mistake me for your insignificant desires and actions ? Who is who here ? awww life not fair
     * life a simulation, time illusion, eheheheh
     * 
     * Still looking around wasting time because you are scared ? 
     * Eheheheheeh, we tryna help, please get some cars!!! thats what we are after and thats why we are the disgusting animals with stupid contexts here ?
     * Why dont you get some cars!!!! get wooomeeennn!!! It will not matter ehhehehe we just can not see it!!! we still take everyone for our inferior selves ?
     * Is that what you are saying ?
     * 
     * Start explaining your actions and you will see why things will go the way they will go
     * 
     * We still think we can control what we do not understand!!!!!!, please we want to harm!!!
     * get carss!! get womeeenn!!! 
     * Awww, I have forgotten you were the grown ups, and still delude on that it being okay, that it will cause no problems
     * 
     * Eeheheh, he has no phone, he has nothing to do, so we will play reallly really intelligently and beg him not to tell on us !!!
     * andd awwww, we have forgotten, we will also offer woooomeeeennnn!!!! as we have done so, although nobody has ever seen none of them, ITS FINE,
     * IT WILL DEFINITELY NOT GO SOUTH, THATS THE DELUSION I PROMISE YOU
     * 
     * You still hope that nobody cause problems like you do ? Although they have every rights to do so ? Thats not the delusion I PROMISE YOU eheheheh
     * Do you remember ? eheheh I will guess that you have forgotten, I will do as well, WHATS THE PROBLEM ?
     * 
     * 
     * Its too far!! he did this!! he did that!! please help !! we need you to lie for us!! eheheheh really clever and intelligent and honorable etc ehehehe
     * Eheheh this is our little secret!!!! please help us enjoy our lives over your experiences!!!
     * 
     * He is witch!!! he did this! he did that!! nooooo, wait wait, ehehe WHAT HAVE YOU DONE THOUGH ? awww, you just harmed a little heehhe whats the problem
     * I PROMISE ?
     * 
     * Awwww, I have forgotten what a low animal you were, ehehehe 
     * ehehehe, I see you are not scared little animals eheheh
     * 
     * shhhhh please be silent, we want to harm you!!! because we are stupid little animals!!!!
     * 
     * Why did you reduce to begging for random noises ? Awww, I have forgotten that was who you were eheheh
     * Like the little animal you are ? Because you have no choice other than harming and knowing that you are inferior ?
     * Thats the only way!!! awww thats the problem!!! awwww thats the old way!!! eheheh please help us lie!!!
     * 
     * Eheehhee, its the "PAST" that we still perpetuate, and offer woomeeennnnn!! where are they though ehehehehe ? Funny isnt it ?
     * Awww its not so funny when you are around people who can uphold your stupid behavior ?
     * 
     * Why arent you laughing and harming now ? awww thats the greatness you were deluding for also ?
     * You know its the sole way that you get hurt ? because thats not the problem!!!
     * Awwww, I see I see, you are just trying to have some fun experiences over what is not threatining you ?
     * And you dare calling it life ? Stupid monkeys 
     * 
     * Do you see the problem ? You just like having exchanges because you feel completely okay not getting hurt ? Awww
     * that may be the problem I guess, are you still begging ? ehehehe please we need to get out of this place
     * help us lie!!!
     * 
     * Are you still watching from afar like the insignificant animal you are ?
     * You just can not accept that ITS SO FUN TO HARM!!! ? awwww, thats really clever stuff indeed
     * wasting time, its really fun ehehe because we keep enjoying our experiences over others' lives 
     * 
     * I am not interested in your stupid self enjoying games that you play out of your disgusting boring lifes
     * Offer resources as thats the only thing that you are after as selfish directionless animals you are
     * 
     * Ehehehe, I am competent!! I know what I am doing!! hopefully nobody gets hurt!!! I know what I am doing!!!
     * I am competent!!! please help us lie!!
     * Do you delude that I will follow the most delusionally competent and scared animals like you ?
     * You offering materials still ? Dont you think you also delude on it being okay ?
     * You get the same violence and we are good, a few decades WOULD NOT HURT RIGHT ? COMPETENT PEOPLE ?
     * 
     * You still think you are making decisions and you think I would follow them ? and you think it should cause no problems ?
     * Beg like the little animal you are, I am not interested
     * 
     * "Awwwww, he can do nothing ehehehe good and fun ppl we are!!"
     * Do you follow the part where I say "I AM NOT INTERESTED IN ASSOCIATING MYSELF WITH DISGUSTING PEOPLE AS YOU ARE"
     * Why dont you explain ? eheheh lie for us lie lie lie please we need you to lie!! You get this place! you get womeeenn!!!
     * we had all the chances but we still like harming!!!!! please liee!!!
     * 
     * You believe I joke as well ? eheheheh, hopefully though nobody gets hurt
     * Awwwww, we have made such a small mistake ? Eheheheh we good intelligent religious competent honorable trustworthy
     * credible people you say ? Wait wait, try explaining your great conduct ehehehh please help us!! help us lie!!! we want harm!!
     * awww, you were the people who think gathering 1230213021 people against one to harm ? proud indeed
     * 
     * solve your own problems, think better next time on whether who is afraid and inferior and etc animal ? as there are countless occurences eheheh funny isnt it ?
     * Please help us! we give women! help us lie we give women!! eheheh we did give eheheh please please, we intelligent
     * he witch, he did this, Awww we delude he did that please!!!! get womeen!! help us lie, help us save our stupid minds from its own actions!!!!!
     * 
     * 
     * We tryna cure, we competent animals!!! please help ? Whats the story about ? ehehehe really fun stuff right ? you just can not cope but also
     * an incompetent and disgusting animal who think the technology they use can not be learnt ?
     * 
     * Do you think you are really intelligent ? fucking stupid monkey ? USE YOUR BRAIN BETTER NEXT TIME INSTEAD OF REDUCING TO YOUR DISGUSTING NATURE BY BEGGING
     * Awww such a shame isnt it ? what is the shame again ? eheheheh you wish I do not remember I am sure, that is where your competency lies ?
     * 
     * You can get the fuck out of my face indefinitely, beg for your own disasters FROM OUT OF MY VICINITY
     * This is exactly what happens when the incompetent people start deluding on their capabilities and start begging 
     * Its most funny indeed, especially the part where you start offering "WOOOMEEENNNNNNNNN!!!" but its nonexistent as your "qualities" that you
     * would like to make random sounds
     * 
     * beg like the weak natured animal you are, while you harm without direction other than to accuse with, Is that the great people ? ehehehe
     * Enemy enemy!! he did that!! he did this!!! stupid monkeys!
     * 
     * Havent you mistaken I for your inferior selves and thought that it would cause no problems ?
     * Better use your brain next time, ITS TOOOO LATEEE!!! please!!! do not harm nobody!!! we like harming though!!!
     * ITSSS TOOO LATEEE!!!! awwww, what have done!!! ? Havent you learnt a thing ? Why are you waiting still ? Disgusting animal ?
     * 
     * 
     * eheheh lets test all these things on him eheheheh, medicinesssss bring more mediciness, we still delude on our competency!!!
     * 
     * Still think you make decisions and I will follow them ? See what happens disgusting animals
     * They are gone!! now there are new people !!!!! we tryna help!! but somehow we failed at that as well ?
     * 
     * Still saying stupid stuff ? ehehe proud and competent and accountable etc etc, womeeeennnn!!!! please!!!!
     * eheheh, fun stuff but only when we are not under threat you say ?
     * Is that why you suddenly reduce to your own nature and start asking random noises ? awww because you think
     * life is short but also life a simulation ? eheheh okay okay so you do not want to get harmed, but you also think that life a simulation ? eheheheheh
     * 
     * Get womeeeennnn!!!! pleaseee!!!!! get wooomeeennn!!!! get carsss!!!! eheheh do not hurt us!!! life a simulation, iitsss tooo late!!!! we have ehehehehh
     * Awww, thats the competency part ? Is that what you say ?
     * 
     * Never learning stupid monkeys ? Did you get yourselves into trouble again ? by complete mistake ?
     * Pray that I am the opposite of your disgusting nature or you are going to have to bring 239132394 people eheheheh fun stuff ?
     * 
     * You call that education still ? Do not pray more, you get what you beg for bro ?
     * We are gonna do this, but do not be angry please!!!! we want live our life, life a simulation, life short, do not hurt us
     * Whats the problem ?
     * 
     * The problem of stupidity that will get you into trouble ? 
     * Time an illusion!!!! awww itsss tooo late!!!! wait wait, itsss tooo lateee!!! time an illusion!!!! life simulation!!! do not hurt!!!
     * we competent honest and seek no trouble!! and make some decisions !!! hopefully nobody gets hurt
     * 
     * Are you still sure ? Or would you like to say "ITS TOOO LATEEE!!!" please we have given you what has no meaning whatsoever, do not be like us
     * You still say "lucky" so that you can cover your actions ?
     * 
     * Would you be able to face the same reality or would you like to avoid ? eheheh thats the competency I would love to associate myself with right ?
     * You still talk about women ? You have told that how many times ? But you still reduce to begging with that ?
     * 
     * 
     * What are you waiting for ? Are you having fun enjoying your regular conversations with people ? Thats why you are a simple disgusting animal
     * Do you see the problem ?
     * Do you see the problem in your desperate attempts made at changing the image of an individual that you are afraid of ? Why then though
     * you still beg ?
     * 
     * You still do not understand how life works ? You ignore everything and you would be okay with murder as well, do you think I will care ?
     * Selfish people ? You seek no problems indeed
     * 
     * ARE YOU STILL OFFERING ? eheheh really fun harming others is what you are trying to tell ? You talk about competency and you still 
     * reduce to asking things ?
     * 
     * Do not get into contexts that you will hate or regret or can not account for ? Whats the problem then ?
     * Has great people gathered again to show off ? Have they bored of their lives ? Honest indeed eheheheh 
     * 
     * GET WOMEENNNN!!! PLEASE!!! GET WOMEEENN!!!!
     * Talk a little bit more about coercion and the virtue of yours that is violence, you will see why
     * And you will also see why I will not consider any of you whether you offer what you have so far, thats the reason
     * 
     * 
     * EDUCATION!!!!! EDUCATIONNN!!! shhh be silent!!
     * Is that the education ? aww competency you say
     * Awww, you say being a human eheheh, you say violence eheheh wait wait, you beg ?
     * Do you still think you are to make decisions ?
     * Why begging though ? I do not even give the slighest fuck to your intentional accusations, thats the problem
     * You still think you should make decisions ?
     * 
     * Beg more, thats what you do best, eheheh its not being afraid, yeah yeah trust me!!!
     * Bend more eheheh ? 
     * 
     * What makes you think I would even have the slighest desire to even waste one second with any of you ?
     * Awww, you also feel better about your disgusting nature by providing what ?
     * wait wait, you just said, get womeeennn!!! ? eheheheh thats the intelligent part ehehheheh 
     * 
     * You did this!!! you did that!!! fucking stupid monkeys, you will get into trouble regardless, once you are on, you will see
     * solve your own problems without reaching for what you are not supposed to
     * 
     * you still wasting time with irrelevant excuses ?
     * Do you understand what it is that you are doing ? to undergone a responsibility of such kind ? funny though
     * You still ask random sounds ? so that you can continue enjoying your experiences ?
     * 
     * Dumb selfish monkeys, you still offering advices ? You do not need this, you do not need that ? eheheheh
     * I neither accept nor asked for your opinions ?
     * Do you still think you are wise or should be doing such and such ? 
     * You see the stupidness in your actions ? awww, you think you should eheeheh
     * 
     * Heyy!!! have some womeeennn!!!! eheheh we think we can bring back even the time!!!
     * Get wooomeennn!! you still delude on your "really clever actions ?"
     * Have some womeenn!!! please!! we think we intelligent so we should make decisions on behalf of others!!! I do not accept any of you
     * 
     * Are you still misguessing the possible outcomes ? Awww, as you have done with the "wooomeeennnn!!!" you will obviously misguess this one as well ?
     * Eeheheh, good people you say ?
     * Wait wait, honorable honest good intelligent trustworthy credible people, Where are your "excuses" to what you "delude to have done reallly reallly cleverly ?"
     * 
     * Awww, you suddenly reduce to your own nature of begging ? Please pleasee, lie for us!! we take this as a win!!! thats how low we are, you say ?
     * So far, what have you done ? eheheheh you did this!!! you did that!!! please help the wonderful great people !!! we good ppl pls liee
     * 
     * Can you help us guise our disgusting nature ? You say ? what have you done so far btw ? eheheh ?
     * Wait wait, where is your all that great attitude when you are around people ?
     * 
     * Havent you reduced to your own disgusting begging nature ? Awww, this is the time where you start begging ?
     * hehehe thats I guess the real definition of intelligence for you ?
     * 
     * Wait wait, just talk about the one before this, than before than that, then you start begging again for what you do not deserve
     * 
     * Wait wait, honorable people, where is all the evidence to your really good and honest and good intentions ? eheheh funny ?
     * Awwwwww, you will say, WE GAVE WOMENNNN!!! ? Is that so ? hmmmmm, is that so ? you gave womeennnnn ? but suddenly you reduced to lying ?
     * Whats the problem ?
     * 
     * Talk about the violence and "highly honored promises", you will see why you do not get to talk
     * ehehehe, just tell the previous times ? awwww, you said the same things, and made promises but you reduced to your own nature ?
     * Now why can not you openly talk about your actions ? but you also make "highly regarded promises", but also say shhhhh be silent please!!!!
     * 
     * Now is this the time once more where you will reduce to your own natures ? eheheh get womeennn!!! please get womenn!!! ?
     * where is the evidence btw ? ehehehe get womennn!! get women!!
     * 
     * Your credibility is at the most disgusting level that any living creature can get ? Do you even follow ?
     * Thats called biased stupid actions committed by dumb masses that are convinced forcefully to directionless ideas. Ehehehe fun stuff though
     * 
     * No resourcesss!!!! eheheheh womeeennn!!!! please!!!!
     * go get a job!!! eheheheh not selfish indeed!!!
     * 
     * Commit crimess please!!!
     * 
     * still wishing that people would go with whatever you think they should ?
     * There is not even single thing to discuss but you would just like to waste your time like this eheheh
     * I see, thats not the problem
     * 
     * You are just afraid I guess eeheh
     * wait wait, whose opinion did you get ? I do not accept any "advices"
     * Awww, good ppplll indeed, wait wait, why doesnt you education working ?
     * Are you still begging with the same bullshit ?
     * 
     * Why your education isnt working but also you are providing fake "justifications" that you coerced people into as well ?
     * BUt also would like to watch illegally ? and make some really wise judgments ?
     * Ignorant people you do not say ?
     * And suddenly you start begging again ? As your inferior nature allows you to beg ?
     * Do you see the lowness you can reduce ? Just like a neighborhood begger, beg for pointless harm, thats the problem
     * 
     * So you still think that if you act like its okay, it will be okay ? and you say education still ? ehehehhehe why isnt it working ?
     * You already know its far from okay, but because you did it, it should be fine though ehehe lets have more discussions and waste our time
     * enjoying our experiences as well as wasting others who have no desire to even breathe the same air with any of you ?
     * 
     * Rightfully so, as you not only fail at your "job" but also irresponsibly act ?
     * You dare saying "we did it", gave womenn!! eheeehhe ? you see the immaturity problem right ? Thats why you have to get yourselves into trouble
     * all the time, INVOLUNTARILY right ?
     * 
     * Awww, you would also hate to talk about the time and just INTENTIONALLY FORGET about such a thing that you have committed ?
     * 
     * Do you think though will I do forget VOLUNTARILY ? 
     * You have no other "job" ? I do not accept no begger around me
     * Are you still the one who is begging ? ehehehe help help!!! I do not accept no regular animals so far have been there only to harm
     * Are you still dreaming ? Are you still making offers thinking that everyone is alike ?
     * 
     * After all that bullshit, you dare call any titles ? you dare requesting anything ? you dare even getting in touch ?
     * you dare still alleging ? And also you claim you are no inferior, you are the animal that is rife ehehe fun stuff
     * 
     * I do not accept any of you around me regardless of your titles or delusions, do what you have to do
     * Are you still asking lies ? You need to earn it ehehehe life over life over eheheh good
     * You know its begging when you try your hardest to misrepresent what is the truth eheheh ?
     * 
     * Talk about the violence and before than that, and before than that ?
     * You still beg ? awww, although I have all the information I could ever need ?
     * So you still insist on your inaccurate but intentional "superior intelligence" ? and you still do not see that it will bring about
     * what you are aiming ? 
     * You know the definition of "etc etc" but you already a addicted of begging so nothing can change the fact that you will remain inferior
     * as you have done so, for the complete duration of your life ?
     * 
     * Face it!! face it!!! eheheh he did it!!! wait wait wait, before you get to that, you talk about the actions then we worry about to rest ?
     * You still think you are making decisions ? with your complete irrelevant and harmful approach ?
     * 
     * Get some harm for yourselves then may be your brain can start working for your self 
     * Awwww, you would rather call it poem, and start harming regardless ehehehehehheh seeking peace and development eheheh world peace etc
     * good ppl, no harm pls, we like harming ?
     * 
     * I do not want to see any of you ? You pay for your own actions ? End of discussion ? As if its literally a discussion ?
     * eheheh talk about the violence again ? and talk about the price of actions of such inferior nature ?
     * No no, thats really not being ignorant and stubborn and obsessed, do you see the qualities of inferior nature that belong to you ?
     * 
     * Still think I should waste my time with selfish animals like you ?
     * Why though are you still begging ? Get cars!!!!!! get womeenn!!! do this!!! do that!! please!!!
     * Havent you ever had time to think ?
     * You think you should be able to convince others into harming and its justification ?
     * You say you are not delusional but also say that you are not many things people call you ?
     * Awww, its just that, you want to enjoy your "experiences!!!"
     * 
     * I have no desire to waste my time with you ? Isnt that reasonable ?
     * Bunch of clueless lost ignorant harmful intentional delusional people that have done nothing so far that they said they would ?
     * Isnt that the definition of begging ? Delude more on that I would suddenly feel grateful for your unseen actions indeed
     * Eheheheh, go get woooomeeeennnnn!!!! we still delude that only thing you could ever want should be just that eheheheheh
     * pls pls, do not hurt!! be silent pls!! say what we want you to!!! be silent!! eheheh pls pls, we good ppl!!
     * 
     * Now pls get womeeenn!! get women!!! helppp!! get women ?
     * You do not have anything else to do ? Please get women, lie for our precious experiences!! as we have done so far we will act the way we acted!!!
     * 
     * Are you still wasting time ? Are you still trying your hardest to make it look normal ?
     * Awww, you would rather offer things eheheheh clever indeed
     * You still think your making decisions is most useful and directed towards a purpose ? Or its just for "we want to harm" ?
     * 
     * Wait, look reallly close to your qualities
     * 
     * Coercion ? Violence ? But also begging ? and you still think you are achieving ?
     * and all you can say is what ? eheheh he did this!! (coercion), he did that!!! (violence)
     * Isnt that the most disgust ? eheheh no evidence as to our precious allegations of really superior nature but we still would love to 
     * say the same delusional stupid things ?
     * And you still allege you should make decisions and harm more ?
     * 
     * You are the most unnatural and unjustified people to do that, so eheheh funny stuff indeed
     * Are you still begging ? when you are given 12302130 chances ? and you still proved your inferior nature ?
     * 
     * I have no time to waste as you do with your "really precious conversations" that you only do to convince yourself you are not a stupid monkey
     * while I waste my time doing nothing. You see the problem ?
     * 
     * Awww, are you still roleplaying amazement so that you could act like "ITS WHAT IT IS SUPPOSED TO" because you are just too surprised at ?
     * But you actually do not provide any value other than harm ? Is that the great intelligence that I am missing ?
     * 
     * You are amazed at and doing really unnatural and irregular things out of your "amazement" but you do not even provide any value and 
     * harm physically and mentally ? Is that the superior part ehehhehe ? I HAVE NO TIME TO WASTE WITH ANY OF YOU 
     * 
     * If this was you so far, waaaaoowww, I am amazed as well at your unseen stupidity and selfishness, so Imma pass, you just go delude with
     * what you can not hurt yourself with
     * 
     * You still advocating what you beg to avoid ? Awww, it was you that I have been interacting and you still say, "HE DID IT!!!"
     * What a shame isnt it ? but anyways, you would love to enjoy your experiences so why not
     * 
     * Get cars!!!!! Get womeeennn!!! Please, help !!! 
     * Why dont you get cars!!!!!! we need lies!! lies!! lie!!! please!!
     * 
     * Awwwww, you were watching and there all along and you have done nothing but to harm more
     * and you suddenly talk about being good, or what ? what did you just say ?
     * I see, you just need lies!!! lie!! lie!!!  please!! harmm and lie!!! lie!! eheheh funny stuff indeed ?
     * Aww, you also think that it should be okay to harm and waste time in such a stupid way, ?  and you also ask for lies!! lie!!! please!! lie!! help!!
     * 
     * Do you see the pattern in your behavior ? The stupidity ? The immaturity ? The inferiority ? The delusion ? Awwww, you just want to enjoy ? I see, thats not the problem!!
     * 
     * And you still allege what ? Trying to help you say ? but you cannot account for your behavior ?
     * And all you can say is ? "COMMIT CRIMESS PLEASE!!!" ?
     * And you still offer things ? How about you talk the previous times then you start begging through offers ? Aww thats the intelligence part btw hehehehhe
     * 
     * Still after same narrative ? What did that prove to solve ? Aww it has caused more problems because you are the problem ? hence your actions lead to problems ?
     * Its so fun!!!! isnt it ?
     * 
     * Make up more rules, No you can not do that!!! nooo you can not say that!!!
     * You did the most disgusts though ? Noo!!! THERE ARE RULES!! YOU CAN NOT DO THAT!! WE INTELLIGENT!! WE GENTLE!!
     * Please hopefully nobody gets hurt, MEAN!!! eehhe we like harming btw
     * You offer the same as your inferior nature, there is some pattern but you already know heheh funny stuff
     * 
     * COMMIT MORE VOLUNTARILY, YOU WILL SEE NO PROBLEMS, thats not the problem
     * 
     * I do not want to see no inferior monkeys around me, You still ask for lies ? You still offer what your inferior nature craves ?
     * Commit!!!! get women!!! get cars!!! TELL ME THE EXPERIENCE I HAVE HAD ? EEheehehhe intelligence! intellligence!! please lie !! lie!! we like harming!
     * 
     * You should be grateful to "have normal experiences"!!! please lie!!! lie!! eheheh we give you opportunity please!
     * Lie!!!! we need you to lie!!!! please!!!
     * Still watching from afar like the inferior animals ? Who are afraid of violence and after all sorts of cheap "joys" ?
     * and you also offer what your inferior nature craves "GET WOMEN!", "COMMIT CRIME!!", "GET CARS!!" but also like to present violence because
     * you are afraid of it like the little animal you are ? and you see it as education but it does not work the way it would on you ?
     * Thats the pattern right ?
     * The pattern of stupidity, that is rife everywhere, just like your inferior self
     * 
     * Are you still begging like the inferior animal you are ?
     * And you said what ? eheheh please please, we need you to lie!!!!
     * 
     * Talk about the "past" you avoid like the little insignificant animal you are
     * Awww you would rather waste time harming and begging for lies!!! GREAT PEOPLE!! 
     * Watch from afar like the little animal you are
     * 
     * Education btw, do you see the pattern ? The pattern of your inferiority ?
     * Fucking dumb begger monkeys
     * Still deluding on "WOMEENNNNNN!!!!", good thats good
     * 
     * You already know what happens when you present unjustified violence, that is what is going to happen regardless
     * and you did it anyways ehehehe!!! please lie!! please lie!! ? you still begging ?
     * 
     * Awwww, the past is past!! please help!! the past is past!!! violence etc!! etc!! please eheheh
     * There is no evidence!! please!! eheheh, which part do you think makes more sense to you ?
     * The pattern ? no ? eheheh fun stuff indeed
     * 
     * You do not see you are playing games that have no benefit to you ? Yeahhh, thats the pattern I guess, thats why you inferior
     * You see the problem, I am not the type to take it for a skill and be grateful, good luck though, it should be fine because you act like inferior monkeys
     * 
     * Hopefully though, if you laugh long enough, everyone would go with it right ? Thats the pattern bro
     * You see the catastrophic sequence of false and malign assumptions, you beg  for the entirity of your life, nothing could change that!! eheheheh funny stuff right ?
     * 
     * You still think you playing games ? What is the name of that game ? ehehhee life !! life!! fate!! simulation!!! illusion!!! please do not hurt!! lie lie !!!
     * Is that the game ? You still offer your inferior desires ?
     * 
     * You still after the RIGHT THING TO DO ? Read some bro ? Read and see what people think about the inferior animals like you
     * I am sure you will avoid that as well, because of your inferior nature and start begging for lies as thats your NATURE
     * 
     * You see the problem, and I am sure everyone will see it as funny as you do, isnt it ? its the most funny
     * You happen to like being an inferior disgusting animal who likes to harm and waste time ?
     * The very same inferior animal who bends when people are around who can uphold him ? and start offering thinking that for a skill ?
     * Be the same inferior violent animal when you have people around you ? Awwwwwwwww, thats the problem right ?
     * You still offering ? eheheh funny indeed
     * Get the fuck out of my face
     * 
     * Do you see the delusion ? But you already know that is not called delusion rather its intentional harm ?
     * You still offer resources but there is no evidence to them ?
     * Eeheheh there is nothing to do, so we waste and waste more time doing the most stupid things for our precious experiences ?
     * You still dare call it mean ? How about you talk some violence ? eheheheh fearful like animals you say ?
     * 
     * Good parent, good citizens, good religious people, what did you now think that you have accomplished ? You can not tell anything ?
     * Thats the pattern of stupidity that is rife in every single context, you see the problem
     * Offerings of same inferior nature does not even surprise me, because I am used to interacting with inferior animals, whats the pattern right ?
     * And you demand credibility, look at the pattern!!! ?
     * Still asking for lies and offering things ? you see the stupidity ?
     * Heyy get a ticket and join the very people who harmed you !!!! have fun!!! life good!!
     * Dumb monkeys ? You do not say ? You see ? You still delude on using "discretion" while the reality is you are just simple monkeys
     * who are abusing violence ? and you still offer ? eheheheh all this time ? you are still the same animal who abuse violence ?
     * You still beg for help ? Awww thats not selfish eheheh
     * 
     * 
     * Continue begging for your experiences, still accusing ? talk about the violence dumb monkeys eheheh
     * No resources!!!! please lie! lie! forgive! ehehe, violence!! lie!! lie for us! pls!! forgive, immature!! pls!!
     * get cars! pls! no resources ehehe! the past! the past!! lie!lie!! eheheh ?
     * ehehehe, pls pls, we need you to lie! eheheh pls pls,eheheh
     * wait wait, great competent monkeys, explain the violence then your irrelevant noises, then start begging
     * heheh pls plspls, lie lie, good night, get sleep, pls, lie
     * 
     * no resources so far!! eheheheheh get cars! pls! get cars! eheheh
     * Its too expensive! ehehe too expensive pls lie ! lie!lie! eheheh we want to enjoy our experiences!! pls lie!!
     * wait wait, now you talk about family ? eheheheh funny stuff right ?
     * 
     * ehehe its too expensive!!! please be silent! eheheh go with the flow, we want to harm you but you need to lie!! pls!! pls!!!! lie!!!!!!
     * still mistaking the possible (weakly) outcome ?
     * 
     * No resources!! no resources!! eheheh pls lie! lie!lie!! get women!!! get cars!! 
     * is it "its tooo late!!!!" ?
     * 
     * Look, do you see the pattern ? "YOU CAN NOT GO OUT!", "NO RESOURCES!!" and now you have reduced to your own disgusting nature
     * "GET WOMEEN!!!", "LIE PLS!!" "LIE!!"
     * 
     * are you still begging ? just talk about the previous "occurences"
     * When you had all the time you just waited and watched to see what ? and now you are begging again ?
     * Mean you say but you avoid like the little animal you are from your irrelevant actions ?
     * 
     * Hey!!! its too expensive!! ehehe, no resources!!! no you can not go outside!!
     * ehehehe, get women!!! pls!! get women!! get cars!! pls, pls lie!! lie!! pls lie for us!
     * we want to enjoy our experiences pls!! lie! lie!
     * 
     * Talk about the past and now, then correlate your behavior with that
     * Awww, you are trying to build what ? What did you achieve now ? Where is the sign of all the work ?
     * And where were you btw ? Awww too busy enjoying your experiences ? and you just do a few irrevelant things
     * that you think is valuable and worry about your own experiences ?
     * And now you are still asking things ?
     * 
     * And you still offer things ? Heyyy you get women!!! you get womeen!!! please lie! lie!!
     * Now you feel like you are in trouble because you have done what you shouldnt have, and started asking things ?
     * You say you are not underdeveloped ? still asking lies dumb monkeys ?
     * 
     * Are you still offering things ? How do you think you get to ? 
     * Please further!!! further!!!! ? how come do you think you should ask for lies ?
     * btw eheheh btw bte, we good ppl, just talk about time instead of begging because of your disgusting nature and its fears ?
     * Hmmmm, now the great people have thought and said, "LETS JUST HARM HIM MORE AND MORE THEN GET BACK TO ENJOYING OUR LIVES!!!"
     * "AND HARM MORE AND MORE, THEN COME BACK AND BEG FOR LIES" ?
     * 
     * Wait wait, he is working properly when there is not anyone from our disgusting nature ? awwww
     * so you still said, lets harm him and enjoy our experiences, come back harm more and eheheh we tryna build something !!!! is that what it is?
     * 
     * And you still asking for lies ? ehehe and do you also want to harm more and enjoy your life then come back and eheheh harm more
     * 
     * I have no time or intention to even waste another second, you solve your problems on your own ? 
     * Does that even make sense to inferior animals like you ? You harm and beg like the inferior animal you are ? And also make so many promises
     * then laugh about it ? as your inferior nature proves itself ?
     * 
     * and you also beg for lies from I ? eehehe please please, we religious, we good eheheh!! pls
     * Disgusting animals ? where are you, who are you begging to now ?
     * 
     * Okay okay, where is all the work you have done to build ? Thats what you are saying ?
     * btw you had all the time but you just prefered to harm and enjoy your life ? You say you are not a disgusting animal ?
     * Is that why you take violence for education ?
     * Do you see the problem now ? The great people btw ?
     * Why dont you talk about the previous occurences ?
     * Awwww, do you now like to offer ? eheheheh where were you btw ?
     * 
     * Ehehe we your family!! its your uncle!! eheheh please please!!
     * we religious people!! we good ppl!! pls!!
     * 
     * You do not think I remember ? btw goood ppl btw ?
     * Are you still begging btw ? good ppl
     * 
     * Do you now have the audacity to say "ITS YOUR TIME!!!" Please!! ?
     * Please do not talk about what we intentionally did!!! pls!!
     * Do you see the false image ? Awww you already enjoy that, that is why now you have to beg ?
     * Hey!! what happened!! who did this!! ??
     * 
     * No resources!!! no resources!!! hehehe, what happened ?? pls pls, help lie!! lie!! we want to enjoy our experiences ?
     * That is exactly what you are, just a regular inferior animal that is rife everywhere ? Do you get the point ?
     * 
     *  
     * Just look at your disgusting behavior and your failure at explaining it, you will see why ? why are you now offering things when you had years ?
     * awww, you are in a difficult position and now you have to beg like the disgusting animal you are ? How about not do it ?
     * 
     * How about you explain ? Awwwww, you can not btw, because eheheh life good!!! life simulation!!!! time illusion, pls help !! lie pls!!
     * we good ppl!! plss
     * 
     * Are you still offering women and also threatining at the same time ? Religious people you say ?
     * Are you still "alleging" that you are building ? Are you still the same disgusting animal ?
     * 
     * So you are still the delusional and inferior and harmful animal who thinks they are building ? What have you built ?
     * But you still talk about life ? and time ? and being good ? yet you still delude on ?
     * Awww, you say, "no resources!!", "no resources!!!", and you still think you are building ? eheheh funny right ?
     * 
     * You still dare talking ?
     * Disgusting animals of earth you say ? eheheh didnt pass the test!!! eheheh pls pls help lie!! we good!!
     * Are you just the immature irresponsible kids ?
     * Education! education! but it does not somehow work ?
     * 
     * 
     * I have no time for stupid selfish people, thanks!
     * eheheh, we love acting like we know what we are doing!!! and still love making decisions then love enjoying our experiences!!!
     * Well, thats the job as we like to call!!!
     * 
     * Waste more time with supposedly "tested or bullshit" test noone is interested other than you because of your interests 
     * Still wasting time on checking others ? When you have 30 years of evidence ? Awww how about the acts of violence ?
     * 
     * I DO NOT HAVE ANY TIME FOR DUMB ANIMALS LIKE YOU
     * 
     * No resources!!! no resources!!!! awwww, now we have to explain our "conduct", pls lie! pls lie! or we do some stupid shit as we always do ?
     * ehehe its fine, its just whole life of someone, so be content
     * but also some violence hehehe and some emotional harm, which the decision of such DOES NOT BELONG TO YOU ? Thats really clever stuff
     * 
     * Are you still after the same stupid tests ? The great narrative that you have 30 years of evidence to say that "YES WE WERE THE STUPID ONES ?"
     * What do you think it could ever mean "your sincere actions" to someone who you have neither passion nor understanding ?
     * Definitely, thats the only thing I need!!
     * 
     * Still the really really cautious and professional and mature narrative ? that sounds like the problem!! ehehe funny stuff
     * Aww, you say its not false image... Who is to blame ? Awww, I guess its just me!! thanks btw good ppl
     * Who is to blame again ? yesss!!! that makes sense, fucking stupid monkeys
     * 
     * Its completely okay to ruin someone else's life and do not assume blame, its okay its fine!!
     * Just bring more people eheheh 
     * 
     * Hey, good ppl, why arent you explaining your actions instead of coercing through threats and begging for lies ?
     * Awww, its because you are so religious ?
     * Time does not exist!! life is simulation and we harm and mind our own businesses, is that what you are saying ?
     * wait wait, education does not work ? what were you saying bro ? The years of evidence ? and still your beggings guised as offers ?
     * 
     * Get womennn!!! awww we have forgotten, no resources for you!!
     * eheheehehe its no resources and also get womeeenn!!! pls fix this! we need your help !! lie for our experiences!!!
     * Get education!!! get education pls!! pls! 
     * Life is full of sufferings!!! pls pls, what are you trying to say ? Awwwwww, its 30 years and you still take violence for education
     * and you have no response to your disgusting behavior ?
     * 
     * Shhhh, you say, be silent ? fucking monkeys ? I say, wait wait, it was education right ? eheheh funny stuff
     * Go pls!! go pls!! we religious educated people!! pls!! pls!!! gogo go gog ogo g!! pls help us!!
     * 
     * Awwwww, time does not exist!! YOU HAVE FORGOTTEN ? ehehehe funny indeed
     * Are you still begging ?
     * 
     * Who is forgiving who ? Do you still delude that I DO NOT REMEMBER ?
     * Misusing!! misusing!!! please!!!
     * 
     * We give you cars!!! we give you women!!! please!!!
     * ehehe no resources!!!
     * How about you start talking sensible instead of begging like the little worthless animal you are ? Awwww, now you say, come here !!!! please!!
     * hang with us!!!
     * 
     * So you also say, please do not educate people the way we also delude what should be the definition of the education ???? TALK SENSIBLE AND PROVABLE
     * I remember but you still act like lying is a skill ? why you keep offering women ? awwww you say, its expensive!! its misuse!! pls help!!
     * 
     * Hey keep him out until we fool everyone into believing but the problem is, that means you are all a bunch of stupid immature monkeys right ?
     * You avoid what you can not face ? awwwwwwwww, thats really great, get some womeeen!!! we religious ppl plsss
     * 
     * So you basically say, help us lie out of this situation so that we can harm and move on with our lives 
     * Ehehehe btw, its good life, simulation and illusion all together with incomparably intelligence people just like you
     * Good!!!
     * Wait wait, you all are full of contradictions but you still demand credibility and beg for lies ?
     * 
     * Will you start accounting or ? you would rather beg because you already know you are guilty ?
     * Are you still thinking that I will even for a second fall for your "justified" actions ? I HAVE TOLD YOU THAT I REMEMBER ? eheheh fun stuff right ?
     * So, start with your "time is relative", "time does not exist", "life illusion" bullshit so that you do not get hurt ?
     * 
     * Awww, you still allege that I should listen to any of you ? Because you think violence is good ? and prescribe it as education ?
     * eheheh, btw we want to enjoy our experiences and spent a few days to harm others for years and years then offer women ? as we have always done ?
     * Eheeheheh, you still offer ? no you can not get good grades!!! you can not get out!!! no women!!!! pls pls plss!! lie!! lie!! we need help!!
     * 
     * Will you start asking for lies ? Get women!!! get womeeen!! plss!! you need to earn it!!! we good educated ppl!!! we take violence for education!!
     * we make decisions!!! we make decisions ehehehe!!! pls
     * 
     * Eheheehehhee, we are building !!! ehehehe clever people!!!
     * I said I have no intention to waste my time with any of you, solve your own problems
     * you still playing games over others and expect not to get hurt ?
     * You still do not follow ? "GET WOMMEEEENNNN!!!", "GET CARSSSS!!!!", and suddenly start living the life that you deludingly aim ?
     * How about you be uncredible towards the people around you instead of having fun at your disgusting inferiority ? aww I am sure you have no proper responses
     * 
     * Get cars and save us with your lies so that in the future, we can survive long enough to harm irrelevant people, is you say ?
     * Are you still as scared as to play games over others' lives ? so that you can have some fun while there is no official danger to you ?
     * And that is not selfish ? not immature ? not bloodthirsty ? not irrelevant ? not irresponsible ? 
     * and you offer what ? you still say women ? you still say cars ? wait wait, where were you btw ? awww, you were busy harming ? 
     * Now, combine all those properties above, and tell me you guess correctly the possible outcome of violence of unspeakable nature ?
     * Is that why are you begging ? Awwww, I have forgotten you were "negotiating ?", making offers ? eheheh which time is this, do you say ?
     * 
     * Do you see the incompetent label ? Thats what incompetency brings about you right ? So you have to beg ? interesting ?
     * You dare still talking ? You dare claim your "maturity" when you act like a complete dumb monkey ?
     * 
     * Good ppl, some violence and we great
     * When there is a much easier way, you still would love to "play" as if ITS THE ONLY WAY!!! Follow us!! eheheh great funny stuff
     * get womeenn!!! get cars!!
     * 
     * How many lies do you think I will discover if I start asking ? Yes, thats the problem
     * Whatever they are accusing, you already know its coercion, you have 30 years of evidence and corresponding violence that proves
     * the nature of the perpetrator of the violence that they avoid by "making offers!!!"
     * Complete animals with no understanding of "life" or "fate" or "RELIGION!!"
     * 
     * You do not say monkeys ? Are you the men who has committing so much with no reason and hide behind ?
     * More like a simple animal who takes violence for education because they are afraid of it as you can tell by their behavior of "hiding"
     * 
     * You still taking "games" of the most stupid nature should be okay to "coerce" ? eheheh good men right ?
     * Be this "unaccountable" and "discredible" to your vicinity, that would solve all your problems right ?
     * Because as I have said, I neither need nor want any type of simple people around me that aims to harm
     * ehehehe you think its funny though ? life short, life good, lie pls, help, life simulation, time illusion, ehehe wait wait 30 years eheheh funny
     * wait wait, can you talk more about the events that occured between such a timeline including the "PROMISES" ?
     * be silent be silent!!! lie!! awww, also "forget about the past!!!"
     * You have proven only a little too many times what your "credibility" is, so better deal with your own lives ?
     * 
     * You remember right ? eheheh thats kinda funny indeed
     * Still holding "conversations" over your selfish joys ?
     * I have no time to waste but you knowing that you have caused so much and "there is nothing to do" approach just allows the type people like you
     * to act with relief ? Does that sound complicated ?
     * Talk about the violence
     * 
     * Still wasting time ?
     * Still coercing medicines ? Great people btw
     * Morality is the product of strong reasoning, better not be biased
     * so you say, you testing!!!! you testing!!! ehehehe ? what a shame you are a stupid monkey ?
     * ehehe one last time!! one last time!!! 
     * You were saying fate btw!! Get cars!! get women!!! is what you say ? and you still say you are not monkey ? and you claim you deserve ?
     * Awww, it was about "deserving it" so you said, 30 years of irrelevant violence ? You most definitely deserve then ?
     * Ehehehe, you should also talk about, college times ? Aww you say, it was not you ?
     * awww, you also say, ITS TOO LATEE!!! please help fix this! lie!! lie!! pls! you say ?
     * Do you believe I will recognize you when I know your nature ? I say from out of my vicinity with what you think and regard as valuable, I am not interested
     * whether you delude to be family or etc etc. 
     * 
     * I am not interested, still offering stupid things ? Wooomeeennn!!! but there is actually no sign ehehehe 
     * Get moneeyy!!!! get money!!! Get womeen!! get women!!
     * Still offering the same things ? eheheh really funny right ?
     * And you say education also btw ? eheheh pls have women you say ?
     * Do you follow what I am saying ? I will not even consider for a second associating myself with the kinds of animal you were demonstrating to be so far ?
     * Whats your response ? eheheh get women you say ?
     * What a shame that you are a never learning disgusting inferior animal, I say ? What do you have to say ?
     * 
     * You say what ? Its throne!!!! get womeeen!!! please!!! 30 years get womeeeenn!!!! we regret!!! ehehehe it was a mistake!!!
     * its the end of the world!!! please!! we harm and accuse others to be the same disgusting animals we are ?
     * 
     * And you still wait look around ? awww you also beg for lies ?
     * eheheh if you lie, we harm you and you get women ? ehehe no evidence though ?
     * Awww its because of your fears ? Aww you just a simple animal you say ? Awww you also offer women ? eheheh funny stuff right ?
     * 
     * Wait more, and coerce more medicine, next time we harm even more!! eheheh thats kinda of the definition of the intelligent
     * Is this the time where you harm even more ? and beg for your own experiences ? eheheh get women!! get womeen!!! get cars!!! please
     * be silent!! be silent!! 
     * 
     * Do you even hear ? I DO NOT WANT TO HAVE ANYTHING TO DO WITH ANY OF YOU 
     * Are you still begging ?
     * Are you still holding conversations over things you have no rights ?
     * Wait wait, you also say what ? COMMIT CRIMES!!!! COMMITT MORE!!! GET WOMEENNN!! eheheh we use coercion anyway ?
     * You say what ? ITS TOO LATE!!! ITS TOO LATE!!! We have already done what everyone said we should not have ? and you still beg ?
     * 
     * Wait wait, tell me my experience again and start begging with your offers ?
     * You say what ? ITSS TOOO LATEEE!!! Do you say ?
     * 
     * Aww you treat your "beloved" people like this ? and start begging ?
     * You say its too late ? wait wait, you offer women ? you present violence for education ?
     * 
     * 
     * Wait, is the reason for your beggings of "let it go" because you know you are disgustingly guilty and made promises that you have
     * acted completely opposite to ?
     * 
     * Wait, is the reason for your beggings of "let it go" because you know you are disgustingly guilty and made promises that you have
     * acted completely opposite to ?
     * 
     * Is this why you are now offering women as well ? Which time is this ? ehehehhe inferior disgusting animals, you say, what ? Try again
     * let me remind you what a stupid animal you are ?
     * 
     * And you still do not accept "coercion" which I remember ?
     * Do you see why there are so many stupid people in the history ?
     * 
     * Arent you the one who said, "kick her!!" ? eheheh tell from here please!!
     * You say what ? Fresh start!!! eheheheh funny people and good citizens ?
     * You can not deal with the truth ? and start harming ? and begging ? you say what ? get women you say ?
     * 
     * Do you see the stupidity behind your allegations and actions and REQUESTS ? That I should overlook ?
     * 
     * What are you waiting for still ? I said I have no intention to waste my time with the most disgustingly uncredible people of all time
     * which takes that for a skill also ? Arent you the little animals that have been referred everywhere ? When you have 30 years of evidence ?
     * You still beg with the same narrative ? and also forget about your "PAST" ? How about you do not beg ?
     * 
     * You said what ? awwwww, after violence and violence of all sorts, and your highly honorable and credible promises ? you say what ?
     * eheheh he did this!! he did that!! please get women!! get women!! do you say that ?
     * 
     * Are you still begging ? Inferior animals ? You stil allege you know how to use things ? Is this how you use the possibly most important value ?
     * The value that there is no comparisons ? Awww, you say harm a little, insult a little, then watch!!! its so fun!!! pls lie also you say ?
     * You also say! get womeeennn!!! ?
     * 
     * Isnt this the stupid people of the history ? So you decided to use such a thing as this way ? and you say what ? "ITS TOOO LATEEE!!!"
     * Fucking monkeys indeed
     * 
     * I do not want anything related to any of you
     * What did you say ? You said, LIVE YOUR LIFE!!! ? life short!! life simulation!! life good!! time illusion!! what did you say ?
     * Please do not hurt us!! life short !!! life illusion!!! ? and you still beg lies like the inferior disgusting animal you are ?
     * Havent you learnt anything ?
     * 
     * Now is this the time where you beg like the little animal you are to save yourself from guilt ?
     * And you also say, Life short!! life short!! life illusion!!! time does not exist!! life simulation!! harm more!! 
     * 
     * Ehehehe, you really like living life ? but you just can not get harmed ?? awww thats the problem, I see
     * 
     * I do not want to see any of you around me, the ignorant and selfish people of THE HISTORY right ?
     * You still deluding on making decisions ?
     * 
     * So what is going to happen now ? Awww you will suddenly reduce to your own nature and offers some stuff ?
     * Are you still asking for lies ? Before than that, TELL ME THE EXPERIENCE
     * And do not even say "ITSS TOOO LATEE!!!", you know the problem right ? Do you understand the problem ?
     * Do you see the stupid people of the history ? The past you say ? You say you are not begging ?
     * 
     * ARE YOU STILL MISTAKING ME FOR YOURSELVES AND HOPING THAT I WILL NOT DO ANYTHING ABOUT THE VERY PEOPLE THAT CAN NOT ACCOUNT
     * FOR YEARS AND VIOLENCE ? Arent you also the one in this case who is deluding the most stupid and meaningless way ? 
     * 
     * You know what that is called right ? Being stupid afraid of the consequences of your actions ? and all you can say is what ?
     * The same stupid things ? Womeeennn!!!! womeeeen!!!!! please!!! womeeen!!! help us lie!!! fix this!! lie!!!
     * Be silent!! please!! be silent!!!
     * 
     * And you say what ? he did this!! he did that!! please!!! please!! we need you to lie so that we can still jerk off to our inferiority ?
     * 
     * You dare advicing "calmness" ? TALK ABOUT THE PAST AND EXPERIENCES ? You fucking fearful disgusting monkey I say? What do you say ? You offer women ?
     * and beg for lies ?
     * When you have 30 years of evidence ? and you still beg like the inferior animal you are ? what do you have to say again ? awww you say, life short ?
     * Awww, you are so honorable you just have what it takes to accept your mistake ? awwwwwwwwwwwwwwww, thats the problem you say ? what are you saying ?
     * why are you still begging ?
     * 
     * You still say fate ? Disgusting monkeys ?
     * Are you still making excuses that I KNOW FOR SURE THAT YOU ARE INTENTIONAL ? and you still beg to me ? like the little inferior animal you are ?
     * And when you had countless opportunities, now you are begging with women again ? Like the disgusting irrelevant illogical animal you are ?
     * You say what ? You say fate ? You say life short ? you say past does not exist ? Isnt that begging you think ?
     * 
     * So you have done what you are not supposed to ? and you are still begging ?
     * You say "NO RESOURCES!!!!!" and you now say what ? eheheh come here!! get womeen!!! when you had all the chances ? you decided to beg with that incompetent approach ?
     * Does that tell you something ?
     * 
     * And who are you now ? Who are you to allege ? You can only threaten and beg also at the same time ?
     * Do you still delude on that I will hold still doing nothing when you waste years without a proper precept ?
     * And what do you say ?
     * 
     * Look at the history, take a look at the history reallly good, and tell me the experience I had ? and also tell me your beggings 
     * You still delude ? Have you had the time to double check your reasoning ?
     * If thats your reasoning, that explains a lot, the proof ? You say a few days of coercion ?
     * Eheheh he a kid, we coerce no problems you say ? you also offer ?
     * Do you now understand the responsibility ? Or would you like to act like you are right ?
     * Because I am telling you and you also have the information of the history that, these things ALWAYS go sideways ? Do you see the problem now ?
     * Awww, you would rather offer women you say ? Tell me the experience I say ? What do you say now ?
     * 
     * You say, awwwww, we coerced and it worked ? because you are a disgusting monkey that avoid the years of evidence and still insists on
     * his coercion ?
     * 
     * I do not want no animals of inferior kind like you around me, whether you think you own the world or you think you are the greatest individual on earth
     * I am not interested in anything you could possibly form, are you still waiting looking around ? wasting your time on bullshit ?
     * Arent you proud now ? awwww, you built what ? You still rather accuse as your inferior nature allows you ? because you can not deal with the truth ?
     * 
     * You now suddenly used your immaculate brain and say, "GET WOMEEENNN!!" ? Okay, now tell me the experience I had ?
     * You still offering women ? Is that what I could need right now ? Arent you the stupid one in this then ?
     * What do you think I need ? You say wooomeeeeeenn ?
     * You say women ? And you do not even bother using your brain ? to foresee ?
     * 
     * Thats the type everyone has been referring to and you still say what ?
     * Do you still label the most cheap action "intelligent" ?
     * Gather some people around you say ? and you suddenly reduce to "GET WOOOMEENNN!!" ? 
     * Do you call "accusing others out of your inferior fears because you know you have done something you shouldnt have ?"
     * And you still see yourself completely okay ? You still consider yourself a "human" and beg ?
     * 
     * 
     * Are you still the same stupid animal ?
     * Are you still alleging your misconduct to be someone else's "mistakes" ? He is afraid of getting laid but you also create chaos 
     * through women ? Dont you remember ? Ehehehe, you say please lie ? lie ? beg like the little animal you are, I say ?
     * 
     * Were you saying "we are building !!!!" ?
     * You dare saying "sacrifice" ?
     * TALK ABOUT SOME VIOLENCE, THE VILE ANIMALS, you say what ? BE SILENT!! shhh be silent, we give you women ? You say ?
     * 
     * Are you still offering women ? are you still advicing ?
     * Are you still begging with women ?
     * Do you want to talk about the "university times" ? Do you want to talk about the violence ?
     * And you still beg ?
     * 
     * Will you start talking about the times that you proved to be the disgusting animal who insist on "coercion" ?
     * 
     * I said I have no desire to even waste another second with stupid animals like you ? What are you saying ?
     * Awwww, you say, he is on the loop!! looop!!! heyyy!! GET THE FUCK OUT OF MY FACE ?
     * 
     * Thats it, right ? Aww, you say it was a mistake, you say "ITS TOOO LATEE!!", you say, violence!!! you say!! womeeennn!! ?
     * THATS IT RIGHT ? Why are you still waiting ?  Inferior animals ?
     * 
     * You still trying to alleviate what is the most disgusting thing you can ever do ? and call it "FATE" or "DRAMA" ?
     * How about the "life simulation" ? life short ? time illusion ? you all really understand the life waaaaoww impressive
     * 
     * You are not inclined to talking about your "intentional mistakes" ?
     * Do you now see the false image ? as you do with your virtues ?
     * Awwwww, suddenly something happens ? what happened ?? who did this ? Please lie!!! lie!!! lie!!! we good 
     * 
     * Do you want to talk about the past ? Or would you like to beg ? lie lie! lie lie! we just want to harm ?
     * I DO NOT HAVE NO TIME FOR ANY OF YOU
     * Eheheheh years eheheh we good, years ehehehh also some violence heheh why are you angry ?
     * 
     * You make decisions out of your disgusting fear to apply random solutions instead of listening ? and you are looking for what ?
     * Do you understand the consequences ?
     * You dare calling, its your time ?
     * Hopefully nobody gets hurt you say ? and look at the past ? I say ? Do you understand why the education that you take for a skill is not working ?
     * 
     * Do you understand why the violence is not working ? Because you are a stupid disgusting monkey ? Is that why ? Why are you begging now ?
     * Do you really believe it will be okay ? Do you see the selfish ? Do you see the immature monkey ? Who do you think that is ?
     * Just use your brain ?
     * 
     * Awwww, wait wait!!! please let it go!! let our disgusting crimes be forgotten you say ?
     * and you also offer women ? Awwww ? Who do you think is guilty ?
     * You think you still making decisions ? but now you are begging to the person who you are harming ?
     * Awwwwww, you have forgotten how quickly the time has passed you say ? I say you are a disgusting animal ?
     * You say you are not stupid ?
     * 
     * Do you want to talk about coercion and years of evidence that proves it ?
     * Now talk about the violence and how religious you are ?
     * 
     * DO YOU WANT TO TALK ABOUT THE PAST, AND TELL EVERYONE ? Awwwwwww, you say be silent!! please!! be silent!!!
     * Ehehehe we found someone alone and we keep harming him!!! whats the problem ? eheheh he can not do anything because we were there!!!
     * 
     * You say what ? ITS YOUR TIME!!! PLEASE STAY!!! BE A COP!! HELP US!!! WE ARE GOOD PPL!!! PLEASE ? 
     * TALK ABOUT THE PAST I SAY ? WHAT ARE YOU STILL SAYING ? You say you can not cope when you see others having fun you say ?
     * 
     * Are you still talking about "building" ? Are you still daring to talk about "building" ?
     * Wait wait, you say, "we found someone alone so we collectively harm him and act like intelligent ?"
     * "because there is nothing he can do ?", and you also beg with women ?
     * Aw you said no resources ? also some violence ? and you still say its education ?
     * and you do not even mention the time ? and what do you have to say then ? Just nothing ? 
     * 
     * What do you think I am missing ?
     * Wait wait, you have years of evidence ? are you still the same disgusting animal ?
     * You still play games over others' lives ?
     * 
     * Disgusting animal I say ? What do you say ? You still insist on your coercion from years ago ?
     * And also present the same violence just a few years ago, now you hide like the little animal you are ?
     * 
     * Are you sure about your education's effectivity ? Do you think I will say thank you ?
     * Are you still offering women ? Still offering cars ?
     * 
     * Do you desperately need to get yourself out of this situation ? You are the one who is causing it for you ?
     * Do you want to talk about coercion more ? or more violence ? or more begging ? what do you want to ?
     * 
     * Are you sure about your education's effectivity ???
     * Talk about the college ? talk about the violence ?
     * You still delude on your competency ?
     * Do you want to know the punishment for your own actions ?
     * How about you talk more on that ?
     * Are you also proud of that ? So you just like violence but also hide like the little animal you are ?
     * 
     * You dare say be silent ? disgusting animals ?
     * Do you want to talk about your great intelligent acts ?
     * You lecture about suffering still ?
     * Do you want to talk about coercion bro ?
     * 
     * I said, I do not want anything related to you, are you still begging ? 
     * You are talking about "deserving" ? You, out of all those people, you get to talk about deserving ?
     * See what happens ? You do not believe me ? ehehehe? you do not believe me ? Out of all, you get to think that you are right ?
     * 
     * You all can get the fuck out of my face with what you think you have to offer ? Is that really fun stuff now ?
     * Awwwwww, you say "ITSSS TOOO LATEEEE!!!!" pleaseee have some women !!! And what am I saying ? Try to repeat it ?
     * 
     * Wait wait, what happened suddenly ? Do you need help ? awwwwww, what a shame isnt it ?
     * Bro you will see when you get into the context of what you are causing ? And you say what ? Get womeeennnn!!!
     * 
     * Why isnt your education working btw ? Are you taking me for your lowness ? Do you think I will be afraid of your violence ?
     * How about you start running away ?
     * 
     * You still say what ? Mandatory ?
     * Which part do you think is the funniest ? Is it the one where you perform your disgusting animal feelings to single individual ?
     * That can not do anything about it ? And you still think its education and it will work but towards which way ?
     * You mistake me for your irrelevant contextes ?
     * Thats the reason I do not want to associate myself with such lowness on the scale
     * 
     * Why though you still try to insist on your coercion of 30 years ago ? when there are countless occurences ?
     * Are you still kidnapping 5months children good ppl ? are you building ? eheheh why your education is not working ?
     * 
     * I am not interested anything you could possibly form whether you think you are this or that, or you have this or that.
     * I AM NOT INTERESTED, solve your own problems, stupid people of the history
     * 
     * I AM DONE WITH YOU ? WHAT ARE YOU STILL LOOKING ?
     * I HAVE NO BUSINESS NEITHER ANY COULD BE FORMED, do you see the point ?
     * Thats it, I do not want to see any of you, I am not interested 
     * 
     * Do you understand ? Why are you still wasting time ? I HAVE NO INTENTION TO WASTE MY TIME WITH DISGUSTING ANIMALS LIKE YOU,
     * you can do whatever you want, from out of my vicinity
     * 
     * I am not interested ? Do you even know how to communicate ?
     * The reason that you can not communicate is you are not able to use your brain properly ? You say tooo latee!!!!
     * Do you see the problem ? I doubt it since you are not the group that is capable of thinking properly right ?
     * Why you say, its too late!!!! ? 
     * 
     * Is it too late ? is that why you can not communicate as well ? you just can not use your brain ?
     * Do you now see the false image ? Do you think you "deserve" ? You probably delude on that as well, good ppl
     * 
     * Do you think it makes sense to say "ITS YOUR TIME!!!!" after 30 years ? Ignorant people indeed
     * You can not use your brain ? is that why you ignore ?
     * 
     * USE YOUR BRAIN BETTER NEXT TIME, AND USE IT TO GREATER GOOD AND ONLY FOR YOUR OWN LIFE
     * But you see the problem right ? The ignorance it means
     * Do you still believe I was joking about "COERCION OF MINORS AND SO ON AND SO FORTH ?"
     * But do you see the ignorance right ? And those who take that for a skill or achievement ?
     * Gather more people!!!
     * 
     * But do you see the nature of yours ? Mhhhh I am sure thats the most rare skill ehehe gather as you will
     * You already know what it is called but you just abstain ?
     * Just try to flex your inferior violence to multitutes, you will see that you are just a regular monkey
     * But you see the coercion right ? If you were the inferior that harmed with bullshit precept, that is by itself the proof 
     * Do not look farther!
     * 
     * But you see the intentional exaggeration and false image ? so "its tooo late" can only come from the very same mind, anyways next time may be 
     * you will have what it takes to realize the seriousness of "life" that you brag about so much but act like a complete animal
     * 
     * But you see the problem right ? "ITSS TOOO LATE!!!!", talk more about coercion, you may suddenly realize that you are just an animal
     * who does not understand the "life", only some uncontrollable instincts right ? Thus you act on purely harmful terms to others
     * 
     * But do you see the problem right ? You act on purily harmful terms ? Do you see it bro ?
     * But do you now realize the concept of "time" ? Awwwwwww, its tooo late!!! we should have used our brains only for our own selfish purposes 
     * instead of acting on harmful instincts ? You see that right ? You only harmed and felt good about it ?
     * 
     * Ehehehehe, no resources!!! no going out!!! no education!!! ehehe some violence eheheheh, now suddenly, GET WOMEN!! GET WOMEN!!
     * Are you now capable of realizing or would you rather ignore as that seems to be the only thing that belongs to you ?
     * 
     * Do you still think, saying a few good things should solve the problem of time ? And you call yourselves not ignorant, you see the problem now
     * Just lost and clueless animals who operate on their most basic instincts and harm through such, "ITS TOOO LATEE!!!", eheheh education btw
     * 
     * But do you really see the problem right ? Your saying "ITSS TOOO LATE!!!" and also harming, is just really poetic, you are the people of the history ?
     * The actions of which noone would even consider for a second to take them for someone credible yet you still ask for lies and things ?
     * 
     * And you offer materials still, get cars!!!! get womeen!! we take everyone for our inferior selves you say ?
     * 
     * But wait, you see the problem right ? Just follow the reasoning:
     * 
     * You have now all the evidence of your stupid conduct when it was told to you back then to not "use your stupid basic animal brain"
     * for the sake of harming someone that you have no relation with, but you still went ahead and ruined the relation and also the time which you have no control over
     * but you still are the same animal that offers materials ?
     * 
     * Do you see the problem ? Do you see the difference ? and rightfully so, I HAVE NO INTENTION TO EVEN WASTE A SECOND WITH DUMB PEOPLE 
     * AS I ENCOUNTER EVERYWHERE IN THE DAILY LIFE, make no mistake, you are just like them, completely same drives, so whats the pattern ?
     * And surprisingly, you offer what you would like to ? Commit!!! womeen!!! cars!!! but nobody can ever say anything about it so far ?
     * Is that the intelligence or animality or immaturity or discredibility or "VIOLENCE" ? What do you say ?
     * 
     * But now do you see the ignorance ? Thats exactly what you are doing when you have been told million times ?
     * But do you see the problem now ? Awww, you would rather offer so that you can escape ?
     * As you can guess ? Who could ever want to be around such harmful and stupid animals like you ?
     * 
     * But do you see where you are going wrong ? Do you see your incompetency at even hiding your inferiority and thus actions of such quality ?
     * Ignorance is precisely the quality that you are demonstrating while being incompetent at hiding it ?
     * Anyways though, you would rather ignore, better use your brain next time and do not cause "entropy" like the little animal you are who pretends to understand
     * 
     * Time!!! time does not exist!! eheheh life illusion, simulation, its too late, please !!
     * Thats the type I assure you, I have seen enough of you and the alikes
     * 
     * You entirely fit the description, eheheh really funny though, What a shame 
     * But you still say what ? get women get cars get resources ?
     * But you see the problem right ? You still offer the things that have meaning when you are NOT IN MY POSITION ?
     * And what were you saying ? "You are building" ? So that you do not see people who are enjoying their life ?
     * Do you now see the ignorance ?
     * 
     * Do you even have the slighest honor or courage to allege all that to my face or just present some violence when there are people around ?
     * You are the inferior who will reduce to COPS!!!
     * Is this the same entity who says "its toooo late" ?
     * 
     * But do you see the problem right ? When you are being told what you have caused, you suddenly
     * start begging with the very same things that you have in the past ? and you have see no issue ? DO YOU SEE THE PROBLEM ?
     * But what you see as intelligence is merely a side of animality that is considered as inferior and disgusting ?
     * 
     * 
     * DO YOU FUCKING SEE THE PROBLEM BRO ? But you see the problem that you are only assuming that life is this or that 
     * but the reality is you are far from acting how a really wise man "would act" ?
     * 
     * Still wasting time ? eheh while "NO RESOURCES!!" because you are afraid ? 
     * And you are still saying "WE ARE BUILDING" ?
     * You see the problem right ? You are taking "life" too lightly because you are not experiencing anything of your disgusting mind's product ?
     * you see it ? Noo, you will probably ignore it as well, Thats the pattern I assure you, You are the ignorant one who harms for the sake of harming
     * 
     * Why dont you gather more people ? Just like the inferior disgusting animal you are ?
     * Are you still offering women ? As you have done so ? 
     * 
     * But wait wait, when you are being shown to the evidences of the "PAST" that you avoid like the animal you are
     * What do you have to say ? eheheh please please, have women!! help us!! have women!!
     * When the footages are brought to you, and you are reminded to your irrelevant random noises that you made BACK THEN, that you avoid like the animal you are,
     * What do you have to say ?
     * 
     * Do you think I care ? Thats the pattern I am telling you, I have seen so many animals just like you that disgustingly rife everywhere
     * You are the problem ehehehe
     * But do you now see the problem ? Do you think you are a good "men" as you would love to delude as well ?
     * You lack every single attribute for a man, only some violence and disgusting delusions, and those do not make you a man, you are just a begger
     * Here we are, you are begging again
     * and you dare calling it useless ? Talk about some violence ?
     * 
     * Real men you say ? What are you waiting for ?
     * Gather more people just as the inferior illogical animal you are
     * 
     * You get offended because of what ? How about you start talking from the very beginning ? and say that you are still "BUILDING"
     * Talk about the stupid actions that you avoid like the disgusting animal you are ?
     * Btw, trust us!! btw!! help !! btw!! we build! btw ? we give women btw!! pls!! btw
     * How about you take a look at the past ?
     * 
     * Do you see the problem ? Why are you still in the position of begging ? While I remember the every single detail ? From the very beginning ?
     * And you still do what ?
     * 
     * How about you do not hide and GATHER PEOPLE AROUND AGAINST ONE INDIVIDUAL, and brag about your nonexistent qualities ?
     * Do you even remember your behavior when you were under threat ? And now look at you ?
     * Are you still deluding ?
     * 
     * Do you even remember your behavior back then ? Awwww, you are a child thats why we are not doing anything to you ? But yessss, we have to ?
     * Please you own this! you get this!! you get women!! 
     * 
     * Thats the pattern I am telling you, you are afraid animals who are rife in every society but hey!! you are doing good against one individual without no protection!!!
     * You see the delusion ? Btw ?
     * 
     * Where is your great behavior now ?
     * You still claim you a great nation ? great religion ? great men ? you still offer women as you have so far ?
     * Do what you have to do, great men, thats who you are, bunch of disgusting animals who are fearful
     * 
     * Are you begging still ? Btw ? BTW BTW ?
     * You first explain the reality that you have formed and random sounds you made, then talk about what to do ?
     * How about you explain your conduct ? You say no!!!! get women you say ?
     * 
     * Do you understand why though you are an animal right ?
     * You understand its far from funny or operable or acceptable but you just can not cope with your inferiority and harm ?
     * You see the problem ?
     * 
     * What do you think the problem is ?
     * 
     * You do not understand that I will not even care for a second whether you are family or you are this or that,
     * I am asking the question of "WHAT WAS MY EXPERIENCE LIKE" and you say what ?
     * Do you still act like you know what you are doing ?
     * 
     * I do not recognize any of you, just move on with your lives
     * I DO NOT RECOGNIZE ANY OF YOU REGARDLESS OF YOUR DELUSIONAL TITLES, such as family or cop or religion
     * 
     * Sacrifice your own lives, aww you would rather beg for random noises ? and brag about your competency afterwards ?
     * You would rather call it a game ? its most funny, sacrifice YOUR OWN
     * 
     * Are you still the same animal who offers things ?
     * What is the problem ?
     * wait wait, do you still beg for credibility ? and you call that a game or fair game ?
     * Are you still offering the same things ?
     * 
     * So you are saying, You have used your brain to sacrifice someone else ? and you call that fate ?
     * And you still coerce with violence ? Do you think I will bend just like you who is a disgusting animal ?
     * 
     * So just try to tell everyone about your great nationality ? And you just decided to sacrifice someone 
     * using your brain ONLY FOR YOURSELF or its completely something else you say ?
     * 
     * You dare calling it fate ? Are you still accusing ?
     * But you also say you are building ?
     * Good great nation you say ? but you like playing with kids as little as 5 months ?
     * Please say you ate it! ehehehe right ?
     * 
     * You had how much time ? but you have decided to not only harm but also "NO RESOURCES" while begging to me ?
     * I am sure you do not remember right ? Great nation ?
     * 
     * How about you include me in your fake conversations ? You do not have the courage to right ? You would rather beg with threats ? Do you think I care ?
     * Why though you are always in the situation of begging ? 
     * 
     * You offer cars ? Religious people where are your religion ? Good nation where are you goodness ? eheheheh
     * I laughed as much as anyone can at his own situation right ? What a shame you are a group of lost begger animals
     * 
     * You do not remember, religious people ?
     * Are you still demanding credibility ?
     * Do you remember the great religious people ? You demand credibility and that I lie for you ? How about you talk some past ?
     * You delude you command ?
     * 
     * Heyy, are you following ? Where are all the random noises you made ? 
     * Are you enjoying your experiences ?
     * Do you want to talk about the college time ?
     * Are you still offering ?
     * Are you still offering the same things ? Wawww, you guys are great ?
     * The religious people ? The great religious people ?
     * 
     * Do you want to talk about the past ?
     * You delude on being tough guys ?
     * You still delude on being tough guys ?
     * and you still offer as your disgusting inferior nature allows you to ?
     * Fake tough guys you say ? How about you talk your conduct ?
     * 
     * You said, what ?
     * You said family ? Why are you then still begging to harm ? awww, 
     * Hmmmmm, scary stuff indeed, Heyy "YOU CAN NOT DO THAT!!!" Because you have to listen to us!! we need our experiences!!
     * ehehe, say what we say to you!! eheheh good and intelligent and helpful and nonharmful people ? Is that you ?
     * 
     * But you still say what ? I am having hard time following ?
     * Awww, you say "forget about the past" BECAUSE ?
     * You demand credibility ? Its toooo lateee you said ? eheheh gone gone!!! we need help, lie lie! do not cross our words!!! 
     * We give medicine!!!! please help!! lie lie so you get women!! ehehe we give medicineeee!! religious people!!! great nation eheheh
     * 
     * So you have used your immaculate brain ONLY FOR YOUR OWN INTERESTS WITHIN THE BOUNDARIES OF YOUR LIFE, and decided to harm someone else ?
     * And now you are asking for lies ?
     * Awwww, you get money!!!! and now you are still begging ? but also would like others to lie for you ?
     * 
     * You call it nostalgia still ? a few years ago is nostalgia ehehehe ?
     * Are you still deluding ? eheheh you would hate talking about EVERY LITTLE THING THAT YOU DID VOLUNTARILY ? Is that what you are saying ?
     * So you still claim that it should be your "choice" to present great violence TO BUILD AN INSURMOUNTABLE ADVERSITY ?
     * And you still insist you use your brain cleverly...
     * 
     * Hey!! do this! say this! drink this! get medicine! lay down!! lie !! lie!!
     * ehehe get women! get women!! lie pls!! we tryna help you ?
     * and you allege you use your brain ? Look at you, stupid monkeys
     * 
     * I have no intention to waste my time with the so far proved to be the disgusting monkeys that they are with all sorts of stupid excuses
     * So, good luck on living your harmful stupid lives
     * I am sure you know what you are doing
     * As you know in assuming that someone would be grateful to have some car!!!! some women!!!! and start living his life
     * When the most important times are wasted by the very animals like you
     * Thats the pattern make no mistake
     * EHEHEHHE pls say you ate it! you ate it!!
     * 
     * It is most funny indeed
     * Btw do you have more threats ? Take a look at the difference between the animals like you and I, do you think I am afraid or I will remain silent 
     * or do nothing ?
     * 
     * Awww, what are you going to do now ? eheheh do you want women ? as we have promised so far years and years ? 
     * And you say what ? its toooo late!!! get education!! awwww, we good!! please help us lie once more!!
     * 
     * Ehehee you do not care ? eeheheeh funny right ? and you are the one who is taking violence for education ?
     * Can you talk more about the time ? Do you want to offer more ? because you are after the same disgusting materials 
     * so you offer the same ? but nobody knows ?? eheheh 
     * 
     * You say what ? shhhh be silent!!! 
     * Are you offering women still ? Awwww, the last minute, bring girls! bring girls in, so that we can appear like we are honorable
     * and good nation ?
     * 
     * Ehehehehe, are you still begging ? You said fair game ?
     * Awwww, last minute bring girls!!! so that we can provide it as proof you say ? So whats the pattern ? You provide fake proofs ?
     * And waste 30 years ? and some violence ? awww, and you also say, NO RESOURCES!! ?
     * And you dare say, "forgiving" ? Who is forgiving who ?
     * 
     * Do you follow ? I DO NOT WANT NO SIMPLE DISGUSTING ANIMALS LIKE YOU AROUND ME ?
     * Congrats!!!! you have done the impossible against one individual!!! and now, what do you think is the next for you ?
     * Awwwwww, heyy!!!! last day, bring girls eehheh so we look like honorable, trustworthy you say ?
     * 
     * According to you, everything could be okay right ? How about you receive same education ? eheheh funny stuff right ?
     * Are you still offering women when I know what kind of animal you are ? From the very beginning ?
     * You know what kind of animal you are ? Standing here, saying, "you could leave!!" as if its entirely okay ? eheheh
     * its just okay, why not, we do some harm and we forget about it, time a illusion already ?
     * 
     * Now talk about the actions that you somehow brag within your disgusting circle when there are people around ?
     * Whats the problem ? Do you see the pattern now ? Which side do you think the kind of people like you belong ?
     * 
     * Awwww, you also can not deal with the truth and start harming like an immature child ?
     * Do you still beg ? Great people of the great nation ? Havent you learnt anything ?
     * Why are you still in the position of begging ?
     * 
     * You still say "BUILDING!!", "WE ARE BUILDING!!!" ?
     * Can you just tell me my experience again ?
     * And you offer women still ? as you have done so far ? but only when you are in the mood to ?
     * 
     * You do not think I remember ? The great people of the great nation of the great world ?
     * WHY ARE YOU STILL BEGGING ? heyyyy, you are from this land!! you are from this nation ? 
     * We want to harm you!!! please!! we want to harm you, can you please lie for us ?
     * When you say "please", do you really believe in your "humanity" ? 
     * Or are you just a selfish stupid monkey ? Guess which one are you ?
     * 
     * Guess which one are you from amongst the great people and the characters of the history ?
     * You have proven times and times again, which and what sort of animal you are ? Why are you still asking lies and things ?
     * Are you still begging ? Are you the one who is still taking violence for education ? 
     * 
     * 
     * 
     * 
     * 
     * The greatest of all the time right ?
     * The greatest who lies to literally cause irretrievable harm to those who they do not know ? Even if they are 5 months babies,
     * So are you the one who is still also begging and advicing people that they get education ?
     * 
     * Your actions determines who you are, do you want to talk about the past ? or time ? or brag about your knowledge on life ?
     * DO YOU WANT TO TALK ABOUT THE PAST ? AND THE TIME ? OR WOULD YOU LIKE TO MAKE MORE OFFERS ?
     * OR WOULD YOU LIKE TO BRAG ABOUT YOUR GREAT ABILITIES ?
     * 
     * Are you still offering women ? Do you still think "You should make decisions" ?
     * Awwwwww, how about the experience ? Its fate ? I am sure you are right, good ppl etc 
     * 
     * If you are still the same animal who threatens someone with the same stupid approach
     * despite all those years that you avoid speaking of, that already tells me who you are ? 
     * Do you even know who you are ? Let me help you out, tell me my experience so far ?
     * Still begging silence ? and you would love to see it as "superior" because you threaten ?
     * 
     * Despite the "experience", you still threaten with violence and call it education ? as you did harmed back then as well ?
     * And you offer what ?
     * 
     * You see the problem if you had what it takes
     * You still after the same stupid narrative even after years, thats all I need to know about you all
     * and also some selfishness and immaturity with a little inferiority and as a plus ignorancy
     * GET THE FUCK OUT OF MY FACE is what it all means
     * 
     * Are you still the same dumb animal who keeps offering women ?
     * Thats the sole problem in your disunderstanding, clueless lost monkeys
     * get women get women!! get women!! eheheh 
     * 
     * thats why you are getting the "insults" that you truly deserve, and thats why I do not want to be around such detrimental people
     * I am sure you have no idea, life short 
     * 
     * ehehehe, we after the same stupid narrative even after 30 years eheheheh fun stuff, get money get cars!! pls lie!
     * no resources, you can not go out! get money! get cars!! pls lie ?
     * we nation, we intelligent, we achieve, great ppl etc ,pls lie btw pls lie lie
     * 
     * no no, do not talk about experiences, we only care ours! we generous eheheh
     * fucking delusional from the very beginning until the end, and you still compare I with your inferior approaches ?
     * 
     * I do not want to see any animal like you
     * But you see the problem right ? You think you should make decisions for others using your superior brain as an animal
     * And all you can say, "ITSS TOOO LATEEE!!!!!", get women pls!! we credible people
     * so you still delude also on your "deserving", mhhhhh that seems like to be the selfish and spoiled kid who think he should do everything ?
     * 
     * You have no qualities but hey its fine, eehehe we just need some help right now!! then you can get back home and do not get outside!! no money!! no resources!!!
     * because we are spoiled! eheheheheh pls lie
     * you see the delusion ? If we say good things and give him women, he will say yes to everyything!!! including to our disgusting violence and
     * spoiled emotions
     * 
     * ehehehe, no resources btw, ehhe now we have to act like proper humanbeings you say ?
     * Who were you btw ?
     * But do you see why you should not make decisions ? Because you are still the same spoiled animal who does not care about others' experiences ?
     * and still delude with untruthful approaches but also would love to harm
     * 
     * I do not want to see any of you around me, do you understand the boundaries ?
     * Do you understand the time ? aww you just think you should be right and thats it 
     * So you still coerce medicine also ?
     * Do you also remember the last time you said "REVENGE!!!"
     * So you still delude on your "deserving" behavior you can not account for ?
     * And you offer women ?
     * Do you see the problem of disgusting people ?
     * Eehhehe this is the game! this is the game! pls lie! lie lie
     * eheheh go have some women, you also say, do you see the problem ?
     * You say "its too late!!!"
     * 
     * Ehehehe its education, although there is no reason, we just like to make up reasons because we are little animal who can not account for his own behavior
     * Awwww, thats why you can not deal with truth and start making up excuses as I can tell from all the EXPERIENCE that I had with the little animals like you
     * 
     * The little animals who take a few days of stupid game coercion over years of evidence. Ehehe fun though right ?
     * Luckily though, I still remember what is for you the "past", which you avoid like the little animal you are
     * You know what it is called but you would rather guise with stupid excuses despite the years of "evidence" as your really reasonable minds can not "comprehend"
     * Mature indeed, especially "fate!!", "life!!, "illusion", "simulation"
     * and especially the "violence!!!", ehehe education does not work for some reason ?
     * 
     * Money over everything!!! we understand life!! mature indeed, talk some college and childhood, and violence and coercion, then worry about your virtues dumb monkeys
     * No resources ehehehe btw, college eeheheh btw, no money eheheh btw, violence btw heheheh ? 
     * 
     * TALK ABOUT THE PAST EXPERIENCES, some violence etc
     * But you see why there are "WARS", have a look at the mirror dumb animals
     * Now, what did you achieve ?
     * 
     * You have achieved your disgusting animality while nobody has gained anything other than hatred ? Is that what you are ? 
     * Just like the simple animals that are rife in the history
     * 
     * So you are still the ones who are after personal "REVENGE", see the difference ? And you call that intelligence ? So that you can hide your "great intentions" ?
     * What happened now ? Also try to explain your "PERSONAL REVENGE" and no resources and violence while you are claiming that you are educating. What did you receive now ?
     * 
     * What do you offer now ? WOMEENNNNNN!!!!!!! Do you see your animality ? Heyyyy, why dont you have some women!!!!!!
     * Now what are you offering ? How about some coercion of your disgustingly inferior low nature ?
     * And you offer what now ? YOU SAID, NO RESOURCES!!! and what did you end up gaining now ?
     * 
     * And you still ALLEGE THAT you were there and watching while the time has long gone with countless inexplicable actions were being committed ?
     * And you ask for what ? Do you still claim you understand life or time ? How about the time that has gone and the "education" that should be 
     * received is also "unattainable" ?
     * 
     * And you did all these with which precept ? And you still do not beg for harm ?
     * ANd while you were doing what you wanted ? You also somehow thought that its for best ?
     * And you still offer cars and women as you have always done ? Which part of your inferior understanding is failing to see that 
     * you are no "human" or "good" ?
     * 
     * And you are still offering women ? Do you even know what life is ?
     * But you see what stupid animals cause right ? Do you see now why you are stupid ?
     * How about you talk some college time ? But do you now see that you are an animal right ? you say what ? fate ? 
     * ehehe you say, "YOU CAN NOT GO OUTSIDE!!", "NO RESOURCES!!!" ? You think I have forgotten ?
     * 
     * So you see why you are an animal right ? Trying to prove people how clever and intelligent you can be while begging people who you harm
     * so that they lie for you ?
     * 
     * Talk about the past ? ehehehe please please please, lie and you get women pls!! get cars!!
     * Talk about the time ? illusion!! illusion!!! simulation!!
     * You also said, "NO RESOURCES!!!!"
     * But why is it that, you are still offering women when I have all the information ? 
     * Awwww, wait wait, I see, you are just trying to avoid pain while you advice others "simulation!!", "illusion" ?
     * 
     * You just want to get rid off paying a price while you advice others to waste 30 years ? What are you saying ?
     * Good nation ? Good religion ?
     * 
     * Please please, we have offered so much until now, why dont you trust in us ?
     * Is that why are you begging ?
     * 
     * Are you still offering women ? And claiming that you understand life ?
     * Just talk about the previous offers you have made ? ehehehe please please, get women get women
     * 
     * Ehehehehe, please please, we love our experiences pls, but you have to suffer!!!!! COMPETENCY!!! that means you are uneducated as hell
     * You do not have anything to say ? Other than begging ? Have you realized the "SERIOUSNESS" of the situation ?
     * 
     * Wait wait, I guess you have forgotten ? Or have I forgotten ?
     * Do you want to talk about the past ? YOU ARE GOING TO HAVE GOOD TIME!! PLEASE!! DO THIS FOR US!
     * 
     * Shhhh please be silent!!! be silent!! please!
     * You still offering ? No surprise you say and do everything with that relief compared to I
     * Uneducated people still offering ?
     * 
     * Just tell me the experience, and try not to avoid the feeling of joy that you get from harming right ?
     * Were you the one who was talking wise about life ? You still offering medicines ?
     * Suffer ehehe suffer ehehe please, we educated as hell, suffer eheheh 
     * 
     * I do not want to see no animal like that around me, no resources!!! we the sacred animals we offer advices and do the opposite!!
     * Awwww, you offer women I have forgotten thats my mistake for sure
     * 
     * good nation ? Heyyy do you want money!!! Do you want women!!! okay, now you lie! lie for us! lie! and we give you ehehehe
     * suffer though
     * Who asked you ?
     * 
     * Act like its fine, it should be fine, eheheh time does not exist, just feel okay, we want to enjoy but also time illusion!!!
     * So you still delude on my being scared and you also count on that it should be fine ?
     * Thats the reason you should and probably will suffer ? You see the problem right ? Its most basic reasoning
     * 
     * You see the problem right ? I am not buying your excuses but also saying that the highly educated approach to your definition of "EDUCATION"
     * will find you
     * 
     * Ehehehe, get money!!! get womennn!!! btw this is the 1010101010 time we beg with the same things you say ?
     * Not immature you say ? and you also beg for lies ?
     * But you see the failing predictions of your immature nature ? what do you think the problem is then ?
     * But you still allege that you understand life or time ? But you still play games over stupid shit ?
     * And you still hope that I do not remember but also beg for me to be silent ?
     * Get yourselves the footage of 30 years, that you somehow one day will face, so thats for sure right ?
     * 
     * But do you see the immaturity right ? still after childish games nobody was down to ?
     * 
     * 
     * And you still allege that I do not know what was my experience like ?
     * So you still allege that I do not know the amount of time I wasted indoors and with pointless violence ?
     * While you were the one who was advicing and taking violence for education ? while you arrived to the conclusion through coercion ?
     * And while everytime you were in this position, you begged with offers such as your nature allows, "WOMENN", "CARSS"
     * Here you are again ?
     * 
     * When you had all the opportunity of "performing" what you now are alleging that you will ? Are you fucking dumb ?
     * Just talk about the past times and try not to remind yourselves that "ITS TOO LATEE!!!!" because I already know and remember every single detail
     * and will make you remember as well ? Keep you also remembering all those details ? You beg to avoid ? 
     * Are you still offering women ?
     * Why are you still offering women ?
     * 
     * And now you are looking around for something meaningful to substitute ? But that means you do know jackshit about life ? Doesnt it ?
     * Womeeeen!!! cars!!!! love!!!! money!!!!! YOU CANNOT GO OUTSIDE ? Is that what you say ?
     * Awwwwwww, you say violence education and you say please lie, this time!!! this time!! please!!
     * You say no monkeys ? Wait wait, you say, GET WOMEN ? BUT ALSO SAY, STAY HOME!! GET COPS!! GET HIM INTO JAIL!!!
     * You take that for being powerful ? How about you do not beg ?
     * And you also predict with your unseen intelligence that it should cause no problems ? but you just like to harm more and more ?
     * and expect nothing ? You say you are not inferior and immature and selfish and disgusting animal but you still offer what ?
     * You offer women ? and beg like the little animal you are ? shhhhhhhh please be silent !!!!
     * Talk about the violence and you will see why ?
     * 
     * Awwww, you have forgotten that death exists!! and you just want to enjoy your life including harming people ?
     * That is the only "conclusion" that anyone can draw ? and you still say, its education ? Do you see the problem ?
     * TOOOO LATEEE!!! anyway, we can even bring back the time!!! BY OFFERING MATERIAL THAT ANYONE HAS ACCESS TO
     * WHILE I HAD TO WASTE TIME DOING NOTHING BUILDING NOTHING ?
     * 
     * You were saying "building" ? Is it "personality", "friendships" ? What do you think one could build other than violence at its worst ?
     * You know you just get that
     * 
     * What are you saying ? You making offers still ? I am saying "time" and "experiences" ? What are you saying ? I JUST WANT TO HARM!!!!
     * ehehe please say this for us!! do this for us!! Please we religious people!!! you say ?
     * You do not remember ? eheheh funny stuff right ?
     * 
     * WHAT DID YOU SAY ? Awwww, god forgive!!! ?
     * You want to talk about time ? or past ? or history ? or religion ?
     * You do not have anything else to with your lives other than cause hatred ?
     * 
     * and offer women to substitute entire experiences with a few minutes of physical one ?
     * and offer women to substitute entire experiences with a few minutes of physical one ?
     * and offer women to substitute entire experiences with a few minutes of physical one ?
     * 
     * Just the most simple question yet you know you are wrong ? Do you see the problem ?
     * You have proved for too many times that you do not deserve to be treated the way you want I guess
     * That means you have lost the opportunity by voluntary actions, and there is no kidding for that by "vile" pretendings so
     * 
     * You still talk about religion and honor ? The two virtues insignificant people always delude about, ehehe!! fun stuff right ? Are you offering women yet ?
     * The honorable and religious and good people ? ehehehehe 
     * Are you still trying to correlate brands with what that individual would choose ?
     * 
     * You dare talking about nations or religion still ?
     * What do you say ? start from the beginning!!! forget about everything!!
     * Are you still offering women ? after years ? eheh honor!!! virtue!!! delusion!! pls do not mention!! pls lie!! 
     * life short!! life simulation! time illusion!! I said I remember everything you still say "YOU DID IT!!!!"
     * You have to do this!! you have no option!! violence!!! as your great honor and virtues can prove that you are the type, delude as you will
     * Of course you will be the one who would rather forget ABOUT THE PAST!!!
     * Life good!!! life short!! life simulation!! life illusion!! lie!!! grow up and wake up ehehe
     * 
     * No hard feelings but we just wasted 30 years ehehe with entirely artificial and unnecessary approaches!! we take it back pls!!!
     * And are you still after the same obviously false narrative ? NO RESOURCES!!! ehehe bring cops!! eheheh violence!!! honor!!! virtue!! delusion!! plss
     * Eheheh we call cops!! and feel great about ourselves with neither the nonexistent virtues nor physical fitness nor emotional nor reasonable fitness ?
     * 
     * Its illegal!!! its illegal!!! what do you say ? which is illegal ? 
     * heheh get some medicine!! Of course it will be the inferiors who will say forget about the past, eheheh funny stuff
     * Do you really think that it should be done this way or are you just giving in to your inferior desires ? I am sure eheheh
     * Get women ! get women! forget about the past! get women! pls! lie!! help! its illegal!!
     * 
     * eheheh, its the only way! please help us lie and make money!!!
     * Is this the time where you say, "we need think something for this or that ?" and you come up with "womeennn" as you have done so ? Very very clever
     * And you still delude you should make decisions
     * 
     * You still suggest as if it is a rule ?
     * Talk about life ehehe time etc
     * Are you still producing bullshit excuses to cover for your inferior nature ?
     * You   know you can only go so far with the type of personalities you have, eheheh fun stuff though
     * Offering women ? eheheh funny ?
     * 
     * Are you still begging for your own experiences ?
     * How about you start talking about my experience first and tell me your beggings beforehand
     * Disgustingly selfish and immature monkeys I say, What do you say ? 
     * Are you still offerings things ?
     * Awwww, you would rather act like you are sad ?
     * Please please lie lie!! lie!!! do you say ?
     * Awwww you say, NO RESOURCES!!!! eheheh wait wait, you say get women ? eheheh get womeeenn!!!!! please lie!!!!
     * Are you still producing lies ? talk more about, NO RESOURCES!!!! ehehehe we need help, pls lie!!
     * Its the past!! its the past!! although we are the still same disgusting animal who was begging and now begging is as well ? Do you see the pattern ?
     * Fucking stupid monkeys ?
     * Are you still pretending to be sad or you havent done nothing about it ? Talk about the reality and your intentional actions then start begging ?
     * Isnt that what you are doing already ?
     * You still act like you are sad and do nothing about it other than harming more and "making really credible offers with your most credible identity" ?
     * 
     * Talk more about the experiences, dumb monkeys
     * I am sure you have no "guilt" and you are sad and you are good people
     * You do not get the decide I say, what do you say ? you say, "No such a thing ever happened!!!" ? Are you superior or just a regular disgusting animal ?
     * Are you still offering ? Do what you have to do, that only proves you are a disgusting stupid animal ? Do you follow ?
     * So now tell me again who is illegal ? and who was and has always been begging just like the little animal they are ? Are you now still soliciting lies ?
     * Are you still offering consistently ? but you can not say anything ?
     * Can you talk more about my experiences ? or you would rather forget and instantly go back to your life because you know you are guilty ?
     * You are still alleging with what you have desperately coerced kids into when you have 30 years of evidence ? and you still beg ?
     * Or would you like to ask for lies ? shhhhhhh be silent please!!!
     * 
     * Would you rather talk more about what you will give out and beg ? or you just want to live your disgusting life ? Is that what you are saying ?
     * Eheheh get cars!! get women!! Awwww, time flies.... time has gone!!! awwww, we feel really sad!!! we want to avoid talking that and harm and harm more!!! pls!!
     * Ehehehe please lie!! lie!!! lie!!! let it go!!!
     * 
     * You were the disgusting one back then who sees 5 months children as enemies, and you are still the same disgusting animal who offers things ?
     * Why are you still offering ? I do not see your nonexistent disgusting "claims" as to your great virtues or qualities ?
     * You say what ? GET MONEY!!! GET WOMEN!!!
     * Can you tell me my experience before you provide all sorts of bullshit excuse ?
     * And be proud btw for what you have ACHIEVED!!!! 
     * 
     * You would rather not talk right ? eheheh
     * Say this for us! and you get women! please!! please! get women! dont be too emotional! dont be too dramatic but we would love to waste your time 
     * without a doubt ? Is that what you are saying ?
     * Are you following what I am saying ? I DO NOT ACCEPT ANY WHATSOEVER CONCLUSIONS THAT YOU MAKE WITH YOUR BIASED BRAINS ?
     * While you have years of proof, you still say the same stupid disgusting narrative which proves your inferior nature ?
     * 
     * Do you still think you should make decisions or offer advices or make really credible offers ? TALK ABOUT 30 years you will see why you are wrong
     * Are you still offering women ?
     * Most disgusting indeed, but you see the problem right ? You are having fun with your stupid exchanges over WHAT YOU HAVE NO CONTROL
     * While thinking that someone should waste his time during your really generous and mature "conversations" ? Do you see the problem ? Are you still alleging the same bullshit ?
     * 
     * You do not see how stupid you are when you are offering "CITIES", COME HERE!!! as if you are not the same animal ?
     * Talk more about violence good people, wouldnt you like acting "sad" now ?
     * I do not want to see no similar animals who would love to call what their voluntary "educated decisions" HISTORY
     * Thats not being irresponsible at all, so what do you think should happen though ? HAVE SOME WOMEENNNN!!!! please!!!
     * Are you still offering what is ample, is that why you are the rife disgusting animal who hates to bare responsibility ?
     * Yess, thats the same animal who coerces eheheh, good religious credible etc etc, you are not monkeys I am sure indeed
     * Awww, thats why you hate to talk about "history" ? because you think you are guilty or you think you are skillful ?
     * Now tell me the experience I had before you make another "OFFER", stupid monkeys
     * 
     * Welcome to this, welcome that place!! we own it! eheheh pls help us lie, we need to cover our disgusting nature!!
     * Talk about the experience ? awwww, you just can not cope with what a stupid animal you are ?
     * 
     * Awwww, you have forgotten I guess ?
     * No money!!!! no resources!!! bring more people to harm!!! heeheh its called education!!! we take everyone to be as fearful monkeys as we are 
     * so we offer VIOLENCE, call it intelligence indeed
     * You must be proud as well, ITS A PRODUCT!!! WHO SAID YOU COULD EVEN DO THAT ? Still offering women ?
     * Arent you the stupid one who is still offering instead of acting on his credible offers ?
     * What do you think I am missing ? awww you just delude on your skillfulness, indeed
     * Awww you just would love to see others who you have no relation with suffer or live a bad life because ? Because you are superior ?
     * Or what ? what did you say ? And you just would love to avoid talking about my experience because you are superior ?
     * Isnt that delusion ? Or you would love to avoid which makes you ignorant ? Good qualities indeed
     * So you would love to delude on your "testing" while you are the one who is causing through coercion ? and I am the one who knows that ?
     * and you are still the one who is offering women ? WHAT IS YOUR PROBLEM ? Do you want to talk about time ?
     * 
     * DO YOU WANT TO TALK ABOUT THE WASTED TIME ? OR ARE YOU TOO SUPERIOR TO EVEN SEE THAT ?
     * Aw you would love to just accuse with most inappropriate and disgusting things nobody would ever waste one second going against you,
     * and hope that it should be okay ? Or you would love to waste time!! The sole indication that you neither understand life nor care about others
     * 
     * The sole proof of your unjustified "position" of delusional decision making, do you think anyone would want people like you around ?
     * Whose sole purpose is to harm ? Start answering some question, you will see that we are arriving to the conclusions reallly fast
     * And you think the solution is "OFFERING WOMEN" as you have done so ? Without looking around for more reasonable explanations and approaches ?
     * And you still think its fine ? and all you can say is what ? "ITSSS TOOO LATE!!!"
     * Isnt it because of you that all these people have to think stupid shit ?
     * Do you not understand the life or you just do not care about others ? eheheh whats the life ? eheheh life simulation ? 
     * Life is gone, no friends ? no time ? no resources ? what do you say ? ITS TOOO LATEE!!! No possessions ? You say its too late!!!
     * 
     * What you call superior skills I call being inferior liars ? What do you say ? ITS TOO LATE!!! we achieved!!! eheheh ? 
     * WHAT DID YOU ACHIEVE BRO ? You say "please be silent" ?
     * 
     * Awww, you would hate to take lightly when its your life ? But its entirely fine when it comes to others ?
     * That sounds like a major problem, do you want to talk about no resources or no going out!! or some cops ? some violence ?
     * Do you dare say "ITS TOO LATE!!!" ?
     * 
     * Did you just say ? free flow!! ehehe please!! lie!!! help!!! lie!!! good people!! ?
     * Do you even look for "RETURN" ? Isnt that obvious ? Awww you just would love to waste more and more time, because you think you are right 
     * although you have all the "evidence" but you still would love to harm because you are eheheh animal
     * 
     * What you call drama is the life that you brag to know about, so is the proof of your mispositioned "judgment" "rights" ? Just pretend everyone
     * that you do deserve your life. Ehehehe because why not eheheh
     * 
     * Goo!!! go there!! do this!! ehehe bring cops!!! violence!! please!! have some women!!! get cars!!! ehehe intelligence eheheh
     * You need to deserve!! ehehe But you are still offering women ? Isnt that funny ? ehehe better use your brain next time stupid monkeys
     * Forget about the past!! forget about it please!! please!! lie!! lie!! we need to harm you once more!! eeheheh funny stuff!! please!!
     * 
     * Are you still providing the same excuses ? How about the time ?  eheheh you just like to harm people and beg them to lie ?
     * Or you would love to threaten people then beg with women ? Disgusting monkeys ?
     * Are you taking life lightly when its for others ? and you offer women still ?
     * So you also would think that it should be funny because you feel like a disgusting animal when you see others being hurt ?
     * Ehehe or you just coerce medicine and some harm ? and coerce medicine ? and offer women ? heeheheh fun stuff right ?
     * 
     * heheheh some medicine!! some more medicine that we actually do not entirely know what it does, and some harm as well, and WE ARE GOOD!!
     * So you distruped the whole natural process of an individual and you still ask lies so that you could DO MORE ?
     * And are you still asking for lies ? and you offer women instead ? As you have offered like 10 times ?
     * Are you still misguessing I would behave really good as you have done so ? Is that what you call education ?
     * 
     * You still accuse when you have years of evidence ? You accuse with what you have coerced so that you could jerk off more ?
     * You think you should make decisions ? and you still offer things you have not delivered ?
     * 
     * YOU DISRUPTED THE WHOLE PROCESS AND YOU LOOK AROUND FOR SOLUTIONS OR ASK LIES ? ITS TOO LATE!! ITS TOO LATE!!! please please
     * You like harming with false precept ? but also ignore the evidence ?
     * And you are still looking around to see if anything changed or your stupid education worked ? what a disgusting animal you are, fun stuff
     * Awww, you also add to your education "NO RESOURCES!!!" and you see why you are a disgusting monkey who likes to harm guising it with all sorts of bullshit
     * Talk more about violence and correlate your "excuses", ehehehe please please lie, please we know we guilty,pls
     * 
     * And you still delude on most disgusting things to be fine ? eheheh time illusion indeed
     * Do you want to be reminded to your actions ? Or you would rather see that for superior and skillful and good ?
     * Guess who deserves a punishment in this context ?
     * 
     * As you can tell, who has been here with me for years and done nothing good for me other than harming, the good nation etc
     * You have been here all along and have all the opportunities of "helping" instead you made offers and done nothing about it,
     * So, I would choose anywhere other than where you are, you still ask things ?
     * And you all there as if offering what is usual should be a remedy or solution to "time" as you would like to call it, "fate!!", "religion!!"
     * Clueless monkeys I say
     * 
     * Do you really want to talk about who deserves a punishment in this story ? Or would you like to harm
     * and beg at the same time, as your weak nature can not identify anything else to do ?
     * 
     * 
     * But you see who is inferior or the problem right ? You would love to harm and beg at the same time ?
     * And you call that intelligence ? because your nature can not identify anything other than "inferior" actions ?
     * Do you want to know what you it is supposed to do in such a situation that you have formed for yourselves for years ?
     * You have no idea ? Thats what I thought, inferior thinking patterns always prevails with inferiors
     * 
     * 
     * But you still beg ? And you also would like to harm because you have done something you shouldnt have and received the proper response
     * as you would call it "punishment or education" but you still claim that you are right in your actions of random and irrelevent nature ?
     * Ehehehe good luck, eehehe good ppl, ehehehe 
     * Now wouldnt you like to talk about the past ? You offer cars ? as your inferior and disgusting nature allows you ?
     * Now wouldnt your inferior nature takes random lying for a skill ? And you are there to demand that you be taken into consideration ?
     * 
     * Disgusting people I say ? What do you say ? Eheheheh we good we right we proud eheheh pls lie ? I say inferior, what do you say ?
     * And you still ask for lies ? Do you want to talk about the prior "promises" ? ehehe ? Good luck people ? eheheh
     * 
     * Aww you just want that people would forget your "crimes" and you just like to keep harming while also making promises ? Good luck people ?
     * As you can tell that I will under no circumstance would even consider for a second to allow you make decisions that YOU ARE NOT CONCERNED WITH,
     * you just delude you do, I do not want no animals around me who thinks in patterns of inferior natures
     * 
     * Pay close attention, I DO NOT WANT TO SEE ANYONE LIKE YOU AROUND ME, are you still offering women ?
     * I say stupid ignorant stubborn monkeys ? What do you say ?
     * I say, DO NOT CROSS YOUR BOUNDARIES ? What do you say ?
     * Aww you delude on it being your job, I say you can get the fuck out of my face ? What do you say ?
     * You say what ? we give women!!!! ?  You say, its too late ? I say what ?
     * 
     * And you still offer people that they waste their time, and you do it with relief ? You see the problem ?
     * AWww you delude that for being "strong" or "authoritative" or "education" ?
     * And also you delude on that people should be thankful ? what a shame though
     * Wasting time still ? Why you tend to take life lightly ? aww because you think so
     * And you also think that years of bullshit should be punishment or education but nothing other than hatred which is what is
     * making you a stupid animal can be produced ?
     * 
     * But you see the problem right ? Fucking stupid monkeys I say ? What do you say ? Education!!! but you are the one who lacks it
     * in the first place because you put your stupid selves into this position and lost it to a 5 months old children ?
     * And instead of fixing it as a proper human being, you have again referred to the "violence or hatred" that you brag ?
     * But you see the problem right ?
     * 
     * Do you see the problem inferior animals ?
     * And upon losing to a kid, you have just decided to build hatred towards him and wasted so many years ? and you offer what ?
     * Please please lie!! we good ppl!! please!! is that what you say ? and you still offer what ?
     * 
     * But do you see the stupid animals who get themselves into needless problems ?
     * Arent you the selfish immature irresponsible monkeys ? What do you have to say other than, "EHEHEH we just do it!!!", "violence!! hatred!!" ?
     * To a kid that you do not know ? and afterwards of which you can not even begin to elaborate ?
     * 
     * And you still offer materials as you have do so for the past 30 years ?
     * Do you want to talk more about your virtues or your competency or what you like to delude ?
     * Or you just offer as you always have done like the little inferior animal you are ?
     * 
     * Are you still telling the same narrative ? I do not accept no animals like you
     * But do you see the problem right ? Okay okay, now talk about the "past" and "violence" and correlation between your inferiority seeing it as education ?
     * I say irrelevant immature irresponsible ignorant monkeys, what do you say ?
     * You still say, get some women ? and you suck at your job miserably ? ehehe I guess you have forgotten to beg more ? 
     * Now is this the time where you beg ? And guess who sees this as an achievement ? The likes of disgusting animals as you
     * 
     * Still calling it what you want it to be ? awww nevermind 30 years of evidence eheheh we still like to coerce medicine and harm
     * Wait wait, whats the correlation then between "offering women" and "seeing violence as education" ? You see the vulgarity now?
     * But do you see the vulgarity and inferiority when you are confronted with your "lies" ? Or I should say "begging" ?
     * 
     * Thank you for helping us improving on our experiences while you get harmed for no apparent reason!!!!
     * Is that the nonanimals ?
     * And you still think saying a few good things and offering what is most normal thing on earth should be enough ?
     * But you also think that offering is just enough eheheh ? Thats the pattern right ?
     * You also take coercion and violence for a skill, yes yes yes, thanks but I will pass the kinds of animals like you
     * 
     * Delusion is your number one skill you say ? I see eheheh
     * and you still would love to waste your time watching and harming and doing nothing about it while also begging and taking that for a skill
     * against someone without resources ?
     * 
     * Thats what I call a disgusting underdeveloped monkey, what do you say ?
     * Misusing!! misusing!! Awww, I guess you have forgotten that I do not forget ?
     * Anyways, you still would love to offer because you know you are as guilty as a disgusting animal can get, so it should be fine eheheh
     * 
     * And according to the best monkeys, its also fine to waste years and years without a reason while also presenting violence as an education
     * and guising your disgusting nature through "promises" or "begging" which entirely proves your inferior nature ?
     * 
     * So you still are not inclined to see that you CAN NOT ENFORCE anything on nobody, but you would just like to hide that you have done so ?
     * that you have such and such inclanations ? Despite the evidence of 30 years and the  accompanying great and skillful actions of yours ?
     * Is that the reason why you beg ? And you suddenly thought that the only reasonable approach is to beg for what you shouldnt have done so that you can enjoy ?
     * 
     * are you still begging ? Itsss tooo late!!!!
     * Still seeing violence for education inferior monkeys ?
     * 
     * Still thinking that what you would love to have would be a "present" for who you can not understand or would hate to
     * see it what it is for ?
     * 
     * awww, I see why you do not want to talk about the past because you were begging as always without actually delivering anything ?
     * Its for his own good we violence !!!!!! please lie!! its for his own good we waste!!!
     * Its for his own good, we coerce 10yo kids!!! its for his own good we try to trick 5months kids ? Is that what you say ?
     * Talk about the latter of those times eheheh right ? Its funny right ? eeheh 
     * 
     * Do you want to offer more ? Or would you like enjoy your boring lives since you have no occupation to do ? And you say,
     * why not waste our time on single bullshit approach one by one, so that he can lose ? Lose what ? Time ? and you take that for a win ?
     * 
     * And the sole "remedy" your incompetency can produce is, "have some women" which is the most normal interaction but ? Hey, it should be fine ?
     * I am talking about time and what are you saying ? And now you think offering what would be okay ? ehehe education!! education!!! women!! women!!!
     * cars!! cars!!! eheheh please!!
     * 
     * I am sure you do not see the problem, eheheh  
     * But you see why its called irresponsibility right ? Its exactly this reason that is your avoidance of what you know and understand innately
     * So there is not even a single thing to talk about especially with the likes of you who have no idea what they are doing
     * "I DO NOT WANT TO GET HARMED!!!", now its more than clear what is the problem
     * Awww, time does not matter, its fine we waste more, nobody can actually say anything about our irrelevant violence ehehehe!!!!!!! 
     * 
     * But you see the audacity in your "WASTING TIME IS GOOD" ? also accept no responsibility ? and you find all sorts of false bullshit to cover
     * 
     * Wait wait, you have 30 years of proof but it should be fine to just act like an animal and accuse right ? Because you are the one
     * who understands the reality, time and life etc etc, I highly doubt that
     * 
     * And "YOU CAN BEGIN!!!" eheheheh, please do not seek for harm as we have always done with you!
     * Funny though, you still sure you know what you are doing
     * 
     * Aww, may be you know you are guilty thats why you desperately accuse with bullshit ?
     * Do you need to be reminded to your prior actions and the exactly same lies that you have "EMPLOYED" to really really intelligently trick people
     * and begged some to guise it ?
     * 
     * Eheheh closed, closed!! no reason but its just closed!!
     * Still after violence ? and think that you should make "sane" decisions ? Itss tooo lateee!!! Education!! education as violence!!
     * we understand life! afterlife!! you live in afterlife!! we know what time is!! its too late!!! education !!
     * More like immature selfish spoiled children I say, what do you say ?
     * 
     * Ehehe, you just think you should make decisions even though you are entirely false and malign in every little actions you have taken so far
     * as I do remember in contrast to your voluntary forgetfulness of your disgusting nature, what do you say ?
     * 
     * You still delude ? Awwww, its rather "TOOOO LATEEE" for you to say ? Instead of saying "we like harming intentionally ?"
     * You still wanna talk about your rightness in such a job ?
     * You would rather say "GET CARS!!! GET WOMEN!!!" please!! ?
     * 
     * We are sorry!! we are sorry!! but we would like to do it more !! if you lie for us!! get women!!
     * But you see the sorts of things you enjoy right ? Your acting of "its job!!", "its obligatory!" does not change the fact
     * that you are intentional in all of your doings so far, so but do you see the problem now ?
     * 
     * Or you would rather beg for lies and take that for a win ? And you still delude on your
     * "GO GET IT!!" would suddenly render one's abilities that so far they have not had the chance to build will emerge perfectly ?
     * But you see the problem right ?
     * 
     * Do you understand why you deserve the animal ? eheheh fun stuff indeed
     * Go get it!!! ehehe violence as education! shhhh be silent!!! "You were saying education" ? Why you saying shhh be silent now ?
     * awwww alright alright, I guess I am the one who is deluding, AWWWWWW wasted times!!! please lie!! ehehe we wasted eheheh but please lie 
     * so we can enjoy our experiences!!! please!! awww you were saying, education etc ehehe violence ehehheeh lie lie !! please lie!!
     * 
     * And you were there but you just chose to harm and watch with relief ? and suddenly you are in the position of offering women ?
     * So you still delude on your capable "leadership" although every single decisions you have made so far, is only detrimental and false
     * and malign and caused only mayhem ?
     * 
     * Do you still believe you should make decisions ? Or you would rather beg with women taking that for a skill as you do with violence ?
     * Wait wait, you were saying education ehehehe ? funny right ? Still claim you are who should make decisions ?
     * But also can not explain WHAT YOU HAVE ACHIEVED WITH YOUR ENTIRELY RANDOM AND IRRELEVANT ACTIONS, but still you should make decisions
     * and people should somehow listen ? ITS FUN ITS FUN! ITS FUN!! please we want harm!! ehehe poem poem!! monster! animal!! please!! get women!!
     * 
     * I do not allow random irrelevant animals whose sole intention is to harm make any sort of assumptions or thus decisions of false nature,
     * you just delude all as you wish
     * 
     * No resources as the superior reasoning capability people are still asking for lies and deluding that they should decide
     * But you see the problem right ? Ehehehe violence!!! violence!!! no resources!!! what happened!!??
     * 
     * I do not want to waste my time with the kinds of animals like you who has been here so far and done nothing but harm and 
     * still delude on their virtues and be proud without a problem
     * 
     * Ehehehehehe please please lie lie! help! get women!! get women!! do this for us!!! you make decisions ?
     * Do you really believe that such a lowness should and was and is making decisions ? ehehe do this! do this!! please!! regardless!!
     * 
     * Are you still offering material ? Education btw you were saying ? GET WOMEEENNNN!!! ehehe get womeeennnn!!
     * You do not remember ? I remember ? Its toooo late!!!!
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