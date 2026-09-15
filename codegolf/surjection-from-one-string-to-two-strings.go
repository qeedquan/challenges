/*

This is the inverse of negative seven's question.
https://codegolf.stackexchange.com/questions/193640/injection-from-two-strings-to-one-string

Write a program or function which, given any single, possibly-empty string of printable ASCII (codes [32,126]) outputs or returns two strings of printable ASCII.

For any two ordered, possibly empty strings s1 and s2, there must be third string s0, which input to your program, outputs s1 and s2.

In other words, if S is the set of all ASCII strings (including the empty string):

f is well-defined on S: (∀s∈S)(f(s)∈S×S)

f is a surjection to S×S: (∀s1,s2∈S)(∃s0∈S)(f(s0)=(s1,s2))

Test cases:
For each of these strings (surrounding «quotes» excluded), your output should be two strings:

«»
«hello world»
«'one' 'two' 'three' 'four'»
«"one" "two" "three" "four"»
«["one", "two", "three"]»
«; exit()»
For each of these pairs of strings, there must be at least one string you can provide to your program such that that pair is output (surrounding «quotes» excluded):

 s_1     |  s_2
---------|----------
«hello » | «world»
«hell»   | «o world»
«hello»  | « world»
« »      | «»
«»       | « »
«»       | « !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~»
«\r\n»   | «\r\n»

As always, you are encouraged to add test cases pertinent to your method.

Rules:
Input must be a single string/character array/byte array consisting of only ASCII characters.
Output is ordered; (a,b)≠(b,a). Output can be any ordered structure in your language, or printed with a newline (LF or CR LF) separator and optional trailing newline.
I/O must be consistent. If one case handles input as an argument and outputs to stdout with a trailing newline, all cases must handle input as an argument and output to stdout with a trailing newline.
Standard loopholes are forbidden.
This is code-golf, so shorter programs are better!
As a reminder, this is only a surjection, not a bijection: Your program/function will likely map many different strings to the same output.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(split(``))
	fmt.Println(split(`some normalish string, like, almost all strings`))
	fmt.Println(split(`exit(0)`))
	fmt.Println(split(`the book of e_xodus has an `))
	fmt.Println(split(join(`any given string`, `any other given string`)))
	fmt.Println(split(join(`any _xxxx_ string`, `any otherxx given string`)))
	fmt.Println(split(join(`any given string`, ``)))
	fmt.Println(split(join(``, `any other given string`)))
	fmt.Println(split(join(``, ``)))
	fmt.Println(split(join(`hello`, `world`)))
}

/*

@xnor

A tempting idea for the inverse is to encode the pair of input strings by putting some separator string in between them. That way, we can extract the pair by splitting on this separator. The issue is that the separator may appear in the inputs string.

We get around this by making the separator longer than the total length of both strings. We use 1 followed by a number of 0's equal to the number of characters in both strings. For example,

abc, defgh -> abc100000000defgh
Note that no matter how many 0's and 1's are in the two inputs, there's no way to get another copy of the separator to appear.

We can recover the separator from the combined string by using a number of zeroes equal to half its length rounded down. I had wanted to compute this as 10**_, but Python's repr appends an annoying L to large numbers, which messes it up.

We need to the submission function still give two outputs when the input string doesn't contain the required separator. In this case, splitting just gives the original string, but we copy it twice to be compliant.

*/

func split(s string) (string, string) {
	p := "1" + strings.Repeat("0", len(s)/2)
	t := strings.Split(s, p)
	if len(t) == 1 {
		t = append(t, t[0])
	}
	return t[0], t[1]
}

func join(a, b string) string {
	return a + "1" + strings.Repeat("0", len(a+b)) + b
}
