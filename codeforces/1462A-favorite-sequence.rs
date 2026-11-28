/*

Polycarp has a favorite sequence a[1…n] consisting of n integers. He wrote it out on the whiteboard as follows:

he wrote the number a1 to the left side (at the beginning of the whiteboard);
he wrote the number a2 to the right side (at the end of the whiteboard);
then as far to the left as possible (but to the right from a1), he wrote the number a3;
then as far to the right as possible (but to the left from a2), he wrote the number a4;
Polycarp continued to act as well, until he wrote out the entire sequence on the whiteboard.
The beginning of the result looks like this (of course, if n≥4).
For example, if n=7 and a=[3,1,4,1,5,9,2], then Polycarp will write a sequence on the whiteboard [3,4,5,2,9,1,1].

You saw the sequence written on the whiteboard and now you want to restore Polycarp's favorite sequence.

Input
The first line contains a single positive integer t (1≤t≤300) — the number of test cases in the test. Then t test cases follow.

The first line of each test case contains an integer n (1≤n≤300) — the length of the sequence written on the whiteboard.

The next line contains n integers b1,b2,…,bn (1≤bi≤10^9) — the sequence written on the whiteboard.

Output
Output t answers to the test cases. Each answer — is a sequence a that Polycarp wrote out on the whiteboard.

Example

input
6
7
3 4 5 2 9 1 1
4
9 2 7 1
11
8 4 3 1 2 7 8 7 9 4 2
1
42
2
11 7
8
1 1 1 1 1 1 1 1

output
3 1 4 1 5 9 2
9 1 2 7
8 2 4 4 3 9 1 7 2 8 7
42
11 7
1 1 1 1 1 1 1 1

Note
In the first test case, the sequence a matches the sequence from the statement. The whiteboard states after each step look like this:

[3]⇒[3,1]⇒[3,4,1]⇒[3,4,1,1]⇒[3,4,5,1,1]⇒[3,4,5,9,1,1]⇒[3,4,5,2,9,1,1].

*/

fn main() {
    assert_eq!(
        polycarp(vec![3, 4, 5, 2, 9, 1, 1]),
        vec![3, 1, 4, 1, 5, 9, 2]
    );
    assert_eq!(polycarp(vec![9, 2, 7, 1]), vec![9, 1, 2, 7]);
    assert_eq!(
        polycarp(vec![8, 4, 3, 1, 2, 7, 8, 7, 9, 4, 2]),
        vec![8, 2, 4, 4, 3, 9, 1, 7, 2, 8, 7]
    );
    assert_eq!(polycarp(vec![42]), vec![42]);
    assert_eq!(polycarp(vec![11, 7]), vec![11, 7]);
    assert_eq!(
        polycarp(vec![1, 1, 1, 1, 1, 1, 1, 1]),
        vec![1, 1, 1, 1, 1, 1, 1, 1]
    );
}

fn polycarp(a: Vec<isize>) -> Vec<isize> {
    let mut p = vec![];
    let n = a.len();
    if n == 0 {
        return p;
    }

    let (mut i, mut l, mut r) = (0, 0, n - 1);
    while l <= r {
        if i & 1 == 0 {
            p.push(a[l]);
            l += 1;
        } else {
            p.push(a[r]);
            r -= 1;
        }
        i += 1;
    }
    return p;
}
