/*

Polycarp plays "Game 23". Initially he has a number n and his goal is to transform it to m. In one move, he can multiply n by 2 or multiply n by 3. He can perform any number of moves.

Print the number of moves needed to transform n to m. Print -1 if it is impossible to do so.

It is easy to prove that any way to transform n to m contains the same number of moves (i.e. number of moves doesn't depend on the way of transformation).

Input
The only line of the input contains two integers n and m (1≤n≤m≤5⋅10^8).

Output
Print the number of moves to transform n to m, or -1 if there is no solution.

Examples

input
120 51840
output
7

input
42 42
output
0

input
48 72
output
-1

Note
In the first example, the possible sequence of moves is: 120→240→720→1440→4320→12960→25920→51840.The are 7 steps in total.

In the second example, no moves are needed. Thus, the answer is 0.

In the third example, it is impossible to transform 48 to 72.

*/

fn main() {
    assert_eq!(moves(120, 51840), 7);
    assert_eq!(moves(42, 42), 0);
    assert_eq!(moves(48, 72), -1);
}

fn moves(n: isize, m: isize) -> isize {
    if n == m || n == 0 {
        return 0;
    }
    if m % n != 0 {
        return -1;
    }

    let mut r = 0;
    let mut v = m / n;
    while v % 2 == 0 {
        v /= 2;
        r += 1;
    }
    while v % 3 == 0 {
        v /= 3;
        r += 1;
    }

    if v != 1 {
        return -1;
    }
    return r;
}
