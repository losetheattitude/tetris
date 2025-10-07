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
     * Eheheheh problem solvers ehehehehe the genius people from the western society !!! Waaowwwwww, making decisionss !!!!! assumptions of
     * never ever seen kind before !!! 
     * 
     * Perfect job !!! YOU CAN GET THE FUCK OUT OF MY FACE !!
     * 
     * Stupid disgusting animals who thinks they can solve everything with medicine and coercion, What makes you think ?
     * WONDERFUL JOB !!! WONDERFUL ACTIONS AND INCOMPARABLE OUTCOME !!! You have done a great job !!!  Definitely !!
     * 
     * Useful as yourselves !!! The great genius nations !!
     * Bravo !!! A wonderful outcome built by not delusional people who would love to ignore consistently !! Because "THE PAST IS PAST !!"
     * 
     * You see the great decisions !!! OMFG !!! You must be the best of da best from the universe !!
     * Very very genius decision making performance FROM THE WEST !! Not delusional at all !! Only a few ten years !!!
     * Get wumen muney !!
     * 
     * Foolin foolin genius nations !!! FROM DA WEST !!
     * What a beneficial and useful outcome built by the very genius western disgusting animals !!!
     * 
     * Foolin medicine sleeping coercing sleeping TO CHILDREN eheheheheh, Australia ahhahah australiaa eheheheh good job !!
     * Germany eheheh france hehehehe england Great genius nations !!! Together for making absolutely nothing !!
     * 
     * Only a few ten years of nothing !! Not marvel at all !! Not delusional at all !! Perfect !!
     * 
     * The true geniuses of the universe !! Makin decisions and assumptions for other people who they do not care !!
     * What a lovely outcome indeed !! GO GALS!!! You are the best !! OF THE BEST !! I AM NOT INTERESTED
     * 
     * Little disgusting animals !! Nice job !!
     * 
     * The true and only genius nation on the surface of earth !! THE WEST MAKING GREAT DECISIONS and trying miserably to hide !!
     * OMFG !! what could be the problem !!! Wonderful actions and the outcomes !!!! Waaaowww
     * 
     * Eheheheh just a few ten years, its fine so long as nobody knows !!! Its okay !!! forget about the past !! eheheheh genius west!!
     * A wonderful job and outcome indeed !! Great ppl
     * 
     * Ehehe medicine etc ehehe coercion eheheheh scary eheheheh a few ten years etc ehehehe
     * Definitely good job !! Wumen wumen muney genius delusional west ehehehehe
     * 
     * Da best of da best !! Lovely outcome builders !!! eheheh
     * Carsssss, wumeennnn, muneyyyyyyy, coerced drugsssss, coerced sleepingss for a few yearsss because THE GENIUS WEST !!!!
     * 
     * Makin really reallly important outcomes !!!
     * Guess who is not interested in your disgusting lies !!! Wowwww indeed
     * Eheeheheh fun and reasonable stuff !!
     * 
     * I AM NOT INTERESTED IN YOUR DISGUSTING ANIMALITY, !! You go on deluding
     * Perfect approach !! wumen wumen eheheheh muney cars ehehehehe life simulation eheheh genius west !!!
     * 
     * Not interested thanks, remind yourselves THE TRUE MEANING OF LIFE !! The meaning you choose to live !! WHAT AN OUTCOME !!
     * 
     * I WILL NEVER BE INTERESTED IN ANYTHING YOU CAN OFFER !! Thanks !! You can get the fuck out of my face!!
     * 
     * Keep the most disgusting violent actions between "FAMILY" eheheheheh
     * Forget about the past ehehehehe eheheheheh
     * 
     * Eheheheh WRONG ASSUMPTIONS !!! AND NOT YOUR DECISIONS !!! ITS TOO LATE !!!
     * Like the wrong assumption of "ehehh say some nice stuff he will feel okay !! THATS MY JOB!!!"
     * Like the wrong assumption of "eheheh he will forget and forgive eheheheh"
     * Like "life a simulation !!!!"
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN PROVIDE, hope that makes sense !! Good job ! You are the world's best society !! Genius west 
     * can GET THE FUCK OUT OF MY FACE INDEFINETELY
     * 
     * Like the wrong assumption of "wumen wumen muney get muney that solves everything !!!"
     * Ehehehehe sleep some eheheh sleep eehheh medicine ehehehe coercion eheheheh
     * 
     * The best of the best indeed, NOT INTERESTED
     * Like the wrong assumption of "ehehe runnin experiments eheheheh forget about the past please !!!"
     * 
     * GET THE FUCK OUT OF MY FACE, eheehhe drugging indeed !!
     * Eheehhe holiday holiday ehehehehehehe eheeheheheheheheh making decisions eheheheheheheh Really realllyy nice and clever stuff !!
     * Just a couple of ten years WONT HURT ANYBODY,
     * 
     * Get some holiday eheheheh
     * I am not interested in anything you can offer
     * Like the a couple of ten years that have resulted in NOTHING, thats who you are !! Good job !! Offer more FROM OUT OF MY VICINITY
     * 
     * From out of my vicinity indefinitely, I am not interested, do what you will, I AM NOT INTERESTED IN DISGUSTING ANIMALS 
     * 
     * Ehehe wumen wumen muney offerers can not see something BUT WHAT ?
     * Eheheheheheheh, good job !! 
     * 
     * Move on ignoring please, I AM NOT INTERESTED, good job though anyone would congratulate you all !! The best of the best !!
     * Good job !! The real deal gangsta genius nation people !! GET THE FUCK OUT OF MY FACE
     * 
     * Life a game no life a simulation no no, get wumen and muney !! eheheh holiday eheheheheh MAKIN MAKIN DECISIONS !!! Ayyyy
     * Get cars eheheheh Get wumen get muney, life a game no no life a simulation !! NOT INTERESTED
     * 
     * 
     * NOT INTERESTED IN ANYTHING YOU CAN OFFER, good job !!
     * Wonderful outcome !! The real genius west !! Guess who is not interested in tens of years gone to nowhere eheheheh !!! 
     * You know the answer never ask, come up with a betta scenario THE REAL GENIUS WEST !!
     * 
     * Ehehehehe life a theater no no life a game no no life a simulation, nooo life is "GET WUMEN GET WUMENN MUNEY MUNEY CARSSS GTT "!!!
     * Ehehehe only tens of years ITS NOTHING !!! Wonderful outcome !!
     * 
     * eheheheh hehehehehehhe funny stuff !!
     * Eheheheh guess what would ehehehe The true genius nation can make a few guesses, ITS FINE 
     * Yayyyy
     * 
     * Ehehehehe wumen wumen muney life time does not exist eheheheheh genius BTW !! Yayyy
     * 
     * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!
     * 
     * 
     * 
     * 
     * 
     * 
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!* Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * * Hopefully now you can see WHAT WILL BE THE DECISION !!
     * 
     *
     * 
     * NOT INTERESTED
     * Very very talented people, genius engineers CAN GO ON FROM OUT OF MY VICINITY, I do not have anything for you
     * Keep reminding yourselves the "DESTINY" part !! Da numba on west GENIUS NATION !! I am not interested
     * 
     * NOT INTERESTED IN ANYTHING ANY OF YOU CAN OFFER, ehehehe live your lives !!! life already a game !!! eheheheheh
     * We makin decisions eheheheheh disgusting animals can get the fuck out of my face
     * 
     * Not interested, Move on
     * Wonderful job !! Great west !! Genius society !! Yayyy
     * 
     * Coercin medicine as always !!! Yayyyyy expecting reasonable actions !! yayyy geniussss nation!!! I AM NOT INTERESTED
     * Disgusting western animals you do not say ? Aww you say, forget about the past eheheheh please do not fire up any place hehehehe
     * 
     * Ehehe anyways, more medicine and nothing !!! GO GALSS !!! You are the best of the best !!!! Disgusting little animals, not delusions 
     * Ehehe no delusions just a few ten years, Thats the way to go !!!! The true genius society !! DA WESTERNS OMFGGG !!! Numba on !!
     * 
     * Perfect outcome !! Move on from out of my vicinity !! Ehhehehe great western animals !!! 
     * Ehehehe universe talkers ehheheh decision makers eheheh life advicers eheheheh REAL GENIUS SOCIETY FROM DA WEST !!!
     * Number one !!!
     * 
     * What a lovely outcome indeed, from the very geniuses of DA WEST !!! Great job !!
     * Eheheh offering holiday wumen muney cars however life not a game !! a simulation not !! OMFG !!
     * 
     * Lovely outcome, I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * Eheheheh especially the destiny part ehehhe Really realllyy beneficial actions !!! MORE DRUGS and it will be fine 
     * 
     * Eheheheh usa usa !!! europa eheheh yayyy making decisions ahahahahah ehehehheeh, coercing drugs eehheheheh 
     * The best of da best !!! NOT INTERESTED
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
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