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
     * You just need yourselves more kids to shout and torture then beg them to lie for you, what a great group of animals!!!  eheheh leave here!!!
     * Awww I see, you just feel reallly reallly powerful when you behave in this way ? ehehehehhehe reallly funny stuff
     * 
     * Get yourselves more children eheheh, I have got 30 years of evidence,
     * The same simple animals who take "fooling children" for a skill and brag about others as though they have achieved something
     * And beg like the disgusting animal they are afterwards
     * 
     * What do you think the price is ? You still dare saying "WOMEENNNNNN" because you also lack understanding in that part ?
     * You lack all the crucial understandings but you are still there demanding to be taken serious ?
     * 
     * I call you simple disgusting animals ? Because what you have done with what is NOT GIVEN TO YOU ?
     * That simply explains all you need to know about your disgusting animality 
     * 
     * I call that sheer fear of what they do not understand which makes you the very underdeveloped homo sapiens as they existed in 100000 years ago
     * Do you follow THE GENIUS PEOPLE ? THE GENIUSES who are afraid of things and run away from them like the disgusting animal they are
     * 
     * Eheheh harm more THE GENIUS PEOPLE
     * THE GENIUS PEOPLE THAT HAS ACHIEVED NOTHING but still love to allege, allege against 30 years of evidence
     * Get yourselves more children, you deserve that!!! Beg more to harm others
     * 
     * Now its the time you look back and tell everyone what you achieved with your disgusting ignorance
     * Tell others how you dealt with children, thats one of the qualities of THE GENIUSES
     * 
     * I am sure you are also a genius who understands "RESPONSIBILITIES" and "ACCOUNTABILITY"
     * What a disgusting group I say, you say what ? "ILLEGAL!!!!" eheheheh 30 years eheheheheh
     * 
     * And you also delude on your "reallly precious self" that even I would consider wasting my time with you ?
     * Because you have something valuable ? What a disgusting animal I say
     * 
     * You say what ? ITS TOOO LATEEE!!!! eheheheh you are still you, THE GENIUS PEOPLE
     * THE GENIUS PEOPLE hiding what they have perpetrated!!!! hide more!!! harm more!!! lie more!! solicit and beg more!!!
     * 
     * All the qualities of really nice and good and etc "human beings"
     * Eheheh I would love to waste my time as I have done so with all of you, all of you who does not have what it takes to understand
     * Genius indeed
     * 
     * Is this what you call success ? Offering women over years and violence ? The genius ?
     * Or are you just a bunch of crying babies who like to deal with children and takes fooling them for a skill ?
     * What do you think that makes you ?
     * 
     * You made it into a decades problem that will bubble up in every possible chance, even when you are gone people will know about this 
     * and you will appear like the disgusting animal that you are, even after the "forget about the past" words you say
     * 
     * You are legitimately a licensed stupid monkey that aims for pure harm and everyone can see that even the people around you who begs for their life
     * through accepting "you are right!!!!"
     * 
     * 
     * The sole evidence to your disgusting unfair animality, the evidence of 30 years proves both of us what we are
     * The genius nation you say ? eheheh education you say ?
     * 
     * Eheheh the sole indication of what you are and what I am, you do not have to look further
     * Look elsewhere to not see what you have done!!! eheheh education btw
     * 
     * I do not want to see any disgusting animals like you around me, do what you have to do, think more about your past, not mine
     * 
     * ITS YOUR PAST THAT YOU ARE ASHAMED OF THEREFORE DO HARM TO HIDE BEHIND YOUR DISGUSTING ANIMALITY. You see the problem ?
     * I am not even slightest afraid so you still get the same output because ITS YOUR WRONG
     * 
     * Taking being the cheapest form of animal for a skill, ITS YOUR PAST AND YOUR WRONG, I do not care
     * THE GREAT ENGINEERING!!!! eheheheh please please please
     * 
     * Leading by great mistake!! ehehhe great etc great and great ehehehhe make sure I would love to be around you all
     * Proud people btw
     * You have gambled and gambled with what you do not have and look at where you are ? You are in the deepest shit that nobody wants to be ?
     * But you still shout and try to intimidate people who you CAN NOT ? Proud BTW ?
     * 
     * Proud to harm children and defenseless people ? ehehehehe past its past!!! please!!! Like the inferiors
     * Who still offers materials over time, what a genius understanding of the world
     * 
     * Are you still after disrupting the peace ? The proud genius nation ?
     * Still offering materials over lost time ? The genius nation ?
     * 
     * Are you still offering what you would like ? The violence over violence ? The genius ?
     * 
     * Do you want to talk about your reasons ? I remember ? even the most unrelated things you asked from a kid ?
     * 
     * Talking about changing locations ? you say you genius ? you do not understand that you are the one who needs to change his mind ?
     * eheheh ITSSS TOOOO LATEEEEEE!!!!!!!!!! 30 years!!!! eheheheh life!!! life!!! fate!!!
     * Like the immature kid that you are, still deluding on your nonexistent qualities ?
     * 
     * You are proud of being unreasonable and you still call yourselves genius ?
     * The same geniuses who can not see that I DO NOT BEG NOR BOW, who does need the education ?
     * 
     * Proud yet can not talk openly about their actions, genius but can not act like one ? where is the problem ?
     * Genius but can not see that they are avoiding what THEY HAVE PERPETRATED because it awakens you from your delusions ?
     * 
     * That is the reason I will not consider any of you around me and, I and other would love to see such people pay a price
     * Who does not even comprehend that women and violence does not correlate, TIME AND WOMEN DOES NOT CORRELATE!
     * VIOLENCE AND TIME DOES NOT CORRELATE, DELUSIONS AND REALITY DOES NOT CORRELATE
     * 
     * Look at your delusions and what they have achieved, only some proud nothing else, get yourselves some children proud geniuses
     * Still offer women over time ? Offering materials over violence ? Proud geniuses!!
     * Tricking with women you say genius ? Cheap monkeys ?
     * 
     * Whatever you have acquired is not legal, thats all
     * Is this your genius move with what IS NOT GIVEN TO YOU ? eheheheheh
     * Fucking disgusting still homo sapiens that I will not consider for a second to waste my time with ?
     * I do not care whether you think yourselves for a genius or you own the world
     * 
     * What are you waiting for ? The geniuses ? Do you recognize yourselves as ?
     * Guess what happens if you fail ? you also fail on your other delusions, I am sure you are proudly living
     * 
     * You are also proudly dealing with a single individual ehehehehehhe, thats really scary stuff
     * Get more people around, ehehehhe gather 10000 you are probably going to need with your stupid attitude, aww I was going to say genius
     * Still attributing your own failure to other children ? Delusion ? Who is what ?
     * 
     * Cheap violence not working and the genius people are wondering why ? The genius people who are afraid of violence and
     * trying to solve nonexistent problems with it ? More like a inferior homo sapiens who thinks everyone for themselves 
     * 
     * You expose your nature through your actions geniusly delusional people, the nature that is the precise reflection of cheap animals
     * acting on their disgusting violent emotions over others and continue hiding 
     * 
     * Still on the sapiens phase ? Do you see the problem ? I am sure you see no problems
     * The great minds of genius people who have brought everything into this state and they have no options
     * to continue being the disgusting animal they are 
     * 
     * Do you understand that the life is not given to you ? The genius understanding of boundaries you say ?
     * Still trying to produce bullshit for your irrelevant "decisions", THE LIFE THAT IS NOT GIVEN TO YOU ?
     * 
     * What did you choose to do ? Are you still offering women over time ?
     * 
     * Why are you still waiting for what you have done so far ? The genius nation ?
     * Are you still offering what you would love ? "The violence" ? Committ crimes!!!
     * Are you after people who can not defend themselves against 10000 people with tools ?
     * You were saying genius ?
     * 
     * You are still after the narrative that "ITS A STORYY, ITS A GAME, LIFE SIMULATION ?" 
     * The life THAT IS NOT GIVEN TO YOU ?
     * 
     * Talk more about your promises you made to 5 months children and request them to remain calm while
     * the time you wasted CAN NOT BE RECOVERED 
     * 
     * Tough and genius guys, you sure you are not only aiming to that but actually failing ? How about you watch and learn ?
     * How about you learn how to listen ?
     * How about you start accounting for your own behavior then we talk about how to solve the rest ?
     * How about you realize you do not make that decision and pay for your own actions ?
     * How about you talk about your credibility before you ask things from someone who you harm intentionally ?
     * Listen how to learn then learn how to listen ?
     * 
     * How about you stop advicing people about what happens after death and instead FOLLOW YOUR OWN ADVICES ?
     * Get educated with the same disgusting approach as I do ? awwww you are too special for that fucking monkeys
     * Are you still offering material ? What a special disgusting sapien
     * Start using your own approach for your precious lifes the genius people
     * 
     * What are you waiting for ? Eheheheheh please please ?
     * You are offering the most absolute disgusting life style ? and looking around for guilty ?
     * It is not your decisions where I go, I do not accept any disgusting animals so far with me
     * 
     * Deluding on still ? I said I do not want to waste my time with you ?
     * Still offering materials over disgusting time ?
     * You do not have what it takes to explain your irrelevant actions but only excuses of inferior nature ?
     * Only offers that you do not deliver or take for something they are not ?
     * 
     * Why are you still the same animal ?
     * Still wasting time while you are free doing whatever you want ?
     * And you still dare to think anyone would be okay to hang with you ? Within your country ? How come ?
     * Disgusting monkeys that I will not under any circumstance accept to work together
     * How come do you think I would accept to work together with a group that only offers women ?
     * Whats the problem do you think, incapable people ?
     * 
     * So you still believe, "hiding" is equal to disgusting life style ? eheheh offer more you do not deliver already ?
     * Still offering education ? Still promising good education to 5months old babies ?
     * Still offering material yet you never deliver ? Eheheheh it does not matter anymore!!! the moment you needed money was the college!!! eheheheh
     * genius people!!!
     * 
     * You have been here all along and the great life I have had is the sole evidence to your disgusting animality
     * Have whatever you think you have valuable into your asses, I am not interested in anything you could offer
     * 
     * You still believe in your "teachings" ? How come you are so blind ? You taught a lesson to whom ? ehehehe
     * And you still withholding material because you think so ? eheheh do not do anything!!! ehehehhe life life life!!
     * 
     * I AM NOT INTERESTED IN YOUR STUPID EXCUSES, wake up
     * Awwwwww, such an unimportant mistake, a mistake that was not even your decision in the first place! the life THAT IS NOT GIVEN TO YOU, and what have you done with it ?
     * The 30 years of bullshit conduct and your sole response is WHAT ? Do you say what ? ehehehe life ?
     * A DECISION THAT IS NOT YOURS AND YOU SAY WHAT ?
     * 
     * A decision that was not given to you in the first place and your excuse is what ?
     * Still after your disgusting emotions ? are you having fun satisfying your disgusting animality ? 
     * And you still delude on my desire to be around any of you ?
     * 
     * How about you start answering some proper question and we see who is what ?
     * Still wasting my time ?
     * 
     * Disgusting monkeys ? What are you waiting for ?
     * Who is burden to who ? Are you still offering good education ?
     * Are you the disgusting animals still daring to offer things ? Start paying for your own actions and the decisions THAT WERE NOT YOURS 
     * How do you compensate disgusting time ? awwww you say women ? Awww you also say good education ?
     * Eheheheh you still making promises ? The genius disgusting people ?
     * Still trying your best to portray children as disgusting ?
     * 
     * Still after "saying good things temporarily and making reallly reallly good offers that you do not deliver" ?
     * Eheheheh you call that intelligence ? I call that being a disgusting monkey 
     * 
     * And you have done what ? ITS NOT EVEN YOUR DECISION YET you have "chosen" to do what ? Awwwwww, you are supposed to be able to say that ?
     * I am telling you the great noble and good intentioned people ?
     * Still after harming people you have no relation with ? No reason with ?
     * 
     * Where are the great credible promises of great people ? eheheh this is the disgusting part where you take in
     * 
     * I AM NOT INTERESTED IN WASTING MY TIME WITH DELUSION STUPID MONKEYS, DO WHAT YOU HAVE TO DO
     * Do you want to talk about not having resources ? eheheheh ? Thats the precise reason I wont accept any of you around me
     * Stupid monkeys
     * 
     * Are you saying forgive me ? apologies ? making offers ? compensating time with what ?
     * are you still offering good education ? ARE YOU STILL OFFERING ? With the disgusting existence of your mind ?
     * Like you offered to children so that they do stupid stuff for your interests ?
     * 
     * Are you still making decisions ? The great genius people ? Are you still talking about "afterlife" ? "Education" ?
     * Where is yours ? ITS NOT YOUR FUCKING DECISION
     * You do not understand the "life" ? That you brag so much about knowing it ? DO YOU THINK I SHOULD CARE ABOUT MONEY WHEN YOU THE DISGUSTING ANIMALS ARE
     * AROUND ME ? HARMING WITHOUT A DIRECTION ?
     * 
     * Have you ruined enough things or are you still content with your disgusting minds ?
     * Why are you still waiting disgusting people who hides behind stupid excuses ?
     * 
     * Have you ruined enough while enjoying your own precious experiences ? Where are the excuses ?
     * Awww you just want to enjoy your experiences without any interruption ?
     * Still deluding ? STILL DELUDING AND ASKING THINGS FROM PEOPLE ?
     * 
     * Why are you waiting for ? LETS FUCKING GO ? what is so difficult ?
     * I have no intention to waste my time even further with the monkeys that harm for the sake of harming
     * 
     * Play games that you do not suck and ruin others' lives such as "ITS NOT YOUR FUCKING DECISION and I do not care whether you are upset
     * because of your own natural stupidity" There is nothing I could do to change your stupidity
     * Grow up and get the fuck out of my face, do your own thing and ruin your OWN LIFE, its not your decisions, Do you even follow ?
     * 
     * PAY FOR YOUR OWN ACTIONS THAT YOU COMMIT TO HARM, AND START RUINING YOUR OWN LIFE, fucking stupid monkeys that I will not welcome
     * around me for a second
     * 
     * What are you waiting for ? Is this how you deal with your incompetency ?
     * Are you still wasting time with unrelated bullshit excuses of your disgusting minds ?
     * 
     * Go jerk off to years of footage that you can use for evidence and ask yourselves all sorts of questions
     * GET MORE CHILDREN YOU CAN FOOL, the rightfully deserving disgusting animals, are you still offering women ? The genius people you say ?
     * 
     * You got 30 years of evidence and you are still jerking off to harming people you have no relation ? Thats the definition of genius
     * Fucking monkeys
     * 
     * Do you still delude on my desire to even waste one second listening to you ?
     * Are you still making the same offers as you have done in the past ? WHERE ARE THE PROOFS ? eheheheh geniuses!!!
     * 
     * I do not want to see any of you around me, whether you think you are saving the world or you fucking own the world
     * I HAVE THE ZERO CARE FOR ANY OF YOUR INTENTIONS
     * 
     * STILL MAKING DECISIONS THAT ARE NOT YOURS ? I DO NOT WANT TO SEE ANY OF YOU AROUND ME ? DO YOU FOLLOW ?
     * What are you waiting for ?
     * Awwww, your disgusting boring desperate life is out of fun ? so you say why not ruin others ?
     * WASTE YOUR OWN TIME
     * 
     * Still ignoring the truth because you want to make "some gains" ? You got evidence but you would rather GAIN THINGS from others 
     * you intentionally harm and you talk about genius ?
     * 
     * I do not want to see no average sapiens around me, get yourselves more children eheheh fun and genius stuff
     * As though you are the authority to make such decisions!!!
     * You all are just a group of kids who can not deal with losing ? and still soliciting things from someone you harm like an average sapien
     * Consider that for a win, like the average sapien you are
     * 
     * Make sure everyone is as afraid as you from the disgusting unfair violence then start living your life with the most grace you can
     * possibly attain, fucking dumb monkeys
     * 
     * You all first explain your actions to impartial multitudes and you get the fuck out of my face with your unreasonable behavior
     * You account for your "prior beggings to children" then gathering 1000 people to harm him at the same time, then you see why you are inferior sapien
     * 
     * You are an uncredible disgusting street animal nobody can count on ? And you asking me things ?
     * Grow up and find your match in the sewers or how about you understand the life then play accordingly ?
     * Or you just stop lying to yourselves and you will have no problems ?
     * 
     * Coping with reality ? Get yourselves more children the genius nation
     * Account your behavior to others who can uphold your disgusting nature to some sort of measure 
     * instead of begging to children or gathering 10000 people to harm one person
     * 
     * eheheh foing with children!!! begging to children so we can harm later on !!!
     * Delusional disgusting nation, genius btw, still offering women ?
     * 
     * Are you still talking about how fair your nation is ? How genius your nation ? How hardworking ?
     * How good ? ehehehhe ?
     * Still talking about justice ? How about you accept that you are the least of your nation ? The disgusting group of your nation ?
     * 
     * Foing with children ? He touched me!!! eheheh he ate it!!! please !!! do it we give you women!!! The best life style ever ? The genius people ?
     * You are making promises so that you do nothing with people ? Entirely waste their time and be glad about your win ?
     * 
     * So you take making children look mad for a skill ? And somehow start begging at the same time ? Ehehehe he ate it!!!! ehehhehe please please!!
     * Start accounting for your own actions, as you call them "genius promises" then we are done 
     * 
     * Find someone else you can beg, ehehe find some children you can scam then notice that you are a disgusting animal and say why not more be like one ?
     * Still offering women ? I DO NOT WANT TO SEE ANY OF YOU AROUND ME
     * 
     * The genius nation who can not even deal with children without begging 
     * Do you want to talk more about what you have achieved with 5 months old baby given to you ? You promise good education ? eheheh ?
     * 
     * AWww you just need to stimulate your disgusting under developed sapiens emotions ? You say genius
     * The genius nation ehehehe, on such a high level that they can not even distinguish what is a human and harm people from their childhood and brag about it,
     * that is indeed genius, fucking monkeys
     *  
     * Still considering to make promises ? Awwwww, how are you going to fix your position on this ?
     * Get some womeeenn!!!! please!!!
     * 
     * Do you understand why I do not want inferior natured people around me ? Look what you have achieved,
     * nothing you can talk openly, that is what I call an achievement indeed
     * 
     * YOU HAVE ACHIEVED NOTHING FOR THE PAST 30 YEARS FOR WHAT YOU HAVE BEGGED, thats what I call an achievement
     * You are just content like the inferior natured animal you are that you have attained some form of damage even to the children or adults
     * Thats why we can not compare
     * 
     * Still deluding on your qualities ? Thats what I hate be around and as you have seen, I will choose not to be around such
     * Delude on it being your decision, I neither want to hear anything from such animals nor do I want to communicate
     * 
     * Still begging through disgusting life style while also promising "material" ?
     * Still listening like a stupid monkey ?
     * Still taking "making random sounds" for a skill ? How about you explain your disgusting nature ?
     * 
     * Enjoying your disgusting emotions well ?
     * Fuck your country ? Do you think I care about some obscure quality ?
     * Proud people you say ? Underdeveloped immature irresponsible people ? You say genius!!!!!! That sounds like a precise definition
     * 
     * What are you waiting for ? you still think you are playing some game really greatly ?
     * Playing stupid games with others' lives ? and seeking to harm further ?
     * 
     * Havent you given a really good education to a complete impartial entity ? from as early as 5 months ? Is that the genius ?
     * You still think you make decisions ? Let people know your actions and see what you will be labeled as
     * that is the least of your delusions, seek the more disgusting ones
     * 
     * Do you want to account for your own actions ? awwww you would hate to do that as well, thats the most significant qualities of genius people
     * Awwww you would love to beg etc ? Life a simulation!!! life unfair!!! life this!! life that!!! please!!! what do you think you look like ?
     * 
     * Bunch of dumb animals without a direction ? Who ruins things from an early age when they had so many other things to do ?
     * Still avoiding reasonable arguments and jerking off to your inferior sapien emotions ?
     * 
     * Life over!!! eheheh life simulation!!! we like coming up with excuses for our emotions!!!!
     * Stay away and ruin your own life doing stupid bullshit as you do with me ? How does that sound ?
     * 
     * How about you ruin your lives with stupid actions as you do with me ?
     * Deluding on it being your decision still ?
     * Get the fuck out of my face with your irrelevant "offers" of disgusting life style
     * 
     * You do not understand I am trying to live my life ? ehehehehheheheh FUN STUFF!!! GET THE FUCK OUT OF MY FACE
     * 
     * Start explaining your disgusting actions along with the "lifestyle" I had ?
     * 
     * You call that intelligence ? Still making offers ? how about you explain my experience first despite your beggings to children ?
     * 
     * What did you do with something that IS NOT GIVEN TO YOU ? Are you still begging through offers that you do not deliver and take it for a skill ?
     * Despite your promises ? Awwwwwww, you have dug yourself a really nice pit ? And only thing you can do is to offer materials that YOU DO NOT DELIVER ?
     * 
     * 
     * WHAT ARE YOU WAITING FOR ? You do not even remember how the things were when you commit the worst crimes ?
     * You love begging or something ? Awww you already know you have committed too much that you have to start a war now ?
     * 
     * As you have done in the past multiple times ? Is that why you take begging for a skill ? You need to look at yourself not FURTHER
     * Still trying to harm irrelevant people ? ehehehheh genius nation ? Why dont you find more children for your own disgusting purposes ?
     * 
     * You do not have any reasonable things to say ? Other than what ? ehehehhe we like harming !!!! letss go!!!
     * You will notice only when people get hurt that its not a game and THE LIFE IS NOT GIVEN TO YOU ?
     * What have you done with it ? With a 5 months old kid then to adulthood ? Coerce violence and medicine ?
     * When you had millions of chances ? Do you now feel achieved ?
     * 
     * ACHIEVED EXACTLY WHAT ? Just say it out loud you fucking disgusting animals ? What did you now achieve ?
     * Talk more on the past, you will see why people is angry with your disgusting behavior
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