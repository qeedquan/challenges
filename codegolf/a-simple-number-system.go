/*

Let me tell you about a simple number system. (which I made up just for this challenge)

This system contains the functions (), [], {}, and <>.

1. ()
When () is given no arguments, it evaluates to 0.

When () is given one or more arguments, it evaluates to the sum of the arguments.

2. []
When [] is given no arguments, it evaluates to -1.

When [] is given one or more arguments, it evaluates to the first argument minus the sum of the other arguments.

3. {}
When {} is given no arguments, it evaluates to 1.

When {} is given one or more arguments, it evaluates to the product of those arguments.

4. <>
When <> is given no arguments, it evaluates to 1.

When <> is given one or more arguments, it evaluates to the first argument integer divided by the product of the other arguments.

Your task
Given a string that contains a valid number (that means brackets are balanced, no division by 0s, etc.) in this simple number system, print its value.

Test cases
() -> 0
(()()) -> 0
([][]) -> -2
({}<>) -> 2
({}[]) -> 0
[] -> -1
[[][]] -> 0
[()<>] -> -1
{()} -> 0
{([]<>)} -> 0

Remember, this is code-golf, so the code with the fewest bytes wins.

*/

package main

import "fmt"

func main() {
	test("()", 0)
	test("(()())", 0)
	test("([][])", -2)
	test("({}<>)", 2)
	test("({}[])", 0)
	test("[]", -1)
	test("[[][]]", 0)
	test("[()<>]", -1)
	test("{()}", 0)
	test("{([]<>)}", 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r int) {
	v, err := eval(s)
	fmt.Println(v, err)
	assert(err == nil)
	assert(v == r)
}

type Scope struct {
	op   rune
	args []int
}

func eval(s string) (int, error) {
	p := []Scope{{}}
	for i, r := range s {
		var err error
		switch r {
		case '(', '[', '{', '<':
			p = append(p, Scope{
				op: r,
			})
		case ')':
			err = xec(&p, '(', xadd)
		case ']':
			err = xec(&p, '[', xsub)
		case '}':
			err = xec(&p, '{', xmul)
		case '>':
			err = xec(&p, '<', xdiv)
		default:
			err = fmt.Errorf("%d: invalid character %q", i, r)
		}

		if err != nil {
			return 0, fmt.Errorf("%d: %v", i, err)
		}
	}

	if len(p) != 1 || len(p[0].args) != 1 {
		return 0, fmt.Errorf("unclosed expression")
	}

	return p[0].args[0], nil
}

func xec(p *[]Scope, op rune, f func([]int) int) error {
	n := len(*p)
	if n < 2 {
		return fmt.Errorf("invalid expression")
	}

	x := &(*p)[n-1]
	y := &(*p)[n-2]
	*p = (*p)[:n-1]
	if x.op != op {
		return fmt.Errorf("unmatched closing parentheses: %q", op)
	}
	y.args = append(y.args, f(x.args))

	return nil
}

func xadd(a []int) int {
	r := 0
	for i := range a {
		r += a[i]
	}
	return r
}

func xsub(a []int) int {
	n := len(a)
	if n == 0 {
		return -1
	}

	r := a[0]
	for i := 1; i < n; i++ {
		r -= a[i]
	}
	return r
}

func xmul(a []int) int {
	r := 1
	for i := range a {
		r *= a[i]
	}
	return r
}

func xdiv(a []int) int {
	n := len(a)
	if n == 0 {
		return 1
	}

	r := a[0]
	p := 1
	for i := 1; i < n; i++ {
		p *= a[i]
	}
	if p != 0 {
		r /= p
	}
	return r
}
