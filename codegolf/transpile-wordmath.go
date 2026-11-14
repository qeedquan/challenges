/*

We've all seen those online "maths hax" that look like this:

Think of a number, divide by 2, multiply by 0, add 8.
And, by magic, everyone ends up with the number 8!

Language
Let's define a programming language which uses the syntax of the text above, called "WordMath". WordMath scripts follow this template:

Think of a number, <commandlist>.
Which basically means: Take a number (as input from STDIN) as the initial accumulator, perform all commands on it, and output the result.

The commands are seperated by the delimiter , (comma + space). The valid commands are (note that # represents a non-negative integer:):

add # / subtract # - Add/subtract the value from the accumulator.
divide by # / multiply by # - floordiv / multiply the accumulator by the given value.
subtract from # - Similar to subtract, but does acc = # - acc instead of acc = acc - #
repeat - do last command again. This cannot be the 1st command, but you must support multiple consecutive repeats.
The Challenge
Your task is to create a program or function which takes a valid WordMath script as input and transpiles it into a valid full program - in the same language your cur is in.

For example, if my cur is in Python 2 and the script is:

Think of a number, subtract from 10, add 10, multiply by 2.
The outputted program can be:

a = input()
a = 10 - a
a += 10
a *= 2
print(a)
Or alternatively:

print(((10-input())+10)*2)
As long as it is a full program which takes input from STDIN and prints to STDOUT, or the language's nearest equivalents.

Rules
Your original program may assume that the input is always a valid WordMath script.
The transpiled programs do not have to handle mathematical errors such as division by 0.
The transpiled programs may assume that the input represents a valid signed integer, within your language's standard integer range.
This is cur-golf, so the shortest solution (in bytes) wins.
Only the byte count of your original program matters - the outputted cur can be as long as you want!
Example Scripts
Example 1:

Think of a number.
Take input, do nothing, display it: WordMath's cat program.

Example 2:

Think of a number, divide by 5, subtract from 9.
Remember that "divide" is floor division, so for this program 6 -> 8, and 29 -> 4.

Example 3:

Think of a number, add 5, add 10, multiply by 2, subtract 15, repeat, divide by 2.
The extended cat program!

Example 4:

Think of a number, subtract 1, repeat, repeat.
Takes a number and subtracts 3.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	fmt.Println(transpile("Think of a number, subtract from 10, add 10, multiply by 2."))
	fmt.Println(transpile("Think of a number."))
	fmt.Println(transpile("Think of a number, divide by 5, subtract from 9."))
	fmt.Println(transpile("Think of a number, add 5, add 10, multiply by 2, subtract 15, repeat, divide by 2."))
	fmt.Println(transpile("Think of a number, subtract 1, repeat, repeat."))
}

func transpile(src string) string {
	fmts := [][2]string{
		{"add %d", "a += %d"},
		{"subtract %d", "a -= %d"},
		{"divide by %d", "a /= %d"},
		{"multiply by %d", "a *= %d"},
		{"subtract from %d", "a = %d - a"},
	}

	var prev, cur string
	out := new(bytes.Buffer)
	stmts := strings.Split(src, ",")
	for i, stmt := range stmts {
		stmt = strings.TrimSpace(stmt)
		stmt = strings.TrimSuffix(stmt, ".")

		switch {
		case i == 0:
			if stmt != "Think of a number" {
				return "Error: Invalid start statement"
			}
			cur = "int a = 0;\n"
			cur += `scanf("%d", &a);`
		case stmt == "repeat" && prev != "":
			cur = prev
		default:
			for _, xfmt := range fmts {
				var val int
				n, _ := fmt.Sscanf(stmt, xfmt[0], &val)
				if n == 1 {
					cur = fmt.Sprintf(xfmt[1]+";", val)
					goto next
				}
			}

			return fmt.Sprintf("Error: invalid statement %q at index %d", stmt, i+1)
		}

	next:
		fmt.Fprintln(out, cur)
		prev = cur
	}

	fmt.Fprintln(out, `printf("%d\n", a);`)
	fmt.Fprintln(out)
	return out.String()
}
