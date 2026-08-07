/*

Task
You are given a moment in time and space. What you must do is break it down into time and space, to determine if that moment is from the past, present or future.

Time is the sum of characters that increase time (i.e. numbers in range ['1'..'9'].

Space in the number of characters which do not increase time (i.e. all characters but those that increase time).

The moment of time is determined as follows:

 If time is greater than space, then the moment is from the future. If time is less than space, then the moment is from the past. Otherwise, it is the present moment.

You should return an array of three elements, two of which are false, and one is true. The true value should be at the 1st, 2nd or 3rd place for past, present and future respectively.

Examples
For moment = "01:00 pm", the output should be [true, false, false].

time equals 1, and space equals 7, so the moment is from the past.

For moment = "12:02 pm", the output should be [false, true, false].

time equals 5, and space equals 5, which means that it's a present moment.

For moment = "12:30 pm", the output should be [false, false, true].

time equals 6, space equals 5, so the moment is from the future.

Input/Output
[input] string moment

The moment of time and space that the input time came from.

[output] a boolean array

Array of three elements, two of which are false, and one is true. The true value should be at the 1st, 2nd or 3rd place for past, present and future respectively.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
moment(const char *s, bool r[3])
{
	size_t p, t;

	for (p = t = 0; *s; s++) {
		if ('1' <= *s && *s <= '9')
			t += *s - '0';
		else
			p += 1;
	}

	r[0] = r[1] = r[2] = false;
	if (t < p)
		r[0] = true;
	else if (t == p)
		r[1] = true;
	else
		r[2] = true;
}

void
test(const char *s, bool r[3])
{
	bool x[3];

	moment(s, x);
	assert(!memcmp(x, r, sizeof(x)));
}

int
main()
{
	bool r1[] = { true, false, false };
	bool r2[] = { false, true, false };
	bool r3[] = { false, false, true };
	bool r4[] = { false, false, true };
	bool r5[] = { false, false, true };
	bool r6[] = { false, true, false };

	test("01:00 pm", r1);
	test("12:02 pm", r2);
	test("12:30 pm", r3);
	test("11:12 am", r4);
	test("05:20 pm", r5);
	test("04:20 am", r6);

	return 0;
}
