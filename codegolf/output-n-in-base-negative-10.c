/*

Challenge:

In the programming language of your choice, accept an integer as input in base 10, and output it in the negadecimal notation, which is also known as base -10

Example algorithm:

This is an algorithm taken from Wikipedia to convert base 10 to any negative base in VB.NET:

Function toNegativeBase(Number As Integer , base As Integer) As System.Collections.Generic.List(Of Integer)

    Dim digits As New System.Collections.Generic.List(Of Integer)
    while Number <> 0
        Dim remainder As Integer= Number Mod base
        Number = CInt(Number / base)

        if remainder < 0 then
            remainder += system.math.abs(base)
            Number+=1
        end if

        digits.Insert(0, remainder)
    end while

    return digits
end function
Obviously, you can use any algorithm, as long as it fulfills the challenge

Example inputs / outputs:

Input:

12
Output:

192
Another example:

Input:

2048
Output:

18168

Rule:

You must not use any built-in methods that solve this problem that exist in your programming language

This is a code-golf, so shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// https://en.wikipedia.org/wiki/Negative_base
long
dec2base(long n, long b)
{
	ldiv_t d;
	long p, v;

	p = 1;
	v = 0;
	while (n != 0) {
		d = ldiv(n, b);
		if (d.rem < 0) {
			d.rem += labs(b);
			d.quot += 1;
		}
		n = d.quot;

		v += p * d.rem;
		p *= 10;
	}
	return v;
}

void
test(long n, long r)
{
	long v;

	v = dec2base(n, -10);
	printf("%ld\n", v);
	assert(v == r);
}

int
main(void)
{
	test(-15L, 25L);
	test(-5L, 15L);
	test(0L, 0L);
	test(12L, 192L);
	test(2048L, 18168L);

	return 0;
}
