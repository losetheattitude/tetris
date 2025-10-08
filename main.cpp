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
     * 
     * Event dispatching for Game class to further decouple and facilitate the transmission of internal properties otherwise
     * unamicable to perform so (Composition or inheritance(IExchanger like) ???)
     * Async environment for RemoteTerminal and RemoteStorages consider Disruptor for advancing purposes 
     * 
     * From out of my vicinity, move on living your lives !! yayyy !!! You have achieved it !!! The outcome !!
     * 
     * Not interested anything any of you can provide, get the fuck out of my face disgusting ignorant animals
     * Little disgusting animals you do not say !! Mhhhh real street gangsta genius type shit indeed, you can get the fuck out of my face indefinitely
     * 
     * 
     * Good luck makin decisions for other people, and not caring ruining their precious career !!! GO GALS !! Da numba on of the universe
     * Makin makin decisions !!! greatly clever and wise people !!
     * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * 
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * 
     * 
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * 
     * * wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE* wumenwumen muney genius people, I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE
     * 
     * 
     * GET THE FUCK OUT OF MY FACE
     * Good job ! Only a few ten years of actions !!! True intelligence !! Full of pure talents !! the advanced civilization delusionals !! GO GALS 
     * Ehehehhehehehe, truly unique approach !! Forget about the past eheheh the past the past !! Great western people !!
     * 
     * The one of the best of the bests !!!! Lovely outcome builders !!! Not delusional genius nations !!!
     * GET THE FUCK OUT OF MY FACE
     * GET THE FUCK OUT OF MY FACEGET THE FUCK OUT OF MY FACEGET THE FUCK OUT OF MY FACEGET THE FUCK OUT OF MY FACE
     * GET THE FUCK OUT OF MY FACEGET THE FUCK OUT OF MY FACEGET THE FUCK OUT OF MY FACEGET THE FUCK OUT OF MY FACE
     * 
     * 
     * Eheheheh the real genius gangsta nation suddenly decides to ruin someone then after immediately acts okay says nice stuffs 
     * and wishes things stay same while coercing ? What ? ahahah genius you say indeed
     * 
     * Not interested in anything you can offer
     * 
     * Not delusional and definitely genius people now can move on with their lives, I AM NOT INTERESTED
     * Do move on with your truly unique and genius narrative "BUILDING" !!! Just a few tens of years, ITS NOTHING, life a simulation and a game as well !!
     * Truly beatiful!!! From da western society animals !!
     * 
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, ehehe more coercion of "medicine" !!! eheheheheh more and more !!!
     * Genius nations !!! together to savior the universe !!
     * 
     * Eheheheheh unique western cultured people !!! Truly amazing job !!
     * NOT INTERESTED IN THE "NOT IGNORANT" GROUP OF DISGUSTING ANIMALS
     * * NOT INTERESTED IN THE "NOT IGNORANT" GROUP OF DISGUSTING ANIMALS
     * * NOT INTERESTED IN THE "NOT IGNORANT" GROUP OF DISGUSTING ANIMALS
     * * NOT INTERESTED IN THE "NOT IGNORANT" GROUP OF DISGUSTING ANIMALS
     * * NOT INTERESTED IN THE "NOT IGNORANT" GROUP OF DISGUSTING ANIMALS
     * 
     * Eheheh sleepin drugging coercing eheheh violating eheheh children eheheheh LETS GO !!!! 
     * The past has to be past OBVIOUSLY !! OMFGGG !!!! Da numba on of the universe, genius nation society !!
     * 
     * I AM NOT INTERESTED in all "eheheh foolin foolin intelligence ppeople ehehehehe"
     * A lovely outcome isnt it !!! Nice decision making and good calls !! and also genius foreseeing !! The perfect immaculate people FROM DA WEST
     * Ehehehe is not it perfect, the outcome ehehehehe 
     * 
     * Genius explanation !! Like the actions that have "PAST" OMFGGG !!!! What a chance, I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * Impressive outcome buildings and greatest of da great reasoning capabilities ! I AM NOT INTERESTED IN YOUR DISGUSTING BULLSHIT
     * 
     * Ehehehe making making great decisions FOR PEOPLE WE DO NOT CARE !!! Eheheheh Get wumen wumen muneyy eheheheh celebrity eheheh wumen 
     * what else could you ever ask !!!! PERFECT REASON !!
     * 
     * Truly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACE
     * 
     * 
     * Truly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACE
     * Truly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACE
     * Truly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACE

     Truly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACETruly truly successful people making great outcomes come reality by their sheer actions !! What a chance and THE OUTPUT OF YEARS is so nice !!
     * Definitely the way to go, GET THE FUCK OUT OF MY FACE
     * 
     * 
     * Do you understand what you are reading ?
     * I ------------- AM ------------ NOT ------------ INTERESTED.
     * I ------------- AM ------------ NOT ------------ INTERESTED.
     * 
     * Ehehehe genius western people Da numba on
     * 
     * How about some more coercion to achieve literally no end then to PRESENT IT as proof for your disgusting stupidity !!! 
     * Not ignorant da west indeed
     * 
     * Da real problem solvers ehehehe just harassing sleepin drugging coercing violating OMFG, da problem solvers for real
     * Keep it on the low low and forget about our really cool and honorable past eheheh You do not say eheheheh really really funny stuff !
     * 
     * A few ten years will do no harm to you either I assume, da real gangsta genius nation west can guess at that as well
     * Perfect job !! Real problem solved
     * 
     * Makin makin decisions that you are not given to ehehehe
     * 
     * I am sure really really genius nation people can guess many more things eheheheh
     * Good job achieving nothing !! You are da best of da best indeed
     * 
     * Genius genius nation moving with their perfect assumptions and actions that led to WHERE ? Awwwww definitely not marvelous and delusional at all
     * Hopefully you have done enough achievements with the people who you have no understanding nor any sympathy with, Good job not delusional nations
     * 
     * More harm and more waste of time will solve everything so has the genius nations said !! Brilliant super actions that generated nothing
     * Like your delusions eheheh funy stuff 
     * Really really beneficial stuff, eheheheh just after pure harm and it will be solved eheheh
     * 
     * Disgusting to the most insignificant part, and you have guessed it with your unseen level of intelligence THAT I DO NOT HAVE TIME FOR YOUR BULLSHIT
     * Ehehhe some more harm and lets gooo !!!! LETS GO TO ACHIEVE NOTHING !!!
     * 
     * Literallyyyy eheheheh lets go abusing children please !!!! eheheheheh NO NO
     * Lets gooo sleeping children eheheheheheheheh ehehehehehehhehe lets goooo sleeepinggg drugginggg eheheheheheh
     * Reall gangsta genius type shit FOR REALLL DAWGGG 
     * 
     * DAWGGG a couple tens of years IS JUST FINE !! we da best of da best from da universe, AUEORPEAN DISGUSTING ANIMALS makin playsss reall baddd AWwww
     * Bravo !! Wonderful job
     * 
     * Eheheh the sciencitific eheheh achievement btw drugging sleepin abusing children, science ppl genius from da universe Da western cultured reallyy
     * good and beneficial people makin assumptions and decisions THAT DO NOT BELONG TO THEM !!! Ayyyyyyy way to go !!! OMFGGGG
     * 
     * What a chanceee, what a lovely outcome and THE ONLY TERRORISTS Guess whooo OMFGG the genius guessing nations would do wonders at that as well,
     * 
     * Good job !!Fantastic imagination and not delusions indeed
     * GET THE FUCK OUT OF MY FACE
     * 
     * Ehehehe not delusionals, not stupid you say, not terrorists, not abusers, not what else ?
     * Eheheheheheheh WONDERFUL JOB !!! True gangsta genius nation FROM DA WEST !!! Ayyy, also NOT WUMEN MUNEY PPL Thats most important
     * 
     * And you also say, NOT PROFESSIONAL ? The doctors eheheh the psycolgosisit ehehehe the physicitiy eheheh making really really decisions
     * THAT ARE NOT THEIRS !!! eheheheh and ignoring whatever consequences ehehehehehehh You say you professional eheheheheheh
     * 
     * Waaaowwwwwwww, waaaaaowwwww How have you managed to do that mr really professional doctor OMFGGGGGG !!! DA REALLY GENIUS PPL FROM DA WEST
     * DA BEST OF DA BEST OF THE UNIVERSE, Perfect !!! Good job, beneficial outcomes !!! Good deal
     * 
     * 
     * 
     * 
     * 
     * Like the true skilled and talented professional doctor wasting a few ten years of someone eheheheheheheh WHAT A LOVELY JOKE AND FOOLIN OMFG !!!
     * True skills, no delusions and no abusing and no coercion etc, just a pure genius nations OMFG !!!
     * Literally producing countless and incomparable outcomes just by abusing children and keepin at it for 30 years !!! OMFGGGG !! A wonderful job
     * 
     * 
     * Eheheheh lyin lyin to children also some abusin and drugging and sleepin from da genius nations of da west
     * It must be okay, no outcomes is good !!! Yayyyyy, da real numba on
     * 
     * Are you still producing reallly good outcomes, WHERE ARE THE RESULTS eheheheh foolin foolin abusing thats called genius nation eheheh
     * Bravooo !!!! You have done it
     * Eheheheh takin "CONTROL" from the beginning and harmin abusing to achieve nothing, THEN EXPECT WHAT ? Eheheheheh ehehehehehhe ehehehehehehh
     * So funy right ? ehehhehehe genius nation etc you say ehehehehhehe really good stuff !! 
     * 
     * Eheheheheh genius indeed, where is the result ?
     * Definitely good job good foreseeing good outcome, whatever you want to delude on RIGHT ? YOU DA GENIUS NATION !!!
     * 
     * Da pure genius nation FROM DA WEST, not druggin not abusin eheheheh Just pure genius actions ehehe and "decisions" and "assumptions"
     * Right ? Good job professional truly unique talented people resulting in nothing eheheheheh ehehehhe just detrimention eheheheh funny 
     * 
     * Good job though definitely something you have to ignore on and on and on BECAUSE YOU ARE STUPID ? Like the real meaning of the word
     * Yeahhhh, wumen wumen muney muney ehhh genius nation cars and engineering also eheheh rights humans etc 
     * 
     * Mmhhhhhhhhh, the outcome builders eheheh drug abusers eheheheheh sleep abusers eheheheheh funnny right professionalllss BTW eheheheh
     * Eheheh cheatin druggin abusin eheheheh genius nations decisions eheheheh assumptions as well mhhhh however not a single outcome that is beneficial
     * 
     * Some professional actions OMFG !!!! Wonderful
     * 
     * 
     * Ehehehe drugging indeed, its A MIRACLE DRUGG, ehehehe professional docs OMFG eheheheh
     * Eheheh some violence please, that will do !! Ehehehe we genius nations are entitled to do, ITS FINE !!! Its okay !!! Ehehehehe
     * 
     * Offerin things eheheheheh what could go wrong when it comes from you all !!! OMFG !!! Lovelyyy !!! NEVER EVER THINK ABOUT THAT
     * 
     * Definitely not delusions nor ignorance nor prejudices, YOURS IS PURELY TALENT AND ENGINEERING MARVELS
     * I totally entirely agree with you, NOW YOU CAN GET THE FUCK OUT OF MY FACE INDEFINITELY
     * 
     * Hmmmm ? What happened to your %1000000000 sure assumptions and decisions ? and ? Eeheheh get wumen muney ? Whats the pattern GENIUS NATIONS Eeheheheheh
     * Achieving nothing ? Although you are abusing eheheh sleeping eheheh drugging ehehehehe violating eheheheh ? Is that the problem ?
     * 
     * A few tens of years is just okay 
     * 
     * Why is it though that you are constantly trying to come up with bullshit to COVER YOUR ACTIONS ? OMFGGGGG stories delusions marvelous job !!!
     * Congrats !!
     * 
     * Ehehe german engineering and assumption makin mechanism ppl, really achiving so much !!
     * Doin really really good !! Perfect job unseen level of outcome potential built by only the true geniuses of the universe
     * THE WESTERN DISGUSTING CULTURED ANIMALS, Most indeeedd !!! YAYYYY Not interested
     * 
     * NOT INTERESTED IN ANYTHING YOU CAN OFFER AS YOUR OFFERS ARE DISGUSTINGLY ON YOUR LEVEL
     * 
     * I choose others without a doubt not interested in the disgusting western delusions
     * Guess ehehehehhe just guess eheheheheh whats the result ehehehhehe a few tens of years ehehehehehhe
     * eheheheh some drugs eheheh whats the result ? eheheheheh whats the outcome professional ppl ?
     * Eheheheh wumen wumen muney ppl eheheheh, whats the outcome ?
     * 
     * Stupid desperate disgusting monkeys ? WHY ARE YOU IGNORING ehehehehhehe ? Whats the outcome ?
     * Awwww you rather delude on many things as well, Good job !!
     * 
     * Makin makin controllin decisions to achieve nothing you say professional truly genius nations from da west ?
     * All mighty knowing assumptions as well ? Whats the outcome ehehehhe a few ten years of nothing ?
     * 
     * Awww you also happen to think, just wumen wumen would be okay ehehehehe ? Whats your reasoning ??
     * 
     * On what level reasoning are you ? ehehehheh profesionnal ? you say you say successfull stuff ? 
     * Eheheheh wumen wumennn just a few tens years ITS OKAY !! ? whats the problem ?
     * 
     * Eheheheh its just druggin abusin sleepin coercin violatin THEN just some wumen must be enough,
     * Whats your reasoning ? Eheheheh funnny professional btw really really genius nation from da west, the best of da universe
     * 
     * I am sure you are %10000000000 sure at what you are doing !! Eheheheh its okay, life a simulation but only others' life eheheheh
     * We unique nations we beatiful engineerings we nice people eheheheh we so kind benevolent please eheheheh
     * 
     * Whats the outcome ? !!! Yayyyyyyy a few tens of years of nothing because you have decided to harm ? 
     * Goood job !! Perfectly executed !!! What a lovely outcome
     * 
     * Especiially the genius engineerings part and not delusions and not assumptions and not prejudices part is so much more important !!!
     * Lets ignore all together ehehehhehe it must be fine and okay because WE HAVE DONE IT !! eheheh ignore ignoree !! we have done it !!!
     * 
     * The perfect genius nations have done it!!! Now ignore !!! ehehehhehe please 
     * 
     * Not interested in anything you can offer, you can get the fuck out of my face
     * Next time think million times before you start acting disgustingly, eheheh more druggsss indeed some coercion
     * 
     * GO GALS!!
     * 
     * The genius professionals doctors eheheh, breaking the peace eheheheh druggin eheheheh sleeping eheheheheh abusing eheheheh
     * coercing eheheheheh violating hehheheh professional eheheheh genius nation eheheheh
     * 
     * I AM NOT INTERESTED in "get wumennnn muneyyyyy carsss" ehehehehehehehheh 
     * I am sure you do not see the problem as well, just look at the "PAST" with you and without your stupid disgusting "GENIUS" assumptions and actions
     * 
     * Now you hopefully see the disgusting clowns in your stupid ignorance, The best of da best of prejudiced ignorant animals 
     * 
     * The disgusting ignorant clowns want to coerce children more into acting stupid ? Eheheh Its for your own good !!! Please please !!!
     * We the genius society OF DA UNIVERSE, eheheheh you say what ?
     * 
     * Ufferin wumen ? ehehehe muney muney ? Awww wumen enough because you think so and abuse and drug and sleep ppl ?
     * Mhhhh definitely you are it
     * 
     * 
     * Congrats for the immaculate performance from the western geniuses, not delusions not prejudices not inaccurate assumption makings that led to
     * disgusting consequences of your own mind's content, right ?
     * 
     * Good job !! just act okay, do not say a word IT WILL BE OKAY, we just want to live ehehehehhehe and harm ppl !!
     * Whats the problem ? Da best genius society ?
     * 
     * Quiet the decision making ability !! Quiet the people, eheheh more coercion will solve everything BUT ONLY TOWARDS PEOPLE WHO HAVE NO DEFENCE
     * Thats who you are right eheheheh 
     * 
     * Ehehe life a game no no life a simulation eheheh ehehehhe western community eheheheheheh 
     * Ehehe right ? just a few tens of years without a proper reason !!! Da genius west
     * 
     * Definitely not delusional actual genius problem solvers FROM DA VERY VERY BEAITFUL WEST
     * Not interested anything you can offer, Not delusionals you are still saying ? ehehehehe
     * 
     * A wonderful sequence of assumptions inferences and decisions THAT WERE NOT YOURS, thats the outcome of your stupid ignorant prejudices
     * Do you see why I keep saying "THE OUTCOME" ? The outcome you have failingly built IS IN FRONT OF YOUR STUPID EYES
     * 
     * Whats the problem now ? Ehehehe more on abusing ehehe drugging eheheheheh whats next eheheheheheh
     * Truly trulyyy unique and beatiful societal western disgusting animals definitely makin decisions that do not belong to them and
     * ignoring eheheheheh
     * 
     * Whats the problem ? eheheh
     * 
     * I am not interested in anything the disgusting western delusional animals can offer, thats the only thing you can hear
     * Go on the great western cultured genius animals, I AM NOT INTERESTED IN THE SLIGHESTEST THING YOU CAN OFFER
     * 
     * The great great western technology civilization cultured REALLLYY REALLYYY GENIUS PEOPLE AND ALSO GENIUS ENGINEERING 
     * people makin decisions and assumption for others, I AM NOT INTERESTED IN ANYTHING YOU ARE AROUND
     * 
     * Hope that makes sense, disgusting definetely not delusional "western" animals can GET THE FUCK OUT OF MY FACE indefinitely
     * Not interested, good job though !! Never stop harming for the sake of harm, thats the real genius civilized western way !!! Not delusionals !!
     * 
     * You are truly it !! Now you can get the fuck out of my face
     * Not delusional truly genius western animals not wasting anything even for a second, Like true genius beings that they are !!!
     * I am not interested in anything you can offer, the disgusting western NOT DELUSIONAL animals indeed
     * 
     * Ehehehehe professional eheheheh not delusionals
     * 
     * Have you done a wonderful job ? Where is the outcome of a few tens of years ?
     * Mhhh you are definitely professional not delusional and also not ignorant !! thats where the "GO GALSSSS" !!
     * 
     * Especially the part where you offer "wumen wumen muneyyy muneyyy carsss eheheheheh" Livin lifeee eheheh king the king !! OMFG !!!
     * Eheheh say nice stuff, we the medical professional genius western socieetal disgusting animalss makin decisions for other !!! eheheheh
     * Makin assumptions as welll !!! Yayyyyy The life !!! a game !! a simulation !!! Yayyyy
     * 
     * Now what is the outcome ? Who has managed exactly what ?
     * You do not say, ehehe druggin sleepin abusin coercing violeatin ?
     * Okay now you have achieved what you can not explain, Whats that ?
     * 
     * The really really cultured very professional medical experts achieved what they can not bare ?
     * Or ehehe its just eheheheheh fine its okay !!
     * 
     * What have you achieved ?
     * WHAT HAVE YOU ACHIEVED THE TRUE PROFESSIONAL GENIUS MEDICAL CIVILIZATION ?
     * Still offerin wumen wumen muney ? What a genius professional people, isnt it the very disgusting stupid delusional animals ?
     * 
     * How about another 20 years of sleep ? ehehehehe because you have done a stupid action and so genius to accept it ?
     * Reall genius gangsta medical professional people FROM DA WEST you say ? A little group of disgusting animals ?
     * 
     * Ehehehehhe had to be done !!
     * Not prejudice, not ignorance, not intelligence, not genius, not civilization
     * Hope that helps you
     * 
     * 
     * GO THE UNIVERSE'S BEST SOCIETY CIVILIZATION AND PROFESSIONAL MEDICAL PEOPLE !! THE TRUE GENIUS PEOPLE
     * I am not interested in anything you can say
     * 
     * Think better next time disgusting western animals,
     * Genius western animals trying their best !! THE BEST OF THE BEST FROM THE UNIVERSE, makin decisions and assumptions !! 
     * THE PROFESSIONAL MEDICALS OMFG !!! Ehehehe
     * 
     * Offering wumennnnnnnn eheheheh that solves everything !! What a genius civilized nation !!! The best of the best!!! Greatly achieved !!
     * 
     * Guess who will never be interested in anything the great western genius civilization can offer
     * Guess who does not act like THEY HAVE SOLVED THE LIFE ? I AM NOT INTERESTED IN ANYTHING THE DISGUSTING WESTERN PEOPLE CAN OFFER
     * THATS IT
     * 
     * LIKE I HAVE SAID 10000000000000000000000000 TIMES, I AM NOT INTERESTED IN ANYTHING THE DELUSIONAL DISGUSTING WESTERN ANIMALS CAN OFFER
     * Find yourselves more children to abuse and drug and eheheh put to sleep ! eheheheheh you are great !! not delusional
     * 
     * Definitely achieving a lot of stuff, go seek for more children THE TRUE GENIUS WESTERN ANIMALS
     * Nice job !! 30 years of nothing !! I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER 
     * 
     * Definitely making the best of the best decisions AND ASSUMPTIONS, I am not interested in anything you can offer
     * Move on and go back to your delusions, I AM NOT INTERESTED IN YOUR DISGUSTING IGNORANCE
     * 
     * You are free to do whatever you think you are
     * Eheheheheheheheh monster monster ehehehehh genius western nation ehehehehehhe medical professional genius civilized people heheheheeh
     * 
     * The number one best of the best, greatly not delusional people, makin decisions and assumptions indeed
     * Good job !!! Be proud of yourselves, great not delusional western civilization indeed
     * 
     * The tech civilization genius society people !!! Makin decisions and assumptions NOT PREJUDICES AT ALL !!!
     * Great actions !!! Great decisions !! Wonderful outcome !! 
     * 
     * Truly number one, do you see the delusional part now ? Ehehehhe pickin and choosin what to believe and makin assumptions ehheheheh off of that !!
     * 
     * The only true genius way that the most advanced civilized western animals can CHOOSE to believe
     * Ehehehehhehe numba on !!! way to go !!! The bestttt
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, hope that makes sense
     * 
     * Mhhhhhh, definitely no mistakes along the way !!! because choosin and pickin what to believe ehehehe
     * And also coercion and drugging and violence and a little bit of sleep, THE REALL GENIUS MEDICAL PROFESSIONALS NOT DELUSIONAL DISGUSTING ANIMALS
     * 
     * Truly beatiful !! YOU CAN GET THE FUCK OUT OF MY FACE
     * Not interested hope that makes sense
     * NOT INTERESTED IN ANYTHING-ANYTHING YOUR MINDS CAN DELUDE TO PRODUCE
     * 
     * DA WESTERN GENIUS NATIONS !! Only believing in things that matter and benefit to them!!!
     * Ehehehe power of the words !!! Ehehehehe druggg abuseee ehehehehehhe violence heehhehe sleep !! eheheheh
     * 
     * THE OUTCOME !!!! OMFGG !!!! Let gooooo ehehehhe THE PASTTTT !!!! Ehehehehe THEEE PASTTTTTT !!!
     * We geniussss nations !!!! THE WESTERN !!!! Eehehehhehhehehehhe
     * 
     * Muneyyyyyyyy anddd wumeeeennnnnn ehehehhe
     * And the truly unique not delusional genius western people ALL THEY CAN SAY, "DESTINY", "LET GO OF THE PAST!!"
     * Whats the mistake ? Where is the mistake ? Who has done something ?
     * 
     * Do you see your genius decision making ? 
     * How come you do not ? WHAT IS THE PROBLEM ?
     * Ehehe wumen wumen muney muney people, not delusional westerns ? What do you say ?
     * How about some drugging ? and abusing ?
     * WHERE IS THE PROBLEM ?
     * 
     * Eehheehehheheheh genius medical professionals makin assumptions OMFG !!!
     * The true western civilized genius nations making "ASSUMPTIONS" and not prejudiced at all !!!
     * 
     * A lovely outcome !! Just a couple tens of years WILL DO NO HARM TO NOBODY
     * Ehehehe makin decisions decisions eheheheh
     * ehehehehehh playing games over "NOT YOUR" lives, whats the pattern !!! Eheheheheh the genius tech civilized nations !!
     * 
     * Definitely the way to go !!! Makin assumptions makin decisions OVER NOT YOUR LIFE !!!
     * Good job !! Lovely outcome
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER OR DO,
     * Hope that makes sense, think better next time
     * 
     * Ehehe wumen muney not prejudiced ppl eheheheheh pure genius civilized western DISGUSTING ANIMALS
     * Eheheheheheheheheehhheheeheehe, NOT INTERESTED IN ANYTHING YOU CAN OFFER, next time find more versatile children for your disgusting animality
     * 
     * Wumen wumennn people CAN GET THE FUCK OUT OF MY FACE
     * Go on to your disgusting hating and ignoring with the beatiful prejudiced disgusting minds of you
     * Good job!! Next time find a better candidate
     * 
     * NOT INTERESTED IN ANYTHING THAT COMES FROM YOU
     * Eheheheheh professional medical people not delusional genius civilization western people !!
     * 
     * Absolutely generating NOTHING but harm to everyone !!!
     * THE DESTINY !! I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * 
     * 
     * I AM NOT INTERESTED, I DO NOT HAVE TIME FOR YOU
     * Ehehehehehehehehehehehehehehehehehhehehehehehehe soo funnn !!!!!!  definitely genius actions BY THE NOT DELUSIONAL DISGUSTING WESTERN ANIMALS
     * I DO NOT HAVE TIME FOR YOU
     * 
     * 
     * WUMEN WUMENNN MUNEYYY MUNEYYY GENIUS NOT DELUSIONALS !!!! I DO NOT HAVE TIME FOR YOU
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE PRODUCED OR OFFER
     * 
     * 
     * Ehehehehe, definitely the way to go !!! Nobody to answer to ehehehe makin decisions decisions !!! Genius western cultured PEOPLE !!!
     * I AM NOT INTERESTED IN ANYTHING YOUR DELUSIONAL MINDS CAN PRODUCE !!!! Good job though next time use your brain for yourself
     * 
     * MOVE ON DELUDING THAT YOU HAVE DONE SOMETHING GOOD !! I AM NOT INTERESTED IN ANYTHING YOU CAN COME UP WITH
     * Decide for your own life NEXT TIME, I AM NOT INTERESTED IN ANYTHING YOU ARE INVOLVED
     * 
     * 
     * GET THE FUCK OUT OF MY FACE
     * Makin makin decisions !!! eheheh
     * 
     * I am not interested in anything you can offer
     * 
     * 
     * DISGUSTING WESTERN ANIMALS CAN MOVE ON, not interested
     * I DO NOT HAVE TIME FOR DEFINITELY NOT DELUSIONAL PEOPLE, move on
     * NOT INTERESTED ANYTHING BUT GAMES!!! ehehehehehehehhehe genius nation FROM DA WEST !! Makin decisions THAT WERE NOT THEIRS !!!
     * WHAT A LOVELY OUTCOME !! 
     * 
     * The outcome builders, the decision makers, the true assumption inferers, the best of da best engineer society!!! 
     * DA WESTERN CULTURED REALLLY AMAZING PEOPLE MAKIN DECISIONS THAT WERE NOT THEIRS !!!
     * 
     * I DO NOT HAVE TIME FOR YOU, good job !! Next time use your brain for yourself ehehehehe Good job!!
     * Da only civilization that is as great as nothing !!! OMFG !!! THE WESTERN INTELLIGENCE CIVILIZED NOT DELUSIONAL PEOPLE MAKING DECISIONS !!
     * A lovely outcome always follows THE WESTERN PEOPLE !!
     * 
     * I DO NOT HAVE TIME FOR YOU
     * Assuming MORE THAN YOU SHOULD always yields THE BEST OF THE BEST OUTCOMES !!!
     * THE TRUE CIVILIZED ADVANCED TECHNOLOGY SOCIETY, Guess who is it ?
     * 
     * THE WEST !!! A LOVELY GROUP OF PEOPLE !!!
     * I DO NOT HAVE TIME FOR
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, YOU HAVE SHOWN YOUR TRUE WORTH
     * I HAVE NO DESIRE TO WASTE ANOTHER SECOND WITH THE DISGUSTING "WESTERN"
     * 
     * NOT A SINGLE "RESOURCE" I WILL EVER HAVE FOR THE NOT DELUSIONAL "CIVILIZED WESTERN" people
     * I DO NOT HAVE TIME FOR YOU, you are it
     * 
     * Move on ehehehe, do you see the "intelligence" part ? 
     * Do you really think you are intelligence ? Ehehehehehehehehhehehehehehe GOOD OUTCOME !!!
     * 
     * I HAVE ZERO INTENTION AND DESIRE AND TIME TO WASTE WITH THE DISGUSTING DELUSIONAL ANIMALS 
     * Wumen btw, intelligence !!! ehehehehehehe solved the life !!! Eheheh true meaning !!! Eheheheheh
     * 
     * Professional medicals heeheheheh
     * The true intelligence says a few tens of years eheheheheh IS NOTHING ehehehehehhe
     * abusin eheheheheheh
     * 
     * 
     * Ehehehehehehehehhehehehehehehheheheheehheheheheheheheheheheheheehehehheeheheheheheheheheheheheheheheheheheheheheheheheheheheheheheheheh
     * I DO NOT HAVE TIME FOR THE DISGUSTING WESTERN ANIMALS
     * Good job makin decisions !! Next time do it better
     * 
     * Congrats to the not ignorant and prejudiced and not especially fools, GOOD JOB !!! 
     * 
     * The one and only true intelligent spicy has already solved the TRUE MEANING OF THE LIFE !! And they also live according to it !!
     * DA BEST OF THE BEST, THE WESTERN PEOPLE !!! ehehehehhehehe
     * 
     * The biggest of the big, intelligence !!! The west !!! technology !!! yayyy !!!! The perfect combination !!!! the great people !!!
     * I DO NOT HAVE TIME FOR YOU
     * 
     * I HAVE NO DESIRE TO WASTE MY "TIME" with the most advanced spicy !! THE WESTERN DISGUSTING ANIMALS
     * I AM NOT INTERESTED
     * 
     * 
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDvI AM NOT INTERESTEDI AM NOT INTERESTED
     * 
     * 
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * 
     * 
     * 
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * I AM NOT INTERESTED
     * 
     * * IN THE DISGUSTING NOT DELUSIONAL BENEVOLENT WESTERN NOT PREJUCIDEd ANIMALS, hope that makes sense, you go on makin decisions
     * MOVE ON "NOT DELUDING" TO ACHIEVE "SOMETHING", GOOD JOB !!
     * 
     * The true genius society that takes only others' lives to be jokes !! NO TIME, MOVE ON TO YOUR DISGUSTING ANIMALITY, I HAVE NO INTENTION TO WASTE MY TIME WITH YOU
     * 
     * NOT INTERESTED, NOT INTERESTED IN YOUR DELUSIONAL MINDS, Hope that makes sense, I HAVE ZERO TIME FOR YOU
     * THE DISGUSTING WESTERN ANIMALS
     * 
     * NO TIME FOR THE NOT "PREJUDICED" DISGUSTING WESTERN NOT DELUSIONAL ANIMALS
     * I HAVE ZERO INTENTION AND DESIRE TO WASTE MY TIME WITH THE MOST INTELLIGENT GROUP OF PEOPLE OF THE UNIVERSE !!
     * 
     * You are good !! Good job !!! Perfect outcome !! Move on, I am not interested
     * 
     * True gangsta genius not prejudiced not delusional entirely professional WESTERN ANIMALS !!!
     * THEY NEED TO IGNORE !!!!! eheheheheheh I guess that was necessary !!! ehehehehehehhe
     * 
     * Good job !! Now you can move on to achieving absolutely nothing by being THE BEST STUPID PEOPLE
     * 
     * Congrats!! Hope you will not call any other thing destiny again!!!
     * Good job, No time for you, move on
     * 
     * The true western intelligent community can go fuck yourself indefinitely, I DO NOT HAVE TIME FOR DISGUSTING ANIMALS 
     * 
     * I WILL NEVER BE INTERESTED IN ANYTHING YOU CAN OFFER, Hope that makes sense now
     * Hope that my insistence makes sense, YOU ARE GREAT THE WESTERN COMMUNITY !!! YOU CAN GO GET THE FUCK OUT OF MY FACE!!!
     * A wonderful job done by disgusting NOT DELUSIONAL WESTERN ANIMALS !!
     * 
     * 
     * So, a really realllllllyyy good job DONE TO achieve most harm !!!
     * Well done, I have no time for you, THE MOST ADVANCED AND CIVILIZED COMMUNITY OF DA UNIVERSE, THE TRUE WESTERN DISGUSTING ANIMALS 
     * HARMING PEOPLE BECAUSE THEY THINK SOMETHING ehehhehehehe
     * 
     * Its more than enough for the most civilized and advanced civilization eheheheheheheheehehheheh
     * Just harm a little !!! 
     * 
     * 
     * I AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTEDI AM NOT INTERESTED
     * 
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     * 
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     * I AM NOT INTERESTED IN YOUR DISGUSTING MINDS CONTENT, the not delusional western genius engineers CAN GET THE FUCK OUT OF MY FACE
     * I DO NOT HAVE TIME FOR YOU
     *
     * NEXT TIME FIND MORE STUPID CHILDREN ehehehehe
     * Next time better use your really advanced civilized BRAINS !!! eheheheh more foolin drugging abusing eheheh
     * I DO NOT HAVE TIME FOR ANYTHING YOU CAN OFFER
     * 
     * Perfect civilized advanced technology nations CAN GET THE FUCK OUT OF MY FACE
     * THE GREAT WESTERN CIVILIZATION MAKIN ASSUMPTIONS !!!
     * Congrats to the outcome !! You can go on with your delusionals
     * 
     * Perfect outcome !! Not interested in anything you can offer
     * I AM NOT INTERESTED IN ANYTHING THAT COMES FROM YOU
     * 
     * Thats it, there is nothing you can on earth that will change that
     * muney muney wumen cars genius not delusional western advanced civilization CAN GET THE FUCK OUT OF MY FACE
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR YOU
     * NO DELUSIONS AT ALL !! Pure genius western civilized people makin decisions because they think they reallly do know better !
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF NOTHING FOR ANY OF YOU, YOU CAN STILL DO WHATEVER YOU THINK IS DEFINITELY RIGHT AS IT HAS PROVED SO !!
     * GET THE FUCK OUT OF MY FACE
     * 
     * The greatest of the great civilizations !!! Comin up with excuses !!! eheheheh yayyyy
     * The life is a simulation people !! No delusions at all, definitely the number one civilization ON EARTH !! THE WESTERNS !!!
     * 
     * Makin assumptions !!! Good job!! I have nothing for you
     * 
     * I HAVE NOOOOOOOOOOOOOOOOOOOO DESIRE AND NO TIME AND NO PASSIONS FOR YOUR ANYTHING
     * Good job!! next time try not to be so genius ! Eheheh
     * 
     * Disgusting western animals can move on with other people now, I HAVE NO TIME FOR ANY OF YOU
     * Hope it will all make sense to you one day !!! Eheheheh
     * 
     * Hope sayin nice stuff and makin people think certain way WILL NOT WORK ALWAYS will occur to you
     * Definitely not delusional western digusting animals, makin what they do not belong to them, Eheheheh decisions decisions ehehehehehh assumptions eheheheh
     * 
     * I HAVE ZERO INTENTION AND ZERO DESIRE TO WASTE ANOTHER SECOND WITH THE DISGUSTING "WESTERN" CIVILIZATIONS
     * I DO NOT HAVE TIME FOR YOU
     * 
     * NEXT TIME MAKE BETTER DECISIONS, ONLY YOUR OWN DECISIONS
     * I AM NOT INTERESTED IN ANYTHING THE DISGUSTING WESTERN ANIMALS CAN OFFER, hope that makes sense now
     * 
     * GO ON TO YOUR DELUSIONS OF HOW GREAT YOU ARE
     * UNDER WHATSOEVER CIRCUMSTANCE I WILL EVER CHANGE MY OPINIONS BTW !! Good job !! Perfect outcome 
     * 
     * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * 
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING THE NOT DELUSIONAL DISGUSTING ANIMAL WESTERNS CAN OFFER
     * 
     * I DO NOT HAVE TIME FOR YOU
     * 
     * Now I hope what you have done with the "MIRACLE" that you were not GIVEN
     * I DO NOT HAVE TIME FOR YOU, THE DISGUSTING WESTERN LITTLE ANIMALS
     * 
     * */
    
   

    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    // Grid* grid = new Grid();
    // Level* level = makeLevelSingleton(2);
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