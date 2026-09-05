/*

Your task is to write a function 'anArgument' that doesn't have a fixed number of parameters. The function should count the arguments passed to it and return a string that specifies how many arguments were passed in, and states what they were.

If the function call is

anArgument("pigs", "giraffes", "unicorns");

The returned string should say

'You gave me 3 arguments and they are "pigs", "giraffes" and "unicorns".'

If there is only one argument passed in, the string should say

'You gave me 1 argument and it is "pigs".'

If there are two arguments, the string should say

'You gave me 2 arguments and they are "pigs" and "giraffes".'

If there are no arguments, the string should say

'You didn't give me any arguments.'

###Punctuation and grammar notes

There are commas after each argument except the last and second-last, which are separated with 'and'
Arguments are presented in quotation marks
The singular: '1 argument' as opposed to multiples: '3 arguments'
Verb agreement: 'and it is' as opposed to 'and they are'

*/

package main

import "fmt"

func main() {
	assert(argument() == `You didn't give me any arguments.`)
	assert(argument("pigs") == `You gave me 1 argument and it is "pigs".`)
	assert(argument("pigs", "giraffes") == `You gave me 2 arguments and they are "pigs" and "giraffes".`)
	assert(argument("pigs", "giraffes", "unicorns") == `You gave me 3 arguments and they are "pigs", "giraffes" and "unicorns".`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func argument(args ...string) string {
	switch len(args) {
	case 0:
		return "You didn't give me any arguments."
	case 1:
		return fmt.Sprintf("You gave me 1 argument and it is %q.", args[0])
	}

	str := fmt.Sprintf("You gave me %d arguments and they are ", len(args))
	for i, arg := range args {
		str += fmt.Sprintf("%q", arg)
		if i+2 < len(args) {
			str += fmt.Sprintf(", ")
		} else if i+1 < len(args) {
			str += fmt.Sprintf(" and ")
		}
	}
	str += "."
	return str
}
