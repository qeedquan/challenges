/*

Your task is to take in one integer input and print a zigzag pattern using slashes and backslashes.

The integer input determines the length of each zig and zag, as well as the number of zigs and zags
The pattern always starts from right to left
Test Cases
4->
   /
  /
 /
/
\
 \
  \
   \
   /
  /
 /
/
\
 \
  \
   \
2->
 /
/
\
 \
0->
1->
/
8->
       /
      /
     /
    /
   /
  /
 /
/
\
 \
  \
   \
    \
     \
      \
       \
       /
      /
     /
    /
   /
  /
 /
/
\
 \
  \
   \
    \
     \
      \
       \
       /
      /
     /
    /
   /
  /
 /
/
\
 \
  \
   \
    \
     \
      \
       \
       /
      /
     /
    /
   /
  /
 /
/
\
 \
  \
   \
    \
     \
      \
       \

*/

fn main() {
    zigzag(4);
    zigzag(2);
    zigzag(0);
    zigzag(1);
    zigzag(8);
}

fn zigzag(n: isize) {
    if n < 1 {
        return;
    }

    let (mut c, mut x, mut dx) = ('/', n - 1, -1);
    println!("{}->", n);
    for _ in 0..n {
        for _ in 0..n {
            for _ in 0..x {
                print!(" ");
            }
            println!("{}", c);
            x += dx;
        }

        if c == '/' {
            (c, x, dx) = ('\\', 0, 1);
        } else {
            (c, x, dx) = ('/', n - 1, -1);
        }
    }
}
