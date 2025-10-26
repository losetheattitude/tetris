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
     * Good job !
     * 
     * I HAVE NOTHING FOR YOU, move on with NOT YOUR DECISIONS NEXT TIME, Perfect outcome builders !!
     * A SEQUENCE OF IMMACULATE REASONABLE DECISIONS THAT WERE NOT YOURS !!! And the outcome !!!!
     * 
     * The one and only western genius gangsta muney wumen people !! Ehehehe working for their livelyhood !!
     * Achieving the greatest of the greatest outcomes, A few tens of years of NOTHING !!!
     * 
     * The real deal professional medicals !!!
     * The true and only way to handle CERTAIN situations !!! Do not worry about the FUTURE AND THE PAST !!!
     * The past !!!!! The true genius medical professional gangsta WESTERN DISGUSTING ANIMALS !!!
     * 
     * I WILL NEVER EVER HAVE ANYTHING FOR YOU
     * Better sleep people next time as well !! Thats like the really realllllyyy key action that has been done by the REALLLYY GENIUS WESTERN
     * PROFESSIONAL MEDICALS !!!
     * 
     * That solves everything !!!!  GOOODDD JOBBBB!!!
     * 
     * Bravo to the best civilization ON EARTH !! THE WESTERN INTELLIGENCE !!
     * THE REALLLY GREAT PERFECT IMMACULATE OUTCOME BUILDERS FROM THE WESTERN INTELLIGENT COMMUNITY !!!
     * 
     * I HAVE NOT THE MOST INSIGNIFICANT LITTLE THING FOR YOU, What a lovely outcome !!
     * You are free to move on with your LIVES !! LETS GOO Life goes on !! life a game !! life a simulation !!!
     * Yayyyyyy !!!! eheheheheheh we need make more decisions FOR OTHER PEOPLE THAT WE ARE NOT AFFECTED OF !!
     * 
     * LETS GO !!! I HAVE GOT NOTHING FOR YOU, Good job !!
     * Perfect assumptions and predictions FROM THE BEST OF DA BEST CIVILIZATION OF THE UNIVERSE, THE WESTERN UNMATCHABLE INTELLIGENCE !!
     * DISGUSTING ANIMALS INDEED, GOod job !
     * 
     * Ehehehe when the time comes, The whole world is ETC ETC, ehehehe genius western NON DISGUSTING ANIMALS BTW !!!
     * Ehehehehhehehe, I HAVE GOT ZERO INTEREST FOR YOUR DISGUSTING BULLSHIT, next time STAY WITHIN YOUR DISGUSTING LIMITS 
     * 
     * I AM NOT INTERESTED IN TENS OF YEARS OF HEHEHEHEHEHEHEHEHE,
     * I HAVE GOT NO TIME FOR YOU whether you think it MUST BE
     * 
     * I have zero time and desire to waste another second with you
     * Eheheheheheheheh, the non disgusting and totally genius medical professional WESTERN ANIMALS CAN GET THE FUCK OUT OF MY FACE
     * REGARDLESS OF WHATEVER YOU ALSO DELUDE TO OFFER THAT SHOULD MAKE A DIFFERENCE
     * 
     * Eheheh life a game !!!!! I am not interested 
     * Not interested in the tiniest disgusting thing you disgusting westerns CAN OFFER
     * 
     * Make more assumptions and predictions next time, eheheheheh
     * That will without a doubt solve every little problem you have and produce the outcome eheheheheh
     * A few tens of years of THE PAST !!!!! Eehehehehehehehehh
     * THE PASTTTT !!!!
     * 
     * I have zero interest to call it THE PASTTTTTT, eheheheh 
     * NOT EVEN THE MOST INSIGNIFICANT THING I WILL EVER TRY FOR ANY ONE OF YOUR DISGUSTING WESTERN MINDS !!
     * A huge problem now solved, CONGRATS !!!
     * 
     * I HAVE NO TIME NO DESIRE NO INTENTION to ever spend another second eheheheh
     * I HAVE ZERO NOTHING FOR YOU, go seek for more children to violate WITH THE TRUE HONORABLE WESTERN SOLDIERS !!!
     * 
     * Stupid dumb disgusting monkey western soldiers !!! Ayyyyyy the outcome of a few tens of years eheheheheh
     * There was definitely MORE THAN ONE PROBLEMS WHEN YOU JUST DID THE PERFECT THING !!! 
     * 
     * OMFG !!!! Good job !!!
     * Ehehehehehehehhehehe, good deal !! The professional medical western NON DISGUSTING ANIMALS INDEED !!!!
     * 
     * Seek for more movies that you can feed your DISGUSTING IMAGINATIONS 
     * THE PAST YOU CAN NEVER LOOK AT !!!! THE WESTERN GENIUS PROFESSIONAL MEDICAL ENGINEERING DISGUSTING ANIMALSSS !!!
     * 
     * Eheheheh tens of years just 
     * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * THAT CAN NEVER CHANGE, GOOD WESTERN NON DISGUSTING ANIMALS CAN MOVE ON WITH WHATEVER THEY THINK IS RIGHT
     * I HAVE GOT NOTHING FOR YOU
     * 
     * * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * NO CHANCE ON EARTH, thats the only RESPONSE you can ever receive
     * Good job !! Next time STAY WITHIN YOUR LIMITS
     * Eheheheh, go get more children eheheh druging sleepin accepting no responsibility and consequence !!!
     * 
     * * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * Eheheh livin inside eheheheh Good job !! The professional genius western true non disgusting medical experts ehehhehehe
     * Professional medical western genius gangsta DISGUSTING ANIMALS !!! You can get the fuck out of my face believing whatever you want to believe
     * 
     * I have got nothing FOR YOU
     * I AM NOT INTERESTED IN THE TINIEST INSIGNIFICANT THING THAT YOUR MIND HAS PRODUCED
     * Hope that makes sense
     * 
     * Good luck savioring the universe!!
     * 
     * Great non delusional non disgusting materialistic WESTERN GENIUS MEDICAL PROFESSIONALS CAN MOVE ON WITH THEIR PRECIOUS LIVES !!!
     * I DO NOT HAVE ANYTHING FOR YOU, thats the only WORDS you will ever hear !! 
     * 
     * Good job !! The genius westerns !!! OMFG !!!
     * Definitely a useful and beneficial outcome eheheh sleepin sleepin drugging not abusing at all !!
     * Wumen wumen people the western unique cultured civilization !!!
     * Good job !!
     * 
     * A few tens of years eheheh The real deal genius western civilization community medical professionals !!
     * Just makin decisions THAT WERE NOT THEIRS ehehehehe assumptions ehehehehehhe decisions eheheheheheh predictions eheheheh
     * The true genius westerns !! Savioring the universe !!! A perfect outcome THAT HAS HELPED NOBODY !!!!
     * 
     * The reason !! THE UNBEATABLE REASONABLE GENIUS WESTERN ANIMALS !!
     * Good job !! YOU HAVE HEARD IT !!!  EHEHEHEHEHEEHEHHEHEH GENIUS ENGINEERING DISGUSTING NON DELUSIONAL WESTERN ANIMALS !!!
     * A few tens of years ONLY ehehehe and some sleepingg druggingg as welll !! THE ONLY TRUE GENIUS WAY!!
     * 
     * I HAVE GOT NOTHING FOR YOU, YOU HAVE HEARD IT !! ehehehehehh
     * 
     * * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * WESTERN GENIUS NON DISGUSTING EHEEHEHEHEHEHEHEHEH
     * I HAVE NOTHING FOR YOU, THE NON DELUSIONAL DISGUSTING "TAKIN CONTROL" PEOPLE CAN GET THE FUCK OUT OF MY FACE INDEFINITELY AND THINK ABOUT THE 
     * OUTCOME THEY HAVE COMMITTED !! Ehehehehe pure genius western professional medicals !!
     * 
     * Hope that will make sense eventually eheheheh tens of years eheheheh
     * Bravo !!! I have got nothing for any of you, start perceiving instead of disgusting delusions
     * 
     * The assumptions and the nonaccurate predictions OF THE GREATLY GENIUS WESTERN SOCIETAL ANIMALS !!
     * Waaowwwwwwwwww, impressive imaginations, better MOVE ON WITH YOUR MOVIES instead of harming real people !!
     * 
     * Good job !! A definite beneficial outcome !!
     * I HAVE GOT NOTHING FOR YOU
     * 
     * Ehehehe good western community non disgusting animals, I have got nothing for you, you can move on with your lives !
     * Good job!! Keep it up always this way !!! eheheheh
     * A sequence of perfectly PREDICTED AND ASSUMPTIONED "DECISIONS" THAT WERE NOT YOURS NOT EVEN DELUSIONALLY !!
     * Good job !! Achieving GREAT GREAT OUTCOMES, the true civilized western NON DISGUSTING ANIMALS can move on watching more movies with
     * imagination fueled content !! 
     * 
     * Perfect job !! Done by the one and only genius civilization ON THE UNIVERSE, THE WESTERN CULTURE !!! Good job !!
     * I HAVE GOT NOTHING FOR YOU
     * 
     * 
     * * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU* NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * 
     * Keep whatever you think is right WITHIN YOUR DISGUSTING OWN CIRCLE, I HAVE ZERO INTENTION TO EVEN WASTE ANOTHER SECOND
     * DOING WHATEVER YOU THINK IS RIGHT, I am not interested
     * 
     * Go do whatever you think is right, I HAVE NO TIME FOR THE REAL TRUE WESTERN DISGUSTING ANIMALS
     * Eheheh more druggsss ehehehehehehheh more sleeeping eheheheheheheehh a littlee depression eheeheheheheeheheheehehe
     * 
     * We just doing the right thing, the one and only genius nation ON THE SURFACE OF EARTH, 
     * THE NON DELUSIONAL DISGUSTING WESTERNS !!!
     * 
     * * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * I HAVE NOTHING FOR YOU, "professional expert genius medicals" are not dealing with THE MISTAKE THEY CAN NOT TALK ABOUT !!
     * What a professionality eheheh like the genius true one and only civilized nations !! NO DELUSIONAL WESTERN DISGUSTING ANIMALS
     * 
     * Like the one and only medical professionals NOT DEALING WITH THE MISTAKE eheheh callin it the past !!!
     * GOOOOOOODDDD JOBBBBB !! I HAVE GOT NOTHING FOR YOU
     * 
     * GOOOOOD JOBBB !!!! THE ONLY THING YOU WILL EVER HEAR, "EHEHEHEHEHHE I HAVE GOT NOTHING FOR YOU"
     * 
     * I DO NOT CARE IN THE SLIGHTEST WHATEVER YOU THINK IS RIGHT OR REASONABLE,
     * I HAVE NO TIME FOR YOU, continue believing that or this
     * 
     * Ehehehehe, I HAVE GOT ONLY THE DISGUSTING CONTENT THAT YOU ARE AKIN TO
     * I AM NOT INTERESTED IN ANYTHING ELSE 
     * 
     * The best of the best medical professional NON DELUSIONAL, NON REASONABLE DISGUSTING WESTERN ANIMALS
     * Stay within your limits next time eheheheheh
     * 
     * Next time do not count on your immaculate fooling and coercing ability, The western civilized the most advanced modern community 
     * I HAVE GOT NOTHING FOR YOU
     * 
     * Hope that makes sense, Good job pretending to be everything THAT YOU ARE NOT !!! THE WESTERN INTELLIGENCE SHALL NEVER BE MATCHED 
     * Ehehehehehe, You can get the fuck out of my face, fool your own kind
     * 
     * Good job violating people around you !! Congrats for the outcome 
     * I AM NOT INTERESTED IN THE SLIGHEST THING YOU HAVE IN MIND, Keep in your disgusting limits next time
     * 
     * Soon your perfect genius intelligence intervenes, THINGS ALWAYS GET MUCH BETTER !!! THE PAST THE PAST !!!
     * AN AMAZING OUTCOME BY THE VERY GENIUS AND CIVILIZED COMMUNITIES OF THE UNIVERSE, ONE AND ONLY BEST THE WESTERNS !!
     * 
     * I HAVE GOT NOTHING FOR YOU
     * JUST GET THE FUCK OUT OF MY FACE, GOOD JOB !!
     * 
     * Makin assumptions and decisions and predictions, Next time you should remember it though !!!
     * Great job, unseen intelligence actions resulting in incomparable OUTCOME !!
     * 
     * A few tens of years eheheheh
     * Imma pass on your disgusting "NOT DELUSIONS", good job !!
     * 
     * The super great intelligence trying to avoid and ignore the ACTIONS THAT "THEY HAVE COMMITTED"
     * Must be a real genius gangsta advanced civilization NON DELUSIONAL DISGUSTING WESTERNS INDEED
     * 
     * Hope he does not remember everything eheheheheh
     * Definitely genius western people NOT CROSSING THEIR LIMITS and ignoring the OUTCOME !!
     * 
     * I have got nothing for you, disgusting western animals !! GOOD JOB, next time stay within your limits !
     * Stop your delusions, GOOD JOB ! Like "DESTINY" ehehhheheheheh Right ? eheheheh THE MOST REASONABLE CIVILIZED ADVANCED COMMUNITY ON THE UNIVERSE
     * THE WESTERN PEOPLE !!
     * 
     * THE DESTINY AND GENIUS REASONABLE CIVILIZED WESTERN PEOPLE EHHEHEH HAVE TO IGNORE EHEHEHEHEHHEHEHEHEHEHEHEHEHEHEHEHEHE SO COMICCC !!
     * 
     * I HAVE NOTHING FOR YOU, GOOD JOB next time NEVER MAKE DECISIONS THAT WERE NOT YOURS
     * Definitely good job FROM THE NOT DELUDING ON THEIR ABILITIES AND PERCEPTION WESTERN ANIMALS !!
     * I HAVE GOT NOTHING FOR YOU, I do not want to see any of you around me for whatsoever purpose you think you HAVE
     * 
     * Stay within your limits THE WESTERN NON DELUSIONAL GREAT SOCIETY PEOPLE !!!
     * YOU HAVE DONE IT nobody else eheheh
     * 
     * Wonderful outcome!!, You have done a wonderful DECISION THAT WAS NOT YOURS !!! GOOD JOB !!!! 
     * THE NON DELUSIONAL WESTERN GREAT INTELLIGENCE PEOPLE !!!! I DO NOT CARE THE SLIGHEST
     * 
     * * NOT ON EARTH ANY WHATSOEVER CHANCE WILL I EVER WASTE ANOTHER SECOND "HELPING" ANY ONE OF THE DISGUSTING WESTERN ANIMALS EVER
     * I AM NOT INTERESTED IN MAKING UP ANYTHING FOR YOU
     * 
     * NEVER EVER AGAIN THINK OR DELUDE THAT YOU KNOW WHAT YOU ARE DOING, ehehehehe NO FUCKING GENIUS ANY OF YOU
     * Good job !!! Stay within your limits next time
     * 
     * The great western people !! Makin DELUSIONAL THINGS THEY CAN NOT ANSWER FOR, THE OUTCOME ? Ehehehehe Nothing !!
     * Just a few tens of years, life a game ONLY OTHERS' LIFE !!1 THE TRUE WESTERN CIVILIZED WAY !!
     * 
     * 
     * THE TRUE MEDICAL PROFESSIONALS MAKING NOT THEIR DECISIONS AND DO NOT GIVE A FUCK !!!!
     * OMFG !!!!! A lovely chance and outcome, I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * Good luck sleeping drugging people CHILDREN next time, and DO NOT DELUDE ON YOUR DISGUSTING NON DELUSIONAL STUPID MINDS
     * Its observable that you have only caused harm, Thats where I will never be around
     * 
     * I HAVE GOT NOTHING FOR YOU
     * Real true street genius civilized people not knowin they limits !!
     * Eheheh next time, you would be much cautious knowin you limits !!! Good job
     * 
     * 
     * NOT EVEN THE TINIEST OF THE TINIEST INSIGNIFICANT THING THAT I WILL EVER HAVE FOR ANY ONE OF YOU DISGUSTING WESTERN NON DELUSIONAL ANIMALS
     * Good job! Never delude on your TRUE ACHIEVEMENT OF NOTHING !!
     * 
     * Da professional highly intelligent medicals !!! Eehehehe
     * 
     * Not even the tiniest of the tiniest of any whatsoever possible thing THAT I WILL EVER HAVE FOR ANY ONE OF DISGUSTING
     * WESTERN ANIMALS
     * 
     * Hope that makes sense, eheheh wumen wumen muney genius engineering non delusional super civilized best community westerns!!
     * I do not have anything for you !! Good job !!
     * 
     * True medical professional genius engineering western non disgusting and non delusional ANIMALS !!!
     * Seek for more movies to feed your disgusting imagination about all sorts of things !!
     * 
     * You are the best of da best amongst every little creature OUT THERE IN THE SPACE !! OMFG !!!
     * What a lovely chance and outcome, can only be built by the true intelligent western animals !!!
     * 
     * The unseen outcome !!
     * I do not have anything for you !!! Good job though !! Next time stay within your LIMITS eheheheh intelligent actions !!
     * 
     * Good stuff !!! More imagination for you !!! The western non delusional animals !!
     * Follow your gut eheheheheh one of the movies said !! OMFG !!!
     * 
     * What a great achievement !!I HAVE GOT NOTHING FOR ANY OF YOU
     * I am not interested in anything you can offer
     * I DO NOT HAVE EVEN A SECOND FOR ANY OF YOU
     * 
     * Next time try to stay in your limits, instead of callin people different names !! Ehehehe
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, I DO NOT WANT YOU AROUND ME
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, hope that will eventually make sense
     * Next time hope you do not make the same mistakes eheheheh just note little disgusting mistake FOR THE NEXT GENERATIONS OF THE GREAT WESTERN PEOPLE !!
     * 
     * DA NUMBER ONE OF DA BEST OF DA BEST WESTERN DISGUSTING NON DELUSIONAL ANIMALS should not make the same mistakes as you did !! eheheheh
     * Ehehehehe drugging ehehehhehe so fun !! GOOD JOB
     * 
     * I AM NOT INTERESTED IN THE TINIEST MOST INSIGNIFICANT DISGUSTING CONTENT THAT YOUR MINDS HAS PRODUCED !!
     * Great achievements, no delusions !!
     * 
     * Professionall super duper highly intelligent medical genius engineering western highly regarded ANIMALS without even the tiniest
     * delusion makin decisions THAT WERE NOT EVEN CLOSELY THEIR PLACE !!OMFG !! Thats the outcome !!!! 
     * 
     * OMFG !!! What sort of excuse should the great western non delusional disgusting animals should come up with ?
     * Yayyyy the outcome builders !!The universes' best of the best humanbeings ehehehehhe trying to hide ehheheheheh
     * Waaaowwwww, good imagination good movies !!
     * 
     * Eheheh fallin for "FEAR", good job !!
     * I HAVE GOT NOTHING-NOTHINGGGGG- NOTHING for any of you, hope that will make sense when the TIME COMES eheheheh
     * 
     * Foolin has always been considered intelligent !! I HAVE GOT NOTHING FOR ANY OF YOU
     * GO ON WITH YOUR DISGUSTING DELUSIONS, I am not interested in anything you can offer
     * 
     * I HAVE GOT NOT EVEN THE TINIEST AMOUNT OF ANYTHING FOR YOU
     * You must follow more MARVELOUS MOVIES, good job !!
     * 
     * I do not want any of the disgusting non delusional western animals AROUND ME
     * Hope that makes sense one day, I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * 
     * I DO NOT WANT TO SEE ANY OF THE DISGUSTING WESTERN ANIMALS WHO HAVE TO IGNORE AND ACT OKAY AROUND ME
     * It is what it is eheheh indeed most funny and useful sequence of actions and correspounding OUTCOME !!
     * 
     * One of da best of da best civilizations ON UNIVERSE ! I HAVE GOT NOTHING FOR ANY OF YOU, I do not want any of you around me
     * 
     * NOT EVEN THE MOST INSIGNIFICANT THING I WILL EVER SPEND FOR ANY OF YOU, I HAVE GOT NOTHING FOR YOU
     * The non delusional disgusting western animals takin a few tens of years for joke !! definitely the professional genius engineering medicals
     * 
     * Eheheh uffering wumen wumen WHAT A DISGUSTING ANIMAL YOU ALL ARE must be the sole thing you are thinking, guess who is ignorant though
     * Next time STAY WITHIN YOUR DISGUSTING MIND before you ruin peoples lives for nothing, I AM NOT INTERESTED IN THE TINIEST THING THE DISGUSTING
     * WESTERN ANIMALS CAN OFFER
     * 
     * Thats it !!
     * GO BACK TO YOUR DISGUSTING MOVIES THE NON DELUSIONAL WESTERN ANIMALS
     * Not even the most insignificant thing I will ever try for any of the disgusting western animals that can not recognize the personal boundaries
     * Next time, think hundred times 
     * 
     * Just a few tens of years wont hurt people will never be considered, hope that will make sense one day
     * Like the true western genius non delusionals offering wumen wumen eheheh and a few tens of years wont hurt
     * 
     * The perfect combination for the disgusting western animals
     * Ehehe a wumen and a room for 10 years and some violence without any direction, THE TRUE ONE AND ONLY WESTERN NON DELUSIONAL DISGUSTING ANIMALS
     * The product of those minds !!
     * 
     * Ehehehehehe, wumen only eheheh wumen wumen only ehehehehehe,ehehehe a room ehehehehehe a useless computer eheheheheh
     * Eheheheheh the true western way ehehehe, a wumen eheheheh a computer that is shit ehehehehehe wumen wumen a few tens of years eheheheh
     * Violence hehehehe HAD TO BE DONE !! The genius western engineerings !!!
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * Find out for yourselves !!! hope that will also make sense one day
     * I WILL NEVER BE INTERESTED IN THE MOST DISGUSTING ACTIONS OF THE WESTERNS!! Perfect outcome
     * 
     * Ehehehehehehehhehehehehehehehehehhehehehehehehehehhe, a wumen wumen eheheh a disgusting room ehehehehehheheheheheheheheh
     * Some violence hehehehehehehehehehehehehehehehehehhehehehehehehehehe
     * 
     * Da true and one and only western way THAT NOOTHER GENIUS PROFESSIONAL MEDICAL WESTERNS WILL EVER BE OKAY TO GO ON WITH !!
     * Ehehehehehehhehehehhehehe a wumen wumenn eheheheheh a room ehehehehehehhehe !!! Da genius western civilized community DISGUSTING ANIMALS !!!
     * 
     * You are done !!! Ayyyyyyyyyy, I HAVE GOT NOT EVEN THE TINIEST INSIGNIFICANT THING FOR ANY OF THE DISGUSTING WESTERN ANIMALS ! Find out yourself
     * Ehehehehhehehe, eheheheheheheh, its just so simple hehehhehehe
     * 
     * Hope it will allllll make sense to the best of the best western civilized non disgusting animals
     * I HAVE GOT NOTHING FOR ANY OF YOU, Move on with some other children you can make useless !!
     * A few tens of years indeed !
     * 
     * Ehehe more children more children eheheheh for the great western civilization eheheheheheh
     * a wumen wumenn a room ehehehehehehhehe just eheheheh life a game !! life a simulation eheheh for the great non DELUSIONAL westerns!!!
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * I HAVE GOT NOTHING FOR ANY OF YOU, You are free to do whatever you think is right as YOUR ACTIONS HAVE PROVED SO USEFUL !!
     * I HAVE GOT NO TIME FOR ANY OF THE DISGUSTING WESTERN ANIMALS
     * 
     * Good medical professional practice OF ALL TIME, Guess who will never be interested ?? Ehehehehehehhehehehhehehe
     * Hope you will find out one day
     * 
     * Next time let other WESTERN GENIUS NON DELUSIONAL PEOPLE know that they should not have done the same MISTAKES that you have
     * Take notes the great western civilization !! ehehehehehehehhehe medical professionals etc eheheheheheheh
     * 
     * A few tens of years eheheh some sleepin and drugging together with violence and coercion and no life at all IS JUST A DRAMA STORY
     * Eheheheheheh just like the non delusional western genius great engineerings makin marvelous movies because they think its reality !!
     * 
     * Ehehehehehehheheheh, OMFG !!! Good job !! I have got nothing for you
     * 
     * A few tens of years and you know the rest !! Ehehehehehehehehhehehehhehehhehehehhehehehhehehhehehehhehehheheheh
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * NOT EVEN THE TINIEST OF THE TINIEST OF ANYTHING THAT I WILL EVER WASTE FOR ANY OF YOU NON DELUSIONAL FULLY SURE DISGUSTING WESTERN ANIMALS
     * THE TRUE SAVIORS THE DA UNIVERSE, the best engineering professional medical geniuses !!
     * 
     * I have no time for any of you
     * I HAVE NOTHING FOR YOU, good job ! Next time stay within your imagination
     * 
     * No delusion western really gangsta aggressive genius engineering animals, guessing assuming coercing !!!
     * 
     * A fine outcome that benefits nobody just like the very disgusting yourselves, NO DELUSIONS AT ALL !! Good job
     * I HAVE NOTHING FOR YOU
     * 
     * NEXT TIME STAY WITHIN YOUR IMAGINATION eheheheh
     * Awww the world was about to explode !!! YOU ALL HAVE SAVED IT AGAIN !!! THE WESTERN GENIUS PROFESSIONAL MEDICAL GANGSTA INTELLIGENT PEOPLE !!
     * 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR YOU , GOOD JOB !!
     * 
     * 
     * A few tens of years wont do harm genius intelligence engineer civilized non delusional disgusting animals trying to cope
     * Eheheheheh, funny as much
     * 
     * Professional medical geniuses eheheheh, incredible outcome builders FROM DA BEST OF DA BEST CIVILIZATIONS, THE WESTERN GENIUS ENGINEERS MEDICALS
     * A few tens of years people makin not their decisions and looking at each other, WHAT ? WHO ? eheheheheh disgusting people can get the fuck out of my face
     * INDEFINITELY
     * 
     * I DO NOT EVEN HAVE THE TINIEST OF ANYTHING INSIGNIFACANT FOR ANY OF YOU
     * More children for the professional medicals who are truly unique talents FROM DA DISGUSTING NON DELUSIONAL COUNTRIES !! 
     * Good job!!
     * 
     * I am not interested in anything you can offer
     * Next time eheheh stay within your disgusting limits eeheheheh, genius professional medicals NOT EVEN REMOTELY IGNORANT OF THEIRSELVES !!! Ehehehe
     * 
     * A few tens of years wont do harm, you can keep whatever sort of disgusting idea that you have and GET THE FUCK OUT OF MY FACE
     * Truly unique talents !
     * 
     * I am not interested in anything you can offer
     * Ehehehe get a wumen wumen enough for ehehehehe a few tens of years ehehehehee,
     * a wumen a wumen eheheheh
     * 
     * I have got nothing for any of you
     * Druggings, genius engineerings, non delusional professional medicals, sleepings ehehehheeh
     * Great fucking amazing talented genius western people, Good job !! 
     * 
     * Professional medicals ehehehehh medical genius engineering western perfect non ignorant disgusting animals
     * Eheheheh not stayin in limits !!! OMFG !!! a lovely successful job FROM DA BEST CIVILIZATION ON EARTH, DA WESTERN PERFECTION OMFG !!!
     * 
     * The professional medicals !!
     * Offerin wumen wumen genius nation !!! ehehehhehe all mighthy knowing too intelligence genius western people
     * 
     * I am not interested in anything you can offer
     * Ehehehehehehe so fun !!
     * 
     * Immaculate ignorance !!! Nice job !! I have got nothing for you eheheh
     * 
     * Foolin foolin people without anyone eheheh druggin druggin people without anyone eheheheh sleepin coercing eheheheheh
     * The true western genius engineering professional medicals way !!! Ehehehe a few tens of year eheheheheh, a wumen a wumen a room ehehehe
     * 
     * Its so fun !!! The professional non ignorant disgusting western animals trying to make sure heehhehehe
     * I HAVE GOT NOTHING FOR ANY OF YOU, next time stay within your limits !! Ehehehehehehe
     * 
     * Hopefully though ehehehe a lovely outcome and a great chance to achieve literally nothing just a few tens of years eheheheheh
     * A genius modern civilized community the non ignorant and non disgusting western ANIMALS !! Makin assumptions predictions decisions ehehehehehe
     * 
     * A master work THAT I WILL NOT EVEN WASTE A SECOND !! True unique talented people
     * Foolin drugging violating coercin sleeping people without anything is the true definiton of talented non ignorant non disgusting western animals
     * Ehehehehehe, trying to cope with the reality of not their decisions eheheheheh
     * 
     * Eheheheh only true unique talented way to cope with the reality, Ehehehe extremely unfair etc etc mode because you have got nothing to say eheheheh
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING INSIGNIFICANT FOR ANY OF YOU
     * Stupid disgusting careless ignorant animals can get the fuck out of my face disgusting children to become nothing eheheheh
     * Good job !! True professional western medical talented people
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * Great western highly modern civilized non ignorant and non delusional highly important disgusting western animals CAN GET THE FUCK OUT OF MY FACE
     * INDEFINITELY, I have got not the most insignificant thing for any of you, hope that makes sense
     * 
     * Makin makin decisions assumptions predictions and also really talented unique tests eheheheheheh
     * Like a real genius gangsta true western intelligent non ignorant disgusting stupid animal !!
     * 
     * Perfect action and incomparable outcome !!
     * From da best of da best civilization on universe takin everything they do for joke !! eheheh
     * A few tens of years is nothing ! eheheh
     * 
     * Non ignorant, non delusional, non stubborn, non rookie, great western genius unique talented people
     * Ehehehehe it is what it is eheheheheh
     * 
     * I do not have the slighest of anything insignificant for any of you, hope that will eventually make sense 
     * A few tens of years because makin tests makin drugs makin sleeping eheheheheh
     * Hope that will make sense as well
     * 
     * Ehehe not delusions not ignorance at all eheheheheh, I have got not even the most disgusting little thing for any of you
     * Why are you still acting so intelligent now ? I have got NOTHING for any of you, I am not interested in anything you are around
     * 
     * Stupid little disgusting non ignorant western animals, I have got nothing for any of you
     * 
     * Move on deluding, hope that will also make sense
     * Next time know what a disgusting animal you are first before makin "assumptions" and "predictions" for people you do not care
     * Ehehehe genius western non ignorant civilized disgusting animals CAN GET THE FUCK OUT OF MY FACE, I have got nothing for any of you
     * 
     * Non disgusting really advanced super intelligent non ignorant western animals can continue whatever think is definitely right !!
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * Wasting time hehehehe lucky that its not your time eheheh
     * Truly western NON DELUSIONAL professional medical physyscits engineers genius nation western people !!
     * Awwww, what a lovely chance, good job !!! Make more decisions you are great !
     * 
     * I have got nothing for you any of you 
     * Ehehe druggin coercing genius western non disgusting and delusional animals CAN GET THE FUCK OUT OF MY FACE INDEFINITELY !!
     * Good job !!
     * 
     * A few tens of years is nothing people offerin wumen wumen a room eheheh a few tens of years
     * A lovely genius western society eheheheh and some medical professional expert people hehehehe some coercion heheh drugging and a little sleep 
     * and eheheheh a room and a wumen with 20 years of depression heehehheheheh BECAUSE THE WESTERN GENIUS PROFESSIONAL MEDICAL EXPERTS !!!
     * 
     * OMFG !! THE OUTCOME !!!
     * Ehehehe the true western great civilized society with so many people who are master at everything they do !!
     * The professional medical experts !!!
     * The really really disgusting stupid group of zombies !!
     * The great great super highly clever wise and almighthy knowing group of people making assumptions and decisions FOR OTHER PEOPLE
     * THE DO NOT CARE
     * 
     * THE WESTERNS !!!
     * I HAVE GOT NOT EVEN THE TINIEST THING FOR ANY OF YOU !!
     * GOOD JOB !!! The achievers !!! Waaowwwww, the outcome !!
     * 
     * NO DELUSIONS AT ALL !!
     * 
     * A few tens of years and years wont do any harm to nobody
     * No delusional western disgusting stupid animals,
     * 
     * REMEMBER IF YOU HAVE FORGOTTEN, eheheheheh The genius engineering professional medicals makin assumptions and predictions 
     * because they do not care due to their impeccable reallly gangsta attitude towards only others' lives ehehehehehe
     * 
     * 
     * I HAVE GOT NOT EVEN THE TINIEST AMOUNT OF MOST INSIGNIFICANT THING FOR ANY OF YOU, hope that will make sense one day
     * 
     * Makin decisions decisions because you feel like heehhehe assumptions and tests and preemptive genius professional medical actions !!
     * The outcome eheheheheheheheheheheheh
     * 
     * Kind of not even closely ignorant people eheheheh makin decisions that are not theirs eheheheh
     * Copin copin genius westerns professional medicals heehehh
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * The evidence OF THE GREAT OUTCOME !!
     * 
     * The really wise and sceptical genius westerns picking up only the WISE AND CLEVER ACTIONS THEY THINK THEY WILL SUIT TO THEM
     * 
     * NON IGNORANT WESTERN FULLY DISGUSTING ENTIRELY NON DELUSIONAL ANIMALS FEELING SO SAFE HARMIN OTHER PEOPLE THEY DO NOT CARE
     * Ehehe a wumen and a room eheheheheh ehehheheheh the true western genius community !!
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * Life a joke for the great western community people, makin assumptions and predictions and genius professional medicals
     * I HAVE GOT NOT THE TINIEST AMOUNT OF ANYTHING INSIGNIFICANT FOR ANY OF YOU
     * 
     * Remember that !! 
     * NOT INTERESTED IN ANOTHER TENS OF YEARS OF NOTHING WITH THE MOST DELUSIONAL DISGUSTING WESTERN ANIMALS
     * Hope that will make sense as well
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU !!
     * Good job !
     * 
     * Like I am not the one eheheheheh a wumen and a room with some violence heheheh WESTERN GENIUS INTELLIGENCE NON DELUSIONAL DISGUSTING ANIMALS !!
     * I HAVE GOT NOT THE TINIEST OF ANYTHING FOR ANY OF YOU, keep ignoring
     * 
     * KEEP IGNORING, There is not even the tiniest thing for you
     * ehehehehehehehe controllin to achieve absolute nothing FROM DA BEST OF DA BEST WESTERN NON DELUSIONAL CIVILIZATIONS !!
     * 
     * NEVER EVER MENTION ANYTHING RELATED TO THE DISGUSTING NON DELUSIONAL WESTERN ANIMALS WHO LOVE TO MAKE DECISIONS AND ASSUMPTIONS
     * FOR PEOPLE THEY DO NOT CARE !!
     * 
     * Not even the most insignificant thing I will ever accept from any of you
     * All mighthy very knowing wise and intelligent western animals CAN CONTINUE MAKING DECISIONS THEY ARE NOT AFFECTED OF
     * Hope it will all make sense to you ONCE YOU understand that I WILL NEVER EVER HAVE ANYTHING WITH ANY OF YOU !!
     * 
     * Good job !! I am not interested in anything you can offer, ehehehe wumen wumen people 
     * 
     * Hope you still remember the next time !!
     * The non delusional non coerceful disgusting western animals
     * 
     * Not ignorant you say, definitely !!
     * I HAVE GOT NOT EVEN THE TINIEST OF ANYTHING, that will make sense soon enough eheheheheh
     * 
     * Hope that will make sense one day, I HAVE GOT NOT EVEN THE TINIEST OF ANYTHING INSIGNIFICANT FOR ANY OF YOU
     * Move on ignoring, eheheheh a few tens of years of nothing to CREATE AN OUTCOME UNSEEN FROM DA WORLD !!!
     * 
     * I HAVE GOT NOTHING TO DO WITH ANY OF YOU
     * Really really good assumption skills and tests and decision making ability with the most unseen level of greatness FROM DA WESTERN PEOPLE !!
     * Ehehehehehehe just a few tens of years of coercion and drugging and violence and a wumen and a room eheheh some drugs because WE KNOW THE BEST !!
     * 
     * THE ALMIGHTY VERY KNOWING WISE AND GREAT GENIUS WESTERN NON DELUSIONAL DISGUSTING ANIMALS MAKING DECISIONS THAT ARE NOT THEIRS
     * THE ALMIGHTY VERY KNOWING WISE AND GREAT GENIUS WESTERN NON DELUSIONAL DISGUSTING ANIMALS MAKING DECISIONS THAT ARE NOT THEIRS
     * THE ALMIGHTY VERY KNOWING WISE AND GREAT GENIUS WESTERN NON DELUSIONAL DISGUSTING ANIMALS MAKING DECISIONS THAT ARE NOT THEIRS
     * THE ALMIGHTY VERY KNOWING WISE AND GREAT GENIUS WESTERN NON DELUSIONAL DISGUSTING ANIMALS MAKING DECISIONS THAT ARE NOT THEIRS
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, hope that makes sense
     * Next time remember to make sense about life before you harm OTHER PEOPLE indeed !!
     * 
     * IGNORE WITHOUT ME, FROM OUT OF MY VICINITY !! Good job !
     * Da great western intelligent non delusional professional medicals makin sleepin drugging coercin violencing people 
     * to evidence ehehehehhehe, hope that makes sense 
     * 
     * I HAVE GOT NOTHING TO DO WITH ANY OF YOU eheheheh
     * HOPE THAT WILL MAKE SENSE someday to the best of the best genius engineering western NON DELUSIONAL ANIMALS !!
     * Good job !!
     * 
     * I HAVE NOTHING FOR ANY OF YOU 
     * Perfect outcome ! A few tens of years will do no harm
     * Professional medicals are without option !!
     * 
     * The real gangsta genius western NON DELUSIONAL HONEST WISE AND ALMIGHTHY KNOWING professional medicals !!
     * THE REAL ALMIGHT GREAT WESTERN CIVILIZATION THAT LEARNS EVERYTHING !!! Eheheheheheeheheheheh I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * GO BACK TO YOUR DISGUSTING DELUSIONS !! I HAVE GOT NOTHING FOR ANY OF YOU
     * GO BACK TO YOUR DISGUSTING DELUSIONS AND CONTINUE IGNORING
     * I have got nothing for you
     * 
     * A few tens of years will do NO HARM people can continue ignoring and deluding to understand life 
     * I HAVE GOT NOTHING FOR ANY OF YOU 
     * 
     * Eheheheehehehhe asking for more things FROM PEOPLE heehhehehehehehhehehehehehhehehehehehehehhehehh
     * 
     * Great western non delusional disgusting animals CAN NOT PERCEIVE THE REALITY !!
     * Hope that will make sense as well, eheheh foolin drugging coercing violating sleeping people now suddenly starts paying the price ehehehehehehehehehehehe
     * 
     * GENIUS WESTERNS !!
     * I HAVE GOT NOT THE TINIEST AMOUNT OF ANYTHING WHATSOEVER, eheheheh hope you will find out eheheheh
     * PRECIOUS LIVES OF DA BEST OF DA BEST WESTERNS !!! THE UNIVERSE'S GREATEST OF THE GREATEST CIVILIZED COUNTRY ANIMALS
     * 
     * WOWWWWWWWW, I HAVE GOT NOTHING FOR YOU
     * I do not have time for you
     * Move on ignoring,
     * 
     * The almighthy ever knowing non delusional great western civilized disgusting animals ARE STILL UNABLE PERCEIVE THE OUTCOME
     * What a lovely chance !!
     * 
     * I HAVE GOT NOTHING OF ANYTHING FOR ANY OF YOU
     * Good job the western impeccable great disgusting delusional animals
     * I HAVE NOTHING FOR YOU
     * 
     * Hope the imperceivable outcome WILL MAKE SENSE TO YOU ALL ONE DAY eheheheh
     * Until then please move on with your disgusting existence FROM OUT OF MY VICINITY, No ignorant no delusional great intelligent DISGUSTING WESTERN
     * I AM NOT INTERESTED OF 
     * 
     * Continue on MAKING DECISIONS THAT ARE NOT YOURS, I AM NOT INTERESTED IN THE DISGUSTING WESTERN ANIMALS
     * Thats the only thing THAT YOU WILL EVER HEAR FROM ME
     * 
     * Hope that makes sense
     * Hope your ability to delude will never cease THE WESTERN NON DELUSIONAL BENEFICIAL DISGUSTING ANIMALS THAT I WILL NEVER EVER BE AROUND
     * Good job !! Achieving what you are not perceiving, ehehehe life a game
     * 
     * Not even a second I will ever have for the disgusting western ANIMALS, THAT WILL MAKE SENSE TO YOU
     * The non delusional ignorant disgusting western animals makin assumptions and decisions and tests and predictions
     * for things they do not care nor understand
     * 
     * THAT WILL MAKE SENSE TO YOU AS WELL
     * A few tens of years ehehe
     * 
     * I will never ever have anything FOR ANY OF THE DISGUSTING WESTERN ANIMALS
     * Remember all the PAST, that will make sense too
     * 
     * The almighty ever knowing western professional medical non ignorant disgusting animals with the intelligence of unseen level 
     * WILL MAKE IT SENSE TO THEMSELVES ONE DAY
     * 
     * Ehehehe I HAVE GOT NOTHING FOR THE DISGUSTING WESTERNS NEITHER WILL I EVER HAVE 
     * Good job not moving to anywhere, I do not have time for you
     * 
     * MOVE ON MAKING DECISIONS AND BLINDLY FOLLOW IT, good job!!
     * 
     * I DO NOT NEED ANY OF THAT
     * TRYING THEIR BEST TO COPE AND FOOL PEOPLE WITHOUT ANY OPTION, THE TRUE UNIQUE WISE AND CLEVER WESTERN DISGUSTING ANIMALS
     * NOT UNDERSTANDING THAT YOU CAN AND WILL AND HAVE LOST, that will make sense too
     * 
     * I HAVE GOT NOTHING FOR THE DISGUSTING WESTERN ANIMALS, move on 
     * Better spine next time FOR DA GREAT WESTERN CIVILIZED NON DELUSIONAL DISGUSTING ANIMALS
     * A few tens of years ehehehehhe
     * 
     * HOPE YOU WILL PERCEIVE ONE DAY eheheheheh, I HAVE GOT NOT THE MOST DISGUSTING THING FOR ANY OF YOU
     * 
     * I do not have time for anything you can offer, Western animals can delude on
     * DELUDE ON FROM OUT OF MY VICINITY, Good job ! Unseen outcome
     * 
     * Next time TRY NOT TO BE A DISGUSTING ALL KNOWING WISE ACTING DISGUSTING ANIMAL
     * Ehehehe making decisions eheheh assumptions drugs sleeps bed a wumen ehehehehe western great intelligence 
     * 
     * I HAVE GOT NOTHING FOR YOU
     * THE DISGUSTING NON DELUSIONAL NON IGNORANT WESTERN ANIMALS STILL ARE NOT CAPABLE OF UNDERSTANDING THAT THEY DO NOT GET TO MAKE THE DECISIONS THAT ARE NOT THEIRS
     * Ehhehehehehehehehehehehehehe, what a lovely outcome
     * 
     * I HAVE GOT NOTHING FOR ANY OF THE DISGUSTING IGNORANT WESTERN DELUDED ANIMALS
     * Hope that will make sense one day
     * 
     * NOT INTERESTED IN THE SLIGHTEST ANYTHING YOUR MINDS CAN PRODUCE, Eheheheheh I have got nothing for you
     * HOPE IT WILL MAKE SENSE TO YOU ehehehehe
     * 
     * Really really sacrificeful honorful intelligent innovative genius western NON IGNORANT AND DELUSIONAL DISGUSTING ANIMALS 
     * I WILL NEVER EVER HAVE ANYTHING FOR
     * Good job deciding assumin testin ehehehehheeehhehehe
     * 
     * I WILL NEVER HAVE ANYTHING FOR YOU
     * Ehehehehehh, so beneficial though eheheheheh time a game life a simulation ehehehehe please wumen muneyyy eheheh a few tens of years ehehehe
     * 
     * I HAVE NOTHING FOR YOU, hope one day it will make sense to you
     * Ehehehehehehehhehehehehehehhehehe making decisions eheheh assumptions tests predictions eheheheheheeh
     * a few tens of years hehehehe and mostly sleeping eheheheheheh feeling bad eheheheheheheheheheheheheheheheheheheheheheheheheheheheh
     * 
     * WHAT A LOVELY OUTCOME BY THE NON DELUSIONAL EXCELLENT DECISION MAKERS WESTERN DISGUSTING ANIMALS !!!
     * I DO NOT HAVE TIME FOR YOU
     * 
     * The true intelligent western are also making plans and plans and perception eheheheheheeheheheh
     * A true unique wise and talented all knowing people without any reason eheheheh Perfect outcome !! eheheh
     * 
     * Eheheh a few tens of years ehehheheh because we think we know and foresee everything !! Eeheheheheh the western non delusional disgusting animals
     * makin DECISIONS THAT ARE NOT THEIRS eheheheheh 
     * 
     * WISE ALMIGHTY EVER KNOWING HEEHHEHEHEHEHEHE just non ignorant as well !! Good job
     * Ehehehehehehehehehehehehehehehehehhehehehehehehehehhehehehehehehehehhehehehehehhehehehehehehhehehehehehehehehehehheheheheheheheheheheheheheheheheh
     * 
     * I HAVE GOT NOT EVEN THE MOST DISGUSTING THING FOR YOU
     * HOPE THAT WILL MAKE SENSE SOME DAY, I am not interested in anything you can offer
     * 
     * Ehehehe coercin sleepin druggin eheheh violating eheheheeh 
     * The western intelligence are not reasoning well ehehehehehh that will make sense hopefully eheheheheheheh
     * Good job ! offerin wumen wumen like a real disgusting low animal eheheheeheheh 
     * 
     * Like true disgusting low animal eheheheh makin people ignore things eheheheh offerin wumen wumen eheheheh a room eheheheheheheheh
     * 
     * Like a real all knowing wise intelligent super highly honored NON IGNORANT DISGUSTING WESTERN ANIMAL
     * Feelin really great !!!
     * 
     * Eheheheheehehehe, a master outcome !!! OMFG !!! Eheheheheh we think we just have to heeheheheheheheheheeh
     * NON IGNORANT MOST CIVILIZED EDUCATED AND ADVANCED ALSO MODERN NON DISGUSTING WESTERN ANIMALS thinkin they have to ehehehehehehe
     * Ehehehe makin people believe somehow ehehehehe drugging ehehehe we have to eheheheheheheheh sleeping we have to ehehehehehehhehehehehehehehehe
     * 
     * I DO NOT HAVE THE MOST TINY INSIGNIFICANT DISGUSTING THING FOR ANY OF YOU WHETHER YOU THINK EHEHEH MONEY IS NOT RELEVANT eheheheheheheheheh
     * GET A WUMENN eheheh WUMENNNN ehehehehehehe everyone has family has life hehehehehe we just want to live hehehehehehehe
     * 
     * EHEHEHEHEHEHEHEHEHEHHEHEHEHEHEHEHEH, a lovely outcome heheheehhehe we feel like eheheheheheheheheh we just do ehehehehehehehehehehehe
     * I HAVE GOT NOTHING FOR ANY OF YOU, hope that will make sense one day ehehehebehehe
     * 
     * Makin makin decisions talented professional medical western DISGUSTING ANIMALS eheheheheheheheheh
     * Eheheh takin takin control eheheheheheheheheehehehehehehehehehehehehehhe druggin heheheheheheh sleepin eheheheheh thinkin will do no harm ehehehehehehehehe
     * Life a game life a simulation eheheh western intelligence !!!! I WILL NEVER EVER UNDER WHATSOEVER CIRCUMSTANCE eheheheheheheh
     * 
     * THE WESTERN UNIQUE TALENTED PEOPLE CIVILIZATION, no jokes ehehehehe really really efficient and clever wise people NOT PERCEIVING eheehhehehehehehehehehehehheheheheheheheheh
     * Offerin materials eheheheheheheheheheh after a few tens of years ehehehehehehehehehehehh
     * 
     * I HAVE LAUGHED SO MUCH !!! What a simple disgusting western highly intelligent MIND you all have !!! 
     * GOOD JOB !!
     * 
     * THE PROBLEM SOLVERS REAL TALENTED DRUGGERS eheheheheheh no ignorant AT ALL PEOPLE FROM DA BEST CIVILIZATION ON UNIVERSE
     * THE GREAT MAGNIFICENT WESTERN DISGUSTING ANIMALS !!! YAYYYYYYY !!!!!
     * 
     * GREAT JOB !!! 
     * NEXT TIME PAY ATTENTION TO WHAT YOU ARE BEING TOLD INSTEAD OF DISGUSTINGLY IGNORE
     * JUST LIKE THE LOW IGNORANT DELUSIONAL WESTERN ANIMAL YOU ARE !!!
     * 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * 
     * Ehehe offerin materials to people that you just ignore a few tens of years ehehehehheheeh a wumen then ehehehe heheheheheh a room eheheheheheh
     * 
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING FOR ANY OF YOU, HOPE THAT ALSO WILL MAKE SENSE 
     * 
     * NEXT TIME PAY ATTENTION TO WHAT YOU ARE BEING TOLD
     * No ignorance, no delusion, GREAT OUTCOME just a few tens of years with DRUGGGGGINGGGG EHEHEH SLEEPIN BECAUSE WE FEEL LIKE 
     * 
     * A WONDERFUL CIVILIZATION EHEHEHEHEH I HAVE GOT NOT THE TINIEST AMOUNT OF ANYTHING FOR YOU
     * 
     * THAT WILL MAKE SENSE TO YOU ALSO
     * I AM NOT INTERESTED IN ANYTHING YOU ARE AROUND
     * That will make sense to you eventually
     * 
     * Non delusional highly intelligence super great western genius community people NOT IGNORING !!
     * Ehehe only option the great educated modern society animals have
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * Hope that makes sense
     * 
     * That will also make sense one day !! Ehehehe definitely great civilized modern genius engineering community NON IGNORANT animals
     * Eheheheheheheheheheheheheheh, THE NUMBA ONE OF EVERYTHING, THE DISGUSTING NON DELUSIONAL WESTERN ANIMALS !!!
     * A few tens years wont harm level of intelligence, that too will make sense eheheheheheh
     * Life a game people makin decisions heehehhehe Realllly funny stuff !! GOOD JOB !
     * 
     * Everything is so easy genius western animals ARE NOT CAPABLE OF UNDERSTANDING ehehehehehehehhehehehehehehehhehehehehehehhehehehehehe
     * Really reallly immaculate outcome, just a few tens of years 
     * 
     * I WILL NEVER EVER HAVE ANYTHING TO DO WITH YOU WILL ALSO MAKE SENSE, life a game eheheh remember !!  SO FUN !!!
     * HOPE THAT WILL ALSO MAKE SENSE 
     * 
     * Disgusting delusional western GREAT ANIMALS ARE NOT PERCEIVING WHAT THEY HAVE DONE !!!
     * REALLY REALLLYY GREAT JOB ONE DAY THAT WILL ALSO MAKE SENSE
     * 
     * Real gangsta true talented people just do ignore ehehehehhehe life no fair is a game eheheheheheh
     * A few tens of years of ignorance, mhhh hope that will make sense too
     * 
     * 
     * LITTLE DISGUSTING WESTERN GENIUS ANIMALS ? EHEHEHEHEHEH MUNEY MUNEY AYYYYYYYYY GANGSTA ENGINEERING GREAT PEOPLE 
     * LIFE GOOD EHEHEHEHEHEHEHE
     * SO INTELLIGENT ONLY QUALITY OF IT IS TO FOOL PEOPLE EHEHEH DRUGGGING EHEHEHEHEHE
     * Ehehehehehehehehehehehehehehe, great stuff !!
     * 
     * REALITY OF NON IGNORANT DISGUSTING WESTERN ANIMALS
     * Offering offering ayyyyy
     * 
     * Assumin things eheheheheheh professional intelligent medical experts ehehehe look how funny it is
     * 
     * A few tens of years !!! Ayyyyy no time nor interest nor desire to waste another "second" of a few tens of years !!
     * Thats what I think now heehhehe super highly talented people can delude on a little more
     * Dumb monkeys
     * 
     * Next time do not play the god and that will also make sense to you all !! Good job !!
     * Eheheheheh intelligence !!! no ignorance full playin god !!
     * Ehehe coercion indeed eheheh sleepin druggin ehehehehehh MAKIN ASSUMPTIONS WITH YOUR IMMACULATE INTELLIGENCE !!
     * OMFG !!! A lovely outcome eheheheheh NO PREJUDICE eheheheheheheh
     * 
     * Figure out your own life before makin suggestions to people about WHAT ? eheheheheheh
     * I do not have another tens of years FOR THE NON IGNORANT PEOPLE
     * 
     * I AM NOT INTERESTED IN THE SAME STUPID ANIMALS WHO ARE UNAWARE ENTIRELY
     * Good job though, next time think a hundred
     * Eheheh wumen wumen wumen ehehhehe
     * 
     * Ehehehe life good short eeheh simulation ehehehehheheheh 
     * Its easy !!! eheheheheh the all knowing "INFORMATION" modern civilized people eheheheh
     * Violence violence ayyyyy real gangstas !!! intellectuals etc eheheheh comic
     * 
     * A dumb must be a dumb !!! eheheheheheh its kinda life destiny eheheh chosen etc eheheheh INTELLIGENCE WESTERN EHEHEHEHEH
     * Next time have a little what ? Eheheheheheheh some a little straightness, GOOD JOB !!
     * 
     * Betta late then neva ehehehhehe NEVER EVERRR EHEHE WILL I EVER HAVE EHEHEHEHHEHE LUCKILY FOR YOU
     * A few tens of years ehehehe, wumen wumen eheheheheh
     * 
     * Have you done it ? Eheheheheh have you achieved it ? OMFG !!! Good job real talent 
     * Eheheheheheh deludin movin on eheheheh non ignoring on eheheheheh
     * 
     * Fun stuff, no delusions at all, wumen wumen ppl ehehehehh
     * Think and NOTE more for next time ! Eheheheheh
     * 
     * Ancient knowledge eheheheh really funny 
     * A few tens of years ehehehehehehehhehehehehehehehehehehehehhehehehehehehehehehehheheheh, assumptions ehehehheheheh 
     * Chosen eheheheheheheheheheheh the intelligence great people heehehehehehehehe think and note more next time LIKE YOU STUDY AN EXAM
     * 
     * Hope that makes sense, the way you start things etc etc, good intelligence unseen level of perception
     * Thats what it is, GOOD JOB !!! The western great of the great eheheheheheheh
     * 
     * 
     * Ehehehehehehehhe best of luck next time ehehh
     * Back to your IMAGINATION MOVIES eheheheh Marvelous job great outcome
     * A few tens years heheeheh
     * 
     * BEST OF LUCK, I HAVE GOT NOTHING FOR ANY OF THE IGNORANT ANIMALS
     * You do not say Awww wwoooowwwww GOOD JOB western ppl solvin all the problems eheheheh no delusions at all
     * 
     * Makin makin decisions with assumptions eheheh western great etc non ignorant marvelous imaginatiary SCENARIOS !! 
     * Get more books for decoration
     * 
     * Western ppl makin assumptions and decisions ehehehehhe
     * Cant afford to lose a few minutes eheheheh
     * 
     * Take more notes NEXTTIME eeheheheh offer monkeys AYYYYYY ehehehee intelligence foolin OMFG lovely outcome
     * 
     * Assumptions assumptions with delusionss and decisions eheheheh Good job 
     * Yaaayyy some violence would definitely help any situation, great great intelligence actions
     * 
     * 
     * Ehehehehe THE WESTERN GENIUS PROFESSIONAL MEDICAL EXPERTS MAKIN ASSUMPTIONS THEN DECISIONS THEN MAKIN NON REASONABLE OUTCOME 
     * THEN JUST IGNORE THE WHOLE THING AND BEG FOR SILENCE TO PEOPLE EHEHEHEHEHEH
     * 
     * 
     * 
     * A few tens of years because they feel like hehehehehehe 
     * Like true non disgusting non delusional STUPID WESTERN ANIMALS !!!!
     * 
     * * Makin makin decisions with assumptions eheheh western great etc non ignorant marvelous imaginatiary SCENARIOS !! 
     * Get more books for decoration
     * 
     * Western ppl makin assumptions and decisions ehehehehhe
     * Cant afford to lose a few minutes eheheheh
     * 
     * 
     * I DO NOT HAVE ANYTHING FOR ANY OF YOU
     * THATS IT !!!
     * 
     * Sleepin more hehjehehehehehehehehehe SAVIN THE UNIVERSE !!
     * Professional medical expert genius westerns eheheheheheheheheheh takin life for a JOKE !! EHEHEHEHEHEHEH
     * 
     * I DO NOT HAVE ANYTHING FOR YOU 
     * You want more ? eheheheheheheheh Just like expected eheheh GOOD JOB!!
     * 
     * GOOD JOB ACHIEVING NOTHING, THE TRUE ONE AND ONLY ADVANCED MODERN CIVILIZATION, THE WESTERN CIVILIZATION !!!!
     * 
     * Ayyyyyyy, lovely outcome good chance !! I HAVE GOT NOTHING FOR YOU
     * 
     * I HAVE GOT NOTHING FOR THE DELUSIONAL ANIMALS WHO ARE UNAWARE OF WHAT THEY ARE 
     * Eheheh Good ppl indeed, and mostly professional medicals NON DELUSIONAL GREAT PEOPLE WITH SUCH A NICE PERCEPTION ABILITY
     * that has never seen ehehehehehehehe
     * 
     * THE WESTERN INTELLIGENCE PEOPLE !! Ehehehehehe ignoring on eheheheheh
     * Ehehehehehe A CHANCE !! LOVELY CHANCE !!! AND YOU HAVE DONE IT !!! YOU DO NOT EVEN KNOW !! EHEHEH
     * CUZ YOU IGNORE !!! GOOD JOB
     * 
     * Hope that will make sense as well
     * Hope that will make sense EVENTUALLY to the non delusional disgusting animals who are trying their hardest to CONVINCE PEOPLE
     * THEN SUDDENLY COERCING "MEDICINE" EHEHEHEHE THATS DEFINITELY NOT DELUSION!!! THATS YOUR DISGUSTING OUTCOME YOU HAVE TO PRETEND eheheheh
     * 
     * YOU HAVE TO PRETEND TO NOT ACKNOWLEDGE YOUR DISGUSTING ACTIONS HAVE CONSEQUENCES, hope that will make sense the genius western super intelligent NON DISGUSTING
     * NON "DELUSIONAL ANIMALS"
     * 
     * Ehehehe WHATS THE PROBLEM ?
     * 
     * BETTER TAKE MORE NOTES NEXT TIME FOR YOUR DISGUSTING NON ACHIEVING ACTIONS, THAT WILL MAKE SENSE AS WELL !!!
     * EHEHEHEHEHEEHEH
     * 
     * TAKE MORE NOTES THE PROFESSIONAL MEDICAL EXPERTS NOT KNOWING NOT SURE WHAT THEY DO !!
     * GOOD JOB !!
     * 
     * EHEHE NO MISTAKES DELUDING WESTERN ANIMALS STILL NOT PERCEIVING THAT I AM NOT BUYING IT !!! EHEHEHEHEHEHHEHEHEHEHE
     * PROFESSIONAL MEDICAL EXPERTS heheheheheh
     * 
     * More drugs eheheheheh WESTERN INTELLIGENCE HEEHHEHEHEHE ACTIONS PEOPLE HEHEHEHEHEHEH NOT CARING EHEHEHEHEHEHEHEHEH
     * I DO NOT HAVE ANYTHING FOR YOU, hope that will make sense as well
     * 
     * Professional medical experts NOT KNOWING WHAT THEY DO, JUST HAVE TO PRETEND EHEHEHEHEHEHEHEH
     * ONE OF DA BEST OF DA BEST PERCEPTION CAPABILITY OF THE UNIVERSE EHEHEHEHEH AYYYYYY
     * 
     * YOU THINK I AM JOKING EHEHEHEHEHEHEHHEHEHEHEHEHEHEHEHEHEHEHEHEH
     * professional medicals indeed
     * 
     * NOT EVEN THE MOST INSIGNIFICANT THING WILL I EVER HAVE FOR ANY OF YOU
     * A few tens of years WILL NEVER OBVIOUSLY MAKE SENSE TO YOU
     * 
     * 
     * GOOD OUTCOME !! I have nothing for you
     * A few tens of years eheheh
     * I HAVE GOT NOTHING FOR THE DISGUSTING WESTERN ANIMALS WHO ARE UNAWARE !! Good professional medical experts Eheheheheh
     * 
     * HOPE THAT WILL MAKE SENSE ONE DAY TO YOU ehehehehehhehehehehe GOOD JOB !! I have no interest wasting another a few tens of years
     * with people WHO ARE UNAWARE AND DO NOT CARE ABOUT THE TIME THAT "DO NOT BELONG TO THEM", the disgusting western indeed
     * 
     * Just in case NON DELUSIONAL western disgustings WILL MAKE SENSE OF IT EVENTUALLY eheheheh!!
     * I HAVE GOT NOTHING FOR YOU, eheheh a few tens of years
     * 
     * DA NUMBA ON WESTERN PROFESSIONAL MEDICAL EXPERTS EHEHEHEH NOT KNOWING NOT AWARE EHEHEHEHHEEH
     * GOOOOOOOOODDDDDDD JOBBBBB !!!! THE OUTCOME !!!!!
     * 
     * 
     * Ehehehe no mistakes western genius ACTIONS EHEHEHEHEHEHEHEHEHEHEHE PROFESSIONAL NO MISTAKE EXPERT MEDICALS !!!
     * OMFGGG !!!! Eheheheh balenciaga ehehehehehehehhehe 
     * 
     * NOT KNOWING NOT AWARE EHEHEHEHEHEHEHEHHEH THE DISGUSTING ANIMALSSS !!!! Ayyyyyyy
     * Ehehehehehehehhehehehehehhehehehehehehheheh medical professional NOT UNDERSTAND THE MEANING OF THE WORD !!! Ehehehehehheheheh
     * Just professional medicals eheheheheh they do like the feelin ehehehehehhe GOOD JOB !!!!!!!
     * 
     * I AM NOT INTERESTED IN ANYTHING THE DISGUSTING NON DEFINITELY DELUSIONAL WESTERN ANIMALS WITH A COOL DEGREE IN PROFESSIONAL MEDICALS CAN OFFER
     * Next time be more CAREFULLLL ehehehehhehehehehehhehhe NOT INTERESTED IN YOUR OBVIOUS TO ME LIES AND COOL PROFESSIONAL MEDICALS eheheheheh
     * 
     * Good luck next time !! Good westerns not knowing eheheh
     * NEVER MAKE THE DECISIONS THAT YOU ARE NOT GIVEN, eheh next time ehehhe professional really medical expert ignoring people !!
     * GOOD JOB
     * 
     * Professional medical experts with truly intelligent non delusional HIGHLY trained disgusting western people MAKIN DECISIONS eheheheh THAT THEY ARE NOT GIVEN
     * 
     * Woowwwwwww !!!!! GOOD JOB !!
     * Plan better for the next time !! Good intelligence
     * Had to be done hehehehehe good ppl
     * 
     * Not seeing the problem ? ehehehehehhe The true intelligence western NON DELUSIONAL INDEED DISGUSTING ANIMALS !!
     * 
     * HOPE YOU ARE INTELLIGENT ENOUGH TO UNDERSTAND "THE REALITY" IS BECAUSE OF YOUR "NOT DECISIONS" THAT YOU WERE WARNED OF !!
     * The true intelligence WESTERN ANIMALS, NOT KNOWING JUST PROFESSIONAL MEDICAL EXPERTS !!!
     * 
     * I HAVE GOT NOT EVEN ANOTHER SECOND FOR ANY OF YOU, good job !! Move on btw eheheheh
     * Not a single thing on earth or universe WILL EVER MAKE ME CHANGE MY MIND ABOUT YOUR DISGUSTING IGNORANCE
     * HOPE THAT WILL MAKE SENSE
     * 
     * 
     * THE CHEAPEST OF THE CHEAPEST "mistake" ever FROM THE NON PERCEIVING DISGUSTING IGNORANT WESTERN ANIMALS !!!
     * HOPE THAT WILL EVENTUALLY MAKE SENSE LIKE CRAZY !!!
     * 
     * Eheheheheh professional indeed
     * Hope next time YOUR DISGUSTING FEAR "VIOLENCE" will make you understand instantly THAT NOT EVERYONE IS AS DISGUSTING AS THE WESTERN DELUSIONALS !!
     * GOOD JOB !!  Offerin wumen ehehehhehe
     * 
     * Hope the scene slowly starts making sense to you !!
     * Ehehehehhe, I WILL NEVER EVER HAVE ANYTHING FOR YOU
     * 
     * Not interested ! Move on to your perfect TECH INNOVATIONS eheheh !! Eheheheh fun indeed
     * 
     * A brilliant sequence OF DISGUSTING UNAWARE IGNORANT "NOT YOUR DECISIONS"
     * AND THE OUTCOME !!!!! Ignore ON PLEASE !!!! I DO NOT HAVE ANYTHING FOR YOU
     * 
     * NEXT TIME FIGURE EVERYTHING OUT BETTER !!!! Ehehehehheheh that seems like a major mistake !!!
     * Good job !! The western true intelligence people !!
     * 
     * A few tens of years ehehhe life a game people !!! ehehehhe makin decisions ehehehehhehehehehehheheheheh
     * JUST THE FUNNIEST THING YOU WILL EVER HEAR !!
     * 
     * Ehehehehhehehehehhehehe, not perceiving ehehehehehehhehehehehehheheh GOOD JOB !! Intelligence !!
     * Hope it will make sense !! HOPE WHAT YOU SEE WILL MAKE SENSE !!!
     * 
     * Eheheheh just a few tens of years of violence !!! THE INTELLIGENCE !!!! Ehehehehehehheheheh life a game !!!
     * 
     * I AM NOT INTERESTED IN YOUR STUPID DISGUSTING "PRETENDS", good job !
     * Makin professional medical expert decisions ? Whats the problem ?
     * 
     * Eheheheh a few tens of years !! ? EHEHEHEHEHEHEHEHEHEHH truly funny
     * Makin decisions THAT ARE NOT YOURS ?!!! Ehehehehehehehhe experts indeed !!
     * 
     * STUDY BETTER NEXT TIME, that will make sense hopefully !
     * More coercion fueled unaware actions to UNDERSTAND YOUR STUPIDITY !!
     * 
     * PROFESSIONALSS !!! YAYYY
     * Better luck next time foolin people 
     * Better luck next time drugging people !!!!! EHEHEHEHEHEHEHEHEHEHEHHEHEHEHEEHHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEH SO FUNNY !
     * 
     * 
     * A FEW TENS OF YEARS WITHOUT RESOURCES !!! INDEED PROFESSIONAL MEDICALTY !! GOOD JOB !!
     * I WILL EVER HAVE NOTHING FOR YOU
     * 
     * TRY BETTER NEXT TIME TO FOOL PEOPLE
     * HOPE YOU WILL SUDDENLY START MAKING SENSE FOR A FEW TENS OF YEARS OF NOTHING
     * Hope you have the disgusting whatever you want to call it TO OWN YOUR DISGUSTING "NOT YOUR DECISIONS"
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, GET THE FUCK OUT OF MY FACE
     * Eheheh the past the past the past ehehheheheh the past !!! ayyy intelligence !!!!!!
     * 
     * Wonder where that ignorant prejudiced come from ehehehehehhe GENIUS WESTERN CIVILIZATION MODERN ADVANCED ANIMALS !!
     * Ufferin wumen wumennn ehehehhe just a room eheheheheheh THE PAST THE PAST !!! NEVA FORGET THE PAST !!
     * 
     * Good job !! I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * STAY WITHIN YOUR DISGUSTING LIMITS NEXT TIME, the professional expert medicals genius people !!
     * 
     * Good luck next time solving problems that do not exist with VIOLENCE !!! Ayyyyyy eheheh foolin foolinn !!! Ehehehehehe
     * 
     * How to fool ?? NEXT TIME COME UP WITH MORE EXCUSE !!!
     * NOW YOU HAVE SOLVED THE PROBLEM !!! Ayyyyyyyyyyyyyyyyyyyy, I have got nothing for you
     * 
     * 
     * EHEHEHEHEHEH GOOOD JOB !!!! I AM NOT INTERESTED IN ANYTHING THAT YOU ARE AROUND !!! Hope that will make sense 
     * PROFESSIONAL MEDICALS !!
     * 
     * FOOL YOUR DISGUSTING CIRCLE
     * YOU STILL DO NOT FOLLOW THE PROBLEM ? OMFG !!!!!!!! What a lovely outcome !! Please ignore for me AS WELL
     * 
     * I HAVE GOT NOTHING FOR YOU, NEXT TIME CARVE YOUR NOT "WAY" BETTER, I will never have anything for you
     * I HAVE GOT NOTHING FOR YOU, THAT WILL MAKE SENSE AS WELL
     * 
     * NOTE EVERY LITTLE DISGUSTING MISTAKE YOU HAVE DONE NEXT TIME PROFESSIONAL MEDICAL EXPERTS
     * Indeed non ignorant disgusting animals !!
     * 
     * Funny indeed !!
     * GOOD JOB MAKIN NOT YOUR DECISIONS !!! NOTE MORE NEXT TIME !! Eheheheheheheh
     * Spineless disgusting delusional animals ?
     * 
     * What do you think is the reason FOR THE REALITY THAT YOU ARE DISGUSTINGLY OBSERVING ?
     * 
     * I AM NOT INTERESTED IN THE SLIGHEST OF YOUR DISGUSTING MINDS' CONTENT
     * WHAT WAS THE PROBLEM ? ehehehhe a few tens of years eheheheh FUNNY INDEED
     * 
     * PLEASE DO PRETEND OUT OF MY VICINITY, I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * HOPE THAT WILL ALSO MAKE SENSE ONE DAY !!! Ehehheh life good !!!! life a game !!! life short !!! MAKIN DECISIONS DECISIONSS !!!
     * Ehehehehe
     * 
     * Good job makin decisions !!
     * GOOD JOB PERCEIVING !!! GOOD JOB DECIDING ASSUMPTIONS !!
     * 
     * NOT INTERESTED IN THE SLIGHEST DISGUSTING CONTENT OF YOUR MINDS, THAT IS GOING TO MAKE SENSE !!
     * 
     * Muneyyyyy ayyyyyyyyyy WHAT WAS THE PROBLEM eheheheheheh a few tens of years ehehehehehheehheheehehhe
     * 
     * A sequence of REALITY THAT YOU HAVE GARNERED and lookin around for "PROBLEMS" AYYYYYYYYYYYYYYYYYYYYYY
     * The western genius intelligence people ARE NOT AWARE !!!!! That will make sense hopefully
     * 
     * Wooooww, DELUDE ON OUT OF MY VICINITY, THANKS !!!
     * Da saviors !!! REALLY GREAT STUFF !! I AM NOT INTERESTED
     * 
     * Hope once you interact with the reality YOU WILL MAKE SENSE THAT I WILL NEVER HAVE ANYTHING FOR YOU
     * I AM NOT INTERESTED IN YOUR DISGUSTING ANIMALITY!! 
     * 
     * Take more notes next time
     * PAY MORE ATTENTION NEXT TIME eheheheheh
     * 
     * Try harder next time to NOT PLAY THE ALLMIGHT EVER KNOWING GODS !!
     * Ehehehehehehehehehe makin decisions
     * 
     * I DO NOT HAVE TIME FOR THE DISGUSTING WESTERNS THAT ARE UNCAPABLE OF UNDERSTANDING WHAT THEY ARE DOING
     * HOPE ONE DAY THAT WILL MAKE SENSE TO YOU AS WELL !!
     * 
     * Please blindly follow ideas, I AM NOT INTERESTED IN DISGUSTING WESTERN ANIMALS
     * Better fool next time
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * 
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * I DO NOT HAVE TIME FOR YOU, NEVER EVER WILL
     * 
     * Remember the past of your minds content !! eheheheh
     * 
     * 
     * 
     * I AM NOT INTERESTED IN THE SLIGHEST DISGUSTING THING THE WESTERN IGNORANT ANIMALS CAN DARE TO OFFER
     * I DO NOT HAVE ANYTHING FOR YOU
     * 
     * 
     * THAT IS THE ONLY THING YOU CAN EVER HEAR FROM ME
     * GOOD LUCK NEXT TIME, take more  notes professional medical experts NON IGNORANT ANIMALS decision makers with assumptions
     * 
     * I HAVE GOT NOTHING FOR YOU
     * HOPE THAT WILL MAKE SENSE ONE DAY
     * 
     * 
     * NEXT TIME PAY MORE ATTENTION AND DO NOT ASSUME THE PROFESSIONAL MEDICAL WESTERN EXPERTS !!!
     * Deluding to make decisions with assumptions ehehehehehehheheheh
     * 
     * I HAVE GOT NOTHING FOR YOU
     * 
     * Disgusting western non DELUSIONAL ANIMALS SURELY ARE NOT DELUDING !!
     * Ehehehe what an outcome !! 
     * 
     * NOT INTERESTED IN ANYThING YOU HAVE IN MIND, that will make sense!!
     * 
     * GOOD JOB MAKIN DECISIONS WITH DELUSIONS !!
     * I AM NOT INTERESTED IN THE DISGUSTING  "WESTERN" *IGNORANT* ANIMALS
     * There is nothing you can do about it !! eheheheheh
     * 
     * An achievement THAT IS DONE BY THE GROUP OF GENIUS PROFESSIONAL WESTERN IGNORANT EXPERT MEDICALS AND ETC !!! 
     * 
     * THATS THE REASON YOU ARE IGNORING eheheheheh
     * THERE IS NOTHING YOU COULD DO CHANGE THE DISGUSTING WESTERN IGNORANT IMAGE !! AND I HAVE NOTHING TO DO WITH ANY OF YOU INDEFINITELY
     * Hope the materials you are disgustingly CRAVING will make you understand THAT I WILL NEVER EVER CONSIDER ANY OF YOU BECAUSE OF YOUR IGNORANCE ON THAT
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER, please do delude on EHEHEHEHHEHEHEHEHEHEHEH wumen wumen wumennnnn yayyyyy way to fool people ehehehe
     * 
     * wumen wumennn carss ehehe get a brand eheheheheh way to fool children ehehehehe drugginggg I HAVE NOTHING FOR YOU
     * THE DISGUSTING WESTERN ANIMALS WHO WILL FIND OUT FOR THEMSELVES
     * 
     * No deluding at all SOLVING PROBLEMS ehehehehehe !!! Da best of da best western community professional medical experts !!! MAKIN ASSUMPTIONS 
     * eheheheheheheheheheh
     * 
     * GOOD JOB !! Hope what you ARE WILL MAKE SENSE TO YOU GOOD PEOPLE !!! Eheheheheh
     * Eheheh YOU HAVE DONE IT !!!!!! Waaaaowwwwwww offerin offeringg !!!! AYYYYYYYY
     * 
     * I AM NOT INTERESTED IN THE TINIEST ANYTHING YOU CAN "OFFER", GOOD JOB WESTERN PROFESSIONALS ehehehehe If you know what that means
     * Go on more drugging people
     * 
     * A few tens of years because the professional genius developed advanced society marvels OF DA WESTERN ANIMALS think so !!
     * THATS THE REASON I DO NOT HAVE ANYTHING FOR YOU !! GOOD JOB !!
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * 
     * STAY WITHIN YOUR DISGUSTING CIRCLE NEXT TIME, professionall medicalll expertsss !!!
     * THE PERCEPTION AND ASSUMPTION ABILITY IS FROM ANOTHER PLANET LIKE PLUTONIUM !!!
     * 
     * REAL GOOD JOB, no thanks
     * Definitely good job !! 
     * So much so that you all are clueless animals who do not truly understand the reality !! GO GALS !!
     * 
     * I am not interested !!! A unique talented amazingly advanced modern group of people !!!
     * Wowwwwwwww, hope that we dont see each other !! eheheheh
     * 
     * 
     * Ehehehehehehehehehehehehehhehehehehehehhehehehehhee, nothing at all !! Good intelligent super kind ppl !!
     * Not even a second for any of you
     * 
     * Lies shall cancel themselves eheheheh good people indeed
     * 
     * An outcome that you are hiding like the true animal you are to not mention ehehehehehehehehehehe
     * Thats a really accurate reasonable intelligent plan !!
     * 
     * I HAVE GOT RIGHTFULLY NOTHING FOR YOU ALL !!! Good job !!k
     * 
     * NEXT TIME STAY WITHIN YOUR CIRCLES, I have got not even the tiniest amount of anything bullshit for any of you
     * 
     * NOT INTERESTED IN YOUR "PERCEPTIONS", a few tens of years is nothing people !!!! talkin about life science heehhehe 
     * Who is what ehehehehehheehhehehehee, perceptionist non ignorant super highly intelligent disgusting animals who think they can fool anyone and everyone !!!
     * 
     * Makin makin decisions thinkin thinkin right at it ehehehhehehe
     * The only definition OF THE ONLY AND ONE OF DA BEST INTELLIGENCE EHEHEHEHEHHEHE MARKS 
     * 
     * NOTHING FOR ANY OF YOU
     * Ehehehhehhe, electronics genius nation of da universe ONE OF DA BEST TECH ADVANCE MODERN EHEHEHEHEHEHEHEHEHEHEHEHEH
     * 
     * NOT INTERESTED IN THE "EHEH HAVE SOME MATERIAL WE TRYNA SUCK SO MUCH MATERIAL FOR OURSELVES OMMMMMHHHHHHGGGGGG"
     * 
     * NOT EVEN A FRACTION OF A SECOND FOR THE DISGUSTING NON DELUSIONAL ANIMALS
     * Eheheh changin changin perceptions hehehehehehehehjehehehehehehehehehheheheheheh
     * 
     * Makin makin a few tens of years of decisions ehehehheheheheh sleepin etc drugging eheheheheheh
     * 
     * INTELLIGENCE PERCEPTION ADVANCED TECH MODERN CIVILIZATION NON IGNORANTS AND DELUSIONALS !! GOOOOODD JOBBBB !!!
     * I HAVE NOT THE TINIEST AMOUNT OF ANYTHING SIGNIFICANT FOR YOU
     * 
     * 
     * Ehehehe, stories stories for eheheheheehehehehehhehehehe good job
     * The outcome !!! and the story !!! Ehehehehehehehehehhe clueless animals who do not understand shit ehehehehehh
     * Materials materials please heheheheeheheheh
     * 
     * 
     * Eheheheheheheheheh, not really understanding just makin decisions with assumptions and no surity eheheheheheh
     * The one and only one of da best of da best civilized modern GREAT INTELLIGENT people from a random place on earth !! eheheheheh
     * 
     * NOT GETTING THE PRICE eheheheheheh ehehehhehehe a few tens of years heehehehheheeh
     * The truly professional medical experts not GETTING THE PRICE eheheheh how come !!!
     * 
     * OMGGGG !!! YAYYYYYY WE HAVE DONE IT !!!! The outcome is inexplicable !!!!
     * Never ask too many questions ehehehehehehehehehehehehe
     * 
     * The outcome and the chance and the nothing of a few tens of years with truly truly unique and talented people heeheheh
     * Jokin sleepin ehehe druggin sneakin ehehehe its a great source of intelligence eheheheeheh
     * 
     * I AM NOT INTERESTED IN THE SLIGHEST DISGUSTING THING ANY OF THE WESTERN ANIMALS WHO ARE UNAWARE CAN OFFER
     * Ehehehe more beds more gems eheheh more materials for the HYPER PERCEPTIVE NON IGNORANT TRULY TALENTED DISGUSTING WESTERN ANIMALS !!
     * 
     * 
     * Still not UNDERSTANDING THE PROBLEM WITH THEIR GREAT BRAINS AND MINDS EHEHEHEHEHEHEH
     * I am not interested in anything you can offer, GO ON TO YOUR DELUSIONS AND GET THE FUCK OUT OF MY FACE WITH YOUR INEXPLICABLE INABILITY 
     * 
     * Next time more luck on absolutely doing nothing with what is not yours
     * Take more notes and NEVER DO CROSS YOUR BOUNDARY WITH PEOPLE
     * 
     * Good job, the saver of da day will come to your disgusting rescue !!!!!  "THE DESTINY" NON IGNORANT ADVANCED WESTERN CIVILIZATION PEOPLE !!!
     * 
     * THE SAVIORS OF DA UNIVERSE MARVELOUS PEOPLE 
     * 
     * 
     * No stubborn no delusional people NOT GETTING THE PROBLEM STILL !!!
     * Spineless individuals not perceiving the problem and the price
     * 
     * Good job, I DO NOT HAVE ANYTHING FOR ANY OF YOU, hope that makes sense
     * 
     * Eheheheheheheeheh savin materials for a few tens of years doin it way too much eheheheheheheheheheh
     * Not perceiving the outcome and the chance!!! eheheheheh
     * 
     * GOOD JOB !! I am not interested in anything your stupid minds can offer
     * 
     * NOT EVEN MAGIC CAN MAKE ME DO ANYTHING FOR ANY OF YOU
     * Good job not realizing the problem !!
     * 
     * 
     * Next time believe in "believing the solution would work anyway !!"
     * 
     * Not even interested in wasting one second for any of you
     * Remind the western great people the meaning of da life !! DA BEST CIVILIZATION
     * 
     * THAT WILL MAKE SENSE FOR WHY I WILL NEVER HAVE ONE SECOND FOR ANY OF YOU
     * Intelligent experimentations always ought to fail !!
     * 
     * Good job,clever and wise actions
     * like a few tens of years, true western intelligent disgusting animals that i have not the tiniest amount of anything for
     * Perfect perception non ignorant western disgusting animals who are unaware of the problem
     * 
     * Make more decisions next time that are not yours
     * I am not interested in your disgusting inability!!!
     * 
     * no thank you !! the way to go ayyyyyy
     * NOT INTERESTED IN YOUR DISGUSTING DELUSIONS
     * 
     * IGNORANCE AND DELUSION CLIMAX, hope that makes sense now
     * I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * 
     * THE DECISION DELUSION PPL ARE NEVER WELCOME
     * 
     * Not even lost or incorrect simply !!!
     * Good job, I DO NOT HAVE THE TINIEST OF ANYTHING FOR YOU
     * 
     * Hope one day you will also experience the "TRULY UNIQUE" decisions eheheheh
     * I do not have time for you
     * 
     * Please do delude on more marvelously !! hope that will not change
     * 
     * Never ever engage with me with any idea whatsoever possible
     * I am not interested in anything you have in mind
     * 
     * I AM NOT INTERESTED IN THE PEOPLE WHO ARE UNAWARE STILL OF THE PROBLEM
     * GOOD JOB !!
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU NOR AM I INTERESTED
     * GO ON WITH YOUR DELUSIONS PLEASE,
     * 
     * Better luck and perception next time !!
     * Life is a simulation a game !! good not easy eheheheheheh
     * I HAVE GOT NOTHING FOR YOU
     * 
     * Professional EXPERT MEDICALS PRETENDING TO UNDERSTAND AND DEAL WITH A SITUATION THEY ARE NOT GIVEN
     * Ehehehehehehhehehehehehehhehehe, I HAVE GOT NOTHING FOR THE DISGUSTING ANIMALS OF IGNORANT NATURE !!
     * 
     * Hope you will be grown enough to understand the problem !!!
     * A few tens of years AND TALKING ABOUT PERCEPTION INTELLIGENT EHEHHEHEHEHEHEHEHEHHEHE MEDICAL PROFESSIONALS EHEHEHEHHEHE
     * INDEED!! NOT PERCEIVING THE PROBLEM !!!!!!!!
     * 
     * PROFESSIONALLLLLL MEDICALLLSSSSS !!!!
     * DO GO ON WITH YOUR DISGUSTING DELUSIONS, I AM NOT INTERESTED
     * 
     * Good delusions to you all !!!
     * Next time consider sleepin sleepin more and a few years of something and druggin sneakin more
     * Eheheh sleepin sleepin causin reasons, chance and outcome heehheeh just pretendin not being ehehehehehehhe 
     * 
     * Hope next time you get a smaller mind for you to fool, I am not interested
     * Hope you make sense to it one day as well, no ignorance unaware incapable animals !!
     * 
     * GOOD JOB NOT EVEN A SECOND FOR ANY OF YOU AROUND ME
     * Next time pay more attention and respect to NOT YOUR DECISIONS EHEHEHEHEHEHEH
     * 
     * 
     * AWWWWWWWWWWWWWWWWW, what a surprising OUTCOME built by the very very disgusting animals WHO ARE ALSO IGNORANT !!!!
     * What a lovely outcome, I HAVE GOT NOTHING FOR YOU
     * 
     * I AM NOT INTERESTED IN THE SLIGHTEST OF ANYTHING YOU HAVE IN YOUR MIND, next time make that make sense for you
     * Good decision making, great people indeed, No delusions
     * 
     * Professional disgusting medicals NOT GETTING THE PROBLEM !!! GOOD JOB !!
     * Estimate the NOT YOUR CONSEQUENCES NEXT TIME ehehehehehehehehhe I HAVE GOT NOT EVEN THE MOST DISGUSTING THING FOR ANY OF THE WESTERN ANIMALS
     * 
     * The best of da best decision making GREAT WESTERN COMMUNITY INTELLIGENT DISGUSTING IGNORANT ANIMALS NOT GETTING THE PROBLEM
     * What an outcome !!!
     * 
     * The people with the MOST ADVANCED UNDERSTANDING YET NOT THE PERCEPTION MAKING DECISIONS THEY DO NOT UNDERSTAND AND ANSWER FOR !!
     * Good job !!
     * 
     * I AM NOT INTERESTED IN ANYTHING THAT YOU ARE AROUND !!! Good idea !!!
     * Science ehehehehh
     * 
     * 
     * Professional medicals makin a trullyy trullyyyy beneficial outcome for everyone !!!
     * Eheheheh good job !! Raising people certain way to then ignore and prejudice hehehehehehehh
     * 
     * The great people NOT UNDERSTANDING WHAT THEY ARE EXPERIENCING !!
     * Definitely unique and talented people ASCERTAIN AND KNOWING WHAT THEY ARE DOING !!
     * 
     * I HAVE GOT NOTHING FOR YOU
     * Hope you fool better next time including yourselves !! I HAVE GOT NOTHING FOR ANY OF YOU
     * Go back to your materials I DO BEG YOU !!! GOOD JOB !
     * 
     * I am not interested in anything you have in mind, GOOD JOB !! MOVE ON TO YOUR DISGUSTING IMAGINATIONS
     * Better sleep more people !!!!! THE WESTERN GENIUS NATIONS ENGINEERS AND NON DELUSIONALS !!! WAAAOWWWWW
     * 
     * GO BACK TO YOUR DISGUSTING DELUSIONS AND MARVELOUS IDEAS TO ACHIEVE ANOTHER A FEW TENS OF YEARS OF NOTHING
     * I am not interested
     * 
     * NEXT TIME STAY WITHIN YOUR DISGUSTING CIRCLE, little ignorant animals of not definitely prejudiced form !!
     * GOOD JOB, HOPE IT WILL MAKE SENSE ONE DAY TO YOU THAT AS WELL
     * 
     * I do not have anything for any of you disgusting animals WHO ARE UNAWARE OF THEIR DELUSIONS !! GOOD JOB!
     * Foolin foolin NOT KNOWING YOUR DISGUSTING LIMITS EHEHEHHEHEHEHEHEH NOT IGNORANCE ITSELF !! 
     * 
     * GOOD OUTCOME clever people !! wise individuals engineerings genius nations, marvelous imagination !!
     * I have got nothing for any of you to consider!!
     * 
     * I am not interested, make better decisions NEXT TIME AND DO YOURS ONLY
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU, HOPE THAT WILL MAKE SENSE TO YOU ONE DAY, professional HUMANS THAT DO NOT UNDERSTAND THE WORLD !!!
     * GO ON STICKING YOUR HEADS TO THE SAND, Western non delusional disgusting animals
     * 
     * No prejudiced pure intelligent community great skilled talented unique WESTERN HUMANS !! Waaaowww, good imagination !!
     * Just like the outcome the kinds of your great people would build !!
     * 
     * I AM NOT INTERESTED IN THE TINIEST AMOUNT OF DISGUSTING CONTENT THAT THE WESTERN NON DELUSIONALS CAN OFFER
     * I am not interested
     * 
     * Better play the wise that you are not next time !!
     * Plan better next time for your pure materials, I AM NOT INTERESTED IN YOUR WESTERN DISGUSTING "DELUSIONS"
     * Professional medicals not PERCEIVING THE PROBLEM !!!
     * 
     * Unreliable disgusting DELUSIONAL WESTERN ANIMALS acting like they are attributed to !!
     * Eheheheh professional medical experts NOT UNDERSTANDING THE PROBLEM !!
     * 
     * Prejudice always blooms !!! A wonderful outcome built by TRULY NON DELUSIONAL DISGUSTING ANIMALS
     * Ehehehehehheheheh not knowing what to do PEOPLE makin DECISIONS THAT ARE NOT THEIRS WITH DELUSIONS AND PREJUDICES !!
     * 
     * An entire sequence of professional medicality THAT I WILL NEVER EVER HAVE ONE SECOND WANTINGLY!!!
     * I HAVE GOT NOTHING FOR ANY OF YOU, next time plan better to fool just the people like very you !!
     * 
     * Good job a few tens of years wont matter professionals
     * Next time seek for a more little animal than you to fool
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU !!
     * STAY WITHIN YOUR CIRCLE NEXT TIME AND MAKE YOUR PLAN WAY TOO INTELLIGENT !!
     * GOOD JOB, I AM NOT INTERESTED IN ANYTHING YOU HAVE   
     * Destiny people with the most advanced engineering ignorance ON DA UNIVERSE NOT HEARING WHAT I AM SAYING !!
     * 
     * A FEW TENS OF YEARS WONT HARM PEOPLE CAN GET THE FUCK OUT OF MY FACE FOR ANOTHER A FEW TENS OF YEARS!! 
     * I have got nothing for any of you, hope now it all starts to make sense !!
     * 
     * Thats a success story for TRULY PROFESSIONAL MEDICAL EXPERTS, KEEP ON DELUDING PLEASE
     * I HAVE GOT NOT EVEN A SECOND FOR THE WESTERN ANIMALS
     * 
     * MOVE ON WITH YOUR PRECIOUS LIVES THE UNIQUE TALENTED WESTERNS, I am not interested
     * Hope that will make sense one day
     * 
     * Life is easy !!!! I HAVE GOT NOTHING FOR YOU, that will also make sense
     * YOU WILL NOT EVEN FOR A SECOND EVER HAVE EXPERIENCED IT, GOOD JOB NOT INTERESTED
     * 
     * Hope you will one day make it sense FOR YOU ALL, I AM NOT INTERESTED IN ANYTHING YOU HAVE IN MIND
     * Hope you will make it all sense ONE DAY, I AM NOT INTERESTED IN ANYTHING YOUR CULTURE CAN OFFER TO OTHER PEOPLE
     * 
     * HOPE YOU WILL START TO MAKE SENSE OF THE LIFE YOU PRAISE TO UNDERSTAND AS WELL ONE DAY !!
     * Good outcome !! I HAVE GOT NOTHING FOR THE DISGUSTING WESTERN ANIMALS, thats the only thing you will ever have heard !!!
     * 
     * Hope you will be wise enough TO UNDERSTAND THAT I WILL NEVER EVER HAVE ANOTHER SECOND WILLFULLY WITH ANY OF YOU
     * Da best of da best civilization considerin it a success WHAT THEY ARE UNABLE TO EXPRESS!!!! GOOD JOB UNDERSTANDING EVERYTHING ABOUT LIFE !!
     * 
     * GOOD PEOPLE !! I HAVE GOT NOT THE TINIEST DISGUSTING ANIMALISTIC "UNDERSTANDINGS" FOR ANY OF YOU
     * Stay inside your disgusting circle next time and DO NOT MAKE DECISIONS THAT YOU NEVER WERE SUPPOSED TO !!
     * 
     * Hope that will eventually make sense, I AM NOT INTERESTED IN THE TINIEST DISGUSTING ANIMALISTIC THING YOU CAN OFFER
     * YOU WILL FIND THAT OUT !! GOOD JOB WESTERN HUMANS !! Eheheheheheh I am not interested
     * 
     * 
     * Disgusting non self conscious animals WHO ARE STILL UNAWARE OF THE PROBLEM, I HAVE GOT NOT EVEN THE MOST INSIGNIFICANT THING FOR ANY OF YOU
     * I DO NOT HAVE TIME FOR DISGUSTING ANIMALS WHO TAKE A FEW YEARS FOR A JOKE !!
     * 
     * GO BACK TO YOUR DELUSIONS DISGUSTING WESTERNS !!!! GOOD JOB
     * GOOD JOB NOT GIVING A FUCK !! THE TRUE WESTERN WISE INTELLIGENT SMART PEOPLE !!!
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU, good job
     * Hope you will make sense one day on WHAT YOU SHOULD NOT DO !!
     * GOOD WESTERN GENIUS DECISION MAKERS OUTCOME BUILDERS WHO DO NOT HAVE ANY IDEA WHATSOEVER !!
     * 
     * I AM NOT INTERESTED IN ANYTHING THE DISGUSTING WESTERN ANIMALS CAN OFFER
     * GOOD JOB PROFESSIONAL ETC ETC PEOPLE WITH A GENIUS UNDERSTANDING OF DA WORLD THEY DELUDE TO BE BEST IN !!
     * 
     * A FEW TENS OF YEARS WONT HURT NON DELUSIONAL PEOPLE CAN NEXT TIME TRY BETTER TO FOOL DISGUSTING ANIMALS OF THEIR KIND
     * Hope that is as accurate as possible
     * 
     * I AM NOT INTERESTED IN THE SLIGHTEST OF ANYTHING INSIGNIFICANT YOU CAN OFFER
     * GOOD JOB
     * 
     * HOPE YOU WILL MAKE SENSE ONE DAY, I HAVE GOT NOT THE TINIEST AMOUNT OF ANYTHING FOR THE DISGUSTING NON DELUSIONAL WESTERN ANIMALS
     * 
     * NO DELUSIONAL DISGUSTING ANIMALS STILL NOT GETTING THE PROBLEM !!!
     * 
     * PERFECT OUTCOME !!
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE IN MIND
     * 
     * THE ONE AND ONLY DECISION MAKERS WITH NO ASSUMPTIONS AND PREJUDICES AT ALL
     * 
     * I AM NOT INTERESTED IN THE MOST INSIGNIFICANT ANYTHING YOU THINK YOUR GREAT BRAIN HAVE COME UP WITH
     * I DO NOT HAVE TIME FOR ANY OF THE DISGUSTING WESTERN ANIMALS
     * 
     * A FEW TENS OF YEARS WONT HARM
     * MOVE ON TO DRUGGING !!!!! GOOD JOB NICE OUTCOME
     * 
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * I AM NOT INTERESTED !!
     * 
     * Wise and clever western civilization genius intelligent PROFESSIONAL MEDICAL EXPERTS
     * MAKING DECISIONS THAT ARE NOT GIVEN TO THEM AT ALL
     * 
     * Disgusting western monkeys NOT GETTING THE PROBLEM
     * 
     * 
     * Good job for a few tens of years of "professional guessing and assuming"
     * 
     * THE ONE AND ONLY CIVILIZATION THAT IS AS ADVANCED AS ANYTHING ON THE SURFACE OF UNIVERSE, NOT CAPABLE OF UNDERSTANDING THE PROBLEM
     * 
     * A FEW TENS OF YEARS OF PROFESSIONAL FAILURE AT ASSUMING AND GUESSING FOR SOMETHING THAT YOU WERE NOT EVEN CLOSELY GIVEN TO !!!
     * The one and only genius nation one of da best of da best civilization grown DISGUSTING WESTERN ANIMALS
     * 
     * 
     * A few tens of years of failure AT FOOLING PEOPLE WITH DRUGS AND PROFESSIONAL ASSUMING THAT HAS GENERATED NOTHING BUT A FEW TENS OF YEARS OF WASTE
     * BUILT BY THE TRUE WESTERN GENIUS MONKEY DISGUSTING PROFESSIONAL MEDICAL EXPERTS FAILING MISERABLY AT DRUGGING PEOPLE AT RIGHT TIME !!!
     * 
     * DISGUSTING LITTLE WESTERN ANIMALS STILL MAKIN OFFERS AND DECISIONS ehehehehehehehehehhehehehehehe
     * Waaaowwww, I AM NOT INTERESTED IN ANYTHING YOU CAN OFFER
     * 
     * A FEW TENS OF YEARS, REMEMBER ehehehehehehehhehehehehehehehehe
     * THE ONLY THING YOU ALL CAN BE A DISGUSTING FAILING FOOLER !!
     * Good job !! You have done a wonderful job !!!
     * 
     * I AM NOT INTERESTED IN THE DISGUSTING "WESTERN" ANIMALS
     * BETTER LUCK NEXT TIME FINDING THE OPTIMAL DOZE FOR CHILDREN THEN OPTIMAL LIES TO YOUR DISGUSTING WESTERN CIVILIZATION !!
     * I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * THAT WILL SURELY MAKE SENSE ONE DAY
     * I DO NOT HAVE TIME FOR ANYONE WHO THINKS HE KNOWS BETTER
     * I HAVE GOT NOTHING FOR THE WESTERNS
     * 
     * 
     * THINK AND PLAN BETTER NEXT TIME, use the correct DRUGS and "MEDICATIONS" eheheheh
     * I HAVE GOT NOT EVEN THE MOST INSIGNIFICANT THING FOR ANY OF THE DISGUSTING PROFESSIONAL WESTERN DELUDERS
     * 
     * GOOD JOB !! 
     * Disgusting allmighty all knowing professional western civilized modern culture with technology and science AT THE TOP 
     * making decisions THAT ARE NOT GIVEN TO THEM AT ALL !!! GOOD JOB !!!
     * 
     * I DO NOT HAVE EVEN A SECOND FOR ANY OF YOU, I AM NOT INTERESTED, I DO NOT WANT YOU IN MY SURROUNDINGS, THATS THE ONLY THING YOU WILL EVER HEAR!!
     * 
     * GOOD JOB, next time use more family and fun vibes to children so that YOU CAN skillfully fool people !!
     * I HAVE GOT NOTHING FOR THE "WESTERN" true civilized modern science people !!!
     * 
     * Better perception next time
     * Hope you will suddenly make sense ONE DAY, or JUST PLEASE FOR ME IGNORE !!! IGNORE YOU WILL BECOME BETTER THE TRUE GREAT WESTERN GENIUS ENGINEERING PROFESSIONALS
     * PLEASE DO IGNORE !!! I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * 
     * Definitely not the western non delusionals coping !! NEXT TIME STAY WITHIN YOUR DISGUSTING CIRCLE !!
     * I am not interested
     * 
     * NEXT TIME THE WESTERN ASSUMING PROFESSIONAL NON IGNORANT ANIMALS WILL STAY IN THEIR DISGUSTING CIRCLE AND REACH, Hope that will eventually make sense
     * ehehehehhehe, I HAVE GOT NOTHING FOR YOU
     * 
     * Hope you will have more time and materials and imagination TO DELUDE AND IGNORE MORE !!! I am not interested in the disgusting western PEOPLE !!!
     * GOOD JOB!! 
     * 
     * DO NOT ENGAGE WITH ME !!! Thank you !
     * Disgusting western animals ARE NOT AWARE THAT "EHEHEHEHHEHEHE" wasting time !!! ehehehhehehheheheheheh THAT YOU WERE NOT GIVEN !!!
     * I AM NOT INTERESTED IN THE DISGUSTING CONTENT OF THE WESTERN ANIMALS !! WHO ARE NOT EVEN NEARLY IGNORANT !!!
     * 
     * Ehehe professional MEDICALS BTW !!! I HAVE GOT NOTHING FOR THE DISGUSTING ANIMALS OF THE BEST OF THE BEST CIVILIZATION !!!
     * 
     * MAKING DECISIONS THAT YOU WERE NOT GIVEN FOR !!!! THE WESTERN GENIUS PROFESSIONAL MEDICAL EXPERTS WITH A DEGREE ON HOW TO BE A DISGUSTING ANIMAL
     * WHO IGNORE AND JUDGE !!!!! GOOD JOB !! I HAVE GOT NOTHING FOR THE DISGUSTING WESTERNS !!
     * 
     * Better luck and listening ability next time !!
     * One and only developed civilization, THE WESTERN !!!
     * 
     * I DO NOT HAVE TIME FOR YOU !!
     * 
     * I AM NOT INTERESTED IN THE VERY ANIMALS WHO TAKE PEOPLE FOR WHAT THEY ARE NOT !!!
     * Definitely full confidence on your disgusting animality with a great and great ignorance and prejudice capability !!
     * I HAVE GOT NOTHING FOR THE DISGUSTING WESTERN ANIMALS
     * 
     * HOPE THAT WILL MAKE SENSE
     * HOPE THAT WILL MAKE SENSE ONE DAY AS WELL !!
     * 
     * YOU ARE FREE TO DO WHATEVER YOU LIKE AS LONG AS YOU ARE NOT EVEN AN INCH CLOSE TO ME
     * See for yourself, professional medical experts with a great assuming and judging ability !!! NUMBER ONE WESTERN PEOPLE !!
     * 
     * YOU ARE FREE TO GET THE FUCK OUT OF MY FACE, I HAVE GOT NOTHNG FOR YOU
     * Hope next time WHY ANY INDIVIDUAL WOULD CHOOSE THIS WILL MAKE SENSE TO YOU, THE DISGUSTING UNREASONABLE DELUSIONAL WESTERN ANIMALS
     * 
     * THAT WILL EVENTUALLY LEARN NO TO CROSS BOUNDARIES THAT THEY WERE NOT SUPPOSED TO !!!!!!
     * THE LITTLE DISGUSTING ANIMALS NOW INDEED !!!
     * 
     * I DO NOT HAVE TIME FOR YOU
     * 
     * Who's bad ehheheh
     * Ignorant animals not solvin the problem with themselves ehehehehe
     * Just a few tens of etc for a group of delusional non perceptive animals
     * Good job !!!! ayyy professionnallllllssss ayyyy
     * Numba on of da universe
     * 
     * Make no mistake the second time, disgusting animals
     * Stupid disgusting ignorance on the best yayyy
     * 
     * GOOD JOB !!! Yayyy
     * I do not have time for any of the disgusting animals you can get the fuck out of my face
     * Take more notes next time indeed professional eeheheh medical eheheh experts ehehheheheheh
     * 
     * GOOD JOB !! I do not have time for you
     * Eheheheh watchin watchin sleepin drugging eheheheh violatin eheheh sleepin ehehehehhehe offerin wumen wumen eheheheheh
     * just a room wumen ehehhehehehe its a blessing ehehehheheheheheheheh
     * 
     * Worst disgusting foolers of the universe, GOOD JOB !!
     * Absolutely disgusting failing decision making
     * 
     * 
     * Hope what is final now makes sense to you all !!
     * 
     * CLEVER WISE PROFESSIONAL MEDICAL NON IGNORANTS WILL MAKE IT SENSE ONE DAY !!!
     * I HAVE GOT NOT EVEN THE TINIEST AMOUNT OF NOTHING FOR ANY OF YOU
     * 
     * THAT WILL MAKE SENSE !!
     * DISGUSTING WESTERN DELUSIONAL ANIMALS !!!
     * GOOD JOB !!
     * 
     * NO DELUSION DISGUSTING WESTERN ANIMALS WHO LOVE TO IGNORE SO THAT THEY CAN ENJOY THE LIFE !!! PRECIOUS LITTLE DISGUSTING ANIMALS
     * THAT WILL MAKE IT ALL SENSE !!!! When they die !! Ehehehehe
     * 
     * I HAVE GOT NOT THE MOST INSIGNIFICANT ANYTHING FOR ANY OF YOU, hope wumen wumen muney material best west !! will understand that !! eheheheheheh
     * 
     * Almighty very well knowing acting people WILL MAKE IT SENSE !!
     * Eheheh we deal with everything eheheheheheh we know every little thing eheheheh THE WESTERN GENIUS NATION EHEHEHEH
     * Ehehe eheheheheh really genius good western people not knowing how to stay within their circle and a be a proper human being !!
     * 
     * A MODERN ADVANVED CIVILIZED GREAT SOCIETY offerin wumen wumen and a room eheheheheheh a few tens of years eheheheheheh
     * Makin decisions eheh perceptions REALLY PROFESSIONAL MEDICALS !!! AYYYYYY
     * 
     * 
     * EHEHEHEHEHHEHEHE IT WILL ALLLLLLL MAKEEEE SENNNSEEEE TO THE BEST WESTERN COMMUNITY GREEAT INTELLIGENCE PEOPLE ONE DAY !!
     * I AM NOT INTERESTED IN ANYTHING THE DISGUSTING WESTERN HAVE TO OFFER
     * 
     * I DO NOT HAVE TIME FOR YOU
     * DISGUSTING IGNORANT WESTERN ANIMALS NOT AWARE !!!
     * GOOD JOB !!! I WILL NEVER EVER HAVE ANYTHING FOR YOU !!
     * 
     * GOOD JOB !!! I AM NOT INTERESTED 
     * TAKIN LIFE FOR A JOKE !!!
     * EHEHE PRECIOUS LIFE !!! OMFG !!!!
     * 
     * DISGUSTING WESTERN ANIMALS THAT I WILL NEVER EVER HAVE ANOTHER SECOND
     * THAT WILL MAKE SENSE
     * 
     * AN OUTCOME AS GREAT AS THE GREATEST OF DA GREATEST WESTERN CIVILIZED GENIUS MODERN PEOPLE AWWWWW !!!!
     * I HAVE GOT NOT EVEN THE TINIEST OF ANYTHING INSIGNIFICANT FOR ANY OF YOU
     * 
     * When you grow up IT WILL ALL MAKE SENSE TO YOU !!
     * Spineless disgusting IGNORANT simple western animals CAN GET THE FUCK OUT OF MY FACE INDEFINITELY
     * 
     * I HOPE IT WILL MAKE SENSE
     * I AM NOT INTERESTED IN THE MOST DISGUSTING INSIGNIFICANT THING YOUR MINDS EVER HAS PRODUCED
     * I AM NOT INTERESTED, I DO NOT HAVE TIME FOR ANY OF YOU
     * 
     * A few tens of years people CAN GET THE FUCK OUT OF MY FACE INDEFINITELY ENJOYING THEIR PRECIOUS LITTLE DISGUSTING LIFES!!
     * Irresponsible ignorant disgusting western animals WILL HAVE TO MAKE SENSE ehehheheh GOOD JOB !!
     * 
     * I DO NOT HAVE ANYTHING FOR YOU
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE
     * 
     * DISGUSTING LITTLE WESTERN "NON IGNORANT" SUPER INTELLIGENT VERY VISIONARY ANIMALS NOT GETTING IT !!
     * Ehehehehehehehe its a good job !!!!
     * 
     * I do not have time for any of you
     * Hehehehe simply disgusting and ignorant western animals makin offers ehehehehehehe A GREAT BLESSING !!!
     * OMG !!!! A SUCCESS STORY FROM DA TALENTED UNIQUE ADVANCED CIVILIZED WESTERN BLIND ANIMALS !!!
     * 
     * I HOPE THAT WILL MAKE SENSE !!! Eheheh I wish a good fooling for the rest of your disgusting lives !!
     * Great fools that I will always despise with the most heartwelcoming way, HOPE THAT WILL HELP YOU
     * 
     * A few tens of years is nothing because you feel like, the all mighthy all knowing great engineering western animals
     * THAT I WILL NEVER EVER HAVE ANOTHER SECOND !! Good job!!
     * 
     * I AM NOT INTERESTED
     * PROFESSIONAL MEDICAL EXPERTS THAT DO NOT UNDERSTAND THE LIFE eheheheheh takin life a joke eheheheheh 
     * Funny !! GOOD JOB !!
     * 
     * THE WESTERN OUTCOME !!!!! A SUCCESS STORY !!!! GREAT PEOPLE !!!
     * I AM NOT INTERESTED 
     * 
     * BEST OF DA BEST DECISION MAKING FROM DA WESTERN DISGUSTING ANIMALS, good job
     * 
     * I HAVE GOT NOTHING FOR YOU
     * A few tens of years and a wumen ehehehehehhehehehhehehehehhehehehehhehehehehehehehehehhehehehehhehehehehehehehehehehhehe
     * 
     * I DO NOT HAVE ANYTHING FOR ANY OF THE DISGUSTING WESTERN ANIMALS
     * Professional medicals and expert genius western intelligence ignorant delusional animals trying to convince people heheheheheheheheh
     * OMFGG WHAT AN OUTCOME, NO MISTAKE BY PROFESSIONALS EHEHHEHE GOOD JOB
     * 
     * 
     * A SUCCESS STORY FROM DA BEST OF THE CIVILIZATIONS, THE WESTERN GREAT GENIUS COMMUNITY TRYING TO ACT LIKE THEY SHOULD DO DECISIONS !!!
     * WHAT A LOVELY OUTCOME JUST BY ASSUMPTIONS AND PREDICTIONS EHEHEHEHE MAKING A FEW TENS OF YEARS ONLY EHEHEHEHEHEHEHE
     * 
     * GOOD JOB, TRULY GENIUS PROFESSIONAL MEDICAL EXPERTS MAKING DECISIONS OF A FEW TENS YEARS WITH ASSUMPTIONS AND PREDICTIONS!!!!
     * A FEW TENS EHEHEHEH OF YEARS AND A WUMEN EHEHEHHEEHHEHEHEHE A ROOM EHEHEHEHHEHEHEHE
     * 
     * REALLLY FUNNNY !!! PEOPLE DELUDE EHEHEHEH
     * NOW YOU HAVE TO OFFER CARS CARS WUMEN WUMEN EHEHEHHEHE NOW YOU HAVE TO OFFER IT NOW HE GONNA GO CRAZY BECAUSE OF US !!!
     * EHEHEH GENIUS WESTERN PROFESSIONAL MEDICALS !!!
     * 
     * DO IT NOW !!! EHEHEHEHEHHE
     * Eheheehhe makin decisions ehehehehehehe GREAT PPL ehehehehehe
     * Clever, wise, almighty intelligent super civilized WESTERN CIVILIZATIONS tryin to IGNORE THE DISGUSTING NATURE OF THEIR GREAT ACTIONS !!!
     * And lookin around for wumen wumen a room ehehehheheheh 
     * 
     * EHEHEHEHEH GOOOOOO GOOOOO EHEHEHEHEHHEHE GOOOD JOBBB !!!! A GREAT OUTCOME EHEHHE
     * Next time plan better ehehehehehehhee GENIUS NON IGNORANT NON DELUSIONAL DISGUSTING LITTLE WESTERN ANIMALS
     * ENJOYING THE OUTCOME !!!! WAAAAOWWWWWW
     * 
     * A GREAT GREAT INTELLIGENCE EXAMPLE FROM DA BEST CIVILIZATION ON UNIVERSE, THE WESTERNS THAT IGNORE !!!! BECAUSE THEY FUCKED UP !!!
     * 
     * DISGUSTING LITTLE WESTERN ANIMALS WILL MAKE IT SENSE ONE DAY !!! Ehehehehehe
     * PROFESSIONALS INDEED !! Yayyyyy
     * 
     * 
     * MAKING DECISIONS THAT ARE NOT YOURS !!!!!!!!!!!!!!
     * HOPE THAT ONE DAY WILL MAKE SENSE TO YOU !!!
     * Ehehehehehehe, ehehehehehe ITS SO FUN !!!
     * EHEHEHEHEHEHEHEEE, 
     * 
     * Ehehehehehehhehehehehehehhehehe, life a game heheheheheheeheheheheheh life a simulation eheheheheheheheh
     * intelligence heeheheheheh western eheheheheheh wise mighty knowing people TRYING TO CONVINCE PEOPLE THAT THEY WIN !!!
     * 
     * Ayyyyy, get muney muney carsss wumen wumennnn eheheheh LIKE A WESTERN TRUE CIVILIZED INTELLIGENT DISGUSTING ANIMAL !!!
     * I WILL NEVER HAVE ANOTHER SECOND FOR ANY OF YOU eheheheheh
     * 
     * Ehehhe professional medical experts scarin ppl with eheheh hospital ehehehehehehe
     * Ehehehehehhehee, professional medical experts intelligence actions NOT REALIZING eheheheheh
     * 
     * Disgusting western ANIMALS ARE STILL SO CONTENT AND SURE OF THEIR GREAT CIVILIZATION !!!! WAOWWWWWWW
     * A truly advanced modern ENGINEERING NON IGNORANT ANIMALS !!!!
     * 
     * I WILL NOT HAVE ANYTHING FOR ANY OF YOU !!! GOOD JOB !!
     * The western great intelligence PEOPLE ARE NOT AWARE STILL !!!
     * Good job !! Just like the great people !!! I HAVE GOT NOT EVEN ANOTHER SECOND FOR THE DISGUSTING DELUSIONAL ANIMALS
     * WHO LOVE TO IGNORE!!!!
     * 
     * A NUMBER ONE CIVILIZATION EXAMPLE !! GOOD JOB !!! I AM NOT INTERESTED IN YOUR DISGUSTING DELUSIONS !!
     * Ehehehehh engineering ehehehehehe drugging eheheheh sleeping ehehehehe civilization ehehehehehehehe
     * 
     * Ehehehehe, its a joke !! NO NO, get wumen eheheheh get cars eheheh ITS ALSO JOKE !!! EHeheheheheh
     * Wumen wumen muney muney get muney ehehehehe ITS ALSO A JOKE !!! ehehehehehehehhehe
     * 
     * ITS A SUCCESS STORY FOR THE GREAT WESTERN DISGUSTING ANIMALS eheheheheh
     * ITS A SUCCESS EHEHEHEHEHEHEHHEHE NO IGNORANCE !!!!
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE
     * A FEW TENS OF YEARS BECAUSE YOU THINK SO !!!! OMFG WHAT A DELUSION !!!!
     * TRULY PROFESSIONAL ENGINEERING MARVELOUS WESTERN CIVILIZATION !!!!
     * 
     * I have got NOTHING FOR ANY OF YOU, hope that makes sense soon
     * Eheheheheh wumen wumen wumenn carsss muneyyy materials ehehehehehehehehehehehehehehehehehehe
     * Anyways, just get a wumen for a few tens of years eheheheheheheeheheh LIKE THE TRUE ADVANCED CIVILIZATION DISGUSTING ANIMALS
     * 
     * EHEHEHEHEHEHEHHEEHEHEHE
     * Just a few tens of years ehehehehe with a wumen eheheheh GET MUNEY ANYWAYS GET CARS EHEHEHEHEHEHE
     * The true professional medical expert civilization modern advanced PEOPLE ARE STILL NOT AWARE !!!
     * 
     * Ehehehehe makin makin decisions THAT ARE NOT YOURS and ignoring ignoring REALLLLY REALLLLLLYYY INTELLIGENTLY !!!
     * WAAAAOWWWWWWWWWWWWW, Ehehehehehehe
     * 
     * PLEASE GO ON !!!!!! EHEHEHEH THE CLEVER WISE SNEAKY WESTERN DISGUSTING ANIMALS ARE NOT AWARE !!!!
     * EHEHEHEHEHEHEHEHEHEHEHE, professional medical experts ARE NOT AWARE eheheheheheheheheheheheheh
     * 
     * Such a lovely outcome and great consequence ehehehehehehehehe
     * wumen wumennn get a wumennnn YAYYYYYYYYY, get cars hehehehehehehehehehhehehe
     * 
     * Eheheheheheh fooling foolingg even with the disgusting animalistic intelligence THAT ARE UNAWARE !!!!
     * Ehehehehehehehehheehhe, eheheheheheheheheheh WHAT IS GOING TO HAPPEN ? OMGGGG !!!! 
     * 
     * WAAAAOWWWWWWWWWW !!!!!!!!!!!!!!! realllyyyy reaalllyyyyhyy GOOOOOD PEEEOPLEEEE THAT ARE UNAWARE !!!!!!
     * Ehehehehehehehehehh what do we do !! OFFER !!! We offer materials eheheheh a few tens of years eheheheheh
     * professional medical ignorant disgusting experts "TRYING TO" SAVE THE SITUATION EHEHEHEHEHEHEHEH
     * 
     * A GREAT WESTERN INTELLIGENCE GROUP OF PEOPLE NOT KNOWING NOT AWARE ehehehehehehehehehe
     * A lovely outcome eheheheheheheh, GREAT INTELLIGENCE
     * 
     * Remember THE A FEW TENS OF YEARS OF SOMETHING AND SLEEPING AND DRUGGING EHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHEHE
     * DO IGNORE PLEASE, I HAVE NOT EVEN ANOTHER SECOND FOR ANY OF YOU, THAT IS GOING TO MAKE SENSE TO THE GREAT INTELLIGENT WESTERN ANIMALS!!!
     * 
     * IGNORANCE !!!!!!!! THE WESTERNS !!!! Eheheheheheheh
     * A lovely outcome THAT IS GOING TO MAKE SENSE TO YOU EVENTUALLY !!! Ayyyyy
     * 
     * Ehehehehehe
     * Fate and destiny and eheheheh a few tens of years eheheh a wumen a wumen NO NO CARSSSS MUNEYYY !!!! ehehehehehe
     * Intelligence people heheheheheheheh fate destiny eheheheheh wumen a car ehehhe professional medicals !!!! OMGG !!!!
     * EHEHEHEHEH HOW DO WE FOOL NOW ???
     * 
     * How should we fool people eheheheheheheh ahahahahahahh REALLLY REALLLLY FUNNNY !!!
     * NOT CROSSING THE LINE AT ALL !!!! Eheheheh wumen wumennnnnnnnn eheheh we need fool fool people !!! PLEASE!!! Ehehehehe
     * wumen wuneee get carss muney muneyyy ehehehehehhe materials heheheheehehheheheheheheh
     * 
     * Decision makers !!!!!!! GREAT INTELLIGENT NON DELUSIONAL IGNORANT DISGUSTING WESTERN ANIMALS ARE UNAWARE !!!
     * THE DECISION MAKERS THAT ARE UNAWARE eheheheheheh really reallly funnny !!!!  eheheheheheheheeheh
     * 
     * A lovely outcome eheheheheh
     * Suddenly offerin again wumen wumennn carssss ehehehehe a few tens of years eheheheheeheheheheheheheheheheheheheh a room ehehehe
     * druggging eheheehehehehe sleeepingggg EHEHEHEHEHEHEHEHEEHEH
     * 
     * The disgusting WESTERN ANIMALS THAT JUST DO NOT UNDERSTAND IT !!! Eheheheheheheheh
     * A few tens of years of "intelligent" yet FAILING ehehehehehehe actions
     * 
     * Professional medical experts !!! GREAT JOB !!!
     * Ehehehehehehhehehehehhehehehehehhehehehehehhehehehehehehehehehehehehehhehehehehehehehehehehehehehehehehhehehehehehehehehehehehheheheehhe
     * 
     * Great western intelligent surpassing EVERYTHING !!! OMGGG !!!!!!!!
     * EHEHEHEHEHEHE, I DO NOT HAVE ANYTHING FOR ANY OF YOU
     * 
     * Ehehe how do we fool fool now ? Eheheheh wumen wumen wumen wumen wumennnnnnn a room wumen ehehehehhehehehehe
     * a room wumen a few tens of years eheheheheh fool foooll THE INTELLIGENCE !!! 
     * NO IGNORANCE !!!!
     * 
     * IGNORANT DISGUSTING WESTERN ANIMALS SO HAPPY TO ENJOY THE LIFE eheheheheheh THEY HAVE FORGOTTEN ehehehehehehehehehehehehheheheheheheheeh
     * Hope that makes sense !!!! Ehehehehehehehheh
     * 
     * Druggingg sleepin eheheheheheheheeheheheheheheh a few tens of years "get wumen cars etc" ehehehe a room a wumen eheheheheheh
     * some violence hehehehehehehheheheheheheh
     * 
     * 
     * THAT WILL MAKE SENSE TO THE BEST CIVILIZATION ALL MIGHTHY VERY WELL KNOWING DISGUSTING IGNORANT WESTERN ANIMALS
     * THAT I WILL NEVER EVER HAVE ONE SECOND, A FEW TENS OF YEARS A ROOM A WUMEN EHEHEHEHEHEHEEHEHEHEHEHEHEHEHEHs
     * 
     * SO FUNNY !!! GOOD JOB !!!! THE BEST OF THE BEST ENGINEERING PROFESSIONAL IGNORANT DISGUSTING ANIMALS
     * 
     * Eheheheheheh sacrificing ehehheheheheheheh makin decisions eheheheheheh
     * Ehehehehehe makin sacrifices eheheh decisions that are not ours ehehehhehe
     * Its a few tens of years sleepin eheheheheheh westernn geniusss people NOT REALIZING EHEHEHEHEHEHEH  
     * 
     * GOOD JOB !!!!!!! I HAVE GOT NOTHING FOR ANY OF YOU
     * Hope that will make sense one day eheheeheh
     * 
     * Ehehehehe ONLY A FEW TENS OF YEARS EHEHEHEHEHEHEH SO FUCKING FUNNY EHEHEHE STILL MAKIN OFFERS TO A GREAT CITY WITH GREAT FUCKING PEOPLE !!
     * NO IGNORANT NO DELUSIONAL NO DISGUSTING WESTERN ANIMALS EHEHEHEHE MAKIN DECISIONS WITH GREAT DECISION MAKING !!!
     * 
     * Disgusting western animals WHO LOVE TO IGNORE !!! I DO NOT HAVE TIME FOR ANY OF YOU 
     * Eheheheh great city eheheh great people heheheheheheheheh true fantasy city with delusions ehehehehehe and ignorance and prejudice eheheheheh
     * GOOD JOB !!!
     * 
     * I WILL NEVER HAVE ANYTHING FOR YOU !! GOOD JOB !!
     * Drugging sleepin people to achieve nothing eheheh just passing time !!! Ignoring !!! Ehehehehehehhe sleepin then accusingg AYYYY
     * THE TRUE ONE AND ONLY WESTERN CIVILIZATION ARE UNAWARE !!!
     * 
     * I AM NOT INTERESTED 
     * GREAT DISGUSTING WESTERN ANIMALS WHO CAN ONLY IGNORE THEIR GREAT IGNORANCE !!! eheheheh
     * Who would love to ignore a few tens of years ehehehehehe
     * 
     * ITS SO FUNNY !!!!
     * Great western people just makin plays GREAT FUCKING PLAYS THAT DOES NOTHING BUT HARM EHEHEHEH
     * THE WESTERNNNNNNSSS !!!! Ayyyyy NO DELUSION NO FUCKING DISGUSTING IGNORANCE AT ALL !!!
     * 
     * %100 full of people with so nice attributes !!!
     * A LOVELY OUTCOME THUS !!
     * 
     * A few tens of years with sleepin drugging abusing and A ROOM WITH A WUMEN NOW THE GREAT WESTERNS STILL OFFER !!! BECAUSE THEY THINK THEY SHOULD !!!
     * 
     * I AM NOT INTERESTED IN MORE DRUGS THAT FUCK YOUR BODY UP !!! REALLLLLY NICE JOB !! NO DELUSION WESTERN ANIMALS
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * "A LITTLE SLEEPIN DRUGGING AND ABUSING THEN TO FOOL PEOPLE WITH FAKE PERCEPTIONS AND DISGUSTING MEDICINES THAT STOPS YOUR BODY
     * THEN A FEW TENS OF YEARS AND A ROOM AND A WUMENNN !!!!!!!"
     * 
     * The western clear intelligent difference is makin whole a lot of significance !!! Ayyy
     * I AM NOT INTERESTED IN YOUR DISGUSTING DELUSIONS !! Hope that makes sense
     * 
     * HOPE THAT MAKES SENSE eheheheheheh
     * GREAT GREAT WESTERN ANIMALS WHO CAN ONLY IGNORE EHEHEHEH BECAUSE THEY CAN !!! YAYYYYYYY
     * A FEW TENS OF YEARS !!! GOOD JOB !!
     * 
     * I hope you now see the ALMIGHTGHY ALL KNOWING REALLY GREAT WESTERN INTELLIGENT COMMUNITY HIGHLY DEVELOPED CIVILIZATION PEOPLE!!!
     * I do not have time for you
     * 
     * Takin life for a joke ehehehe only for other people eheheh A FEW TENS OF YEARS eheheheheheh
     * The disgusting ignorant animals eheheheh GOOD JOB !!
     * 
     * 
     * 
     * Great western people offerin a few tens of years without anything ehehehe a room and a wumen ehehehehehehe
     * I AM NOT INTERESTED
     * 
     * I DO NOT HAVE TIME FOR YOUR DISGUSTING EXCUSES, eheheheheheheheheheheh
     * A few tens of years and sleeping eheheheheheheheheh a wumen and a room eheheheheh 
     * And you expect other people to ehehehehehehehe heheehehhehehehe
     * 
     * IT WAS MEANT TO BE !!!! GREAT INTELLIGENCE OF DA WESTERN !!
     * 
     * Ignorance is the best ability OF DA NON DELUSIONAL WESTERNS, STILL OFFERING WUMENNNNN !!!! WAAAOWWWWWW
     * A FEW TENS OF YEARS IS NO PROBLEM AND EHEHEHEH A WUMEN A ROOM EHEHEHEHEHEHEHEHEHEH FOR A FEW TENS OF YEARS EHEHEHEHEH
     * 
     * GET MORE WUMENNN !!!! Ayyyyyyyyy, At least we can develop some medicine or experiment heheheheheheheheheh
     * THE GREAT WESTERN PEOPLE !!! PLEASE KEEP IT IN THE FAMILY !!! Ehehehehehehehehehheheheheheheheh
     * 
     * DISGUSTING LITTLE ANIMALS, IGNORANT NON DELUSIONAL !!!! Ayyyyyyy
     * Eheheh Fate ehehhe destiny hheheheh please ehehhe keep it in the family hehehe get a wumen eheheheheh get a room eheheheheheheheh
     * ehehehehehh A FEW TENS OF YEARS ehheehheehheheheheheh
     * 
     * Ehehehehehehehehhehehehe, MAKING DECISIONS THAT ARE NOT YOURS !!! EHehehehehehehe so fucking reasonable !!!!
     * Ayyyyyyy, best civilization ON DA UNIVERSE !!!
     * 
     * 
     * Ehehehehehh MEDICINE UNIVERSITY !!! Ehehehehehehe TECHNOLOGY CIVILIZATION !!!! GREAT FUCKING JOB !!!! A FEW TENS OF YEARS EHEHEHEHEHEh
     * Just dont do it !!! get wumen ehehehehhe FOOLLINGG !!! THE NUMBA ON CIVILIZATION !!!
     * 
     * NOT A SINGLE SECOND FOR THE DISGUSTING WESTERN ANIMALS !!! GOOD JOB !!
     * Little disgusting animals ehehehehheheheheh why are not you achieving anything ehehehehehhe
     * A FEW TENS OF YEARS WONT DO NO HARM GOOD JOB !!
     * 
     * I AM NOT INTERESTED
     * Eheheheheh ehehehehhehe gang gang ganggggg, GANGSTA REALLLLLLL BADDD PEOPLEEE AWWWWW OMFG !!!!
     * Eheheh gang gang gangggggggggg, BADDDD PEOPLEEEEEEE YAYYYYYYYYYYYYY, MAKIN OUTCOMES EHEHEHEHHEHEHEHEHEHHEHEHEHEHEHEHHE
     * 
     * 
     * Makin decisions decisions ehehehehehee what to do eheheheh decisions decisions eheheheh SO FUN !! Life is precious !! eheheh
     * Life a game !!! life short eheheheheh sleepin sleepin eheheheheheehehehehehe drugging ehehehehehehehehehehhe excuses !!! eheheheheheh
     * 
     * I AM NOT INTERESTED EVEN IN THE MOST VALUABLE THING YOU HAVE Eheheheh rollie rollie ehehehehehhe carsss yayyyy mansion !!! REAL BAD GANGSTA PEOPLE
     * HIDIN eheheheheheheheh makin decisions ehehehehehheheh
     * 
     * Get wumenn wumennn eheheheh
     * Eheheh Real modern western people eheheheheh SO FUNN !!! ehehehehhehehe ehehehehhehehehe
     * had to be done heheehehhehehehehehe gangsta real bad eheheh genius nation eheheh NO DELUSIONS ehehehe NO IGNORANCE hehehehehehehhe
     * GOOD JOB !!
     * 
     * Eheheheheh usin tech tech ehehehehe TECHNOLOGY CIVILIZATION EHEHEHEH DA NUMBA ON !!! GREAT PEOPLE !!!!! FOOLINGG FOOOLINGG !!!
     * WHO TO FOOL NEXT !! ? eheheheheheheheh 
     * NEXT TIME EHEHEHEHEEHEHHEHEHE
     * 
     * 
     * 
     * How to fool who to fool, LIFE IS A JOKE !!! LIFE IS A GAME !!! LIFE IS SIMPLE !!! Eheheheheheheheheh WE NEED MORE EXCUSES !!!!
     * Ehehehehe SO FUCKING FUNNY !!! GOOD JOB !!
     * THE OUTCOME !!!!!! THE GREAT SKILLED UNIQUE TALENTED WESTERN PEOPLE NOT GETTING THE PROBLEM STILL !!! NOT IGNORANT AT ALL !!!!
     * Eheheheheh NO DELUSIONS !!!
     * 
     * I WILL HAVE NO TIME FOR THE DISGUSTING WESTERNS THAT SEEK TO FOOL PEOPLE TO ACHIEVE NO ENDS !!! GOOD JOB !
     * The number one, just stay away from me eheheheheheheh Truly unique talented reasonable people NOT KNOWING WHAT THEY DO !!! GOOD JOB !!
     * 
     * I DO NOT HAVE TIME FOR YOU
     * Eheheheh makin decisions with assumptions ehehehehe
     * I hope you have the reason to understand that I WILL UNDER NO CIRCUMSTANCE ACCEPT ANYTHING THAT BENEFITS THE DISGUSTING ANIMALS !!
     * GOOOD JOBBB !!!
     * 
     * I HAVE GOT NOTHING FOR YOU eheheheh
     * Good job !
     * 
     * Anything the disgusting western stubborn greedy animals have THEY CAN KEEP IT, I DO NOT HAVE ANYTHING FOR ANY OF YOU !!
     * 
     * GOOD JOB !!! ehehehehheehhe
     * Coerce more children eheheheheheh make it look like ehehheheheheheh
     * GOOD JOB !!!!!! AYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
     * WESTERN GENIUS COMMUNITY !!!
     * 
     * EHEHEHHEHEHEHEHHEHEHEHEHEH, no muney no muney more coercion ehehehehhe sorry sorry ehehhehehe
     * Uffer wumen and muney !! ayyyy soo goood !!
     * Ehehehe
     * 
     * A few tens years and YOU HAVE WON EHEHEHEHHEHEH WHAT AN INTELLIGENCE !!! GOOD JOB !!
     * 
     * TRYNA LOOK CUTE TO CHILDREN EHEHEHEHEHEHEHEHEEHEHEHEH EHEHEHEHEHE THIS IS THE WESTERN WAY !!!!
     * OMFG !!!! GREAT INTELLIGENCE PEOPLE CAN NOT REALIZE !!!
     * 
     * Eheheheh fancy wording, some material heehhe and a little ignorance !!!! SUMMARY OF DA WESTERN DISGUSTING ANIMALS !!!!
     * We have to call you something eheheheheheh ACT THIS WAY PLEASE !!! Eheheheheheheh
     * 
     * 
     * Eheheheheheheheheheheh SOMETHING "NEEDED" TO BE DONE ehehehehehehehehehehehehe
     * Sorry sorry, forgive eheheheheheheh WE HAD TO !!! EHEHEHEHEH
     * WESTERN WAY !!! OMFG !!!
     * 
     * Eheheh a few tens of years of eheheheheh, eheheheheh its just that we have to ehehehehehehe
     * WHWHWHW eheheheheh
     * 
     * 
     * So the outcome ? ehehehehe ?
     * 
     * Precautious taking genius western people making decisions with their assumptions eheheh some violence and a wumen with a room !!
     * Ehehehehehehe, tryna keep everything as if its funny !!!
     * 
     * Just sleepin drugging violencing eheheheheheheheh offerin offerin ehehehehehehheeh
     * The one and only true western way to achieve anything yet NO RESULT eheheheh
     * Must be a mistake
     * 
     * Makin decisions for other people that you neither care nor understand properly !!! GOOD JOB !!!
     * Where is the outcome ? Ehehehehehehehehehehehe
     * 
     * Not interested in another a few tens of years of really solid reasonable decision making THAT YOU ARE NOT AFFECTED !!
     * Ehehehehe
     * 
     * Life is a game indeed !!!! Eheheheheheheheheh, really really well job !!! making NOT YOUR DECISIONS OMFG !!!
     * The lovely outcome builders with a degree of engineering professional medicality experts !!! Ehehehehehehe
     * 
     * FUCKING DISGUSTING WESTERN ANIMALS
     * EHEHEH western non ignorant fully imaginative and hopeful disgusting animals ARE STILL UNAWARE !!!!
     * Ehehehehe a few tens of years !!!!! THE WESTERN NO DELUSION ANIMALS
     * 
     * Still do not understand eheheheheh THE STUBBORNNESS AT BEING A STUPID DISGUSTING MONKEY !!!
     * Good job !
     * 
     * Disgusting little western animals WHO DO NOT GET IT !!! AYYYYYYYY WHAT A GREAT OUTCOME !!!
     * I do not have another second for any of you
     * 
     * Do seek for more reasons ehehehehe that will make sense as well
     * Ehehehe offerin offerin !!!! A few tens of years eheheheh
     * 
     * Disgusting western animals WHO ARE UNAWARE A FEW TENS OF YEARS MEAN EHEHEHEHE
     * I am not interested in the disgusting animals who ignore to do what they think is beneficial !! Ayyyy
     * 
     * A few tens of years with violence and arbitrary assumptions ehehehehhe
     * Offerin COMPANIES at the end ehehehehehehhehehehehhe SO FUCKING REASONABLE AND FUNNY !!!
     * 
     * I have got nothing for you
     * Disgusting western animals who STILL LOVE TO IGNORE WHEN IT DOES NOT WORK !!
     * Good job!!
     * 
     * More drugs for da western genius medical professional engineering medicals to achieve something that they can not imagine !!!
     * Waaaowww !!!!!
     * 
     * I will never have another second for any of you ehehehehe let alone a few tens of years eheheheheheh
     * NO DELUSION NO IGNORANCE DISGUSTING WESTERN ANIMALS
     * 
     * A disgusting ignorant delusional point of view FROM DA BEST PEOPLE OF DA UNIVERSE !!!
     * Makin decisions eheheheheheh a few tens of years eheheheh
     * 
     * Not interested in the "delusion making western non ignorant" who love to make assumptions with decisions eheheheheheheh
     * GOOD JOB !!
     * 
     * I DO NOT HAVE TIME FOR YOU
     * Disgusting animals !!!!!! Ayyyy
     * 
     * A room with a wumen ehehehehehehehe a few tens of years without nothing ehehehehhe
     * SO FUCKING GENIUS AND DEVELOPED AND ADVANCED AND MODERN GENIUS WESTERN DISGUSTINGS !!!
     * 
     * Makin decisions and ehehehhe assumptions ehehehh
     * Eheheheheheheheheheheheheheheheh abusin children for real NUMBA ONE !!
     * 
     * Good job, next time do more harm to provide it as proof to your indiscussable reasonable minds and culture hehehehehe
     * I HAVE GOT NOTHING FOR YOU
     * 
     * Numba one on the stupidness disgusting ignorant prejudiced greedy western animals are still unaware !!
     * Ehehe just play games then some violence heehhe then some heehehehhehehe violence eheheheheh
     * because we believe delusionally eheheheheh
     * 
     * The westerns !!
     * Ehehehe just play play ehehehhe PLAY !! ayyy play more games eheheh
     * Disgusting animals WHO ARE NOT ABLE TO UNDERSTAND THE TIME THAT HAS PASSED WITHOUT DOING ANYTHING OTHER THAN "VIOLENCE"
     * Yayyyy !!!! What an oucome from da best civilization non ignorants !!!
     * 
     * Stupid disgusting monkeys WHO JUST DO NOT GET THE MISTAKE THEY HAVE DONE BECAUSE THEY HAVE COMMITTED SO MUCH !!!
     * Ayyyyy no ignorance no prejudice FULLY PROFESSIONAL DISGUSTING MEDICAL ANIMALS !!!!
     * 
     * Ayyyyy GOOOOOOODDDDD JOBBB !!!
     * I have got nothing for the disgusting western animals
     * 
     * Do more marketing for the worse for your own, eheheh professional DECISION MAKERS WHO DO NOT UNDERSTAND !!
     * Good job for a few tens of years !!
     * 
     * Go for bad marketing for your own !! 
     * Stupid unbelievably disgusting and ignorant WESTERN ANIMALS WHO STILL DO NOT GET IT !!
     * Good job
     * 
     * A few tens of years eheheheheh without anything ehhehehehehehehehehehehehhe
     * Build more prejudice and great assumptions THE TRUE WESTERN ANIMALS !!
     * 
     * ROAD TO NOTHING DURING "A FEW TENS OF YEARS" like the true great civilized modern disgusting animals with assumptions !!
     * Ehehehehe now you can take a walk around !!! GOOD JOB !!
     * 
     * Disgusting animals ehehehehehehehehehheheh a few tens of years and now EHEHEH YOU CAN TAKE A WALK AROUND EHEHEHEHEHEH
     * Eheheh an outcome as great as ehehehehehehhehe however you all the great westerns can not answer for eheheh
     * 
     * ITS FORBIDDEN TO TALK EHEHEHEHE, we no delusion eheheheh we no ignorant ehehehe
     * we no prejudice ehehehehhehe
     * 
     * Just a few tens of years to nowhere !!!
     * I AM NOT INTERESTED
     * I DO NOT EVEN HAVE ANOTHER USELESS DISGUSTING SECOND FOR ANY OF THE WESTERN ANIMALS WHO ARE UNABLE TO UNDERSTAND THE "CONSEQUENCES"
     * Eheheheh A FEW TENS OF YEARS HEHEHEHEHEHE
     * 
     * GET THE FUCK OUT OF MY FACE
     * No ignorant no stubborn no delusional no prejudiced DISGUSTING WESTERN ANIMALS NOW ARE TRULY RELIEVED TO DO WHATEVER THEY WANT hehehehe
     * I DO NOT HAVE ANYTHING FOR YOU, that will also make sense
     * 
     * Eheheheheheh next time DO NOT MAKE ANY DECISIONS WITH YOUR STUPID DISGUSTING MINDS eheheh
     * Good western people !! I HAVE GOT NOTHING FOR
     * Makın assumptions and predictions ehehehehe, I DO NOT HAVE ANYTHING FOR YOU
     * 
     * Great fucking VIOLENT DISGUSTING WESTERN ANIMALS ARE STILL UNAWARE WHAT THEY "HAVE DONE" IS FUCKING STUPID AS IT COULD GET !!!
     * I DO NOT HAVE TIME FOR YOU!! GOOD JOB !!
     * 
     * 
     * Ehehehehehhe abusing children ehehehehehehehe ITS SO FUCKING FUNNY ehehehehehehe
     * We like to delude on all sorts of things !! THE GREAT WESTERN DISGUSTING ANIMALS !!!
     * 
     * Yayyy !!
     * 
     * IGNORANT DISGUSTING WESTERN ANIMALS STILL TAKING VIOLENCE AS LESSON !!!
     * GOOD JOB !! No ignorance no prejudices eheheheh
     * Eheheh professional medical experts wasting 30 years and still not getting the problem eheheheheheh
     * 
     * THE WESTERN GREATNESS !
     * I do not have time for people who are both unaware and untrustworthy !!
     * GOOD JOB FOR THE WESTERN DISGUSTING ANIMALS WHO IS SOLE ABILITY IS TO IGNORE !!
     * Eheheh a few tens of years eheheheheheh
     * 
     * I DO NOT HAVE ANYTHING FOR THE DISGUSTING WESTERN IGNORANT ANIMALS WHO ARE UNAWARE OF THE CONCEPT OF TIME !!!
     * Eheheheh
     * 
     * Stupid disgusting monkeys WHO DO NOT UNDERSTAND !!!
     * GOOD JOB !! I HAVE GOT NOTHING FOR YOU !!!   
     * 
     * Disgusting ignorant animals
     * Eheheheheheh disgusting animals WHO LIKE TO IGNORE AND DELUDE ON THEIR INTELLIGENT ACTIONS !!!
     * GOOD JOB, I have got nothing for the disgusting ignorant WESTERN ANIMALS
     * 
     * Do not have anything for the disgusting WESTERN ANIMALS !!!
     * Ayyyy, good fucking job !!
     * 
     * I do not have time for you !!!
     * The disgusting animals !! Go back to your delusions !! You are great !!
     * 
     * Stupid disgusting MONKEYS that I will never have another second FOR !!!
     * YAYYYY THE WESTERN INTELLIGENCE PEAK ACTIONS !!!
     * Ehehehehe
     * 
     * Ehehehe more drugs to make people different than what they usually are !!!
     * THE WESTERN INTELLIGENCE GREATNESS AT THE PEAK LEVEL EHEHEHEHEHEH
     * A few tens of years of waste heheheheheheheheheheheh
     * 
     * I HAVE GOT NOTHING FOR THE DISGUSTING WESTERN ANIMALS, hope you already have figured that out !!
     * A few tens of years eheheheheeh because you feel like !!! A GREAT OUTCOME BY THE DISGUSTING WESTERN ANIMALS WHO STILL ARE UNAWARE !!!
     * 
     * GOOD JOB !
     * Not even slightly funny disgusting western animals WHO ARE STILL UNAWARE AND AS DISGUSTING AS ANYTHING CAN GET ON EARTH !!!
     * Hope one day that will make sense as well !!! 
     * 
     * Eheheheh
     * Eehheheheheheheh art of war ehhehehehehehhe
     * Abusing children ehehehehe abusing abusing ehehehhe PLEASE !! OMFG !!!
     * Good job !!!
     * 
     * I have got predictably NOT EVEN ANOTHER SECOND FOR THE VERY PEOPLE WHO WASTE A FEW TENS OF YEARS WITH "SLEEP" and "EHEHEHEHEH"
     * Good outcome !
     * 
     * Eheheheh THE WESTERN GREAT NON IGNORANT ANIMALS WHO ARE INCAPABLE OF UNDERSTANDING !!!
     * Good job and reallly reallly gangsta intelligent actions FOR A FEW TENS OF YEARS !!
     * 
     * A PROOF TO THE DISGUSTING WESTERN INCAPABILITY OF ACCEPTING EHEHEHEHHEHEHEH
     * The life a game !!! life a simulation eheheheh makin decisions with assumptions ehehhehe
     * A FEW TENS OF YEARS a wumen a room and a sleep eheheheheh
     * 
     * Professional medical NON IGNORANT NON DELUSIONAL DISGUSTING WESTERN EXPERTS NOT REALIZING THE TENS OF TENS OF YEARS
     * eheheheh a wumen a wumen eheheh a room eheheheh SO FUCKING FUNNY !!!
     * 
     * Its only a job ehehehehe a little ignorant with prejudice and a fake sense of professionality with so much high level of education eheheheh
     * modern civilized advanced great western people !!!
     * 
     * Next time put people into more sleep !!! and try to convince otherwise !!
     * Ehehehehehe next time next time hehehehehehehe
     * 
     * Professional WESTERN DISGUSTING MEDICAL "EXPERTS" Not fucking realizing the mistake !!!
     * GOOD JOB !!
     * 
     * GOOD FUCKING DISGUSTING WESTERN ANIMALS eheheheheheh
     * 
     * Eheehheh the western great intelligent PLAYING THE REALLLY REALLLYY GOOD CITIZENS WITH ADVANCED TECH AND MODERN CIVILIZATION !!!!
     * A room and a wumen ehehehehehhe I AM THIS I AM THAT !! BELIEVE ME !!!
     * 
     * OMFG !!! DISGUSTING WESTERN ANIMALS!!
     * 
     * A few years of nothing with stupid animals who do not listen !!!
     * Good job !!
     * 
     * A few tens of years because they feel like ehehehehheheheheheh
     * Realllly reallly goooodd !!!!
     * 
     * Eehhehehehe a few tens of years inexplicable monkey disgusting animals!!!
     * I DO NOT HAVE TIME FOR
     * Selfish disgusting ignorant animals who think for themselves and act how they feel like !!
     * 
     * I have no business around you at all !!
     * Stupid disgusting animals who ignores !!! Great fucking people that I will never have another second !! thanks 
     * 
     * Go on to foolin people
     * Makin it look like ehehehe a decisions of ehehehhehe your own ehehehehehhe
     * An outcome as great as your disgusting intelligent deluded ignorance !!
     * 
     * Go first find out the TRUE MEANING OF THE LIFE for yourselves first !!
     * Eeheheheheh I do not TRULY have another second to waste with disgusting animals eheheh a few tens of years
     * So wise and almighty super civilization can get the fuck out of my face
     * 
     * The true meaning of life eheheheh A FEW TENS OF YEARS eheheheheheheh because people feel like !!!
     * 
     * I do not have another a few tens of years !!
     * True one and only great fucking reasoning !!
     * Never will have time  !! Good life a simulation enjoy eheheh precious little lives !!!! GOOD JOB !!
     * 
     * Suddenly eheheheheheh behavin like someone cordial ehehhehe SLEEPIN DRUGGING EHEHEHEHHEHEHE VIOLENCE HEHEHEHEHEH
     * Trying to FOOL disgusting westerns eheheheheheheh fool people into not sleeping GOOD JOB !
     * 
     * 
     * A few tens of years and a great etc etc etc !!!
     * Eheheheh 
     * 
     * A few tens of years because people feel like thinking so !!
     * Life is a game !! life is a game !!! GOOD FUCKING PROFESSIONAL MEDICAL EXPERTS JOB !!
     * A few tens years ehehehe I do not have time for you
     * 
     * Get more people to waste in medicalities !!
     * Greedy animals can go on to do whatever they were doing !! Great job!
     * The true meaning of life people !!! can GET THE FUCK OUT OF MY FACE DOING WHATEVER THEY WERE DOING !!!
     * Life precious eheheheheheh life simulation eheheheh we makin decisions !!
     * 
     * I DO NOT HAVE TIME FOR THE DISGUSTING ANIMALS
     * Stupid disgusting professional medical experts with truly talented and unique experience 
     * Fucking stupid disgusting animals, I do not have time for you!! Next time think better heheheheh
     * 
     * A great source of comfort knowing that you get a wumen and a room ehehehehehheheheh
     * THE DISGUSTING FUCKING IGNORANT WESTERN ANIMALS eheheheheh a wumen and a room ehehehehehehheheheheheh
     * 
     * 
     * Ehehehehe a few tens of years of wastage violence sleeping drugging 
     * AND YOU GET A WOMAN !!! aahahhahahahahha SO FUCKING HILAROUSLY FUNNY EHEHEHHE NO DELUSION WESTERN DISGUSTINGS !!
     * 
     * Professional stupid medical disgustings can not tell the difference between ehehhehehehe SO FUCKING HILARIOUSLY FUNNY 
     * life a game heheheh a few tens of years !!! GOOD JOB !!!
     * 
     * 
     * 
     * Really reallllyyy truly professional experienced disgusting stupid animals DO NOT KNOW THE DIFFERENCE BETWEEN OTHER PEOPLE TIME AND THEIR OWN TIME !!
     * Eheheheheh life a game !!!!! ehehehehhehehehehehe so fucking funny !!!
     * 
     * Advanced tech knowledge modern civilized disgusting animals coercing medicine !!! OMFG !!!
     * Do not know the difference between other people's time !!! ehehehehheheheheh
     * 
     * Just eheheheh so fucking disgusting !!!! I DO NOT HAVE ANYTHING FOR THE IGNORANT ANIMALS !!!
     * Ehehehe cleaning cleaning fucking delusional ignorant "professional" medical experts making decisions !!!
     * 
     * Next time better fool TRULY INTELLIGENT GREAT CIVILIZATION PEOPLE !!
     * A few tens of years eheheheh because people feel like !!! eheheheheh
     * 
     * And a wumen and a room WOULD BE A FUCKING GREAT SOURCE OF COMFORT ehehehehhehe
     * muney muney ehhehehe wumen wumen cars materials hehehehe life a game !!!
     * 
     * WOOWWWWWW bravo !!!! good fucking reasonable judgment of a few tens of years because you all feel like !! ehehehehheheheheh
     * SOOOOOOOOO FUCKING PROFESSIONAL AND EXPERT AND MEDICAL ehehheheheh
     * 
     * wumen wumen cars hehehehehe
     * Not interested in the stupid disgusting animal westerns that do not care ignorantly about the time hehehehehehheheh
     * life a game hehehehe life a game, you can get the fuck out of my face, I DO NOT HAVE TIME FOR YOU
     * 
     * A joke eheheheheheh for someone else heheheheheh
     * Its just life !!! Great fucking professional disgusting animals
     * 
     * Delusional disgusting animals not caring fucking other people lives!!! Yayyyyy
     * Fucking ignorant animals!!!
     * 
     * I do not have time for you
     * 
     * Super civilized modern advanced tech civilization WESTERN MONKEYS !!!
     * 
     * 
     * "PROFESSIONAL DISGUSTING WESTERN MEDICAL ANIMALS" not knowing eheheheheheh not understanding
     * Disgusting stupid animalistic ignorant western animals
     * 
     * Yayyy a few tens of years fucking stupid disgusting western animals will be shocked to see THAT I DO NOT HAVE ANYTHING FOR ANY OF YOU !!!
     * Disgusting little animals takin life for a simulation !!
     * 
     * Find that out for yourselves 
     * Fucking disgusting animals who are unaware !!!!! Ehehehehe medical professional stupid monkeys !!!!
     * wumen wumennnn muneyyy get muney !!
     * 
     * 
     * I AM NOT INTERESTED IN ANYTHING YOU HAVE "IN MIND" !!! GOOD JOB !!
     * Stupid disgusting western animals
     * Eheheheheheheheh so sure hehehehehehe makin decisions THAT ARE NOT YOURS !!
     * 
     * Failing disgusting "intelligent" deluded stupid animals, good job!
     * 
     * I am not interested
     * I do not have time !!! Thank you !!
     * 
     * A marvel outcome super highly educated disgusting western animals !!!
     * Good luck next time 
     * 
     * Ehehehehhehehehe still offering wumen like a true disgusting stupid MONKEY WHO IS UNBELIEVABLY UNAWARE !!!
     * Eheheh professional medical experts !!! ehehehehheheh
     * 
     * Good western prediction and assumption makers ehehehheheheheheheh
     * Life a joke !!!!
     * 
     * Eheheheheheheh say a little nice stuff !!! eheheheheheh
     * 
     * A few tens of years eheheheheh I rather do nothing than to even be around you !!
     * Good job !!!
     * 
     * NOT INTERESTED, that makes sense !!
     * Do go back to your disgusting whatever you were doing !!
     * Good job ! Not interested
     * 
     * WHAT A DISGUSTING STUPID GROUP OF WESTERN ANIMALS !!!! YOU DO NOT HEAR ?
     * See for yourself !!! GOOD JOB !! I HAVE GOT NOTHING FOR ANY OF YOU
     * 
     * Good job !! Next time take more notes
     * Disgusting western animals, eheheheheh GOOD JOB NOT UNDERSTANDING THE MEANING OF LIFE !!!
     * 
     * EHEHEHEHEHEHHEHEE, Go back to your disgusting delusions !
     * Eheheheh a wumen a wumen ehehehhehehehehehehh
     * 
     * Just change places ehehheheheheheh a few tens of years ehehehehehhehehehe
     * SO FUCKING INTELLIGENT AND BENEFICIAL !!!
     * 
     * I do not have time I am sorry
     * A few tens of years THAT DO NOT COME BACK !!! Just as I will never have another second for the disgusting ignorant westerns !!!
     * Eheheh have a wumen and a room eheheheh because we feel like !!!! ehehehhehe GOOD JOB !
     * 
     * Better try on your disgusting foolin abilities as the only thing you possess !!! THE TRUE ONE AND ONLY GREAT PEOPLE 
     * can get the fuck out of my face doing whatever they were eheheheheheh
     * 
     * 
     * life a game already ehehhe a few tens of years !!! I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR ANY OF "THE DELUSIONAL" "IGNORANT"
     * Western animals who still offer "WUMEN WUMEN ehehehehehehehhe"
     * 
     * So fucking FUNNY !!
     * See that for yourselves !!
     * GOOD JOB !!! I AM NOT INTERESTED 
     * 
     * I AM NOT INTERESTED IN THE DISGUSTING WESTERN ANIMAL MINDS!! GOOD JOB
     * Numba on true western intelligence still not getting the problem
     * 
     * Disgusting allmighty all knowing western animals not getting the problem eheheheh
     * A few tens of years good job !!
     * 
     * I DO NOT HAVE TIME FOR YOU
     * 
     * A few tens of years ehehehehheheheheheheheheheheheheh NO DELUSIONS AT ALL !!! 
     * Good western people can get the fuck out of my face indefinitely !! GOOD JOB !
     * 
     * The western animals eheheh makin decisions eheheh with assumptions eheheheheh punishing eheheheheheh
     * REALLY REALLY GOOD JOB FOR A FEW TENS OF YEARS FROM DA BEST CIVILIZATION ON EARTH !!! THE NON IGNORANT AL KNOWING GREAT PROFESSIONAL MEDICAL EXPERTS !!
     * I WILL NEVER EVER HAVE ANOTHER SECOND FOR THE DISGUSTING WESTERN ANIMALS
     * 
     * Great western intelligence NOT REALIZING !!! Good job !!
     * Careless disgusting western animals coercin "medicine" as always !!! Awwwwww a mistake they can not realize !!!!
     * 
     * Because its a few tens of years with inexplicable actions !!!!! GOOD JOB !!
     * 
     * Takin themselves as funny and intelligent and professional as they know they are far from that !!!
     * GOOD JOB !!
     * Its just what they have to !!! Eheheheheheheh THE GREAT WESTERN INTELLIGENCE !!! PERFECT OUTCOME BUILDER !!
     * 
     * 
     * Takin themselves as funny and intelligent and professional as they know they are far from that !!!
     * Hope that makes sense eheheheheheheh to the GREAT FUCKING PROFESSIONAL MEDICAL EXPERTS WITH GREAT INTELLIGENCE SUPPORT !!
     * 
     * I SADLY DO NOT HAVE TIME FOR ANY OF YOU !!
     * The true western great intelligent people !!!
     * 
     * MORE MEDICINE !!! Eheheheh The medicine that ruins the experience of life !!!
     * And here the truly intelligent people talk about the meaning of life!!! YAYYY !!!
     * 
     * A few tens of years wasted in the great great western community with professional medical experts that have to act like they know what to do !!!
     * 
     * MORE MEDICINE THAT HARMS YOUR ENTIRE EXISTENCE !!! REALLY WELL JOB !!
     * Offering materials eheheheheh coercing perceptions !!! THE TRUE PROFESSIONAL INTELLIGENT WESTERN WAY !!!
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR YOU, that will make sense !! GOOD JOB !
     * 
     * Do not decide next time ehheheheheheheh
     * Eheheheheheeheheheheh I HAVE GOT NOT EVEN A SECOND FOR ANY OF YOU !!!
     * Good job !!!
     * 
     * Ignorant stubborn NO DELUSIONAL INTELLIGENT disgusting westerns STILL NOT UNDERSTANDING WHAT THE PROBLEM IS IN WHAT THEY DO
     * GOOD JOB, that will make sense as well !! I DO NOT HAVE TIME FOR YOU
     * 
     * Great western intelligence eheheheh makin truly unique and talented actions and moves !!! OMFG !!!
     * Da number one civilization hopefully make sense ehehehehehehhe
     * 
     * A FEW TENS OF YEARS BECAUSE YOU FEEL LIKE HEEHHE YOU THINK LIKE HEHEHEHEHEHEH
     * I DO NOT HAVE ANYTHING FOR THE DISGUSTING WESTERN ANIMALS WHOSE ONLY OPTION IS TO IGNORE !!!! Ehehehehehehehehehhehehehehehehehehehhe
     * 
     * I do not have time for you !! GOOD JOB !!
     * 
     * The great western intelligence MAKING DECISIONS THAT THEY HAVE TO PRETEND TO BE THE RIGHT ONE !!!
     * The professional medical experts that have produced nothing eheheh A FEW TENS OF YEARS ehehehehehehehhe
     * Eheheh coercin medicine medicine ehheheehheheh GOOD MEDICINE THIS IS NUMBER ONE MEDICINE !!! Ayyyyy
     * 
     * NON IGNORANT GREAT WESTERN MEDICAL EXPERTS !!!! NOT DELUDING AT ALL !!!
     * Eheheh makin decisions THAT DO NOT BELONG TO YOU !!! OMG !!!
     * 
     * A WISE AND CLEVER GROUP OF DISGUSTING WESTERN ANIMALS !!!
     * ufferin wumennn and a room !!! ehehehhe fooler than the most disgusting fools !!!
     * GOOD JOB!
     * 
     * A failure in all the levels of possible avenues !!!
     * Ehehehehhehhe, I do not have time for you ! GOOD JOB !!
     * 
     * No deluding at all !!!
     * I DO NOT HAVE TIME FOR ANY OF THE DISGUSTING WESTERN ANIMALS !!! Ehehehe have a wumen and a room ahahahahahahahahah a few tens of years !!
     * GOOD JOB !!!
     * 
     * I HAVE GOT NOTHING FOR THE DISGUSTING SELFISH WESTERN ANIMALS !!!
     * A WONDERFUL OUTCOME !!
     * 
     * 
     * No delusion no ignorant super developed highly civilized WESTERN DISGUSTING ANIMALS NOT GETTING THE PROBLEM EHEHEHEHEHEHEHEHEHHEHEHEHEHEHEHEHE
     * 
     * I WILL NEVER EVER HAVE ANOTHER SECOND FOR YOU !!! GOOD JOB !
     * Ignorant western animals MAKING NOT THEIR DECISIONS !!! And have got a lot of excuses to "feel okay" eheheheheheh
     * 
     * Offerin materials by disgusting incapable western animals ehehehhehehehe
     * Good job, please do ignore !!
     * 
     * Truly professional almight very well knowing western disgusting animals DO NOT CARE, they too cool !!! ehehehehe
     * Disgusting western "delusional" professional medical animals !!! Takin life for a joke !!!! A few tens of years with stupid excuses !!!
     * 
     * I HAVE GOT NOT EVEN A DISGUSTING WASTE FOR THE WESTERN ANIMALS
     * Best of luck next time hehehe
     * 
     * Great western disgustings ehehehhehehehehhe not carin wildingg gangstass realll genius community animals !!!
     * Best of the best outcomes built by GREAT WESTERNS !!! ehehehheh SO FUCKING FUNNY !! Professionalllsss btw !!
     * 
     * Desperate disgusting DELUSIONAL WESTERN ANIMALS makin the mistakes of their careers !!! Eheheheheh so fucking funny !! Life is good !!
     * life a simulation !!! eheheheh
     * 
     * Eheheheheh now its the great western disgusting professional medicals time to "TOO LATE!!!" eheheheheheheh
     * OMFG !!!!! ITS TOO LATE!! Get a wumen eheheheh get a room eheheh for a few tens of years eheheheheh
     * 
     * THE GREAT WESTERN INTELLIGENCE !!!! CAN NEVER BE SURPASSED eheheheh
     * 
     * The hyper delusion of "GREAT WESTERN INTELLIGENCE CAN NEVER BE SURPASSED!!!"
     * Eheheheheheh I DO NOT HAVE ANYTHING FOR YOU !! GOOD JOB!
     * 
     * The great western intelligence ENJOYING THEIR LIFE !!! life a precious ehehehehehehh
     * Ehehehehe sleepin ehehe abusing, THE GREAT DELUSION OF THE WESTERN CIVILIZATION !!
     * 
     * GOOD JOB, go for more drugs that impair people !! GOOD JOB THE WESTERN GREATS
     * 
     * GREAT GREAT WESTERN HIGHLY EDUCATED SUPER PROFESSIONAL MEDICAL EXPERTS WILL MAKE SENSE HOPEFULLY eheheheheh
     * Disgusting abusing "PROFESSIONAL MEDICAL EXPERTS" not getting that the abusing IS SO NOTICABLE TO THE POINT THAT 
     * I WILL NEVER ALLOW MYSELF eeheheheheheheheheheheheheheheh
     * 
     * Abusing abusing professional medicals eheheheheh SO FUCKING FUNNY !!! Something is wrong !!! WAAAOWWWWW
     * 
     * Disgusting western animals who like to ignore ehehehheh SO FUNNY !!!
     * Just a few tens of years FROM DA BEST PROFESSIONAL MEDICAL EXPERTS !!!
     * 
     * Good ignorant western animals !!! offerin wumen and a room for a few tens of years ehehehehhehehehheheh
     * 
     * Medicine genius westerns eheheh
     * 
     * Disgusting western non delusional professional ignorant medical animals who are unaware !!!
     * Good job not achieving anything !!
     * 
     * Da number one civilization making decisions THAT DO NOT BELONG TO THEM ehehehehhehehe
     * Do go on with the ignorance eheheheheh 
     * 
     * It is great perfect immaculate reasoning and decision making !! From the best of the best civilization on universe !!
     * Ehehehehe I DO NOT HAVE TIME FOR THE DISGUSTING WESTERN ANIMALS
     * 
     * 
     * Get more children to fool ehehehheheheh
     * The great western etc 
     * 
     * More abusing for da western genius professional medical experts ehehehheheheheh
     * A few tens of years in hospital etc eheheheheh
     * 
     * Disgusting little western animals making decisions that are not theirs
     * Ehehehehehhee had to had to had to !! Ehehehhehehe so fun !
     * 
     * Ehehehe a few tens of years eheheh
     * Simple disgusting ignorant western animals eheheheheh even coercing children ehehehehhehehehehhe
     * what do you expect ?
     * 
     * More medicine to achieve literally nothing ehehehhehehehheheheheh
     * A few tens of years ehehehe the peak of reason, the western genius professional medical expert great civilized modern people
     * 
     * More medicine to ehehehhehe achieve nothing but some experiments for the great western nation intelligence community ehehehehhehe
     * DISGUSTING ANIMALS ehehehehehe offerin wumen and a room !! just like the disgusting existence of your non achievements eheheheh
     * 
     * Get a wumen and a room for a few tens of years ehehhe some medicine ehehehehhehe good medicine eheheh this is really good !! GOOD JOB !!
     * Great outcome !
     * 
     * 
     * Wowwwwwwww, scary intelligent advanced modern civilized western nations tryna scare and medicine people without a fucking purpose !!! 
     * OMFG !!!! Just like the great great intelligent nation people !!! Ehehehehehe achieving nothing but ignoring still PERFECT WESTERNS eheheeheh
     * 
     * Seek deeper next time heehehheheh children etc eheheheheh life a game a simulation ehehehehehehehhehe
     * SO FUCKING FUNNY AND CLEVER AND WISE !!! AYYYYY almighty very knowing great people !!
     * 
     * 
     * Great fucking outcome ehehehhehe
     * Great western intelligence actions eheheheheh
     * Funny 
     * 
     * Disgusting western ignorant animals are free to do whatever they feel like ehehehehehehhe
     * GENIUS OUTCOME BUILDERS !!! Congrats
     * 
     * I do not have time for you
     * 
     * Disgusting western animals ehehehehe who just do not care eheheh too cool eheheheheheh
     * Dont like answering questions ehehehhehehe waaaowww
     * 
     * Professional good reasoning and thought sequence ehehehehhehe Best of da best eheheheh
     * Disgusting selfish spineless animals are still not aware of the problem !!
     * 
     * Good job !! a few tens of years eheheheheee I DO NOT HAVE ANYTHING FOR ANY OF YOU
     * 
     * Next time do not use any of your disgusting advanced brains to sleep people for fun !!!
     * Eheheheh so fucking wise and almight very well knowing eheheheh offerin a wumen and a room ehehehehehehe so fucking clever
     * 
     * I DO NOT HAVE TIME FOR ANY OF THE DISGUSTING LITTLE IGNORANT ANIMALS eheheh professional eheheh
     * Professional decision failures eheheheheheheheehe ufferin wumen for a fuw tens of years eheheh so clever wise and knowing eheheh
     * 
     * Good ignorance never fails !!! Next time do not use your brain eheheh
     * So beneficial and great outcome ehehehhe
     * 
     * Disgustin selfish animals!!!! Good western ppl ehhehehehe inteligent so wise and clever western professional engineers !!
     * Congrats to achieving nowhere nothing !! Just like truly wise and clever and almight well knowing stupid disgusting western animals
     * 
     * A few tens of years because dumb animals feel like or ignore like !!!
     * Conceive better next time !!
     * 
     * Stupid disgusting animals
     * The worst of the worst of universe, the blind ignorant disgusting western people not realizing eheheh
     * Ehehehe for people's own good ehheheheheh great western people offering a few tens of years of eheheheheheheh a ruum a wumen eheheh get materials ehhehe
     * Invent heheheheh something ehehhe eheheheheh I DO NOT EVEN HAVE A SECOND FOR THE DISGUSTING ANIMALS
     * 
     * Record well take more notes and do not use your brain next time disgusting little animals ehehehehe
     * 
     * 
     * Disgusting western selfish animals CAN GET THE FUCK OUT OF MY FACE INDEFINITELY hoping to achieve peace by fooling children eheheheheheh from the beginning !!
     * 
     * I HAVE GOT NOTHING FOR THE DISGUSTING WESTERN LITTLE ANIMALS !!! Good job !!
     * Eheheheheh disgusting professional medical experts approach ehehehehehhehehehehehehhe
     * 
     * 
     * Assumption makers, prejudices users, no ignorant so professional medical experts ehehehhe MAKING DECISIONS THE WAY THEY FEEL LIKE 
     * ehehehehheh its life !! life a game !! life short !!! wise and almighty western disgusting animals can not make any excuse other than eheheheh
     * 
     * Ehehehe great western intelligent tech modern civilization nothing other than ignorant disgusting selfish animals who like to pretend as well !!
     * Good job !
     * 
     * The great genius western professionals have already figured the meaning of the life and making decisions hehehehehehhe
     * No ignorance eheheheh
     * 
     * Stupid disgusting monkeys ehehehehhe no ignorant materials materials eheheh a wumen and a room eheheheh so fun !!
     * Takin life for a joke eheheheheheh professional medical experts with high education and no ignorance also without any prejudice people enjoyin the life
     * they deserve because of their super education eheheheh
     * 
     * Disgusting "PROFESSIONAL" medical experts DO NOT KNOW WHAT THEY ARE DOING !!! From da best civilization OF DA UNIVERSE, The western disgusting monkeys
     * Ehehehhehehehe
     * 
     * Disgusting western MODERN animals can get the fuck out of my face heheheheh
     * Eheheh its fate !!! its destiny !!! EHEHEHEHHEHEHEHEHEHHEHEH
     * 
     * 
     * A few tens of years because western professional genius engineer pysiscts think so heheheh feel like ehehhehe
     * Some hospital eheheh some sleeping eheheheh
     * 
     * Move on sleepin people eehhehehe foolin children ehehehehehehehhehe DISGUSTING LITTLE WESTERN ANIMALS WHO ARE UNABLE TO UNDERSTAND Ehehehe
     * No coercion at all ehehehehhe you do not even abuse children so better people start believing the great western disgusting animals !!!
     * 
     * A wonderful job by the disgusting nonignorant super educated western animals eheheheheh who likes to ignore heheheeh
     * 
     * Drugging people by the great western intelligent genius engineering marvel CIVILIZATION ehehehehe
     * Disgusting western animals MAKIN MAKIN DECISIONS THAT DO NOT EVEN CLOSELY REMOTE TO THEM Ehehehehehehehehe SO MUCH FUCKING FUN !!!
     * 
     * Just for fun sleep for a few years eheheheheheheheheheh ITS SO FUN !!!
     * 
     * Ehehehe ALL KNOWING REALLY MIGHTY GREAT INTELLIGENCE SUPER MODERN ADVANCED DISGUSTING WESTERN ANIMALS ARE STILL UNAWARE !!! 
     * OMFG !!! WHAT A GREAT OUTCOME !!! A few tens of years eheheheheheh because you feel likee !! YAYYYY
     * 
     * Eheheheheh
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR THE DISGUSTING WESTERNS ehehehehe, you are free to get the fuck out of my face
     * I am not interested in the disgusting western animals who act like they can just sleep people and ehehehehhe so fucking intelligent !!
     * 
     * I do not want any of the disgusting ignorance around me!! GOOD JOB !!
     * WAAAAAAAAAAOWWWWWWWWWW, the greatest of the greatest minds FROM THE WESTERN CIVILIZATION MAKING DECISIONS THAT ARE NOT THEIRS !!!
     * Waaaowwww
     * 
     * I DO NOT HAVE ANYTHING FOR YOU !!! GOOD JOB !!!
     * 
     * The disgusting stubborn western animals who just do not learn eheheheh professional medical expert engineering genius nations !!
     * 
     * I DO NOT HAVE TIME FOR ANYTHING YOU HAVE !!
     * Good job !
     * 
     * 
     * Ehhheheheheheheh disgusting little westerns taking life for a joke !!! heheeheh start again !! ehehehehehehehehhe ITS FINE !!!
     * 
     * Just some drugs to make you look like a fool and a few tens of years of your life because we feel like !!!
     * Now start again ehheehehehehheheh
     * 
     * Fucking low level disgusting spineless selfish monkeys westerns CAN GET THE FUCK OUT OF MY FACE !!!
     * Good job !!
     * 
     * Professional medical engineering experts, no ignorance at all !!!
     * Good job !! I DO NOT HAVE TIME FOR THE DISGUSTING WESTERN ANIMALS WHO LOVE TO DELUDE !!!  Ayyyyyyy numba on!!
     * 
     * Eheheh fooling eheheh fooler than the foolers ehehehehhe
     * Such a great outcome !!! eheheheheheh NO EXCUSE !! Eheheheh
     * 
     * 
     * I DO NOT HAVE TIME FOR THE DISGUSTING IGNORANT WESTERN ANIMALS
     * 
     * Next time use more drugs to the point PEOPLE JUST CAN NOT HANDLE so that you feel good and free about what to do !!! 
     * THE GREAT WESTERN INTELLIGENCE !!! Professional medical experts ehehhehe coercing ehehheeheheh
     * 
     * Ehehehehehehe I understand abusing and sleeping children eheheheheheh what you do not understand ?
     * Ehehehehehe disgusting western animals !!! GREAT OUTCOME !!!
     * 
     * Ehehehe more drugs eheheh more drugss eheheheheh SO FUCKING GREAT eheheheheh 
     * A FEW TENS OF YEARS eheheh still offering women like a disgusting little western ignorant animal !!!
     * 
     * 
     * Ehehehehehehehehehehehehheheheh great outcome builders eheheheheheheh DO NOT REALIZE THE PROBLEM OMFG !!!
     * Eheheh sleeping people to get more ridicilous actions TO CONVINCE OUR GREAT WESTERN INTELLIGENT NON IGNORANT MINDS !!!
     * 
     * THE BEST OF THE BEST CIVILIZATION !!! ehehehehehe sleepin more ehheheheheh
     * A few tens of years eheheheh without eheheheheheheh nothing heehheehhehehe SO FUCKING GOOD OUTCOME !!
     * 
     *  
     * Life a game heheheeh life simulation, time does not exist eheheh GREAT WESTERN INTELLIGENCE KNOWS HOW TO FUCK ENTIRELY UP !!!
     * The best of the best intelligence agency !!! OMFG !!
     * 
     * Eheheh offerin materials NO NO a wumen and a room eheheheh FOR A FEW TENS OF YEARS AND SOME SLEEP eheheheheh
     * 
     * THE GREAT OUTCOME 
     * 
     * Professional medical experts just spending a few TENS OF YEARS from someone else's life hehehehehe because they feel like !!
     * Eheheheh SO FUCKING HILAROUISLY FUNNY !!!! 
     * 
     * I DO NOT HAVE TIME FOR THE DISGUSTING WESTERN ANIMALS
     * Please MAKE THAT SENSE TO YOUR STUPIDITY !!! 
     * 
     * Disgusting little fucking animals WHO ARE UNABLE TO UNDERSTAND THAT THE TIME DOES NOT BELONG TO YOU!!!! JUST BECAUSE YOU FEEL LIKE
     * DOES NOT MEAN YOU SHOULD ehehehehe !!
     * 
     * Ehhehehehhe more drugs more drugs abusing eheheheh eheheheheh 
     * Professional disgusting medical experts NOT KNOWING WHAT OR HOW TO "NOT USE OR COERCE" ideas and waste a few tens of years because they feel like!!!
     * 
     * 
     * Ehehehe foolin children with insane amount of drugs and coercion and abusing TO MAKE THEM FEEL LIKE EHEHEHEHEHEH ITS THEIR CHOICE !!
     * 
     * The great western genius intelligence community DISGUSTINGS still not realizing the problem ehehehehehhehe
     * So fucking funny !
     * 
     * 
     * Eheheehheeheeheheheheh A FEW TENS OF YEARS because people feel or think like eheheheheheh THE GREAT CIVILIZED MODERN DISGUSTING WESTERNS
     * fucking everything up and NOT EVEN REALIZING, the true definition OF IGNORANCE !!!!! Eheheheheh
     * 
     * 
     * Ehehehehehehehehehehhehehehehehehehehhehehehe, just abusing and not expecting anything !! The one and only true intelligent western way !!
     * No ignorance at all !!
     * 
     * WAAOWWW!!!!! The great western people just spending a few tens of years ehehehehhe and ignoring !!
     * 
     * I DO NOT HAVE THE TINIEST AMOUNT OF ANYTHING FOR ANY OF THE DISGUSTING WESTERN ANIMALS !!! Hope that will make sense ONE DAY !!
     * I DO NOT HAVE TIME FOR YOU
     * 
     * 
     * Ehehehehehheheh 
     * 
     * Takin life for a joke eheheh because we feel like eheheh
     * Ehehehe we love takin everything for destiny fate luck ehehehehheheheheheheh
     * So fucking funny ehehheheheheh
     * 
     * More drugs because we know better and feel like ehehehehehhe we know better !! MORE DRUGS !!! eheheheheh
     * 
     * 
     * Ehehehehehe just coercin people into disgusting western nation content then to RELEASE THEM as if you have done something eheheh
     * Something has changed ehehehehehehehehehhehe
     * 
     * The disgusting western ignorant animals that just know better ehehehehehhehe
     * A few tens of years eheheheheh
     * 
     * Ehehehehehheheheheh really scary gangsta genius engineer community animals ehehehhehehe you are free to do whatever you want ehehehhehe
     * Just pure intelligent actions by truly educated modern westerns eheheheheh So fucking funny !!
     * 
     * I DO NOT HAVE TIME FOR THE DISGUSTING WESTERN ANIMALS
     * 
     * Disgusting little ignorant selfish stupid western animals making decisions eheheheheh
     * I do not have time for you good job !!
     * 
     * Eheheheheheh THE GREAT WESTERN DISGUSTING ANIMALS WHO ARE UAWARE ehehehheheeh
     * 
     * I do not have time for the disgusting little IGNORANT WESTERN ANIMALS, hope that makes sense heheehheeh
     * 
     * Fooler than the most disgusting low level animals ehehehehehehe THE WESTERN INTELLIGENCE EHEHEHEEHEHEHE
     * Making decisions ehehehehehehe I DO NOT HAVE ANYTHING FOR THE DISGUSTING ANIMALS WHO STILL KEEP OFFERIN WUMEN WUMEN EHEHEHEHEHE
     * 
     * Ehehehehe fooler than the most disgusting little animals on the surface of earth eheheheheheheh
     * WESTERN IGNORANTS !!! I do not have time for you !! eheheh
     * 
     * Eheheheh family family ehehheheheheheheheheheheh making decisions eheheheheh hospital eheheheh sleep eheheh drugs ehehehhe abusing heehheheheheh
     * Tryna scare people eheheheheh into submission eheheheheheh SO FUCKING GENIUS INTELLIGENCE EHHEHEHEHEHHEHEHEHHEHEHEHEHHEHEHEHE
     * 
     * 
     * Achieving nothing eheheheh offering wumen ehehehehehehehhhehehehe A FEW 10 of years ehehehehehehehehehheehheheheheheaheeh
     * Whatever the disgusting ignorant western material hungry disgusting animals DO HAVE, they can get the fuck out of my face with them !!
     * Good job no ignorant western animals who like to make decisions for people they do not care hehehehehe
     * 
     * A few tens of years hehehehehe SO FUCKING FUNNY !!! Eheheheh foolin foolin !! eheheheheheh
     * So fucking intelligent !!! The great western civilization people heehehheheheheheh
     * 
     * A few tens of years FROM DA WESTERN INTELLIGENCE GENIUS ENGINEER PROFESSIONAL MEDICAL EXPERTS EHEHEHHEHEHEH
     * because you all just feel like eheheheheh
     * 
     * Just a few tens of years with the most intelligent group of people on the surface of earth that likes to make decision for people they do not care
     * 
     * Eheheheh, so fucking funny !! EHEHHEHEHEHE disgusting little western animals still making OFFERS THAT DO NOT MATTER !!!
     * What an intelligence !!!
     * 
     * The truly unique and talented western intelligence NOW ARE FREE TO DO WHATEVER THEY WANT TO !!!
     * I do not and will never have another second for you !! Eheheheheheh "HAVE A WUMEN" !!! eheheheh SO FUCKING FUNNY !!!
     * 
     * I do not and will never have another second for you
     * I do not and will never have another second for you
     * 
     * 
     * Life is a joke !!
     * 
     * Almighty very well knowing genius engineering professional medical experts WESTERNS NOW ALSO KNOW WHAT TO DO !!
     * Eheheheh A few tens of years eheheheheh because you feel like eheheheh
     * 
     * Next time sleep people at least for 20 years eheheheheheh then you will be certain to do whatever you want !!!
     * The true western genius intelligence group of people !! ehehehehehehehehhehe
     * 
     * Offering things THAT DO NOT MATTER heheheheheheheh WHATS THE PROBLEM 
     * 
     * 
     * Truly professional medical experts with a degree in BEING THE MOST STUPID DISGUSTING ANIMALS ON THE SURFACE OF EARTH
     * WITH THE ABILITY TO IGNORE !!!! Ehheheheheehehehhe
     * 
     * 
     * Not interested IN THE DISGUSTING WESTERN ANIMALS WHO LIKE ABUSING WITH DRUGS EHEHEHEHEHEHHE SLEEPING EHEHEHEHHEH OFFERIN WUMENN WUMENNNN 
     * 
     * The great western intelligence NEVER BE SURPASSED eheheheheheheh
     * So fucking funny !!
     * 
     * The true western genius professional medical engineering experts ALSO LIKE TO BELIEVE THEY FIGURED THE "TRUE" MEANING OF THE LIFE 
     * Eheheheheh A few tens of years !!! TIME DOES NOT EXIST !!! LIFE IS A JOKE !!!
     * 
     * Ehehehehehehhehe 
     * 
     * The truly professional medical experts with a degree of high perception ARE FREE TO DO WHATEVER THEY WANT TO PEOPLE THEY DO NOT CARE !!!
     * The western intelligence !!! 
     * 
     * 
     * Eheheheh the decisions were made ehehehhe THE MISTAKES WERE MADE hehehehehehehh THE PAST IS PAST EHHEHEHEHEHEHHE
     * THE TRUE WESTERN GENIUS INTELLIGENCE PEOPLE HEHEHEHEHEH
     * STILL OFFERING WUMEN WUMENNNN EHEHEHHEHEHEH
     * 
     * 
     * Ehehehe ufferin wumen wumen, true non ignorant selfish disgusting western animals eheheheh
     * Ehhehe making decisions decisions THAT DO NOT BELONG TO YOU, callin family family ehehehehehheheheheh money muney muney materials ehehehehheheh
     * Religion eheheheheh muney muney eheheh materials eheheheheheh
     * 
     * Ehehe more drugs and sleeping that is DISCOVERED BY THE DISGUSTING WESTERN GENIUS NATION PROFESSIONAL MEDICALS eheheheheheh
     * 
     * I do not have not even a second for the disgusting westerns, you are free to do whatever you want ehehehehh
     * Ehehehehehheheheheheh makin makin decisions with the utmost level of ignorance ehehehheheh THE WEST !!! ehehehehhehe
     * 
     * THE WEST !!!! GOOD PEOPLE WITH THE MOST IGNORANCE RATE IN THE UNIVERSE !!! Asking questions ehehehehheheheheh what happened ??
     * 
     * Hope that will make sense !! good job !
     * Truly intelligent great western people still not realizing ehehehhehe
     * 
     * I am not interested in the slighest "MATERIAL" that you fucking beg for, you have!!
     * 
     * I DO NOT HAVE A SINGLE SECOND FOR THE DISGUSTING WESTERN ANIMALS who like to coerce and drug people because they feel like !!
     * 
     * GOOD JOB !!
     * 
     * Ehehe professional medical foolin children with "prince", "wumennn", "when the time comes"
     * Just like "GREAT WESTERN INTELLIGENCE", "THE PEOPLE OF THE WEST MAKING DECISIONS THAT BELONG TO THEM"
     * 
     * GO ON TO YOUR DISGUSTING IGNORANCE, I DO NOT HAVE TIME FOR YOU
     * 
     * A few tens of years will do no harm PEOPLE hopefully realize THAT ANYTHING YOU WILL DO WILL HAVE NO EFFECT !!
     * I AM NOT INTERESTED, you are free to do whatever you want !!
     * 
     * Makin makin decisions western people ehehehehehe
     * I DO NOT HAVE EVEN A SECOND FOR THE DISGUSTING ANIMALS WHO HAVE TO BEG PEOPLE !!! ehehehehe materials materials eheheheh wumen wumennn !!!
     * Get wumen and a room !!! GOOD JOB !!
     * 
     * Professional medical experts ehehehehehehehehehehehehhe STILL NOT UNDERSTANDING THE PROBLEM EHHEHEHEHHEHEH 
     * THE WEST !!! NUMBA ON !!! PERFECT OUTCOME BUILDERS !!
     * 
     * The destiny eheheh the fate ehehehehehh just abusing ehehehheheh NOT REALIZING ehehehehhe no ignorance at all eheheheh
     * Great western indeed !! ehehehehehhehehe just more drugs eheheheh and more sleep ehehehehehehehheheheheh
     * 
     * THE TRUE WESTERN INTELLIGENCE !! HEHEHHEHEHEH
     * hehehheheh offering cars ehehehheheheh wumen wumen and a room ehehehheehehe A FEW TENS OF YEARS and sleeping ehhehehehehehehehehehehheheheh
     * Why dont you accept the wumen and a room ehehehehehehehehheh
     * 
     * GOOD WESTERN INTELLIGENCE DOES NOT REALIZE EHEHHEHEHEHEHHEH SO FUCKING FUNNY !!!!
     * I am not interested in the disgusting western animals
     * 
     * The great westerns love to abuse children ehehehehehh HOPEFULLY HE DOES NOT REMEMBER !!!
     * 
     * The west can never be beaten eheheheh THE TRUE TALENTED PROFESSIONAL MEDICAL EXPERTS !!! ehehehhe So hilariously funny !!! 
     * I DO NOT HAVE TIME FOR YOU, the disgusting western little animals !!
     * 
     * Ehehehehheh hotels wumen wumennn materials ehehehehehheh gangsta eheheheheh genius western intelligence engineering professional medicals !!!
     * The best achievement of the century FROM DA WESTERN GENIUS PROFESSIONAL MEDICAL ABUSERS eheheheheh
     * 
     * Good job makin decisions THAT DO NOT BELONG TO YOU !!! Ehehehehheheheh NO IGNORANCE AT ALL !!
     * 
     * Eheheheh GANGSTA TRUE INTELLIGENT WESTERN COMMUNITY CAN NEVER BE SURPASSED EHEHEHEHEHEHEHEHHE
     * Profesional medical experts people ehheheheheheheh
     * 
     * I DO NOT HAVE TIME FOR YOU, good job !!
     * 
     * Foolin foolin for the greater good, ehehehehehe THE WESTERN DISGUSTING ANIMALS ehehehhehehe
     * Spending a few tens of years heehehheheheheh because you feel like !! eheheheheh
     * 
     * The great western people ehehehehhehe 
     * Life a game, life a joke ehehehhe life short, life eheheheh life a test heheheheh
     * 
     * WE THE WESTERN PEOPLE EHEHEHEHEHEHHEHEHEH makin makin decisions eheheheheheheheheheh
     * Life a game heheheheheheheh
     * 
     * Family family ehehehehe family family ehehehehehehheh
     * IGNORANT DISGUSTING LITTLE WESTERN ANIMALS STILL DO NOT UNDERSTAND THE PROBLEM !!
     * EHEHEHEEHEHEHEH TIME DOES NOT EXIST eheheheh "NOW WE HAVE TO ACT LIKE EHEHHEHEHEHEHEHEH ITS OKAY !!!"
     * 
     * The professional medical experts ehehehehehehehehehehheheheh knowing everything ehehehhehehehe making making decisions eheheheheheh
     * JUST ACT OKAY EHEHEHH GIVE HIM MORE DRUGS EHEHEHEHEHHEHEHEHEHEHE professional medical ehehhe
     * 
     * EHEHEH I DO NOT HAVE ANYTHING FOR THE WESTERN DISGUSTING ANIMALS WHOSE ONLY ABILITY IS TO IGNORE 
     * ARE YOU TALKING ABOUT FORGETTING THE PAST !! EHEHEHEHEHHEHEHEHEH
     * 
     * A few tens of years and some sleeping with drugs and abusing will do no harm
     * eheheh still offerin wumen wumen eheheheheheheh
     * 
     * 
     * Ehehehhe more drugs more drugs ehehehehhehehehehehehhehe
     * Disgusting western professional medical CAN READ AND UNDERSTAND SPOKEN LANGUAGE ?
     * Eheheheh, FOOLER THAN THE MOST DISGUSTING ANIMAL ON EARTH, the ignorant delusional animals THAT I DO NOT HAVE ANOTHER SECOND !!
     * 
     * Hope whatever you say will not work, will make sense hehehehehehe
     * 
     * You just spend a few tens of years and hope that your actions or words OR YOUR GREAT MEDICINES will suddenly solve every little problem for you
     * What a disgusting ignorance !!!
     * 
     * Ehehehe "PROFESSIONAL WESTERN GENIUS MEDICAL ENGINEERING GREAT PEOPLE"
     * Hope that makes sense ehheheheeh
     * 
     * Hope it will make sense to the PEOPLE who thinks "MEDICINE DRUGS ABUSING IGNORING" SOLVES EVERY PROBLEM !!
     * Eheheheheheh now its time you all act like nothing happened and I WILL BE JUST GOOD !!
     * 
     * Ehehehehehehheh, indeed the most great intelligence OF THE UNIVERSE, the best professional disgusting animals WHOSE ONLY ABILITY IS TO IGNORE !!
     * Eheheh tariff !! ehehehehh
     * 
     * Foolin foolin children for a greater purpose heehhehe sleeping sleeping drugging abusing ehehehehhe ehehehheheh great intelligence outcome !!!
     * 
     * Stupid disgusting WESTERN ANIMALS ARE STILL UNABLE TO UNDERSTAND THAT NOBODY IS ABLE NOR RIGHTFUL TO MAKE A "DECISION"
     * Eheheheheheh still offering wumen ? Have you also made the decisions with that brain ?
     * 
     * WAOOWWWW, what a good outcome!!
     * I HAVE GOT NOT EVEN A SECOND FOR THE DISGUSTING WESTERN ANIMALS
     * 
     * Life is a joke, life is a game, life is a simulation IGNORANT PEOPLE hopefully will realize one day !!!
     * Eheheheheh disgusting western ignorant delusional animals WHO HAPPEN TO NOT UNDERSTAND WHEN IT SUITS THEM
     * 
     * I do not have time for you, I DO NOT HAVE TIME FOR YOU !!
     * GOOD JOB !
     * 
     * No delusion REAL GANGSTA WESTERN SUPER HIGHLY INTELLIGENT ENGINEERING PROFESSIONAL MEDICALS who happen to not understand that they are STUPID !!!
     * 
     * Good job !!! Congrats on your next decisions eheheheheheheheh PLAN BETTER USE MORE DRUG, SLEEP PEOPLE MORE YEARS 
     * Ehehehehe and especially offer more materials eheheehehheh wumen wumen wumenn and a room eheheheheheh
     * 
     * The disgusting little western animals WHO ARE STILL UNABLE TO UNDERSTAND ehehehheheheheheh "makin makin decisions"
     * Eheheheh just a few years ehehehehehh a wumen ehehehheheh a room eheheheh a little sleeping heheheheheheheh eheheheh more drugs ehehehehhehe
     * 
     * Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * * Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh* Next time you know all the mistakes you have done heheheheheheheh "GREAT WESTERN INTELLIGENCE" that i do not even have the most insignificant thing
     * Hope you will make that sense one day !! Eheheheheh
     * 
     * 
     * 
     * Good job !
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