/*

Imagine a very simple language. It has just 2 syntax features: () indicates a block scope, and any word consisting only of 1 or more lower case ASCII letters, which indicates a identifier. There are no keywords.

In this language, the value of identifiers is not important except when they appear multiple times. Thus for golfing purposes it makes sense to give them names that are as short as possible. A variable is "declared" when it is first used.

The goal of this challenge is to take a program, either as a string or as a ragged list, and make the identifiers as short as possible. The first identifier (and all its references) should be re-named to a, the next b then so on. There will never be more than 26 identifiers.

Each set of () encloses a scope. Scopes can access variables created in the parent scope defined before but not those created in child or sibling scopes. Thus if we have the program (bad (cab) (face)) the minimum size is (a (b) (b)). A variable belongs to the scope when it is first used. When that scope ends the variable is deleted.

In summary:
If a variable name has appeared in the scope or enclosing scopes before, re-use the letter
Else create a new letter inside the current scope
At the end of a scope delete all variables created inside the scope.
Test cases
{
    "(rudolf)":                   "(a)",
    "(mousetail mousetail)":      "(a a)",
    "(cart fish)":                "(a b)",
    "(no and no)":                "(a b a)",
    "(burger (and fries))":       "(a (b c))",
    "(burger (or burger))":       "(a (b a))",
    "(let (bob and) (bob let))":  "(a (b c) (b a))",
    "(let (a (fish (let))))":     "(a (b (c (a))))",
    "(kor (kor kor) (kor kor))":  "(a (a a) (a a))",
    "((kor) kor)":                "((a) a)",
    "(aa (ab ac ad) (ad ad) ad)": "(a (b c d) (b b) b)",
    "(aa not (ab ac ad) (ad ad))":"(a b (c d e) (c c))",
    "(((((do) re) mi) fa) so)":   "(((((a) a) a) a) a)",
    "(do (re (mi (fa (so)))))":   "(a (b (c (d (e)))))",
    "((mark sam) sam)":           "((a b) a)",
}

IO
You can take input as either a string or ragged array.
You can give output either as a string or ragged array.
However, you must use the same format for input and output. Specifically, you need to produce output in such a way that it would also be a valid input. Applying the function or program more than once always has the same result as applying it once.
Neither scopes nor variable names may be empty. Applying your program to its result again should be a no-op.

*/

package main

import (
	"bytes"
	"fmt"
	"unicode"
)

func main() {
	assert(minify("(rudolf)") == "(a)")
	assert(minify("(mousetail mousetail)") == "(a a)")
	assert(minify("(cart fish)") == "(a b)")
	assert(minify("(no and no)") == "(a b a)")
	assert(minify("(burger (and fries))") == "(a (b c))")
	assert(minify("(burger (or burger))") == "(a (b a))")
	assert(minify("(let (bob and) (bob let))") == "(a (b c) (b a))")
	assert(minify("(let (a (fish (let))))") == "(a (b (c (a))))")
	assert(minify("(kor (kor kor) (kor kor))") == "(a (a a) (a a))")
	assert(minify("((kor) kor)") == "((a) a)")
	assert(minify("(aa (ab ac ad) (ad ad) ad)") == "(a (b c d) (b b) b)")
	assert(minify("(aa not (ab ac ad) (ad ad))") == "(a b (c d e) (c c))")
	assert(minify("(((((do) re) mi) fa) so)") == "(((((a) a) a) a) a)")
	assert(minify("(do (re (mi (fa (so)))))") == "(a (b (c (d (e)))))")
	assert(minify("((mark sam) sam)") == "((a b) a)")
	assert(minify("(no and no)") == "(a b a)")
	assert(minify("(burger (and fries))") == "(a (b c))")
	assert(minify("(burger (or burger))") == "(a (b a))")
	assert(minify("(let (bob and) (bob let))") == "(a (b c) (b a))")
	assert(minify("(let (a (fish (let))))") == "(a (b (c (a))))")
	assert(minify("(kor (kor kor) (kor kor))") == "(a (a a) (a a))")
	assert(minify("((kor) kor)") == "((a) a)")
	assert(minify("(aa (ab ac ad) (ad ad) ad)") == "(a (b c d) (b b) b)")
	assert(minify("(aa not (ab ac ad) (ad ad))") == "(a b (c d e) (c c))")
	assert(minify("(((((do) re) mi) fa) so)") == "(((((a) a) a) a) a)")
	assert(minify("(do (re (mi (fa (so)))))") == "(a (b (c (d (e)))))")
	assert(minify("((mark sam) sam)") == "((a b) a)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func minify(s string) string {
	w := new(bytes.Buffer)
	b := new(bytes.Buffer)
	p := []map[string]rune{}
	for _, r := range s {
		if !(unicode.IsSpace(r) || r == '(' || r == ')') {
			b.WriteRune(r)
			continue
		}

		fmt.Fprintf(w, "%s%c", mapto(b, p), r)
		switch r {
		case '(':
			p = append(p, make(map[string]rune))
		case ')':
			if n := len(p); n > 0 {
				p = p[:n-1]
			}
		}
	}
	fmt.Fprint(w, mapto(b, p))
	return w.String()
}

func mapto(b *bytes.Buffer, p []map[string]rune) string {
	s := b.String()
	d := len(p) - 1
	b.Reset()
	if s == "" || d < 0 {
		return s
	}

	v := 0
	for n := d; n >= 0; n-- {
		if p[n][s] != 0 {
			return string(p[n][s])
		}
		v += len(p[n])
	}
	p[d][s] = rune('a' + v)

	return string(p[d][s])
}
