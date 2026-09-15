/*

Kleptyk decided to create a three-dimensional model of cubes using matches for the edges of the cubes.
The length of the edge of each cube is equal to one match. He used 28 matches to build a model of three cubes.

What is the minimum number of matches Kleptyk needs to build a model of n cubes? The cubes must be arranged in the most optimal way.

All numbers in this problem do not exceed 2⋅10^9.

Input
The input contains one number n — the number of cubes in the model.

Output
Print the minimum number of matches required to build the model of n cubes.

Examples
Input #1
1

Answer #1
12

*/

fn main() {
    let tab = vec![
        4, 12, 20, 28, 36, 44, 52, 60, 68, 76, 84, 92, 100, 108, 116, 124, 132, 140, 148, 156, 164,
        172, 180, 188, 196, 204, 212, 220, 228, 236, 244, 252, 260, 268, 276, 284, 292, 300, 308,
        316, 324, 332, 340, 348, 356, 364, 372, 380, 388, 396, 404, 412, 420, 428, 436, 444, 452,
        460, 468,
    ];

    assert_eq!(solve(1), 12);
    assert_eq!(solve(3), 28);

    for i in 0..tab.len() {
        assert_eq!(solve(i), tab[i]);
    }
}

// https://oeis.org/A017113
fn solve(n: usize) -> usize {
    (8 * n) + 4
}
