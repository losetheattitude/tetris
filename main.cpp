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
     * Stateful joystick (indeterminate due to current command and future observer pattern implementation) to grant player 
     * limited reversing ability (checkpoints to connotate). Requires mapping of opposite commands
     * IsState queries in the game class dont comply with Open-Closed principle 
     * 
     * Know your limits and what you could request from "others" and continue living 
     * content and unbothered with your insincere guises you have formed about me amidst obscure circumstances
     * 
     * Ensure you have taken all the precautions to feel completely okay and move on with "your lifes" ehehe your lifes right heeheh
     * Quick reminder, its most important that you display some sort of unexplicable sorrow beforehand just in case 
     *  
     * 
     * Sick minds can continue sicken each other, dont mind me appreciating the both "greatness and vileness" of
     * the universe that you all talk about so much as if you acknowledge what it entails 
     * 
     * Which "property" do you think you are regarded as ? :d Tell your fucking stupid tales to others who are "naive" enough to
     * take you for someone who is credible. You are just the animal on the street with no understanding
     * 
     * Proceed with whatever your incompetent imaginations and reasons have produced miserably, believing you are achieving great things.
     * Stupid monkeys
     * 
     * You have submitted your course of life implicitly, other scenario is to kill me which I highly advise again and again.
     * It is not my concern whether you think you have a higher purpose or some sort of special bullshit. Each and every one of you
     * is liable
     * 
     **/  



           
  
    InitWindow(500, 620, "Raylib Tetris");  
    SetTargetFPS(144);            
         
    // Grid* grid = new Grid();  
    // Level* level = makeLevelSingleton(2); <    
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