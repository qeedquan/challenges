/*

Each student eagerly awaits the day he would pass the exams successfully. Thus, Vasya was ready to celebrate, but, alas, he didn't pass it. However, many of Vasya's fellow students from the same group were more successful and celebrated after the exam.

Some of them celebrated in the BugDonalds restaurant, some of them — in the BeaverKing restaurant, the most successful ones were fast enough to celebrate in both of restaurants. Students which didn't pass the exam didn't celebrate in any of those restaurants and elected to stay home to prepare for their reexamination. However, this quickly bored Vasya and he started checking celebration photos on the Kilogramm. He found out that, in total, BugDonalds was visited by A students, BeaverKing - by B students and C students visited both restaurants. Vasya also knows that there are N students in his group.

Based on this info, Vasya wants to determine either if his data contradicts itself or, if it doesn't, how many students in his group didn't pass the exam. Can you help him so he won't waste his valuable preparation time?

Input
The first line contains four integers - A, B, C and N (0≤A,B,C,N≤100).

Output
If a distribution of N students exists in which A students visited BugDonalds,
 B - BeaverKing,
 C - both of the restaurants and at least one student is left home (it is known that Vasya didn't pass the exam and stayed at home), output one integer — amount of students (including Vasya) who did not pass the exam.

If such a distribution does not exist and Vasya made a mistake while determining the numbers A, B, C or N (as in samples 2 and 3), output -1.

Examples

input
10 10 5 20
output
5

input
2 2 0 4
output
-1

input
2 2 2 1
output
-1

Note
The first sample describes following situation: 5 only visited BugDonalds, 5 students only visited BeaverKing, 5 visited both of them and 5 students (including Vasya) didn't pass the exam.

In the second sample 2 students only visited BugDonalds and 2 only visited BeaverKing, but that means all 4 students in group passed the exam which contradicts the fact that Vasya didn't pass meaning that this situation is impossible.

The third sample describes a situation where 2 students visited BugDonalds but the group has only 1 which makes it clearly impossible.

*/

#include <assert.h>

int
nopass(int a, int b, int c, int n)
{
	int f, p;

	p = a + b - c;
	f = n - p;
	if (p >= n || c > a || c > b)
		return -1;
	return f;
}

int
main(void)
{
	assert(nopass(10, 10, 5, 20) == 5);
	assert(nopass(2, 2, 0, 4) == -1);
	assert(nopass(2, 2, 2, 1) == -1);

	return 0;
}
