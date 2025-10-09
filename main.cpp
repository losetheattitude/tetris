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
     * From out of my vicinity, move on living your lives !! yayyy !!! You have achieved it !!! The outcome !!
     * 
     * Not interested anything any of you can provide, get the fuck out of my face disgusting ignorant animals
     * Little disgusting animals you do not say !! Mhhhh real street gangsta genius type shit indeed, you can get the fuck out of my face indefinitely
     * 
     * I DO NOT HAVE ANYTHING FOR YOU
     *
     * Good job making nothing out of something !! 
     * Just like the not delusional professional genius gangsta engineer medicals, I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR YOU
     * Congrats to the best of the best civilization geniuses THE WESTERN NON DELUSIONALS ! Good job
     * I DO NOT HAVE TIME FOR YOU
     * 
     * NOT THE MOST INSIGNIFICANT THING I WILL EVER DO FOR ANY OF THE DISGUSTING WESTERN ANIMALS
     * You can get the fuck out of my face, I am not interested 
     * 
     * You are free to go do whatever your disgusting non delusional western super civilized genius minds think is doable, 
     * I HAVE NOTHING FOR YOU
     * 
     * Eheheheh indeed good outcome !! Nice job !! I am not interested, you are free to move on eheheheheheheh
     * 
     * Not even the tiniest insignificant anything I have for any of you, you are free to do GENIUS PROFESSIONAL MEDICAL NON DELUSIONALS !!
     * Ehehehehhehe, good job !!
     * 
     * Good job !!! eheheheh makin makin decisions eheheheheheh Super great intelligence FROM DA WESTERN EHEHEHEHEH
     * 
     * Super unseen western genius intelligence takin a few tens of years FOR NOTHING ehehehe, I have got NOTHING FOR YOU
     * Good job!! A wonderful outcome built by disgusting western animals
     * 
     * A sequence of tens of GREAT INTELLIGENCE DECISIONS, eheheheh and a few tens of years of HARM led to NOTHING
     * THE WESTERN TRUE INTELLIGENCE THAT NOBODY CAN EVER MATCH ehehehehehehe OMFG !!! Good professional medical genius engineerings disgusting non delusional western animals !!!
     * Good job !! Druggin abusin sleepin people Ehehehe makin makin decisions, I HAVE NOTHING FOR YOU
     * 
     * Genius engineering western civilized nations !! A wonderful NON DELUSIONAL OUTCOME !!! Eheheheh no results other than ehehehehehh just a few tens of years eheheh with harm eheheheh
     * 
     * I HAVE NOT THE TINIEST AND INSIGNIFICANT THING FOR ANY OF YOU, I DO NOT HAVE TIME, Move on with your disgusting acts
     * OUT OF MY VICINITY !! Great job !!
     * 
     * The true western non delusional intelligence actions !!! Greatest of da great from THE UNIVERSE !!
     * THE WEST !!! eheheheh Not interested
     * 
     * Good job !! No time for you
     * Perfect observation skills FROM THE WESTERN GENIUS PROFESSIONAL MEDICALS ehehehe sleepin druggin eheheh coercing ehehehehe violatin eheheheh
     * Move on with your disgusting actions, seek for more resilient children !!
     * 
     * I DO NOT HAVE TIME FOR ANY OF YOU
     * wumen wumennnn muneyyy cars ehehehe muney muneyyy westernnn eheheheh intelligenceee !! ehehehheh 
     * Eheheh The definition of true intelligent professional medicals !!
     * 
     * Good job, I do not have time for you
     * Good prediction and foreseeing ability FROM THE WESTERN NON DISGUSTING ANIMALS indeed !!
     * Just a couple of tens of years without NOTHING ehehehehehehheheheh 
     * 
     * The real gangsta true professional genius medical engineering DISGUSTING WESTERN ANIMALS
     * Who has to ignore some disgusting acts THEY HAVE DONE !!! Good job !
     * 
     * I have nothing for you
     * Eheheh except the genius medical professional engineering non delusional western animals can only offer some 
     * drugginggg eheheheh sleeepingg eheheh abusinggg ehehehhe children ehehhehehehe
     * 
     * The one and only true civilization OF DA UNIVERSE !!! ehehehe More marvelous movies for your disgusting imagination !!!
     * Eheheheh, fine outcome !! Good job!!
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * Foolin foolin indeed, definitely good outcome built by the true medical professional western animals !!
     * I HAVE NO TIME FOR YOU
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, I do not have one second to waste with you
     * 
     * You are not wanted around me, go on with your stupid delusions
     * FROM OUT OF MY VICINITY, I am not interested
     * 
     * Go back to your disgusting imaginations, make your own decisions next time
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, NO thank you YOU HAVE DONE AN INCREDIBLE JOB ACHIEVING NOTHING !!
     * 
     * Only a few tens of years TO NOWHERE !!! Like the true medical professional genius gangsta non delusional WESTERN disgusting ANIMALS
     * I HAVE ZERO TIME FOR YOU
     * 
     * Go with the stupid "ASSUMPTIONS", I have nothing for you, I AM NOT INTERESTED IN ANYTHING THAT YOU ARE AROUND
     * Get the fuck out of my face
     * 
     *
     * Definitely no delusional scenarios for your disgusting imaginations !! Ehehe just a few tens of years WITHOUT ANYTHING
     * To "CONVINCE" THE ONLY TRUE INTELLIGENCE WESTERN DISGUSTING ANIMALS !!!
     * 
     * Eheheheh life a game life a simulation, makin makin decisions ehehehehehehheheh OMFG !!!!! A STICKY SITUATION !!! THE SAVIORS OF DA UNIVERSE !!!
     * 
     * Good job for 30 years !! eheheh western professional medical geniuses !!
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * 
     * Eheheh good job for 30 years ehehehehhe makin makin decisions eheheheheh
     * 
     * Ten out of ten !! Intelligent spark people !!! THE ONE AND ONLY TRUE INTELLIGENT SPECIES OF THE UNIVERSE
     * THE WESTERN INTELLIGENCE !!!! A few tens of years of someone else's life !!!
     * 
     * Perfect outcome !!
     * A reallly nice story WE MUST BUILT to convince people ehehehehh Gooodd jobb  !!!!
     * Ehehehehehhehehehehehehehehe, THE WESTERN INTELLIGENCE !!
     * 
     * Savioring the world !! A truly unique and beatiful non delusional disgusting professional medical westerns !!
     * 
     * The true non delusional western intelligence !!! I HAVE NOTHING FOR YOU
     * Eheheh sleepin sleepin people just in case eheheh tens of years eheheheheh intelligence !!!
     * 
     * No delusions !! no marvelous movies eheheh no imaginations ehehehehehh 
     * THE ONE AND ONLY TRUE WESTERN DISGUSTING NON INTELLIGENCE !!!
     * 
     * Good job ! Sleepin sleepinnnn drugginggg NO ANGYR ehehehe do not ehehehehhe
     * Coercin coercin intelligence western non delusional DISGUSTING ehehehehehhe
     * 
     * Perfect job !! I HAVE GOT NOTHING FOR YOU
     * 
     * NEXT TIME DO NOT TOUCH ANYTHING YOU DO NOT UNDERSTAND, Good job !!
     * Achieving a lot of good deal beneficial outcomes !!
     * 
     * Definitely the one and only western true professional medical genius engineering DISGUSTING ANIMALS
     * 
     * I HAVE ZERO TIME AND INTENTION AND DESIRE TO WASTE ANY INSIGNIFICANT THING WITH YOU
     * The true western animals can GET THE FUCK OUT OF MY FACE doing what they think is right 
     * 
     * I have nothing for you
     * 
     * Wumen wumen muney offerers CAN MOVE ON WITH THEIR DISGUSTING LIVES !! YOU HAVE DONE IT !!
     * YOU HAVE ACHIEVED THE NOTHING !! What a lovely outcome and definitely unique chance and product THAT YOU WILL NEVER EVER UTILIZE !!
     * 
     * Good job though, I have no time for you
     * 
     * THE ONE AND ONLY TRUE INTELLIGENT WESTERN ANIMALS WHO HAVE TO IGNORE "WHAT THEY HAVE DONE" !!
     * Good job !! Professional medical genius nations !! Achieving nothing, just a few tens of years eheheh with violence heheheh
     * 
     * The one and only genius imaginative way !!
     * Next time DO NOT CROSS YOUR LIMITS !! eheheheheheheheheheheh THE TRUE WESTERN DISGUSTING ANIMALS that I have nothing for !!
     * */

    
   

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