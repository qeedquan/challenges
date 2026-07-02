/*

Description

You are teaching a course and must cover n (1 <= n <= 1000) topics. The length of each lecture is L (1 <= L <= 500) minutes. The topics require t1, t2, ..., tn (1 <= ti <= L) minutes each. For each topic, you must decide in which lecture it should be covered. There are two scheduling restrictions:
1. Each topic must be covered in a single lecture. It cannot be divided into two lectures. This reduces discontinuity between lectures.
2. Topic i must be covered before topic i + 1 for all 1 <= i < n. Otherwise, students may not have the prerequisites to understand topic i + 1.

With the above restrictions, it is sometimes necessary to have free time at the end of a lecture. If the amount of free time is at most 10 minutes, the students will be happy to leave early. However, if the amount of free time is more, they would feel that their tuition fees are wasted. Therefore, we will model the dissatisfaction index (DI) of a lecture by the formula:

   |0         if t=0

   DI=| -C    if 1 <= t <= 10

   |(t-10)^2  otherwise

where C is a positive integer, and t is the amount of free time at the end of a lecture. The total dissatisfaction index is the sum of the DI for each lecture.

For this problem, you must find the minimum number of lectures that is needed to satisfy the above constraints. If there are multiple lecture schedules with the minimum number of lectures, also minimize the total dissatisfaction index.

Input

The input consists of a number of cases. The first line of each case contains the integer n, or 0 if there are no more cases. The next line contains the integers L and C. These are followed by n integers t1, t2, ..., tn.

Output

For each case, print the case number, the minimum number of lectures used, and the total dissatisfaction index for the corresponding lecture schedule on three separate lines. Output a blank line between cases.

Sample Input

6
30 15
10
10
10
10
10
10
10
120 10
80
80
10
50
30
20
40
30
120
100
0

Sample Output

Case 1:

Minimum number of lectures: 2
Total dissatisfaction index: 0

Case 2:

Minimum number of lectures: 6
Total dissatisfaction index: 2700

Source

East Central North America 1998

*/

package main

import "fmt"

func main() {
	test(30, 15, []int{10, 10, 10, 10, 10, 10}, 2, 0)
	test(120, 10, []int{80, 80, 10, 50, 30, 20, 40, 30, 120, 100}, 6, 2700)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(L, C int, T []int, rl, rp int) {
	l, p := schedule(L, C, T)
	fmt.Println(l, p)
	assert(l == rl)
	assert(p == rp)
}

func schedule(L, C int, T []int) (int, int) {
	n := len(T)
	l := make([]int, n+1)
	p := make([]int, n+1)

	l[1] = 1
	p[1] = cost(C, L-T[0])
	for i := 2; i <= n; i++ {
		l[i] = l[i-1] + 1
		p[i] = p[i-1] + cost(C, L-T[i-1])
		s := T[i-1]
		for j := i - 1; j > 0; j-- {
			s += T[j-1]
			if s > L {
				break
			}

			a := p[j-1] + cost(C, L-s)
			if l[i] > l[j-1]+1 {
				l[i] = l[j-1] + 1
				p[i] = a
			} else if l[i] == l[j-1]+1 {
				p[i] = min(p[i], a)
			}
		}
	}
	return l[n], p[n]
}

func cost(C, t int) int {
	switch {
	case t == 0:
		return 0
	case 1 <= t && t <= 10:
		return -C
	}
	return (t - 10) * (t - 10)
}
