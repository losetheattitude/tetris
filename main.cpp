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
     * GET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELY
     * GET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELYGET THE FUCK OUT OF MY FACE INDEFINITELY
     * 
     * Da best of da best engineering delusionss !!! ayyyyy what a chance !!! GOOOOOOOOOOOOODD JOBBBB!!!!
     * Ayayaya what a best outcome ayyyy
     * 
     * Makin makin great decisions that were not yours ayyyyyyyyy what a genius best of da best universe society !!! the genius engineers of da world 
     * Ayyyyyyyyy, GET THE FUCK OUT OF MY FACE INDEFNITELY
     * 
     * Makin great great decisions and makin outcomes that can not be explained with reason !! THATS THE GENIUS OF DA BEST AND BEST AYYYYY
     * GET THE FUCK OUT OF MY FACE INDEFINITELY, INDEFINITELY,INDEFINITELY,INDEFINITELY,INDEFINITELY,INDEFINITELY
     * 
     * Makin makin great decisions ayyayayyyy makin great great wonderful outcomes ayayaya what a chance !!!
     * 
     * Ayyyyyy da genius best of da best of da universe ppl !!!! Da greatest society of da world da best west !! ayyyy
     * 
     * Imma pass on the delusionals, da real best engineer genius problem solvers ayyy 
     * Solvin problems makin decisions ayyyy makin universe's biggest best innovations Da real ppl from da west !!! ayyyy
     * what an outcome !!
     * 
     * Da reallllll geniusss nations !!! the problem solvers !!! the decision makers !!! Theeee outtcomeeee builders !!!
     * What a result !!! 
     * 
     * The makin assumptions and decisions and outcomes society the genius best of da best ppl can GET THE FUCK OUT OF MY FACE
     * Da europaean best of da best delusionals ayyyyy who would hesitate!!! GET THE FUCK OUT OF MY FACE indefinitely
     * 
     * 
     * Da best of da best innovators who are begging ppl to NOT SPEAK ABOUT THINGSS THEY HAVE DONE ayyyyyy
     * Who would hesitate to associate!!!!  OMGGGG !!! DA WEST!!! Numba on!!!
     * Get the fuck out of my face
     * 
     * Disgusting little delusional animals who ? WHO DO YOU THINK ahahahah funny stuff !! go gals!
     * The delusional western people fooling ayyyyyy what a wonderful chance !!!
     * 
     * WHAT A CHANCE!!!! The great outcome builders !!!
     * Have you achieved it ?? Awwwww why havent you achieved it yet ?  Awwwwwww OFFER WUMEEENNNNN OMGG!!!! 
     * Disgusting little delusional animals
     * 
     * Eheheheheh wise genius engineering nations btw eheheheh
     * Doin work makin decision makin great outcome !! awwwww
     * 
     * Still deluding ? Awwwwwww what a chance indeed !!
     * Thatssss it !!!! Keep on deluding !!! ayyyy
     * 
     * You still do not say delusional euw !! ?? awww thats not the problem !! go gals!!
     * Definitely a great product that does nothing
     * 
     * You all go ignorant selfish gals, I am not interested indefinitely
     * Gang ganggg ayyyy single cell disgusting blind animals !!! GO GALSS !! you have done it !!!
     * 
     * Disgusting animals indeed, great stubborn can solve everything !!! ayyyy go gals!!
     * Wise eheheheh, outcome builder ppl ayyy
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