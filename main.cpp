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
     * Waaaowww, what a great experience and opportunity !!! go galsss forever ayyy
     * 
     * Ayyyyyy, you have done it !!!! thats success
     * 
     * HIGHWAYYYY AYYYYYYY, disgusting inferior animals
     * Ayyyyy, makin decisions aaayyyayayaya
     * 
     * Codin codin makaveli genius eu coungtry ayyy ahahahha
     * Ayyyyyyy making the impossible ayayayay the western genius ayayaya the western wayy awwwwwww goood jobb !! go galss for avar !!! yaaaa
     * 
     * 
     * 
     * 
     * Ayayayayay definitevly the best of the one of the best, you all have no competitors goood really goood fooling !!! ayyy
     * Youcan get the fuck out of my face INDEFINITELY!
     * 
     * THE BESTTT AYYYYY
     * 
     * Offferin muney muney wumen wumen !! ayayaya good job !! the advanced ppl saviors
     * Looooking at the results ayayayay, you have done a wondeful jbo the good county eu !!! ayyyy
    */

    InitWindow(500, 620, "Raylib Tetris");  
    SetTargetFPS(60);

    // Grid* grid = new Grid();
    // Level* level = makeLevelSingleton(2);
    // InputTerminal* terminal = n ew InputTerminal();    

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