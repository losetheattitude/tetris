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
     * Bravo !!!! You have done a wondaful job !!! what a great achivement and lovely chance with also some great great wise assumptions and decisions !!
     * Stupid disgusting animals indeed, wumen wumen muney muney puwer get cars mansion yayyyy we do not care!!! ayyy
     * 
     * Medication genius ppl ayyy marvel delusions ayyy
     * Definitely way to go, lovely chance genius nation, wise ppl etc, CAN GET THE FUCK OUT OF MY FACE
     * Makin assumptions, ehehehe YOLO !!! OMFGGG DA NUMBA ON WEST MAKING DECISIONSS !!! Lovelyyy
     * 
     * Quiet successful actions by the genius nation of da universe the great wise western civilization marvel imaginations great professional workers !!
     * Lovely actions indeed, What else could you be doing !! AYYYYY
     * 
     * Definitely genius ppl !! Woowww
     * Savioring da world by da very genius society ppl DA WEST, OMFG !!! Lovelyyy, get wumen muney genius nations !! OMFG!!
     * 
     * BRAVOO !!! What a wonderful job !!
     * Very very accurate and wise assumptions a clear sign of quietttttt the high intelligence THAT YOU ALL POSSESS OMFG !!!
     * What a lovely chance !! GO GALSS !!!! Da numba on society of da universe !!! great ppl
     * 
     * 
     * Da almighty all knowing genius societal disgusting animals, makin reall reallly wise assumptions and decisions using their 
     * superior abilities !! FROM OUT OF MY VICINITY
     * 
     * Ehehehehe really really clever ppl, makin assumptions and never lookin back, OMFGGG !!! What a lovely chance !!!
     * YOU CAN GET THE FUCK OUT OF MY FACE ! Brilliant ppl !!
     * 
     * 
     * Saved da whole world !! a blessing indeed to be AUROPEAN OMFG!!!!! Act okay !! Go away
     * Da almighty all knowing genius societal disgusting animals, makin really accurate assumptions and actions !!
     * GO FOR IT !!! 
     * 
     * Who could have guessed it !!! What a wonderful job and outcome !! You can get the fuck out of my face INDEFNITELY
     * Trickin and geniusing and wising really reallly good society and wonderful contitent ppl !! da western ppl da very best of the universe
     * makin assumptions, GO GALS !!
     * 
     * Eheheheh crisis management, wise nations, skilled genius animals ehehehe preemptive ehehehehe really wise ppl from da west !! OMFG !!!
     * Best of best decision and assumption makin machines FROM DA WEST !!! The most modern and advanced animals OMFG !!!!
     * 
     * From out of my vicinity 
     * Wonderful !!! you are the best ! you can now get the fuck out of my face
     * muney muney wumen ppl, wise definitely
     * 
     * Really skilled AND "WISE" ppl who coerce and scare little kids into believing ahahahh
     * Right ? That sounds too accurate !! OMFGGGG !!! Da numba on from the universe, Da great wise western disgusting animalss !!!
     * makin muney wumen assumptions decisions !!!! YAYYYYY
     * 
     * What a lovely chance !! 
     * You are not wanted ? Is that a coincidence eheheheh
     * Really skilled though, you can move on getting the fuck out of my face disgusting little western animals
     * 
     * Incredibly successful and well guessed assumptions !! wowwww
     * Ehehehe scaring coercing sleepin children eheheheh
     * Ehehe runnin experiments ehehehe druggin little kids eheheheheh wondaful nations from da western !!! Ayyyy
     * Wumen muney ppl, eheheheh delusioning eheheheh uffering eheheheheh 
     * 
     * Ehehehehe doin our jobs !! da saviors of da western great civilization genius ppl doctors phssyicispy psicologieis OMFG !!!
     * Especially, druggin kids and coercing and threatening eheheheheh and also some genius civilization talents OMFGG !!! lovely chance
     * 
     * Da outcome builders and sleepers, From da most advanced civilization, DA WEST
     * Wonderful decisions !!! You can get the fuck out of my face
     * 
     * The very most talented people of the 21. century makin assumptions !!! druggin coercing scarin children !!! OMFGG
     * What a lovely outcome !!
     * 
     * Ehehehe doin their most crucial jobs !! OMFGGG  Eheheheheh the western genius civilization ppl can GET THE FUCK OUT OF MY FACE indefinitely
     * Ehehehehehehehehehehehehehehehehe, wise clever ppl, not interested in your disgusting stupid "experiments"
     * 
     * Bravooo to you alll !!! you are marvelous !!! imagination stories all thatt !! you all the numba on !! the western disgusting animals !!
     * GO GALS!! Ehehehe sleepin makin assumptions, druggin eyyyyyyyy scarinn eyyyyy genius nation eyyyyy da west !!!
     * 
     * 
     * 
     * Ehehehe 21 21 21 21 yayyy we manipulate tech eheheheheh and feel skilled and talented at doing so messin with ppl
     * druggin scaring coercin children manipulating tech feeling intelligent, muney muney wumen !!! yayy
     * 
     * Good job !! Wondaful ppl from da west !! the whole mighty knowing good qualities !!! da best of the universe!!
     * Wise and genius engineerings !!! YOU CAN GET THE FUCK OUT OF MY FACE
     * 
     * Eehehhe especially sleeeping ppl and drugging and coercing and scaring eheheheheh
     * Lovely chance and outcome, whole mighty and knowing genius delusioning ppl !!! waaaowww
     * 
     * Definitely useful, you can go from out of my vicinity, I am not interested
     * Ehehehehe, a wonderful chance to do absolutely nothing but harm eheheheh Go the genius nations FROM DA WEST !!
     * 
     * Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!
     * 
     * * Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!
     * 
     * Wonderful !! Definitely worth 30 years !! Definitely the way to go !! Look at all the benefits YOU HAVE ALL ACHIEVED DOING NOTHİNG !!
     * Eheheh had to be ehehe etc had to !! ayyyy the very advanced society!!
     * 
     * Number one !!! the best !! very wise and clever people !!! assumptions and decisions !! That were not YOUR PLACE !!! GO GALS !! Da number one 
     * I am not interested in anything you can provide, go back to your delusions marvelous ppl
     * 
     * Good reason!!! Perfect execution !!! very skilled and talented delusional ppl !! you can go away, I am not interested
     * Really skilled amazing people !!! Ehehehehe its fine !!
     * 
     * Really reallly serious and businesslike people not givin a fuck about WHAT IS NOT THEIR CONCERN and actin cool !!! OMFG !!!!
     * You have done it !! Ehehehe wumen wumen muney !! Really good job !
     * 
     * Tough and wise and clever people, da unique western society !!! The most useful sequence of actions !! Go gals
    */ 

   

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