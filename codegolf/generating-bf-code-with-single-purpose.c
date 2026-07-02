/*

I'd like to see you create code (in any programming language) that output working BF (Brain***k) code. Your program have a single character input on stdin. The input should be one digit ("0", "1", "2", "3", "4", "5", "6", "7", "8" or "9").

Your code should output BF-code that when interpreted with a normal BF-interpreter outputs a 5*5 ascii version of the digit. The generated BF-code should not accept any input. The resulting output from the generated BF-code should be exactly this:

Input: '0'

Output BF-code that when interpreted generates the following output:

.---.
|  /|
| / |
|/  |
'---'
Input: '1'

Output BF-code that when interpreted generates the following output:

 .
/|
 |
 |
 '
Input: '2'

Output BF-code that when interpreted generates the following output:

.---.
    |
.---'
|
'---'
Input: '3'

Output BF-code that when interpreted generates the following output:

.---.
    |
 ---|
    |
'---'
Input: '4'

Output BF-code that when interpreted generates the following output:

.   .
|   |
'---|
    |
    '
Input: '5'

Output BF-code that when interpreted generates the following output:

.---
|
'---.
    |
'---'
Input: '6'

Output BF-code that when interpreted generates the following output:

.---
|
|---.
|   |
'---'
Input: '7'

Output BF-code that when interpreted generates the following output:

----.
   /
  /
 /
'
Input: '8'

Output BF-code that when interpreted generates the following output:

.---.
|   |
|---|
|   |
'---'
Input: '9'

Output BF-code that when interpreted generates the following output:

.---.
|   |
'---|
    |
'---'
The output from your code must be 10 different BF sourcecodes, one for each digit you input. Your program should not output all 10 BF in one run, it must ask for a digit and output BF code for that and only that ascii representation.

The BF-code requirements:

cell size: 8bit unsigned.
Overflow is undefined.
Array size: Max 30000 bytes (not circled)
It can contain other characters than [],.+-<>, but they should all be ignored. It is only - the standard BF code without any extensions that counts.
The EOF return 0
Linefeed is chr(10)
The winning answer will be the one that scores that lowest code using this formula:

your code in number of bytes * 5 + sum of the 10 generated BF codes
So keep in mind that you need to generate GOLF'd BF-code to score better.

Edit/Add (2011-08-25): You may omit or supply trailing spaces, as long as the digits displays the ASCII representation on a 80 column output, so the limit is 80 chars rows. Honor to the answers to generates exactly 5*5 output for all digits.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// ported from @JiminP solution
const char *
gen(unsigned n)
{
	static const char *code[] = {
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<.<<.>>>>.<<<..>>>>.<.<<<<.>>>>.<<<.>>>>.<<<<.>>>.<<<<.>>>>.>.<<<<..>>>.<<<<.>>>>>>.<<<...>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<<.>.<<.>>>>>.<.<<<<.>.>>>.<<<<.>.>>>.<<<<.>.>>>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<.<<.>....>>>.<<<<.>>.>...>>>.<<<<<<.>>>>.<<<<.>>>>>>.<<<...>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<.<<.>....>>>.<<<<.>.>>...>.<<<<.>....>>>.<<<<.>>>>>>.<<<...>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.<...>.<<.>>>>.<<<...>>>.<<<<.>>>>>>.<<<...>.<<<<.>....>>>.<<<<.>....>>>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<<<.>>>>.<<<<.>>>>>>.<<<...<.<<.>....>>>.<<<<.>>>>>>.<<<...>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<<<.>>>>.<<<<.>>>>.<...<.<<.>>>>.<<<...>>>.<<<<.>>>>>>.<<<...>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<....<.<<.>...>>>>.<<<<<.>..>>>>.<<<<<.>.>>>>.<<<<<.>>>>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<.<<.>>>>.<<<...>>>.<<<<.>>>>.<...>.<<<<.>>>>.<<<...>>>.<<<<.>>>>>>.<<<...>>>.",
	    "++++++++[->+>++++>++++++>++++++>+++++++++++++++>++++++>+++++<<<<<<<]>++>>-->--->++++>->-<<<<.>...<.<<.>>>>.<<<...>>>.<<<<.>>>>>>.<<<...>.<<<<.>....>>>.<<<<.>>>>>>.<<<...>>>.",
	};

	if (n < nelem(code))
		return code[n];
	return NULL;
}

int
main()
{
	unsigned i;

	for (i = 0; i <= 9; i++)
		printf("#%d: %s\n", i, gen(i));

	return 0;
}
