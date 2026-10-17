/*

Another brilliant question from Stack Overflow turned into a code-golf challenge!
https://stackoverflow.com/questions/20696011/searching-for-the-lowest-even-integer-using-68-k

Write a program that:

Accepts a string as user input (not piped in or a command line argument). The data type of the input must be a string, if the language does auto evals on input, it must be cast to a string.
Finds the index (0 or 1 based) of the first lowest even digit.
Prints 2 integers, the index and the lowest even digit.
If there is no even digit, return -1 as the index, the second number can be anything.
For the purposes of this zero is not even.
Test examples, given the string on the left output the values on the right:

25376  -->  0,2
523726 -->  1,2
583746 -->  4,4
53771  --> -1,0
_4___2 -->  5,2
The winner: is the program with the lowest character count. No bonuses, no penalties.

edit: (about stdin) I screwed up on the user input part, basically no piping data in, and no command line arguments. You must provide a user prompt of some kind within the program itself.

*/

fn main() {
    assert_eq!(led("25376"), (0, 2));
    assert_eq!(led("523726"), (1, 2));
    assert_eq!(led("583746"), (4, 4));
    assert_eq!(led("53771"), (-1, 0));
    assert_eq!(led("_4___2"), (5, 2));
}

fn led(s: &'static str) -> (isize, isize) {
    let (mut i, mut n, mut m) = (0, -1, 10);
    for c in s.chars() {
        let x = match c {
            '0' => 0,
            '2' => 2,
            '4' => 4,
            '6' => 6,
            '8' => 8,
            _ => 10,
        };

        if x < m {
            (n, m) = (i, x);
        }
        i += 1;
    }
    (n, m % 10)
}
