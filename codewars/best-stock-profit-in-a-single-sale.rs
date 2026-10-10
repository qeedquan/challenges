/*

You're a buyer/seller and your business is at stake .. You need to make a profit .. Or at least, you need to lose the least amount of money!
Knowing a list of prices for buy/sell operations, you need to pick two of them. Buy/sell market is evolving across time and the list represent this evolution. First, you need to buy one item, then sell it later. Find the best profit you can do.

Example:
Given an array of prices [3, 10, 8, 4], the best profit you could make would be 7 because you buy at 3 first, then sell at 10.

Input:
A list of prices (integers), of length 2 or more.

Output:
The result of the best buy/sell operation, as an integer.

Note:
Be aware you'll face lists with several thousands of elements, so think about performance.

*/

use std::cmp::*;

fn main() {
    assert_eq!(max_profit(&[3, 10, 8, 4]), 7);
    assert_eq!(max_profit(&[10, 7, 5, 8, 11, 9]), 6);
    assert_eq!(max_profit(&[3, 4]), 1);
    assert_eq!(max_profit(&[9, 9]), 0);
    assert_eq!(max_profit(&[10, 7, 5, 4, 1]), -1);
}

fn max_profit(p: &[isize]) -> isize {
    if p.len() < 2 {
        return 0;
    }

    let mut m = p[0];
    let mut r = p[1] - p[0];
    for &x in &p[1..] {
        r = max(r, x - m);
        m = min(m, x);
    }
    return r;
}
