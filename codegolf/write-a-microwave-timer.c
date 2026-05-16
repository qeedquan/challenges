/*

You are an employee of Microteque, a leading Silicon Valley startup creating smart microwave ovens for all kinds of strange places. Your customers can get their microwaves printed with patterns to match their kitchens, campers, man caves; even the kitchens of large nation-state facilities have shiny new branded microwave ovens.

Due to the cutting-edge nature of your microwave control board technology, you've ended up having to use the programming language MicrowaveX* and you're working out how to program the time counter. Your counter looks like this:

https://i.stack.imgur.com/M86e4.png

Your goal is to write a program that takes the input time and translates it into the number of seconds that the microwave needs to run.

As input, the function must take a string in the format ##:## (including the colon at position 3) and return an integer.

Please note that it should also be able to handle more than 60 seconds in the seconds slot.

Finally, due to some pesky regulations, you cannot have your microwave oven run for more than 100 minutes (6,000 seconds)

Sample inputs and outputs:

01:30 --> 90 seconds

00:66 --> 66 seconds

01:99 --> 159 seconds

02:39 --> 159 seconds

99:99 --> 6,000 seconds (capped at 100 minutes due to aforementioned regulations)

*: MicrowaveX happens to be identical to your programming language of choice, but Microteque has rebranded it to sound more appealing to their investors.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
microwave(const char *t)
{
	static const unsigned maxtime = 6000;
	unsigned m, s;

	if (sscanf(t, "%u:%u", &m, &s) != 2)
		return -1;

	return min((m * 60) + s, maxtime);
}

int
main(void)
{
	assert(microwave("01:30") == 90);
	assert(microwave("00:66") == 66);
	assert(microwave("01:99") == 159);
	assert(microwave("02:39") == 159);
	assert(microwave("99:99") == 6000);

	return 0;
}
