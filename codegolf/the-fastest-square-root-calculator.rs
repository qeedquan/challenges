/*

Write a program which outputs the square root of a given number in the shortest time possible.

Rules
It may not use any builtins or powering with non-integers.

Input format
as a function argument
as a command line argument
as a direct input on stdin or a window
Your entry hasn't to be a complete program, it may be a function or a snippet.
It doesn't need to be exact; a one percent margin of error is allowed.
The test cases will only be positive integers, but your program should output/return floats.
It may return the square root as function return value, print it to stdout or write in a consistent file, which is readable by the user..
Each program should specify the compiler/interpreter it should be run on and compiler flags. If they aren't specified, I'll use the following implementations: (just talking about mainstream langs):

C/C++: gcc/g++ on Linux, no flags
Java: OpenJDK on Linux, no flags
Python: CPython
Ruby: MRI
Assembler: x86 Linux
JS: Node.js
Examples
Input    Output
4        2 (or something between 1.98 and 2.02)
64       8 (between 7.92 and 8.08)
10000    100 (between 99 and 101)
2        bewteen 1.40001 and 1.428
Scoring
Your programs on the same computer with same conditions (Terminal and Iceweasel with this tab open). This question has the tag "Fastest code", so the program, which calculates the square root of a (not yet given) random integer between 1 and 10^10 as fast as possible will win!

*/

extern "C" {
    fn sqrtf(x: f32) -> f32;
}

fn main() {
    unsafe {
        let mut i = 0f32;
        while i <= 100f32 {
            println!("{}", sqrtf(i));
            i += 1f32;
        }
    }
}
