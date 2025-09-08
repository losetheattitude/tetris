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
     * 
     * ITS DONE !!! IT WAS ALREADY DONE !!! You are just to perfect to not see it !! ayyyy the greatest intelligent organizm ayayay
     * 
     * Ayyyyyyyyyyy the best of the best !!!! engineering geniuses !!! from the planet earth !!!! the saviors of the universe !!!!
     * DELUSIONINGG !!! ayyyyyyyyyyy you can get the FUCK OUT OF MY FACE INDEFINITELY !! 
     * 
     * 
     * THE MOST ORGANIZED THE MOST GENIUS THE MOST ADVANCED THE BEST OF THE BEST NATION ON THE UNIVERSE !!!
     * YOU GOT IT !!! Ayyyy you have done it !!!! congratljuations !!! ayyyyyy
     * 
     * 
     * Ayyyyyyyyyyy go galss !!!! you da best !!! ayyyyy the most intelligent !!! ayyyyy you have done a wonderfuul job !!! ayyyyyy
     * 
     * Really realllyyyyy genius nation !! ayyy
     * 
     * Go back to your stupid artificial movies YOU DA BEST !!!!
     * BACK TO YOUR DISGUSTING ARTIFICIAL MOVIES AND DREAM ON
     *  
     * Go back to your stupid artificial movies YOU DA BEST !!!!
     * BACK TO YOUR DISGUSTING ARTIFICIAL MOVIES AND DREAM ON
     *  
     * Go back to your stupid artificial movies YOU DA BEST !!!!
     * BACK TO YOUR DISGUSTING ARTIFICIAL MOVIES AND DREAM ON
     * 
     * Go back to your stupid artificial movies YOU DA BEST !!!!
     * BACK TO YOUR DISGUSTING ARTIFICIAL MOVIES AND DREAM ON
     * 
     * Real gangstas only born into EU !!! the europa genius civilization !!! ayyyy gangstass !!! go galss
     * More like disgusting animals who would love to IGNORE EVERYTHING ayyyyy go gals I AM NOT INTERESTED
     * 
     * DREAM ON DISGUSTING DELUSIONAL EUROPEAN ANIMALS WHO LOVE MAKING DECISION THAT ARE NOT THEIRS AYYYYYYY
     * Ayyyyy get wummenn wumenn carss muneeyyy for 30 yearss we good !!! 
     * 
     * GET THE FUCK OUT OF MY FACE, DISGUSTING LITTLE ANIMALS
     * Thats it !!
     * 
     * DA BIGGEST GREATEST ENGINEERS OF THE UNIVERSE AYYYYYYYYYYY MEDICATION FORCE COERCE AYYYY
     * DISGUSTING ANIMAL DREAMING AYYYYYYYYYYYYYYYYY
     * 
     * THERE IS NOT A SINGLE FORCE ON THE SURFACE OF THE PRECIOUS UNIVERSE THAT CAN MAKE WHAT YOU WANT POSSIBLE
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