/*

(2 Jan 2018) Because of the winning criteria I am going to accept the Jelly answer, but I am also giving upvotes to all other answers which all use astounding methods as well

Introduction
There are lots of challenges asking for a shortest program to calculate mathematical constants. I saw some with restrictions like banning the literals 3.14 and π etc. However, there seems no such challenges using the number of distinct characters as one of the criteria.

The Challenge
Make a Plain PIE using the fewest kinds and least amount of ingredients but still yummy enough

Write a code that calculates π*e to at least 10 decimal places, that uses as FEW distinct characters (and de facto numeric literal characters) and as short as possible.

This challenge is not banning numeric literals; instead they are discouraged. Numeric literals are seasonings ;)

Requirements
The code must be a full program receiving no inputs and outputting the result, or a function which can be called with no arguments either outputting or returning the result. Lambdas are allowed.
The result must start with 8.5397342226 and must be in a numeric type. There should only be one output/return in the main program/function. Sub-functions are allowed.
Restrictions
String-to-number conversion functions that trivially turn the string literal to a number it represents are not allowed unless explicitly declared and implemented within the code. Also, NO implicit conversions from strings to numbers.
eg. eval, Number(), parseInt() and "string" * 1
Character-code functions and length functions like ord, String.charCodeAt(n) and String.length are allowed because they do not trivially convert the string into the corresponding number.
Use of the following built-ins are not allowed:
Mathematical constants, or any built-in functions that evaluates to those constants directly
eg. Math.PI in JS, žs in 05AB1E (because it evaluates to π directly)
Trigonometric functions and the exponential function, unless explicitly defined and implemented in the code.
eg. Math.atan and Math.exp in JS
Built-in power functions and exponentiation operators (eg. ** or ^) are allowed, given that they receive 2 arguments/operands (WLOG a and b) and returns ab
The length of each run of numeric literal used must not be longer than 5 (eg. 12345 allowed (but not encouraged), but 123456 is not allowed).
Standard loopholes apply.
Scoring
The scoring is divided into three parts:
Distinctness: Scored by counting the number of distinct characters used. Uppercase and lowercase are counted separately. However, the following characters must each be counted as 10 characters:
Hexadecimal digits: 0123456789abcdefABCDEF
Decimal points: .
Any other single characters that may be used as numeric literals (applicable in golfing languages)
Size: Scored by the length of the code in bytes.
Accuracy: Scored by the number of correct digits counting from the decimal point. Any digits after the first wrong digit are not counted. For fairness, a maximum of 15 digits are counted. The value of π*e according to WolframAlpha is 8.539734222673567(06546...).
The total score is calculated by (Distinctness * Size) / Accuracy
Winning Criteria
The answer with the lowest score wins. If tied then the candidate answer which is posted earlier wins.

For non-golfing languages, the score can be calculated using the following snippet (For some golfing languages, the snippet does not work since this checks for UTF-8 length of the code only):

Show code snippet

Example
Submission

JavaScript(ES6), S=141, D=49, A=12, 575.75pt
(t=()=>{for(f=o=9/9;++o<9999;)f+=o**-(9>>9/9);return (f*(9*9+9))**(9/9/(9>>9/9))},u=()=>{for(f=o=r=9/9;++o<99;){f+=r;r/=o}return f})=>t()*u()
Output: 8.53973422267302

Scoring

Size        : 141 bytes
Distinctness: 49 (Numerals: 3 (use of "9", "e" and "f")), Non-numerals: 19)
Accuracy    : 12 decimal places
Score       : 575.75

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(pie(), math.Pi*math.E)
}

func pie() float64 {
	return 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0 + 1.0/(1.0+1.0/(1.0+1.0/(1.0+1.0+1.0+1.0+1.0+1.0/(1.0+1.0/(1.0+1.0+1.0+1.0/(1.0+1.0/(1.0+1.0+1.0+1.0+1.0/(1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0/(1.0+1.0+1.0+1.0/(1.0+1.0+1.0/(1.0+1.0/(1.0+1.0+1.0+1.0+1.0+1.0/(1.0+1.0+1.0/(1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0+1.0/(1.0+1.0/(1.0+1.0))))))))))))))))
}
