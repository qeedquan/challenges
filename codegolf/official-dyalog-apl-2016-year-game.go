/*

If you think this could be fun, but too much work, consider participating in this much smaller challenge.

A bit of fun (and possibly frustration!) for 2016... Dyalog's "puzzle of the year". Enjoy!

The Objective
Find Dyalog APL (download) expressions (other languages are allowed, see Eligibility below) involving exactly the digits 2 0 1 6 in that order to equal the numbers 0 to 100. For example:

20=16
×2016
2⌊016
2+0+1*6
...

The aim is to use as few characters as possible in each expression (the minimum number of characters for an expression is 5 – the four digits 2 0 1 6 and a single primitive function/operator).

The Rules
Each expression must contain the digits 2 0 1 6 (in that order) and no other digits. Pre-set constants and variables are also not allowed.
In addition to the four digits 2 0 1 6, only built-in symbols and names, parentheses/braces, spaces, high minus signs and decimal points can be used. The resultant expressions must be deterministic (that is, give the same result on repeated evaluations). For non-APLs, functions/operators with a name are also allowed; same rules as here.
Assume all default settings for your language. For Dyalog APL, this means ⎕ML and ⎕IO are both 1, and ⎕PP is 10.
Each entry comprising correct expressions for all the numbers from 0 to 100 inclusive will be rated according to the number of characters used by those expressions excluding redundant spaces (minimum 505 for all 101 expressions).
Eligibility
Anyone can enter. You may answer in any language, but only APL answers will be considered for accepting. If you use another language than APL, you may use snippets, programs, functions, etc. as alternatives to expressions, and you may print, leave the number in an accessible memory location, or otherwise return the result, as long as your code directly evaluates to the desired number as any standard numeric data type for your language.

Closing Date
30 November 2016.

Prizes
Have your answer accepted
Be immortalised in Dyalog's 2016 Hall of Fame!
Submitting Your Entry
After 30 November 2016, I will accept the shortest answer, and submit your answer, in your name, to Dyalog's 2016 Hall of Fame.

FAQ
Is J (e.g. 37=⌈⍟!20J16) allowed?
No: In addition to the four digits 2 0 1 6, only only built-in symbols and names, parentheses/braces, spaces, high minus signs and decimal points can be used.

Is output as a string acceptable?
No: equal the numbers 0 to 100.

Physical digits, or data digits?
Data digits, as per OP: same rules as here, where one of the examples contain LOG10(.

Is assigning variables then using them as part of the expression (e.g. 56=a+16+a←20) allowed?
Yes, but you may not use an assignment from one expression in another one.
I have explicit written permission to post this challenge here from the original author of this challenge. Feel free to verify by following the provided link and contacting the author. I gave the original competition author the link to this page within the minute I posted it, so they can check if I submit someone's answer as my own.

*/

package main

import "fmt"

