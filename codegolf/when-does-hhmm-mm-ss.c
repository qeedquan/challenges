/*

Let's begin with a thought experiment. You have a clock and a timer, in which you start the timer when the clock shows exactly hh:mm.00.

Clock: The clock employs 24-hour time. So the range of hh is 0<=h<23. (Because 23 inputs are unsolvable, you aren't required to handle that)
Timer: It starts exactly on 00.00. The number to the right of . isn't milliseconds; it's seconds.
What you need to do is to find out when the two numbers represented by clock time (hh:mm) is respectively equal to the timer time (mm.ss); e.g. 13:24 is "respectively equal" to 13.24. There can potentially be more than one time.

An example
Say the input is 1:59.

Clock: 1:59
Timer: 0.00   (The timer just started)

...
Clock: 1:59
Timer: 0.59   (59 seconds later...)

...

Clock: 2:00
Timer: 1.00   (As the timer's second section rounds up to the minute section, the clock time gets incremented by a minute. And the 59 minutes in the clock section gets rounded up to the hour section, hence the 2:00.)

...
Clock: 2:00
Timer: 1.59 (59 seconds later...)

...
Clock: 2:01
Timer: 2.00 (The timer minute gets rounded up, as the clock time increments by a minute)

...
Clock: 2:01
Timer: 2.01 (Now the clock time is "respectively equal" to the timer time)
Therefore you need to output 2:01 for the 1:59 input.

Examples
Here is a sample program I use to check my test cases.

0:59 -> 0:59 (or 1:00, if your answer supports that)
1:30 -> 1:31
2:59 -> 3:02
1:59 -> 2:01
3:58 -> 4:02
22:01->22:23

Specifications
Although in the test cases, the input is taken as hh:mm, you can nevertheless take input in a list, e.g. [hh,mm], or any format suitable for your answer.
You can output the time in the format [mm,ss].
You could start two physical timers, but you need to optimize their speed somehow. Your code running all of the test cases must terminate in 60 seconds.
You are allowed to take input/output as base 60.
You don't need to handle unsolvable inputs. I.e. The hour section in the clock will never be 23.
If you find more than one time for a specific test case, you can output any of them.

*/

#include <assert.h>
#include <stdio.h>

void
equivalent(int h, int m, int *mm, int *ss)
{
	*mm = h + (h + m) / 60;
	*ss = (*mm + m) % 60;
}

void
test(int h, int m, int mmr, int ssr)
{
	int mm, ss;

	equivalent(h, m, &mm, &ss);
	printf("%d:%02d -> %d:%02d\n", h, m, mm, ss);
	assert(mm == mmr);
	assert(ss = ssr);
}

int
main()
{
	test(0, 59, 0, 59);
	test(1, 30, 1, 31);
	test(2, 59, 3, 2);
	test(1, 59, 2, 1);
	test(3, 58, 4, 2);
	test(22, 1, 22, 23);

	return 0;
}
