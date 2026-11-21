/*

You may have heard about "asymmetric" methods in cryptography, and even probably already have solved some related problems - e.g. the one about RSA. These evolved in late 1970s and were based on idea that it is comparatively easy to calculate exponential function in finite integer field (R = X ^ Y mod P) but much more difficult to perform reverse operation, particularly finding Y from result of operation R and exponent base X. Hence decryption used different key and different operation (raising R to yet different power Q to get X) - and thus the method was "asymmetric" - secrets for encryption and decryption are not the same.

It was a turning point in cryptography - no more need to conceal and secretly transfer code books etc - secrets now can be public! However, 20-30 years later mathematical instruments were improved and nowadays keys for RSA and similar algorithms need to be very large and calculations should involve a lot of iterations to keep decent level of secrecy.

That's the motivation why the newer method gains popularity - the one you may have heard under the name of Elliptic Curves - it also allows some "one-way" math function (i.e. one difficult to revert) useful for encryption, but with less ideas (as yet) on breaking it - and hence allowing much shorter keys.

The idea and math behind this approach is a bit more complicated and a way more "esoteric" :) so I thought we may have an exercise to start learning a bit more about this.

What is an Elliptic Curve and Points Addition
That's easy. They call so any function with formula

Y^2 = X^3 + A*X + B       or   Y = +/- sqrt(X^3 + A*X + B)
In the second form we need to regard both "branches" of sqrt - positive and negative: these curves have symmetry (as if mirrored upside-down). You may see one of the typical forms of the curve below, blue line (don't mind other lines and points marked yet) with A = -6 and B = 7.

https://imgur.com/dYmvDJW

Now, mathematicians are somewhat funny people. The would like to regard some set of something and introduce some operation(s) on elements of this set. In case of elliptic curves they:

regard a set of Points on a given Elliptic Curve
introduce "addition" operation, which take two points and produce the third
However this "addition" looks much different from whatever you may imagine. Look at the picture above! Here P and Q are two points on the curve, for which we want to find "sum". Graphically result is found like this:

trace straight line between P and Q until it intersects with the curve for the third time (red line)
flip this intersection point around the OX axis (flip shown with green line) to get the resulting point R.
This is conveniently written as R = P + Q though there is no such simple relation between their coordinates.

Really, we can figure out the formula for the red line Y = k*X + m, where:

k = (Yq - Yp) / (Xq - Xp)

m = Yp - k*Xp
And find its intersection with the curve analytically or iteratively. That's not precisely important for now since we'll regard curves over finite integer field with math somewhat different.

Interesting case is also adding the point to itself (P + P = ?) - how to draw the red line then? But imagine we move P and Q closer and closer - and it is easy to conclude that when they combine at last, the line should be the tangent of the curve at the point P. Coefficient k for it could be found with curve derivative formula which is (after recollecting some high-school math):

         (3*X^2 + A)             (3*X^2 + A)
k = ------------------------- = -------------       (then 'm' is found as before)
     2 * sqrt(X^3 + A*X + B)        2 * Y
Don't haste to analyze this formula, it is only needed to explain related formulas when we switch to finite fields.

Elliptic Curves over Galois Finite Fields
Imagine that the formula for the elliptic curve is applied not to real numbers but to finite set of integers from 0 to some p-1, with operations mod p (you may remember modular calculator problem and related ones). Such set is called Galois Field (by given modulo).

For example let regard function with the same coefficients A=-6, B=7 in the GF19, meaning all operations are taken by modulo 19. Now both X and Y can only have integer values from 0 to 18 so it is easy to plot the "curve". For example

with X=3 right part becomes 3^3 - 6*3 + 7 = 16

which corresponds to Y=4 or Y=15, since 4*4 = 16 and 15*15 = 16 (225 mod 19)
Now let

https://imgur.com/riQfva2

If we continue calculating points, we can draw such a "scatter" plot. Note there are no values for X values 1, 2, 8, 11, 12, 18 because resulting values in right part have no integer square root in the given field (no Y can produce such value when squared mod p). We have total of 26 points on the plot, to which also virtual infinity point is added, so the whole number of points in the curve - or the order of that curve is 27.

Now, what about "addition"?
We can "add" points in the same manner, tracing a line from some couple of them to see where it hits some different point. However this line should "wrap" when getting to "ceil" and continue from the bottom. How to calculate its "formula"? in the same manner, just remembering we can't simply "divide" values in modular arithmetics - instead we use "inverse" value, particularly

k = (Yq - Yp) * inv(Xq - Xp)      when `P` and `Q` differ

k = (3*X^2 + A) * inv(2 * (X^3 + A*X + B))
Where inverse value is calculated by any suitable approach (feel free to revisit Modular Inverse problem) - and is guaranteed to exist for every value if p is prime.

For example let's look at the couple of points P = (0, 11) and Q = (7, 17) - their distance by X is 7 to which we want to know inverse, e.g. value, which multiplied by 7 yields 1 - it is 11 (for 7*11 = 77 = 1 (mod 19)), so we find the gradient:

k = (Yq - Yp) * inv(Xq - Xp) = (17 - 11) * inv(7 - 0) = 6 * 11 = 9 (mod 19)

m = Yp - k*Xp = 11 - 14 * 0 = 11
You may check for the Q point that k*Xq + m = 9 * 3 + 11 = 15 (mod 19). It is represented on the picture below - note that line doesn't go "straight" as "intuition" may hint us. Now we only need to find out which of the next "curve's points" satisfies this line equation. The picture do not continue that far, but (17, 12) is what we want (k*17 + m = 9*17 + 11 = 12 (mod 19)).

https://imgur.com/fOnEJYB

Hence, remembering that we want the mirror-point we conclude that R = (17, 7). You may check that, however, some other pairs of points on this specific curve are not so "lucky" and won't hit the third point (explanation of this fact is left as a subpuzzle for those who have bit more inclination to math).

In the case when Q is the same as P the same approach with derivative is used, as in real-field function above, just replace division in the formula for k with multiplication by inverse. This is called "doubling" of the point (R = 2*P).

Problem Statement
Input data: the first line contains values defining the curve, A, B and p (the "order" of the finite field on which we work).
Second line contains N - the number of test-cases to follow.
Further N lines contain 4 values each, Xp Yp Xq Yq - coordinates of points P and Q.

Answer should give 2*N values - pairs of coordinates of the resulting point for every addition operation.

Example

input:
2 7 23
2
21 8 9 15
15 13 15 13

answer:
5 21 22 2

*/

