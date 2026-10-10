/*

We start with the string a, and forever append to the string a comma followed by the string quote-escaped, where quote-escaping means doubling all quotes in a string, and then surrounding it with an additional pair of quotes.

In the first few steps we will get:

a
a,'a'
a,'a','a,''a'''
a,'a','a,''a''','a,''a'',''a,''''a'''''''
If we continue to do that forever, we get the following infinite string: a,'a','a,''a''','a,''a'',''a,''''a''''''','a,''a'',''a,''''a'''''',''a,''''a'''',''''a,''''''''a''''''''''''''','a,''a'',''a,''''a'''''',''a,''''a'''',''''a,'''...

If create a sequence, which is 1 at indices that string contains a quotes, we'll get the following sequence:

0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, ...
Alternatively, we can look at the indices of quotes, and get the following sequence (this is 0-indexed):

2, 4, 6, 9, 10, 12, 13, 14, 16, 19, 20, 22, 23, 25, 26, 29, 30, 31, 32, 34, 35, 36, 37, 38, 39, 40, 42, 45, 46, ...
Your task is to output one of these numeric sequences.

Rules
You can choose whether you use 0-indexing or 1-indexing.
If you output sequence 1, you can use any truthy/falsey values instead of 1/0, or any two different consistent values.
If you output sequence 2 (the one with the indices), you can choose if those indices use 0-indexing or 1-indexing.
You can use one of following output modes:
Take n as an input, and output the n-th element in the sequence.
Take n as an input, and output all elements in the sequence up to the n-th element.
Take no input, and output the entire sequence forever.
You can use any reasonable input/output format.
Standard loopholes are disallowed.
This is code golf, so the shortest code wins.

*/

package main

import (
	"bytes"
	"fmt"
	"reflect"
)

func main() {
	tab := []int{0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1}

	assert(reflect.DeepEqual(gen(len(tab)), tab))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@loopy walt

a=b="/"
while[print(end=b)]:b="/\%s\\"%repr(a)[1:-1];a+=b

Prints the entire sequence using / for 0 and \ for 1.

*/

func gen(n int) []int {
	w := new(bytes.Buffer)
	a := "/"
	b := "/"
	s := ""
	for {
		s = w.String()
		if len(s) >= n {
			break
		}

		fmt.Fprint(w, b)
		b = fmt.Sprintf("/\\%s\\", escape(a))
		a += b
	}

	r := []int{}
	for i := 0; i < n; i++ {
		r = append(r, truth(s[i] == '\\'))
	}
	return r
}

func escape(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		w.WriteRune(r)
		if r == '\\' {
			w.WriteRune(r)
		}
	}
	return w.String()
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}
