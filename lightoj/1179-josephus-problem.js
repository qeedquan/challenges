/*

The historian Flavius Josephus relates how, in the Romano-Jewish conflict of 67 A.D., the Romans took the town of Jotapata which he was commanding. Escaping, Josephus found himself trapped in a cave with 40 companions. The Romans discovered his whereabouts and invited him to surrender, but his companions refused to allow him to do so. He therefore suggested that they kill each other, one by one, the order to be decided by lot. Tradition has it that the means for affecting the lot was to stand in a circle, and, beginning at some point, count round, every third person being killed in turn. The sole survivor of this process was Josephus, who then surrendered to the Romans. Which begs the question: had Josephus previously practiced quietly with 41 stones in a dark corner, or had he calculated mathematically that he should adopt the 31st position in order to survive?

Now you are in a similar situation. There are n persons standing in a circle. The persons are numbered from 1 to n circularly. For example, 1 and n are adjacent and 1 and 2 are also. The count starts from the first person. Each time you count up to k and the kth person is killed and removed from the circle. Then the count starts from the next person. Finally one person remains. Given n and k you have to find the position of the last person who remains alive.

Input
Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case contains two positive integers n (1 ≤ n ≤ 10^5) and k (1 ≤ k < 2^31).

Output
For each case, print the case number and the position of the last remaining person.

Sample
Input	Output
6
2 1
2 2
3 1
3 2
3 3
4 6

Case 1: 2
Case 2: 1
Case 3: 3
Case 4: 3
Case 5: 2
Case 6: 3

*/

var assert = require('assert');

function josephus(n, k) {
	if (n < 1)
		return 0;
	if (n == 1)
		return 1;
	return (josephus(n - 1, k) + k - 1) % n + 1;
}

assert(josephus(2, 1) == 2);
assert(josephus(2, 2) == 1);
assert(josephus(3, 1) == 3);
assert(josephus(3, 2) == 3);
assert(josephus(3, 3) == 2);
assert(josephus(4, 6) == 3);
