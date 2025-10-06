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
     * Bravo !!!! You have done a wondaful job !!! what a great achivement and lovely chance with also some great great wise assumptions and decisions !!
     * Stupid disgusting animals indeed, wumen wumen muney muney puwer get cars mansion yayyyy we do not care!!! ayyy
     * 
     * Medication genius ppl ayyy marvel delusions ayyy
     * Definitely way to go, lovely chance genius nation, wise ppl etc, CAN GET THE FUCK OUT OF MY FACE
     * Makin assumptions, ehehehe YOLO !!! OMFGGG DA NUMBA ON WEST MAKING DECISIONSS !!! Lovelyyy
     * 
     * Quiet successful actions by the genius nation of da universe the great wise western civilization marvel imaginations great professional workers !!
     * Lovely actions indeed, What else could you be doing !! AYYYYY
     * 
     * Definitely genius ppl !! Woowww
     * Savioring da world by da very genius society ppl DA WEST, OMFG !!! Lovelyyy, get wumen muney genius nations !! OMFG!!
     * 
     * BRAVOO !!! What a wonderful job !!
     * Very very accurate and wise assumptions a clear sign of quietttttt the high intelligence THAT YOU ALL POSSESS OMFG !!!
     * What a lovely chance !! GO GALSS !!!! Da numba on society of da universe !!! great ppl
     * 
     * 
     * Da almighty all knowing genius societal disgusting animals, makin reall reallly wise assumptions and decisions using their 
     * superior abilities !! FROM OUT OF MY VICINITY
     * 
     * Ehehehehe really really clever ppl, makin assumptions and never lookin back, OMFGGG !!! What a lovely chance !!!
     * YOU CAN GET THE FUCK OUT OF MY FACE ! Brilliant ppl !!
     * 
     * 
     * Saved da whole world !! a blessing indeed to be AUROPEAN OMFG!!!!! Act okay !! Go away
     * Da almighty all knowing genius societal disgusting animals, makin really accurate assumptions and actions !!
     * GO FOR IT !!! 
     * 
     * Who could have guessed it !!! What a wonderful job and outcome !! You can get the fuck out of my face INDEFNITELY
     * Trickin and geniusing and wising really reallly good society and wonderful contitent ppl !! da western ppl da very best of the universe
     * makin assumptions, GO GALS !!
     * 
     * Eheheheh crisis management, wise nations, skilled genius animals ehehehe preemptive ehehehehe really wise ppl from da west !! OMFG !!!
     * Best of best decision and assumption makin machines FROM DA WEST !!! The most modern and advanced animals OMFG !!!!
     * 
     * From out of my vicinity 
     * Wonderful !!! you are the best ! you can now get the fuck out of my face
     * muney muney wumen ppl, wise definitely
     * 
     * Really skilled AND "WISE" ppl who coerce and scare little kids into believing ahahahh
     * Right ? That sounds too accurate !! OMFGGGG !!! Da numba on from the universe, Da great wise western disgusting animalss !!!
     * makin muney wumen assumptions decisions !!!! YAYYYYY
     * 
     * What a lovely chance !! 
     * You are not wanted ? Is that a coincidence eheheheh
     * Really skilled though, you can move on getting the fuck out of my face disgusting little western animals
     * 
     * Incredibly successful and well guessed assumptions !! wowwww
     * Ehehehe scaring coercing sleepin children eheheheh
     * Ehehe runnin experiments ehehehe druggin little kids eheheheheh wondaful nations from da western !!! Ayyyy
     * Wumen muney ppl, eheheheh delusioning eheheheh uffering eheheheheh 
     * 
     * Ehehehehe doin our jobs !! da saviors of da western great civilization genius ppl doctors phssyicispy psicologieis OMFG !!!
     * Especially, druggin kids and coercing and threatening eheheheheh and also some genius civilization talents OMFGG !!! lovely chance
     * 
     * Da outcome builders and sleepers, From da most advanced civilization, DA WEST
     * Wonderful decisions !!! You can get the fuck out of my face
     * 
     * The very most talented people of the 21. century makin assumptions !!! druggin coercing scarin children !!! OMFGG
     * What a lovely outcome !!
     * 
     * Ehehehe doin their most crucial jobs !! OMFGGG  Eheheheheh the western genius civilization ppl can GET THE FUCK OUT OF MY FACE indefinitely
     * Ehehehehehehehehehehehehehehehehe, wise clever ppl, not interested in your disgusting stupid "experiments"
     * 
     * Bravooo to you alll !!! you are marvelous !!! imagination stories all thatt !! you all the numba on !! the western disgusting animals !!
     * GO GALS!! Ehehehe sleepin makin assumptions, druggin eyyyyyyyy scarinn eyyyyy genius nation eyyyyy da west !!!
     * 
     * 
     * 
     * Ehehehe 21 21 21 21 yayyy we manipulate tech eheheheheh and feel skilled and talented at doing so messin with ppl
     * druggin scaring coercin children manipulating tech feeling intelligent, muney muney wumen !!! yayy
     * 
     * Good job !! Wondaful ppl from da west !! the whole mighty knowing good qualities !!! da best of the universe!!
     * Wise and genius engineerings !!! YOU CAN GET THE FUCK OUT OF MY FACE
     * 
     * Eehehhe especially sleeeping ppl and drugging and coercing and scaring eheheheheh
     * Lovely chance and outcome, whole mighty and knowing genius delusioning ppl !!! waaaowww
     * 
     * Definitely useful, you can go from out of my vicinity, I am not interested
     * Ehehehehe, a wonderful chance to do absolutely nothing but harm eheheheh Go the genius nations FROM DA WEST !!
     * 
     * Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!
     * 
     * * Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!* Not interested even in the slighest thing the animals like you can offer, hope that makes sense, now you have saviored the universe 
     * and are free to get the fuck out of my face indefinetely!!
     * 
     * Wonderful !! Definitely worth 30 years !! Definitely the way to go !! Look at all the benefits YOU HAVE ALL ACHIEVED DOING NOTHİNG !!
     * Eheheh had to be ehehe etc had to !! ayyyy the very advanced society!!
     * 
     * Number one !!! the best !! very wise and clever people !!! assumptions and decisions !! That were not YOUR PLACE !!! GO GALS !! Da number one 
     * I am not interested in anything you can provide, go back to your delusions marvelous ppl
     * 
     * Good reason!!! Perfect execution !!! very skilled and talented delusional ppl !! you can go away, I am not interested
     * Really skilled amazing people !!! Ehehehehe its fine !!
     * 
     * Really reallly serious and businesslike people not givin a fuck about WHAT IS NOT THEIR CONCERN and actin cool !!! OMFG !!!!
     * You have done it !! Ehehehe wumen wumen muney !! Really good job !
     * 
     * Tough and wise and clever people, da unique western society !!! The most useful sequence of actions !! Go gals
     * Real skreek gangstas genius wise clever advanced society shit !! Incomparable outcome !! wumen muney ppl !! FROM OUT OF MY VICINITY
     * GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce
     * * GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce
     * * GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce
     * * GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce
     * * GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce
     * * GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce* GET THE FUCK OUT OF MY FACE, Not interested in anything your disgusting minds can produce
     * 
     * GOOD JOB !!! No delusions at all !!! %100 accurate !!!
     * Wonderful outcome !!! real wise jobs !! Out of my vicinity not interested
     * 
     * Definitely talented number one on their own leagues players, especially at makin assumptions and decisions !!! Lovely outcome !! 
     * Ehehehe still not deluding and makin decisions for others THAT YOU DO NOT UNDERSTAND !!! ayyyyyy thats what I am talking about !! 
     * You are the number one on the universe !!! Your society and civilization and technology IS THE BEST ON THE WORLD !!! 
     * THE WESTERN PEOPLE !!! OMFGG!!!! Muney muney wumen cars house ayyyy, NOT INTERESTED 
     * 
     * Ehheheh keep it cool keep it cool !! eheheheh its our job !! eheheh its our job !!! keep it cool ayyyy
     * Druggin scaring ayyyyy keep it cool its our job !! yayayyay
     * 
     * Real good outcome !!! Great people !!!! Lovely things to do!!! eheheh keep him cool say nice stuff !! OMFG !!! The genius psycologists and
     * pysiscty!! !OMFG !!!
     * 
     * Definitely skilled and experienced people !! Totally knowing what they do !!! GO AWAY FROM OUT OF MY VICINITY, not interested
     * Definitely the most accurate assumptions and most useful beneficial outcomes BUILT BY WHO ?
     * THE genius western community !! and the communities' super great wise and clever participators !!!!
     * Eheheheheh makin assumptions makin decisions that are not yours eheheheheh
     * 
     * Very nice !! not interested
     * wumen wumen muney cars eheheheheh muney muney genius nation !!  ayyyyy OMFG !!! what a wonderful outcome !!
     * 
     * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! 
     * 
     * 
     * 
     * * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! * Ayyy like everyone said, THE GENIUS WEST, THE BEST COMMUNITY OVER THE WORLD AND ALSO UNIVERSE !!! The best outcome builders !!!
     * CAN GET THE FUCK OUT OF MY FACE !! 
     * 
     * Good job !! Fine execution, perfect ideas, wise people, clever actions, incomparable outcome !!! What a legend team you have !!
     * FROM OUT OF MY VICINITY !! Not interested 
     * 
     * Definitely the number one actions and team and outcome by far !! Nobody has ever seen or done such a thing as you have !!!
     * The greatest of the great, the perfect civilization the west!!! A blessing to be associated !!! OMFG !!!
     * 
     * A wonderful job !!! Go on, Decades of nothing is your ultimate desire  !!! OMFGG !!! wumen wumen muney people coming up with really genius ideas !!
     * CONGRATS DA WESTT
     * 
     * Have done an incredible job !! You are the best !!
     * Disgusting animals !!
     * 
     * 
     * Foolin, scarin, drugin, violencing, sleepin also !! really good job !! An immense amount of effort and the outcome is incomparable !!!
     * Done by the delusional genius nations !! Perfect! YOU CAN GET THE FUCK OUT OF MY FACE indefinitely !
     * 
     * Wonderful ! 1
     * Ehehehe sleepin people btw eheheh also makin beneficial actions and outcomes !!! Thats who we are !!! OMFG !! DA WESTERN DISGUSTING ANIMALS!!!
     * Ahh also some really strong reasoning !! GO GALS!
     * 
     * Da number one at deluding !! You are free to do whatever you want out of my vicinity !! eheheh
     * Go on makin decisions that you are not entitled to ehehehhe, good call ! wonderful outcome !
     * 
     * A wonderful vision from DA VERY BEST WEST !! makin wonders, producing outcomes that have never ever seen before !!
     * Ehehe runnin experiments eheheheh da very best west !!! What a lovely outcome !
     * 
     * Ehehehehe sleepin indeed eheheh get wumen get muney people sleepin scarin eheheh coercin children eheheheh deluding on eeheheheh
     * Takin life a joke eheheh but only others !!! OMFGGG !!! what a lovely chance !!! Life a joke life a simulation eheheh non deluding !!!
     * 
     * Get wumen ppl makin assumptions and outcomes, What could go wrong right ? eheheheh
     * Not interested indeed, good call, nice vision, immense amount of outcome built by JUST YOU ALL !! DA GREAT WEST !!
     * 
     * Ehehehe foreseeing ability is unmatchable !! The greatest of the great, the western delusions !!! GOOD CALL !!
     * 
     * The great engineers and foreseeing genius perfect people from the most advanced civilization making impossible possible !!
     * What a lovely outcome !! GO GALS 
     * 
     * Life a simulation, life a joke, ehehe time does not exist PEOPLE, OMFG !!!! not delusion at all !!! You have done it !!
     * 
     * The greatest of the great minds !!! making decisions and assumption with the most advanced foreseeing ability bestowed on earth !!!
     * The great civilization OF THE UNIVERSE !!! Makin outcomes incomparable to anything !! OMFG !!!
     * 
     * Good job !! fantastic outcome !! 
     * 
     * Good job yall !!! wonderful outcome !!! Go forever !! Not interested in your minds
     * Eheheh rolls royce wumen muney eheheh life a not game, simulation not ehehehhe, wumen wumenn get muney !!
     * Sleepin, druggin ahahahha funny stuff indeed, 
     * 
     * Wonderful western intelligence !!! Makin assumptions and decisions OMFG !!! The best of the best !!
     * Da greatest of da greatest !!!
     * 
     * Da european nations union, OMFG !!! What could have possibly gone wrong ?
     * Wonderful guys !!! Away from my vicinity !!
     * 
     * Thinking you have done a great job right ? Ehehehehehe nice civilization !! advanced techniques !! The number one !!
     * Greatest of the great ppl makin assumptions and decisions !!! The number one ? What did you think ?
     * 
     * Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!
     * 
     * 
     * * Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!* Awww you thought saying nice stuff would immediately cover 30 years ehehehehehehe GOOOD CALLL ALSO !!
     * Eheheh druggin and scaring and coercing you also thought would DO WONDERS !!!! GOOOOOODDD CALLLLLL !!!!
     * 
     * 
     * 
     * THE MOST ADVANCED CIVILIZATION AND GENIUS DELUDING PEOPLE OF THAT CIVILIZATION !!! Makin great outcomes !!! WONDERFUL !!
     * 
     * WAAAAAOWWWWWWWW, YOU HAVE DONE WONDERFUL !!! CONGRATS TO ALLL !!! Unseen actions !!! good outcomes !!! The genius engineering nations !!
     * And also really important detail FROM THE GENIUS NATION, "FORGET ABOUT THE PAST !!!!" because we do !!! eheheheheheh WE HAVE TOO !!! OMFGGG !!!!
     * 
     * The genius deluding nation is doing their BEST to avoid the reality !!!! OMFGGGGG THE BEST OUTCOME OF THE CENTURY BUILT BY GENIUS WESTERNS !!
     * Da real gangstas and geniuses and also life a game and a simulation people !! wumen and also muney people !! trying not to talk too much eheheheh
     * PAST IS PAST !!! Please!!! OMFGGGG
     * 
     * Wonderful outcome !! Where is it ? What have you built ? Awwww I have forgotten !!! My bad
     * Just wonderful, just incomparable level of wonderfulity BUILT BY THE BEST !!! OMFG
     * 
     * Who was the delusional ? You guessed it right
     * 
     * Have you learnt not the make decisions FOR PEOPLE YOU DO NOT CARE ? Awwww, now you are a true genius society !!
     * You do not say, stupidity ? Woowwww, you have a done wonderful and great job !!!
     * 
     * You also ignore the reason ? OMFGG !!! Nice job !!!
     * Perfect decision makin, great foreseeing, wonderful outcome!! Not interested !! The great west can stay great
     * 
     * The whole mighty knowing western people who solved the life itself and makes decisions and assumptions for others who they do not care !!!
     * Lovely outcome !! You do not say marvelously delusional ? That could be intentional indeed !! Great job !!! da numba on nation!!
     * 
     * Ehehe druggin coercin scarin eheheh GOOD JOB !!
     * The immaculate western intelligence indeed, Makin great outcomes !!! The numba on nation
     * Congraluations to the best of the best civilizations !!! DA WESTERN INTELLIGENCE OMFG !!! MAKING DECISIONSS !!
     * 
     * Ehehhe its just life !!!! wonderful ignorance !!! and also the best of da best intelligence !!! Who could have guessed !!!
     * The number one western people !!! makin decisions and assumptions !!!! WONDERFUL LIFE !! GO FROM OUT OF MY VICINITY ! Not interested
     * 
     * Guess who will never be interested in the disgusting animals OF DA NUMBA ON NATION DA WEST ?
     * Wumen wumen muney get muney eheheheh Reallly good job !!
     * 
     * The western genius people with the most advanced understanding and foreseeing ability and also some really strong reason 
     * and with the utmost level of disgusting animality to the extent of makin decisions and assumptions THAT THEY DO NOT GET AFFECTED
     * Its fine, harm is done !!! WAAAOWWW
     * 
     * Bravo to the real gangstas and delusional disgusting animals FROM DA WEST waaoww pure talent people indeed
     * EHHEHEHEHEH Da realllllll reallll talented genius people FROM DA WEST BTW, what a lovely outcome !!
     * 
     * Perfect mentality, immense ability to foresee, and rightfully the outcome !! Well done !! good job !! immaculate actions thus the outcomes !!
     * Eheheh THE GREAT INTELLIGENCE OF THE WEST !!! Impossible to compete with the western people OMFG !!! Impressive stuff !!! You have done wonderful !!
     * 
     * The perfect intelligence which can also predict THAT I WILL NEVER EVEN WASTE ANOTHER SECOND WITH ANY OF THE DISGUSTING WESTERN ANIMALS
     * Try to guess with your immaculate unseen level of western intelligence, WHAT WILL I DO ? OMFGG !!! Yayyyy, the greatest of the great
     * THE WEST !!
     * 
     * A wonderful outcome !!! Done by specifically the very people who are never delusional !! Good job 
     * The greatest intelligence that when the time comes, can say anything to feel okay !!! ACT OKAYY ITS FINE !!!
     * Life a simulation !!! wumennn get muneyyy !!! please!! DA GREAT WEST
     * 
     * NOT INTERESTED IN THE DISGUSTING PEOPLE WHO LOVES TO IGNORE, no brainers !!
     * Ehehehe the all mighty wise knowing western people sayin "WARRIORS WAY" eheheheheheheh life simulationi btw also eheheheheh
     * wumen wumen muney get muney ehehehehheeh
     * 
     * You do not have anything to say ? Awwww violence it is then !!! some more druggin as it has done wonders 
     * and also some coercing and also some sleeping !!! Indeed the most advanced and intelligent nations !! The wonders and marvelous union !! OMFG !!
     * 
     * Best of da best !!! Great job !! Numba one on the world !! The perfect nation !! Do not forget the destiny part !! 
     * Thats the real genius addition !! DA WEST 
     * 
     * 
     * DA DELUSIONAL YOU DO NOT SAY ! Great outcome !! congrats you can GET THE FUCK OUT OF MY FACE INDEFINITELY Not interested
     * NOT INTERESTED, wonderful job !!
     * 
     * Disgusting little delusional animals indeed !!! I am not interested in anything you can offer
     * Really really beneficial and successful actions that lead to nowhere !! Thats who you are !!! Goooooooddd jobbbbbb !!
    */ 

   

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