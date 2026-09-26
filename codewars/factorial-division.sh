#!/bin/sh

cat << EOF >/dev/null

You have to define a function to calculate the division of two factorial numbers. This can be useful for large numbers.

In mathematics, the factorial of integer n is written as n!. It is equal to the product of n and every integer preceding it. For example: 5! = 5 * 4 * 3 * 2 * 1 = 120.

Some hints: We can see that (n + 1)! = (n + 1) * n!. So (n + 1)! / n! = (n + 1)

We know that 0! = 1 (because n! = (n + 1)! / (n + 1) therefore 0! = 1! / 1 = 1)

And your solution should be able to calculate n! / d!.

*** Please, don't worry about the parameters. You will only receive positive integers, and the first one will be greater than the second one

EOF

initbc() {
	funcs=$(cat)
}

initbc << EOF

define factdiv(n, d) {
	scale = 0
	if (n < 0 || d < 0) {
		return 0
	}
	r = 1
	for (i = d + 1; i <= n; i++) {
		r *= i
	}
	return r
}

EOF

factdiv() {
	echo "$funcs; factdiv($1, $2)" | bc -l
}

factdiv 5 3
factdiv 8 5
factdiv 10000 9999
factdiv 98 90
factdiv 262 256
factdiv 9741 9737

