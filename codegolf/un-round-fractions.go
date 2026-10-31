/*

When you convert a fraction to a decimal number and you want to store that number, you often have to round it, because you only want to use a certain amount of memory. Let's say you can only store 5 decimal digits, then 5/3 becomes 1.6667. If you can store only 2 decimal digits it will be 1.7 (now assuming that it is always between 0 and 9.99...).

If you now try to reverse that process with 1.7 and you want to get your fraction back, that can be difficult, since you know that 1.7 is only a rounded number. Of course you can try 17/10 but that is rather an 'ugly' fraction compared to the 'elegant' 5/3.

So the goal is now finding the fraction a/b with the least denominator b, that results in the rounded decimal number when correctly rounded.

Details
The input contains a string with a number of 1 up to 5 digits that is between 0 (including) and 10 (not including) with a '.' after the first digit. Let's say n denotes the number of digits. The output must be a list/array of two integers [numerator, denominator] or a rational datatype (you can create your own or use built-in) where the numerator is non-negative and the denominator is positive. The fraction numerator/denominator must be equal to the input when correctly rounded to n digits (which means n-1 digits after the decimal point).

Restriction: only one loop statement allowed. This means that you can use only one single looping statement (like for or while or goto etc. as well as functional loops like map or fold that apply code to every element of a list/array) in your whole code, but you are free to 'abuse' it or use recursion etc.

You should write a function. If your language does not have functions (or even if it does), you can alternatively assume that the input is stored in a variable (or input via stdin) and print the result or write it to a file. The lowest number of bytes wins.

Rounding
The rounding should follow the 'conventional' rounding rules, i.e. if the last digit that will be cut off is 5 or greater, you will round up, and you will round down for any other cases, so e.g:

4.5494 will result when rounding to

1 digit: 5
2 digits: 4.5
3 digits: 4.55
4 digits: 4.549

Examples
Please include following test cases and other 'interesting' ones:

Input 1.7     Output 5/3
Input 0.      Output 0/1
Input 0.001   Output 1/667
Input 3.1416  Output 355/113

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(unround("1.7"))
	fmt.Println(unround("0."))
	fmt.Println(unround("0.001"))
	fmt.Println(unround("3.1416"))
}

func unround(s string) *big.Rat {
	r := new(big.Rat)
	f := new(big.Float)
	f.SetString(s)
	f.Rat(r)
	return r
}
