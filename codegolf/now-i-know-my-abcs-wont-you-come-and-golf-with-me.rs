/*

Write a program or function that outputs this exact text, case-insensitive:

A, B, C, D, E, F, G,
H, I, J, K, L, M, N, O, P,
Q, R, S,
T, U, V,
W, X, Y, Z.

(Based on the alphabet song that many American kids learn to help memorize the alphabet, though edited for more compressibility.)

The output must look exactly the same as the above (again, case-insensitive), but may contain trailing spaces on each line and/or trailing newlines. Notice the period at the end.

This is code-golf, so the shortest code in bytes wins.

*/

fn main() {
    println!("{}", ALPHABET);
}

const ALPHABET: &str = r#"A, B, C, D, E, F, G,
H, I, J, K, L, M, N, O, P,
Q, R, S,
T, U, V,
W, X, Y, Z."#;
