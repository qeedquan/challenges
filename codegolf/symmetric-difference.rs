/*

Surprised that we don't have a symmetric difference challenge yet.

Given two lists only containing positive integers, return all items among these two lists that aren't contained in both of the lists.

Rules
From the set definition:

A set is a collection of definite distinct items.

So you can assume the items in the input lists are always unique.
You can also take input as a set if your language supports it.
Test cases
Here is a sample program that generates the test cases.

[1,2,3],[2,3,4] -> [1,4]

*/

use std::collections::*;
use std::iter::*;

fn main() {
    assert_eq!(symdiff(vec![1, 2, 3], vec![2, 3, 4]), vec![1, 4]);
}

fn symdiff(a: Vec<isize>, b: Vec<isize>) -> Vec<isize> {
    let x: HashSet<isize> = HashSet::from_iter(a);
    let y: HashSet<isize> = HashSet::from_iter(b);
    let z = x.symmetric_difference(&y);

    let mut r = vec![];
    for v in z {
        r.push(*v);
    }
    r
}
