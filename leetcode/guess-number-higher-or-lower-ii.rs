/*

We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


Example 1:

Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
Example 2:

Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
Example 3:

Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.


Constraints:

1 <= n <= 200

Hint:
The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
Take a small example (n = 3). What do you end up paying in the worst case?
Check out this article if you're still stuck.
The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?

*/

use std::cmp::*;

fn main() {
    assert_eq!(money_amount(10), 16);
    assert_eq!(money_amount(1), 0);
    assert_eq!(money_amount(2), 1);
    assert_eq!(money_amount(234), 1167);
}

// https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/375-guess-number-higher-or-lower-ii.html
// https://baihuqian.github.io/2018-08-21-guess-number-higher-or-lower-ii/
fn money_amount(n: usize) -> usize {
    if n == 0 {
        return 0;
    }

    let mut dp = vec![vec![0; n + 1]; n + 1];
    for k in 0..n {
        for i in 1..n - k + 1 {
            if k == 0 {
                dp[i][i + k] = 0;
            } else if k == 1 {
                dp[i][i + k] = i;
            } else {
                let mut c = usize::MAX;
                for j in i + 1..i + k {
                    c = min(c, max(dp[i][j - 1], dp[j + 1][i + k]) + j);
                }
                dp[i][i + k] = c;
            }
        }
    }
    return dp[1][n];
}
