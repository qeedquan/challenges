/*

This is a sequel to Numbers Interpreted in Smallest Valid Base.

Let us define the operation of rebasing a number as writing out its digits in decimal form, then interpreting them in the smallest base N possible (2 <= n <= 10). For example, rebasing the number 1234 gives 194, since the smallest base that "1234" can be interpreted in is base 5, and "1234" interpreted in base 5 is 194 in decimal.

Let us also define a number as inert if, when rebased, gives itself. For example, any single digit number is inert, and any number with the digit 9 is inert.

Challenge
Given a positive integer n, repeatedly rebase n until it is inert. Output both the number of times the number was rebased, and the final inert number (as a decimal integer).

Expected output
Some testcases:

n       => inert, steps
1011010    90     1
10201      4      2
12345      293    4
56789      56789  0
8314       19     6
88         3      8
3          3      0
80852      3      18
This is code-golf.

Note that this is OEIS entries A091047 and A091048.

*/

fn main() {
    let tests = [
        (1011010, 90, 1),
        (10201, 4, 2),
        (12345, 293, 4),
        (56789, 56789, 0),
        (8314, 19, 6),
        (88, 3, 8),
        (3, 3, 0),
        (80852, 3, 18),
    ];

    for (input, expected_result, expected_steps) in tests {
        let [result, steps] = rebase(input, 0);
        assert_eq!(result, expected_result);
        assert_eq!(steps, expected_steps);
    }
}

// ported from @ShadowRanger solution
fn rebase(input: u128, steps: u128) -> [u128; 2] {
    let result = (2..)
        .find_map(|base| u128::from_str_radix(&input.to_string(), base).ok())
        .unwrap();

    if result < input {
        rebase(result, steps + 1)
    } else {
        [result, steps]
    }
}
