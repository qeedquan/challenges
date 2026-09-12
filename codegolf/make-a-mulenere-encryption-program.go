/*

Mulenère cipher is a version of Vigenère ciphers, which uses multipling instead of adding.

Algorithm
It's simple. First, the password will repeated as much as reach a size bigger than length of the text input.

For encoding, ASCII code of each character of text will multiplied by the character in repeated key which have same index as current character of input, then put a character to encoded output with same ASCII code of multiplied result.

For decoding, it's simple. For each character of encoded input text, divide it's ASCII code with ASCII code of current character index but in key.

Input format
Could be in any reasonable format which contains a boolean to decode or encode, an input text and key.

Output the decoded/encoded (based on action boolean) with your input and key.

Encoding Example
Note this is the format I prefer, but this can be in any reasonable format.

e
Hello
Golf
Hello is input and Golf is key.

First, as Golf is smaller than Hello. We repeat Golf twice, becoming GolfGolf. Then, removing useless end characters, become GolfG.
ASCII codes for input: 72, 101, 108, 108, 111
ASCII codes for key: 71, 111, 108, 102, 71
Computation:
72 x 71 = 5112
101 x 111 = 11211
108 x 108 = 11664
108 x 102 = 11016
111 x 71 = 7881
Output: Unicode 5112, Unicode 11211, Unicode 11664, Unicode 11016, Unicode 7881
Decoding Example
Note this is the format I prefer, but this can be in any reasonable format.

e
<unicode-input>
Golf
Hello is input and Golf is key. is Unicode 5112, Unicode 11211, Unicode 11664, Unicode 11016, Unicode 7881.

First, as Golf is smaller than input. We repeat Golf twice, becoming GolfGolf. Then, removing useless end characters, become GolfG.
ASCII codes for key: 71, 111, 108, 102, 71
Computation:
5112 / 71 = 72
11211 / 111 = 101
11664 / 108 = 108
11016 / 102 = 108
7881 / 71 = 111
Output: Hello
Rules
This is code-golf, shortest code per language wins!
If your language supports this as a ready-to-use function, you must to use your own function instead of ready-to-use functions.
Execution comes without internet connection (offline executing)
Your code does not need to handle where incorrect key provided in decoding.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	key := "Golf"
	in1 := encrypt("Hello", key)
	in2 := decrypt(in1, key)
	fmt.Printf("%q\n", in1)
	fmt.Printf("%q\n", in2)
}

func encrypt(in, key string) string {
	return crypt(in, key, 'e')
}

func decrypt(in, key string) string {
	return crypt(in, key, 'd')
}

func crypt(in, key string, op rune) string {
	w := new(bytes.Buffer)
	a := []rune(in)
	b := []rune(key)
	if len(b) == 0 {
		return in
	}
	for i := range a {
		if op == 'e' {
			w.WriteRune(a[i] * b[i%len(b)])
		} else {
			w.WriteRune(a[i] / b[i%len(b)])
		}
	}
	return w.String()
}
