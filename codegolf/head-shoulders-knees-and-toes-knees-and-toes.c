/*

Introduction:
I think we all know it, and it has probably been translated in loads of different languages: the "Head, Shoulders, Knees and Toes" children song:

Head, shoulders, knees and toes, knees and toes
Head, shoulders, knees and toes, knees and toes
And eyes and ears and mouth and nose
Head, shoulders, knees and toes, knees and toes
wikipedia

Challenge:
Input: A positive integer.

Output: Output one of the following words based on the input as n-th index:

head
shoulders
knees
toes
eyes
ears
mouth
nose
Here the body parts are appended with the indexes:

Head (0), shoulders (1), knees (2) and toes (3), knees (4) and toes  (5)
Head (6), shoulders (7), knees (8) and toes (9), knees (10) and toes (11)
And eyes (12) and ears (13) and mouth (14) and nose (15)
Head (16), shoulders (17), knees (18) and toes (19), knees (20) and toes (21)

Head (22), shoulders (23), knees (24) and toes (25), knees (26) and toes  (27)
Head (28), shoulders (29), knees (30) and toes (31), knees (32) and toes (33)
And eyes (34) and ears (35) and mouth (36) and nose (37)
Head (38), shoulders (39), knees (40) and toes (41), knees (42) and toes (43)

etc.
Challenge rules:
You are of course allowed to use 1-indexed input instead of 0-indexed. But please specify which one you've used in your answer.
The output is case insensitive, so if you want to output it in caps that's fine.
You should support input up to at least 1,000.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Test cases (0-indexed):
Input:  Output:
0       head
1       shoulders
7       shoulders
13      ears
20      knees
35      ears
37      nose
98      knees
543     nose
1000    knees

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

@Arnauld

How it works
We have 4 distinct pairs of words that always appear together: 'head' is always followed by 'shoulders', 'knees' is always followed by 'toes', etc.

Therefore, we can use the following index:

00: [ 'knees', 'toes' ]
01: [ 'head', 'shoulders' ]
10: [ 'eyes', 'ears' ]
11: [ 'mouth', 'nose' ]
And compress the whole sequence (in reverse order) into the following binary mask:

00 00 01 11 10 00 00 01 00 00 01
We use [ 'knees', 'toes' ] as the first pair to get as many leading zeros as possible.

We pad this sequence with an extra 0 so that the extracted value is premultiplied by 2, which leads to:

0b00000111100000010000010 = 245890
Hence the final formula for the correct word:

(245890 >> (n % 22 & ~1)) & 6 | n % 2

*/

const char *
bodypart(unsigned n)
{
	static const char *parts[] = {
		"knees", "toes", "head", "shoulders", "eyes", "ears", "mouth", "nose"
	};

	unsigned i, s;

	s = (n % 22) & ~1;
	i = ((245890 >> s) & 6) | (n & 1);
	return parts[i];
}

void
test(unsigned n, const char *r)
{
	const char *p;

	p = bodypart(n);
	puts(p);
	assert(!strcmp(p, r));
}

int
main()
{
	test(0, "head");
	test(1, "shoulders");
	test(7, "shoulders");
	test(13, "ears");
	test(20, "knees");
	test(35, "ears");
	test(37, "nose");
	test(98, "knees");
	test(543, "nose");
	test(1000, "knees");

	return 0;
}
