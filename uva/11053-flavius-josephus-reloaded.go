/*

Flavius Josephus once was trapped in a cave together with his comrade soldiers surrounded by Romans.
All of Josephus’ fellow soldiers preferred not to surrender but to commit suicide. So they all formed a
circle and agreed on a number k. Every k-th person in the circle would then commit suicide. However,
Josephus had different priorities and didn’t want to die just yet. According to the legend he managed
to find the safe spot in the circle where he would be the last one to commit suicide. He surrendered to
the Romans and became a citizen of Rome a few years later.
It is a lesser known fact that the souls of Josephus and his comrades were all born again in modern
times. Obviously Josephus and his reborn fellow soldiers wanted to avoid a similar fiasco in the future.
Thus they asked a consulting company to work out a better decision scheme. The company came up with the following scheme:
• For the sake of tradition all soldiers should stand in a circle.
This way a number between 0 and N - 1 is assigned to each soldier, where N is the number of soldiers.
• As changing numbers in the old scheme turned out to be horribly inefficient, the number assigned to a soldier will not change throughout the game.
• The consulting company will provide two numbers a and b which will be used to calculate the number of the next soldier as follows:
Let x be the number of the current soldier, then the number of the next soldier is the remainder of a*x^2 + b mod N.
• We start with the soldier with number 0 and each soldier calculates the number of the next soldier according to the formula above.
• As everyone deserves a second chance a soldier will commit suicide once his number is calculated for the second time.
• In the event that the number of a soldier is calculated for the third time the game will end and all remaining soldiers will surrender.
You are to write a program that given the number of soldiers N and the constants a and b determines the number of survivors.

Input
The input consists of several test cases.
Each test case consists of a single line containing the three integers N (2 ≤ N ≤ 10^9), a and b (0 ≤ a, b < N) separated by white space.
You may safely assume that the first soldier dies after no more than one million (10^6) steps.
The input is terminated by a single number 0 which should not be processed.

Output
For each test case output a single line containing the number of soldiers that survive.

Sample Input
2 1 1
5 1 1
10 3 7
101 9 2
698253463 1 181945480
1000000000 999999999 999999999
0

Sample Output
0
2
4
96
698177783
999999994

*/

package main

type fn func(int64) int64

func main() {
	assert(solve(2, 1, 1) == 0)
	assert(solve(5, 1, 1) == 2)
	assert(solve(10, 3, 7) == 4)
	assert(solve(101, 9, 2) == 96)
	assert(solve(698253463, 1, 181945480) == 698177783)
	assert(solve(1000000000, 999999999, 999999999) == 999999994)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, a, b int64) int64 {
	_, lambda := cycle(mkfn(a, b, n), 0)
	return n - lambda
}

func cycle(f fn, x int64) (int64, int64) {
	tortoise, hare := f(x), f(f(x))
	for tortoise != hare {
		tortoise, hare = f(tortoise), f(f(hare))
	}

	mu, lambda := int64(0), int64(1)
	for hare = x; tortoise != hare; mu++ {
		tortoise, hare = f(tortoise), f(hare)
	}
	for hare = f(tortoise); tortoise != hare; lambda++ {
		hare = f(hare)
	}
	return mu, lambda
}

func mkfn(a, b, n int64) fn {
	return func(x int64) int64 {
		return (a*(x*x%n) + b) % n
	}
}
