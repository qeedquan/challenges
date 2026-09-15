/*

Story
Have you seen this post from 9gag? Maybe you got the feeling to make your own sentences. But then you realize that you could just golf a script in half an hour, and you will never have to deal time with that.

The submission
Your program will get an input string which it will return with added quotation marks as explained below. Standard loopholes are forbidden. Output as a list of lines is allowed. Trailing spaces and empty lines that don't break the output are allowed.

The rules of input
The input only contains printable ASCII characters.
The input may contain spaces. The words are determined with them.
It's guaranteed that a space will never be followed by another space.
The case of no input or empty string doesn't matter.
The rules of output
If one word is given then the program has to return the string between quotation marks.

If the input string has 2 or more words, it first returns the initial input, but the first word is in quotation marks. Then on the next line, it returns the initial input, but with the second word in quotes. And so on for the remaining words.

In general, the program has to return as many lines as there are words in the input.

Examples:
test -> "test"

This is codegolf -> "This" is codegolf
                    This "is" codegolf
                    This is "codegolf"

This is a significantly longer, but not the longest testcase -> "This" is a significantly longer, but not the longest testcase
                                                                This "is" a significantly longer, but not the longest testcase
                                                                This is "a" significantly longer, but not the longest testcase
                                                                This is a "significantly" longer, but not the longest testcase
                                                                This is a significantly "longer," but not the longest testcase
                                                                This is a significantly longer, "but" not the longest testcase
                                                                This is a significantly longer, but "not" the longest testcase
                                                                This is a significantly longer, but not "the" longest testcase
                                                                This is a significantly longer, but not the "longest" testcase
                                                                This is a significantly longer, but not the longest "testcase"

Here is an another one -> "Here" is an another one
                          Here "is" an another one
                          Here is "an" another one
                          Here is an "another" one
                          Here is an another "one"

This is code-golf, so the least byte answer wins!

*/

package main

import (
	"fmt"
	"reflect"
	"strings"
)

func main() {
	test("test", []string{
		`"test"`,
	})

	test("This is codegolf", []string{
		`"This" is codegolf`,
		`This "is" codegolf`,
		`This is "codegolf"`,
	})

	test("This is a significantly longer, but not the longest testcase", []string{
		`"This" is a significantly longer, but not the longest testcase`,
		`This "is" a significantly longer, but not the longest testcase`,
		`This is "a" significantly longer, but not the longest testcase`,
		`This is a "significantly" longer, but not the longest testcase`,
		`This is a significantly "longer," but not the longest testcase`,
		`This is a significantly longer, "but" not the longest testcase`,
		`This is a significantly longer, but "not" the longest testcase`,
		`This is a significantly longer, but not "the" longest testcase`,
		`This is a significantly longer, but not the "longest" testcase`,
		`This is a significantly longer, but not the longest "testcase"`,
	})

	test("Here is an another one", []string{
		`"Here" is an another one`,
		`Here "is" an another one`,
		`Here is "an" another one`,
		`Here is an "another" one`,
		`Here is an another "one"`,
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := quotes(s)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func quotes(s string) []string {
	r := []string{}
	t := strings.Split(s, " ")
	for i := range t {
		t[i] = `"` + t[i] + `"`
		r = append(r, strings.Join(t, " "))
		t[i] = t[i][1 : len(t[i])-1]
	}
	return r
}
