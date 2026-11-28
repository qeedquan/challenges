/*

This a simple question.

The start day is a Saturday and let the input be a non-negative number x.

The output should be the number of weekdays (Mon-Fri) in the next x days inclusive.

For example, if x = 3 then the output should be 2. For x from 0 onwards the output should be:

0,0,1,2,3,4,5,5,5,6,7,8,9,10,10,10,11,...
—-—

Now I am regretting not having asked the question for a user specified day of the week instead of just Saturday. It’s too late to change the question now and a new question would probably be marked as a duplicate. If anyone wanted to add an answer for this extension, I would love to see it.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@xnor

lambda x:x*6/7-x/7
Found by brute-forcing. x*6/7 counts non-Sundays, and -x/7 subtracts the number of Saturdays.

all          x       0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 ...

all - Sun  = x*6/7   0  0  1  2  3  4  5  6  6  7  8  9 10 11 12 12 13 ...
Sat        = x/7     0  0  0  0  0  0  0  1  1  1  1  1  1  1  2  2  2 ...
all - Sun - Sat      0  0  1  2  3  4  5  5  5  6  7  8  9 10 10 10 11 ...
Brute-forcing suggests that this is the unique arithmetical solution of this length or shorter, subject to some limitations like not using parens, using only single-digit constants, and not having too-large intermediate results.

lambda x:x-x/7+-x/7

Found by brute-forcing. But, it has a nice interpretation. x counts all x days. Then -x/7 subtracts the number of Sundays in those x days, and +-x/7 subtracts the number of Saturdays. Note that there's a difference in Python between subtracting x/7 and adding -x/7 aka (-x)/7, because floor-div is not symmetric around zero since it always round down.

all =   x        0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 ...
Sun =   x/7      0  0  0  0  0  0  0  1  1  1  1  1  1  1  2  2  2 ...
Sat = -(-x/7)    0  1  1  1  1  1  1  1  2  2  2  2  2  2  2  3  3 ...

all - Sun - Sat  0  0  1  2  3  4  5  5  5  6  7  8  9 10 10 10 11 ...

lambda x:x*5/7+x%7/4

I found this by hand, noting that f(x) increases asymptotically with slope 5/7 and
seeing that the difference to x*5/7 (with floor-division) has a nice period-7 form.

*/

int
wd(int x)
{
	return (x * 6 / 7) - (x / 7);
}

int
main()
{
	static const int tab[] = {
		0, 0, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10, 10, 10, 11
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(wd(i) == tab[i]);

	return 0;
}
