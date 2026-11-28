/*

Your function must accept two strings and return new string where are UTF-16 code of all symbols is the sum of UTF-16 codes of inputs symbols

If the resulting sum is greater than 65535 (maximum UTF-16 codepoint), take the sum modulo 65536

If there are more symbols in one string then sum with zero, codes of symbols which doesn't have pairs

For example:

'a' + 'b' = a(97) + b(98) = 97 + 98 = 195 => 'Ã'
'A' + 'B' = A(65) + B(66) = 65 + 66 = 131 => '\u0083' (No Break Here)
'Aa' + 'BbC' = [A(65) + B(66)][a(97) + b(98)][(0) + C(67)] => '\u0083ÃC' - \u0083 will not be displayed but it must be here so the length of result string must be 3 not 2
Test cases:

'a', 'b' --> 'Ã'

'A', 'B' --> '\u0083'

'Aa', 'BbC' --> '\u0083ÃC'

'耀', '耀' --> '\u0000' (Null character)

'Программирование', 'Programming' --> 'ѯҲҭҚҲґҩҩҡҮҥвание'
Ungolfed version (check in real time):

const updateResult = () => {
  const string_1 = input1.value;
  const string_2 = input2.value;
  resultString = [];

  for (let i = 0; i < string_1.length || i < string_2.length; ++i) {
    resultString.push(
      (string_1.charCodeAt(i) || 0) +
      (string_2.charCodeAt(i) || 0)
    );
  }

  resultString = String.fromCharCode(...resultString);

  result.innerHTML = resultString;
  resultLength.innerHTML = 'Length: ' + resultString.length;
}

input1.addEventListener('input', updateResult);
input2.addEventListener('input', updateResult);

updateResult();
<input id="input1" value="aA"/>
<input id="input2" value="bB"/>

<br/><br/>

<div id="result"></div>
<div id="resultLength"></div>

The shortest code in each programming language wins!

*/

package main

import (
	"fmt"
	"unicode/utf16"
)

func main() {
	test("a", "b", "Ã")
	test("A", "B", "\u0083")
	test("Aa", "BbC", "\u0083ÃC")
	test("耀", "耀", "\u0000")
	test("Программирование", "Programming", "ѯҲҭҚҲґҩҩҡҮҥвание")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, t, r string) {
	p := conv(s, t)
	v := string(utf16.Decode(p))
	fmt.Printf("%q %q\n", v, r)
	assert(v == r)
}

func conv(s, t string) []uint16 {
	r := []uint16{}
	a := []rune(s)
	b := []rune(t)
	n := len(a)
	m := len(b)
	for i, j := 0, 0; i < n || j < m; {
		var x, y uint16
		if i < n {
			x, i = uint16(a[i]), i+1
		}
		if j < m {
			y, j = uint16(b[j]), j+1
		}
		r = append(r, x+y)
	}
	return r
}
