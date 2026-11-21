Your task is to create one brainfuck program for each of the following binary operators. Each program should take one or two 8-bit numbers (A and B) from input and calculate the specified operation:

A XOR B
A AND B
A OR B
A Shifted Left by 1 (circular shift)
NOT A
You do not have to implement all 5. Score is calculated by:

#totalCharacters + {4000 * #problemsNotCompleted}
So valid scores are from zero (best) to 20,000(nothing completed).

I don't care where you store the result, or whether or not you preserve the input. Assume 8-bit cells, and as many empty cells as you need to the right only.

You may assume the numbers are already in whatever memory location works best for you, so you don't need to worry about IO operations.

@Daniel Cristofani

It works better to expand these with a binary counter. The less intuitive parts deal with the possibility that A or B is 0. I didn't find a profitable way to use nondestructive flow control in the actual bit manipulation of the first three. Incidentally these should all work fine with 16-bit cells and slowly with 32-bit.

XOR, 86

Assumes A and B are in cells 1 and 2, stores A XOR B in cell 2, pointer starts in cell 0 and ends in cell 5.

-[[>>>>>>[>>>]++[-<<<]<<<-]>]>>>[<]>[[>[>-<-]>[<<<<<<+>>>>>>[-]]>]+[<[<<<++>>>-]<<]>>]
AND, 78

Assumes A and B are in cells 1 and 2, stores A AND B in cell 4, pointer starts in cell 0 and ends in cell 5.

-[[>>>>>>[>>>]++[-<<<]<<<-]>]>>>[<]>[[>[>[<<<<+>>>>-]<-]>+>]<[<[<<<++>>>-]<<]]
OR, 86

Assumes A and B are in cells 1 and 2, stores A OR B in cell 2, pointer starts in cell 0 and ends in cell 5.

-[[>>>>>>[>>>]++[-<<<]<<<-]>]>>>[<]>[[>[>+<-]>[<<<<<<+>>>>>>[-]]>]+[<[<<<++>>>-]<<]>>]
ROL, 18

Assumes A is in cell 0, stores A ROL 1 in cell 1, pointer starts and ends in cell 0.

[>++[>>]<[>+>]<<-]
NOT, 7

Assumes A is in cell 0, stores NOT A in cell 1, pointer starts and ends in cell 0.

+[>-<-]
