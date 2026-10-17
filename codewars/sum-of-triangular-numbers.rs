/*

Your task is to return the sum of Triangular Numbers up-to-and-including the nth Triangular Number.

Triangular Number: "any of the series of numbers (1, 3, 6, 10, 15, etc.) obtained by continued summation of the natural numbers 1, 2, 3, 4, 5, etc."

[01]
02 [03]
04 05 [06]
07 08 09 [10]
11 12 13 14 [15]
16 17 18 19 20 [21]
e.g. If 4 is given: 1 + 3 + 6 + 10 = 20.

Triangular Numbers cannot be negative so return 0 if a negative number is given.

*/

fn main() {
    let tab = [
        0, 1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 286, 364, 455, 560, 680, 816, 969, 1140, 1330,
        1540, 1771, 2024, 2300, 2600, 2925, 3276, 3654, 4060, 4495, 4960, 5456, 5984, 6545, 7140,
        7770, 8436, 9139, 9880, 10660, 11480, 12341, 13244, 14190, 15180,
    ];

    for i in 0..tab.len() {
        assert_eq!(tetra(i), tab[i]);
    }
}

// https://oeis.org/A000292
fn tetra(n: usize) -> usize {
    n * (n + 1) * (n + 2) / 6
}
