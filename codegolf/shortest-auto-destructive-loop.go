/*

Your task is to write a full program or function that takes no input and runs any type of loop (while, for, foreach, do, do-while, do-loop, goto, recursion, etc) that will end in causing an error, which means that the program must stop itself running and exit.

Rules:

The error must be a run-time error, unhandled exception, or anything that makes the program end itself.
The error must produce the stop and exit from the program without calling explicitly exit; (or equivalent) at some point.
Messages like Warning:, Notice:, etc, that do not cause the program to end itself are not valid. For example in PHP divisions by zero produces a Warning message but the program will not stop and will still run, this is not a valid answer.
The loop must run at least one full cycle. In other words the error can happen starting at the second cycle and further. This is to avoid to cause the error using incorrect code syntax: the code must be syntactically correct.
The loop can be even infinite (example for(;;);) if it respects the above said rules, but must take no longer than 2 minutes to end itself in a run-time error.
Recursion without Tail Call Optimization is invalid (1,2).
This is code-golf so the shortest code wins.
Standard loopholes are forbidden.
C# example (test online):

using System;
public class Program {
    public static void Main() {
        int i;
        int[] n;
        n = new int[5];
        for(i=0; i<7; i++) {
            n[i] = i;
            Console.WriteLine(n[i]);
        }
    }
}


Output:

0
1
2
3
4
Run-time exception (line 9): Index was outside the bounds of the array.

Stack Trace:

[System.IndexOutOfRangeException: Index was outside the bounds of the array.]
  at Program.Main(): line 9

*/

package main

import "fmt"

func main() {
	destruct()
}

func destruct() {
	n := make([]int, 5)
	for i := range 7 {
		n[i] = i
		fmt.Println(n[i])
	}
}
