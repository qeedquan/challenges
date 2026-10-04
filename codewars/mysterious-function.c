/*

Among the ruins of an ancient city a group of archaeologists found a mysterious function with lots of HOLES in it called getNum(n) (or get_num(n) in ruby, python, or r). They tried to call it with some arguments. And finally they got this journal:

getNum(300) #-> returns 2
getNum(90783) #-> returns 4
getNum(123321) #-> returns 0
getNum(89282350306) #-> returns 8
getNum(3479283469) #-> returns 5
The archaeologists were totally stuck with this challenge. They were all in desperation but then.... came YOU the SUPER-AWESOME programmer. Will you be able to understand the mystery of this function and rewrite it?q

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
getnum(uvlong n)
{
	static const uvlong lut[] = { 1, 0, 0, 0, 0, 0, 1, 0, 2, 1 };
	uvlong r;

	r = 0;
	do {
		r += lut[n % 10];
		n /= 10;
	} while (n);

	return r;
}

int
main()
{
	assert(getnum(300) == 2);
	assert(getnum(90783) == 4);
	assert(getnum(123321) == 0);
	assert(getnum(89282350306) == 8);
	assert(getnum(3479283469) == 5);

	return 0;
}
