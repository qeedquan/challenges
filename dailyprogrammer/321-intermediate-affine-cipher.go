/*

Description
You are to output what you think is the solution to a given Affine Cipher. In short, Affine ciphers are encoded by the following formula for each character in the plaintext: C ≡ aP + b (mod 26) where a and b are constants, C is the ciphertext letter, and P is the plaintext letter. In this case, the letter "a" has the value of 0, "b" 1, and so on and so forth. If you want a hint as to how to decode:

Decoding is done in the same fashion as encoding: P ≡ aC + b
In order to rank your decodings in terms of accuracy, I recommend you use a dictionary of some sort (builtin, or the popular enable1.txt -- note that enable1 lacks "i" and "a" as words). You can choose to not use a dictionary, but it will likely be harder.

Here's a sample of encoding, done with simple numbers (a = 3, b = 2) N.B. This is done with the letters a-z mapped to 1-26 (26≡0) instead of 0-25. This still is correct, just not the exact result you'd expect from following the method I've established previously.

foobar

First, we express our input numerically

6, 15, 15, 2, 0, 18

Then we multiply by a

18, 45, 45, 12, 0, 54

Optionally reduce to least positive residue

18, 19, 19, 12, 0, 2

Add b

20, 21, 21, 18, 2, 4

Now we change this to text again

tyyrbd

Formal Inputs & Outputs
Input description
Input will be words separated by spaces or newlines. Input will be in uppercase if need be (i.e. if you can't figure out a way to handle mixed cases), but if not, it will be provided in regular text (e.g. Lorum ipsum ... word). Expect only alphabetical characters. With reference to my previous equation, a will only be a number coprime with 26. Hint:

that is, a will be one of the following: 3, 5, 7, 11, 15, 17, 19, 21, 23, or 25
Output description
What your program thinks is the correct decoding, in lowercase if you only took uppercase input, else in the same case as you were given. You may give multiple outputs if there is a "tie" in your scoring, that is, if your program deemed two or more decodings to be correct.

Test Cases
Test Case 1: NLWC WC M NECN

this is a test
Test Case 2: YEQ LKCV BDK XCGK EZ BDK UEXLVM QPLQGWSKMB

you lead the race of the worlds unluckiest
Test Case 2 Bonus: Yeq lkcv bdk xcgk ez bdk uexlv'm qplqgwskmb.

You lead the race of the world's unluckiest.
Test Case 3: NH WRTEQ TFWRX TGY T YEZVXH GJNMGRXX STPGX NH XRGXR TX QWZJDW ZK WRNUZFB P WTY YEJGB ZE RNSQPRY XZNR YJUU ZSPTQR QZ QWR YETPGX ZGR NPGJQR STXQ TGY URQWR VTEYX WTY XJGB

my heart aches and a drowsy numbness pains my sense as though of hemlock i had drunk or emptied some dull opiate to the drains one minute past and lethe wards had sunk
Test Case 3 Bonus: Nh wrteq tfwrx, tgy t yezvxh gjnmgrxx stpgx / Nh xrgxr, tx qwzjdw zk wrnuzfb p wty yejgb, / Ze rnsqpry xznr yjuu zsptqr qz qwr yetpgx / Zgr npgjqr stxq, tgy Urqwr-vteyx wty xjgb.

My heart aches, and a drowsy numbness pains / My sense, as though of hemlock I had drunk, / Or emptied some dull opiate to the drains / One minute past, and Lethe-wards had sunk.
Bonus
Make your solver work for all forms of input, not just alphabetical and make your output match the input. I think it goes without saying that this challenge is for the English language, but if you want to, make this program for another language or compatible with English and another. If you want another challenge, optimize your code for run-time (I'd be interested to see submissions in this category).

Credit
This challenge was submitted by u/Cole_from_SE, many thanks! Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import (
	"bytes"
	"fmt"
	"math"
	"strings"
	"unicode"
)

func main() {
	test("NLWC WC M NECN", "this is a test")
	test("YEQ LKCV BDK XCGK EZ BDK UEXLVM QPLQGWSKMB", "you lead the race of the worlds unluckiest")
	test("Yeq lkcv bdk xcgk ez bdk uexlv'm qplqgwskmb.", "You lead the race of the world's unluckiest.")
	test("NH WRTEQ TFWRX TGY T YEZVXH GJNMGRXX STPGX NH XRGXR TX QWZJDW ZK WRNUZFB P WTY YEJGB ZE RNSQPRY XZNR YJUU ZSPTQR QZ QWR YETPGX ZGR NPGJQR STXQ TGY URQWR VTEYX WTY XJGB", "my heart aches and a drowsy numbness pains my sense as though of hemlock i had drunk or emptied some dull opiate to the drains one minute past and lethe wards had sunk")
	test("Nh wrteq tfwrx, tgy t yezvxh gjnmgrxx stpgx / Nh xrgxr, tx qwzjdw zk wrnuzfb p wty yejgb, / Ze rnsqpry xznr yjuu zsptqr qz qwr yetpgx / Zgr npgjqr stxq, tgy Urqwr-vteyx wty xjgb.", "My heart aches, and a drowsy numbness pains / My sense, as though of hemlock I had drunk, / Or emptied some dull opiate to the drains / One minute past, and Lethe-wards had sunk.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(input, expected string) {
	output := solve(input)
	fmt.Println(output)
	assert(strings.ToLower(output) == strings.ToLower(expected))
}

// ported from @skeeto solution
// uses english histogram instead of english dictionary
func solve(input string) string {
	A := []rune{9, 21, 15, 19, 7, 23, 11, 5, 17, 25}

	output := ""
	best := math.MaxFloat64
	for b := range rune(26) {
		for _, a := range A {
			decoded := decode(input, a, b)
			value := score(decoded)
			if value < best {
				output, best = decoded, value
			}
		}
	}
	return output
}

func decode(input string, a, b rune) string {
	output := new(bytes.Buffer)
	for _, c := range input {
		switch {
		case 'a' <= c && c <= 'z':
			c = 'a' + ((c-'a'-b)*a+676)%26
		case 'A' <= c && c <= 'Z':
			c = 'A' + ((c-'A'-b)*a+676)%26
		}
		output.WriteRune(c)
	}
	return output.String()
}

func score(input string) float64 {
	english := []float64{
		8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966,
		0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
		6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074,
	}

	count := make(map[rune]float64)
	total := 0.0
	for _, c := range input {
		c = unicode.ToLower(c)
		if 'a' <= c && c <= 'z' {
			count[c], total = count[c]+1, total+1
		}
	}

	value := 0.0
	for i := range rune(26) {
		diff := (100*count[i+'a'])/total - english[i]
		value += diff * diff
	}
	return value
}
