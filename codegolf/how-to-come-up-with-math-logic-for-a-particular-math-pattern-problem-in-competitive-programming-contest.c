/*

Codeforces Problem - 1973A Chess For Three

Three friends gathered to play a few games of chess together.

In every game, two of them play against each other. The winner gets 2 points while the loser gets 0, and in case of a draw, both players get 1 point each. Note that the same pair of players could have played any non-negative number of times (possibly zero). It is also possible that no games were played at all.

You've been told that their scores after all the games were played were p1, p2 and p3. Additionally, it is guaranteed that p1≤ p2 ≤ p3 holds.

Find the maximum number of draws that could have happened and print it. If there isn't any way to obtain p1,p2 and p3 as a result of a non-negative number of games between the three players, print −1 instead.

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows. The first line of each test case contains three integers p1, p2 and p3 (0≤p1≤p2≤p3≤30) — the scores of the three players, sorted non-decreasingly.

Output:

For each testcase, print one number — the maximum possible number of draws that could've happened, or −1 if the scores aren't consistent with any valid set of games and results.

Example:
INPUT
7
0 0 0
0 1 1
1 1 1
1 1 2
3 3 3
3 4 5
1 1 10

OUTPUT
0
1
-1
2
-1
6
2

For this problem I easily come up with first hint that if sum of p1,p2,p2 is odd then the answer is -1. Then I can't think any of the further approach for this problem but after the contest I look at other people submission.

I have pasted one of the people Accepted submission

t=int(input())
for i in range(t):
    a,b,c=map(int,input().split())
    if (a+b+c)%2==1:print(-1)
    elif a+b<=c:print(a+b)
    else:print((a+b+c)//2)

The if condition which he wrote was same what I thought of but for the elif condition he wrote, I can't understand in what logic did he write that. According to my knowledge of aspect it looks completely non logical how someone could come up with that and how this code could passes all the test cases.

After seeing this code, I understand that I somewhat lack some mathematical logic which I need to learn to solve these kind of mathematical problems.

That's what I need if someone could help me or refer what I need to learn to understand and solve these kind of math problems and how to solve some other similar math pattern problem in future.

And also explain the logic behind this code.

*/

#include <assert.h>

int
draws(int a, int b, int c)
{
	if ((a + b + c) & 1)
		return -1;
	if (a + b <= c)
		return a + b;
	return (a + b + c) / 2;
}

int
main()
{
	assert(draws(0, 0, 0) == 0);
	assert(draws(0, 1, 1) == 1);
	assert(draws(1, 1, 1) == -1);
	assert(draws(1, 1, 2) == 2);
	assert(draws(3, 3, 3) == -1);
	assert(draws(3, 4, 5) == 6);
	assert(draws(1, 1, 10) == 2);

	return 0;
}
