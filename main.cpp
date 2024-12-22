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
     * Have you ever seen disappointed people who are trying to ignore their stupidity ? Just have a look around
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