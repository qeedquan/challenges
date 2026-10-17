/*

A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false.
He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question.
In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

Example 2:

Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.

Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT".
In both cases, there are five consecutive 'T's.

Constraints:

n == answerKey.length
1 <= n <= 5 * 10^4
answerKey[i] is either 'T' or 'F'
1 <= k <= n

Hint 1
Can we use the maximum length at the previous position to help us find the answer for the current position?

Hint 2
Can we use binary search to find the maximum consecutive same answer at every position?

*/

package main

func main() {
	assert(solve("TTFF", 2) == 4)
	assert(solve("TFFT", 1) == 3)
	assert(solve("TTFTTFTT", 1) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(answers string, k int) int {
	result := 0
	maximum := 0
	count := make(map[byte]int)
	for i := range answers {
		count[answers[i]] += 1
		maximum = max(maximum, count[answers[i]])
		if result-maximum >= k {
			count[answers[i-result]] -= 1
		} else {
			result += 1
		}
	}
	return result
}
