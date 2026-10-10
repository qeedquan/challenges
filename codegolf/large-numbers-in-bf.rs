/*

Background
The language BrainF*** (or simply BF), is an extremely minimal programming language. We're going to strip it back even further by eliminating IO operations; only the sub-langage defined by the operations +-<>[], henceforth referred to as BF-subset, shall be used. The BF variant considered has a tape extending infinitely to the left and right, and cells which can take on any integer value without overflowing, and which are initialized to 0.

For those unfamiliar with BF, this explanation is adapted from the esolangs BF page.

A BF-subset program is a sequence of commands. The commands are executed sequentially, with some exceptions: an instruction pointer begins at the first command, and each command it points to is executed, after which it normally moves forward to the next command. The program terminates when the instruction pointer moves past the last command.

>   increment the data pointer (to point to the next cell to the right).
<   decrement the data pointer (to point to the next cell to the left).
+   increment (increase by one) the byte at the data pointer.
-   decrement (decrease by one) the byte at the data pointer.
[   if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
]   if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.
The Task
If a BF-subset program terminates, its score is defined as the final value of the cell which the program halts at, otherwise 0. Your challenge is to write a program to generate BF-subset programs of each length between 1 and 20 inclusive, such that the total score is maximized.

The winner of the contest will be the entrant with the highest total score; in case of a tie, the shortest program takes the title. Your program must be fast enough for you to run it to completion.

Example Output and Scores
+                   01
++                  02
+++                 03
++++                04
+++++               05
++++++              06
+++++++             07
++++++++            08
+++++++++           09
++++++++++          10
+++++++++++         11
++++++++++++        12
+++++++++++++       13
++++++++++++++      14
+++++++++++++++     15
++++++++++++++++    16
+++++++++++++++++   17
++++++++++++++++++  18
+++++++++++++++++++ 19
+++++++++++++++++++ 20
Here, the total score is 210.

Edit: Changed the maximum length from 17 to 20.

*/

fn main() {
    for i in 1..21 {
        gen(i);
    }
}

fn gen(n: usize) {
    for _ in 0..n {
        print!("+");
    }
    println!();
}
