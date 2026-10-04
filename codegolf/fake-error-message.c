/*

Write a program that prints out the syntax error message of the compiler or interpreter. The error message should be misleading so that code maintainers will take days to find out that the error was faked, that means, you should obfuscate (and hide your intention). Also, the error must be as exact as possible, and should reference to the code correctly.

For complied languages, assume your code maintainer will do compile program.p && ./program on the command line to compile AND run the program, that means, he cannot distinguish if the output comes from the compiler or the program itself. Also, assume your code maintainer will turn on syntax error messages.

For reference, here is an example I made: https://gist.github.com/359604

The DATA section encodes the string of error message, and the hash %abcdef is the decode table. The error printed references to the backslashes, which makes a code maintainer will try to count the backslashes.

Entries will be graded by:

Code has an deceptively obvious intention /6
Code reproduces error correctly /16 (your point starts with 16, and divide by the corresponding factors for each inaccuracies)
Correct capitalization: 4
Correct line number and column number: 4
Correct wording: 2 for each incorrect words
The line number referenced misleads the code maintainer /3
For example,

./pythontest1.py: line 7: syntax error near token `('
./pythontest1.py: line 7: `   x=input("Enter a number:") #Number input'
gets 8 (16 / 2) on correctness for missing "unexpected" before "token", a normal Python interpreter displays

./pythontest1.py: line 7: syntax error near unexpected token `('
./pythontest1.py: line 7: `   x=input("Enter a number:") #Number input'
If your "code reproduces error correctly" point is under 1, your entry disqualifies.

In case of a tie, I will put up additional grading factors.

*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

int
fakeout(const char *name)
{
	FILE *fp;

	fp = fopen(name, "w");
	if (!fp) {
		fprintf(stderr, "fakeout: %s: %s\n", name, strerror(errno));
		return -errno;
	}

	fprintf(fp, "cat: %s: No such file or directory\n", name);
	fclose(fp);
	return 0;
}

int
cat(const char *name)
{
	FILE *fp;
	int c;

	fp = fopen(name, "r");
	if (!fp) {
		fprintf(stderr, "cat: %s: %s\n", name, strerror(errno));
		return -errno;
	}

	while ((c = fgetc(fp)) != EOF)
		fputc(c, stdout);

	fclose(fp);
	return 0;
}

int
main()
{
	fakeout("readme.txt");
	cat("readme.txt");
	return 0;
}
