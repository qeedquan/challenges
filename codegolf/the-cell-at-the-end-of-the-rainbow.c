/*

We all know of, or at least have heard of, brainfuck, one of the most famous and influential esoteric languages. While these days most implementations use an infinite tape, the original compiler by Urban Müller had a tape of 30000 cells. A little known fact* is that there is actually a special value at the end of the tape, something that is almost never interacted with in a typical brainfuck program.

While you could print this value with 29999 >s and a ., brainfuck is known for its short and concise solutions, so your aim is to print this value with the minimum number of characters.

*fiction

Rules:
A refresher on the brainfuck instructions:
+/-: Increment/decrement the current cell, wrapping from 255 to 0 when 255 is incremented and vice-versa
</>: Move the pointer left/right on the tape
.: Print the value of the current cell.
[: Jump to the corresponding ] if the value at the cell is 0
]: Jump to the corresponding [ if the value at the cell is not 0
In this case , (Get input) does nothing, as the original compiler leaves the cell unchanged on EOF, and this program should receive no input.
The tape is initially filled with all 0s, except for cell 30000, which contains an unknown value
The pointer starts at cell 1 and should end on cell 30000, having printed it.
Cells to the left of 1 and to the right of 30000 have undefined behaviour, so solutions should not visit these cells.
Note that the value at 30000 is may be a 0, so simply looping until you hit a non-zero cell will not work.
You should print only the value at cell 30000
The shortest solution wins!
Tie-breaker is the more efficient program (executes in the least steps), followed by the fastest submission time.
Tip: Esolanging Fruit suggests using https://copy.sh/brainfuck to test your code. The specs are as described in this challenge, and you can select the abort option so your program halts if it goes out of bounds.

*/

#include <stdio.h>

void
output(void)
{
	unsigned i;

	for (i = 0; i < 29999; i++)
		printf(">");
	puts(".");
}

int
main(void)
{
	output();
	return 0;
}
