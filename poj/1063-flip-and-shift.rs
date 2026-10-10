/*

Description

This puzzle consists of a random sequence of m black disks and n white disks on an oval-shaped track, with a turnstile capable of flipping (i.e., reversing) three consecutive disks. In Figure 1, there are 8 black disks and 10 white disks on the track. You may spin the turnstile to flip the three disks in it or shift one position clockwise for each of the disks on the track (Figure 1).

http://poj.org/images/1063/f1.gif

You are to write a program which decides whether a given sequence can reach a goal or not. If a goal is reachable, then write a message "YES"; otherwise, write a message "NO".

Input

The input consists of T test cases. The number of test cases ) (T is given in the first line of the input file. Each of the next T lines gives a test case. A test case consists of an integer, representing the sum of m and n, and a sequence of m+n 0s and 1s, representing an initial sequence. A 0 denotes a white disk and a 1 denotes a black disk. The sum of m and n is at least 10 and does not exceed 30. There is a space between numbers.

Output

The output should print either "YES" or "NO" for each test case, one per line.

Sample Input

2
18 0 0 1 0 1 1 1 1 0 1 0 0 1 0 0 0 0 1
14 1 1 0 0 1 1 1 0 0 1 1 0 1 0

Sample Output

YES
NO

Source

Taejon 2001

*/

fn main() {
    assert_eq!(
        reachable(vec![0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1]),
        "YES"
    );

    assert_eq!(
        reachable(vec![1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0]),
        "NO"
    );
}

fn reachable(a: Vec<isize>) -> &'static str {
    let n = a.len();
    if n & 1 != 0 {
        return "YES";
    }

    let (mut e, mut o) = (0, 0);
    for i in 0..n {
        if a[i] != 1 {
            continue;
        }

        if i & 1 != 0 {
            o += 1;
        } else {
            e += 1;
        }
    }

    if isize::abs(o - e) > 1 {
        return "NO";
    }
    return "YES";
}
