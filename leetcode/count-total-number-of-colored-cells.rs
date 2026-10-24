/*

There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

    At the first minute, color any arbitrary unit cell blue.
    Every minute thereafter, color blue every uncolored cell that touches a blue cell.

Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.

https://assets.leetcode.com/uploads/2023/01/10/example-copy-2.png

Return the number of colored cells at the end of n minutes.

Example 1:

Input: n = 1
Output: 1
Explanation: After 1 minute, there is only 1 blue cell, so we return 1.

Example 2:

Input: n = 2
Output: 5
Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5.

Constraints:

    1 <= n <= 10^5

Hint 1
Derive a mathematical relation between total number of colored cells and the time elapsed in minutes.

*/

fn main() {
    let tab = vec![
        1, 5, 13, 25, 41, 61, 85, 113, 145, 181, 221, 265, 313, 365, 421, 481, 545, 613, 685, 761,
        841, 925, 1013, 1105, 1201, 1301, 1405, 1513, 1625, 1741, 1861, 1985, 2113, 2245, 2381,
        2521, 2665, 2813, 2965, 3121, 3281, 3445, 3613, 3785, 3961, 4141, 4325, 4513,
    ];

    for i in 0..tab.len() {
        assert_eq!(colorcells(i + 1), tab[i]);
    }
}

// https://oeis.org/A001844
fn colorcells(n: usize) -> usize {
    if n == 0 {
        return 0;
    }
    return n * n + (n - 1) * (n - 1);
}
