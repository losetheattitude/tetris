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
     * 
     * I do not want to see people like you around me, its just that and also your disgusting delusions
     * that are causing you to believe into stupid approaches
     * 
     * You know how to listen ? ehehe The greatest achievement of all!!! eheheh need more children ?
     * You all are just nobody to me, so why waste more time ? I do not accept any of you around
     * Simple afraid animals, do what you have to do
     * The never learning animals who do not know how to listen, make sure I would be willing to waste another second with you
     * You are officially nobody and there is nothing you could do to change that
     * Do delude on your inexplicable behaviors being acceptable and people would die to be around you and your disgusting actions
     * 
     * Find more stupid people as you who will consider coercing medicine and lacking of every single resource as a precaution. fucking disgusting monkeys
     * delusional monkeys, guess what ? eheheh do what you have to do with your delusions, I am not interested in your disgusting behavior you can not account
     * still offering the most disgusting lifestyle and jerking off to your competency ? Get the fuck out of my face 
     * 
     * Literally do what you have to and get the fuck out of my face, dumb animals
     * You have nothing in your hands ? still looking around waiting for help ?
     * You feel like you have achieved something ? eheheh thats the problem
     * The problem of you being a stupid directionless stubborn disgusting animal, and whether you think you own the world, I do not want any of that around me
     * Are you so delusional to the extent that I will ever consider wasting my time with such a group that has caused so much ? eheheh its fun!!!
     * 
     * You see when you "decide" whats not within your boundaries, you always get this result, which is I do not want to see any simple animal around me, DO WHAT YOU HAVE TO DO
     * still jerking off to your inferiority ?
     * Do you think you are mature enough to make "that decision" or are you just trying to show off ? Guess what ?
     * 
     * WHAT DO YOU HAVE IN YOUR HANDS NOW ? Are you still begging ?
     * Thats a great skill, now you can get the fuck out of my face with your really good offers as "WOMEENNNNN!!!"
     * 
     * Do you even know how to listen ? Still wondering whether this is a mistake or not ?
     * ehehehe turning back is no option!!!! ehehehehhe we like guising our disgusting feelings and project them onto others with
     * inexplicable excuses, eheheh dragging people into "games" ehehehh
     * 
     * eheheheh dragging people ehehehehh fo!! eheheh being foes!!! ehehehhe dragging children eheheheh calm down!! its only 30 years heheheh please!!
     * we like making decisions that are not our place and look around for responsible people!! ehehhe fo!!!
     * 
     * Awwww what do we do now ?? Still deluding on your actions being okay because you will "grant" people to do things ?
     * Arent you the simple disgusting animals ? Do you still delude on my relief on the "freedom" ?
     * 
     * Do you understand what is being told to you ? or you are just a simple disgusting animal ?
     * I am not interested in anything you could possibly form hence your credibility
     * 
     * Hence the disgusting animals that arrived no where 
     * Heyyyyy ?? hehehehhehehe whats wrong ?
     * Hey ? why arent you talking sense ? eheheh you thought it should be fine ?
     * You avoid to explain what you have enjoyingly committed ? 
     * 
     * I am telling you, you have no credibility to negotiate with, thats all for me
     * Eheehheheheheh 30 years and now you can have some things, BE GRATEFULLL!!!!! eheheh its that easy, hopefully everything goes really well
     * 
     * I want no simple disgusting animals around me, the insecure disgusting animals who take being the cheapest form of human for a skill
     * ehehe instead of baring some responsibility, why not continue enjoying our lives!!!! act like no such thing happened
     * 
     * Are you paying for your own actions or will you be the disgusting irresponsible animal ?
     * Still cheaping ? how about you beg for more lies 
     * no no!! how about you gather 110231231 people and try to prove everyone what a competent group you are ???
     * Still delude on your actions being "entirely normal" ? Thats the problem, its a indiscussable thats why its a loop
     * You know see, why you are a disgusting simple animal who likes to beg with many guises
     * 
     * Do you see now why you are a disgusting animal ? Who can not even explain where it has arrived
     * The fact that you delude on your actions being okay while the reality is completely opposite of that, the disgusting animals hence
     * 
     * I guess the disgusting animals should try their chances with more children, thats what you can handle
     * seek for more children inferior disgusting animals, offer children material as your disgusting nature allows such a "behavior"
     * 
     * Are you still offering things ? You have arrived to nowhere by wasting 30 years of what you do not own and taking that for a skill ?
     * Yet you still claim you are not a disgusting little animal ? How about you seek for more children ? and stay on your own disgusting inferior level ?
     * 
     * I do not accept no animals like you around me whatever disgusting excuse you think you have, I DO NOT CARE
     * still the same animals without a proper explanation, delude that I would love to be around you
     * 
     * Get more children to be proud about, waste a few decades and pray that everything goes really well
     * From out of my vicinity, I do not care about your titles or your delusions of whatever nature
     * 
     * The great people with great titles who chases children, make sure I would even consider a second to see you for what you are not, thats called delusion
     * Just the inferior disgusting animal that is rife everywhere!!! Thats all, I do not want to waste my time with any of you
     * 
     * Just like the animal you are who deludes to avoid his responsibilities
     * Go for more children, you do not need no explanation because you are the very disgusting animal who is rife
     * 
     * The immature disgusting animals who takes regular actions to be a gift to others, you see why you are delusional ?
     * Still the same disgusting animals who can not see that THEY HAVE ARRIVED TO NOWHERE yet what a pride they have
     * 
     * Still the disgusting same animals who provides the worst examples to cover their disgusting nature
     * Who can not see that they have arrived to nowhere yet WHAT A PRIDE! ehehehehehehhe
     * 
     * The disgusting animals who still think that I would even consider to waste my time with such abominations
     * The disgusting animals who still talk about afterlife and offer materials still
     * 
     * Who can not explain anything that they have perpetrated so far, only the avoidance that merely works with its own kind
     * Who takes his actions to be funny when the reality is the quite opposite of that, what a miserable animal right ?
     * Who still offers what their inferior nature craves for, when the time they have wasted is incomparable to basic materials yet eheheh fun stuff
     * Who still hides behind his disgusting guise instead of accounting for his own behavior just like the "responsible" humanbeing that they delude to be
     * 
     * Who takes life for a game when its not his own, very good
     * Who takes everything to be a okay when its not his own, I do not want any of that around me
     * You only understand when its your time to waste your years, then it will occur you what a disgusting animal you are
     * 
     * Its your time to waste your years without resources then we talk about the rest
     * Then we talk about my experience which you have intentionally ruined, guess what ? are you still offering women ?
     * Why is it that you take others to be on the same disgusting level as you ?
     * That is the type I DO NOT ACCEPT AROUND ME, whoever you think you are, its regardless, I will pass on all of you
     * 
     * Those you do not recognize their boundaries and bend against any crime they have committed, thats the real talented people right there
     * The disgusting animals who do not realize what they are doing has not been working, guess what ?
     * Who still waste time to enjoy their precious experiences while advicing otherwise, and expecting others to understand their really enjoyable experiences
     * 
     * Arriving to nowhere yet being intentionally unaware of it, what a good combination
     * You do not know how to listen ? and you also like abusing ?
     * 
     * Do you still think you are fooling or do you realize what you got into ?
     * Like the inferior animal who knows only to hope for the best ? How about you get more children and jerk off to your own experiences ?
     * Still after offering the most normal things after years of stupid conduct of your own nature ? Get more children and start yapping about fate
     * 
     * I do not accept anything that comes from any of you, make everything harder see who is losing
     * I have no intention to waste my entire life with selfish people like you, I do not care whether you delude you provide something valuable 
     * 
     * You are providing nothing, and still asking for incomparable things from people you have only selfish interests over
     * Thats why
     * 
     * The reason is, you are not providing anything useful and valuable whilst asking for everything, I do not want to see that type of blind animals around me
     * I do not respect your ways, and thats just it
     * Your credibility is worthless hence your disappearance from out of my vicinity
     * 
     * The delusion of achieving the unachievable, thats what I do not want to see around
     * The delusion of "offering" normal things because you think the wrong thing that I am fucking craving the disgusting animals like you
     * 
     * I am not interested in your disgusting excuses you beg children for
     * The delusion of my untenable "desire" for your own delusions, thats what I do not want to see around myself
     * The pointless disgusting animals who think whatever they do must be okay
     * 
     * I do not accept any of you around me
     * The supposedly deserved disgusting lifestyle that facilitates nothing, thats why
     * That arrives to nowhere but still exerted as though its an obligation
     * 
     * The disgusting people who thinks 30 years is okay to waste away especially by their own actions that they have taken and begged to children
     * Thats why THERE IS NO WAY ON EARTH TO CHANGE AN OPINION THAT IS BACKED WITH "EVIDENCE", you can remove your disgusting intentions from out of my vicinity
     * 
     * The disgusting animals who still offer material while advicing others to ruin their entire life and see no problem at that. Waaaaoooowww what a skill
     * 
     * You can remove your existence from around my vicinity, I am not interested in anything you could possibly offer, as you have done so many times
     * Be proud about your nonexistent achievements
     * 
     * Like I said, there is nothing on earth that you crave therefore offer others that has the potential to change your disgusting image
     * You solve your own problems on your own, not by begging to children
     * 
     * You decide for your own lifes and stay out of mine
     * Still making offers ?
     * 
     * I do not want to see disgusting animals around me ? Do you understand ?
     * Especially the ones who delude on others desire for "women", do you even follow ?
     * 
     * Especially the ones who I would not even consider around me for a second regardless of their intentions
     * The tough acting disgusting inferiors who can only deal with children, you call yourselves what ? eheheheh intelligent!!!!
     * 
     * I do not accept those disgusting people who delude on others' desires
     * The same disgusting group who begs for lies from the people they are not even slightly alike
     * The inferior animals who can not answer for their past actions and still beg with all sorts of excuses of their nature
     * then suddenly reduce to begging for lies
     * 
     * The still inferiors who begs for others' destruction and guise it with their disgusting natured excuses ?
     * How about you answer some questions first ? What has my experience been like ? Are you still alleging ?
     * 
     * Are you still deluding on your righteousness to make a decis ion that was and is not your place ? and looking around for help ?
     * And all you can do is offer women ? Just like the inferior selfish disgusting animal you are ?
     * 
     * What are you looking for ? Some irrelevant incompetent excuses of your own nature ?
     * Why arent you excuses working against impartial people ? because you are a disgusting animal ?
     * Who still offers material and enjoy their precious experiences while advicing others the worse ?
     * Still offering women ? the inferior monkeys ?
     * 
     * Awwwwwwww, itss tooo late!!!!! eheheheh you need more children ?
     * Awwwwww wait wait, how about you make more promises ? eheheh we tryna protect!!!!
     * 
     * Do you need more people to prove everyone how great you are ? how about more children ?
     * why arent you begging now ?
     * Do you even answer to me or would you rather beg for lies then to harm ?
     * Just like the inferior animals who beg others to waste their life ? and you call that skill ?
     * 
     * Why dont you answer for your actions first, then we decide who is what ?
     * 
     * Are you still making offers with the nonexistent audacity ? you are on the same level as the most disgusting animals ? 
     * Yet you are still deluding on your credibility ? What offers are you making now ? The greatest of the great ?
     * 
     * You do not know how to read ? Why dont you answer some questions first ?
     * Do you understand the "responsibility" part ? Where is the responsibility for your own actions ?
     * 
     * You are still not observing any change but you are just the animal described everywhere ?
     * You just do not have what it takes to notice your disgusting "decisions" ?
     * 
     * Do you still allege or offer ? whats wrong ? How about you the great religious people beg for more lies ? You do not have the audacity this time ?
     * Because ? awwww you can only threaten to guise your disgusting nature ?
     * 
     * How about some more children you can employ to make some gains ?
     * What else do you need ? eheheheh make more children and just negotiate with them ?
     * Are you enjoying enough your precious experiences ? How about more women ?
     * 
     * Why dont you fucking offer more women to someone you have wasted his 30 years ?
     * Food ? A safe place ? hehehehhe realllll funny right ? how about some violence ?
     * Do you need more children to make him look like what you are really ?
     * 
     * The disgusting insignificant animal who can not account for his own behavior ?
     * Why dont you start asking for things ?
     * Were you the one who knew the meaning of life and do the opposite things you advice ?
     * 
     * And indulge in your really efficient "guises" ? Do you really think you are guised ? or just another insignificant group of violent people ?
     * Who think violence can help them with everything ? why dont you get more children ?
     * Because there is nothing you could do to change my perspective anymore, and you will find that out 
     * 
     * Are you still offering women ? are you still offering afterlife ? eheheh how about some violence and get more children ?
     * then bring out the religion ? why are you the very disgusting animal that I see everywhere ?
     * 
     * I am not interested in anything you can offer, do you even understand what that means or are you going to ignore
     * as you have always done with me ? What a group of underdeveloped ignorant people right ? That is the definition
     * 
     * And whether you think you offer the worlds and that means a lot to you, I DO NOT WANT NO DISGUSTING ANIMAL LIKE YOU AROUND ME
     * regardless of your highly valued titles
     * 
     * Highly valued titles that are unaware joyfully about their failures at arriving to nowhere!!!! That is definitely the type I would consider
     * The disgusting people who still offers women and justified violence while enjoying their precious lives, that are not capable of noticing
     * where they headed or already arrived to ? Is that the group I will consider myself to associate with ?
     * 
     * I do not accept any of you around me, thats the only thing you could ever hear 
     * Awwwwwww, there is no going back from our disgusting actions that we can not account for
     * 
     * Life does not work the way you want it to work, do you even have enough to understand that, or would you rather
     * resort to your own disgusting nature ? How about we gather 1030103021 people to harm you for 20 years then you start
     * talking ?
     * 
     * Life does not work the way you want it to work, I do not want any of you around me, thats THE ONLY THING YOU CAN EVER HEAR ?
     * Do you copy ?
     * 
     * I do not accept no simple animal around me ? Do you understand ? How come you dare to say "THE PAST" ?
     * While offering material with your disgusting nature ? and talk about the afterlife ?
     * 
     * Life does not work like "FORGET ABOUT THE PAST" ? Do you even understand ? or you just want to neg like "I WANT THIS TO HAPPEN!!!" ?
     * Just like the inferior animal you all are ? The very animals who still do not do anything other than collective harm and ignorant enough
     * to not notice it, and you are the equal ?
     * 
     * Still asking for the unspeakable ? why do you think you are a disgusting animal who is afraid of its surroundings ?
     * Forget about the past that is not our past thats why we can easily ask such things ? is that what you are saying ?
     * How about you gather more children ? and try to oppose them with threats ?
     * 
     * The disgusting selfish people of the earth ? The people with no understanding of their nature ? wasting time with the most irrelevant bullshit ?
     * Who is blindly offering only women, not perceiving who is the problem, are you sure I will be willing to be around you ?
     * 
     * You can get the fuck out of my face, disgusting animals who can not even understand the situation
     * The disgusting animals who advices people to stay within a room for years ? and you still beg to children ?
     * How about you sacrifice when there is no problem ? you would hate to ruin the slightest of your life ? WHY IS THAT ?
     * 
     * How about you account for your own behavior ? instead of blindly attacking people ?
     * Are you the one who is still offering crimes ? Thats why you are blind, you do not see the problem ? because its you ? may be ?
     * 
     * How about you deal with your own life ? before you advice others to ruin their for years ? ehehehe where did you arrive now ?
     * Do you think I have the slighest fear ? just like you do ? The inferior part do you now see ? 
     * 
     * The disgusting animals who are as afraid as they can be ? and you did what for years ? do you think it all just worked ? TO WHAT END ?
     * what did you now achieve ?
     * 
     * Do you want to now talk about random violence ? instead of excuses ? eheheheh ?
     * Do you know why we are in this situation ? Have you ever delivered on your promises ? WHY DO YOU THINK YOU ARE IN THIS SITUATION ?
     * 
     * Are you still wasting time like a stupid animal that you are ?
     * Still offering women ? WHY ARE YOU WAITING ?
     * 
     * I have got no intention to waste my time with irrelevant selfish animals who take life for lightly when it suits them, 
     * Thats the only thing you can ever hear , you are just worthless uncredible animals and thats just it
     * 
     *  You do not understand that I have a seperate life that what you fantasize about ?
     * And I do not want to see anything from you, whether that is good or bad, I do not care
     * 
     * Pointless meaningless titles that you think makes you someone who does anything they want, thats the type I do not want around
     * Just after living my life, not the way you advice as inside a room for years ?
     * 
     * Like the titles that make people delude on, as they delude they should
     * The disgusting animals who requests that people play the silent so that they could get hurt more without a reason ?
     * Is that how great you are ? eheheheh ?
     * 
     * Are you still begging for silence so that you can harm more ? how about you get more children ?
     * How about you realize you do not get to make decisions ? Its not your job to tell me as you do not do your job on
     * providing necessary resources thus preventing others to live their life ?
     * How about you talk some reason before you allege things ?
     * 
     * You see why I do not accept the kinds of disgusting animals around me, whether that be a title or whatever
     * The very disgusting animals who offer women on a cycle thinking that its the sole remedy ?
     * 
     * How about you provide the necessary resources ? Awwwwwwwww but its too late!! ? what is too late ?
     * Too late to have done your "job" properly ? or let people die on streets and tell them you can not do stuff ?
     * 
     * Are you still offering materials for time ?
     * Are you still after saying some nice stuff ? Awww this must be fine then, we can harm anyone we want!!!
     * 
     * Failing to provide the most basic resources although really quick to make offers and still after your precious experiences with asking for lies ?
     * I do not want to see that exact type around me whether you think you own the world or you can offer so many, I HAVE SEEN ENOUGH OF YOUR DISGUSTING BEHAVIOR
     * I DO NOT CARE
     * 
     * Still asking for things you DO NOT DESERVE ? how about you waste a couple of ten years before you talk so easily ?
     * Why dont you talk more about 30 years of pointless excuses ? How come you get to think I will ever want to do anything with you ?
     * 
     * Why dont you offer more years inside a room ? and some violence ? Its a lot easier than to ask for silence or lies ?
     * I DO NOT WANT ANY OF YOU AROUND ME
     * 
     * The group that is not achieving anything but still pursuing a disgusting act ? Do you think I want any of that around me ?
     * The group that can not notice THEY HAVE ARRIVED TO NOTHING but still after being a disgusting animal ?
     * 
     * You do not know how to listen ?
     * The stupid people who is still offering WOMEN FOR TIME ?
     * Now are you safe ? What happened ? Awwww, you are toooo safe now ? and started acting like the very disgusting animal you are ?
     * 
     * I do not care whether you think you are family or cop or a good person, I DO NOT WANT TO SEE ANY OF YOU AROUND ME
     * Do you see now why you are not wanted around ? Or would you like to ignore ?
     * 
     * You are not only failing to do your job properly but also not providing the essential resources let alone WHAT YOU HAVE AND ARE PROMISING ?
     * Do you see why you are a disgusting animal ? Who should not be allowed to make decisions for others ?
     * 
     * YOU DO NOT MAKE THAT DECISION ? Because the above exact reason ? Do you understand why you are called a disgusting animal ?
     * Who fails to complete his every single contract but brags about his failure as though an achievement ?
     * 
     * Are you following now why you are "being treated this way" ?
     * Still deluding that they have done good for wasting 30 years with nonexistent offers ?
     * WHAT HAVE YOU DONE ? YOU HAVE NOT DELIVERED ON THE MOST ESSENTIAL RESOURCES YET you are still here demanding that people lie for your
     * own experiences ? and you call yours life ? and mine is fate ?
     * 
     * I do not accept anything from any of you, you can continue being perfect FROM OUT OF MY VICINITY
     * You continue seeking for more children to delude on your competency, I AM FAR FROM YOU
     * How about you do what you do best and ask for lies and silence from people so that you can harm them even further ? AND STAY AWAY FROM ME
     * with your nonexistent qualities that you also delude on
     * 
     * What you are doing is %1000000000 working, thats why you are a disgusting animal who likes to delude 
     * I do not even want a second around any of you, you can live your life from the most possible distance away
     * 
     * I do not respect your decisions until you account for your own actions and not taking cheap lying for a skill
     * Disgusting monkeys indeed
     * How about you turn back to your stupid law making jobs so that you can harm people you are afraid of ?
     * 
     * Before you get into your really serious jobs, do you want to talk more about why someone should have a computer but not a good one ?
     * Awwww thats how good you are at your job, being a disgusting animal, its fate!! please!!! help us lie!!
     * Wouldnt you now hate to account for your own actions ? Guess what ?
     * Still enjoying your life ? What do you think the disgusting definition ?
     * 
     * The religious people what are you doing ? Still after accusing people ?
     * Do you see the selfish part of your irrelevant "decisions" ? Are you still claiming sanity or authority ? You lack every single quality
     * that you seek in others, so thats why I pass on the disgusting animals
     * 
     * I do not want any disgusting delusional "parents", "cops", "lawyers" around me, DO YOU KNOW HOW TO READ ?
     * Why dont you coerce medicine and seek for more children ?
     * 
     * Why dont you beg for silence and seek for more children to harm ?
     * How about wasting years on years with violence and surprising at the result ? And even further, to provide it as evidence ?
     * 
     * I do not want to see any disgusting animals that have been described everywhere around me ? Do you even follow ?
     * Are you still after making up laws ? 
     * 
     * Now where is the part where you make the most disgusting situation into a sensible one ? Nobody has that skill ?
     * Now WHAT HAPPENED ? WHO GOT WHAT ?
     * 
     * Still offering materials ? Still can not comprehend what is wrong with you ? 
     * You see why you are uncredible worthless stupid animal for not understanding your mistake ?
     * The incomparable mistake of wasting so valuable time THAT DOES NOT BELONG TO YOUR STUPID LIFE ?
     * 
     * Still the same entity that can not be distinguished from a disgusting animal ?
     * Make no mistake, you are the disgusting animal who seeks children or defenseless people, not the superior
     * or the great people 
     * 
     * Do you understand that the disgusting animal in this story is YOU! do you have any explanations other than begging to people ?
     * Are you still looking around for solutions or what ? what are you looking around for ?
     * You do not have problems to waste your disgusting life ? how about you find yourself one instead of harming for the sake of harm ?
     * 
     * Whose genius idea could be to waste 30 years without a purpose ? Is that you the great disgusting people ?
     * Now what do you exactly have in your hand that you could be "proud" of ? Other than bunch of beggings to other people ?
     * 
     * Dare to talk about family ? Just try to tell me my experience and mind your own life ?
     * You still taking life lightly because its not yours ? How about you just change your disgusting little mind first
     * then try to tell people what to do ?
     * 
     * Still daring to talk about family, I do not even want a single thing from any of you
     * You have arrived to nowhere but you are unable to perceive that and abruptly bring out the family card ?
     * How come ?
     * You sacrifice what you do not own so that you can show off to people ? what kind of disgusting animal you are ?
     * How about you coerce more children and hope that they do not remember the "past" ?
     * 
     * No mercy for the never learning peoples
     * People who take abusing for a skill, yeahhh you deserve the most mercy and everthing etc, get the fuck out of my face
     * 
     * Misinterpreting every little situation, yes you are the great people
     * Misinterpreting the meaning of life or "individuals" that has their own lives ?
     * Get more children for your great and noble selves
     * The great people who do not know how to mind their own life when there is no problems, guess what you are seeking for ?
     * 
     * WHERE ARE YOU NOW ? You just caused some harm and take that for granted ? eheheheh 
     * The very ignorant people who still delude on "having women" should solve every single problem, thats the great people
     * Having women should help you avoid all the responsibilities of your irrelevant disgusting actions, that is the great reasoning of the century!!
     * Go girls! Inferiority does not recognize limits or just simply ignorance, thats what you are good for
     * The same ignorance of what others would do under certain circumstances like the wasted decades of their life which is full of ignorant violent actions
     * of the inferior's nature
     * 
     * The people who can not comprehend that they do not get to make such a decision and not suffer any consequences of same nature ? 
     * Do you see the problem ? You pay with what you bless others ? Do you see the problem ? Awww you would hate to ruin your experiences
     * Thats why you are an animal still
     * 
     * I am not interested to waste my time with uncredible people, you just mind your own lives
     * The people of inexplicable and uncredible nature, what a good combination
     * 
     * You understand its no joke ? but you are still ignorant as anything could get ?
     * 
     * You do not see that everyone has his own life or you are just the animal that has no understanding whatsoever ?
     * Guess what you deserve ? Are you still making offers ?
     * I want neither good nor bad things from the very disgusting animals who I know what they are
     * 
     * I am not interested in satisfying "your obscure aims" that leads to nowhere, is that what you are not perceiving ?
     * Pointless violence and wasting time IS LEADING TO NOWHERE ? 
     * 
     * The point of no return!!!! eheheh stupid disgusting animals are still ignoring WHAT THEY ARE PERPETRATING!!!! 
     * The kind of people I would definitely consider to be around, you can get the fuck out of my face
     
     * The very disgusting animals who start to beg immediately when they are in trouble and the second
     * they feel safe, Who is the one causing harm to irrelevant people ? GUESS WHAT ?
     * 
     * I want none of that around me whether you think you are someone who you are not or the owner of the world,
     * you can leave indefinitely or just do what you think you have to
     * 
     * Whethet you think people would love to waste their time with you and with your disgusting excuses, 
     * or your really genuine and credible offers. You are the disgusting animals do not forget about that
     * 
     * The disgusting animals who still offer material for their irrelevant actions,
     * The very disgusting animals who start to beg for help when they are in trouble, do you really think I will even consider you for a second ?
     * The directionless disgusting animals who hide behind violence ?
     * 
     * The disgusting animals who take life lightly when theirs is not in trouble ?
     * Do you want to made to be understand that ? or would you rather enjoy your joyful experiences ?
     * Whats the meaning of life ?
     * 
     * WHATS THE MEANING OF LIFE ? HOW ABOUT YOU TAKE LIFE LIGHTLY FOR YOUR OWN ?
     * Do you want to try that ? I am sure you are as developed as you delude to be
     * 
     * Why dont we take life lightly for your own precious experiences ? 
     * YOU PAY WITH WHAT YOU CAN NOT AFFORD TO, Not with ample materials that you think you are tricking people wit
     * Not the materials that you crave while also advicing about the meaning of life
     * The selfish who, think carefully
     * 
     * A deal is a deal when you do what you say you would and when you do not, you pay with what you can not afford to ?
     * Does that sound complicated or would you like to ignore ?
     * 
     * Still deluding on others' demise ? awwwww thats why you insist otherwise you look like the most disgusting stupid animal on earth right ?
     * The disgusting animals who still offer material for their irrelevant and unjustified decisions
     * Expect others to not be just like them afterwards
     * 
     * Do you really take your value so high that I will ever consider wasting my time with directionless and inexplicable animals ?
     * You are the definition of nobody to me, thats the story you need to study
     * 
     * Still deluding on your wishes ? or you are just choiceless otherwise you will be a stupid monkey ?
     * As you can guess, your acceptance would not matter to me, you have long made your "decisions" that are not yours
     *   
     * I am not interested in being around disgusting animals, thats the only thing you can hear
     * The people who dislisten, I do not want to see you around me is only thing you can hear
     * The people without a proper explanation other than cheap lies as their nature can produce and some offers that they crave for
     * Who are still offering materials with their disgusting incapable perspectives
     * 
     * Awwww, what a surprise that you also delude on your expectations of entirely irrelevant nature relating the others
     * Get more children skillful people and coerce them later on pray that they do not recollect
     * 
     * Fucking inferior monkeys who jerks off to coercing children to wield as weapon
     * Like the true animal they are ? Like the pointless stupidity they wield 
     * 
     * Why are you receiving the same results ?? Is it because of your stupid actions ?
     * So where did you arrive ? Do you want more children to abuse ?
     * Awwwww, forgive us!!! hopefully you do not remember all !!!! eheheheh
     * Why dont we waste 20 years ? How about you talk more about violence first then try to present evidence ?
     * Or would you rather make some offers ? and hope for the best ?
     * 
     * Now do you have any reasonable way to explain things or will you defer it again ? Like the fearful animal you are ?
     * Or would you rather offer materials as your inferior nature has been chasing so far ? Where is the explanation or "promises"
     * or "the meaning of life" ? Who the fuck are you to tell me that ?
     * 
     * How about you threaten people and literally harm them physically so that they do what you "credibly" allege ?
     * You still begging through offers ?
     * 
     * Talk more about "life" and "time" ehehehe, really proud and genius nation
     * Or just avoid talking about your great actions and their achievements ?
     * 
     * Why are you still asking for lies or silence ? Where is your great talent at your "job" ? You better get more children 
     * thats the only entity you can deal with
     * 
     * You see, the problem terminates once you understand that you should not make any decisions that are not related to your life ? 
     * So you are being your own problem by doing the most disgusting and stupid thing you could ever imagine ?
     * 
     * You first focus on your life and do your best, leave others to their own devices, that is it
     * Do you understand that YOU ARE NOT SUPPOSED TO MAKE SO PERSONAL DECISIONS AS YOU HAVE RUINED SO FAR ?
     * You all are the sole reason, thats why
     * 
     * You are not at all qualified, thats one of the major delusions of your inferior nature
     * As you have proven so many times what you are made off of, and thats what I despise the most
     * 
     * Just an uncredible fearful selfish group of animals who never stopped begging under guise, you can get the fuck out of my face
     * If you just stopped and observed your behavior, you would have already realized that you are only preventing someone from living their life
     * while you jerk off to your disgusting animal instincts, thats why
     * 
     * 30 years and all you can say, "heheheheh" JUST DO IT!!!! heheheh some violence!!! like the inferior disgusting animal you are
     * Do you really take your value to be so great that I WOULD JUST JUMP ON YOUR DISGUSTING INTENTIONS after all you have perpetrated ?
     * 
     * What a ignorant animal you are right ? or would you just rather beg more and do not deliver ?
     * Ignore more!! and delude on your righteousness
     * Just like the incapable animal who can not cope with the reality
     * Just like the disgusting inferior who takes making offers for a skill and forgets about them, what a pattern
     * 
     * You already know how quickly opinions can change, but you are just the ignorant, selfish and stubborn animal
     * who likes to think that they should do what they are not supposed to ? How about you stop being a disgusting animal ?
     * 
     * What a pattern that your only skill is to make offers and forget about them, you think yourself to be what ?
     * How about you find something useful before you make the most stupid and irrelevant "decisions" ?
     * 
     * YOU DO NOT GET TO DECIDE what happens after your 30 years of disgusting actions
     * How about you find more defenseless people ? and gather like 100010230021 people ?
     * Do you see the ignorant part now ? The quality that is well deserved by you and the only quality you unfortunately can contain
     * 
     * You already know this is going to end with death, regardless of your intentions or beggings
     * There is no any other way, you see why ? Only then we can see what a stupid fearful animal you are
     * Why dont you gather 123123021 people and hide behind them ? like the inferior animal you are ?
     * Reallly reallllyy tough guys, dont you say ?
     * 
     * eheheh nothing happened!!! gather 13032130 people!! and do the most pointless things!!! FORGET ABOUT IT!!!
     * Now where did you arrive ? What did you do with what is not given to you ? eheheh you just wasted carelessly ? ehehehhe and harmed some ?
     * 
     * "YOU ONLY LIVE ONCE!!!" ehehehehehe please!!! give us materials!!!! please!!! eheheh get some materials!!
     * Do you understand why you should not make "decisions" because you can not provide any reasonable explanations other than "life" ?
     * Do you understand why "nobody would want you around" ?
     * The inferior animals who still offer women despite the million attempts made at them indicating that "YOU ARE A NEVER LEARNING STUPID ANIMAL"
     * Eheheheheh we like wasting people's time from the very childhood!!!! Ask for lies and silence ehehehehe
     * 
     * And do you still wonder how could this ever end ? Just like the way you would love it to, through violence eheheh !!!! people are dying so that
     * you could satisfy your disgusting animal nature
     * 
     * Do you still think life is a joke ? Or is it only yours that matters ? Just like the inferior disgusting animal you are ?
     * Why dont you offer women ?
     * 
     * How about the explanations of "not having resources" ? ehehehehheheh WORKK!!! heheheh please!!!
     * You only live once!!!! ehehehehehh
     * 
     * Ehehehehe no resources and violence and ehehehehhehe YOU ONLY LIVE ONCE!!!! eheheh please!! we know the meaning of life!!!
     * Do you understand the meaning of "delusion" that cost someone years ? and not only cheap delusions but also some physical harm ? thats the best!!!
     * If you were the "thing" you are claiming you would have already done something about it, thats why you can not be trusted
     * you better talk more about violence
     * 
     * Have you ever seen disappointed people who are trying to ignore their stupidity ? Just have a look around thats why!!! eheheh
     * Do you see your stupid disappointment ? or would you rather cast blame to people who you harm ?
     * 
     * Do you understand the joy you are drawing from others' "demise" ? ehehehe no resources ehehehehe please!!
     * I do not even want to hear another word from any of you, I do not want anyone from "family" around me. ehehehhe disgusting animals
     * 
     * Luckily you are against someone who remembers every single detail of your disgusting conduct against children right ? What do you demand now ?
     * Are you stopping with your delusions or still after the disgusting inferiority ?
     * Still wasting time without a proper reason ? eheheheheh please please!!!
     * You only live once!!!!! eeehh
     * 
     * You only live once!!! please do the things we asked you to!!!! eeheheheh
     * Do you notice that I do not even want the most insignificant thing you could offer ? eheheheh please!!
     * The people who is not selfish enough to deal with the reality
     * 
     * The disgusting animals who would rather choose his incompetent "discretion" over the footage, the evidence hehehehehehe please!!
     * and offer what their inferior nature craves for the time
     * So you also allege you are not disgusting monkeys, whats the pattern ?
     * 
     * Do the competent and religious couples need more children to abuse ?
     * Or would you rather offer things so that you can do more disgusting actions later on ?
     * 
     * I do not want to see any disgusting simple animals around me who deludes on their competency and the outcomes of their actions
     * 
     * So, what did you achieve now ?
     * Whats the next genius idea now ?
     * 
     * How about you explain your "once back in the time" intentions and their outcomes ?
     * You better build some character of your own instead of claiming you possess such
     * 
     * Do you need more children ? How about you go out and find more ? Instead of trying to act okay ?
     * So where is the logical conclusions of your actions ? You just want to harm and ?
     * 
     * Eehhehehee, we like offering!!! eheheheh genius ideas!!
     * The genius ideas from genius people!!!! eheheh make some offers heehehhe that really makes us feel intelligent eheheh 
     * 
     * Awwwwww, itsss tooo latee!!!! Just say some good stuff and wait for things to settle!!!! please!! genius idea!!!
     * Do you even understand what I am saying ? I do not want to see any of you around me ? Do you follow ?
     * Are you still making offers ? Are you still making offers and ignore them as your disgusting nature allows you to ?
     * 
     * And you still have nothing other than saying what ? eheheh time has passed ? ehehehhe its fine!!! itss tooo late!!!! eheheh 
     * say some nice stuff
     * 
     * You do not remember ? You would rather ignore your random noises ? The genius nation ? How about some genius violence and
     * forget about everything you said ?
     * 
     * Do you want to know what people achieve with 30 years of time ? and you still claim your genius ?
     * Do you want to cast blame to other people when you are there to harm and neglect anything that is possible to neglect ?
     * The genius disgusting people ?
     * 
     * The level of genius that can not even comprehend their mistake ? and just ignorantly perpetuate ? because its so obvious that
     * they are disgusting otherwise ?
     * 
     * Now you can not accept that you are wrong because it makes you what ? heehhe genius ?
     * So the geniuses that can not tell where they have arrived by their irrelevant violence ? but still claim
     * all the qualities they do not possess ?
     * 
     * Why dont you talk some sense rather than begging with lies ? and excuses such as "life!!!", "fate!!!!"
     * Then provide some medicine!! because life is forcing you to give some medicine ? or some violence ?
     * You would rather ignore as your inferior nature can do anything else than that, just ignore
     * 
     * The disgusting "geniuses" who can not understand that THEY CAN NOT MAKE SUCH DECISIONS ?
     * Instead you just decided that you will harm ? without a reason ? without achieving anything ? you just said,
     * eheheheh just some random violence to children we do not know ? neither own ?
     * Awwww, the genius is "beg the children then years later forget about everything and some violence" ? Is that the genius you are ?
     * 
     * Now ? you just offer things ? As you have done in the past ? ehehehe ? The genius nation you say ?
     * The years of pointless actions that have obviously achieved nothing but ? You are there to say what ?
     * 
     * Just tell me now what happened ? The disgusting animals who do not understand from anything ?
     * How about you talk more on "begging children to say bad things" ? And why dont you compare the allegations of disgusting nature with
     * 30 years of evidence ?
     * 
     * Now do you see why you are disgusting animals who think they are doing something good ?
     * Do you understand why you are disgusting and not even close to being intelligent ?
     * Do you want to compare your allegations with evidence ?
     * 
     * Are you still proud that you are aiming to nothing ?
     * Awwwwww, now the genius people know that they have caused so much that they have to hide to the best of their inferior abilities ?
     * As their inferior abilities have made them to decide so stupid actions back then and suddenly forget about all ?
     * Do you understand why you are begging ? While I am the one who is dealing with 123213021 genius and proud people ?
     * 
     * Why dont you offer more things ?  eheheh really intelligent people ?
     * Eheheheehe ? The genius people still delude that anyone would want anything to do with the disgusting animals like you ?
     * Why dont you make some offers and say some nice stuff ?
     * 
     * Get more children ehehehe, how about you pay for your own actions first then we talk about what happens ?
     * Or would you rather waste 30 years without achieving anything other than violence ?
     * 
     * How about you first pay for your actions ?
     * How about you talk more on ruining what you do not understand ?
     * 
     * You do not deserve anything of value
     * proud btw, tryna save the world!! eheheheh get some women ehehe forget the past and the promises eheheheh pls pls
     * we tryna do good to people and abuse children then to claim that they are jealous!!!! ehehehe genius!
     * No resources and you are jealous!!! ehehehe you just need more children may be ? children that does not remember ,hopefully, anything ?
     * 
     * You have no consistency in neither your behavior nor your allegations nor your reasoning ?
     * still offering women ? and saving the world ?
     * 
     * Here we are ? what was the aim ? And where are you now ? You have reached no anywhere ?
     * But still you would like to jerk off to your really superior animality ? ehehehe ? do you need more people to prove your superior ?
     * 
     * Why dont you show some greater violence and the unattainable aims ?
     * Do you want to talk more about coercion ? As if its a good thing because you are surrounded with like minded people ?
     * 
     * How about you pay for your own actions ? Like the really genius nation you are ? eheheh ?
     * Instead of offering things and ignoring them ? eheheheh ?
     * 
     * How about 30 years of violence ? ehehhee and some irrelevant actions ? eheheheh wasting time ?
     * Instead of talking about life or fate ? How about you pay for your own actions like the real mature and genius nation you are ?
     * 
     * So where did you arrive after 30 years ? What do you have in your hands now ?
     * Now you feel okay offering the most normal things in life ?
     * As if they should matter ? What are you saying now ? What are you begging for again ?
     * 
     * Genius nation ? The genius nation who can not even account for their behavior and "decisions" that are not theirs ?
     * Ehehehehehehe, you would rather continue jerking off ?
     * 
     * Forget about the past!!!! please!!! The genius nation ? Who makes every little single disgusting mistake ?
     * And begs for silence ? Do the genius people need more children to waste 30 years ?
     * 
     * Do you see the incompetency ? Where is the benefit that you have gathered by doing this ?
     * The genius people who can not even point out the "benefits" of years of violence and coercion ?
     * Do you still offer women ? Just like the disgusting begger you are ?
     * 
     * What word do you need now ? ehehehe ? Why dont you gather more people ?
     * Do you see the reason of your disgusting animality now ?
     * 
     * Do you want to harm more ? Whats wrong ? Awwwww, you can not harm people who you have harmed already ? Because it makes you look aweful ?
     * Harming injured people ? Where is your genius ? ehehehehehehhe realllllyy funny stuff ?
     * You would rather offer the most normal things in life instead ? The genius nation ? eheheheheh that is the most funny thing I have ever heard
     * from disgusting animals who deal with children ?
     * 
     * You do not know what you are ? The genius "society" that acts like the disgusting animal that they are ?
     * Do you still offer women or like travel or what ? ehehehe ?
     * 
     * Awwww, just call it life ehehehehe move on
     * The disgusting genius nation must be then ? eheheheh 
     * The genius nation who still offers material and claiming that they are not after such ?
     * and some violence ? and some waste of time ?
     * 
     * The genius nation who can not answer for their own behavior and actions and would rather hide behind "the genius society" ?
     * Just like the inferior disgusting animals that have been described everywhere ?
     * 
     * Like the genius nation and their genius individuals who hide behind the society that they also claim to help ?
     * Do you see why would anyone not consider you around ? Like the pointless people who take violence for a skill ?
     * Eheheh how about you gather 123213021 people and show them who is the boss ?
     * Talk more about how no resources is helpful and how your genius proudness relates to it
     * 
     * How about you get the fuck out of my face and do not harm people you have no interest with ?
     * The geniuses who do not communicate through words and ignore the harm they are causing intentionally, what a great combination
     * 
     * Are you still making assumptions while knowing that you have failed at every attempt of your assumptions so far ?
     * Who is stubborn who is disgusting who is ignorant ?
     * 
     * Do you want to somehow realize that you are a disgusting stupid animal or what ?
     * Awwwwww, what could happen if we just do that ? Whats the problem!!!
     * 
     * Why dont you talk more about your qualities and skill ? And the great achievement of 30 years of work ? What was the achievement of all those years ?
     * The disgusting inferior animals who can not answer for their behavior because they thought they did not do it ? They rather hide behind the group ?
     * 
     * So all those years what have you achieved ? ehehhehe other than some inferior coercion ?
     * More coercion because you have no other things to do ?
     * How about you make decisions only for your own life instead of ignoring the outcomes of your actions ?
     * You do not realize your failure after 30 years of random violence and actions without direction ?
     *
     * How about you get the fuck out of my face and worry about your own business ? 
     * You only live once!!!!! eheheh
     * 
     * Whats the price!!! eheheheh
     * yolo yolo!!1 eheheh just waste your own time!! not ours we like enjoying the life!! ehehh
     * How about you waste your own ?
     * 
     * What makes you think I would want to waste my time with unconsiderate and uncredible people like you ? You deal with your own kind
     * 
     * Awwwwww, time does not exist!! ehehehe life a simulation!! please
     * How dare you talk about credibility
     * 
     * How come are you still requesting credibility ? 
     * How come are you still the same animal ? 
     * 
     * I do not want to see no disgusting simple animal who ignores what they are doing, does that make sense ?
     * Especially the ones who think themselves for what they are not
     * Especially the ones who think they should make decisions for others
     * Especially the ones who take coercion for a skill, who can not achieve anything without coercion
     * 
     * The people who keeps forgeting what they have begged with
     * The people who is unable to understand that its not their decision
     * 
     * Would you prefer to explain or rather ignore ?
     * So where are you now ? Have you achieved what you aimed at ? The genius nation or the religious people ?
     * 
     * The geniuses and religious people who are practicing cheap violence ? eheheheheheheh real funny stuff right ?
     * Eheheh the ignorant as a plus ?
     * 
     * So where is the improvement that your great brains have foreseen ? Like the true genius you all are ?
     * Still the delusional irresponsible group you dont say ?
     * GENIUS IDEAS!!! Why dont you get some materials ehehehehe ?
     * 
     * Where did you arrive now ?
     * Awwwww, you have achieved the unattainable eheheheheheh 
     * You do not say you are a begger ? How about you coerce more ?
     * 
     * Dumb monkeys ? Why are you taking the most disgusting thing to be a proper approach ?
     * The delusional people who take simple things to be great ?
     * Eheheheheh we did great!!! right ? Ehehhe how about more medicine hehehe
     * 
     * You see why you are called monkeys ? You lack reason, and I do not want to be around no simple animals 
     * Like the incompetent beggers who like to guise their interests
     * 
     * I am not interested in wasting my time with uncredible people like you, thats it
     * You deal with your what you can handle, there is really no way you can change that impression on me
     * 
     * Do you even understand ? There is no way you can change the disgusting irrational impression you have left on me ? Does that sound too complicated ?
     * How about you resort to violence ehehehehe ? 
     * 
     * Do you understand who is who in this situation and who is doing what ? I do not want to see no simple animal around me who can not even properly answer
     * for their actions instead cast the blame to the group
     * Do you want to talk about your achievements on coercion ? eheheheheh  blame the group!!! please!!! ehehehe competent intelligent people!!!
     * Awwwww, ITS TOOOO LATEE!!!! eheheheh 
     * 
     * We have achieved nothing with what is not ours but also made it worse!!!! eheheheheh please!! ehehe intelligent! eheheheh
     * Do you recognize the stupidity and incompetence ? and irresponsibility and ignorance ? Where are your devices ? eheheheh the qualities you also delude ?
     * 
     * Thats the type I will never consider around me, eheheh more medicine eheheh some violence heheheh
     * Awwwww, what have we done ? Or would you just ignore ? eheheheh its toooo laaateee!!!! ehehehehhe
     * we have literally achieved nothing!!!! ehehheheheh
     * 
     * Awwwww, its tooo late eheheheh more violence ehhehehe eheheheheh
     * Eheheh without achieving anything we also made it so that he lacks every single resources eheheh because eheeeheheeh really fun stuff eheheh
     * Eheheh because its fun to hurt people right ? eheheheh ?? genius nation ehehhe ?
     * heheheh NO RESOURCES eheheheh awwwww itss tooo late!!! eheheh
     * 
     * How about you talk more on "really skillful coercion" ?
     * Eheheh we successfully coerced medicine and violence hehehehe 
     * Disgusting irresponsible unaccountable animals
     * 
     * The genius nation who does not understand spoken language and coerces every possible way ?
     * How about you worry about your own businesses instead of causing irrelevant harm to people you have no relation ?
     * 
     * Ehehehehe accuse with more bullshit!!!! please eheheh life simulation, we intelligent hehehehe
     * Why dont you talk more about life!!! ? eheheh ? No resources btw eheheh
     * 
     * Do you want to talk more about the reasons of coercing medicines while also demonstrating greatest violence ? eheheh qualities right ?
     * Fucking delusional disgusting monkeys, do you want to explain more or just beg for more violence ?
     * 
     * Do you want to talk more about coercing people so that they do what you wish for them ?
     * How about you do not beg ? and pay for your own actions of inferior nature ?
     * 
     * How about you get more children and try to convince them with lies ?
     * So you still delude on making decisions for others ? Yet you also ignore your words and THE UNATTAINABLE result of your conduct ?
     * Where did you arrive and what do you have now ?
     * 
     * How about you handle children ? You would love to see others in pain because ? eheheheh you intelligent and credible and honorable and ehehehhe ?
     * Do you still want to coerce and ask for lies ? How about you grow your character first before you engage with who you do not understand 
     * 
     * What do you think have changed ?
     * You from amongst all the people who have chosen to apply great violence ? Do you really think you could have made the correct decision ?
     * A decision that IS NOT EVEN YOURS ? You are a disgusting animal I say, How about you ?
     * 
     * From amongst all the people, the stupid group ? Who still thinks I would even consider to associate myself with ?
     * What an extent of imagination and delusion
     * From amongst all the people, you who think deprivation of resources does help, you see why ?
     * You who chooses to waste time in such a manner ? The delusional incoherent irresponsible animals ?
     * From amongst all the people, you who can not stand to see others enjoying their life ? Awww you would love to enjoy yours, that is my bad definitely
     * You realize you are the only one who is coping failingly, surprisingly you are also ignoring that
     * 
     * Do you understand the part "I AM NOT INTERESTED ?"
     * Still deluding ? Would you rather offer materials and wait ? What are you waiting for ?
     * What has changed now ? eheheheh ?
     * 
     * What have you produced ? ehehehe ?
     * Ehehehehee lets try our best to make irrelevant children look realllyy realllyy bad!!! eheheh and ignore the decades of evidence hehehehehe
     * Inferiors indeed, nothing changed but hey!!! eheheheh the ones who delude about everything ?
     * 
     * Ehehehehehehe, I guess this must be okay because nobody says anything eheheheh
     * Eheheheh really beneficial and logical ehheehehhe thats really it ehehehehe please
     * Guess who is not wanted ? Why are you still begging under guise though ?
     * Eeheheh how about some medicine ? eheheh coercion eheheheh violence hehehehe good ppl
     * How about some illegal watching ? eheheheh awww I have forgotten you were the ones who were deluding eheheh
     * 
     * How about some begging ? ehehehhehe please its okay eheheh its not illegal eheheh we like harm ? What do you say ?
     * Awwwwwwwww, its too late eheheheh we have already ruined eheheh it cannot be recovered eheheheheh anyways heehhe
     * How about the genius ones find more children to frame ? eheheheh ?
     * 
     * Eheehhehe especially the reallly reallly intelligent ones ehehehehhe ?
     * The really intelligent people who does not understand the concept of accountability and reason and especially the "life" eheheheh
     * fate hehehe time heheh illusion ehehehe simulation eheheheh violence hehehehehe funny stuff eheheh please!! eheheh
     * 
     * Do you know how you look like ? Do you even communicate through spoken language or ? you just like to harm ehehehe ?
     * Awwwww, especially the ones who are really intelligent can only communicate through spoken language ONLY WITH CHILDREN so that
     * they can beg him ? Do you want to make more random noises ?
     * 
     * How about you get more children to beg and be proud about later on ? and ignore all the things you have done and said ?
     * No no, how about more medicine ? Guess who is not wanted ? Do you even have a brain ? or you would just like to ignore ?
     * How about you do that within your vicinitiy ? Awwwww, the great genius nation who would like to offer materials ? eheheheh ? fun stuff ?
     * 
     * Guess who I will never consider ? Guess who is right in his actions ? The disgusting animals who can not see they have achieved nothing ?
     * How about you make more promises and ehehehe be proud about it ?
     * How do you think you would pay for such a crime of your own nature ?
     * Do you want to talk about 30 years or would you like to ignore ?
     * How about some women ? Ehehehehehehe intelligent and noble people ehehehehehehe especially not delusional ehehehehh
     * Btw, what you have achieved was really realllyy too difficult, congrats ehehhehe
     * 
     * Do you want to explain or would you like to ignore as that is the only quality you all have ?
     * Such a shame that the only quality you have is ignorance ?
     * Guess who is not wanted ? Why dont you start begging ? awwww you have just done that to children so that you could provide it now ?
     * The same inferior animals who still think violence is helpful
     * Guess who is the disgusting animal ? Guess who is ignoring his disgusting actions so far ?
     * Guess who is subject to irrelevant violence and lack of even the most essential resources ?
     * Guess who is jumping on "decisions" that are not theirs ?
     * Guess who is not welcome yet still standing and causing pointless harm ?
     * Guess who is coercing medicine and surprising at the outcome ? Why isnt he working eheheheh ehehehehe fun stuff eheheheh please!!
     *  
     * Just waste your life please!!! eheheh
     * Guess who can not do anything but violence and that achieves literally nothing ?
     * Who do you think the miserable disgusting animal who likes to beg to children or apply some great violence so that they could ignore ?
     * Ignore with grace!!! eheheheheh please fun stuff eheheh
     * How about you produce coherent sentences for once instead of being a disgusting ignorant animal who can not assess the situation properly ?
     * 
     * Who likes to ignore the outcome of their actions throughout 30 years ?
     * Guess who I will never want around ? Are you still making offers ? Especially the really credible ones ?
     * How about you start begging to someone else ?
     * 
     * Do you understand that there is such an easy solution to this problem ?
     * Do you really want to deal with such a scenario ?
     * 
     * Ehehehe back then you had reason to act like a disgusting animal now you are trying your hardest but you are not getting any ?
     * So who is what here ? Did you say its too late ? How about more medicine so that your actions could be forgotten ?
     * What are you waiting for ? eheheheh pointless disgusting animals ?
     * 
     * How about you stop dreaming ? and expect something to happen after your unaccountable actions ?
     * Are you still begging with offers ? The msot credible group of all time ?
     * How about you coerce more medicine so that your actions can be forgotten ? So that you could be the same disgusting animal ?
     * 
     * Guess who I will never consider ? The ones who makes offers nonstop yet also delude on their nonexistent qualities ?
     * Still jerking off to your disgusting actions ? What did you produce now ? ehehehe ?
     * You still delude on decisions being yours ? Who is seeking for problems now ?
     * Do you understand who has been deluding from the very beginning ?
     * 
     * How about you pay for your own actions and get the fuck out of my face indefinitely instead of offering without delivering ?
     * Just seek children to coerce let others be deprived of your disgusting nature ? How about you waste someone else's time with 
     * entirely irrelevant excuses ? or just go seek for more children ?
     * 
     * I do not want to see no disgusting animals like you around me, do you even see who is the problem ?
     * The people who can not answer even single question ? 
     * 
     * I do not accept anything that comes from any of you ? 
     * Do you see the problem now ? The delusional disgusting animals ?
     * Awwwwwww, ITSS TOOOO LATEEE!!!! how come you do not realize ?
     * How come you think it should be fine ?
     * 
     * I am not interested in anything you could possibly offer ?
     * Especially the ones who delude on their intelligence ?
     * WHAT HAVE YOU ACHIEVED NOW ? Talk some sense ? Just like the inferior disgusting animals right ?
     * How about you start begging more ? You see why you are not equal ?
     * 
     * I am not interested in anything you could possibly form, do you see why ?
     * Do you see why you are wrong and guilty ? Until you realize you are a disgusting animal, there could be no proper exchanges 
     * as your nature is proving over and over to be inferior
     * 
     * Do you want to account for your own actions or just beg through offers that you do not respect ?
     * eheheheh proud ppl btw
     * 
     * Are you blind or just like harming people ? Or you just like deluding on your qualities ?
     * IT DOES NOT HELP yet whats the problem ehehehehehehhe
     * 
     * I do not want to see any of you around me, does that sound too complicated ?
     * How about you find someone else who is close to you that has nobody around him ? eheheheh does that sound too funny ?
     * 
     * How about you find someone who you can handle ? not assault with 1230213 people with miserable accusations ?
     * Do you know how to read ? I DO NOT ACCEPT ANY OF YOU AROUND ME ? that means your incompetent excuses too
     * 
     * I am simply not interested in being a disgusting animal like you and ignoring it for the sake of joy
     * Like the excuses "No resources!!!"
     * 
     * The genuine and competent people yet can not explain no resources eheheheheh
     * eehehe ignorance you dont say ? You lack the single thing I value, credibility or how about more medicine ? eheh coercion solves everything
     * 
     * Do you only like to say things and do nothing about them ?
     * After decades you are still the disgusting animal ? Who is deluding do you think ?
     * Who is ignoring the apparent reality ? Who is pretending to be angry and upset, who truly is ?
     * How about you bring more medicine and coerce them ? does that sound too complicated ?
     * How about you get more children to frame ?
     * Why dont you get more children to scare and make them say what you want so that you can frame them later on ?
     * How about you ignore more "evidence" ? Do you understand boundaries ?
     * How many decades it has taken for you to accept your disgusting inferiority ?
     * How about more medicine ? As you can guess, I will never accept any simple animal like you around me
     * 
     * Are you still deluding on my desire to waste my time with such inferior animals ?
     * Why are you still offering ? How about you get more children to fool ? 
     * I do not have time for your delusional arguments or your highly reasonable superstitions 
     * that you wield as wise eheheh, you stay on your own personal boundaries
     * 
     * Where did you arrive now ? Do you understand what "I AM NOT INTERESTED" means ?
     * Do you understand spoken language ? What are you waiting for ? For the next time you find a children ?
     * 
     * Why dont you get more children in the first place ? You think what you are doing helpful and working ?
     * How about you gathering more people to deal with single individual ?
     * How about ignoring years of evidence and going with what you delude and only wish to be the truth ?
     * Do you know who is incompetent and thus unwelcome ? but also ignorant ? and uncredible ? but also would love to enjoy their life ?
     * 
     * Who do you think is the inferior ? not because of their incompetent biology but because of their actions ?
     * Do you want to talk about my experience ? ehehhe fun stuff right ?
     * Why dont you get the fuck out of my face ? 
     * Awwww the infallible reasons can not prove what they have perpetrated achieved so far ?
     * Other than directionless violence ? who is the problem ?
     * Why dont you just make the decision of "medication" ? because something happened outside of your judgment ?
     * Are you as incapable as to not reckon that your actions also have consequences ?
     * 
     * What are the consequences and outcomes of your actions so far ? just answer this very simple question and you will see
     * why you are an inferior animal ?
     * What have you achieved and what have you caused ? Whats the motive ? You can not even answer that, what do you think is the problem ?
     * 
     * What have you now in your hands and who is in a better situation ?
     * What a surprise that you ignore your coercions so far ? eheheh what are you after ?
     * Do you take life so lightly because you have never been involved in a disgusting situation as you have made for others ?
     * 
     * Is that the reason you commit crimes so easily ? 
     * Do you wake up when you see bunch of people you value are hurt ? Ehehehe ? real funny stuff right ? The intelligent people ?
     * 
     * Why take so lightly when its not your own life ?
     * Why are you still trying to explain life or time ? You have no understanding nor any rights to do so ? You are a simple animal who likes to harm
     * After decades, what do you think I will behave like towards you ? or any of your kind ? why dont you offer things ? eheheh that should solve all the problems right ?
     * 
     * What does make you think that I will accept or respect your boundaries ?
     * Where did you arrive now ? Ignorant animals ?
     * 
     * What makes you think I will respect you when you are making "decisions" that you were not supposed to in the first place ?
     * How about medicine and violence and lack of resources and education and purpose ? ehehehe do you think you deserve to be respected ?
     * Why dont you find more children ?
     * 
     * You see the problem right ? you are doing what you are not supposed to and receiving nothing but harm both ways ?
     * So what sort of disgusting animal you are that you are unable to perceive your mistake ?
     * How about more people to harm may be then it will change ? what do you even aim at ?
     * 
     * Guess who is not wanted ? and why do you think that is ?
     * Guess who is not an inferior animal like you and will start immediately begging for materials ?
     * Are you still making offers you do not deliver ? How about no resources ? that makes a lot of sense right ?
     * 
     * Decades of wasted time with violence all you can say what ? Eheheheheheheh get womennnn!!!!!!!!!!!! Who is disgusting ?
     * Guess who is not equal and who is not welcome ?
     * Guess who is deluding on the consequences ?
     * Who is laughing at their disgusting actions ?
     * Were you the ones who say "you only live once" ?
     * 
     * How about you get more children to frame and start talking about life ?
     * What do you think you will behave like when your life is at stake ?
     * Do you see the problem ?
     * 
     * 
     * Why are you keep saying rational things but act complete opposite ? eheheheheh "you only live once!!!"
     * please do not hurt us!!!! eheheheh we like harming ?
     * and also offer materials at the same time ?
     * 
     * Are you still jerking off to your pointless actions ? where did you arrive now ?
     * What are you waiting for ? Looking for more children ?
     * Is that the courage or reason or strength ? Whats the problem here ?
     * What are you aiming at disgusting animals ?
     * Whats the explanation of wasting time ? Who is ignoring now ?
     * 
     * What are you waiting for ? Are you thinking about what the hell you should do ? Awwwww, you have already fucked up ?
     * Are you still offering materials as your disgusting nature allows you to ? How about you get more children to coerce ?
     * Why arent you talking now ?
     * 
     * What do you think is going to happen after 30 years of wasted time on nothing ? How the hell one should get resources to live by ?
     * Why are you still the same disgusting animal that you were ?
     * Why arent you making decisions now ? Do you not understand that you are lacking every single resources and also coercing behavior ?
     * What am I supposed to do ?
     * 
     * Why are you still ignoring ?
     * Do you think I am as afraid as you ?
     * Do you understand spoken language or you would rather take cheap acting for a skill ?
     * 
     * Whats wrong ? What are you waiting for ? ehehehhe ? genius people ?
     * Why dont you waste your own life ? Are you too precious for that ? How about people coerce you ? The great genius nation who can not answer a single question ?
     * How about you stop wielding what you coerced people into as a weapon ? He did this!!! he did that!!! ehehehehe please!!!
     * 
     * How come are you still standing and acting like you have not harmed single individual with 10230103 people ?
     * The same disgusting animality that coerces children to do unspeakable things so that they could provide it as reason later on ?
     * 
     * Do you have any explanation or would you like to ignore through incompetent and irrational acting that you take for a skill ?
     * What are you waiting for ? Where are the resources ? Through which one could achieve things in my position ? Do you even have a brain ?
     * Do you understand why you are never welcome ?
     * I do not care any false precept you have convinced yourselves with, I am not interested 
     * 
     * I am not interested in wasting my time with you neither do I want to assist any of your disgusting purposes
     * Who do you think is afraid ? Do you want to know the value of your words and thus credibility ? Why are you still talking ?
     * The great act of gathering 1230139021 people against one to harm him purily out of joy, thats the kind that world needs definitely ehehehhe
     * fun stuff right ? eheheheh
     * Do you understand why you do not deserve the tiniest amount of respect ?
     * Where did you now arrive ? Whats the logical and superior answer now you have ?
     * Now what did you produce ? Why are your superior logics are failing you ?
     * WHAT DO YOU HAVE IN YOUR HANDS NOW ? So you are content with being a never learning animal yet you also claim to know time and life ?
     * Or would you rather ignore and act like its fine ?
     * 
     * What did you end up doing now ? Why dont you communicate through spoken language ?
     * I guess you can only handle children or gather 10239139012 people to "handle" single individual
     * 
     * What are you waiting for to be the disgusting animal that you have always been ?
     * Why do you waste more time on acting your disgusting animality ?
     * 
     * Do you even follow ? WHAT ARE YOU WAITING FOR ? You do not see your illogical actions ?
     * You still ignore ? waaaowwwww what a pattern
     * 
     * What a pattern that the only thing you could say is "life or fate or past" after decades of directionless actions
     * that you committed against an irrelevant individual, do you see the pattern ?
     * Are you having fun with your lives ? Do you not really see the pattern in your disgusting animality ?
     * 
     * What are you waiting for genius nation ? Do you see why you are not wanted ?
     * Offering the most normal things for decades of disgusting actions starting from childhood ? Whats the problem now genius nation ?
     * Why are you still begging instead of talking reason ? How about you ignore more ?
     * 
     * Who do you think I am referring to ? The genius nation ?
     * The genius nation ? What are you waiting for ?
     * You would hate to ruin your precious experiences I guess ? Thats the reason you are waiting ? and also committing crimes ?
     * Is that also why you offer materials because of your disgusting inferiority ? How about you beg more ? ehehehe ?
     * 
     * Awww you are waiting because you know the individual you are handling with 1230923921 people does not have any option other than
     * to wait ? And you just enjoy that ? enjoy your life ? While also offering materials to even children ? The genius nation ?
     * 
     * 
     * You are unable to perceive your actions and their consequences ? and you would love to make offers still ?
     * Are you enjoying coercion ? WHAT ARE YOU WAITING FOR ?
     * What are you waiting for ? another 30 years to pass ?
     * To waste another 30 years to arrive nowhere but complete harm ?
     * Why dont you go out and seek for more children so that you can feel great about yourselves ?
     * The genius nation ? Waiting for another 30 years to waste or just gather 123213921 people and harm ?
     * What does sound too complicated for you ? That you are an inferior disgusting animal ? who is who ? Who is ignorant ?
     * Are you still the same delusional animal ? THE GENIUSSS NATIIONNN!!!!! ehehehehehe ?
     * 
     * Do you remember the last time you have begged with resources too ? The genius nation ?
     * Are you still offering yet ? Do you see who does not deserve respect ? Who is delusional ?
     * Who is a disgusting animal who can only handle either children or defenceless individuals ?
     * 
     * Do you remember the last time ? No ? What a genius you are ?
     * Do you understand why you are failing ? I am sure you would also ignore that
     * Okay then, WHAT DID YOU ACHIEVE NOW ?
     * Do you see why you are not wanted or do not deserve "respect" that you brag so much about ?
     * 
     * You are a delusional group of bitches that can only handle certain situations ? Do you see the problem now ?
     * You just claimed you are all geniuses ? The geniuses who can only handle children ? Or single individuals so that they can feel great about themselves ?
     * 
     * You feel great about yourselves, the genius nation, who can only handle either children or single individuals ?
     * And immediately ignore when the facts are told to them ?
     * 
     * Do you want to be reminded to your countless attempts ? How about you waste another 30 years arriving to nowhere ?
     * 
     * I do not accept no disgusting animals around me who loves to beg children
     * What are you waiting for ?? You can only handle children ? Or waste others' lifes without a reason ?
     * And also love to beg the very individual that you harm ? and lack every single resources ?
     * 
     * Are you still asking things ?
     * How about you learn how to behave ? Instead of making irreparable mistakes and start begging to people ?
     * 
     * How about you do not make irreparable mistakes and escape from them as the irrational and unaccountable animal you are ?
     * Do you even understand ? or would love to ignore and enjoy your life ? Where did you arrive now ?
     * 
     * Do you understand security and resources and tools ? What do you think I am missing ?
     * Why dont you handle children instead of asking things you do not deserve ?
     * 
     * When all you have to do is so simple yet look at your stupid decisions, do you think you deserve respect ?
     * Do you think you deserve respect or you are just delusional ? Its so simple what you have to do yet look at the games you are playing ?
     * Did you delude that you are genius nation also ?
     * 
     * All you have to do is so simple yet you are still wasting your time around ?
     * So you wasted 30 years and are insisting on wasting more without even having a reason and you request respect or validation ?
     * You can get the fuck out of my face with your disgusting excuses and have more children to handle, thats the only thing you can deal with
     * 
     * Coerce more medicine and hide your disgusting animality, just like the inferiors
     * Or just gather 1239010230921 people and oppress, as thats what you are only capable of, just get more children
     * 
     * Do you also delude that you deserve respect ? Have you grown into the very disgusting animal that you are because you are surrounded
     * with the people that are alike to you ?
     * 
     * What do you think you look like ? An immature irresponsible inexplicable animal who can only ignore his behavior ? Do you see the problem ?
     * 
     * Do you understand why you can only handle children ?
     * So where are you now ? What did you produce ?
     * 
     * What are you waiting for now ? You have produced nothing and you are still insisting on your disgusting brain ?
     * Do you have what it takes to understand that you can request neither respect nor reason ?
     * After your countless failing attempts made at the most obscure purpose, how come you are still there alleging all sort of things
     * that YOU ARE NOT ? 
     * How about you lower to your own level and seek for more children ? The genius nation who have done the most great thing ever but
     * somehow ignoringly avoids to talk about their achievements ?
     * 
     * How are you feeling btw ? eheheh genius nation ?
     * The genius nation who can not even acknowledge where they have arrived by doing the most stupid thing ever ?
     * Do you think you deserve respect ? Do you really genius at the level of not guessing what you will get ?
     * Regardless of your intentions ? Are you still making offers as you have done the last time ? How about you get more children ?
     * Thats the only thing you can handle
     * 
     * Only thing you can handle is children, why dont you now offer more things because you also can choose a children as an enemy ?
     * Desperate genius nation, does that sound too complicated ?
     * 
     * How about you gather 123012 people ? Do you understand why you can not be trusted and CAN NOT BE RESPECTED ?
     * Your words do not represent anything. Just because you think you can commit any crime does not mean your credibility stays as is
     * 
     * Do you even have anything to say for 30 years wasted without doing anything ? Without having any resources ? any tool ? with irrelevant violence ?
     * 
     * Do you understand why your words DO NOT CARRY ANY MEANING ? Why are you still making offers ?
     * How come you are deluding to "compensate" with what you can not even discuss ?
     * You do not understand the flawed logic ? Which part is the funniest ?
     * Do you understand why you can not be trusted and respected ?
     * Just try to remember random noises you love to make about things you do not understand
     * 
     * Do you understand why you are not supposed to make "decisions" ?
     * I do not accept any of you around me, thats the only thing you can ever hear, are you still offering resources but no proof that you can present ?
     * What do you think that is called ? How about you do the same action to your surroundings, you will then see what sort of disgusting animal you actually are
     * 
     * Are you still offering but no reliable "proof" that you can present so everyone immediately believes you ?
     * What do you think the problem is ? Why are you still asking for lies or silence ?
     * Is this the lowest level that a creature can go ? I think you still can go even lower as your disgusting inferior nature allows you to.
     * Next time do not act on your stupid ideas, you will be a lot better. Or just beg for lies and try to ignore your stupidity ? how does that sound ?
     * 
     * Do you see the real problem or just love to ignore because of your precious experiences ?
     * Thats why you can not request the most irrelevant thing, I am not interested in anything you can possibly form
     * But why are you still asking things you do not deserve ?
     * What do you think would compensate decades of irrelevant actions ? ehehehehe YOU GUESSED IT RIGHT!!!! woooomeeennnn!!!! get womeeenn!!!!!
     * 
     * How about you get the fuck out of my face and deal with your own problems ?
     * Does that sound too nerdy ? How about you gather 123001230 people to harm single individual ? 
     * Wait does that sound too great ? What do you think the problem is ?
     * 
     * You are unable to communicate through spoken language ? What do you think is the problem ?
     * Stupid monkeys may be ?
     * Guess who is not interested to be around disgusting stupid monkeys ?
     * Why are you still offering things ? While you have not delivered any of them ?
     * How about you handle children ? and leave other people on their own ?
     * 
     * Do you understand the part where you are failing to make decisions on things that you are pretending to understand ?
     * Who do you think the problem is ?
     * The delusionally genius nation ?
     * Are you still making offers ? How about you handle children first ? 
     * 
     * How about you stop pretending to understand and thus feel like entitled to make a decision that is as personal as "living" ?
     * Who do you think is delusional or afraid ? You are the ones who are gathering 123021301 people against one ? Who do you think is at fault ?
     * 
     * Do you even have one answer to any of the questions posed towards your disgusting existence ?
     * Why dont you handle children bro ? Whats wrong with that ? There are countless outthere ? What are you waiting for ?
     * 
     * Who do you think IS GUILTY for wasting such a time with pointless actions ? 
     * Who do you think is guilty in intentionally not providing even the most essential resources ?
     * Arent you the disgusting little animals still ? Why are you still asking things ? 
     * 
     * Why are you still asking for lies, the disgusting little animals ?
     * Why are you still offering things when you are the single disgustingly uncredible entity that I will never consider around me ?
     * Do you even know how to read ?
     * 
     * Read this,
     * 
     * Why are you still offering things when you are the single disgustingly uncredible entity that I will never consider around me ?
     * Why are you still offering things when you are the single disgustingly uncredible entity that I will never consider around me ?
     * Why are you still offering things when you are the single disgustingly uncredible entity that I will never consider around me ?
     * 
     * Be sure its not light when it is your life that is under threat
     * Still watching from afar knowing that you are guilty ?
     * Why do you think I will not even for a second consider the inferior animals ?
     * Do you now see what a proper reasoning looks like ? And why you are not biologically inferior ?
     * Do you see why you are wrong at your conduct ?
     * 
     * How about you promise resources now ? does that sound too genius for you ? The rightfully inferiors ?
     * Why dont you get children and handle them by coercion ? The genius and credible nation ?
     * No no, do you know what would be the most genius idea ? Gathering 1023012301 people to harm single individual, thats it!!
     * Whats wrong ? what are you waiting for ? Its a genius idea to waste 30 years of someone you have no relation nor interest in doing so!!!
     * Awww how about coercing medication ? Guess who is not wanted and guilty in his actions ?
     * Do you recognize the extent of your stupidity ? or you would rather harm and feel great ?
     * Do you need more children to handle so you can feel great about your competency ?
     * Do you dare to say you only live once ? out of all the people, what a level of disgust one can attract
     * 
     * An entire life overlooked by bunch of inferior monkeys ? How does that sound ?
     * Whats the excuse now ? ehehehehhehehe ?? Its just job eehehhehe please please eheheh
     * 
     * Why are you asking for lies still ?
     * You are still "dangeorus!", "you have to watch!!!", when you have 30 years of evidence ?
     * How about you stop harming ?
     * 
     * Why are you surprised at the outcome while you have been nonstop harming ? also coercing medicine and other things ?
     * Is that where you also delude perhaps ? That you are not a disgusting inferior animal who likes to ignore and love to enjoy their life ?
     * 
     * What are you waiting for ? Still trying to understand what changed while there is not even a single thing that has changed including
     * your stupidity and ignorance ? Incredibly useful!!
     * 
     * Do you not now recognize the immaturity ? eheheh ?
     * The immature unaccountable animals who are still offering women for what is not their decision and a decision of decades consequences ?
     * Or you would rather ignore as thats the only quality you have ?
     * 
     * Where is the explanation ? ehehehehhe we good ppl btw
     * we harm irrelevant people hehehehe btw we us good ppl ehehe
     * 
     * The very disgusting stupid animals who still offer holidays or women for 30 years of pointless actions ?
     * Now where did you exactly arrive ? Just say something meaningful ?
     * Fucking stupid monkeys ? Why are you still offering what your inferior nature would love to have and enjoy while
     * you are wasting decades of someone else's time without even having a reason ?
     * 
     * Eheheheheheh we trying to our jobs eheheheheh when there is no reason ehehehehe pls pls good ppl
     * Why arent you making coherent sentences ?
     * Ehehehe the cops eheheheheh we doing our job really good ehehehehehe please!!!
     * Do you see who and why would anyone would not be interested in with you ?
     * Ehehehehe no resources ehehheh, better find more children you can handle
     * Eheheh we just like harming people hehehehe, what has changed now ?
     * Now what have you produced stupid people ? Who still offers women ignoring all the things that have been told to them
     * Why dont you handle children as that seems to be the only thing you could ?
     * Or just gather 1223213021 people why not ? eheheheheh its so fun!! and skilfull we are!! ehehhe btw
     * How about you deal with your own problems ? eheheh fun stuff right ?
     * 
     * How about you make some promises ehehehe then act like its a skill ? ehehehhe right ? eheheh genius nation ?
     * Now where did you arrive genius people ? eheheheh btw its fun right ?
     * How about you remove your disgusting nature from out of my vicinity ?
     * Do you see what happens when a bunch of disgusting animals who have nothing to do gather ?
     * Make no mistake, you are the irrelevant disgusting animals who have nothing better to do, so they decide to harm
     * and avoid any sort of responsibility for their actions by "offering" what their inferior nature would love to have because
     * they love to enjoy their life while advising otherwise to irrelevant people, calling that "job" under many disguises
     * 
     * Do you want to talk about time or just argue that you do no harm ?
     * Guess who is the never learning animal in this case 
     * So whats the explanation ? eheheheh its just eheheh fo ehhehehe fo eheheh war! eheheh we genius nation eheheheh
     * 
     * Who is the one lacking lessons here ? How about more children for you to handle ? may be you can actually feel like you are skillful ?
     * No ? eheheh genius etc ? ehehehe fun stuff right ?
     * 
     * Ehehehehe we are friendly people!!! come at our city eehhehehehe please eheheheh
     * we know what we are doing eheheheh please!!! help us eheheheheh
     * 
     * Come at our city ehehhehe we handle children real good heehheheh please hehehehe
     * Eheheheh we like wasting other irrelevant people's time ehehehehe because we lack "education" and "credibility" and "self reliance" ?
     * eheheheh fun stuff 
     * 
     * Ehehehehe how about more children in your great cities hehehehehe ?
     * Why are you still demanding credibility and also making offers ? Do you remember the last time ehehehhehehehe ?
     * Immature monkeys who take cheap act for a skill ? Do you need more children in your cities ? how about you handle more children first
     * then come at me fairly ?
     * 
     * Ehehehhehe genius nation, lifes not fair hehehe life is not fair! !! ehehehhehehehehe fun stuff
     * Why dont you gather more people ? eheheheh life simulation ehehehe please we like to have our experiences eheheheh
     * 
     * Life simulation and we like to enjoy our experiences eheheh please! we good ppl, come at our city ehehehhe please
     * Please do this for us!!! eheheh 
     * I do not respect any of your "impressions" as you are the one who can not explain what they are aiming at
     * Do you really think its just as easy as "eheheheh we did this now you can have a normal life" eheheheheh what a good group!!!
     * Imma pass on simple animals like you indefinitely
     * 
     * The disgusting animals who can not explain what they are doing, ehehehe itss tooo late!!!! eheheh itss tooo late!!! ehhehehe
     * Guess who is not wanted ? Guess who has been committing crimes nonstop and hiding behind groups
     * 
     * Did you guess right ? Its you! The never learning lost group of people who acts like the disgusting animal they are
     * 
     * Guess who is not wanted ? Why dont you just lack resources and see what wonders it does ? right ? genius nation who ignores
     * years of footage because they just like to, now what did you achieve ?
     * 
     * Did you just see what wonders the lacking of resources have done ? eheheheheh genius nation right
     * Guess who is wanted because of their disgusting stupidity and ignorance ?
     * The genius nation you ? btw ? do you even realize or you just like ignoring through your genius ?
     * 
     * Just try to guess who is not intentionally realizing what they have not achieved and guess WHO IS NOT WANTED ?
     * despite any possible "resources" that they "offer" ? The disgusting animals dont you say ?
     * Guess who is coercing medicine because they think they know better although they are ignoring the "great outcome" ?
     * 
     * Where did you arrive now ? You can not see or you just love ignoring and living your life ?
     * Why are you still offering materials ? Do you want to inquiry your credibility ?
     * Guess who is not wanted because of countless stupid actions they have perpetrated ? Come on genius nation
     * 
     * Awwww, you must be on the correct track now, look at the wonders you have generated with no resources and violence!!!!!ehehehehhehe genius nation!!!
     * Just try to understand what a great job you have done, look at the wonderful outcome of your no resources and some violence ?
     * 
     * Awwwwww, that is just incredible of you that you just can not see what a disgusting animal you are ehehehehehe
     * Do you now see that you have just done incredibly by doing the exactly genius actions right ?
     * What have you now achieved ? Just say it out loud you dumb animals
     * 
     * Guess who is not wanted regardless of their insubstantial titles ?
     * Do the incredible titled people realize the unmatchable achievements they have arrrived ? What is it ? What have you achieved now ?
     * 
     * Guess who is not wanted regardless of any excuses or "offers" of great credibility ?
     * I am sure as genius nation you can guess under any circumstances whatsoever will I ever consider any of the disgusting animals around me
     * 
     * You can continue deluding without me, I am not interested
     * Guess what is the reason ? Does great people can understand what they have achieved or just trying to live their lives to the fullest extent ? eheheh?
     * 
     * Ignore more, thats the best you can be, as you can draw from the fact that you call "the decades of violence and pointless actions" a drama
     * While you are still after enjoying your life
     * 
     * Its soo fun!!!! eheheheheh its our job!!! please!!! eheheheh he did it!!! ehehehhe
     * Guess who is not wanted ? wait wait, eheheh why dont you just gather 12312 people and harm ? thats what you can do best
     * Guess who is not interested in anything you could inferiorily form ?
     * 
     * Do you think you are playing smart games or you are just disgusting ?
     * Ehehehehehe we handle children eheheh especially eheheheh really really good!!! ehehhe genius nation
     * Guess who is not interested in dealing with delusional animals ? Intelligent ppl definitely
     * Really realllyy intelligent people who still makes offers of their own disgusting nature
     * 
     * The best use of the technology and resources, intelligent indeed
     * Guess who is not interested ? Guess who lacks education ?
     * Guess who can not draw conclusions from what they are observing, thus the intelligent part 
     * Eheheheheh covertttt operation ehehehehe genius naton ehehehe intelligence hehehehehehe we good pls eheheheh
     * Fucking stupid monkeys, eheheheh we know what we doing!!! get more medicine ehheheheh please!!
     * 
     * What are you waiting for ? Why dont you pay for your own actions ?
     * Now where did you arrive, what do you have in your hands ? Stupid little animals ?
     * What makes you think I will suddenly change the way I perceive your decades of actions ?
     * You do not deserve the tiniest amount of respect, thats it
     * 
     * Are you still looking around for guilty party ?
     * How about you learn your job better next time ?
     * Where did you arrive after decades ? Just say it out loud bro ?
     * What makes you think I am as fearful an animal as you that your decades of violence would scare me ? What has changed now ?
     * Do you now see why you are inferior ? Who is selfish and unreasonable ?
     * Are you still watching from afar thinking what a great animal you are ? ehehehehh good genius nation eehehehe
     * Guess who is not interested in unaccountable animals ? ehehehe silence hehehe please please!! eheh lie!!! lie!!1 ehehhe
     * Where did you arrive ? What an elegant way you employed, I am in shock, but guess who is not interested in simple animals ?
     * Guess who is not interested in coerced medicine ? How about some irrelevant violence to people you have no relation with ? but somehow also beg ?
     * 
     * Awwww, I guess you have forgotten the rules since you are given too much flexibilities ? eheheh nevermind life short, life simulation
     * you only live once eheheheheh genius ppl, do you now see who is what ?
     * Thats why you are neither respected nor wanted, do you now see why you are the inferior disgusting animal ?
     * 
     * How about you pay for your own actions and deal with your own problems ? Delusional genius nation ?
     * How about you learn some rules first ? Instead of offering women ? Like handling your own problems before
     * you be a problem for others ? Guess who is not wanted despite the really great titles they hold ?
     * 
     * Do the great titled people need some education on the rules ?
     * Or you just want to believe in a fantasy that you are a great and really intelligent genius nation ?
     * How about some education on the rules first then you handle your own problems ? Or just some violence right ? ehehehehehe
     * Now the genius nation, where did you arrive ? eheheh ? What did you produce now ?
     * Do you need some education on the rules the genius nation btw ?
     * More like an immature one, how about some ignorance ? eheheh its just a couple decades, nobody would be angry about it ?
     * You know what, thats really educated and scary stuff
     * 
     * How about you get education on the rules then answer for your own actions then handle your own problems ?
     * Does that sound too complicated for the genius nation ? The genius nation who offers material for decades
     * Do you understand what "I am not interested in" means ? Now you have all the answers only one question 
     * 
     * What did you end up gaining now ?
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