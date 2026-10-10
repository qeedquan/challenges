/*

Explanation:

Last year in math class, on homework we would occasionally get these extremely simple, although equally annoying questions called diamond puzzles.
These were basically questions where we would be given a sum, and a product then were asked to find the two numbers which when multiplied give the product, and when added give the sum.
These drove me crazy, since the only way I knew how to solve them (in Algebra I) was to just list the factors of the product then see which ones added to make the sum.
(Since I didn't know how to use Quadratics at the time) Not to mention, they weren't exactly challenging math.
However, It just occured to me that I should have just written a program. So that is your challenge today! Write a program that can solve a diamond puzzle.

Examples:

https://i.stack.imgur.com/bbHkK.png

Apologies for the blurry image, its the best I could find. Also, ignore the numbers in bubbles.The top of the diamond is the product, the bottom is the sum, the right and left are the two numbers. Answers are as follows: (These are also your test cases)

9, -7
-2, -1
5, 8
-9, -9

Rules:

You may not use any pre-defined functions or classes which accomplish this for you.
Your code must be a complete program, or function which either returns or prints the answers once it finds them
The input is the sum and product, which are inputted as a function parameters or user input
Specifications:

Assume that the two numbers, the sum, and the product will always be an integer.
The two answers will both be between -127 to 127.
Your input will be two integers (Sum and Product).
Remember this is code-golf, so shortest byte count wins. Please title your answer with the standard ##Language Name, Byte Count

Edit: Also, Doorknob pointed out that this is essentially "factor a quadratic of form x^2 + bx + c,". That is another way to think about and approach this challenge. :D

*/

fn main() {
    assert_eq!(solve(-63, 2), (9, -7));
    assert_eq!(solve(2, -3), (-1, -2));
    assert_eq!(solve(40, 13), (8, 5));
    assert_eq!(solve(81, -18), (-9, -9));
}

fn solve(p: isize, s: isize) -> (isize, isize) {
    let h = (s as f64) * 0.5;
    let d = h * h - (p as f64);
    if d < 0.0 {
        return (0, 0);
    }

    let sd = d.sqrt();
    return ((h + sd) as isize, (h - sd) as isize);
}
