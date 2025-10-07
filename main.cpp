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