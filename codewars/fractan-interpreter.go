/*

FRACTRAN is a Turing-complete esoteric programming language invented by John Conway.
In Fractran, a program consists of a finite list of positive fractions. The input to a program is a positive integer n.
The program is run by updating the integer n as follows:

1. For the first fraction f in the list for which n*f  is an integer, replace n by n*f.
2. Start from the beginning and repeat this rule until no fraction in the list produces an integer when multiplied by n, then halt.

Example:
This Fractran program:

455/33 11/13 1/11 3/7 11/2 1/3

given any integer of format 2^a*3^b outputs 5^(a*b), hence it can be said that the program "multiplies" the integers a and b.

Task:
Your task is to write a function fractran(code, n) that runs the FRACTRAN program code with initial value n and returns the final n value after halting.

code is a string, formatted like this: '455/33 11/13 1/11 3/7 11/2 1/3'
n is an integer with n >= 1
every program consists of at least one fraction
if the program does not halt after 1000 cycles, return the n value after that many cycles
Note: If this is too easy you could try writing a Fractran interpreter in Fractran :D

Tests
E = [
    # Adder:  2^a * 3^b  ->  3^(a+b)
     (3**9, 2**4 * 3**5, '3/2')

    # Multiplier:  2^a * 3^b  ->  5^(a*b)
    ,(5**12, 2**3 * 3**4, '455/33 11/13 1/11 3/7 11/2 1/3')

    # Floordiv/Remainder:  2^n * 3^d * 11  ->  5^q * 7^r  where  n = q*d + r  and  0 <= r < d
    ,(5**2 * 7**1, 2**7 * 3**3 * 11, '91/66 11/13 1/33 85/11 57/119 17/19 11/17 1/3')

    # Hamming weight:  2^a  ->  13^H(a)  where H(a) = number of ones in binary expansion of a
    ,(13**3, 2**11, '33/20 5/11 13/10 1/5 2/3 10/7 7/2')

    # Fibonacci:  78 * 5^(n-1)  ->  2^Fn  where Fn = nth fibonacci number
    ,(2**13, 78 * 5**(7-1), '17/65 133/34 17/19 23/17 2233/69 23/29 31/23 74/341 31/37 41/31 129/287 41/43 13/41 1/13 1/3')

    # Prime Generator:  10  ->  stream mixed with 10^n  where  n is prime
    ,(127381246468476, 10, '7/3 99/98 13/49 39/35 36/91 10/143 49/13 7/11 1/2 91/1')
    ]


@test.describe('Sample Tests')
def sample():

    for s, n, code in E:
        test.assert_equals(fractran(code, n), s)

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	test("3/2", "3888", "19683")
	test("455/33 11/13 1/11 3/7 11/2 1/3", "648", "244140625")
	test("91/66 11/13 1/33 85/11 57/119 17/19 11/17 1/3", "38016", "175")
	test("33/20 5/11 13/10 1/5 2/3 10/7 7/2", "2048", "2197")
	test("17/65 133/34 17/19 23/17 2233/69 23/29 31/23 74/341 31/37 41/31 129/287 41/43 13/41 1/13 1/3", "1218750", "8192")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(code string, value, expected string) {
	result := fractan(code, xint(value))
	fmt.Println(result)
	assert(result.Cmp(xint(expected)) == 0)
}

func fractan(code string, value *big.Int) *big.Int {
	fractions := parse(code)
	multiplier := new(big.Rat)
	multiplier.SetInt(value)
loop:
	for {
		for _, fraction := range fractions {
			value := new(big.Rat)
			value.Mul(fraction, multiplier)
			if value.IsInt() {
				multiplier = value
				continue loop
			}
		}
		break
	}
	return multiplier.Num()
}

func parse(code string) []*big.Rat {
	fractions := []*big.Rat{}
	for _, token := range strings.Split(code, " ") {
		fraction := new(big.Rat)
		fraction.SetString(token)
		fractions = append(fractions, fraction)
	}
	return fractions
}

func xint(number string) *big.Int {
	value := new(big.Int)
	value.SetString(number, 10)
	return value
}
