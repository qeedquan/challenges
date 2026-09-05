/*

Sometimes you want to impress those around you by seeming almost like a psychic.
Perhaps you want to show children how much you know and can do.
Guessing a thought-of number is a great trick to grab attention.

Instructions

Ask someone to think of three digits (specifically digits, not numbers).

Then ask them to multiply the first digit by 2 and add 3 to the result. Multiply this result by 5.

Next, add the second digit to the obtained number, then multiply the result by 10.

Add the third digit to the new number.

Ask them to say the obtained number out loud.

Pretend to ponder (but don't take too long).
Meanwhile, subtract 150 from the number spoken.
The first three digits of the result are exactly those digits thought of in the beginning.

Input
The input contains a string with the number spoken by the student.

Output
In the output file, print the three thought-of digits separated by spaces.

Examples

Input #1
747

Answer #1
5 9 7

*/

fn main() {
    assert_eq!(solve(747), (5, 9, 7));
}

fn solve(n: isize) -> (isize, isize, isize) {
    let n = n - 150;
    let a = n / 100;
    let b = (n % 100) / 10;
    let c = (n % 100) % 10;
    (a, b, c)
}
