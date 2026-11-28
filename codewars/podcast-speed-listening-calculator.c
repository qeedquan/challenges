/*

If you have ever listened to an audiobook or podcast, you may have had the option to change the play speed of the audio. This allows you to increase or decrease the speed that you listen to your content.

I want you to calculate the time it takes to listen to the audio when the play speed is varied. The time should be rounded down to whole seconds.

The inputs will be:

audioLength // a string of the total time of the audio, "hh:mm:ss"

playSpeed // a float between 0.5 and 3.0, only to 1 decimal point

Examples:

// The results of calculations on the time units are expected to be truncated/floored

speedListen("00:00:55", 2) => "00:00:27" // NOT "00:00:28"

speedListen("01:20:00", 1.5) => "00:53:20"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int
audible2duration(const char *audible)
{
	int hour, minute, second;

	if (sscanf(audible, "%02d:%02d:%02d", &hour, &minute, &second) != 3)
		return -1;
	return (hour * 3600) + (minute * 60) + second;
}

void
duration2audible(double duration, char *output)
{
	int hour, minute, second;

	hour = duration / 3600;
	minute = duration / 60;
	second = fmod(duration, 60);
	sprintf(output, "%02d:%02d:%02d", hour, minute, second);
}

char *
speedlisten(const char *audible, double playspeed, char *output)
{
	int duration;

	duration = audible2duration(audible);
	if (duration < 0)
		return NULL;

	duration2audible(floor(duration / playspeed), output);
	return output;
}

void
test(const char *audible, double playspeed, const char *expected)
{
	char output[128];

	assert(speedlisten(audible, playspeed, output));
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("00:00:55", 2, "00:00:27");
	test("01:20:00", 1.5, "00:53:20");

	return 0;
}
