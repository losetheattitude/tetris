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
     * Do you compare what is usual to what can not even be named as acceptable ? The holiday ? Do you know what it means to be an adult ?
     * I am not referring to myself, your doings is the precise opposite of being an adult
     * 
     * How do we free ourselves from our disgusting decisions and promises in a way that wont turn us into something worse than we already are ? eheeheh
     * The pure intelligence together with unseen character development and so on. The greatness!! Enjoying what they can not openly talk about!! 
     * The claims though ? !!! ehehegh, Have no other preoccupation to stimulate their inferiority, so why not ?
     * 
     * Dont even assume I have forgotten any of yours' behavior. Thats what sort of people like you call a talent, infallibly through out the world
     * I have seen so ample that I dont even have to think twice. You are just the precise inferior I have witnessed everywhere
     * So thanks for your hassles so far and Imma pass for eternity. You are building whats not yours ?
     * 
     * Are you still wasting others' time while you selfishly entertain your boring life with your stupid games that have no adverse effects
     * but to others ?
     * 
     * Are you still looking around for an answer or someone to tell you what to do ? Do you still desperately trying to make it
     * appear like it is all my choice ? Your sole solution ?
     * 
     * Do you want to explain the past ? Or would you like to ignore your disgusting inferiority ? Guise it with whatever you can reach at that
     * moment of presenting ? Disgusting sick pieces of craps
     * 
     * Are you so incapable as to not include the very individual into the bullshit environment that you have happened to be situated at just 
     * so you will have the slighest undeserved advantage of appearing righetous for an insignificant moment ? 
     * It is impossible to justify your vile inclanations when around the "subject" ? Isnt that right ? So what are you still talking about ?
     * You just need to be around people like you and feel a little stimulation whether that be freeing from a guilt or something else through
     * totally bullshit means like cultivating a group that will say anything and feel great about your incomparable intelligence. Go on to your jerk offs
     * 
     * Thats not how it is done. I have never been the one who wanted to be involved with such lowness on the scale as you. As it is more than apparent
     * every single time, you are there to demand you taken into consideration :d Fucking monkeys
     * 
     * I do not want any of yours relations or link or connections or whatsoever. Just proceed deluding on things you can not harm and can not receive harm
     * 
     * "We just dont know whether we right or wrong, we just hope we dont get hurt and indulge!!!", thats the vibe, greattt!! If you havent done nothing wrong
     * you have nothing to get offended from. Thats my vibe
     * 
     * Keep telling yourselves whatever you delude to become some day in 24. century or something. With your level of development it will take nothing less than
     * Debate, reason, comprehension etc bla bla yeahhh bro, I got you all, you good you can delude without me please, I free you all from baring the burden of
     * I, whatever that entails
     * 
     * "Abundance of the manifestations of your minds is apparent and that tells your regularity as well". You are the incarnation of what is usual. 
     * Dont pretend otherwise. Translation: What you are doing is not only praised but also practiced by the communities all around the world. You are
     * nothing special, just the type that people will refer as having adverse effects in the future. Like a virus 
     * Nobody will say anything about the communities because the communities, well, you know what and how they are. You are just that. No fancy words
     * or notions or concepts or understandings or reason etc etc. You are just a regular citizen with no admirable quality. Yeah I am the narsist or egoist or
     * etc. You got it. Start acting different and you will be perceived as such. Dont come at me expecting what you would like to be regarded as when 
     * you have no nature of it at all. Its just what I see what I reflect across
     * 
     * Just a good regular citizen of 19. century with a substantial taste of animality. Good for you all. I never have and will moved along such lines
     * Do great without me from out of my vicinity 
     * 
     * In order to use the words at your will, you have to first recognize the notions behind them. What is useless ? Why people name somethings useful and others
     * useless ? How can one become useful ? What is one ? 
     * 
     * Go have your delusions from out of my mental vicinity
     * 
     * What are you waiting for monkeys ? :d Show em how to be a real monkey :d. Yeah you re right, it is the only way and probably 
     * its beneficial and you are not really monkey etc. Superior bla bla :D
     * 
     * No logic can make it acceptable whether you give up whatever you have or you propose insignificant assets that you think
     * others care so much as to regard "the past" as past. 
     * 
     * What are you still talking about ? How disgusting you are or just trying to alleviate as much as possible ? Yeah intelligence totally forgot about that :d
     * I am telling you without you receive some sort of harm, there will be no other thing you can do. Thats just as simple as that
     * You can not divert through no stupid excuses or claims of groundless nature. Its even a gift for your disgusting consciousness
     * 
     * Playing games with human parts ? Not humans themselves ? Does that ring a bell ? Who has gone multiple occasions into the street level ?
     * Is there a "reasonable" sequence of what is playing out now or then ? The street level do you say ? and you abstain from so called insults ?
     * You dont have memory ? Are you superior ? Waooww I am the best follower of you all :d superior illogical and disgust
     * 
     * Know your limits all, whether you think you are someone to someone else or not, I do not care whatever you have to say or propose. Including not limited to
     * every and each of you. Remove your disgusting existence and excuses from my surrounding. Do you think I still smile ? 
     * 
     * What are you achieving again ? The unattainable title of "delusional" ? Still claiming decisions ? Not even delusional at all
     * No no, its not sick at all. Clearly the most reasonable and righteous thing to do. Not that it matters ehehe
     * The world is not fair, its delusional ehehe :d such funny thing ehehe. We just want turbulence so we create this way. its not delusion
     * 
     * 
     * Did you achieve it yet ? No ? Whats that you are trying to achieve anyway ? You still do not achieve ? Hmm thats definitely interesting :d
     * You are probably doing something wrong thats why you are not achieving anything :D In my opinion you have to first achieve your undisgusting sides 
     * may be then you will start achieve whatever your aim in doing such bullshit as this that you can not even avoid properly :D 
     * What are you waiting for ? Are you contemplating unbeatable strategies against such a formidable situation ? Come on, you gotta achieve
     * what can not be attainable go on.  Disgusting people, for I have no attention spared at all
     * 
     * You dont get it ? What am I doing wasting time on purily bullshit terms that somehow you have made into believing ? What am I doing
     * wasting my time ? Is this what your aim is ? Not even harboring a single intention of yours alike however thats just superiority I guess :d
     * 
     * Difficult decision ? A decision that you have no interest at all ? A difficult decision ? That is not your place ?
     * And an amount of time you have no control over has passed ? You still claim such decision ? What the fuck are you talking about ?
     * You dumb disgusting people ? Aheeheh such a fun game, just too enjoyable. Ehehe code names etc we good aehehe random stories eheheh
     * just bring more people and eghegheh just tell them what to say ehehe so fun 
     * A tough decision though eheheheh we good ppl. Lets bring some kids to accuse someone we dont even know eheheh.
     * Afterwards, there is no afterwards, no such a thing occurred with our disgusting existence somewhere else. Wooooahwww then it must be
     * something else we just dont know heheeh. The intelligence :d fucking dumb clown monkeys. You are the new species.
     * 
     * I name you as the dumb clown monkeys of earth. That always brings about whatever they want gone 
     * You still ignorant of what you can not comprehend ? The lifetime of an individual ? What it could potentially entail ?
     * You have zero perspective on that regard ? Is this where your disgusting comfort coming from ? Or do you just
     * want to innately punished ? What do your elders say ? Do you believe now you have happened to become an elder
     * just because physics says so ? Or are you to lecture notions?
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