/*

You are one of the most talented programmers and like to solve challenging problems. And my task is to make your life a bit complex by setting some easy looking hard brainstorming problems such that you can sharpen your skills by practicing here. So, I wrote a code that shows a message like the following line:

      ___  ____  ____  ____  ____  __  __ _   ___  ____
     / __)(  _ \(  __)(  __)(_  _)(  )(  ( \ / __)/ ___)
    ( (_ \ )   / ) _)  ) _)   )(   )( /    /( (_ \\___ \
     \___/(__\_)(____)(____) (__) (__)\_)__) \___/(____/

                    ____  ____   __   _  _
                   (  __)(  _ \ /  \ ( \/ )
                    ) _)  )   /(  O )/ \/ \
                   (__)  (__\_) \__/ \_)(_/

             __    __  ___  _  _  ____  __     __
            (  )  (  )/ __)/ )( \(_  _)/  \  _(  )
            / (_/\ )(( (_ \) __ (  )( (  O )/ \) \
            \____/(__)\___/\_)(_/ (__) \__/ \____/
After that, the code will select a random problem for you from my problems database based on your previously solved problems, your skills, and your weaknesses. But while I was implementing this great idea, I found that all of my problems are scattered in 2 computers. So, I have to merge them before running my code.

Given the number of problems in each of the computers, you have to find the total number of problems. You can safely assume that no problem is stored in multiple computers. So, there are no duplicate problems.

Input
Input starts with an integer T (≤ 125), denoting the number of test cases.

Each case starts with a line containing two integers a and b. a denotes the number of problems in the first computer and b denotes the number of problems in the second computer. You can safely assume that a and b will be non-negative and not greater than 10.

Output
For each case, print the case number and the total number of problems. See the samples for exact formatting.

Sample
Input	Output
2
1 7
9 8

Case 1: 8
Case 2: 17

*/

package main

func main() {
	assert(solve(1, 7) == 8)
	assert(solve(9, 8) == 17)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int) int {
	return a + b
}
