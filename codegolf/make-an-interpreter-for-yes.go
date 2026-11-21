/*

Yes is a stack-based language that has a few space-separated instructions:

yes: Push 1 to the stack
no: Push 0 to the stack
what: Push the input to the stack (input is taken at the start of program execution and is the same for the whole execution)
sure: Increment the last item in the stack
nah: Decrement the last item in the stack
really: If the last stack item is a number, replace it with its Unicode character. If it is a letter, replace it with its Unicode char code.
oh: convert the stack to strings and concatenate it, and push that to the stack.
nope: remove the first stack item
yep: remove the last stack item
The stack's last element is always outputted at program end. All non-alphanumeric and non-space characters are ignored. All code is lowercase. Example programs:

yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
oh
prints Hello, World!.

what
prints the input (cat program.)

no nah
prints -1.

no really
prints the NUL character (U+0000)

what
yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really
oh
prints the input and an underscore.

yes no nope
prints 0

yes no yep
prints 1.

You must write an interpreter in as few bytes as possible. Here's a JS implementation (not well golfed!):

function yes(code, input){
	var stack = [];
	var functions = {
		"yes": "stack.push(1)",
		"no": "stack.push(0)",
		"what": "stack.push(input)",
		"sure": "stack[stack.length - 1] ++",
		"nah": "stack[stack.length - 1] --",
		"really": "stack[stack.length - 1] = (typeof lastItem === 'number' ? String.fromCharCode(lastItem) : lastItem.charCodeAt())",
		"oh": "stack.push(stack.reduce((x, y)=>''+x+y))",
		"nope": "stack.shift()",
		"yep": "stack.pop()"
	};
	code.replace(/[^a-z ]/g, "").split(" ").map(x=>(lastItem = stack[stack.length - 1],eval(functions[x])));
	return stack[stack.length - 1];
}
textarea{
  display: block;
}
Code: <textarea id = "code"></textarea>
Input: <textarea id = "input"></textarea>
<button onclick = "output.value = yes(code.value, input.value)">Run</button>
<textarea id = "output"></textarea>
Expand snippet
See also my JS answer below.

You may assume that all integers involved will be less than or equal to 126, that really will never be run with a multi-char string on top of the stack, and that the stack will never be longer than 100 elements.

Edge cases
yes yes oh prints 11.
Intput may be a string or number.
The code can contain any chars. Ones not matching [a-z ] should be ignored.

*/

package main

import (
	"fmt"
	"strings"
	"text/scanner"
)

func main() {
	assert(interpret("no nah", "") == -1)
	assert(interpret("no really", "") == "\x00")
	assert(interpret("yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really oh", "") == "Hello, World!")
	assert(interpret("what", "abc") == "abc")
	assert(interpret("what yes sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure sure really oh", "hello") == "hello_")
	assert(interpret("yes no nope", "") == 0)
	assert(interpret("yes no yep", "") == 1)
	assert(interpret("yes yes oh", "") == "11")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func interpret(code, input string) any {
	var (
		stack  []any
		scan   scanner.Scanner
		reader = strings.NewReader(code)
	)

	scan.Init(reader)
	for {
		if scan.Scan() == scanner.EOF {
			break
		}

		switch scan.TokenText() {
		case "yes":
			stack = append(stack, 1)
		case "no":
			stack = append(stack, 0)
		case "what":
			stack = append(stack, input)
		case "sure":
			add(stack, 1)
		case "nah":
			add(stack, -1)
		case "really":
			char(stack)
		case "oh":
			stack = append(stack, concat(stack))
		case "nope":
			if len(stack) > 0 {
				stack = stack[1:]
			}
		case "yep":
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			}
		}
	}
	if len(stack) > 0 {
		return stack[len(stack)-1]
	}
	return nil
}

func add(stack []any, val int) {
	n := len(stack) - 1
	if n < 0 {
		return
	}

	switch x := stack[n].(type) {
	case string:
		stack[n] = 0
	case int:
		stack[n] = x + val
	default:
		panic("unreachable")
	}
}

func concat(stack []any) string {
	str := ""
	for _, x := range stack {
		switch x := x.(type) {
		case string:
			str += x
		case int:
			str += fmt.Sprintf("%d", x)
		default:
			panic("unreachable")
		}
	}
	return str
}

func char(stack []any) {
	n := len(stack) - 1
	if n < 0 {
		return
	}

	x, ok := stack[n].(int)
	if ok {
		stack[n] = fmt.Sprintf("%c", x)
	}
}
