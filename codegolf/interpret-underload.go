/*

The challenge
Interpret the stack-based programming language underload.

The stack is a stack of strings that can be concatenated together.

Each underload program is a string of some of these instructions:

~: Swap the top two elements of the stack.
:: Duplicate the top element of the stack.
!: Discard the top element of the stack.
*: Concatenate the top two elements of the stack together.
(x): Push the string between the parenthesis to the stack. Parentheses can nest within strings, so (a(bc)d) should push the string a(bc)d to the stack, not a(bc.
a: Enclose the top element of the stack in parenthesis.
^: Pop the top element of the stack, and append it the program, directly after this instruction.
S: Pop the top element of the stack and print it.
Test cases
(Hello, world!)S
Hello, world!

(!@#$%^&*())S
!@#$%^&*()

(a)(b)~SS
ab

(a)(b)!S
a

(a)(b)*S
ab

(a)aS
(a)

(b)(a)^S
(b)

(a(:^)*S):^
(a(:^)*S):^
Input
The input will be a string, either through STDIN, as an argument to a function, or however your programming language takes input.

You can assume the input will have matched parenthesis and will not attempt to run invalid instructions.

Output
The output will also be a string.

This is code-golf, so the shortest answer in bytes is wins!

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(interpret("(Hello, world!)S") == "Hello, world!")
	assert(interpret("(!@#$%^&*())S") == "!@#$%^&*()")
	assert(interpret("(a)(b)~SS") == "ab")
	assert(interpret("(a)(b)!S") == "a")
	assert(interpret("(a)(b)*S") == "ab")
	assert(interpret("(a)aS") == "(a)")
	assert(interpret("(b)(a)^S") == "(b)")
	assert(interpret("(a(:^)*S):^") == "(a(:^)*S):^")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func interpret(src string) (out string) {
	defer func() {
		if err := recover(); err != nil {
			out = "error"
		}
	}()

	buf := new(bytes.Buffer)
	mem := []byte(src)
	stk := []string{}
	for pc := 0; pc < len(mem); pc++ {
		sp := len(stk)
		switch mem[pc] {
		case '~':
			stk[sp-1], stk[sp-2] = stk[sp-2], stk[sp-1]

		case ':':
			stk = append(stk, stk[sp-1])

		case '!':
			stk = stk[:sp-1]

		case '*':
			stk[sp-2] = stk[sp-2] + stk[sp-1]
			stk = stk[:sp-1]

		case '(':
			npc := pc + 1
			for par := 1; par != 0; npc++ {
				if mem[npc] == '(' {
					par++
				} else if mem[npc] == ')' {
					par--
				}
			}
			stk = append(stk, string(mem[pc+1:npc-1]))
			pc = npc - 1

		case 'a':
			stk[sp-1] = "(" + stk[sp-1] + ")"

		case '^':
			buf := []byte(stk[sp-1])
			nmem := make([]byte, len(mem)+len(buf))
			copy(nmem, mem[:pc+1])
			copy(nmem[pc+1:], buf)
			copy(nmem[pc+len(buf)+1:], mem[pc+1:])
			mem = nmem
			stk = stk[:sp-1]

		case 'S':
			fmt.Fprint(buf, stk[sp-1])
			stk = stk[:sp-1]
		}
	}
	return buf.String()
}
