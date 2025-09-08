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
     * MAKIN DECISIONS AYAY MAKIN PERFECT ACTIONS AYAY WE DA BEST WEST AYYYY
     * WHAT A LOVELY OUTCOME !!! DA BEST OF THE BEST AYYY MAKIN DECISION THEY WERE NOT ASKED FOR AYYYY
     * 
     * WUMENNN CARSSS MUNEYY MUNEYYYY GET MUNEYYY WUMENNN WUMEN ENOUGH YAYYYY
     * 
     * DA BEST OF DA BEST EUROPAEN GREAT GUYS OFFFERING WUMEN WUMENNNN MUNEYYY CARSSS AYYYY 
     * LIFE NOT FAIR ayayayay LIFE A GAME NOT A GAME AYYYYY
     * 
     * THE WHOLE KNOWING PERFECT CIVILIZATION DA WEST NUMBA ONE WEST OFFERING MUNEY MUNEYYYY WUMENNN CARSSS
     * FOR VIOLENCE AYYYYYYYYY GENIUS !!! 
     * 
     * AGE DO NOT MATTER, TIME DOES NOT EXIST, WE PROFESSIONAL PSYCOLOHGISY AND PHSYICİTIY FROM THE WORLD 
     * AYYAYY DA WESTTT NUMBA ONE !!!
     * 
     * DA BEST OF DA BEST ENGINEERINGS AND PSYCOLOGIST AND PHSYSCIST FROM DA WEST!!! MAKIN PERFECT ACTIONS !!!
     * 
     * Ayyyyyyyy !! numbe on !!!
     * 
     * THE WHOLE MIGHTY WISE CIVILIZATION FROM DA WORLD NUMBA ON IN THE UNIVERSE
     * MAKIN DECISION AYYYYYY GREAT PSYCOLOGISYST AND PHSYICITS AND ENGINEERSS AYYYYYY
     * 
     * THE MIGHTY KNOWING PEOPLE FROM DA WILD WILD WEST WASTING OTHER PPL TIME WITHOUT HESITATION !!! 
     * THE GENIUS NATION !!
     * 
     * The professional outcome builders !!!! the phsycisits and psycologisit and engineers !! ayyyyyyyyyy
     * Ignoring evidence ayyyyyy genius !!! geniuss !!! numba one civilization !!!
     * 
     * 
     * WAOOOWWW WHOLE DELUSIONAL MIGHTY CIVILIZATION BUILDERS !!! GROUP OF GENIUS PSYCOLOGIEST AND PHSYCITSY AND ENGINEERSS !!
     * WHAT A CHANCE !!!! 
     * OFFERIN WUMEN FOR UNSPEAKABLE AYYYY WUMENN MUNEYYYY CARR OMGGGGGG
     * GO BACK TO YOUR DISGUSTING DELUSIONAL MOVIES AND SATIFY YOUR DISGUSTING BRAINS THE GENIUS NATION ACHIVING ayyyy
     * 
     * 
     * DISGUSTING ANIMAL CAN CONTINUE DELUDING AND WATCHING SUPERFICIAL CONTENT MOVIES
     * ALMIGHTY WESTERN CIVIZLATION MAKIN ASSUMPTIONS AND TRYING NOT TO LOOK STUPID !! AYYYYYYY
     * GENIUS NATION !! OFFERIN MUNEY ADN WUMEN ! ayyyyyyywestern nnnnnn
     * 
     * Da numbe one assumption makers kids abuser and genius psyclogist and phsyciist also engineers 
     * with delusional superficial movie makin creative brains !!!
     * 
     * WHAT AN OUTCOME !!!
     * 
     * I am not interested in THE SLIGHTEST thing you can offer
     * 
     * The whole mighty knowing advanced modern yet assumption maker great civilization s
     * I will pass
     */



    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);
 
    // Grid* grid = new Grid();
    // Level* level = makeLevelSingleton(2);
    // InputTerminal* terminal = n ew InputTerminal();

    Grid *grid = new Grid();
    Level *level = makeLevelSingleton(2);

    // BaseStorage storage = BaseStorage();
    // BaseTransformer formatter = BaseTransformer();
    // Exchanger exchanger = Exchanger(&storage, &formatter);

    Game *game = new Game(grid, level, 0);
    CommandFactory::Init(*game);

    Terminal *terminal = new LocalTerminal();
    JoyStick *joyStick = new JoyStick(terminal);

    GameScene gameScene = GameScene(game, joyStick);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        gameScene.Draw();

        gameScene.Play();
        EndDrawing();
    }

    delete CommandFactory::GetInstance();
    CloseWindow();
}