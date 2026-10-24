/*

You should write a program or function which receives an integers as input and outputs or returns two integers whose sum is the first one.

There is one further requirement: no number can be part of the output for two different inputs.

Details
You should be able to handle inputs for at least the range -32768 .. 32767 (inclusive).
If your datatype can't handle arbitrary whole numbers, that is fine but your algorithm should work for arbitrary large and small numbers in theory.
Examples
Each block shows a part of a correct or incorrect solution in the format of input => output.

1 => 6 -5
2 => -2 4
15 => 20 -5

Incorrect, as `-5` is used in two outputs.
-5 => -15 10
0 => 0 0
1 => 5 6
2 => -5 7

Incorrect, as `5 + 6` isn't `1`.
-1 => -1 0
0 => 6 -6
2 => 1 1

Can be correct if other outputs doesn't collide.
This is code golf so the shortest entry wins.

*/

fn main() {
    for i in -5..=5 {
        println!("{:?}", solve(i));
    }
}

/*

@xnor

These are distinct because cubes are far enough spaced that adding n to n**3 is not enough to cross the gap to the next cube :
n**3 < n+n**3 < (n+1)**3 for positive n, and symmetrically for negative n.

*/

fn solve(x: isize) -> (isize, isize) {
    let y = x * x * x;
    (-y, x + y)
}
