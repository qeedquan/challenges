/*

The program has an input of a and b, and outputs the sum of numbers from a to b, inclusive. Score is in bytes. As always, standard loopholes are disallowed.

If your input is in the format [a,b], +3 bytes

*/

fn main() {
    assert_eq!(sum(1, 100), 5050);
}

fn sum(mut a: isize, mut b: isize) -> isize {
    if a > b {
        (a, b) = (b, a)
    }
    return (a + b) * (b - a + 1) / 2;
}
