/*

IUPAC in their insufferable wisdom have created a systematic element name for any newly created element. This is the temporary name of an element until they finally make up their minds about an actual name.
It works like so: each digit of an element number is assigned a prefix based on its value. The prefixes are concatenated with ‘ium’ at the end.
When this is done and if you get double i’s (ii) or triple n’s (nnn), replace them with single i’s and double n’s.
The symbol for the element is the first letter of each prefix used concatenated and result capitalized.
The prefixes used are below.

0 nil       5 pent
1 un        6 hex
2 bi        7 sept
3 tri       8 oct
4 quad      9 enn

So for this golf, your code needs to generate both the element name and its symbol for a given positive integer.
So if your code was given 137, it should print to stdout or return both untriseptium and Uts.
It should be valid from at least 118 to 558 (https://oeis.org/A018227). Any higher is valid if it doesn't increase your code's length.

Python example showing the method:

def elename(n):
    '''Return name and symbol of new element for given element number.'''
    prefixes=['nil','un','bi','tri','quad','pent','hex','sept','oct','enn']
    nmeFixes, symFixes = [], []

    while n:  # each digit of element number is assigned a prefix
        n, i = divmod(n, 10)
        pf = prefixes[i]

        symFixes.append(pf[0])  # symbol uses only first letter of prefix
        nmeFixes.append(pf)

    # loop assembled prefixes in reverse order
    nmeFixes.reverse()
    symFixes.reverse()

    nmeFixes.append('ium')  # suffix
    name = ''.join(nmeFixes)
    symb = ''.join(symFixes).capitalize()

    # apply rule about too many n's or i's
    name = name.replace('nnn','nn')  # can happen with -90-
    name = name.replace('ii','i')  # -2ium or -3ium

    return name, symb

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	test(137, "untriseptium", "Uts")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(number int, expected_name, expected_symbol string) {
	name, symbol := element(number)
	fmt.Println(name, symbol)
	assert(name == expected_name)
	assert(symbol == expected_symbol)
}

func element(number int) (name, symbol string) {
	prefixes := []string{"nil", "un", "bi", "tri", "quad", "pent", "hex", "sept", "oct", "enn"}

	names := [][]byte{}
	symbols := []byte{}
	for ; number > 0; number /= 10 {
		index := number % 10
		symbols = append(symbols, prefixes[index][0])
		names = append(names, []byte(prefixes[index]))
	}

	reverse(names)
	reverse(symbols)

	names = append(names, []byte("ium"))

	name = string(bytes.Join(names, []byte("")))
	symbol = strings.ToUpper(string(symbols[:1])) + string(symbols[1:])

	name = strings.Replace(name, "nnn", "nn", -1)
	name = strings.Replace(name, "ii", "i", -1)

	return
}

func reverse[T byte | []byte](array []T) {
	length := len(array)
	for index := range length / 2 {
		array[index], array[length-index-1] = array[length-index-1], array[index]
	}
}
