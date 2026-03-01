/*

Code-Bowling
You've been hired by Brunswick Bowling to create a simple program to output the text Code Bowling on their monitors. This company is worth a pretty penny and you feel you can swindle them for quite the bit of cash.

The job description clearly states that they pay on a scoring basis and you're pretty confident you can manipulate their scoring system to your advantage and get the largest pay check possible from these guys. To do so will require you packing as much code as you can into your program/function, even though their scoring system is designed to prevent you from doing so.

Get out your piggy banks, let's code!

Challenge
The challenge is to simply output the text Code Bowling, exactly as it is written here, with the highest score possible. (See section: Scoring System below)

Leading and trailing new-lines (line-breaks) are acceptable.

Your code may be an entire program or just an executable function.

Rules
Obligatory: This challenge is using Code-Bowling: Common Rules, Revision 1.0.0; See Meta for details.

Character : Byte Ratio
In Code-Bowling a character-count is preferred over a byte-count. The obvious reasoning for this is that multi-byte unicode characters (e.g. 🁴) can be used in place of single-byte unicode characters to fluff up byte count and will make bowling more about who renames the most variables with high-byte unicode characters rather than who most strategically creates meaningful complex code.

Variable/Function/Object Names
All variable names (or object pointers, function names, etc) should be 1 character long. The only acceptable time to use 2-character variables names is after all possible 1-character variables have been used. The only acceptable time to use 3-character variables names is after all possible 2-character variables have been used. Etc.

Un-used Code
All code must be used. Meaning the program must fail to always properly complete the task if any individual character (or varying set(s) of characters) is/are removed. Naturally, a subset of the program should not be able complete the task on its own without the rest of the program.

Comments
Comments are not permitted towards character-count, unless somehow utilized by your program/function.

Scoring System:
  Pangram Challenge:
A pangram is a sentence that uses every letter at least once. (The quick brown fox jumps over the lazy dog).

This challenge-type has a scoring systems designed where a perfect pangram would achieve the theoretical maximum score (though you are not required to use every character at least once.) Additionally, using any character more than once will start incurring a penalty. This challenge also expands to more than just the alphabetical characters.

  Scoring Metric:
Each character used increases your score by 1.
Repeated use of any alphanumeric character (a-z, A-Z, 0-9) will result in a deduction of 3 points per repeat (first use does not result in a deduction).
Repeated use of basic punctuation ([!?.-,":';]) - including the brackets - will result in a deduction of 2 points per repeat.
Repeated use of other ASCII characters {`~@#$%^&*_+=|\/><} - including the curly brackets - will result in a deduction of 4 points per repeat.
Use of spaces, tabs, and newlines will result in a deduction of 1 point per use. That is, they do not count towards character total.
Characters not mentioned above (Exotic Characters) will result in a deduction of 1 point per use. That is, they do not count towards character total.
  Scoring Tool:
An automated scoring widget has been created and can be found here.

This is a code-bowling variant. The program with the highest score wins! (Since there is a maximum score of 94, whoever reaches it first (if it can be reached) will be marked as the accepted answer, though others are free to keep answering for fun)

*/

#include <stdio.h>

void
output()
{
	static const char sym[] = "g!#$%&'*n+,./012i34579;<l=>?@ADEwFGHIJKLoMNOPQRSBTUVWXYZ ^_`abchejkmqsuvdyz{|}~ \x6f       C";

	int i;

	for (i = sizeof(sym) - 2; i >= 0; i -= 8)
		putchar(sym[i]);
	putchar('\n');
}

int
main()
{
	output();
	return 0;
}
