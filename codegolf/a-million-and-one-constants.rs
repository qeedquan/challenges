/*

When code golfing, it can be useful to write numbers succinctly. This challenge involves using a source language to generate code for a target language. For the submission to be valid, it must generate 1,000,001 snippets of code for the target language which evaluate to the integers 0, 1, ..., 1000000 (when evaluated in the source language). Target languages unable to exactly express these constants are excluded from this challenge.

This is meta-golf, your score is the sum of the number of bytes in each snippet. In particular, the length of the source code provided does not affect your score. Feel free to format as you prefer. Similarly, the way you delimit the code snippets is flexible. You can return an array, print one on each line, etc., as long as it's clear which is which.

Because each target language has different rules, submissions only compete with other submissions using the same target language.

Note: No byte-based target language can have a score better than 2,933,952. A target language constructed information-theoretically perfectly for this challenge would use log(1000001)/log(2) bits for each number for a total of just under 2,491,449 bytes.

Note: If you don't need a source language, just submit your answer as, e.g., "Text → C" and note the delimiter used between programs.

*/

fn main() {
    for i in 0..=1000000 {
        println!("{i}");
    }
}
