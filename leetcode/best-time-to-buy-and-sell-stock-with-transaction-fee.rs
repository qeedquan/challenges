/*

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

Constraints:

1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4


Hint 1
Consider the first K stock prices. At the end, the only legal states are that you don't own a share of stock, or that you do.
Calculate the most profit you could have under each of these two cases.

*/

use std::cmp::max;

fn main() {
    assert_eq!(max_profit(&[1, 3, 2, 8, 4, 9], 2), 8);
    assert_eq!(max_profit(&[1, 3, 7, 5, 10, 3], 3), 6);
}

fn max_profit(prices: &[isize], fee: isize) -> isize {
    if prices.len() == 0 {
        return 0;
    }

    let mut cash = 0;
    let mut hold = -prices[0];
    for i in 1..prices.len() {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}
