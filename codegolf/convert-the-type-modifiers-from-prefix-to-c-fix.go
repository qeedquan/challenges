/*

Given a base type T, this can be augmented with * or [], each meaning pointer and array. For example, []*T means "array of pointer to T" and *[]T means "pointer to array of T".

Let's call * and [] type modifiers. C has a way of ordering these modifiers tied to the evaluation order. []*T in C-style becomes T *[], and *[]T becomes T (*)[]. You may be able to understand how the conversion works by having a look at the examples below. An explanation is also given at the end of this post.

* -> *
[] -> []
[]* -> *[]
*[] -> (*)[]
*[]* -> *(*)[]
[]*[] -> (*[])[]
*[][]* -> *(*)[][]
[]**[] -> (**[])[]
[]*[]* -> *(*[])[]
*[]*[] -> (*(*)[])[]
Your program or function should process an input string to an output string as the examples above. The input will only contain * and [] without whitespaces.

This challenge is this challenge in reverse, simplified.

Rules for C-fix:

All of the *s always come before all of the []s (in real C code, the variable name comes between the last * and the first []).
Evaluation starts in the middle, where the variable name would be.
If there is both a * on the left and a [] on the right, without any parentheses to determine the order, the [] is bound first, and comes first in prefix:
C-fix *[]
= C *a[] (where a is the variable name) = "array of pointers" =
prefix []*.
In order to change the order of evaluation so that a * gets bound first, it must be put in parentheses (with where the variable name would be):
prefix *[]
= "pointer to an array" = C (*a)[](where a is the variable name) =
C-fix (*)[].
From the last example, (*(*)[])[] in actual C code would be something like int (*(*a)[])[] (where a is the variable name). The evaluation starts from a and [] is bound first unless a set of parentheses blocks the binding.

If you put int (*(*a)[])[] to cdecl.org, the output is "declare a as pointer to array of pointer to array of int". This is because:

The first * is bound first due to the parentheses.
There are no parentheses between the variable name and the [], causing that to be bound before the next *.
Then, the next * is bound because it is in the parentheses with the variable name, whereas the remaining [] is not.
Finally, the remaining [] is bound.
This is *[]*[]int a in prefix. Hence, *[]*[] -> (*(*)[])[].

*/

package main

import (
	"strings"
)

func main() {
	assert(cfix("*") == "*")
	assert(cfix("[]") == "[]")
	assert(cfix("[]*") == "*[]")
	assert(cfix("*[]") == "(*)[]")
	assert(cfix("*[]*") == "*(*)[]")
	assert(cfix("[]*[]") == "(*[])[]")
	assert(cfix("*[][]*") == "*(*)[][]")
	assert(cfix("[]**[]") == "(**[])[]")
	assert(cfix("[]*[]*") == "*(*[])[]")
	assert(cfix("*[]*[]") == "(*(*)[])[]")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cfix(s string) string {
	p := ""
	for _, r := range s {
		switch r {
		case '*':
			p = string(r) + p
		default:
			if strings.HasPrefix(p, "*") {
				p = "(" + p + ")"
			}
			p += string(r)
		}
	}
	return p
}
