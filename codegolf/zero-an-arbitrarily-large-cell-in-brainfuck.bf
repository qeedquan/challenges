@
Your task is to write a piece of code that zeros the current cell in the Brainfuck variant that, each cell can contain a signed integer of arbitrarily large magnitude, instead of the normal 0 to 255.

You may assume there are l cells to the left and r cells to the right of the current cell that are initially zero. You program may only access these l+r+1 cells. After your code ends it should leave the l+r extra cells zero and the pointer to the current cell at the original position.

You may not use any input/output.

The code with smallest l+r wins. If there is a tie, the shortest code wins. It is recommended to also state the time complexity of your program for reference, where n is the absolute value of the original integer in the current cell.

Useful tools
You can test a Brainfuck program in this variation using this interpreter on TIO by mbomb007.

You can also use the interpreter in this answer by boothby (other Python answers probably also work, but I didn't test).
@

@JungHwan Min
My own algorithm. The pointer should begin at the number that needs to be zeroed. The time complexity is O(n^2).

How it works:
We start with the number n.
We increment one, so the number becomes n+1.
We decrement two, so the number becomes n+1-2 = n-1
We increment three, so the number becomes n-1+3 = n+2.
We decrement four, so the number becomes n+2-4 = n-2.
We repeat the process, increasing the in-/decrement each step, until we get zero.

[>+[-<+>>+<]<[>]>[+[-<+<->>]<[->+<]]>[-<+>]<<]>[-]<

