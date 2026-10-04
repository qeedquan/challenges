/*

Challenge
Write a brainfuck program that takes as many steps to halt. Non-halting program brainfuck programs are not allowed.

Not only does it have to be busy but it should also brag by printing the number of steps it takes to halt in good old Base-10.

The program must be at most 1000 bytes.

Scoring
The score would be the number of steps it takes to halt.
Step-counting and interpreter specifics
(same with a previous brainfuck busy beaver challenge)

The counter is incremented after an instruction is executed. Braces do contribute to the counter regardless if they actually cause a jump or not. When they do cause a jump, the corresponding braces it jumps to does not contribute to the number of steps.

Each cell holds an unsigned byte and the tape is infinite in both directions. Values wrap upon incrementing 255 or decrementing 0.

*/

package main

import "fmt"

func main() {
	fmt.Println(CODE)
}

/*

@Level River St

This employs a 255-digit decimal downcounter.

Note that counting down from 99 to zero requires 99 decrements in the units column, and 9 in the 10's column, including 9 carries. For 999 to zero, we need the same 99 decrements for the 10's column, and 9 for the 100's column, including 9 carries. We also need an additional 99 carries for the 10's column and 999 decrements for units column. The execution grows geometrically.

A six-digit implementation of this is given below, running in Value Ink's Ruby instruction-counting brainfuck interpreter from the linked question (note: I have modified this to implement the output instruction . but it still counts invalid characters including whitespace in the execution count.)

The first 72 bytes are hardcoded to build the values 0 10 0 10 0 10 0 10 0 10 0 10 on the tape, representing the 6 digits. (10 represents 9, 1 represents 0, and 0 represents -1, meaning a borrow is required.)

Running this with different number of digits we observe the following pattern, including and excluding the 12 instructions per digit used to setup the tape:

            Instructions Executed
Digits   Including setup     Excluding setup
1        137 =     158-21      125=     158-33
2       1576 =    1588-12     1552=    1588-36
3      15885 =   15889 -3    15849=   15888-39
4     158894 =  158888 +6   158846=  158888-42
5    1588903 = 1588888+15  1588843= 1588888-45
6   15888912 =15888888+24 15888840=15888888-48
We conclude from this pattern that for 255 digits the number of instructions executed (excluding the setup of the tape) will be eval("15"+"8"*255)-45-3*250 = 158...88093 bytes.

Additional code is required to put 255 lots of 0 10 on the tape and (before that) to brag the number of instructions executed. The bragging code includes a loop to increase the number of instructions, avoiding too much variation in the final few digits. The total number of instructions is below (ending 89696133)

15888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888889696133
Code (147 bytes, out of 1000 bytes allowed)
Code is in three lines: the brag, the tape setup, and the busy beaver downcounter itself.

-[----->+<]>--.++++.+++>--------[<.>->-[-<><><>]<]<+.---.+++.---.-----.++..>>>
-[>>[+>>]+[<<]>>-]>>[[-]++++++++++>>]<<
[-[[>>]<]<<[>>++++++++++<<<]>]
Use the link below to run within my modified version of ValueInk's instruction-counting brainfuck interpreter (newlines deleted.) Don't expect it to end before the heat death of the universe. If you delete the busy beaver part, the brag and setup code take 808040 instructions. Adding this to 15....88093 gives 15...889696133 as output by the code.

Commented code

-[----->+<]>           Put 255/5=51 on the tape
--.++++.+++>           Adjust to ascii values for 1 and 5 and output; leave at ascii value for 8
--------               Put 248 on the tape
[<.>->-[-<><><>]<]     Output digit 8 a total of 248 times; kill time looping to make final digits nicer
<+.---.+++.---.        Output 9696
-----.++..>>>          Output 133; move to a clean part of the tape with enough >>> to burn the right number of instructions


-                      Put 255 on the tape
[>>[+>>]+[<<]>>-]      Iterate 255 times leaving 255 0 254 0 ::: 3 0 2 0 1 0 on the tape
>>[[-]++++++++++>>]    Change nonzero cells to 10
<<                     Move pointer to the rightmost nonzero cell

[-                     If not zero; decrement the current column
[[>>]<]                If still not zero no borrow required; move 1 space to the right of the units column
<<                     Move 2 spaces left; if no borrow required we are now 1 space left of the units column
[>>++++++++++<<<]      If a borrow is required we are now on the digit to the left of the one we just decremented
                       Increment original digit by 10 and end 1 space left of the column to be borrowed from
>]                     Move right onto appropriate column (either the units column or the column to be borrowed from
                       Loop if nonzero: code ends when digit value for leftmost column reaches zero
*/

const CODE = `
-[----->+<]>--.++++.+++>--------[<.>->-[-<><><>]<]<+.---.+++.---.-----.++..>>>
-[>>[+>>]+[<<]>>-]>>[[-]++++++++++>>]<<
[-[[>>]<]<<[>>++++++++++<<<]>]
`
