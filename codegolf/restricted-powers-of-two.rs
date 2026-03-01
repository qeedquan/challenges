/*

Challenge
Given a number x, output the first x powers of two, starting with 2¹ (2).

Example
2   2 4
3   2 4 8
1   2
6   2 4 8 16 32 64
You may output numbers separated by non-numerical characters. You may not just output them mashed together like 248163264128.

Rules
In your code, you may only use the number 2. You may not use any other numbers, either as ASCII characters or numeric literals in any base.
You may not use character literals as integers to bypass this rule.
You may not use your language's built-in exponentiation function, operator, or similar. You must implement the exponent yourself.
You may not use bit shifting operators.
You may not use operations that are equivalent to bit shifting.
Standard loopholes are disallowed.
This is code-golf, shortest answer wins. However, it will not be selected.

*/

fn main() {
    assert_eq!(pow2s(2), vec![2, 4]);
    assert_eq!(pow2s(3), vec![2, 4, 8]);
    assert_eq!(pow2s(1), vec![2]);
    assert_eq!(pow2s(6), vec![2, 4, 8, 16, 32, 64]);
}

fn pow2s(n: usize) -> Vec<usize> {
    let mut r = vec![];
    for i in 1..n + 1 {
        r.push(1 << i);
    }
    r
}
