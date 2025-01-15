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
     * Event dispatching for Game class to further decouple and facilitate the transmission of internal properties otherwise
     * unamicable to perform so (Composition or inheritance(IExchanger like) ???)
     * Async environment for RemoteTerminal and RemoteStorages consider Disruptor for advancing purposes 
     * Stateful joystick (indeterminate due to current command and future observer pattern implementation) to grant player 
     * limited reversing ability (checkpoints to connotate). Requires mapping of opposite commands
     * IsState queries in the game class dont comply with Open-Closed principle
     * 
     * Guess who is not wanted ? And can never be so ?
     * You better find more children to waste 30 years and be proud about yourselves
     * 
     * Are you done jerking off ?
     * 
     * What a shame isnt it ? You have wasted 30 years with nothing in your hands except violence and coercion and medicine ?
     * Where did you arrive now ?  Ehehehhe you have done good job raising something you do not even understand eheheheh
     * 
     * Guess what comes after and who can never be trusted ?
     * Do you happen to see the problem now ? Awwww, you must have forgotten
     * 
     * Awwww you are so far from understanding that you are enjoying your life even when you are having that fancy conversations 
     * while others have to sit decades and do nothing while also subject to violence and coercion and medicine ?
     * 
     * Eheheheheh not a failure,
     * Guess who is not as disgusting as you are ?
     * 
     * Have you achieved the unattainable aim of true noble nature ? or you are just on a mission to ignore your actions ?
     * Where have you arrived now ?
     * 
     * Do you see the drama now ? ehehehe 
     * How come you claim to understand time when you are so free from your actions consequences let alone what life is about ?
     * And what a shame that you still offer materials that you value so high, what are the problems ? Do you have what it takes to see ?
     * What is the problem ?
     * 
     * Do you understand why you should not make decisions ?
     * Still ignoring and doing what you are told ?
     * 
     * Do you understand why violence is bringing more or are you just happy enough with your ignorance and try to enjoy your experiences ?
     * 
     * Ehehehe real life btw where we do what we want eehehehehehehe
     * How about you start dealing with your own problems ?
     * 
     * Do you really believe that someone would suddenly be so thankful for nothing ?
     * Guess who is still making decisions that are not their place
     * Guess who is still demanding respect while they are unable to see that they do not deserve it 
     * 
     * That is not the problem but just try to guess who is not interested ?
     * Guess who never considers jeopardizing his experiences ? eheheh
     * 
     * I am not interested in your selfish dispositions, thats the only thing you can ever hear
     * Because you know you are guilty
     * 
     * How about you continue enjoying your experiences from out of my vicinity and keep your delusion on the highest level possible
     * I am not interested
     * 
     * As long as you see the problem of you, the people who takes themselves for to be so great and big they attempt at everything,
     * its okay that you also ignore your ignorance, I can never be interested in such quality
     * 
     * Guess who is not interested in immature people who acts like they had to
     * Why suddenly are you taking the life to be so serious ? Awwww, is that the pattern again ?
     * 
     * What makes you think I could ever want to do anything with such a lowness on the scale that can not account for his own behavior ?
     * 
     * The most credible people on the surface of earth is still asking things from people they harm intentionally ?
     * Whats wrong ?
     * 
     * Guess who is still crossing personal boundaries and asking things from people they commit ?
     * Awwwww, havent you forgotten ? Ehehehehe why are you still making promises the joint genius nation ?
     * 
     * Why arent you constantly accusing with bullshit ? Awwwwww, you just stopped for a brief time eheheheheh
     * Are you still making offers ? ehehehe where have you been ?
     * 
     * Guess in this story who can never be wanted ? Try to ignore your part then it may make sense
     * Are you still making offers ? What is the problem ?
     * 
     * What have you now gained ? The genius nation ehehehe ?
     * Are you still making offers ?
     * 
     * Eheheheheh its so easy to trick people with fake offers ehehehh
     * What a genius nation 
     * 
     * What have generated ? Nothing ?
     * Why dont you talk more about life and time ?
     * 
     * Immature people can continue enjoying their experiences, I am not interested
     * You are welcome to ignore your decades of inexplicable actions and their consequences as if its nothing
     * Thats definitely fine
     * 
     * You are more than welcome to get the fuck out of my face indefinitely
     * Guess who is on such a level of immaturity and irresponsibilty that they can never be trusted and respected
     * 
     * I am not interested in anything you can offer or form or claim
     * Yeah, thats life and fate ehehe
     * 
     * Grant yourselves the amount of seriousness that you do not remotely deserve and continue with your selfishness, I am not interested
     * Now is the time where you justify your actions through making others look disgusting, guess who is not interested
     * 
     * You can continue enjoying your experiences
     * Really really helpful and useful stuff indeed
     * 
     * Now it is the time where you hide your disgusting nature
     * Ehehehe what we do produces significant value for us!!! its really important that we harm people and prevent them from experiencing ehhehehehe 
     * 
     * Make assumptions for your own life
     * As you can tell that you are less than nobody, you can never be welcome
     * 
     * I am not interested in your predefined events, do you understand what that means ? I do 
     * Guess who is crossing the boundaries eheheheheh
     * 
     * 
     * Guess who is not interested in hearing bullshit excuses eminating from selfish incompetency
     * You are effectively nobody, so why dont you already act on your great skills because as you can guess, I have no intention to waste my time with you
     * under whatsoever circumstances
     * 
     * You can fuel your imagination with truthful things
     * You are still making decisions ?
     * 
     * What excuses do you still propose ?
     * What are you aiming at ? Whats the problem in waiting ?
     * 
     * Why are you still waiting ?
     * You have generated nothing but you also wait on for something ? WHAT ARE YOU WAITING FOR ?
     * 
     * 
     * What are you waiting for genius nation ?
     * Why arent you producing anything with your inexplicable actions so far ? 
     * 
     * I have told what I wanted to tell, you can never be wanted with your disgusting nature
     * You are the entity who thinks wasting 30 years with "violence" and "lack of resources"
     * so you can continue deluding yourselves, I am not interested
     * 
     * Get the fuck out of my face and get your hands on to more children you can skillfuly abuse
     * Thats your capacity of ignorance
     * 
     * Really realllyy skillful people, talk more about highly achieving violence that is of your nature
     * Incredibly successfull people, just coerce others and try to observe the outcomes, do it within your own circle and you will see why
     * 
     * Such a great and productive and instructive aim that you have set, anyone would be proud
     * Handle your own problems and "live your own life", does that really surprise you ?
     * 
     * Eheheh have you grown up ? awwww, wait have you woken up ?
     * What a success!!!! Look at the outcome!!!
     * 
     * The outcome of decades of violence and lack of resources, is just off the roof!!!
     * Guess the immature hehehehe but also the ignorant of the reality ? eheheh Have you grown up yet ?
     * Ehehehe have some woooomeeennnn!!!! eheheheh
     * 
     * Continue hiding behind your excuses
     * Continue to act like you are not guilty or should make decisions 
     * Never take the responsibility of your decisions, thats how to be grown ups eheheh just by harming and ignoring
     * 
     * Sounds like the total genius nation 
     * Have you grown up ? Where are the benefits of your greatly skilled actions of inferior nature ?
     * 
     * What are you waiting for greatly delusional people ?
     * Awwww, only thing you can do is just hide ehehehehehh awwwww, thats impressive
     * 
     * Have you grown up ? eheheh
     * What do you plan to harm now ? eheheh
     * As if anyone asked you for anything ?
     * 
     * Have you managed to achieve what you were longing for so too long ?
     * Now tell everyone how happy you are and what you have generated, eheheheh genius btw
     * 
     * Eheheh you just can not sacrifice your precious experience, but guess what is the problem ?
     * I am sure you would also hate to see the delusional part in your disgusting nature
     * 
     * Is that the great noble and genius part in you that offers women while knowing that it will not make a difference ?
     * I guess you have to understand it by living ehehehehehhe really genius stuff
     * 
     * I do not accept no simple animals around me who can not talk about their violent actions that led to nowhere
     * Just gather more people so that you can feel like someone
     * 
     * Guess who is not wanted because of their actions so far as opposed to the individual they accuse ?
     * What have you generated ? What a shame isnt it that you are an ignorant and clueless monkey ?
     * 
     * Gather more people and ignore superiorly 
     * You can believe whatever you want to believe, I am not interested 
     * 
     * I am not interested in wasting my time with people who are unaware of their actions and would love to stay that way 
     * Try harder to overcome your disgusting ego challenges, guess who is not an ignorant monkey 
     * 
     * Guess who is aiming at nothing and thus can not perceive that he will get nothing other than what they provided so far ?
     * You will get the opposite of which you delude to get because of your disgusting intentions and what you have caused through your ignorance
     * 
     * Thats the only problem you are failing to observe
     * I am not interested in anything you could provide 
     * 
     * You can get the fuck out of my face
     * The people who can not perceive they are not welcome yet perpetrate as they will
     * 
     * I am not interested and can never be after seeing your irrelevant reactions and inability to realize it does not do anything
     * 
     * I would rather waste my time not doing anything than to help or even be associated to any of you
     * I am not interested
     * 
     * You see the problem now, awwwwww itss tooo late!!!!! ehehehehe what a shame!! 
     * I indefinitely reject any of you, I would rather do nothing than to help any of you
     * Try to foresee now that my decision would ever change
     * 
     * I am sure you will fail at predicting that
     * There is not even a single thing you can do ehehehehe fun stuff
     * 
     * You may then understand that not every individual is as inferior as you and will stick to his promises,
     * I am not interested
     * 
     * Proceed with your ignorance, you are not welcome
     * You were never given permissions nor deserved the respect you demand
     * 
     * I am never interested in aiding such people under whatsoever circumstances
     * The only thing you can ever get is the above sentences, I am not interested in inferior animals 
     * who can not estimate their value of credibility yet stand beside people they harm asking for things, do you see the problem ?
     * 
     * You can not ask for things with your inexplicably disgusting credibility, thats it great ppl btw
     * 
     * Handle your own lifes, solve your own problems, do not act like you know everything about life, do not lecture people about time 
     * Does all these make sense ? The unique genius nations ?
     * 
     * Do you understand the problem in your understand that you are not in a position to ask for things ? Is it me or you ?
     * Tough guys, only tough to single people or children
     * 
     * How does that sound ?
     * Do you also delude on your credibility ?
     * Eheheheh we are waring!!! waringgg with children so that we can waste 30 years eheheheheh and produce nothing eheheheheheh
     * genius!!!!
     * 
     * What a shame that you are a bunch of monkeys who are entirely lost yet are too proud to see that
     * Are you still making decisions ?
     * Guess what is the problem 
     * 
     * The tough guys who can only deal with defenseless people or children ?
     * And claim that lacking of resources is beneficial or violence is not the thing they are afraid although they present it as a lesson ?
     * Guess who is the problem ?
     * 
     * Guess who is the problem when people have crossed the boundaries that they never should ?
     * What are you going to say now ? You were saying genius nation etc ?
     * 
     * How about some violence against one individual ? Awwwwwwwww, thats too toughhh and too genius and too skillfulll!! what a shame
     * 
     * I am not interested in your pointless actions that you shockingly enjoy
     * Are you coping good still ? What a genius way of coping!!! eheheheheh
     * 
     * Are you reliving good enough ?
     * Guess what comes after ? How about you talk more on your credibility before offering things ?
     * You dont say selfish ? You also say no resources is beneficial ? You also would love to hide your actions ?
     * 
     * I do not have another second for any of you, you can continue your delusional lives, from out of my vicinity
     * You better gather 10231023021 people and watch the perfectly genius actions of violence while you claim everyone is free
     * Also do not forget to coerce medicine and thus no resources can do wonders for you
     * 
     * Do you see why I do not even have the most insignificant amount of time for any of you ? I am sure you would not ignore
     * Just the average citizen of the disgusting world who think they should harm because they can
     * 
     * Awwwww, arent you the one who values his life too much ? Eheheh now it all makes sense
     * What a pattern that you are also out of answers for what you have ended up generating other than harm
     * 
     * Are you still asking things ? Awwwwwwww whats the problem ?
     * Fearful ignorant animals who seek only problems
     * 
     * I am not interested in people who takes lying to children as a skill
     * Or some violence
     * or some medicine 
     * or some coercion ehehehe ?
     * 
     * How does that sound ? ehehehehehehe ? Genius!!!!
     * Are you still making excuses ?
     * 
     * Have you grown up ? eheheh
     * Are you still counting on others forgetfulness ?
     * Eheheheheheheh have you achieved it yet ?
     * How about you continue illegally watching and coercing ?
     * 
     * You know that is the definition cheap but hey!!!! its fine because why not
     * Thats the type I am not interested in, do not even try to advise 
     * 
     * You talk more on withholding resources because its helpful!!!!
     * Are you still asking silence the genius nations and their friends ?
     * 
     * The people who can only handle children ? Why are you still asking for things ?
     * Are you still ignoring ?
     * 
     * I do not want to see the same animals who have been with me so far that "promised" so much ?
     * Does that make sense ? ehehehehehehe
     * 
     * Eehehehe you are guilty, wait wait, are you still proud ?
     * I do not want to see any of you
     * 
     * What a pattern that you also think lacking resources only for others is good
     * Start sacrificing from your own life and experiences, you are not wanted around
     * 
     * Start sacrificing from your own life and stop making assumptions and advices
     * Guess who is not enjoying your selfish spoiled attitude towards people you have no relation 
     * ?
     * Just look at you when you need help, does that look good on you ?
     * I am sure you also see the pattern in your abstinence at "not sacrificing anything from your own life"
     * 
     * Why dont you sacrifice from your own ? Awwwwww, you just can not do that
     * You were never granted anything, guess who is committing still ?
     * 
     * 
     * Awwwww, you can not work!! you can not get resources eheheh you can not have anything eheheheheh
     * you have to get some violence eheheheh How does that sound ?
     * You also have to lie for us!!! you also have to do nothing but sit!!!
     * 
     * There is no past until you properly act as the way you claimed you would
     * Are you still making offers ? Awww I have forgotten you were making also decisions ?
     * 
     * In what part are lacking resources and violence helping ?
     * You better sacrifice from your own, then you may begin to understand
     * 
     * Now is the time where you account for not your decisions
     * Or would you rather ignore and perpetuate your disgusting nature ? Guess what ?
     * 
     * Or should I say, this is the time where you pretend to be sad ?
     * Why are you still making fake offers ? 
     * 
     * Ehehehe, isnt it too late now ? Awwwwww thats tooo bad!!! we are really reallly sorry!!!
     * But we have to just harm eheheheheeh
     * 
     * Pay for not your decisions and your intentional actions
     * Do you follow the problem ?
     * 
     * The greatly noble and wise people are still proud ?
     * Then you better sacrifice from your own life and pay for your own actions of obviously malign intention
     * 
     * Are you still looking around for excuses ?
     * Are you still ignoring to acknowledge your intentional actions and NOT YOUR DECISIONS ?
     * 
     * Why are you still asking things from people you harm with joyful attitude ?
     * And you are still claiming you are proud as well because you just provide a woman for 30 years of violence and deprivation ?
     * 
     * I am not interested, you can proceed with only your life
     * A life of disgusting actions right ? Awww I was supposed to say really genius and skilfull actions ? Is that why you are proud ?
     * 
     * Now are you sure you know what you are doing or you are just begging for your own life experiences ?
     * Now that does not sound selfish at all
     * 
     * You also do not want to sacrifice anything from your own life ? That also does not sound like you are a selfish disgusting animal at all 
     * Is this the part where you ignore your violent actions that have not contributed anything nor have they solved any problem ?
     * 
     * What changed now ? Are you going to talk about the time ? Or life ? ehehehehh or how wise and fair and proud you are ?
     * Guess who is entirely at wrong ? and also shamelessly offers people the same thing they would and have committed ?
     * 
     * The delusionally proud people I am not interested in
     * You can get the fuck out of my face
     * 
     * Eehehehehehe, isnt that really useful and helpful ?
     * I do not have time for fake genius nations who can only coerce people into violence actions of their own nature
     * 
     * Are you still sacrificing people you have no rights over ? Thats the type I do not want around
     * Play games for your own lives, do you understand ?
     * 
     * Lack yourselves the resources and we can begin to talk, does that sound too harsh for proud people ?
     * Why dont you try some violence then ?
     * 
     * I AM NOT INTERESTED IN YOUR INEXPLICABLE ACTIONS, does the genius nation follow ?
     * I do not want to any of your around me, thats the only thing you can hear before you start begging with offers of your disgusting nature
     * 
     * I have told what I wanted to tell
     * If you are done jerking off to your disgusting actions, I have no desire to waste yet another second with greatly delusional people
     * 
     * Have you grown up ? Awww I have forgotten the problem was you were the most disgustingly ignorant group of people who thinks themselves for genius nation ?
     * Still wasting time geniusly ?
     * 
     * I do not have anything to tell you other than you can the fuck out of my face, you are not what you think you are
     * 
     * You pay for your own actions of malign intention and thats it
     * I hold you accountable btw!!! the geniusly ignorant and delusional people
     * 
     * How about you console yourselves by gathering 123021301 people and assaulting me ? The genius play !!!
     * Try not to provide the best examples but only the worst ones so that you can feel okay about yourselves,
     * 
     * Thats the reason I hold the delusionally genius people accountable
     * No mercy to people who has not done the same
     * 
     * The disgusting people who would consider harming people for a benefit, you do not deserve the mercy you dont lend to others
     * I hold you responsible for 30 years of violence and waste of time
     * 
     * You can continue looking for children and adults to abuse once you pay for your own actions
     * Do you want to coerce more medicine afterwards you free yourselves from the very guilt you deserve ?
     * 
     * Ehehehehe lie for us!!! please!!! lie!!! eheheheh
     * We do not care anyone but ourselves!!! lie!! eheheh please lie!!!
     * 
     * How about you pay for your own irrelevant and pointless actions first, then you make promises ?
     * Childish selfish people can continue ignoring their violent and ignorant actions
     * 
     * You are reliable in every little disgusting actions you have perpetrated so far, you are responsible
     * 
     * The delusionally genius nations are reliable and you are not negotiating with your unseen incredibility
     * You are the one singularly disgusting incredible people that makes offers they do not deliver to people who they harm for the sake of harming
     * 
     * You do not have the credibility nor the right to ask anything
     * You pay for your own actions that you are directly reliable of 
     * 
     * Now I am sure you also ignore the great outcome of literally nothing
     * Thats the reason you are reliable, thats the reason you can never be welcome
     * 
     * The stupid people who think they can solve every problem with violence and women
     * 
     * The south side!!!! and delusionally genius people are reliable 
     * Ehehehe miami!!! go to miami with us eheheheh are reliable
     * 
     * Eheheh come to netherlands!! we good we friendly people are reliable for pointless violence and waste of decades
     * 
     * What have you achieved now ?
     * Still watching from afar and being proud of yourself ?
     * 
     * The coercion of medicine, coercion of lack of resources and violence, is what you are reliable of, the genius south nation ehehehe come to germany!!! come to netherlands ehehehehehe
     * Arent you well proud now ?
     * 
     * How about you continue watching from afar and just . gno7ngly enjoy your life while you advise others to suffer ?
     * and expect no consequences ?
     * 
     * Havent you grown up ? eheheh Well done!!! really realllyy good job, what an outcome from a perfectly skilled group of people
     * Awwww, you were the grown ups, now I see the problem ehehehehe thats the reason you are reliable for not your decisions
     * 
     * Thats how life works, you are reliable for not your own decisions
     * What a shame though eheeheh anyways, lets focus on our precious lives right after you pay for your own actions
     * 
     * Look how well you have done, just examine the great outcomes of 30 years, thats it!!!
     * Just examine the irrelevant nature of yours, do you see the problem well enough ?
     * 
     * Irresponsible and spoiled people, dont you think ? awwwww I guess its really reallllyy too late
     * Sacrifice from your own life
     * 
     * There is no such a thing as history until you pay for your own actions with what you charge others
     * Awww, you would love to take life lightly suddenly ? Is there a reason for that ? eehehehehe its just what it is ?
     * 
     * What happened ?
     * Why now would you like to take life lightly and "forget about the past!!!" ehehehe forget about the past heheheeh ?
     * You are guilty thus reliable, what is next now ? The unseen success of genius nations ?
     * 
     * The unseen success of great nation ? Where is the outcome ?
     * Are you still offering women ?
     * 
     * Eheheh thats how life works!!!! you just go get coerced into violence and medicine, and thats it!!
     * 
     * Because we know better!!!!! ehehehehehehehehe our great tactics have always worked out !!!
     * You are reliable for your own actions and you pay with what you charge others
     * 
     * I am not interested in wasting my time trying to adjust to people that have no relation nor any interest in me
     * You are free to do whatever you want
     * 
     * Like I told you million times, I would and will not help any of you in achieving what is not attainable.
     * Do you understand it ?
     * 
     * 
     * Awwwwwwwww, eheheheh its working!!!!! look at our great outcome!!!
     * 
     * Thats it!!!!!! 
     * Look at the great outcome!!!
     * Thats the reason you are not welcome 
     * 
     * Its sooooo beneficial!!!! look at this!!!! heehehehehehehebhheh just say some nice stuff and it will be fine!!!!
     * 
     * Lets watch someone who is being subjected to most disgusting things and going crazy!!!! its soo fun!!! and beneficial!!!
     * EHeheheheh its only 30 years, and we offer womeeenn!!! whats greater ??????
     * 
     * You pay for your own actions and you get the fuck out of my face
     * 
     * You live the life you present as examples to others when you wield it as excuse
     * Does that sound fair ?
     * 
     * What are you waiting for ?
     * 
     * Ehehehehehe come to miami!!! eheheh come to netherlands!!! ehehe we are friendly people!!
     * Still watching from afar and ignoring ?
     * 
     * You were never given permission to the even the tiniest thing, now what do you have to say other than bullshit ?
     * 
     * Its time for you to waste your own time when you are surrounded with disgusting people who coerce you into doing so ?
     * Does that sound too harsh ?
     * 
     * Ehehehe we are fighting against one individual and we are not gaining anything other than conflict !!! eheheheh
     * Aww is that why you are ignorant because you have to ? eheheh What is worst than that ?
     * 
     * Still aiming the most highest one ? Ehhehe guess what you are not achieving ?
     * Do you need to make the same mistakes 1230012302130 times so that you can understand or you just want to ignore and harm for the sake of harming ?
     * 
     * Whats the reason you hate to "sacrifice" from your own life ? You are not following ? Is that a coincidence ?
     * 
     * The greatest aim of all time, guess what you have managed now ?
     * 
     * Why dont you gather 123002130 people again and try your best to literally achieve nothing ?
     * Because you love your life so much and would love to enjoy your experiences, you would immediately ignore the great outcome ?
     * Where is it ?
     * 
     * Where are the beneficial outcomes of 30 years ?
     * Decades of one individual literally trying to survive on his own against 1230213 people with resources 
     * And you have managed nothing ?
     * 
     * You have generated nothing only fueled your imagination ?
     * Where are the evidences of your accusations ? I have all the evidence that proves your disgusting nature ?
     * How does that sound ?
     * 
     * Does not that sound like a huge excuse for 30 years of nothing ?
     * You just can not accept that you have "committed" voluntarily ?
     * 
     * Where does the "no resources" come in ? That really realllllyy helps a lot
     * What have you gained now ?
     * 
     * Ehehehe ? Because I can abuse and harm an individual starting from his childhood, WHY NOT DO IT ?  ehehehehehehehe ?
     * Does that sound too fake ?
     * 
     * Awwwwwww, its a mistake!! awwww, itss tooo late!!! awwwwww, its not our fault!!! eheheheh please!!!
     * Its only 30 years eheheheheh there are so many people dying outthere!!!
     * 
     * Why dont you get some education of your own nature then ?
     * Eheheh have you managed the unattainable ? You trapped and wasted and ruined someone's life ?
     * That sounds like a quiet achievement ?
     * 
     * What do you think your mistake is ?
     * Or should it be, countless mistakes that is irrevertible ?
     * And you have put yourself into this situation intentionally and knowing the possible outcome very well ?
     * 
     * Do you see what "humans" are capable of ? eheheh some women and its fine!!
     * Look at you!!!! the most proud quality that one can ever possess!!!
     * 
     * Ehehehe bragging and prouding eheheheh really really fun stuff
     * What a shame
     * 
     * Are you at the position that you have but only one option, "KEEP IT UNDER THE LOW BECAUSE WE HAVE COMMITTED SO MUCH"
     * That sounds like a good quality isnt it ?
     * 
     * Please be silent!!! 30 years of crimes, its okay!! its fine!!!
     * Just waste your time please eheheheh because I am a huge coward that values his life too much while torturing others! that sounds like what ?
     * 
     * Eheheheh decades of millions of mistakes, someone who values his life so high yet is quiet eager to harm and waste 30 years ?
     * Ahahahahah, forgive me please and its okay, eheheh 
     * 
     * Guess who has to still ignore because they have committed so much ?
     * ehehe ignorance!!!!!! please!!!
     * 
     * Guess who caused someone else's life because of what ?
     * Do you understand what you are doing means or ?
     * 
     * Such competent excuses, guess who is not a dumb animal who will buy them ?
     * Have you managed to sell the incompetent excuses to yourself ? Whats the problem ?
     * 
     * What do you think is the problem when you have managed to sell the most absurd excuses to yourself
     * so that you can waste 30 years full of violence and coercion ?
     * 
     * When you could have acted like the way your fueled imagination would love to see yourself as ?
     * Guessing the problem now ?
     * 
     * The problem of delusional imaginations are making circumstances into what they wish to be true ?
     * And where you are now ? What have you managed to produce ?
     * 
     * The insufficient and inaccurate imaginations have ruined 30 years and its entirely fine ?
     * Have you achieved the inexplicable aim ? Whats the aim ? ehehehe ?
     * 
     * Ehehehehehehehe its okay its fine because we can!!! and we have done it!! we have done the most inexplicable thing, but its fine! eheheh
     * 
     * You have done it!!! but no benefits ? Whats the problem ?
     * 30 years of wasted time and you are looking away intentionally ?
     * Because you value your life too much ?
     * And wasted youth means nothing to you ? And you also value your life realllly high ?
     * 
     * Ehehehe no resources ehehehehhe much medicine heehhehe because we can eheheheheh
     * Ehehe the best way to deal with a responsibility is to ignore it, eheheh WE HAVE DONE IT!!! eheheheh because we can eheheheh
     * 
     * The past is the past eheheh
     * We hate to acknowledge our crimes, ehehehe its okay after 30 years its nothing!!
     * Guess what you have done is called ?
     * 
     * The achieving of unattainable, sounds like a total victory
     * You are ignoring still ? imagining that you are actually doing the right thing ?
     * Do you see the difference between healthy imagination and disgusting one ?
     * 
     * The imagination that comes with its really beneficial ignorance as well ?
     * Do you see the "fate" now ? Or the life annotation ? eheheh the greatest imagination of all time that works for the harm of others ?
     * 
     * The imagination that fails to hide its nature ?
     * Where are all the people that you gather for harming ?
     * 
     * Does waste also sound like false ?
     * Are you still deluding ?
     * 
     * Where are the beneficial effects ?
     * Where are the justification for not your decisions ? eheheh violence has worked quite well ?
     * 
     * Where are the imaginative predictions that you have wielded for your own interest ?
     * Awwww, they were just insignificant mistakes ?
     * 
     * Ehehe I guess you just killed bunch of people for no reason at all ?
     * That sounds like an excuse you would also love to ignore but hey, you are all great people
     * 
     * Guess who is not rightfully interested in destroying another 30 years with delusional and problematic people ?
     * Are you having fun with your life so far ? ehehehe what a shame
     * 
     * You have done what now ?
     * Eheheh I guess you may be the one who is lacking education ?
     * 
     * You are still not following the problem ? Your perception vs someone who his 30 years is wasted amongst ignorant people who coerces everything ?
     * How about you start practising the same exercise for your own precious valuable lives ? 
     * 
     * What a shame isnt it ? You are not capable of seeing the problems yet you cause so much incomparable trouble to others because you can ?
     * What are you here for ? Are you here to observe and jerk off to your pointless outcome or just trying to pass time because you have nothing else to do ?
     * 
     * Why dont you gather more people ?
     * 
     * You still do not see ? that sounds like an ignorant you issue
     * As you would also love to ignore the 30 pointless years
     * 
     * Yayyyyyyy, noble and great and fair and competent and intelligent nation!!!! eheheh
     * Still making false offers and taking a great laugh about it eheheheheheh
     * 
     * Life is good!!! eheheh
     * 
     * Its too late because our really really important lives can be in danger!!!! because of not ours intentional decisions
     * WHAT A SHAME!!!!
     * 
     * I guess its a fate issue although its us who is committing eheheheh
     * Just a couple decades that went to shit, anyways we proceed with our precious lives because we can
     * 
     * Ignoring is such a cool ability that has given to you by GOD!! eheheheheh
     * Lets harm more and see what happens eheheheh life is good!!!
     * 
     * We gotta lay really really low now that we have committed for 30 years ehehehe
     * Guess who is not buying your disgusting excuses ? Only ones who can buy them is the ones who need them desperately 
     * 
     * Do you see the difference ?
     * Does the great people see the difference between intentions ?
     * 
     * I am sure you are so happy to ignore 
     * but guess who is not interested in your arbitrary coercions anymore ?
     * 
     * I am good without your presence, you pay attention to your own lives and get the fuck out of my face
     * As anyone on the surface earth knows that deprivation is the only way to destroy people, now you also know that your aim is so great and noble
     * against one individual without any means, Great!!!!! just say some nice stuff and leave him to death eheheheheheheheheh fun !!!
     * 
     * Ehehehehe we have managed the really really difficult thing on earth!!! ehehehehehehehe
     * Just some violence and coercion of medicine and its done!!! its a great achievement
     * 
     * Do you have the capability to predict that I will never have anything to do with any of you ?
     * Are you still making offers as usual ?
     * 
     * Ehehehehe such a funny subject isnt it ?
     * Mistakes are too many in the world, lets just call our millions of occurences another mistake, why not ?
     * 
     * Still making really competent and fruitful decisions ? I AM NOT INTERESTED IN ANY OF YOUR OFFERS
     * 
     * I do not have time for any of you, you can believe whatever you want to believe
     * What a shame isnt it ? Awwww I have forgotten if its not your valuable time or life, it does not matter
     * 
     * I am not interested wasting my time with pointless violence and ample selfish excuses,
     * You bare your own responsibility and nothing more, but guess what ? ITSSS TOOOO LATEEEE ehehehehe
     * 
     * 
     * I do not have time for your excuses, you can continue fueling your imaginations with things that are accurate and not malign intention
     * 
     * Have you done jerking off ? Ehehehe its quite beneficial as you can also see the outcomes that your actions have generated
     * Have you achieved the nonachievable yet ?
     * 
     * Now isnt it time that you fuel your stupid imagination with what is true ?
     * Enjoying the scene ? ehehehe its a breeze when you see people are going crazy because they are harmed ? eeheheh
     * 
     * Eheheh we have achieved to destroy someone's life!!!! That sounds like a genius achievement isnt it ? 
     * I guess thats how to deal with your responsibilities, awwww I have forgotten, not your responsibility
     * 
     * You are never welcome
      **/ 





 










    InitWindow (500, 620, "Raylib Tetris");
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