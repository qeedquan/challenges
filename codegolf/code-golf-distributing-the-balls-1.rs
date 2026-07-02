/*

Challenge
In this task you have compute the number of ways we can distribute A balls into B cells with with every cell having at-least one ball.

The inputs A and B are given in a single line separated by a blank,the inputs are terminated by EOF.

You may like to check your solutions here.

Input

0 0
1 0
12 4
6 3
18 17
20 19
15 13
18 9
20 20
17 14
9 2
14 13
18 11

Output

1
0
14676024
540
54420176498688000
23112569077678080000
28332944640000
38528927611574400
2432902008176640000
21785854970880000
510
566658892800
334942064711654400

Constraints

Every A and B can be distinguishable.
0 <= A,B <= 20
You can use any language of your choice
Shortest solution wins!

*/

fn main() {
    assert_eq!(balls(0, 0), 1);
    assert_eq!(balls(1, 0), 0);
    assert_eq!(balls(12, 4), 14676024);
    assert_eq!(balls(6, 3), 540);
    assert_eq!(balls(18, 17), 54420176498688000);
    assert_eq!(balls(20, 19), 23112569077678080000);
    assert_eq!(balls(15, 13), 28332944640000);
    assert_eq!(balls(18, 9), 38528927611574400);
    assert_eq!(balls(20, 20), 2432902008176640000);
    assert_eq!(balls(17, 14), 21785854970880000);
    assert_eq!(balls(9, 2), 510);
    assert_eq!(balls(14, 13), 566658892800);
    assert_eq!(balls(18, 11), 334942064711654400);
}

/*

@Peter Taylor

We start with the recurrence f(n, k) = k * (f(n-1, k) + f(n-1, k-1)).
This can be understood combinatorically as saying that to place n distinguishable balls in k distinguishable buckets such that each bucket contains at least one ball,
you pick one of the k buckets for the first ball (k *) and then either it will contain at least one more ball (f(n-1, k)) or it won't (f(n-1, k-1)).

*/

fn balls(n: u128, k: u128) -> u128 {
    if n == 0 && k == 0 {
        return 1;
    }

    if n == 0 || k == 0 {
        return 0;
    }

    return k * (balls(n - 1, k) + balls(n - 1, k - 1));
}
