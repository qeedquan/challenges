/*

Return the Nth Even Number

Example(Input --> Output)

1 --> 0 (the first even number is 0)
3 --> 4 (the 3rd even number is 4 (0, 2, 4))
100 --> 198
1298734 --> 2597466
The input will not be 0.

*/

fn main() {
    assert_eq!(nth_even(1), 0);
    assert_eq!(nth_even(2), 2);
    assert_eq!(nth_even(3), 4);
    assert_eq!(nth_even(6), 10);
    assert_eq!(nth_even(100), 198);
    assert_eq!(nth_even(101), 200);
    assert_eq!(nth_even(201), 400);
    assert_eq!(nth_even(1001), 2000);
    assert_eq!(nth_even(1298734), 2597466);
}

fn nth_even(n: usize) -> usize {
    if n == 0 {
        return 0;
    }
    return 2 * (n - 1);
}
