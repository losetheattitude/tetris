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
     * Genius nations makin decisions ayayay GET THE FUCK OUT OF MY FACE
     * 
     * THE REALL GENIUS NATION MAKIN GENIUSS ACTIONS AYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
     * 
     * THEE REALLL DEALLL GANGSTA EU GENIUS PEOPLE !!! AYYYYY THE PERFECT HANDLING AYYYYYYY GO GALSS!!!
     * WITH A YEARS OF EXPERIENCE REAL GANGSTA GENIUS PERFECT EU !! ayyyyyyyy
     * 
     * YOU HAVE ACHIEVED IT ? AYYYYY YOU HAVE DONE IT ?? Waaaowwww what a great outcome indeed !!
     * OMGGG YOU HAVE DONE IT !!
     * 
     * Makin decisions waaoww !!! ayayay go gals!!! you da best never can be defeated ayyy
     * FROM OUT OF MY VICINITY
     * 
     * "IGNORING" consequences ayyyyy makin decisions ayyyyy go galss !!! THE BEST OF THE BESTTT GENIUS NATION !!!
     * 
     * THE EUROPEAN GENIUS ANIMALS YAYYYYYY GO GALSSS FROM OUT OF MY VICINITY AYYYYYY
     * Perfectt !!! what an outcome !!!! go gals!!! the disgusting inferior "DELUSIONAL" but european animals yayyyyy
     * 
     * WHAT AN OUTCOME !!! THE VERY VERY PROFESSIONAL GUYS !!!! AYYYYY WHAT A PRIVILIGE !!! OMGGG!!!! yayyyy WUMENNN WUMENN MUNEYYYYY
     * PUWERRR PLSSSS 
     * 
     * Ayyy doom bot ayyyy abusin children ayyy especially my own ayyy goodd job !!! the great great geniuss ayyyyy
     * OMG WE GENIUSSS AYYYYY WE DONE IT !!!! WHATS HE THINKNNNN AYYYYYYY, PLS TALK TO ME TALK TO ME !! I AM PROFESSIONAL YAYYYY
     * 
     * 
     * BRAVOO !!!! ayyyy the best of the best outcome builders ayyyy
     * Wait wait, ITS LIFE !!! LIFE A NOT GAME, LIFE NOT FAIR !! ayyy LIFE SIMULIATON AYYYY
     * 
     * 
     * Ayyyyy, FROM OUT OF MY VICINITY
     * THE REAL GANGSTA GENIUS WESTERN GUYS NUMBER ONE !!! yayyy MAKIN DECISIONSSS THAT DO NOT BELONG yayyyy
     * 
     * Not interested, indefinitevly
     * Real reall decision makers CAN GET THE FUCK OUT OF MY FACE
     * 
     * Ayayayayy years and years of "DRAMA" OMGGG !!!!! WHAT AN OPPORTUNITY !!! WHAT AN OUTCOME !!!
     * 
     * THE GREATEST OF THE GREATEST GENIUS NATIONS OF THE EU !! USA ! YAYYYY MAKIN IMPOSSIBLE THINGS !!!
     * 
     * THE GREAT GREAT JOB!!! INDEFINITEVLY GO GALSS !!
     * NEVER EVER MENTION YOUR DISGUSTING PRESENCE ayyy, GENIUS NATIONS!!!
     * 
     * NEVER EVER THINK TO HAVE THAT POWER !!! Disgusting little delusional animals is what you are
     * MUNEYYY WUMENNNN CARSSS AYYYYYYY GET RICH OR DIE TRSYING AYYYYYY GOOOO  GENIUS GUYS !!!! GENIUS NATION !!!!
     * 
     * LOOKKK AT THE WESTERNSS !!! Ayyyyyy wild wildd west !!!! geniusss ayayay
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