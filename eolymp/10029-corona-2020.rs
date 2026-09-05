/*

Ziya loves solving math puzzles.
He is particularly interested in puzzles with the number 2020.
After some calculations, he found three distinct numbers a, b, and c.
Ziya wonders if, by inserting the operators + or - in place of the placeholders (<>) in the expression a<>b<>c, it is possible to obtain the number 2020.

Input
Three integers a, b, and c (1≤a,b,c≤10^8).

Output
If it is possible to obtain 2020, print an expression of the form a<>b<>c that evaluates to 2020 using only the operators + or -.
Otherwise, print the word CORONA. There must be no spaces between the numbers and the operators in the expression.

Examples

Input #1
2019 2020 2021

Answer #1
2019-2020+2021

Input #2
2019 2020 2022

Answer #2
CORONA

*/

fn main() {
    assert_eq!(solve(2019, 2020, 2021), "2019-2020+2021");
    assert_eq!(solve(2019, 2020, 2022), "CORONA");
}

fn solve(a: isize, b: isize, c: isize) -> String {
    if a + b + c == 2020 {
        format!("{}+{}+{}", a, b, c)
    } else if a - b - c == 2020 {
        format!("{}-{}-{}", a, b, c)
    } else if a + b - c == 2020 {
        format!("{}+{}-{}", a, b, c)
    } else if a - b + c == 2020 {
        format!("{}-{}+{}", a, b, c)
    } else {
        format!("CORONA")
    }
}
