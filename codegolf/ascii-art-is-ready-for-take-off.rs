/*

Task

Given a positive integer n, draw the corresponding rocket.
Examples

From n = 1 to 4 the rockets are below. For your program's output, the trailing newline after a rocket is optional.

  |
 / \
*---*
| o |
| o |
*---*
 /_\

   |
  / \
 /   \
*-----*
| o o |
| o o |
| o o |
| o o |
*-----*
 /___\

    |
   / \
  /   \
 /     \
*-------*
| o o o |
| o o o |
| o o o |
| o o o |
| o o o |
| o o o |
*-------*
 /_____\

     |
    / \
   /   \
  /     \
 /       \
*---------*
| o o o o |
| o o o o |
| o o o o |
| o o o o |
| o o o o |
| o o o o |
| o o o o |
| o o o o |
*---------*
 /_______\

You can check this reference implementation (ungolfed).

def spaceship(n):
 r = ""

 # tip
 r += " "*(n+1) + "|" + "\n"

 # head
 for i in range(n, 0, -1):
  r += " "*i + "/" + " "*(2*(n-i)+1) + "\\" + "\n"

 # body
 sep = "*" + "-"*(2*n+1) + "*" + "\n"
 r += sep
 line = "|" + " o"*n + " |" + "\n"
 r += line*2*n
 r += sep

 # propulsion
 r += " /" + "_"*(2*n-1) + "\\" + "\n"

 return r

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

*/

fn main() {
    for i in 0..5 {
        spaceship(i);
    }
}

fn spaceship(n: isize) {
    println!("{}|", repeat(" ", n + 1));
    for i in (1..n + 1).rev() {
        println!("{}/{}\\", repeat(" ", i), repeat(" ", 2 * (n - i) + 1));
    }

    let sep = format!("*{}*\n", repeat("-", 2 * (n + 1)));
    let line = format!("|{} |\n", repeat(" o", n));
    print!("{}{}{}", sep, repeat(&line, 2 * n), sep);
    println!(" /{}\\", repeat("_", (2 * n) - 1));
    println!("");
}

fn repeat(s: &str, n: isize) -> String {
    (0..n).map(|_| s).collect::<String>()
}
