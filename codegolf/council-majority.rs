/*

Introduction

You belong to a council which oversees the destruction of corrupted worlds. When the council assembles, a single vote is taken. The ballot lists all nominated worlds. One is ultimately destroyed each time the council meets.

Due to a bug in user12345's code, the council recently flooded and then sent pirate zombies to the wrong planet. We need a more reliable system for counting votes.

Problem

A vote is described by a series of integers on a single line. The first integer is m, and the worlds nominated for destruction are uniquely numbered from 1 to m. The remaining integers each represent the world each council member voted on.

Somehow, without any collusion, one world always receives more than half of the vote. This always occurs, regardless of how many worlds are present.

Given an input, write a program that outputs the world elected for destruction.

Example Input

Remember, the first 3 is the number of worlds, m. It is not a vote.

3 1 1 2 3 1 3 1 1 3

Example Output

The majority of the council voted for planet 1, so we output that.

1

Assumptions

The exact number of votes is not given
The number of votes is between 1 and 100 (inclusive)
Each vote is between 1 and m (inclusive)
Every vote contains a majority
Input must be provided through stdin, read from a file, or accepted as a sole argument to the program
The answer with the fewest characters wins!

*/

fn main() {
    assert_eq!(majority(vec![1, 1, 2, 3, 1, 3, 1, 1, 3]), 1);
    assert_eq!(majority(vec![1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6]), 6);
    assert_eq!(majority(vec![3, 2, 3]), 3);
    assert_eq!(majority(vec![2, 2, 1, 1, 1, 2, 2]), 2);
}

// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
fn majority(a: Vec<isize>) -> isize {
    let n = a.len();
    if n == 0 {
        return -1;
    }

    let (mut m, mut c) = (0, 1);
    for i in 1..n {
        if a[m] == a[i] {
            c += 1;
        } else {
            c -= 1;
        }
        if c == 0 {
            (m, c) = (i, 1);
        }
    }
    a[m]
}
