/*

Introduction
This challenge is about producing a code to count the frequency of bigrams in a text. A bigram is two consecutive letters in a text. For instance 'aabbcd' contains the bigrams aa, ab, bb, bc, cd once each. Counting bigram frequencies is super useful in cryptography. In a brute force algorithm, this code may be called many times and as a result, must be optimised to run quickly.

Challenge
Challenge is in Python 3 and NumPy can be used.

The input will be a string of text (no spaces or punctuation). The output will be a NumPy array that is 26x26 or a list of lists that would be equivalent to the NumPy array. The first letter of the bigram is the row index and the second letter is the column index. The values in the array represent the frequency of that particular bigram.

The fastest code wins. I will measure the time it takes for the code to run 10,000 times on my computer (2015 Aspire F15 Intel i3 2.0GHz 4GB RAM).

Input
This is the input that I will test the code on

'WERENOSTRANGERSTOLOVEYOUKNOWTHERULESANDSODOIAFULLCOMMITMENTSWHATIMTHINKINGOFYOUWOULDNTGETTHISFROMANYOTHERGUYIJUSTWANNATELLYOUHOWIMFEELINGGOTTAMAKEYOUUNDERSTANDNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUWEVEKNOWNEACHOTHERFORSOLONGYOURHEARTSBEENACHINGBUTYOURETOOSHYTOSAYITINSIDEWEBOTHKNOWWHATSBEENGOINGONWEKNOWTHEGAMEANDWEREGONNAPLAYITANDIFYOUASKMEHOWIMFEELINGDONTTELLMEYOURETOOBLINDTOSEENEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVENEVERGONNAGIVEGIVEYOUUPWEVEKNOWNEACHOTHERFORSOLONGYOURHEARTSBEENACHINGBUTYOURETOOSHYTOSAYITINSIDEWEBOTHKNOWWHATSBEENGOINGONWEKNOWTHEGAMEANDWEREGONNAPLAYITIJUSTWANNATELLYOUHOWIMFEELINGGOTTAMAKEYOUUNDERSTANDNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYE'
Output:
This is the expected output

[[ 0.  0.  4.  0.  0.  1.  8.  0.  0.  0.  8. 11. 10. 21.  0.  2.  0. 14.
   7. 10.  0.  0.  0.  0. 10.  0.]
 [ 0.  0.  0.  0.  4.  0.  0.  0.  0.  0.  0.  1.  0.  0.  2.  0.  0.  0.
   0.  0.  2.  0.  0.  0.  6.  0.]
 [ 0.  0.  0.  0.  0.  0.  0.  4.  0.  0.  0.  0.  0.  0.  1.  0.  0.  6.
   0.  0.  0.  0.  0.  0.  0.  0.]
 [ 6.  6.  0.  6. 10.  0.  0.  5.  1.  0.  0.  0.  0.  3.  8.  0.  0.  0.
   1.  1.  0.  0.  2.  0.  0.  0.]
 [11.  2.  0.  0.  8.  0.  5.  1.  0.  0.  4. 11.  0. 13.  0.  0.  0. 53.
   7. 10.  0. 39.  2.  0. 17.  0.]
 [ 0.  0.  0.  0.  3.  0.  0.  0.  0.  0.  0.  0.  0.  0.  2.  0.  0.  1.
   0.  0.  1.  0.  0.  0.  2.  0.]
 [ 2.  2.  0.  1.  2.  0.  2.  0.  9.  0.  0.  0.  0.  0. 52.  0.  0.  0.
   0.  0.  1.  0.  0.  0.  2.  0.]
 [ 3.  0.  0.  0.  8.  0.  0.  0.  4.  0.  2.  0.  0.  0.  5.  0.  0.  0.
   0.  0.  5.  0.  0.  0.  2.  0.]
 [ 1.  0.  0.  2.  5.  1.  0.  0.  0.  2.  0.  0.  4. 12.  0.  0.  0.  0.
   1.  5.  0.  9.  0.  0.  0.  0.]
 [ 0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.
   0.  0.  2.  0.  0.  0.  0.  0.]
 [ 0.  0.  0.  0.  8.  0.  0.  0.  1.  0.  0.  0.  1.  7.  0.  0.  0.  0.
   0.  0.  0.  0.  0.  0.  0.  0.]
 [ 7.  0.  1.  1.  7.  0.  0.  0.  9.  0.  0.  9.  1.  0.  3.  0.  0.  0.
   0.  0.  0.  0.  0.  0.  2.  0.]
 [ 9.  0.  0.  0.  5.  3.  0.  0.  1.  0.  0.  0.  1.  0.  0.  0.  0.  0.
   0.  1.  0.  0.  0.  0.  0.  0.]
 [49.  0.  0. 26. 39.  0. 13.  0.  0.  0.  1.  0.  0. 47.  8.  0.  0.  0.
   2.  3.  0.  0.  2.  0.  1.  0.]
 [ 0.  1.  0.  7.  0.  1.  0.  0.  3.  0.  0.  3.  2. 44.  9.  0.  0.  2.
   6.  7. 49.  1. 16.  0.  0.  0.]
 [ 0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  2.  0.  6.  0.  0.  0.  0.
   0.  0.  0.  0.  1.  0.  0.  0.]
 [ 0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.
   0.  0.  0.  0.  0.  0.  0.  0.]
 [ 1.  0.  0.  0.  6.  2. 38.  2.  0.  0.  0.  0.  0.  0.  7.  0.  0.  0.
   5. 13.  7.  0.  0.  0.  6.  0.]
 [ 9.  4.  0.  0.  7.  1.  0.  2.  2.  0.  1.  0.  0.  0.  3.  0.  0.  0.
   0.  6.  0.  0.  1.  0.  0.  0.]
 [ 5.  0.  0.  0.  8.  0.  1. 10.  4.  0.  0.  0.  1.  0.  7.  0.  0.  1.
   5.  4.  0.  0.  2.  0. 19.  0.]
 [ 1.  0.  6.  6.  0.  0.  0.  2.  0.  0.  1.  3.  0. 24.  0.  7.  0. 10.
   2.  2.  9.  0.  2.  0.  1.  0.]
 [ 0.  0.  0.  0. 49.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.
   0.  0.  0.  0.  0.  0.  0.  0.]
 [ 2.  0.  0.  0.  9.  0.  0.  3.  3.  0.  0.  0.  0.  8.  1.  0.  0.  0.
   0.  3.  0.  0.  2.  0.  0.  0.]
 [ 0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.
   0.  0.  0.  0.  0.  0.  0.  0.]
 [ 0.  0.  0.  0.  6.  0.  6.  0.  5.  0.  0.  0.  0.  6. 43.  0.  0.  0.
   0.  2.  0.  0.  0.  0.  0.  0.]
 [ 0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.  0.
   0.  0.  0.  0.  0.  0.  0.  0.]]

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
dump(int b[26][26])
{
	size_t i, j;

	for (i = 0; i < 26; i++) {
		printf("[ ");
		for (j = 0; j < 26; j++)
			printf("%d ", b[i][j]);
		printf("]\n");
	}
}

void
bigram(const char *s, int b[26][26])
{
	size_t i;
	int x, y;

	memset(b, 0, sizeof(*b) * 26);
	for (i = 0; s[i] && s[i + 1]; i++) {
		x = tolower(s[i]);
		y = tolower(s[i + 1]);
		if (!('a' <= x && x <= 'z'))
			continue;
		if (!('a' <= y && y <= 'z'))
			continue;

		b[x - 'a'][y - 'a']++;
	}
}

void
test(const char *s)
{
	int b[26][26];

	bigram(s, b);
	dump(b);
}

int
main(void)
{
	test("WERENOSTRANGERSTOLOVEYOUKNOWTHERULESANDSODOIAFULLCOMMITMENTSWHATIMTHINKINGOFYOUWOULDNTGETTHISFROMANYOTHERGUYIJUSTWANNATELLYOUHOWIMFEELINGGOTTAMAKEYOUUNDERSTANDNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUWEVEKNOWNEACHOTHERFORSOLONGYOURHEARTSBEENACHINGBUTYOURETOOSHYTOSAYITINSIDEWEBOTHKNOWWHATSBEENGOINGONWEKNOWTHEGAMEANDWEREGONNAPLAYITANDIFYOUASKMEHOWIMFEELINGDONTTELLMEYOURETOOBLINDTOSEENEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVENEVERGONNAGIVEGIVEYOUUPWEVEKNOWNEACHOTHERFORSOLONGYOURHEARTSBEENACHINGBUTYOURETOOSHYTOSAYITINSIDEWEBOTHKNOWWHATSBEENGOINGONWEKNOWTHEGAMEANDWEREGONNAPLAYITIJUSTWANNATELLYOUHOWIMFEELINGGOTTAMAKEYOUUNDERSTANDNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYENEVERGONNATELLALIEANDHURTYOUNEVERGONNAGIVEYOUUPNEVERGONNALETYOUDOWNNEVERGONNARUNAROUNDANDDESERTYOUNEVERGONNAMAKEYOUCRYNEVERGONNASAYGOODBYE");

	return 0;
}
