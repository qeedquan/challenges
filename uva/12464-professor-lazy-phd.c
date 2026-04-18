/*

Professors are very motivated when they have to travel abroad for a conference (of course, if fees are
paid by the university), but they don’t have the same attitude when the moment to grade exams arrives.
Professor Lazy, Ph.D., has a particular way to grade exams (and very unfair, by the way). He puts
all his exams in a box and then starts getting them out one by one in a totally random fashion. He
assigns grade α to the first exam that he gets out of the box, and grade β to the second exam that he
gets out of the box. From that point on, he assigns a grade to each of the exams based on the grades
of the previous two exams. What he does is that he takes the grade of the immediately previous exam,
adds 1 and divides by the grade of the exam before the previous one.
For example, let’s imagine that α = 2 and β = 3. This is what happens:
• The first exam gets α = 2.
• The second exam gets β = 3.
• The previous two grades are α and β, so the third exam gets (1 + β)/α = (1 + 3)/2 = 2.
• The previous two grades are β and (1 + β)/α, so the fourth exam gets (1 + (1+β)/α)/β=(1 + 2)/3= 2.
• The procedure continues until he’s done with all exams.
More formally, we can define the grade Qn of the n-th exam with a recurrence like this:
Qn =
α                     if n = 0
β                     if n = 1
(1 + Q[n-1]) / Q[n-2] if n ≥ 2

Even this simple procedure is a lot of work for Professor Lazy, Ph.D., so he asks you to write a
program to do it for him. He wants to spend all day long drinking coffee in the cafeteria with other
professors. Given α, β and n find the value of Qn.
Note that the grades do not necessarily lie inside a fixed range. They are just arbitrary integers.

Input
The input contains several test cases (at most 1000). Each test case is described by three integer
numbers α, β and n on a single line (1 ≤ α, β ≤ 10^9 and 0 ≤ n ≤ 10^15).
The last line of the input contains three zeros and should not be processed.
Output
For each test case, write the value of Qn in a single line. The input will be such that the value of Qn
is always an integer. Furthermore, Qi will never be zero for 0 ≤ i ≤ n (in other words, division by zero
will never arise when evaluating the recurrence).
Universidad de Valladolid OJ: 12464 – Professor Lazy, Ph.D. 2/2

Sample Input
1 1 0
1 2 1
5 9 2
2 3 3
7 4 4
2109 650790 344341899059516
45861686 57 594261603792314
2309734 21045930 808597262407955
0 0 0

Sample Output
1
2
2
1
2
650790
804591
2309734

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong a, vlong b, vlong n)
{
	switch (n % 5) {
	case 0:
		return a;
	case 1:
		return b;
	case 2:
		return (1 + b) / a;
	case 3:
		return (1 + a + b) / (a * b);
	default:
		return (1 + a) / b;
	}
}

int
main()
{
	assert(solve(1, 1, 0) == 1);
	assert(solve(1, 2, 1) == 2);
	assert(solve(5, 9, 2) == 2);
	assert(solve(2, 3, 3) == 1);
	assert(solve(7, 4, 4) == 2);
	assert(solve(2109, 650790, 344341899059516) == 650790);
	assert(solve(45861686, 57, 594261603792314) == 804591);
	assert(solve(2309734, 21045930, 808597262407955) == 2309734);

	return 0;
}
