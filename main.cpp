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