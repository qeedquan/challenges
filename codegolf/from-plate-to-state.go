/*

This is essentially the inverse of Generate a US License Plate

Challenge: Given a string that matches one of the below license plate formats, output all possible states that match that formatting. In the below table 0 stands for a single digit 0 through 9 inclusive, and A stands for a single letter A through Z inclusive. For the purposes of this challenge, we're ignoring states with complex format rules (like Delaware, which has variable number of digits), and ignoring removal of look-alike letters (e.g., I and 1).

AAA 000: AK, IA, MS, MP, VT
0000: AS
AAA0000: AZ, GA, WA
000 AAA: AR, KS, KY, LA, ND, OR
0AAA000: CA
AA-00000: CT
AA-0000: DC
AAA A00: FL
AA 00000: IL
000A,000AA,000AAA,AAA000: IN
0AA0000: MD
AAA 0000,0AA A00,AAA 000: MI
000-AAA: MN
00A-000: NV
000 0000: NH
A00-AAA: NJ
000-AAA,AAA-000: NM
AAA-0000: NY, NC, PA, TX, VA, WI
AAA 0000: OH
000AAA: OK
AAA-000: PR
000-000: RI
AAA 000,000 0AA: SC
A00-00A: TN
A00 0AA: UT
Examples:

B32 9AG
[UT]

1YUC037
[CA]

285 LOR
[AR, KS, KY, LA, ND, OR] (in any order)

285-LOR
[MN, NM] (in any order)

285LOR
[IN, OK] (in any order)

Rules and Clarifications

The input string is guaranteed non-empty, and guaranteed to be of one of the above formats
Behavior if given a format other than the above is undefined
Input and output can be given by any convenient method
You can print the result to STDOUT or return it as a function result
Either a full program or a function are acceptable
Standard loopholes are forbidden
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins

*/

package main

import (
	"bytes"
	"fmt"
	"slices"
)

func main() {
	test("B32 9AG", []string{"UT"})
	test("1YUC037", []string{"CA"})
	test("285 LOR", []string{"AR", "KS", "KY", "LA", "ND", "OR"})
	test("285-LOR", []string{"MN", "NM"})
	test("285LOR", []string{"IN", "OK"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []string) {
	p := plate2state(s)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func plate2state(s string) []string {
	lut := map[string][]string{
		"AAA 000":  []string{"AK", "IA", "MI", "MS", "MP", "SC", "VT"},
		"0000":     []string{"AS"},
		"AAA0000":  []string{"AZ", "GA", "WA"},
		"000 AAA":  []string{"AR", "KS", "KY", "LA", "ND", "OR"},
		"0AAA000":  []string{"CA"},
		"AA-00000": []string{"CT"},
		"AA-0000":  []string{"DC"},
		"AAA A00":  []string{"FL"},
		"AA 00000": []string{"IL"},
		"000A":     []string{"IN"},
		"000AA":    []string{"IN"},
		"AAA000":   []string{"IN"},
		"0AA0000":  []string{"MD"},
		"AAA 0000": []string{"MI", "OH"},
		"0AA A00":  []string{"MI"},
		"000-AAA":  []string{"MN", "NM"},
		"00A-000":  []string{"NV"},
		"000 0000": []string{"NH"},
		"A00-AAA":  []string{"NJ"},
		"AAA-0000": []string{"NY", "NC", "PA", "TX", "VA", "WI"},
		"000AAA":   []string{"IN", "OK"},
		"AAA-000":  []string{"NM", "PR"},
		"000-000":  []string{"RI"},
		"000 0AA":  []string{"SC"},
		"A00-00A":  []string{"TN"},
		"A00 0AA":  []string{"UT"},
	}
	return lut[hash(s)]
}

func hash(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch {
		case 'A' <= r && r <= 'Z':
			fallthrough
		case 'a' <= r && r <= 'z':
			r = 'A'
		case '0' <= r && r <= '9':
			r = '0'
		}
		w.WriteRune(r)
	}
	return w.String()
}
