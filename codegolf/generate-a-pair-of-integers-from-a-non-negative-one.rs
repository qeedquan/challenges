/*

You should write a program or function which takes a non-negative integer N as input and outputs or returns two integers (negative, zero or positive) X and Y.

Integers are meant in the mathematical sense as there are infinitely many of them.

The implemented function has to be bijective. This means that for every N it has to output a different X Y pair and every X Y pair should be outputted for some input N i.e. all of the following pairs should be outputted for some N:

                 ...
    ┌─────┬─────┬────┬────┬────┐
    │-2 -2│-2 -1│-2 0│-2 1│-2 2│
    ├─────┼─────┼────┼────┼────┤
    │-1 -2│-1 -1│-1 0│-1 1│-1 2│
    ├─────┼─────┼────┼────┼────┤
... │0 -2 │0 -1 │0 0 │0 1 │0 2 │ ...
    ├─────┼─────┼────┼────┼────┤
    │1 -2 │1 -1 │1 0 │1 1 │1 2 │
    ├─────┼─────┼────┼────┼────┤
    │2 -2 │2 -1 │2 0 │2 1 │2 2 │
    └─────┴─────┴────┴────┴────┘
                 ...
Note that U V and V U are different pairs if U!=V.

Details
If your language doesn't support arbitrarily large integers that's fine but your algorithm should work with an arbitrarily large integer data-type. Your code should still support input values for at least 2^31-1.
If you choose to print or return the output as string no leading 0's or + signs are allowed. Otherwise your language's standard integer representation is fine.

Example

If the task would be to make a bijective function taking a non-negative integer N and output one integer X a solution could be the function

if (input mod 2 == 0) return N/2 else return -(N+1)/2,

implemented in some language. This function returns X = 0 -1 1 -2 2... for N = 0 1 2 3

*/

fn main() {
    assert_eq!(f(0), (0, 0));
    assert_eq!(f(1), (1, 0));
    assert_eq!(f(2), (-1, 0));
    assert_eq!(f(3), (0, 1));
    assert_eq!(f(4), (1, 1));
    assert_eq!(f(5), (-1, 1));
    assert_eq!(f(6), (0, -1));
    assert_eq!(f(7), (1, -1));
    assert_eq!(f(8), (-1, -1));
    assert_eq!(f(9), (3, 0));
    assert_eq!(f(10), (4, 0));
    assert_eq!(f(11), (2, 0));
    assert_eq!(f(12), (3, 1));
    assert_eq!(f(13), (4, 1));
    assert_eq!(f(14), (2, 1));
    assert_eq!(f(15), (3, -1));
    assert_eq!(f(16), (4, -1));
    assert_eq!(f(17), (2, -1));
    assert_eq!(f(18), (-3, 0));
    assert_eq!(f(19), (-2, 0));
    assert_eq!(f(20), (-4, 0));
    assert_eq!(f(21), (-3, 1));
    assert_eq!(f(22), (-2, 1));
    assert_eq!(f(23), (-4, 1));
    assert_eq!(f(24), (-3, -1));
    assert_eq!(f(25), (-2, -1));
    assert_eq!(f(26), (-4, -1));
    assert_eq!(f(27), (0, 3));
    assert_eq!(f(28), (1, 3));
    assert_eq!(f(29), (-1, 3));
    assert_eq!(f(30), (0, 4));
    assert_eq!(f(31), (1, 4));
    assert_eq!(f(32), (-1, 4));
    assert_eq!(f(33), (0, 2));
    assert_eq!(f(34), (1, 2));
    assert_eq!(f(35), (-1, 2));
    assert_eq!(f(36), (3, 3));
    assert_eq!(f(37), (4, 3));
    assert_eq!(f(38), (2, 3));
    assert_eq!(f(39), (3, 4));
    assert_eq!(f(40), (4, 4));
    assert_eq!(f(41), (2, 4));
    assert_eq!(f(42), (3, 2));
    assert_eq!(f(43), (4, 2));
    assert_eq!(f(44), (2, 2));
    assert_eq!(f(45), (-3, 3));
    assert_eq!(f(46), (-2, 3));
    assert_eq!(f(47), (-4, 3));
    assert_eq!(f(48), (-3, 4));
    assert_eq!(f(49), (-2, 4));
    assert_eq!(f(50), (-4, 4));
    assert_eq!(f(51), (-3, 2));
    assert_eq!(f(52), (-2, 2));
    assert_eq!(f(53), (-4, 2));
    assert_eq!(f(54), (0, -3));
    assert_eq!(f(55), (1, -3));
    assert_eq!(f(56), (-1, -3));
    assert_eq!(f(57), (0, -2));
    assert_eq!(f(58), (1, -2));
    assert_eq!(f(59), (-1, -2));
    assert_eq!(f(60), (0, -4));
    assert_eq!(f(61), (1, -4));
    assert_eq!(f(62), (-1, -4));
    assert_eq!(f(63), (3, -3));
    assert_eq!(f(64), (4, -3));
    assert_eq!(f(65), (2, -3));
    assert_eq!(f(66), (3, -2));
    assert_eq!(f(67), (4, -2));
    assert_eq!(f(68), (2, -2));
    assert_eq!(f(69), (3, -4));
    assert_eq!(f(70), (4, -4));
    assert_eq!(f(71), (2, -4));
    assert_eq!(f(72), (-3, -3));
    assert_eq!(f(73), (-2, -3));
    assert_eq!(f(74), (-4, -3));
    assert_eq!(f(75), (-3, -2));
    assert_eq!(f(76), (-2, -2));
    assert_eq!(f(77), (-4, -2));
    assert_eq!(f(78), (-3, -4));
    assert_eq!(f(79), (-2, -4));
    assert_eq!(f(80), (-4, -4));
}

/*

@xnor

This uses digit interleaving like Runer112's solution, but with balanced ternary rather than signed binary. Python doesn't have built-in base conversion, so the code implements it recursively.

The helper function h (with 3 in place of the 9) takes a natural number and converts it from ternary to balanced ternary with the digit substitutions

0 -> 0
1 -> +1
2 -> -1
So, for example, 19, which is 201 in base, becomes (-1)(0)(+1) in balanced ternary, which is (-1)*3^2 +(0)*3^1+(+1)*3^0 = -8.

Balanced ternary suffices to encode every integer, and so gives a mapping from natural numbers to integers.

To map to pairs of integers, we interleave the digits in n. To do so, we have h look at every other digit by doing n/9 as the recursive step rather than n/3. Then, for one coordinate, we shift n by floor-dividing by 3.

*/

fn f(n: isize) -> (isize, isize) {
    (ternary(n), ternary(n / 3))
}

fn ternary(n: isize) -> isize {
    if n == 0 {
        return 0;
    }
    return ((n + 1) % 3) - 1 + (3 * ternary(n / 9));
}
