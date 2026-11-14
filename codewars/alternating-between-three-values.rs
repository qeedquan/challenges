/*

Alternating Among Three Values
Suppose a variable x can have only three possible different values a, b and c, and you wish to assign to x the value other than its current one, and you wish your code to be independent of the values of a, b and c.

What is the most efficient way to cycle among three values? Write a function f so that it satisfies

  f(a) = b
  f(b) = c
  f(c) = a

EXAMPLE
  f( 3, { a:3, b:4, c:5 } ) => 4

*/

fn main() {
    let (a, b, c) = (3, 4, 5);
    assert_eq!(f(a, a, b, c), b);
    assert_eq!(f(b, a, b, c), c);
    assert_eq!(f(c, a, b, c), a);
}

fn f(x: isize, a: isize, b: isize, c: isize) -> isize {
    match x {
        _ if x == a => b,
        _ if x == b => c,
        _ if x == c => a,
        _ => unreachable!(),
    }
}
