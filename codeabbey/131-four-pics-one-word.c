/*

I got the idea from watching my wife play one of those "4 images, 1 word" games on her tablet. Often, she'll get stuck and ask me for help; and then I get stuck too. :-) To help my wife in her games, I made an app that will accept the candidate letters, the word length and use a list of words to give all the possibilities.
Here is the link.

So the idea is basically to give a word list to the user (everyone uses the same word list) with a number of random letters and a desired word length; the goal is to find all the possible words in the list. The results could be to count the words...

My wife also plays this game sometimes. I dare to retell the rules - user is given 4 images and a handful of letters. The goal is to guess the word described by these images which could be built of these letters.

So you see, you are to write the program which searches through the dictionary for suitable words. As a matter of fact it is the advanced version of Anagrams because it is not necessary to use all letters.

Download dictionary file by this link

Input data contain the number of testcases in the first line.
Each of the following lines contains the required length of the word and a set of letters.
Answer should contain the amount of words from dictionary satisfying each case.

Example:

input data:
2
3 t c a z
3 t c a f

answer:
2 4
First case allows words cat and act while second adds fat and aft to them.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef long long vlong;

size_t
trim(char *string)
{
	size_t length;

	length = strlen(string);
	if (length > 0 && string[length - 1] == '\n')
		string[--length] = '\0';
	return length;
}

void
histogram(size_t count[256], const char *string)
{
	memset(count, 0, sizeof(*count) * 256);
	for (; *string; string++)
		count[*string & 0xff] += 1;
}

bool
compare(const char *word, size_t count1[256], size_t count2[256])
{
	int index;

	for (; *word; word++) {
		index = *word & 0xff;
		if (count2[index] > count1[index])
			return false;
	}
	return true;
}

vlong
solve(const char *dictionary, size_t length, const char *word)
{
	FILE *file;
	char line[128];
	size_t count1[256];
	size_t count2[256];
	vlong result;

	file = fopen(dictionary, "rb");
	if (!file)
		return -errno;

	result = 0;
	histogram(count1, word);
	while (fgets(line, sizeof(line), file)) {
		if (trim(line) != length)
			continue;

		histogram(count2, line);
		if (compare(line, count1, count2))
			result += 1;
	}

	fclose(file);
	return result;
}

int
main()
{
	assert(solve("words.txt", 3, "tcaz") == 2);
	assert(solve("words.txt", 3, "tcaf") == 4);

	return 0;
}
