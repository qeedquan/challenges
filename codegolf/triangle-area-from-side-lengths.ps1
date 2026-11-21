#!/usr/bin/env pwsh

<#

Output the area A of a triangle given its side lengths a,b,c as inputs. This can be computed using Heron's formula:

A = sqrt(s(s-a)(s-b)(s-c)), where s = (a+b+c)/2

This can be written in various ways, such as

A = 1/4 * sqrt((a+b+c)(-a+b+c)(a-b+c)(a+b-c))
A = 1/4 * sqrt((a^2 + b^2 + c^2) - 2(a^4 + b^4 + c^4))

See Wikipedia for more. Related: What are my dimensions?

The inputs will be three positive integers that satisfy the triangle inequality and so are sides of a non-degenerate triangle. While the order of the three sides doesn't affect the output, you may not assume they're given in a particular order like sorted. You may take inputs in a list or tuple or the like. Any reasonable float output is fine.

Test cases

1 1 1 -> 0.4330
3 4 5 -> 6.0000
9 3 7 -> 8.7856

#>

function heron($a, $b, $c) {
	$s = ($a + $b + $c) * 0.5
	return [Math]::sqrt($s * ($s - $a) * ($s - $b) * ($s - $c))
}

function main() {
	heron 1 1 1
	heron 3 4 5
	heron 9 3 7
}

main
