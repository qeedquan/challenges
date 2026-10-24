/*

Chained Binary Operations
Here's a challenge involving truth tables and binary operations. For this specific challenge, your task is to use the following table of operations:

https://i.sstatic.net/y1rjR.png

To create a function that takes in two inputs f(p,a), where p is the initial truthy/falsy value and a is a list of tuples representing multiple values of q and the operations to be performed. For instance, f(T,[[T,0],[T,1]]) would return ContradictionOP(T,T)=F. You would then chain the output of this result into the next operation, which would be LogicalNOR(F,T)=F, where the 2nd p is the previous output of F. The final result being false. A better breakdown of what each operation actually is is described below:

https://i.sstatic.net/lsqqE.png

The first part should be rather simplistic in nature, as the operators are arranged in an increasing binary pattern (hint, hint). However, recursing through the additional inputs to chain binary operations is probably the harder part to accomplish.

Examples:
f(T,[])=T
f(F,[[F,15]])=T
f(T,[[F,15],[T,0],[F,6]])=F
f(T,[[F,15],[F,14],[F,13],[F,12],[F,11]])=F

Extrapolated Example:
f(T,[[F,15],[F,14],[F,13],[F,12],[F,11]])=F
[T,[F,15]]=T*
[T*,[F,14]=T*
[T*,[F,13]=T*
[T*,[F,12]=T*
[T*,[F,11]=F
FALSE.

Rules:
You MUST use the order specified for the operations as stated above.
The input format for a can be a 2D array, array of tuples, command line pairwise arguments or any other representation of pairs of boolean/operations. Could even be a single array that you parse pairwise.
You may use 0 for false and 1 for true, it is not acceptable to reverse the two.
The output should be simply a truthy or falsy value.
No loopholes, this is code-golf, standard CG rules apply.

Example Single Iteration Algorithm:

f={
    p,q,o->
    op=Integer.toBinaryString(o);     // Calculate the binary OP string (15=1111)
    binaryIndex="$p$q"                // Calculate binary combination of p/q (T/F=10)
    i=Integer.parseInt(binaryIndex,2) // Convert to decimal index (T/F=2)
    op.charAt(i)                      // Get the binary char at the calculated index (T/F/15=1).
}
f(1,0,15)                             // "1"

*/

package main

import "fmt"

func main() {
	const (
		T = 1
		F = 0
	)

	assert(chain(T, [][2]int{}) == T)
	assert(chain(F, [][2]int{{F, 15}}) == T)
	assert(chain(T, [][2]int{{F, 15}, {T, 0}, {F, 6}}) == F)
	assert(chain(T, [][2]int{{F, 15}, {F, 14}, {F, 13}, {F, 12}, {F, 11}}) == F)

	table()
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @Neil solution
func chain(p int, a [][2]int) int {
	l := p
	for _, x := range a {
		l = (x[1] >> (l + l + x[0])) & 1
	}
	return l
}

func table() {
	sym := [2]rune{'F', 'T'}
	for i := 3; i >= 0; i-- {
		p := (i >> 1) & 1
		q := i & 1
		fmt.Printf("%c %c | ", sym[p], sym[q])
		for f := 0; f < 16; f++ {
			r := chain(p, [][2]int{{q, f}})
			fmt.Printf("%c ", sym[r])
		}
		fmt.Println()
	}
}
