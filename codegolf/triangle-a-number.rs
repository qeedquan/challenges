/*

We are used to the term "squaring" n to mean calculating n2. We are also used to the term "cubing" n to mean n3. That being said, why couldn't we also triangle a number?

How to triangle a number?
First off, let's pick a number, 53716.

Position it in a parallelogram, whose side length equals the number of digits of the number, and has two sides positioned diagonally, as shown below.

    53716
   53716
  53716
 53716
53716
Now, we want to ∆ it, right? To do so, crop the sides that do not fit into a right-angled triangle:

    5
   53
  537
 5371
53716
Take the sums of each row, for this example resulting in [5, 8, 15, 16, 22]:

    5  -> 5
   53  -> 8
  537  -> 15
 5371  -> 16
53716  -> 22
Sum the list [5, 8, 15, 16, 22], resulting in 66. This is the triangle of this number!

Specs & Rules
The input will be a non-negative integer n (n ≥ 0, n ∈ Z).

You may take input and provide output by any allowed mean.

Input may be formatted as an integer, a string representation of the integer, or a list of digits.

Default loopholes disallowed.

This is code-golf, so the shortest code in bytes wins!

More Test Cases
Input -> Output

0 -> 0
1 -> 1
12 -> 4
123 -> 10
999 -> 54 
100000 -> 6
654321 -> 91

Inspiration. Explanations are encouraged!

*/

fn main() {
    assert_eq!(triangularize(0), 0);
    assert_eq!(triangularize(1), 1);
    assert_eq!(triangularize(12), 4);
    assert_eq!(triangularize(123), 10);
    assert_eq!(triangularize(999), 54);
    assert_eq!(triangularize(100000), 6);
    assert_eq!(triangularize(654321), 91);
    assert_eq!(triangularize(53716), 66);
}

fn triangularize(n: usize) -> usize {
    let d = digits(n);
    let l = d.len();
    let mut r = 0;
    for i in 0..l {
        r += d[l - i - 1] * (l - i);
    }
    r
}

fn digits(mut n: usize) -> Vec<usize> {
    let mut d = vec![];
    while n > 0 {
        d.push(n % 10);
        n /= 10;
    }
    d
}
