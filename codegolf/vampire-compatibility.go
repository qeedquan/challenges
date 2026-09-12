/*

A little known fact about vampires is that they must drink the blood of victim that has a compatible donor blood type. The compatibility matrix for vampires is the same as the regular red blood cell donor/recipient matrix. This can be summarized by the following American Red Cross table

Type    You Can Give Blood To    You Can Receive Blood From
A+      A+, AB+                  A+, A-, O+, O-
O+      O+, A+, B+,AB+           O+, O-
B+      B+, AB+                  B+, B-, O+, O-
AB+     AB+                      everyone
A-      A+, A-, AB+, AB-         A-, O-
O-      everyone                 O-
B-      B+, B-, AB+, AB-         B-  O-
AB-     AB+, AB-                 AB-, A-, B-, O-
Challenge
Write a function or program that takes a blood type as input and outputs two lists:

the unordered list of types that may receive donation of the input type
the unordered list of types that may give donation to the input type
If you write a function, then please also provide a test program to call that function with a few examples, so I can easily test it. In this case, the test program would not count towards your score.

Input
Input must be a string representing exactly one of the 8 possible red blood cell types O− O+ A− A+ B− B+ AB− AB+. Input may be given via the normal methods (STDIN, command-line args, function args, etc).

If any other input is given then the program/function must return empty output or throw an error. Normally strict input-checking is not great in code-golf questions, but I felt given the life-death implications of getting blood types wrong that I should add this rule.

Output
Output will be two human-readable lists of blood types in whatever format is suitable for your language. In the special cases where one of the output list contains all 8 types, this list may optionally be replaced with a single item list containing everyone.

Normal output will go to one of the normal places (STDOUT, function return, etc).

Other rules
Standard loopholes are banned
You may use whatever pre-existing 3rd party libraries you need, so long as they are not designed explicitly for this purpose.

Examples
For input AB-, the two output lists would be: {AB+, AB-}, {AB-, A-, B-, O-}
For input AB+, the two output lists would be: {AB+}, {O−, O+, A−, A+, B−, B+, AB−, AB+} or {AB+}, {everyone}
Personal note: Please consider donating blood if you are able to. Without the transfusion I received a few years ago, I might not be here today, so I feel very grateful towards those who are able to donate!

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test("AB-", []string{"AB+", "AB-"}, []string{"AB-", "A-", "B-", "O-"})
	test("AB+", []string{"AB+"}, []string{"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(kind string, expected_receivers, expected_givers []string) {
	receivers, givers := bloods(kind)
	fmt.Println(receivers)
	fmt.Println(givers)
	fmt.Println()
	assert(slices.Equal(receivers, expected_receivers))
	assert(slices.Equal(givers, expected_givers))
}

func bloods(kind string) (receivers, givers []string) {
	compatibles := map[string][2][]string{
		"A+": [2][]string{
			{"A+", "AB+"},
			{"A+", "A-", "O+", "O-"},
		},

		"O+": [2][]string{
			{"O+", "A+", "B+", "AB+"},
			{"O+", "O-"},
		},

		"B+": [2][]string{
			{"B+", "AB+"},
			{"B+", "B-", "O+", "O-"},
		},

		"AB+": [2][]string{
			{"AB+"},
			{"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"},
		},

		"A-": [2][]string{
			{"A+", "A-", "AB+", "AB-"},
			{"A-", "O-"},
		},

		"O-": [2][]string{
			{"O-", "O+", "A-", "A+", "B-", "B+", "AB-", "AB+"},
			{"O-"},
		},

		"B-": [2][]string{
			{"B+", "B-", "AB+", "AB-"},
			{"B-", "O-"},
		},

		"AB-": [2][]string{
			{"AB+", "AB-"},
			{"AB-", "A-", "B-", "O-"},
		},
	}

	result := compatibles[kind]
	receivers = result[0]
	givers = result[1]
	return
}
