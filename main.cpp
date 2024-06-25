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
     * Do you think what you can not even broadly getting closed to understanding could be as simple as feeling incomparably grateful
     * to have a few women around ? Is that you ? again and again?  or Is that I ?
     * 
     * None of you can make anyone admit such a thing was necessary or was an obligation or some such bullshit. Luckily, your
     * acknowledgement of the fact grants me whatever I need for soothing 
     * 
     * Proceed with getting involved into things you can not alter the course of anymore. Just let me know when you run out of 
     * appropriate bullshit to convince such lowness to motion, that wont be a challenge for me I assure you
     * 
     * Avenger ? Mad ? Bloody ? Then he is doing nothing ? Then we were wrong ? It had to be done ? The delusion ?
     * WW2 ? WW1 ? massacres ? The individual that has nothing to do with it ? Its fine, ww2 yeah
     * 
     * Smile and say sorry, it'll all be fine. Just act like you are endeavouring and keep saying the past while smiling and
     * expect what is not worst while it has been worst for others, awww I have forgotten the major thing. Its the lifeee eehehe
     * The life is a game, or life is not fair, life is bla bla aeehehe
     * 
     * 28 years of life is not fair :ddd Get ready to be introduced with the slightest of your inferiority and vileness or
     * just get the fuck out of my face to delay your bullshit existence
     * 
     * Think of what I am proposing and what have you been doing ? I am only stating facts and desiring to deal equally with the
     * very people that have dealt with inequality with me. Not saying anything about your races or what religion you are following
     * 
     * Your capable perceptions would definitely see the difference there as you are the one without an explanation
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