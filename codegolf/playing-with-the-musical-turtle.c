/*

My two kids like to play with the following toy:

https://i.stack.imgur.com/BYhak.jpg

The colored areas with the shapes inside can be touched and the turtle then lights the area and plays a sound or says the name of the color or the shape inside. The middle button changes the mode. There is one mode in which the areas play different musical notes when touched, with a twist: if the kid touches three consecutive areas clockwise, a special melody 1 is played. If the three consecutive areas touched are placed counterclockwise, a special melody 2 is played.

The challenge
Let's simulate the internal logic of the toy. Given a string with 3 presses of the kid, return two distinct, coherent values if the three presses are for consecutive areas (clockwise or counterclockwise) and a third distinct value if they are not.

Details
The input areas will be named with a character each, which can be their color: ROYGB for red, orange, yellow, green and blue; or their shape: HSRTC for heart, square, star (R), triangle and circle. Case does not matter, you can choose to work with input and output just in uppercase or in lowercase.
The program will receive a string (or char array or anything equivalent) with three presses. Examples (using the colors): RBO, GYO, BBR, YRG, YGB, ORB...
The program will output three distinct, coherent values to represent the three possible outcomes: a first value if the combination does not trigger a special melody, a second value if the combination triggers the clockwise special melody, and a third value if the combination triggers the counterclockwise special melody. Example: 0 for no special combination, 1 for the melody triggered by a clockwise combination and -1 for the melody triggered by a counterclockwise combination.
You do not need to worry about handling wrong input.
Test cases
Input   Output      // Input based on colors
--------------
RBO     0           // No special combination
GYO     -1          // Counterclockwise melody triggered
BBR     0           // No special combination
YRG     0           // No special combination
YGB     1           // Clockwise melody triggered
ORB     -1          // Counterclockwise melody triggered
OOO     0           // No special combination
BRO     1           // Clockwise melody triggered
                                        //
This is code-golf, so may the shortest code for each language win!

*/

#include <assert.h>
#include <string.h>

int
melody(const char *s)
{
	static const char comb[] = "ROYGBRO ORBGYOR";

	char *p;

	p = strstr(comb, s);
	if (!p)
		return 0;

	switch ((p - comb) / 7) {
	case -1:
		return 0;
	case 0:
		return 1;
	}
	return -1;
}

int
main(void)
{
	assert(melody("RBO") == 0);
	assert(melody("GYO") == -1);
	assert(melody("BBR") == 0);
	assert(melody("YRG") == 0);
	assert(melody("YGB") == 1);
	assert(melody("ORB") == -1);
	assert(melody("OOO") == 0);
	assert(melody("BRO") == 1);

	return 0;
}
