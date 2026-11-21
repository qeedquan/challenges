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

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://en.wikipedia.org/wiki/Negative_base
// https://oeis.org/A039723
long
dec2base(long n, long b)
{
	ldiv_t d;
	long p, v;

	if (b == 0)
		return 0;

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
	static const long tab[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 190, 191, 192, 193, 194, 195, 196, 197,
		198, 199, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 170, 171,
		172, 173, 174, 175, 176, 177, 178, 179, 160, 161, 162, 163, 164, 165,
		166, 167, 168, 169, 150, 151, 152, 153, 154, 155
	};

	size_t i;

	test(-15, 25);
	test(-5, 15);
	test(0, 0);
	test(12, 192);
	test(2048, 18168);

	for (i = 0; i < nelem(tab); i++)
		test(i, tab[i]);

	return 0;
}
