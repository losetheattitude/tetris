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
     * 
     * Dont even hesitate to enjoy your selfish and miserable existences while what is happening can not be explained and does want to
     * be even looked at avoiding the reflection on the mirror to see yourselves as what it is. Inferior, vile, selfish, undeveloped animals
     * without a reasonable explanation as to their "decisions" and just after the feeling of being someone. I am not alike and thank you for
     * your attempts to turn me into the precise vile animals that you are. "The decision have consequences" eheheh whats the consequences again ?
     * Do you think you are still playing a game and while also someone is in such a state that you can not even speak about together with the
     * "past" that you are always referring to ? And you are there with your incomparable greatness, enjoying your disgusting stupid existence
     * with the most dumb game that you have made others to accept ? Do you think I am unable to distinguish between fate and decision ? The decisions
     * that you have all been talking about nonstop without the notion of notion ? eheheh poet, eheh mathamechejk ehehe gamer eheheh atleete ehheh.
     * I ought to see your emotional sides as well when it is you. When it is the early 20 years of life versus your 50 to 70 years of life.
     * Which is heavier than which ? You can not equate your miserable 50-70 with 18-28. Whats next then ? Women ? My bad, its violence :d
     * Dont even waste any second acting on what you are
     *       
     * Say something good, he will start feeling okay, he is this he is that, he does not know anything, that must be enough eehgehge
     * we understand shittt, he ll either probably forget or he is not conscious enough to retaliate adhefhhfeh we good and great and intelligent
     * Before I see who is "responsible" for this being in the same if not worse condition, rightfully so without any significant explanation or
     * reason to perpetrate, I wont change the way I think even for a second
     * 
     * I havent asked for your opinion or knowledge. Pay attention to your disgusting lifes and stay away
     * 
     * Are you still talking about whats life ?? whats happiness ?? ehheehe I told you to remove your disgusting consciousness from out of my surroundings
     * Your existence is the unhappiness for me, your existences' decisions and just the things like this I have been talking about is the main reason
     * 
     * Why arent you happy ? You have everyyyything you could ever need right ? You are being displayed the most generous and noble way of 
     * behaving by the people around you ? Why arent you happy ? eheheh the life bro, its lifee, you have to be happy ehehegvegh
     * 
     * You have every resource or whatever you could ever need, everr, like everrrr. Why arent you happy that you have countless number of 
     * people around you that have no good feelings or intentions about you and with every opportunity you are being intervened by totally stupid people
     * with unjustifiable or unreasonable intentions ? You have the most perfect reasoning yet you can not see things for what they are ?
     * Just go on to your jerking offs, nobody has even asked what you are thinking. 
     * 
     * The only thing you can say is entirely similar to what the most average middle eastern people will say. You are inferior and I have never been in the
     * mood of accepting what has been proposed with incompetent minds 
     * 
     * You dont even understand anything about life, How dare you ask questions about things you can not answer for ? Your misunderstading is
     * where you take me as others and hoping whatever you have to say will work regardless of its sincerity or accuracy. You can just do that with
     * people who is so underinformed as to blindly follow as they will do for every other
     * 
     * You can not really convince me to why you are right or you had to, or it is entirely usual and there could be nothing in exchange for such
     * and such
     * 
     * You totally look like a selfish prick when you start talking about "the life"
     * 
     * Its not even remotely okay, make sure what you are hiding behind is as impermeable as ever 
     * 
     * For whom are you making decisions ? For whom are you violating every single rights of an individual with nothing to support your
     * disgusting behaviors ? Not even excuses can be seen as viable, that is the point where you brought your insignificant existences
     * 
     * Am I the one who is doing all these ? I am talking about, years, not months not weeks, havent even started talking about the violence
     * 
     * Are you still reading and jerking off ? Go watch some sheeps being sacrified may be that way you can find peace, not from me
     * not ever
     * 
     * Do you believe I am in the mood of taking your bullshit behaviors ? what sort of logic tells you that I will have the desire to
     * listen ? 
     * 
     * You still cant beat your disgustings inclanations ? The point being is, you are already asked not to do nothing. Dumb monkeys
     * You pay attention to your own lives and try not to think too hard on the "past" eheheh we wanna do that, we just have to hehe
     * global problem eheheh 
     * 
     * Delusional ? Wasting selfishly not a resource but the time of such an importance that belongs to an individual you have no
     * rights over and expecting to be received regular and no obligations or such can be raised ?
     * 
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