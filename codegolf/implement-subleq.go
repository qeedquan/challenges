/*

Subleq is a Turing-complete esolang with only one instruction, SUBLEQ. This instruction takes in three parameters, A, B, and C, all of which are memory addresses. The instruction subtracts the value in memory address A from that in memory address B, storing it in address B. If the value at B is now less than or equal to zero, it jumps to memory address C; otherwise, it continues to the next instruction.

Your challenge is to implement this language. As input, the program should take in an array of integers representing the Subleq program, and starting at the first value (index 0), execute the program. In general, if the program is at index i, you should execute SUBLEQ(i,i+1,i+2). Your program should terminate when the instruction pointer is greater than the length of the tape; after execution, your program should output the final Subleq program with the memory modified.

If helpful, you may assume that you will only ever jump to locations which are a multiple of three. The behavior when the Subleq program runs into an error (e.g. jumps to a location outside memory) or get into an infinite loop are not defined.

Example
Adapted from the Subleq esolang wiki page:

[3, 4, 3,
 6, 13, 9,
 6, 3, -3,
 7, 8, 3]
Here is a trace of the execution, where the first number is the instruction pointer and brackets are put around the currently executed line:

0 : [[3, 4, 3], 6, 13, 9,  6,  3, -3,  7, 8, 3 ]
3 : [ 3, 4, 3, [6,  7, 9], 6,  3, -3,  7, 8, 3 ]
9 : [ 3, 4, 3,  6,  7, 9,  6, -3, -3, [7, 8, 3]]
3 : [ 3, 4, 3, [6,  7, 9], 6, -3,  0,  7, 8, 3 ]
9 : [ 3, 4, 3,  6,  7, 9,  6, -9,  0, [7, 8, 3]]
Thus, your program should output

[3, 4, 3, 6, 7, 9, 6, -9, 9, 7, 8, 3]
Standard loopholes are forbidden. Since this is code-golf, the shortest program wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(interpret([]int{3, 4, 3, 6, 13, 9, 6, 3, -3, 7, 8, 3}))
}

func interpret(mem []int) []int {
	defer func() {
		recover()
	}()

	pc := 0
	for pc+2 < len(mem) {
		a, b, c := mem[pc], mem[pc+1], mem[pc+2]
		mem[b] -= mem[a]
		if mem[b] <= 0 {
			pc = c
		} else {
			pc += 3
		}
	}
	return mem
}
