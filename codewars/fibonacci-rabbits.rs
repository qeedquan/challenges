/*

In his publication Liber Abaci Leonardo Bonacci, aka Fibonacci, posed a problem involving a population of idealized rabbits.
These rabbits bred at a fixed rate, matured over the course of one month, had unlimited resources, and were immortal.

Create a function that determines the number of pairs of mature rabbits after n months, beginning with one immature pair of these idealized rabbits that produce b pairs of offspring at the end of each month.

To illustrate the problem, consider the following example:

n = 5 months
b = 3 births
-> 19 mature rabbit pairs
Month	Immature pairs	Mature pairs
0	1	0
1	0	1
2	3	1
3	3	4
4	12	7
5	21	19

Hint
Any Fibonacci number can be computed using the following equation: F(n) = F(n-1) + F(n-2)

*/

fn main() {
    assert_eq!(rabbits(1, 3), 1);
    assert_eq!(rabbits(2, 3), 1);
    assert_eq!(rabbits(3, 3), 4);
    assert_eq!(rabbits(4, 3), 7);
    assert_eq!(rabbits(5, 3), 19);
    assert_eq!(rabbits(0, 4), 0);
    assert_eq!(rabbits(1, 4), 1);
    assert_eq!(rabbits(4, 0), 1);
    assert_eq!(rabbits(6, 3), 40);
    assert_eq!(rabbits(8, 12), 8425);
    assert_eq!(rabbits(7, 4), 181);
}

fn rabbits(n: isize, k: isize) -> isize {
    if n < 0 {
        return 0;
    }

    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        (a, b) = (b, (k * a) + b);
    }
    return a;
}
