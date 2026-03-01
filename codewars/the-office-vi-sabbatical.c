/*

Learning to code around your full time job is taking over your life. You realise that in order to make significant steps quickly, it would help to go to a coding bootcamp in London.

Problem is, many of them cost a fortune, and those that don't still involve a significant amount of time off work - who will pay your mortgage?!

To offset this risk, you decide that rather than leaving work totally, you will request a sabbatical so that you can go back to work post bootcamp and be paid while you look for your next role.

You need to approach your boss. Her decision will be based on three parameters:

val = your value to the organisation
happiness = her happiness level at the time of asking and finally
The numbers of letters from 'sabbatical' that are present in string s.

Note that if s contains three instances of the letter 'l', that still scores three points, even though there is only one in the word sabbatical.

If the sum of the three parameters (as described above) is > 22, return 'Sabbatical! Boom!', else return 'Back to your desk, boy.'.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
sabbatical(const char *string, int value, int happiness)
{
	int count;

	for (count = 0; *string; string++) {
		if (strchr("sabticl", *string))
			count += 1;
	}

	if (value + happiness + count > 22)
		return "Sabbatical! Boom!";
	return "Back to your desk, boy.";
}

void
test(const char *string, int value, int happiness, const char *expected)
{
	const char *result;

	result = sabbatical(string, value, happiness);
	assert(!strcmp(result, expected));
}

int
main()
{
	test("Can I have a sabbatical?", 5, 5, "Sabbatical! Boom!");
	test("Why are you shouting?", 7, 2, "Back to your desk, boy.");
	test("What do you mean I cant learn to code??", 8, 9, "Sabbatical! Boom!");
	test("Please calm down", 9, 1, "Back to your desk, boy.");

	return 0;
}
