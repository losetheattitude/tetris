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