/*

Implement the stack data structure. Write a program that describes and simulates the stack, implementing all the methods specified below.
The program reads a sequence of commands, and depending on the command, performs the corresponding operation.
After executing each command, the program should output one line.

The possible commands are:

push n — Add the number n (where n is a non-negative integer) to the stack. The program should output ok.

pop — Remove the last element from the stack. The program should output its value.

back — Output the value of the last element without removing it from the stack.

size — Output the number of elements in the stack.

clear — Remove all elements from the stack and output ok.

exit — Output bye and terminate the program.

Before executing the back and pop operations, the program must check whether there is at least one element in the stack.
If a back or pop command is issued when the stack is empty, output the string error instead of a numeric value.

Input
Each line contains one command.

Output
For each command, output the corresponding result on a separate line.

Examples

Input #1
push 2
back
pop
size
pop
push 1
size
exit

Answer #1
ok
2
2
0
error
ok
1
bye

*/

package main

import "fmt"

func main() {
	solve([]string{
		"push 2",
		"back",
		"pop",
		"size",
		"pop",
		"push 1",
		"size",
		"exit",
	})
}

func solve(cmds []string) {
	stk := []int{}
	for _, cmd := range cmds {
		var (
			op  string
			val int
		)
		fmt.Sscanf(cmd, "%s %d", &op, &val)

		switch op {
		case "exit":
			fmt.Println("bye")
			return

		case "push":
			stk = append(stk, val)
			fmt.Println("ok")

		case "size":
			fmt.Println(len(stk))

		case "pop", "back":
			sp := len(stk)
			if sp == 0 {
				fmt.Println("error")
				break
			}

			fmt.Println(stk[sp-1])
			if op == "pop" {
				stk = stk[:sp-1]
			}

		case "clear":
			stk = stk[:0]
			fmt.Println("ok")
		}
	}
}
