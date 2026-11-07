/*

Andrey, a fifth grader, is learning about fractions in his math class. Today, the lesson focused on adding fractions, and the teacher assigned a challenging homework problem.

Given four positive integers a, b, c, and d, we define their "fractioning" as the sum:

a/b + c/d

Your task is to rearrange these four numbers to minimize their fractioning. Help Andrey find the order that results in the smallest possible fractioning.

Input
The input consists of a single line containing four positive integers — a, b, c, and d (1≤a,b,c,d≤10^9).

Output
Output the four numbers in a permutation that minimizes their fractioning. If there are multiple permutations that achieve the minimum, you may output any one of them.

Examples

Input #1
1 2 3 4

Answer #1
1 3 2 4

Input #2
5 5 5 5

Answer #2
5 5 5 5

Note
In the first example, arranging the numbers in this order results in the fractioning:

1/3 + 2/4 = 5/6

It is not possible to achieve a smaller value.

In the second example, the fractioning is:

5/5 + 5/5 = 2

*/

fn main() {
    assert_eq!(solve(1, 2, 3, 4), (1, 3, 2, 4));
    assert_eq!(solve(5, 5, 5, 5), (5, 5, 5, 5));
}

fn solve(a: isize, b: isize, c: isize, d: isize) -> (isize, isize, isize, isize) {
    let mut f = [a, b, c, d];
    f.sort();
    (f[0], f[2], f[1], f[3])
}
