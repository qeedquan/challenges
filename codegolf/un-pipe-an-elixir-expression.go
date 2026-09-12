/*

Elixir is a programming language with a feature called the pipe operator, |>, similar to the pipe in Bash and other languages. It passes the result of an expression on the left as the first parameter of a given function on the right.

To clarify, here are some examples.

2 |> myFunction()
is equivalent to

myFunction(2)
Here, the expression 2 is passed as the first parameter of the function myFunction().

Now, consider how an expression with multiple pipes is evaluated. Multiple pipes are evaluated left to right, so all of these lines are equivalent:

other_function() |> new_function() |> baz() |> bar() |> foo()
new_function(other_function()) |> baz() |> bar() |> foo()
baz(new_function(other_function())) |> bar() |> foo()
bar(baz(new_function(other_function()))) |> foo()
foo(bar(baz(new_function(other_function()))))
Here, in each line the leftmost pipe is calculated, which takes the first expression and passes it to the second expression (which is a function).

Challenge
Your challenge will be to write a program or function which, when given an Elixir expression with one or more pipes, will return or output an equivalent expression with no pipes. In real Elixir code the functions may have multiple parameters but to keep this challenge simpler, you may assume all functions will take only one parameter.

Examples
Input                                                       -> Output
2 |> myFunction()                                           -> myFunction(2)
otherfunction() |> newfunction() |> baz() |> bar() |> foo() -> foo(bar(baz(newfunction(otherfunction()))))
Rules
Function names will only contain ASCII letters and underscores, and end in ()
The leftmost expression will only contain alphanumeric ASCII, underscores, and parentheses
You may assume there is no whitespace in the input (the examples here have spaces for readability)
You may also assume there are spaces surrounding the pipe operators like in the examples, if you wish
All functions only take one parameter
Leading or trailing whitespace is allowed in output
Whitespace around parentheses is allowed in output
Any reasonable form of input/output is allowed
No standard loopholes
Shortest code in bytes for each language wins

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(unpipe("2 |> myFunction()") == "myFunction(2)")
	assert(unpipe("otherfunction() |> newfunction() |> baz() |> bar() |> foo()") == "foo(bar(baz(newfunction(otherfunction()))))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unpipe(s string) string {
	r := ""
	t := strings.Split(s, "|>")
	for i := range t {
		n := strings.IndexRune(t[i], '(')
		p := strings.Replace(t[i], "(", "", -1)
		p = strings.Replace(p, ")", "", -1)
		p = strings.TrimSpace(p)
		if n >= 0 {
			r = "(" + r + ")"
		}
		r = fmt.Sprintf("%s%s", p, r)
	}
	return r
}
