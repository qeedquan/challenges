/*

No, I don’t want you to waste important time reading boring introduction. At first, there are n people
numbered 1 to n around a circle and every second remaining person will be eliminated until only one
survives. Let the number of the survivor be x. The process is then repeated with x number of people
and let the survivor number is y. The process then starts with y number of people and so on. The
repetition ends when the survivor is in the last position in the circle.
Example with n = 5:
After the first elimination round, the survivor is person 3. Because this is is not the last person in
the circle, a new elimination round with 3 people is started.
Now person 3 survives, so we can stop.

Input
The first line in the input file is an integer representing the number of test cases. Each of the test cases
follows below. Each test case consists of an integer representing n (0 < n ≤ 30000).

Output
For each test case, print the serial number of the case, a colon, an space, total number of repetitions
(the number of times the elimination process is done after the initial elimination round with n people),
an space and the position of the survivor at last. Check the sample input & output.

Sample Input
2
13
23403

Sample Output
Case 1: 2 7
Case 2: 8 1023

*/

fn main() {
    assert_eq!(solve(13), (2, 7));
    assert_eq!(solve(23403), (8, 1023));
}

fn solve(mut n: isize) -> (isize, isize) {
    for i in 0..isize::MAX {
        let s = josephus(n, 2);
        if s == n {
            return (i, s);
        }
        n = s;
    }
    return (-1, -1);
}

fn josephus(n: isize, k: isize) -> isize {
    let mut r = 0;
    for i in 2..=n {
        r = (r + k) % i;
    }
    r + 1
}
