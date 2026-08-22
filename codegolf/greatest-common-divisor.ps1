#!/usr/bin/env pwsh

<#

Your task is to compute the greatest common divisor (GCD) of two given integers in as few bytes of code as possible.

You may write a program or function, taking input and returning output via any of our accepted standard methods (including STDIN/STDOUT, function parameters/return values, command-line arguments, etc.).

Input will be two non-negative integers. You should be able to handle either the full range supported by your language's default integer type, or the range [0,255], whichever is greater. You are guaranteed that at least one of the inputs will be non-zero.

You are not allowed to use built-ins that compute either the GCD or the LCM (least common multiple).

Standard code-golf rules apply.

Test Cases
0 2     => 2
6 0     => 6
30 42   => 6
15 14   => 1
7 7     => 7
69 25   => 1
21 12   => 3
169 123 => 1
20 142  => 2
101 202 => 101

#>

function gcd($a, $b) {
	while ($b -ne 0) {
		$t = $b
		$b = $a % $b
		$a = $t
	}
	return $a
}

gcd 0 2
gcd 6 0
gcd 30 42
gcd 15 14
gcd 7 7
gcd 69 25
gcd 21 12
gcd 169 123
gcd 20 142
gcd 101 202
