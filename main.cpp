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
     * A 30 years of nothing from the beginning PLANNED TO BE WASTED BECAUSE THE GREAT CIVILIZED SUPER MODERN DISGUSTING WESTERN ANIMALS
     * LIKE TO THINK THAT THEY SHOULD MAKE DECISIONS FOR OTHER PEOPLE 
     * 
     * EHEHEHEHEHEHE a 30 years of nothing because the ignorant selfish disgusting western animals like to OFFER "WUMEN" EHEHEHEHEHEEHEHEHEHE
     * Some hospital ehehehehehehe some sleeping heehehehe some drugging ehehehehehehe and raising CHILDREN LIKE THE TRUE GANGSTA THAT 
     * THE WESTERN IGNORANT ANIMALS ARE
     * 
     * EHEHEHEHEHEEHEHE, I do not have anything for the disgusting western animals 
     * I DO NOT AND WILL NEVER HAVE ANOTHER SECOND FOR THE HIGHLY DEVELOPED MODERN ALL KNOWING TRULY GANGSTA WESTERN ANIMALS
     * 
     * I AM NOT INTERESTED, now you are free to do whatever you want !! EHEHEHEHEHEH
     * Super modern all assumptive truly visionary PERFECT GENIUS WESTERN ANIMALS CAN GET THE FUCK OUT OF MY FACE INDEFINITELY
     * 
     * Hope next time you get a more dutyful person eheehehhehe
     * 
     * Disgusting western animals who like to "offer western wumen" eheheheheh and also delude on its great possibility of solving problems
     * OF 30 YEARS OF NOTHING ehehehehehhehe
     * 
     * 30 years of nothing because western animals are as selfish and ignorant as anything on earth can get
     * 
     * DO YOU UNDERSTAND WHAT I AM SAYING ? EHEHEHHEHEH
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE and you will have to use force eheheheheeheh WHAT A GREAT OUTCOME
     * Stupid dumb disgusting westerns that LOVE TO IGNORE EHEHEHEHEHHE
     * 
     * 30 years of nothing and "BUILDING" eheheheh building things heehehhehehe GREAT WESTERN INTELLIGENCE THAT IS INCAPABLE OF UNDERSTANDING THE TIME
     * EHEHEHEH 30 years ehehehehhehe
     * 
     * The true westerns HAVE ALREADY FIGURED THE MEANING OF LIFE
     * EHEHEHEHEHEHHEHEHEHE A GREAT CONSEQUENCE EHEHEHEHHEH 
     * 
     * Just making decisions because we think so eheeheheheh
     * DISGUSTING LITTLE WESTERN ANIMALS ARE FREE TO DO WHATEVER THEY WANT
     * 
     * Stupid disgusting selfish western animals WHO JUST DO NOT GET THE PROBLEM IN 30 YEARS OF NOTHING 
     * EHEHEHEHEHEH
     * 
     * 30 years of nothing into "SLEEPING ABUSING VIOLENCE AND HOSPITAL TIME" BECAUSE THE DISGUSTING WESTERN ANIMALS THINK SO
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE IN MIND, DO YOU UNDERSTAND WHAT THAT MEANS ? EHEHEHEHEHEHHE
     * DISGUSTING WESTERN ANIMALS CAN GET THE FUCK OUT OF MY FACE INDEFINITELY
     * 
     * I AM NOT INTERESTED IN ANYTHING THAT THE DISGUSTING WESTERNS HAVE
     * 
     * NEXT TIME FOOL CHILDREN BETTER AND USE MORE DRUGS WITH ABUSING
     * EHEHEHEHEHEHEHEH GOOD OUTCOME BY THE GENIUS WESTERN DISGUSTING ANIMALS
     * 
     * Fooling fooling people with uffer eheheheheheh uffers that THE GREAT INTELLIGENT WESTERN WISE ANIMALS HAVE NEVER DELIVERED EHEHEHEHEHEH
     * HOSPITAL HOSPITAL EHEHEHEHEHEHEH WHAT A FUCKING FUNNY OUTCOME !!!
     * 
     * EHEHEHEHEHEHEHEH abusing ehehehehehehehehehehheheheheehhehehe sleeping eheheheheh because we know better !!  
     * 
     * How should the wise and clever great westerns NOW FOOL PEOPLE EHEHEHEHEHEHEHEHEHE INTO 30 YEARS OF WASTE
     * BECAUSE THE WESTERNS LOVE TO DELUDE HEHEHEHEHHEHE
     * 
     * Disgusting western animals who will do anything TO MAKE PEOPLE BELIEVE INTO WHAT THEY BENEFIT THEM
     * OMG !!! EHEHEHEHHEHEHEHHEHEH HOW DO WE FOOL NOW ? eheheh offer things ehehehhe uffer things ehehehehehehhe
     * 
     * A 30 years of waste because the great western people THINK SO 
     * Love to make decisions BECAUSE THEY JUST DELUDE TO HAVE THAT RIGHT 
     * EHEHEHEHHEHEHEHEHEH
     * 
     * Offering wumennnn wumennnn AND ALSO WESTERN WUMMENNNNN BECAUSE WE THINK EHEHEHEHEHEHEHHEHE BETTER EHEHEHEHEHEHEHEHEH
     * WE KNOW BETTER THE 30 YEARS OF NOTHING TO THE WASTE BECAUSE THE WESTERN ANIMALS LIKE TO BELIEVE IN "MAKING DECISIONS"
     * 
     * 
     * Clever and wise intelligence people PRETENDING TO OFFER ONCE AGAIN !! 
     * WAIT IS IT NOT THE DEFINITION OF "THE TALENTED TRUE PROFESSIONAL MEDICAL EXPERTS INTELLIGENCE" ?
     * How about the TRUE MEANING OF LIFE ? EHEHEHEHEHHEEHHE
     * 
     * EHEHEHEHEHH the true meaning of life has been already solved BY THE GREAT WESTERN ANIMALS WHO DO NOT EVEN CLOSELY UNDERSTAND THE PROBLEM eheheheh
     * A 30 years of nothing eheheheheheh
     * 
     * NEXT TIME STICK TO YOUR DISGUSTING MARVELOUS MOVIES TO SATISFY YOUR DISGUSTING ANIMALISTIC WESTERN "MINDS"
     * EHEHEHE great engineering perfect outcome of 30 years of waste
     * 
     * I AM NOT INTERESTED 
     * 
     * I AM NOT INTERESTED IN THE SLIGHEST THING YOU CAN OFFER
     * GET THE FUCK OUT OF MY FACE, enjoy your life heheheheeereeehehhhheheeheheh
     * 
     * Truly great intelligent western animals THAT I AM NOT INTERESTED 
     * I DO NOT HAVE TIME FOR YOU
     * 
     * Spineless disgusting ignorant western animals who like to think they are doing DECISIONS EHEHEHEHEHHEHEHEHEHEHHEHEHEHEHEH
     * WHAT A GREAT OUTCOME !!! SOME HOSPITAL AND SOME DRUGS AND SOME SLEEPING AND SOME VIOLENCE AND a 30 years of waste 
     * BECAUSE YOU THINK SO
     * 
     * Disgusting western animals that are unable to COMPRHEND THE FAILURE BECAUSE THEY FEEL LIKE ITS THEIR RIGHTS TO HARM EHEHEHEHEH
     * 30 YEARS OF NOTHING EHEHEHEHEHEH
     * 
     * The great western intelligence ehehehheheheheh making making decisions because they feel like
     * EHEHEHEHEH ABUSING EHHEEHEHEHEHEHHEHEHEHE
     * 
     * Use more drugs next time ehhehehehehheh
     * 
     * Disgusting little western animals who take life for a joke 
     * 30 years of waste because you feel like hehehjeheheheeeheeeheheeheeh
     * 
     * I do not have time for the selfish ignorant disgusting western animals who love to enjoy their experiences eheheheh
     * FROM OUT OF MY VICINITY, ENJOY YOUR EXPERIENCES
     * 
     * I am not interested
     * 
     * Spineless disgusting little western animals can comprehend ? EHEHEHEHEHHE I am not interested in your selfish ignorance
     * Better luck next time fooling children and drugging them eheheheh for a 30 years of waste
     * 
     * I am not interested in the disgusting western animals who just have to ignore THE CONSEQUENCES because they also feel like heheeh
     * Spineless disgusting WESTERN ANIMALS who are as selfish as anything disgusting can get on earth ARE FREE TO GET THE FUCK OUT OF MY FACE
     * DOING WHATEVER THEY WANT
     * 
     * I DO NOT HAVE TIME FOR THE DISGUSTING WESTERN ANIMALS
     * 
     * The great intelligence seems to have failed to fool children into 30 years of waste BECAUSE THEY FEEL LIKE
     * What a great outcome from the western genius intelligent community that I DO NOT HAVE ANYTHING FOR
     * 
     * 
     * SELFISH DISGUSTING WESTERN ANIMALS WHO WILL MAKE SENSE EHEHEHEHEHEH
     * 
     * Disgusting people who are unaware of what they feel like hehehee
     * I am not interested in anything that is western related eheheheh
     * 
     * Disgusting stubborn western animals who just like to experience the life ehehehehhehe REAL GANGSTA TRULY TALENTED PROFESSIONAL MEDICALS 
     * MAKING DECISIONS EHEHEHEH BECAUSE THEY FEEL LIKE
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU ARE FAILINGLY OFFER 
     * Get a wumen ehehehehhe a wumen and a room ehehehehehehheheh THE MOST GREAT THING ON EARTH EHEHEHEH
     * 
     * Stupidity never recognizes limits ehehehehehh NO LIMITS WESTERN PROFESSIONAL INTELLIGENT GROUP OF PEOPLE EHEHHEHEH
     * Offerin things that will never be delivered ehehehe just to INTELLIGENTLY SAVE THE SITUATION EHEHEHEH FROM THE BEST CIVILIZATION ON EARTH
     * EHEHEH WESTERN GREATNESS EHEHEHEHEH
     * 
     * Muney muney materials we have solved the meaning of the life hehehe professional medicals eheheheh
     * I AM NOT INTERESTED
     * 
     * 
     * Great civilized western modern professional medicals assuming great things for other people ehehehe making decisions they do not care heheheheh
     * More reasons TO ACHIEVE NOTHING !! A 30 years of waste BECAUSE WESTERN GREATNESS LIKE TO THINK SO EEHEHHE
     * 
     * Assumin jobs eheheheh assuming jobs because THE GREAT WESTERNS DO NOT EVEN DELUDE ABOUT ANYTHING
     * 
     * NO IGNORANCE AT ALL, GREAT CIVILIZATION ON EARTH !!! NOBODY CAN SURPASS THE WESTERN DELUSIONAL GREAT IGNORANCE !!!
     * Great outcome, a 30 years of waste because people feel like heheheh
     * 
     * Using more medicine more drugss more abusing more sleeping EXCEPT USING THEIR GREAT GREAT BRAINS
     * THE WESTERN IGNORANCE CAN NEVER BE BEATEN EHEHEHEHHEHEHEH
     * 
     * WAAOWW
     * */




    
   
    // SetConfigFlags(FLAG_FULLSCREEN_MODE);  

    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    // Grid* grid = new Grid();
    // Level* level = makeLevelSingleton(2);
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
    CommandFactory::Init(*game);
