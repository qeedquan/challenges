/*

The cross-entropy of a unigram model is 9.91. What is its perplexity?

Answer correctly to the nearest integer. You may either submit the final answer directly in the plain-text mode, or you may write a program which computes and displays the answer in the language of your choice.

Your answer should look like this:

881
Do not use any leading or trailing spaces, tabs or newlines.

*/

fn main() {
    println!("{}", perplexity(9.91));
}

// perplexity = 2^cross-entropy
fn perplexity(x: f64) -> f64 {
    2f64.powf(x)
}
