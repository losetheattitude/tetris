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
     * rights over and expecting to be received regular and no obligations or such can be raised ? How come you have made yourselves believe into this
     * bullshit ? Telling you over and over again, you can not convince me with your bullshit make up excuses. 
     * 
     * Am I going to thank you afterwards ? You all, directly ruining, not even saying intervening, someone's life ? and expect what in return ?
     * Or what do you think you deserve ? With which audacity you are to joke towards someone you do not even know ? 
     * Who has not even had no prior exchanges ? Who hasnt even said anything good about you ? With which precept are you to joke with
     * your insignificant and disturbing approach ? Who are you to involve your harming existence then start joking or consider it to
     * be okay ? 
     * 
     * Dont you follow ? Whether you smile and act like its nothing for eternity, it will not make a dime of difference. Every one has their 
     * excuses to follow what appeals to their animals. Now compare the incomparable to arbitrary. Do your math
     * 
     * Are you afraid to talk about your decisions and the consequences ? You dont have anything else to do ? Still arguing over someone else's course ?
     * Referring to past exercises, are you willing to garner an environment which is similar to past ? 
     * 
     * I must be the most grateful to be practicing the most basic physical interaction whatsoever and get along just fine. 
     * 
     * Are you completely blind or just flat out inferior to not perceive that this approach is only and only towards you.
     * 
     * I dont want to have anything related to any of you
     * 
     * None of you has ever moved a finger for me, towards the so called "future" of someone you are voluntarily ruining ? 
     * Now is this the part where I take you for someone I can count on ?
     * Is this the part where you gather as many soothing words as possible to free yourselves once again from 
     * implicating yet intentional decisions ?
     * 
     * Are you asking questions about the past that I have been through ? Is your logic failing because of I or your
     * incompetency on weighing the rationals of an individual ?
     * 
     * What could have possibly happened in the past that we have neither an idea nor an understanding of such a culture and its
     * dynamics ? Am I the one who is throwing around random accusations such as "selfish" or is that you ?
     * 
     * Do not make assumptions especially the ones you do not believe yourself like he is happy or some bullshit
     * I care about the experience and results just as you all crave as well ? What would be your reaction ? Yeahhh, special etc blabla disgusting animals I say
     * 
     * 
     * You are nobody, are you still perverting into others' course of life ? With nothing you have could cover anything you have done ?
     * I will pass under whatever circumstance or any sort of bullshit excuses that you have so far generated as if it takes a 
     * great amount of skill and hassle. 
     * 
     * EHehe, we see everyone as we see ourselves so, a holiday must be more than what is enough! Whats the meaning of life ? Isnt it ?
     * We have no understanding of "life" so is our great reasoning! The incomparable holiday proposed by dumb monkeys
     * 
     * 
     * Look for more words. Words that dont have no substance at all, just as useless gestures.
     * Are you low enough to think that I am not aware of the fact that whatever you are proposing as infallible is a mere relativeness of the
     * present moment and a disgusting projection of your "properties"
     * Just bunch of regular people that I am sick of interacting with in my daily life. There is not even the tiniest difference between you
     * and some random individual on the street that just wants others to accept how they see things or happened them to be situated which
     * just tells me that the whole "process" is only arbitrary, no reason has ever been included. 
     * 
     * Continue deluding I am far from where you are as an individual hence the calculated positioning
     * 
     * Believe you can time travel, what could go wrong
     * He ll believe, we are just playing a game as far as we are concerned. Itll be fine. Our reasons are more than obvious so will theirs eheheh
     * Its just entirely good,
     * 
     * Dont stop watching stupid movies that are fictional and look harder around not to feel inferior
     * Your incompetent excuses will not cut it. You are effectively forcing someone change into something that you are miserably afraid of while
     * you are making claims. How inferior and stupid a group can get ?
     * What sort of sick image have you generated as to believing that I will accept what is apparently unnatural over what I could have garner
     * naturally ? Do you take your values to be so great ? There is no course you can switch into
     * You have to suffer voluntarily in order to obtain what you are lacking while praising to contain. Yeahh poet etc
     * 
     * I will gladly assume the position that you are manifesting to come around. Thats your choice as you can infer
     * 
     * What you have been doing can be described as Thanos ? You can not compare as well as reason ? Not even lying properly ?
     * Do I smile ?
     * 
     * Do you compare what is usual to what can not even be named as acceptable ? The holiday ?
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