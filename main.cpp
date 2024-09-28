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