/*

To complete this kata you will have to finish a function that returns a string of characters which when printed resemble a Rubik's cube. The function is named cube, and it has one integer parameter (formal argument) n, for the dimensions of the cube.

For example, when I call the function cube(3) it will return a string which when printed appears as so:

  /\_\_\_\
 /\/\_\_\_\
/\/\/\_\_\_\
\/\/\/_/_/_/
 \/\/_/_/_/
  \/_/_/_/

There are no spaces to the right of the cube edges (same above and below the cube), and it must work for all dimensions greater than, or equal to one (technically 1 x 1 x 1):

1 x 1 x 1

/\_\
\/_/

2 x 2 x 2

 /\_\_\
/\/\_\_\
\/\/_/_/
 \/_/_/

*/

fn main() {
    for i in 0..5 {
        println!("n={i}");
        println!("{}", cube(i));
        println!();
    }
}

fn cube(n: usize) -> String {
    let mut art = String::new();

    for i in 1..n + 1 {
        art.push_str(&r" ".repeat(n - i));
        art.push_str(&r"/\".repeat(i));
        art.push_str(&r"_\".repeat(n));
        art.push_str("\n");
    }

    for i in (1..n + 1).rev() {
        art.push_str(&r" ".repeat(n - i));
        art.push_str(&r"\/".repeat(i));
        art.push_str(&r"_/".repeat(n));
        art.push_str("\n");
    }

    art
}
