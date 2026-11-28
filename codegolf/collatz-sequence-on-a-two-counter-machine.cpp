/*

The Collatz sequence starting from a positive integer n is defined in this way:

if n is even then divide it by 2 (n' = n / 2)
if n is odd then multiply it by 3 and add 1 (n' = 3n + 1)
Repeat the above iteration until n reaches 1.

It is not known (it's a major unsolved problem in number-theory) if the sequence will eventually reach the number 1, regardless of which positive integer is chosen initially.

A Two Counter Machine (2CM) is a machine equipped with two registers that can hold a non-negative integer value and can be programmed with the following instruction set:

INCX    increase the value of register X
INCY    increase the value of register Y
JMP n   jump to instruction n
DJZX n  if register X is zero jump to instruction n,
        otherwise decrement its value
DJZY n  if register Y is zero jump to instruction n,
        otherwise decrement its value
HALT    halt (and accept)
PRINTX  print the content of register X
A 2CM program is simply a sequence of instructions, for example the following program simply copies the content of register X to register Y:

cp:   DJZX end
      INCY
      JMP cp
end:  HALT
Note that a 2CM is Turing Complete (i.e. it can compute every computable function with a suitable input encoding, but it is irrelevant here). Also note that the instruction set is a little bit different from the one in the Wikipedia article.

The challenge
Write the shortest 2CM program, that computes and prints the collatz sequence up to 1 and halts (the register X initially contains the starting value n and register Y initially contains 0). Note that the length of a 2CM program is the number of instructions used (not the length of the text).

For example, when started from X=3 it must print: 3 10 5 16 8 4 2 1 and HALT.

So you can use your favourite language to build a 2CM simulator/interpreter, but the final (shortest) code that you put in the answer must be in the 2CM language.

*/

#include <print>
#include <string>

using namespace std;

/*

Ported from @Runer112 solution

*/

const string CODE = R"(
# Let N be the previous number in the Collatz sequence.

# Print N, and if N==1, halt.
# X=N, Y=0
Main:           PRINTX          # Print N.
                DJZX Done       # X=N-1 (N shouldn't be zero, so this never jumps)
                DJZX Done       # If N-1==0, halt. Otherwise, X=N-2.

# Find the parity of N and jump to the proper code to generate the next N.
# X=N-2, Y=0
FindParity:     INCY
                DJZX EvenNext   # If N%2==0, go to EvenNext with X=0, Y=N-1.
                INCY
                DJZX OddNext    # If N%2==1, go to OddNext with X=0, Y=N-1.
                JMP FindParity

# Find the next N, given that the previous N is even.
# X=0, Y=N-1
EvenNext:       INCX
                DJZY Main       # Y=Y-1 (Y should be odd, so this never jumps)
                DJZY Main       # If Y==0, go to Main with X=(Y+1)/2=N/2, Y=0.
                JMP EvenNext

# Find the next N, given that the previous N is odd.
# X=0, Y=N-1
OddNext:        INCX
                INCX
                INCX
                DJZY EvenNext   # If Y==0, go to EvenNext with X=(Y+1)*3=N*3, Y=0.
                JMP OddNext     # ^ Abuses EvenNext to do the final INCX so X=N*3+1.

# Halt.
Done:           HALT
)";

int main()
{
	println("{}", CODE);
	return 0;
}
