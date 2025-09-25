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
     * 
     * NOOOOO THANK YOUUUU !!! I AMMA PASS AYYY the genius nation euw !! ayyyyyyy 
     * 
     * YOU HAVE DONE IT !!! THE BEATIFUL EUW AYYYY Ayyyyyyy gooo gals!!! forava!!!
     * 
     * Disgusting little animals
     * Eheheheheheh coercing little kids as little disgusting animals ahahahah ayyy the beatiful west
     * 
     * Da great great solution makers genius nation makin decisions ayy you can get the fuck out of my face
     * Ayyyy the great great great euw makin plays beatiful country beatiful ppl OMG
     * 
     * The best of the best ppl genius engineering countries of converged ppl ayyy what a beatiful scenery !!!
     * Da big west !!!
     * 
     * The biggest intelligence west da problem solvers genius engineers CAN INDEFINITELY GET THE FUCK OUT OF MY FACE
     * DA ASSUMPTION AND DECISION MAKERS!! the beatiful ppl !! ahyyyyy gooo west
     * 
     * DA BEATIFUL PPL DELUSIONAL AYY DAA WESTT
     * 
     * Little disgusting delusional animals that think they are great at everything ? DONT YOU SAY
     * AYyyyyy lets abuse children !!! ayyyyyy genius engineers
     * 
     * The unbeatable great genius nation of da world!! THE GREAT EUW awwww
     * Stupid dumb disgusting delusional animals WHO I WILL AVOID INDEFINITELY
     * DA GREAT DECISION MAKERS AYYYYYY SAVIORS OF DA UNIVERSE!!!
     * 
     * Disgusting little animal blood delusional animals ayyyyyyyyyy 
     * What a wonderful job !!! from da west westt wildd genius engineerings ayyyy
     * 
     * Da very very genius usa euw engineers ayyyyy what a lovely thing !!
     * You can get the fuck out of my face indefinitely
     * 
     * Disgusting ayyyyy da best of da best of da universe and world !!!
     * 
     * 
     * Ayyyyyyyyyyyyyyy da best of da best solution makers and decision makers genius euw!!! waaaowwww
     * What a lovely outcome !!! ayyyy what a great society I just can not wait to get involved ayyyyyyy
     * 
     * Btwww, please dont talk about it !!! please !! ayyyy genius engineer nations !!! do not talk about what we have done ayyy
     * 
     * Da biggest of da best of da best makin decisions and plays ayyyyyyy WHAT A LOVELY THING !!
     * The great great outcome builder ayyy GET THE FUCK OUT OF MY FACE INDEFINITELY
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