func main() {
	fmt.Println(201 & 6)
	fmt.Println(2 - 01%6)
	fmt.Println(2 % 016)
	fmt.Println(201 % 6)
	fmt.Println(20 - 16)
	fmt.Println(201 % ^6)
	fmt.Println(2%01 + 6)
	fmt.Println(2 - 01 + 6)
	fmt.Println(2*01 + 6)
	fmt.Println(2 + 01 + 6)
	fmt.Println(^2 + 016)
	fmt.Println(^2 + 016)
	fmt.Println(2 ^ 016)
	fmt.Println(20 - 1 - 6)
	fmt.Println(2 | 016)
	fmt.Println(20 + 1 - 6)
	fmt.Println(2 + 016)
	fmt.Println(2 - ^016)
	fmt.Println(2 + 0 + 16)
	fmt.Println(20 - 1%6)
	fmt.Println(20 | 16)
	fmt.Println(20 + 1%6)
	fmt.Println(20*1 | 6)
	fmt.Println(20 | 1 | 6)
	fmt.Println(20 + ^1 + 6)
	fmt.Println(20 - 1 + 6)
	fmt.Println(20*1 + 6)
	fmt.Println(20 + 1 + 6)
	fmt.Println(2 * 016)
	fmt.Println(20 - ^1 - ^6)
	fmt.Println(-2 * ^016)
	fmt.Println(20 | ^-16)
	fmt.Println((2 + 0) * 16)
	fmt.Println(20*^1 ^ ^6)
	fmt.Println(-20*^1 - 6)
	fmt.Println(20 + ^-16)
	fmt.Println(20 + 16)
	fmt.Println(20 - ^16)
	fmt.Println(20 - ^-^16)
	fmt.Println(-^2 * ^-016)
	fmt.Println(20 << (1 % 6))
	fmt.Println(^-(-^2 * 016))
	fmt.Println(^2 * -016)
	fmt.Println(^20 ^ -1<<6)
	fmt.Println(^20*^1 ^ 6)
	fmt.Println(^2 * ^016)
	fmt.Println(20<<1 | 6)
	fmt.Println(-20*^1 - ^6)
	fmt.Println(^20*^1 + 6)
	fmt.Println(^20*^1 - ^6)
	fmt.Println(-20 / ^1 * ^-6)
	fmt.Println(^2 * ^-^-^016)
	fmt.Println(20 | 1<<^-6)
	fmt.Println(-20*^-^1 + ^6)
	fmt.Println(20*-^-^1 - 6)
	fmt.Println(-20*^-^1 - ^-6)
	fmt.Println(^-^2 * -016)
	fmt.Println(^20*^-^1 - 6)
	fmt.Println(-20*^-^1 ^ 6)
	fmt.Println(^(20 / ^1 * 6))
	fmt.Println(-20 / ^1 * 6)
	fmt.Println(^2 ^ (0-1)<<6)
	fmt.Println(-2 ^ (0-1)<<6)
	fmt.Println(^20 / ^1 * 6)
	fmt.Println((2 - 01) << 6)
	fmt.Println((2 + ^0) | 1<<6)
	fmt.Println(2 | 01<<6)
	fmt.Println(2 - ^0 | 1<<6)
	fmt.Println(^-^2 * ^16)
	fmt.Println(^20*^-^1 + 6)
	fmt.Println(20 / ^1 * ^6)
	fmt.Println(-^(20 / ^1 * ^6))
	fmt.Println(^-^2 * ^-^16)
	fmt.Println(-20<<-^1 ^ ^6)
	fmt.Println(-20<<-^1 ^ -6)
	fmt.Println(^-^-^2 * ^016)
	fmt.Println(^-20 * (^1 + 6))
	fmt.Println(^-^20 / ^1 * -^6)
	fmt.Println(^-20<<-^1 | 6)
	fmt.Println(^-(20 * ^(1 - 6)))
	fmt.Println(20 * (^1 + 6))
	fmt.Println(-^(20 * ^(1 - 6)))
	fmt.Println(^-^-20 | 1<<6)
	fmt.Println(^-20 | 1<<6)
	fmt.Println(20 | 1<<6)
	fmt.Println(-^20 | 1<<6)
	fmt.Println(20<<-^1 | 6)
	fmt.Println(20<<-^1 | -^6)
	fmt.Println(-^-^20 * (^1 + 6))
	fmt.Println(^20*^-^-^1 + ^-6)
	fmt.Println(^-^-20 * -(1 - 6))
	fmt.Println(^20*^-^-^1 - ^6)
	fmt.Println(^20*^-^-^1 - ^-^6)
	fmt.Println(^2 ^ ^-^01<<^-6)
	fmt.Println(-2 ^ ^-^01<<^-6)
	fmt.Println(^-20 * 1 * ^-6)
	fmt.Println((2 + 01) << ^-6)
	fmt.Println(-^(^2 * ^-^0 * 16))
	fmt.Println(^-^-(20 * -(1 - 6)))
	fmt.Println(^-(20 * 1 * ^-6))
	fmt.Println(20 * -(1 - 6))
}
