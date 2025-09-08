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
     * Eheheh bugati bugati wumen muney materials ayayayayaya gogogog genius !!! nation west the best ! ayyy
     * Makin impossible possible ayaayayay FROM OUT OF MY VICINITY
     * 
     * The carsss ayyyy the carss and movies andd muneyy and wumennn ayyyyyy the westt the besttt engineerrss ayyyyyyyyyyy
     * 
     * GOOOO GALSSSS OUT OF MY VICINITYYY !!! ayyyyyyyyyy
     * DA BIGGEST INTELLIGENTTT AYYYYYY VICILIZATION ayyyy"
     * 
     * whats ddone is done ayayayya we must trick somehow !!! ayy this time how we trickin ayyyyyyy goood gooodd genius very nation
     * FROM OUT OF MY VICINITY ayyy
     * 
     * HAD TO BE HARMED AYYYYY 
     * MOVE ON AYY
     * 
     * NEVER EVER TRY TO BRING IT OUT !!! THE GREAT GREAT WESTERN CIVILIZATION AYAYAY THANKS, I WILL PASS
     * THE GREAT GREATTT WESTERN WUMENNN MUNEYY CARSSS MANSION AYYYYYY, NO THANKS
     * 
     * DISGUSTING PPL ARE NOT AWAKINNING AYYYYYY
     * NO THANKS
     * 
     * THE GREAT GREAT INTELLIGENT SPECIES OF UNIVERSE SAVIORING EVERYONE, NO THANKS !!!! 
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