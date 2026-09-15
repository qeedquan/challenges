/*

Shamir's secret sharing scheme is a simple way of protecting a secret by splitting it into several parts needed to reconstruct it.

Your task is to implement Shamir's Secret Sharing reconstruction over the Finite Field defined by the prime 1928049029. If you have any doubts about what this means, just ask or see Finite Field & Finite Field Arithmetic in wikipedia (more resources below).

Input
Input is done using stdin. First comes an integer k, then k lines follow. Each of these lines contains a pair of integers x y that represent a secret. In other words f(x) = y in the original polynomial that was used to construct the secrets.

The number of secrets given is always enough to construct the corresponding secret.

Output
Output to stdout the reconstructed secret.

Examples
Input:

5
1 564797566
2 804114535
4 1354242660
6 1818201132
7 503769263
Output:

1234
Input:

7
1 819016192
2 1888749673
3 1737609270
4 365594983
5 1628804870
6 1671140873
7 492602992
Output:

456457856

Resources
Wikipedia article
https://en.wikipedia.org/wiki/Shamir%27s_secret_sharing

Paper
http://szabo.best.vwh.net/secret.html

Finite field Source: Wikipedia
https://en.wikipedia.org/wiki/Finite_field

Finite field arithmetic Source: Wikipedia
https://en.wikipedia.org/wiki/Finite_field_arithmetic

Lagrange polynomial Source: Wikipedia
https://en.wikipedia.org/wiki/Lagrange_polynomial

Chapter on Finite field arithmetic
https://docs.google.com/viewer?a=v&q=cache%3aCmQSTh2WDeIJ%3awww.springer.com/%3FSGWID%3D2-102-45-110359-4+finite+field+arithmethics&hl=en&pid=bl&srcid=ADGEESikdA6tzTfrWAdoudGolj3rW6eFLQGVnUSdnS3Yl_viLtytnZQUs868ulwqWbdYUCecDNUMQSVou0ItLhhJstUITdUsBbokZuArnDGoB5MzcuAPdz-iODPRYdX0OPRB0kxa2ttL&sig=AHIEtbTNiW7G-8mbUMBt1YEcLTiRDy7eXw

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
reconstruct(vlong *x, vlong *y, vlong n)
{
	vlong a, b, c, d;
	vlong l, m, t, z;
	vlong i, j;

	m = 1928049029;
	z = 0;
	for (i = n - 1; i >= 0; i--) {
		l = y[i];
		for (j = 0; j < n; j++) {
			if (x[i] == x[j])
				continue;

			a = m + x[j] - x[i];
			b = m;
			c = 1;
			d = 0;
			while (b > 0) {
				t = d;
				d = c - (a / b) * d;
				c = t;
				t = b;
				b = a % b;
				a = t;
			}
			l = (l * x[j]) % m;
			l = (l * (c + m)) % m;
		}
		z += l;
	}
	return z % m;
}

int
main()
{
	vlong x1[] = { 1, 2, 4, 6, 7 };
	vlong x2[] = { 1, 2, 3, 4, 5, 6, 7 };

	vlong y1[] = { 564797566, 804114535, 1354242660, 1818201132, 503769263 };
	vlong y2[] = { 819016192, 1888749673, 1737609270, 365594983, 1628804870, 1671140873, 492602992 };

	assert(reconstruct(x1, y1, nelem(x1)) == 1234);
	assert(reconstruct(x2, y2, nelem(x2)) == 456457856);

	return 0;
}
