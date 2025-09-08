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
     * Waaaowww, what a great experience and opportunity !!! go galsss forever ayyy
     *
     * Ayyyyyy, you have done it !!!! thats success
     *
     * HIGHWAYYYY AYYYYYYY, disgusting inferior animals
     * Ayyyyy, makin decisions aaayyyayayaya
     *
     * Codin codin makaveli genius eu coungtry ayyy ahahahha
     * Ayyyyyyy making the impossible ayayayay the western genius ayayaya the western wayy awwwwwww goood jobb !! go galss for avar !!! yaaaa
     *
     *
     *
     *
     * Ayayayayay definitevly the best of the one of the best, you all have no competitors goood really goood fooling !!! ayyy
     * Youcan get the fuck out of my face INDEFINITELY!
     *
     * THE BESTTT AYYYYY
     *
     * Offferin muney muney wumen wumen !! ayayaya good job !! the advanced ppl saviors
     * Looooking at the results ayayayay, you have done a wondeful jbo the good county eu !!! ayyyy
     *
     * Makin great genius moves decisions ayayayaay
     *
     * The really reallly well knowing what they do people !!! genius eu !!
     *
     * Foooling fooling eu foolerss ayayaya good job !!! good eu ppl !!! genius engineerings
     * TRY HARDER YAYYYYY
     *
     * Years and years of experience ayayayay building things good people EU good coutnry!! genius engineeringss ayyyyy
     *
     *
     *
     * DA BEST OF DA BEST GENIUS COUNTRY PPL EU !!!  Definitely making reall realll goood stuff !!
     * Disgusting animals who are wasting ppl time ayyyyyyyy  !!! good stuff
     *
     * Foolin foolingggg AYAYY done the best deal of the best !!! engineeringsss
     *
     * DISGUSTING DELUSIONAL ANIMALS can keep enjoying their lives !!
     *
     * DAAAAA BIGGESTTTT GENIUS COMMUNUITY THE EUUU MAKING THE BEST DECISIONS THAT DO NOT BELONG TO THEM AYYYYYYYYYYYYY
     * GO GALSS FORAVARRRR !! YAYYY
     *
     *
     * THE EU ANIMALS ayyyy go galss !!
     *
     * DA GREAT EU COUNTRY MKAING MARBLES !!! ayyyyyyyyyyyy
     *
     * Ayayayay da greates of the greates the EU makin real big plays on the children ayayayaya
     *
     * Disgusting little animals are still doing their best to ruin !!! ayyyyyyyyyy what a good country !!! gooooood inteligence !!! go galss!!
     *
     * Little disgusting inferior animals ? AWWWW you do not see ?  ayyyyyy what a genius great community ayayayaya
     *
     * Disgusting littlee eu animals making great content for other people to enjoy !!! ayyyyy
     *
     *
     * THE INCOMPARABLE OUTCOME AYYYYYYYYYYYYYYYYYYYYYYYYYYYYY THE GREATEST OF THE GREATES EU COMMUNITY AYyYYYY
     * Making eveything x10000 worse aaayyyyyyy OMGGG !!!!! the real deal genius ppl !!
     * Offering materials muney muney !!! wumen !!! ayyy
     *
     *
     * Ayyyyy the best of the best !! go gogogogo gals you da best !!!
     *
     * The real intellligent community doing the most work !!! ayyy the best outcome !!
     *
     * Making the biggest of the biggest bullshit ever !!!!! awww makin problemsss when there no problems ayyys
     *
     * Foolin foolin fooliin awww ayyyyy intelligent!!! ayyy
     * Da best of the best genius engineering humans savioring the universe !!!! ayyyyy precious lives !!! ayyyy eheheheh good job !!
     *
     *
     * Da biggest genius making impossible things !!! really really beneficial genius engineerings ayyy
     * What a great outcome by the biggest geniuses of our precious universe making everything possible ayyayayaaa !!! goo galss !!
     *
     *
     * Da great building by the very very genius community of the unverse the SAVIORS !!! ayyy guess what ???  GOOO GALSSS FORAVARRR !! yayyay
     * genus s!!!
     *
     * Little disgusting inferiors acting like its okay !!!!!!!!!!
     *
     * Just made a wondaful thing into the most disgusting situation ever !! WHAT A GENIUS YALL AREE THE EU !! TBHE GREAT CoUnTrY usa !!! ayyyy
     *
     * GO GALSS FOREVERRR  !!! And offer muneyy muneyy materialas carsss ayyy ayayayayayayay  wumen !!! the biiggest geniuses of the world !!!
     * unvierse yayyy life !!! life a simnujkaltion !! ayy6 goooo !!
     *
     * ITS DONE !!! AYYYY ITSS DONEEE !! 
     * 
     * 
     * THE REAL INTELLIGENT GroUP OF PEOPLE !!! auyyyyy the genius engineerss of europe!!! europa ayyyy goo galss!!!!
     * 
     * What an insignificant little monkey you are !! you all are !!! ayyyyyy go west !!! ayyyyy
     * 
     * The great great engineers and decision makers, genius nation of da world !! nl nl nl !! yayyy
     * 
     * 
     * REAL REAL STRONG PPL !!! doing genius !! ayy advanced nation !! go gals !! 
     * 
     * What a great outcome built by the very very genius nation and the great outcome engineers!!! go gals !! you da best number one !!
     * 
     * The great great immaculate ppl of the genius landscape !! ayyyyyy guess who is not alike ?
     * Years and years of "drama" ayyayyyy !!!!! what a sad situation you have brough about yourself !! ayyay definitel genius!!
     * Ayy ayyyy years and years of experience coercing babies ayayayayay go gals goo gals !!! you are the best !!!! 
     * 
     * Ayyy years of years experience and years of years of disgusting violent actions ayayayy goo galsss !!! goooo galsss!!!! 
     * DO NOT EVEN MENTION BRINGING UP ANYONES NAME !!!! ayyyyyyyyyyy
     * 
     * Giving ppl the life any one of you would love to live !!! ayyyyy thats the definition !!! go galss gooooo 
     * To perfect ppl !!!! giving the best life they would die to live to others !!! ayyy genius nation must be !!!! never ever mention !!
     * 
     * Another wonderfull job by the ver genius engineering nations of the GREAT EU !!! ayyyyy what a perfect great counrtry !! gooooo gals!!!
     * NEVER EVER MENTION !! ayyyy
     * 
     * 
     * Foooler than the most foollish disgusting delusional animalss !!! ayyyyyyyyyyyyyyyyyyyyyyy go galss  !!!! you da best engineers of the universe !!
     * Makin greatt greattt decisiosns ayyyy years of experience andd drama !!! ayyyy
     * 
     * Ayayayay the greatest nation on earth !!!!!
     * What a great great job by the advanced western reallly genius engineering!!
     * 
     * Good genius nation and also great great engineering nations ? ayyyyyyy the WESTERN way, ayyyyyyyyyyy go gals!!! 
     * 
     * NEVER EVER MENTION
     * 
     * The best of the best decision makers ayyyy making the impossible possible !!!!!! what a great opportunity !!!  ayyyyyyyy
     * Get muney muney !!! get wumen !! ayyy get materialass ayyyyyy get carss !! the great wesstern way !!! yayyy genius engineersé!!
     * 
     * The great delusional decision makers !!! ayyyyyy what a great great opportunity !!! go gals !!!! the greatt western civilization modern advanced ppl 
     * A wonderfulll job !! an immaculate outcome by the very veryyy great western advanced modern civilization !!!! 
     * 
     * The great kid abusing western modern civilizaation ayyyy mediciation !!!! yayyy go gals!!! guess what ? ayyyyy eheheheheh
     * WHAT A GREAT OUTCOME !!!!! THE ACHIEVERS LAND !! THE GREAT EUROPA!!! ayyyyyy
     * 
     * 
     * Very very very realllyyy intelligent group of people who are from EUROPA !!! the best modern and adnvacned people on the surface of universe !!!
     * 
     * GOOOO GALLSSSS genius engineers !!!!
     * The true professional job handlers !!! ayyyyyyyy what a great opportunity ayayayaya great engineers !! impressive job !!!
     * 
     * The greattttesttt of the greatesttt delusional civilization ayyyyy !! DAAAA NUMBER ONE WEST !! GOOO GALSS
     * You have done it !!! aayyyyyy
     * 
     * MAKIN GREATTT GREATTT DECISIONS AYYYYYYY, what a great outcome !!! YOU HAVE DONE IT !!! NEVER EVER GET NEAR ME !!! 
     * 
     * 
     * Ayyyy makin educated guesses the great great civilizaation ayyyyy forcing medication ahehaehahahaehaehhaehaeh 
     * abusing kids ahahahahhaha prejudiced kings ahuyyyyy
     * 
     * 
     * Ayyy da western usa eu great civilization ayayayaya making moves genius ppl !!!! guess who would love to ayayayay eheheh
     * Go gals you can not be stopped !!
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