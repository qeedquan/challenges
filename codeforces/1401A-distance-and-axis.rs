/*

We have a point A with coordinate x=n on OX-axis. We'd like to find an integer point B (also on OX-axis), such that the absolute difference between the distance from O to B and the distance from A to B is equal to k.

The description of the first test case.
https://espresso.codeforces.com/4f63bd211e18b7371616a82218bed31ef22ade41.png

Since sometimes it's impossible to find such point B, we can, in one step, increase or decrease the coordinate of A by 1. What is the minimum number of steps we should do to make such point B exist?

Input
The first line contains one integer t (1≤t≤6000) — the number of test cases.

The only line of each test case contains two integers n and k (0≤n,k≤10^6) — the initial position of point A and desirable absolute difference.

Output
For each test case, print the minimum number of steps to make point B exist.

Example

input
6
4 0
5 8
0 1000000
0 0
1 0
1000000 1000000

output
0
3
1000000
0
1
0

Note
In the first test case (picture above), if we set the coordinate of B as 2 then the absolute difference will be equal to |(2−0)−(4−2)|=0 and we don't have to move A. So the answer is 0.

In the second test case, we can increase the coordinate of A by 3 and set the coordinate of B as 0 or 8. The absolute difference will be equal to |8−0|=8, so the answer is 3.

https://espresso.codeforces.com/a2a4dc378eafaf06d142097a1ccfebca6b493783.png

*/

fn main() {
    assert_eq!(minsteps(4, 0), 0);
    assert_eq!(minsteps(5, 8), 3);
    assert_eq!(minsteps(0, 1000000), 1000000);
    assert_eq!(minsteps(0, 0), 0);
    assert_eq!(minsteps(1, 0), 1);
    assert_eq!(minsteps(1000000, 1000000), 0);
}

fn minsteps(n: isize, k: isize) -> isize {
    if n < k {
        k - n
    } else {
        (n - k) & 1
    }
}