#include <stdio.h>
#include <openssl/ec.h>
#include <openssl/bn.h>

int
solve(int a, int b, int p, int xp, int yp, int xq, int yq)
{
	EC_GROUP *group;
	EC_POINT *EX, *EY, *EZ;
	BIGNUM *X0, *Y0, *X1, *Y1;
	BIGNUM *A, *B, *P;
	BN_CTX *ctx;
	char *xs, *ys;
	int r;

	r = 0;
	ctx = NULL;
	group = NULL;
	xs = ys = NULL;
	A = B = P = NULL;
	EX = EY = EZ = NULL;
	X0 = Y0 = X1 = Y1 = NULL;

	ctx = BN_CTX_new();
	if (!ctx)
		goto error;

	A = BN_new();
	B = BN_new();
	P = BN_new();
	if (!A || !B || !P)
		goto error;

	BN_set_word(A, a);
	BN_set_word(B, b);
	BN_set_word(P, p);

	group = EC_GROUP_new_curve_GFp(P, A, B, ctx);
	if (!group)
		goto error;

	EX = EC_POINT_new(group);
	EY = EC_POINT_new(group);
	EZ = EC_POINT_new(group);
	if (!EX || !EY || !EZ)
		goto error;

	X0 = BN_new();
	Y0 = BN_new();
	X1 = BN_new();
	Y1 = BN_new();
	if (!X0 || !Y0 || !X1 || !Y1)
		goto error;

	BN_set_word(X0, xp);
	BN_set_word(Y0, yp);
	BN_set_word(X1, xq);
	BN_set_word(Y1, yq);

	EC_POINT_set_affine_coordinates(group, EX, X0, Y0, ctx);
	EC_POINT_set_affine_coordinates(group, EY, X1, Y1, ctx);

	if (EC_POINT_add(group, EZ, EX, EY, ctx) != 1)
		goto error;

	if (EC_POINT_get_affine_coordinates(group, EZ, X0, Y0, ctx) != 1)
		goto error;

	xs = BN_bn2dec(X0);
	ys = BN_bn2dec(Y0);
	if (!xs || !ys)
		goto error;

	printf("%s %s\n", xs, ys);

	if (0) {
	error:
		r = -1;
	}

	BN_free(A);
	BN_free(B);
	BN_free(P);
	BN_free(X0);
	BN_free(Y0);
	BN_free(X1);
	BN_free(Y1);
	EC_POINT_free(EX);
	EC_POINT_free(EY);
	EC_POINT_free(EZ);
	EC_GROUP_free(group);
	BN_CTX_free(ctx);
	OPENSSL_free(xs);
	OPENSSL_free(ys);

	return r;
}

int
main()
{
	int a, b, p;

	a = 2;
	b = 7;
	p = 23;
	solve(a, b, p, 21, 8, 9, 15);
	solve(a, b, p, 15, 13, 15, 13);

	return 0;
}
