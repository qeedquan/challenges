/*

Description

Always thinking of the cows' grazing experience, FJ has found that he must remove N (1 <= N <= 50,000) unsightly stumps from the pasture. The stumps are conveniently arranged in a straight line and numbered 1..N with each stump having some height H_i (1 <= H_i <= 10,000).

FJ will use the traditional high explosives to destroy the stumps. These high explosives are formulated to destroy adjacent stumps as long as those adjacent stumps are strictly shorter than the nearest stump being destroyed. The blast can continue past the closest adjacent stump to the next adjacent stump if it is even shorter than the nearest stump just destroyed. As soon as a stump encountered by the blast wave is not shorter, though, no more destruction occurs on that side of the target stump (the other side follows the same rules with whatever stumps might appear there).

Consider a line of nine stumps with these heights:

              1 2 5 4 3 3 6 6 2
If FJ blows up the third stump (with height 5), then the second stump will also be destroyed (height 2) and the first stump (height 1) will also be destroyed. Likewise, the fourth stump (height 4) and fifth stump (height 3) will be destroyed since they are successively shorter, leaving the line like this:

              * * * * * 3 6 6 2
Two more explosives (at stumps 7 and 8) will destroy the rest.

Help FJ determine the minimum number of explosive charges he needs to destroy the stumps.

Input

Line 1: A single integer, N

Lines 2..N+1: Line i+1 contains H_i

Output

Lines 1..?: Each line contains one integer which is the index of a stump to blow up. The indices must be listed in increasing order.

Sample Input

9
1
2
5
4
3
3
6
6
2

Sample Output

3
7
8

Source

USACO 2006 January Bronze

*/

fn main() {
    assert_eq!(explosives(&vec![1, 2, 5, 4, 3, 3, 6, 6, 2]), vec![3, 7, 8]);
}

fn explosives(a: &Vec<isize>) -> Vec<usize> {
    let n = a.len();
    let mut r = vec![];
    let mut i = 1;
    while i + 1 < n {
        if a[i] >= a[i - 1] && a[i] >= a[i + 1] {
            r.push(i + 1);
        }
        i += 1;
    }
    r
}
