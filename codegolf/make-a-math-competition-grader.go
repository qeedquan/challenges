/*

I enjoy participating in math competitions run by Mu Alpha Theta, a mathematics honor society in the United States. At competitions, I take a 30-question multiple choice test. There are five choices per question, labeled A through E.

My score on a test is four points for each correct answer, zero points for a question left blank, and negative one points for each wrong answer.

Write a program that grades a test according to the above scoring system. There should be two components to the input: an answer key followed by responses. Questions left blank are to be inputted as blank spaces. The first input must contain only the letters A-E (or a-e, your choice), and it can be assumed that there is no whitespace in the input. The second input must only contain blank spaces and the letters A-E (or a-e). Inputs not implementing 30-question tests must print Invalid test as output.

The output should be the grade or Invalid test.

Bonus

If your program prints the number right, number left blank, and number wrong after the final score as (aR bB cW), take off 20 bytes.

Sample input

CABBDCABECDBACDBEAACADDBBBEDDA    //answer key
CABEDDABDC BACDBBAADE  CBBEDDA    //responses
Sample output

No bonus

73
Bonus

73 (20R 3B 7W)
Standard rules apply. Shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	assert(grade("CABBDCABECDBACDBEAACADDBBBEDDA", "CABEDDABDC BACDBBAADE  CBBEDDA") == "73 (20R 3B 7W)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func grade(answers, responses string) string {
	if len(answers) != len(responses) || len(answers) != 30 {
		return "Invalid test"
	}

	var score, correct, blank, wrong int
	for i := 0; i < len(answers); i++ {
		answer := answers[i]
		response := responses[i]
		switch {
		case answer == response:
			correct += 1
			score += 4
		case response == ' ':
			blank += 1
		default:
			wrong += 1
			score -= 1
		}
	}
	return fmt.Sprintf("%d (%dR %dB %dW)", score, correct, blank, wrong)
}
