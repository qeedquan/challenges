/*

Input:

An integer.

Output:

First convert the integer to it's equivalent Roman Numeral.
Then convert each capital letter of that Roman Numeral to their ASCII/UNICODE decimal value.
And output the sum of those.
Example:

1991 -> MCMXCI -> 77+67+77+88+67+73 -> 449
^ input                                ^ output
Roman Numerals:
enter image description here
Here is a perhaps useful Roman Numeral Converter.

Challenge rules:

Standard Roman Numeral rules are applied, so no alternative forms like IIII or VIIII instead of IV and IX.*
The Macron lines above the Roman Numerals past 1,000 are ¯ (UNICODE nr. 175). So one line counts as +175 and two as +350.
You are allowed to use any kind of input and output type, as long as it represents the integers.
The test cases will be in the range of 1 - 2,147,483,647.
* Roman Numeral rules (quote from Wikipedia):

Numbers are formed by combining symbols and adding the values, so II is two (two ones) and XIII is thirteen (a ten and three ones). Because each numeral has a fixed value rather than representing multiples of ten, one hundred and so on, according to position, there is no need for "place keeping" zeros, as in numbers like 207 or 1066; those numbers are written as CCVII (two hundreds, a five and two ones) and MLXVI (a thousand, a fifty, a ten, a five and a one).

Symbols are placed from left to right in order of value, starting with the largest. However, in a few specific cases, to avoid four characters being repeated in succession (such as IIII or XXXX), subtractive notation is often used as follows:

I placed before V or X indicates one less, so four is IV (one less than five) and nine is IX (one less than ten)
X placed before L or C indicates ten less, so forty is XL (ten less than fifty) and ninety is XC (ten less than a hundred)
C placed before D or M indicates a hundred less, so four hundred is CD (a hundred less than five hundred) and nine hundred is CM (a hundred less than a thousand)
For example, MCMIV is one thousand nine hundred and four, 1904 (M is a thousand, CM is nine hundred and IV is four).
Some examples of the modern use of Roman numerals include:
1954 as MCMLIV; 1990 as MCMXC; 2014 as MMXIV
SOURCE

General rules:

This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

Test cases:

100          ->   67
1            ->   73
4            ->   159
22           ->   322
5000         ->   261
2016         ->   401
1000000000   ->   427
1991         ->   449
9999         ->   800
1111111111   ->   2344
2147483647   ->   5362

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(value(100) == 67)
	assert(value(1) == 73)
	assert(value(4) == 159)
	assert(value(22) == 322)
	assert(value(5000) == 261)
	assert(value(2016) == 401)
	assert(value(1000000000) == 427)
	assert(value(1991) == 449)
	assert(value(9999) == 800)
	assert(value(1111111111) == 2344)
	assert(value(2147483647) == 5362)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @jDomantas solution
func value(n int) int {
	D0 := []int{
		'I',
		'X',
		'C',
		'M',
		'X' + 175,
		'C' + 175,
		'M' + 175,
		'X' + 350,
		'C' + 350,
		'M' + 350,
	}
	D1 := []int{
		'I' + 'X',
		'X' + 'C',
		'C' + 'M',
		'M' + 'X' + 175,
		'X' + 'C' + 350,
		'C' + 'M' + 350,
		'M' + 'X' + 525,
		'X' + 'C' + 700,
		'C' + 'M' + 700,
	}
	D2 := []int{
		'I' + 'V',
		'X' + 'L',
		'C' + 'D',
		'M' + 'V' + 175,
		'X' + 'L' + 350,
		'C' + 'D' + 350,
		'M' + 'V' + 525,
		'X' + 'L' + 700,
		'C' + 'D' + 700,
	}
	D3 := []int{
		'V',
		'L',
		'D',
		'V' + 175,
		'L' + 175,
		'D' + 175,
		'V' + 350,
		'L' + 350,
		'D' + 350,
	}

	s := fmt.Sprint(n)
	d := len(s) - 1
	l := int(math.Pow10(d))
	switch {
	case n <= 0:
		return 0
	case n < 4*l:
		return D0[d] + value(n-l)
	case n/9*10 >= 10*l:
		return D1[d] + value(n-9*l)
	case n < 5*l:
		return D2[d] + value(n-4*l)
	}
	return D3[d] + value(n-5*l)
}
