/*

A triangle-shaped table is constructed such the first row is "1, 3, 5, 7, ..., 99"

Each subsequent row has the following properties:

One less element than the row above
Each element is the sum of the two elements above it
Like so:

1   3   5    7    9    11 ....
  4   8   12   16   20 ....
    ...............
This continues until the last row with one element.

How many elements are divisible by 67?

Fewest lines, chars, or whatever may win. Depends on ingenuity.

EDIT: the answer is 17 but you have to prove it.

ADDENDUM: I have three-line python code for this but try to beat it:

a = [[2*i+1 for i in range(50)]]
while len(a[-1])>1:a.append([a[-1][i]+a[-1][i+1] for i in range(len(a[-1])-1)])
print len([i for b in a for i in b if i%67==0])

*/

#include <assert.h>

typedef long long vlong;

vlong
solve()
{
	vlong cur;
	vlong add;
	vlong start;
	vlong end;
	vlong ret;
	vlong i;

	start = 1;
	add = 2;
	ret = 0;
	for (end = 50; end > 0; end--) {
		cur = start;
		for (i = 1; i <= end; i++) {
			if (!(cur % 67))
				ret++;
			cur += add;
		}
		start += start + add;
		add *= 2;
	}
	return ret;
}

int
main()
{
	assert(solve() == 17);
	return 0;
}
