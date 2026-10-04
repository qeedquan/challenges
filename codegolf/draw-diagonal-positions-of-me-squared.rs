/*

Based on the interpretation user @ThePirateBay made from the first version of my own challenge

Output diagonal positions of me squared
now I challenge you to make ASCII art that draws diagonal lines based on a square character matrix based on a given number n.

Input
A number n.

Output
A square matrix of size n^2 which outputs diagonals represented by the adequate one of the \ X /chars. All other positions are to be fulfilled with # chars.

Examples:
1
X

2
\/
/\

3
\#/
#X#
/#\

4
\##/
#\/#
#/\#
/##\

5
\###/
#\#/#
##X##
#/#\#
/###\

There will be no accepted answer. I want to know the shortest code for each language.

*/

fn main() {
    for i in 0..6 {
        squarecross(i);
    }
}

fn squarecross(n: isize) {
    println!("n={}", n);
    for y in 0..n {
        for x in 0..n {
            if (n & 1 != 0) && (x == y) && (x == n / 2) {
                print!("X");
            } else if x == y {
                print!("\\");
            } else if x == n - y - 1 {
                print!("/");
            } else {
                print!("#");
            }
        }
        println!();
    }
    println!();
}
