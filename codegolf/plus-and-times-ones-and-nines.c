/*

Implement this recurrence relation as a function or program that inputs and outputs a non-negative integer:

F(0) = 0

F(N) = the smallest integer greater than F(N-1) such that the sum and/or product of its base-10 digits is N

N is your program's input and F(N) its output.

To be clear, the sum of the digits in a number like 913 is 9+1+3=13. The product is 9×1×3=27. For single-digit numbers, the sum and product is the same number. Numbers that contain a 0 of course have product 0.

The results through F(70) are:

N F(N)
0 0
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 19
11 29
12 34
13 49
14 59
15 69
16 79
17 89
18 92
19 199
20 225
21 317
22 499
23 599
24 614
25 799
26 899
27 913
28 1147
29 2999
30 3125
31 4999
32 5999
33 6999
34 7999
35 8999
36 9114
37 19999
38 29999
39 39999
40 41125
41 59999
42 61117
43 79999
44 89999
45 91115
46 199999
47 299999
48 311128
49 499999
50 511125
51 699999
52 799999
53 899999
54 911116
55 1999999
56 2111147
57 3999999
58 4999999
59 5999999
60 6111125
61 7999999
62 8999999
63 9111117
64 11111188
65 29999999
66 39999999
67 49999999
68 59999999
69 69999999
70 71111125
The shortest code in bytes wins. Kudos if you can show that your code takes advantage of some efficiency.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

vlong
mknum(vlong *p, vlong r)
{
	vlong i;

	for (i = 1; i < 10; i++) {
		for (; p[i] > 0; p[i]--)
			r = (r * 10) + i;
	}
	return r;
}

/*

https://oeis.org/A051885 (related)

Ported from @bernaf solution

*/

vlong
f(vlong n)
{
	vlong d[19], *p;
	vlong j, r, c;

	if (n < 1)
		return 0;

	c = n / 9;
	r = n % 9;
	if (c == 0)
		return r;

	if (r == 0) {
		r = 9;
		c -= 1;
	}

	memset(d, 0, sizeof(d));
	p = d;
	j = 9;
	d[9] = c;
	if (!(n % r)) {
		n /= r;
		while ((j - 1) * (n - 1) * c != 0) {
			if (n % j)
				j -= 1;
			else {
				c -= 1;
				d[9 + j] += 1;
				n /= j;
			}
		}
		d[10] = c;
		if (n == 1)
			p += 9;
	}
	return mknum(p, r);
}

int
main()
{
	assert(f(0) == 0);
	assert(f(1) == 1);
	assert(f(2) == 2);
	assert(f(3) == 3);
	assert(f(4) == 4);
	assert(f(5) == 5);
	assert(f(6) == 6);
	assert(f(7) == 7);
	assert(f(8) == 8);
	assert(f(9) == 9);
	assert(f(10) == 19);
	assert(f(11) == 29);
	assert(f(12) == 34);
	assert(f(13) == 49);
	assert(f(14) == 59);
	assert(f(15) == 69);
	assert(f(16) == 79);
	assert(f(17) == 89);
	assert(f(18) == 92);
	assert(f(19) == 199);
	assert(f(20) == 225);
	assert(f(21) == 317);
	assert(f(22) == 499);
	assert(f(23) == 599);
	assert(f(24) == 614);
	assert(f(25) == 799);
	assert(f(26) == 899);
	assert(f(27) == 913);
	assert(f(28) == 1147);
	assert(f(29) == 2999);
	assert(f(30) == 3125);
	assert(f(31) == 4999);
	assert(f(32) == 5999);
	assert(f(33) == 6999);
	assert(f(34) == 7999);
	assert(f(35) == 8999);
	assert(f(36) == 9114);
	assert(f(37) == 19999);
	assert(f(38) == 29999);
	assert(f(39) == 39999);
	assert(f(40) == 41125);
	assert(f(41) == 59999);
	assert(f(42) == 61117);
	assert(f(43) == 79999);
	assert(f(44) == 89999);
	assert(f(45) == 91115);
	assert(f(46) == 199999);
	assert(f(47) == 299999);
	assert(f(48) == 311128);
	assert(f(49) == 499999);
	assert(f(50) == 511125);
	assert(f(51) == 699999);
	assert(f(52) == 799999);
	assert(f(53) == 899999);
	assert(f(54) == 911116);
	assert(f(55) == 1999999);
	assert(f(56) == 2111147);
	assert(f(57) == 3999999);
	assert(f(58) == 4999999);
	assert(f(59) == 5999999);
	assert(f(60) == 6111125);
	assert(f(61) == 7999999);
	assert(f(62) == 8999999);
	assert(f(63) == 9111117);
	assert(f(64) == 11111188);
	assert(f(65) == 29999999);
	assert(f(66) == 39999999);
	assert(f(67) == 49999999);
	assert(f(68) == 59999999);
	assert(f(69) == 69999999);
	assert(f(70) == 71111125);

	return 0;
}
