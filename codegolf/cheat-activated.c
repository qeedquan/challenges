/*

Background

The game Grand Theft Auto: San Andreas went down in history also thanks to its wide selection of cheats. They're almost 90 and anyone who has ever touched this game, no doubt has tried them all!
One cheat is activated (on PC) typing in-game a secret keyword, and then boom, a jet pops out of thin air or perhaps all pedestrians look like Elvis Presley or some other rowdy effect...

They always come with this confirmation message:

enter image description here

Rockstar chose to store them hashed, so due to collisions, in addition to the intended ones there are many other strings that trigger each cheat.

Therefore I propose to solve this downside!
Task

Write a full program that prints CHEAT ACTIVATED if and only if the last part of a string is a cheat code.
Cheat codes

THUGSARMOURY
PROFESSIONALSKIT
NUTTERSTOYS
INEEDSOMEHELP
TURNUPTHEHEAT
TURNDOWNTHEHEAT
PLEASANTLYWARM
TOODAMNHOT
DULLDULLDAY
STAYINANDWATCHTV
CANTSEEWHEREIMGOING
TIMEJUSTFLIESBY
SPEEDITUP
SLOWITDOWN
ROUGHNEIGHBOURHOOD
STOPPICKINGONME
SURROUNDEDBYNUTTERS
TIMETOKICKASS
OLDSPEEDDEMON
DOUGHNUTHANDICAP
NOTFORPUBLICROADS
JUSTTRYANDSTOPME
WHERESTHEFUNERAL
CELEBRITYSTATUS
TRUEGRIME
ALLCARSGOBOOM
WHEELSONLYPLEASE
STICKLIKEGLUE
GOODBYECRUELWORLD
DONTTRYANDSTOPME
ALLDRIVERSARECRIMINALS
PINKISTHENEWCOOL
SOLONGASITSBLACK
FLYINGFISH
WHOATEALLTHEPIES
BUFFMEUP
LEANANDMEAN
BLUESUEDESHOES
ATTACKOFTHEVILLAGEPEOPLE
LIFESABEACH
ONLYHOMIESALLOWED
BETTERSTAYINDOORS
NINJATOWN
LOVECONQUERSALL
EVERYONEISPOOR
EVERYONEISRICH
CHITTYCHITTYBANGBANG
CJPHONEHOME
JUMPJET
IWANTTOHOVER
TOUCHMYCARYOUDIE
SPEEDFREAK
BUBBLECARS
NIGHTPROWLER
DONTBRINGONTHENIGHT
SCOTTISHSUMMER
SANDINMYEARS
KANGAROO
NOONECANHURTME
MANFROMATLANTIS
LETSGOBASEJUMPING
ROCKETMAN
IDOASIPLEASE
BRINGITON
STINGLIKEABEE
IAMNEVERHUNGRY
STATEOFEMERGENCY
CRAZYTOWN
TAKEACHILLPILL
FULLCLIP
IWANNADRIVEBY
GHOSTTOWN
HICKSVILLE
WANNABEINMYGANG
NOONECANSTOPUS
ROCKETMAYHEM
WORSHIPME
HELLOLADIES
ICANGOALLNIGHT
PROFESSIONALKILLER
NATURALTALENT
OHDUDE
FOURWHEELFUN
HITTHEROADJACK
ITSALLBULL
FLYINGTOSTUNT
MONSTERMASH

Input

    A string s

    over the alphabet:
    [A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z]

Output

    Print CHEAT ACTIVATED if there exists a cheat code c

such that c is a suffix of s

    Nothing otherwise

This is code-golf, so the shortest code wins.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
activate(const char *s)
{
	static const char *tab[] = {
	    "THUGSARMOURY",
	    "PROFESSIONALSKIT",
	    "NUTTERSTOYS",
	    "INEEDSOMEHELP",
	    "TURNUPTHEHEAT",
	    "TURNDOWNTHEHEAT",
	    "PLEASANTLYWARM",
	    "TOODAMNHOT",
	    "DULLDULLDAY",
	    "STAYINANDWATCHTV",
	    "CANTSEEWHEREIMGOING",
	    "TIMEJUSTFLIESBY",
	    "SPEEDITUP",
	    "SLOWITDOWN",
	    "ROUGHNEIGHBOURHOOD",
	    "STOPPICKINGONME",
	    "SURROUNDEDBYNUTTERS",
	    "TIMETOKICKASS",
	    "OLDSPEEDDEMON",
	    "DOUGHNUTHANDICAP",
	    "NOTFORPUBLICROADS",
	    "JUSTTRYANDSTOPME",
	    "WHERESTHEFUNERAL",
	    "CELEBRITYSTATUS",
	    "TRUEGRIME",
	    "ALLCARSGOBOOM",
	    "WHEELSONLYPLEASE",
	    "STICKLIKEGLUE",
	    "GOODBYECRUELWORLD",
	    "DONTTRYANDSTOPME",
	    "ALLDRIVERSARECRIMINALS",
	    "PINKISTHENEWCOOL",
	    "SOLONGASITSBLACK",
	    "FLYINGFISH",
	    "WHOATEALLTHEPIES",
	    "BUFFMEUP",
	    "LEANANDMEAN",
	    "BLUESUEDESHOES",
	    "ATTACKOFTHEVILLAGEPEOPLE",
	    "LIFESABEACH",
	    "ONLYHOMIESALLOWED",
	    "BETTERSTAYINDOORS",
	    "NINJATOWN",
	    "LOVECONQUERSALL",
	    "EVERYONEISPOOR",
	    "EVERYONEISRICH",
	    "CHITTYCHITTYBANGBANG",
	    "CJPHONEHOME",
	    "JUMPJET",
	    "IWANTTOHOVER",
	    "TOUCHMYCARYOUDIE",
	    "SPEEDFREAK",
	    "BUBBLECARS",
	    "NIGHTPROWLER",
	    "DONTBRINGONTHENIGHT",
	    "SCOTTISHSUMMER",
	    "SANDINMYEARS",
	    "KANGAROO",
	    "NOONECANHURTME",
	    "MANFROMATLANTIS",
	    "LETSGOBASEJUMPING",
	    "ROCKETMAN",
	    "IDOASIPLEASE",
	    "BRINGITON",
	    "STINGLIKEABEE",
	    "IAMNEVERHUNGRY",
	    "STATEOFEMERGENCY",
	    "CRAZYTOWN",
	    "TAKEACHILLPILL",
	    "FULLCLIP",
	    "IWANNADRIVEBY",
	    "GHOSTTOWN",
	    "HICKSVILLE",
	    "WANNABEINMYGANG",
	    "NOONECANSTOPUS",
	    "ROCKETMAYHEM",
	    "WORSHIPME",
	    "HELLOLADIES",
	    "ICANGOALLNIGHT",
	    "PROFESSIONALKILLER",
	    "NATURALTALENT",
	    "OHDUDE",
	    "FOURWHEELFUN",
	    "HITTHEROADJACK",
	    "ITSALLBULL",
	    "FLYINGTOSTUNT",
	    "MONSTERMASH",
	};

	size_t i, n;
	char *p;

	for (i = 0; i < nelem(tab); i++) {
		p = strstr(s, tab[i]);
		if (!p)
			continue;

		n = strlen(tab[i]);
		if (p[n] == '\0') {
			printf("CHEAT ACTIVATED\n");
			break;
		}
	}
}

int
main(void)
{
	activate("MONSTERMASH");
	activate("FLYINGTOSTUNT");
	activate("ITSALLBULLL");

	return 0;
}
