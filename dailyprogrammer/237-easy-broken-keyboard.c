/*

Description
Help! My keyboard is broken, only a few keys work any more. If I tell you what keys work, can you tell me what words I can write?

(You should use the trusty enable1.txt file, or /usr/share/dict/words to chose your valid English words from.)

Input Description
You'll be given a line with a single integer on it, telling you how many lines to read. Then you'll be given that many lines, each line a list of letters representing the keys that work on my keyboard. Example:

3
abcd
qwer
hjklo
Output Description
Your program should emit the longest valid English language word you can make for each keyboard configuration.

abcd = bacaba
qwer = ewerer
hjklo = kolokolo
Challenge Input
4
edcf
bnik
poil
vybu
Challenge Output
edcf = deedeed
bnik = bikini
poil = pililloo
vybu = bubby
Credit
This challenge was inspired by u/ThinkinWithSand, many thanks! If you have any ideas, please share them on r/dailyprogrammer_ideas and there's a chance we'll use it.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

enum {
	MAXWORD = 64,
};

void
charset(const char *str, char set[256])
{
	memset(set, 0, 256);
	for (; *str; str++)
		set[*str & 0xff] = 1;
}

bool
subset(char *sup, char *sub, size_t len)
{
	size_t i;

	for (i = 0; i < len; i++) {
		if (sub[i] && !sup[i])
			return false;
	}
	return true;
}

size_t
trim(char *str)
{
	size_t len;

	len = strlen(str);
	while (len > 0 && isspace(str[len - 1]))
		str[--len] = '\0';
	return len;
}

int
longest(const char *dict, const char *word)
{
	char set0[256], set1[256];
	char bestword[MAXWORD], line[MAXWORD];
	size_t bestlen, len;
	FILE *fp;

	fp = fopen(dict, "r");
	if (!fp) {
		printf("error reading dict: %s\n", strerror(errno));
		return -errno;
	}

	bestword[0] = '\0';
	bestlen = 0;
	charset(word, set0);
	while (fgets(line, sizeof(line), fp)) {
		len = trim(line);
		charset(line, set1);
		if (len >= bestlen && subset(set0, set1, sizeof(set0))) {
			bestlen = len;
			snprintf(bestword, sizeof(bestword), "%s", line);
		}
	}

	printf("%s = %s\n", word, bestword);
	fclose(fp);
	return 0;
}

int
main()
{
	const char *dict = "enable1.txt";

	longest(dict, "abcd");
	longest(dict, "ewerer");
	longest(dict, "hjklo");
	longest(dict, "edcf");
	longest(dict, "bnik");
	longest(dict, "poil");
	longest(dict, "vybu");
	longest(dict, "aeiou");
	longest(dict, "z");

	return 0;
}
