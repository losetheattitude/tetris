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
     * Ayyy da lovely ppl !! what a great doing !!! ayayy you have guessed it !! and done it !!! ayyy
     * Genius engineering and wise ppl with a great great culture !!! and an immaculate understanding of life!!!
     * life a game ayaya life a simulation ayaya get wumen get muney ayaya get materials eheheheh time does not exist !!! 
     * 
     * Kid abusing genius nation ahahah some failure of engineerings ayayaya
     * 
     * Great greattt job !! ayy
     * Disgusting animals btw !! aayaya
     * Intelligent ppl foolin jokin kids ayayaya genius engineers!!! go galsss
     * 
     * Da big decision makers from the wild wild disgusting kid abuser west ayayaya intelligent ppl eheheh
     * Da usa usa ayyaya makin good, engineer genius nation advanced developed ppl !!! go gals from out of my vicinity ahahah
     * 
     * 
     * Da western bois ayyyy cool as fuck go gals !! FROM OUT OF MY VICINITY
     * Disgusting delusional monkeys who deny for the sake of denying ayyyyy, thats genius engineerings GO GALS !!! DA NUMBA ONE !!
     *
     * wAOOOWWW DA GRREATEST WESTERN CIVILIZATIONS MAKIN IMPOSSIBLE POSSIBLE AYYYYY, do not even mention
     * 
     * IMPOSSSIBBBLEEEE TO BE EVEN SLIGHTLY ASSOCIATED with the most great civilization of the universe!!!  AYYYYYY offering wumen !!!
     * the great genius !!!
     * 
     * The most professional intelligent human beings of all the universe !!! offerin wumennn ayyyyy
     * 
     * IM-POS-SIB-LE !!! ayyyy 
     * 
     * THE MOST GREAT AAYYYYYYY
     * NO THANKSS AYYYY what a great outcome built by the very very genius nations ahyayayayay
     * 
     * Ayyyy the greatest of the greatest victories done by the very genius ayyyyyy
     * 
     * Eheheh bugati bugati wumen muney materials ayayayayaya gogogog genius !!! nation west the best ! ayyy
     * Makin impossible possible ayaayayay FROM OUT OF MY VICINITY
     * 
     * The carsss ayyyy the carss and movies andd muneyy and wumennn ayyyyyy the westt the besttt engineerrss ayyyyyyyyyyy
     * 
     * GOOOO GALSSSS OUT OF MY VICINITYYY !!! ayyyyyyyyyy
     * DA BIGGEST INTELLIGENTTT AYYYYYY VICILIZATION ayyyy
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