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
     * 
     * Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!
     * 
     * 
     * * Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!
     * 
     * * Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!* Almighty assumption making wise and all knowing immaculate great cultured civilization
     * DA BEST OF DA BEST OF THE UNIVERSE, DA WEST !! WHO WOULDNT LOVE TO BE INVOLVED !!!
     * 
     * THE TRUE ROMANS AND GANGSTAS AYYYYY makin assumptions !!!
     * 
     * Offeringgg wumennn muneyyyyyy for the failed assumptions ayyyyyy
     * What a great outcome built by the very genius phsysists and engineers and psycologists ayyyy
     * 
     * What do you think it is ? Ayyyyy you have done it !!
     * 
     * 
     * 
     * 
     * 
     * I WILL PASS WITHOUT HESITATION
     * MOVE ON TO YOUR SUPERFICIAL MOVIES THAT YOU MISTAKE THE REALITY FOR LIKE TRUE GANGSTA THEY ARE
     * REAL BADASS PEOPLE FROM DA WEST
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