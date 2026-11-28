/*

Challenge
Given a single letter (a-z) as input, output the 2 lines of Blackalicious' Alphabet Aerobics that correspond to that letter (ignoring the intro & outro).

Rules
You may take input by any reasonable, convenient means as long as it's permitted by standard I/O rules.
Input must either be case insensitive or consistently uppercase or lowercase.
Output may be a newline separated string or an array/list of two strings.
Output must be formatted (capitalisation, punctuation, etc.) exactly as it appears in the test cases below.
Trailing spaces and newlines are not allowed.
This is code-golf so lowest byte count wins.

Test Cases
Each code block below is what should be output for each letter a-z, respectively.

Artificial amateurs, aren't at all amazing
Analytically, I assault, animate things
Broken barriers bounded by the bomb beat
Buildings are broken, basically I'm bombarding
Casually create catastrophes, casualties
Canceling cats got they canopies collapsing
Detonate a dime of dank daily doin' dough
Demonstrations, Don Dada on the down low
Eating other editors with each and every energetic
Epileptic episode, elevated etiquette
Furious, fat, fabulous, fantastic
Flurries of funk felt feeding the fanatics
Gift got great, global goods gone glorious
Gettin' godly in his game with the goriest
Hit em high, hella height, historical
Hey holocaust hints, hear 'em holler at your homeboy
Imitators idolize, I intimidate
In a' instant, I'll rise in a' irate state
Juiced on my jams like Jheri curls jockin' joints
Justly, it's just me, writing my journals
Kindly I'm kindling all kinds of ink on
Karate kick type Brits in my kingdom
Let me live a long life, lyrically lessons is learned
Lame louses just lose to my livery
My mind makes marvelous moves, masses
Marvel and move, many mock what I've mastered
Niggas nap knowing I'm nice, naturally
Knack, never lack, make noise nationally
Operation, opposition, off not optional
Out of sight, out of mind, wide beaming opticals
Perfected poem, powerful punchlines
Pummeling Petty powder puffs in my prime
Quite quaint quotes keep quiet it's Quannum
Quarrelers ain't got a quarter of what we got, uh
Really raw raps, risin up rapidly
Riding the rushing radioactivity
Super scientifical sound search sought
Silencing super fire saps that are soft
Tales ten times talented, too tough
Take that, challengers, get a tune up
Universal, unique, untouched
Unadulterated, the raw uncut
Verb vice lord victorious valid
Violate vibes that are vain, make em vanish
Why I'm all well, what a wise wordsmith just
Weaving up words, weeded up on my workshift
Xerox, my X-radiation holes extra large
X-height letters and xylophone tones
Yellow-back, yak mouth, young ones' yaws
Yesterday's lawn yardsale, I yawned
Zig-Zag zombies, zooming to the zenith
Zero in, zen thoughts, overzealous rhyme ZEA-LOTS!

*/

#include <stdio.h>

void
aerobics(int c)
{
	static const char *lyrics[] = {
	    "Artificial amateurs, aren't at all amazing",
	    "Analytically, I assault, animate things",
	    "Broken barriers bounded by the bomb beat",
	    "Buildings are broken, basically I'm bombarding",
	    "Casually create catastrophes, casualties",
	    "Canceling cats got they canopies collapsing",
	    "Detonate a dime of dank daily doin' dough",
	    "Demonstrations, Don Dada on the down low",
	    "Eating other editors with each and every energetic",
	    "Epileptic episode, elevated etiquette",
	    "Furious, fat, fabulous, fantastic",
	    "Flurries of funk felt feeding the fanatics",
	    "Gift got great, global goods gone glorious",
	    "Gettin' godly in his game with the goriest",
	    "Hit em high, hella height, historical",
	    "Hey holocaust hints, hear 'em holler at your homeboy",
	    "Imitators idolize, I intimidate",
	    "In a' instant, I'll rise in a' irate state",
	    "Juiced on my jams like Jheri curls jockin' joints",
	    "Justly, it's just me, writing my journals",
	    "Kindly I'm kindling all kinds of ink on",
	    "Karate kick type Brits in my kingdom",
	    "Let me live a long life, lyrically lessons is learned",
	    "Lame louses just lose to my livery",
	    "My mind makes marvelous moves, masses",
	    "Marvel and move, many mock what I've mastered",
	    "Niggas nap knowing I'm nice, naturally",
	    "Knack, never lack, make noise nationally",
	    "Operation, opposition, off not optional",
	    "Out of sight, out of mind, wide beaming opticals",
	    "Perfected poem, powerful punchlines",
	    "Pummeling Petty powder puffs in my prime",
	    "Quite quaint quotes keep quiet it's Quannum",
	    "Quarrelers ain't got a quarter of what we got, uh",
	    "Really raw raps, risin up rapidly",
	    "Riding the rushing radioactivity",
	    "Super scientifical sound search sought",
	    "Silencing super fire saps that are soft",
	    "Tales ten times talented, too tough",
	    "Take that, challengers, get a tune up",
	    "Universal, unique, untouched",
	    "Unadulterated, the raw uncut",
	    "Verb vice lord victorious valid",
	    "Violate vibes that are vain, make em vanish",
	    "Why I'm all well, what a wise wordsmith just",
	    "Weaving up words, weeded up on my workshift",
	    "Xerox, my X-radiation holes extra large",
	    "X-height letters and xylophone tones",
	    "Yellow-back, yak mouth, young ones' yaws",
	    "Yesterday's lawn yardsale, I yawned",
	    "Zig-Zag zombies, zooming to the zenith",
	    "Zero in, zen thoughts, overzealous rhyme ZEA-LOTS!",
	};

	int i;

	if (!('a' <= c && c <= 'z'))
		return;

	i = (c - 'a') * 2;
	puts(lyrics[i]);
	puts(lyrics[i + 1]);
}

int
main(void)
{
	int c;

	for (c = 'a'; c <= 'z'; c++) {
		aerobics(c);
		puts("");
	}

	return 0;
}
