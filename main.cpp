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
     * DISGUSTING LITTLE DELUSIONAL ANIMALS CAN MOVE ON TO OUT OF MY VICINITY ? Does that make sense ayahyaya ??
     * WUMEN WUMEN MUNEYY LIFE CARS ANIMALS CAN GET THE FUCK OUT OF MY FACE INDEFINITELY
     * 
     * DA WEST DO NOT CARE ANYTHING BUT HIMSELF AYYYY GENIUS
     * THE BEST OF THE BEST CIVILIZATION MAKING DECISION THAT WERE NOT ASKED AYYYYYYYYYYYYYYYYYYYYYYYY
     * SO FUN !!
     * 
     * 
     * Disgusting little delusional animals, you can go
     * The great great chess players of the universe savioring the planet from ppl !!! go genius nation, I AM NOT INTERESTED 
     * 
     * The great decisions makers yet consequence ignorers, I WILL NEVER BE INTERESTED IN YOUR DISGUSTING ANIMALITY
     * The great decisions makers yet consequence ignorers, I WILL NEVER BE INTERESTED IN YOUR DISGUSTING ANIMALITY
     * The great decisions makers yet consequence ignorers, I WILL NEVER BE INTERESTED IN YOUR DISGUSTING ANIMALITY
     * 
     * Disgusting delusional animals ?? AYyyy offerin wumennnn wumeennnnn carssss ayyyyy time does not exist!!! we the greatestt ayyy
     * I WILL NEVER BE INTERESTED, ayayyaya Good genius nation making decisions and ignoring everything else !!! what a combination I WOULD LOVE TO INVOLVE
     * 
     * THE DISGUSTING DELUSIONAL "EU" PEOPLE making impossible possible and ignoring the outcome !!! ayyy geniuss !!!! numba on genius civilization !!!
     * 
     * THE DELUSIONAL ANIMALS MAKIN DECISIONS AYAYAYAY WHAT COULD GO WRONG !!!! go galssss forever
     * MAKIN GENIUS DECISION THAT IS NOT YOURS AYYYYY, go forever eheheh funny and genius 
     * 
     * Ayyayayayy eheheheh so funny !! so funny !!! we made it!! we have done it !!! we the genius nation delusionals aayyayay
     * 
     * ITS DONE FOREVER Ayayayay go gals !! you da best of the best 
     * Ayyyyy, THERE IS NOT A CHANCE ON THE SURFACE OF UNIVERSE !!! YOU HAVE DONE IT !!! THE REALLL DEALL GANGSTAS !!! DA NUMBER ONE WESTTT!!! ayytyty
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