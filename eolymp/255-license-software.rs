/*

As you know, to verify licensed software, serial numbers and registration keys are used.
You, as a leading developer of license verification systems, have developed a reliable system.
It is based on the digital roots of numbers.
Now you need to write a program that determines the digital root of a given number.

The digital root of an arbitrary number is defined as follows:

If the sum of its digits is less than 10, then the digital root is the sum of the digits of that number.

Otherwise, the digital root of a number is equal to the digital root of the sum of its digits.

Input
The only number n (0≤n≤2^31-1).

Output
Print one number — the answer to the challenge.

Examples

Input #1
123

Answer #1
6

*/

fn main() {
    let tab = vec![
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2,
        3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5,
        6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8,
        9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5,
    ];

    assert_eq!(digroot(123), 6);

    for i in 0..tab.len() {
        assert_eq!(digroot(i), tab[i]);
    }
}

// https://oeis.org/A010888
fn digroot(x: usize) -> usize {
    if x == 0 {
        return 0;
    }
    return 1 + ((x - 1) % 9);
}
