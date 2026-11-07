/*

Write a function f(n,k) that displays the k-dimensional countdown from n.

A 1-dimensional countdown from 5 looks like

 54321
A 2-dimensional countdown from 5 looks like

 54321
 4321
 321
 21
 1
Finally, a 3-dimensional countdown from 5 looks like

 54321
 4321
 321
 21
 1
 4321
 321
 21
 1
 321
 21
 1
 21
 1
 1
Formal definition
The 1-dimensional countdown from any n is a single line with the digits n, n-1,...,1 concatenated (followed by a newline).

For any k, the k-dimensional countdown from 1 is the single line

 1
For n > 1 and k > 1, a k-dimensional countdown from n is a (k-1)-dimensional countdown from n followed by a k-dimensional countdown from n-1.

Input
Two positive integers k and n <= 9, in any format you choose.

Output
The k-dimensional countdown from n, with a newline after each 1-dimensional countdown. Extra newlines are permitted in the output.

Scoring
Standard golf scoring.

Bonus example
Here's an example with k > n, a 4-dimensional countdown from 3 (with extra comments that are not to be included in actual solutions):

 -- 3-dimensional countdown from 3
 321
 21
 1
 21
 1
 1
 -- 4-dimensional countdown from 2:
 ---- 3-dimensional countdown from 2:
 21
 1
 1
 ---- 4-dimensional countdown from 1:
 1
Clarifications:

Digits on a line do not need to be adjacent, but they must be evenly-spaced.

You may write a full program instead of just a function, if you prefer.

*/

fn main() {
    for i in 1..5 {
        println!("{}", f(5, i));
    }
}

/*

@Dennis

The k-dimensional countdown from n can be defined with a single base case:

If n = 1 or k = 1, the output is n || n-1 || ... || 1 || ¶, where || indicates concatenation.

Using the recursive definition from the question, f(n,k) returns f(n,k-1)+f(n-1,k) if n > 1 and k > 1; otherwise it returns the last n + 1 characters from '987654321\n'.

*/

fn f(n: usize, k: usize) -> String {
    let digits = format!("987654321\n");
    if n < 1 || k < 1 {
        return format!("");
    }
    if n == 1 || k == 1 {
        return digits[digits.len() - n - 1..].to_string();
    }
    return format!("{}{}", f(n, k - 1), f(n - 1, k));
}
