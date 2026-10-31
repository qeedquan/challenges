/*

I'm hungry. Let's microwave something. Given a numerical input of between 1 and 4 digits, output the number of seconds that the microwave should run.

Details
The trick is figuring out if the user is inputting seconds or a combination of seconds and minutes. The ones and the tens places should be interpreted as seconds and the hundreds and thousands places should be minutes. For example, the value 1234 should be interpreted as 12 minutes, 34 seconds and 9876 should be 98 minutes, 76 seconds. Typing 130 and 90 should both result in a cook time of 90 seconds.

Here are a few other inputs and outputs:

1 = 1
11 = 11
111 = 71
1111 = 671
9 = 9
99 = 99
999 = 639
9999 = 6039

Rules
This is code-golf, so the shortest program in bytes wins. Standard loopholes are not allowed. The winning entry must return the right answer when given any integer input from 1 to 9999.

*/

#include <assert.h>

int
cooktime(int n)
{
	int m, s;

	if (n < 1 || n > 9999)
		return -1;

	m = (n / 100) * 60;
	s = n % 100;
	return m + s;
}

int
main(void)
{
	assert(cooktime(1) == 1);
	assert(cooktime(11) == 11);
	assert(cooktime(111) == 71);
	assert(cooktime(1111) == 671);
	assert(cooktime(9) == 9);
	assert(cooktime(99) == 99);
	assert(cooktime(999) == 639);
	assert(cooktime(9999) == 6039);

	return 0;
}
