/*

Given N (2 <= N), print N lines of the letter Fibonacci series like this (i.e. N = 5) First, start with a and b:

a
b
Next, add the two lines.

a
b
ab
Keep adding the last two lines.

a
b
ab
bab
Keep going...

a
b
ab
bab
abbab
And we're done.

Remember, this is code-golf, so the code with the fewest bytes wins.

*/

fn main() {
    fibs(5);
}

fn fibs(n: isize) {
    let mut a = format!("a");
    let mut b = format!("b");
    for _ in 0..n {
        let c = format!("{a}{b}");
        println!("{a}");
        (a, b) = (b, c);
    }
}
