/*

Count how often sign changes in array.

result
number from 0 to ... . Empty array returns 0

example
const arr = [1, -3, -4, 0, 5];

/*
| elem | count |
|------|-------|
|  1   |  0    |
| -3   |  1    |
| -4   |  1    |
|  0   |  2    |
|  5   |  2    |
*/

catchSignChange(arr) == 2;

*/

fn main() {
    assert_eq!(sign_changes(&vec![1, 3, 4, 5]), 0);
    assert_eq!(sign_changes(&vec![1, -3, -4, 0, 5]), 2);
    assert_eq!(sign_changes(&vec![]), 0);
    assert_eq!(sign_changes(&vec![-47, 84, -30, -11, -5, 74, 77]), 3);
}

fn sign_changes(a: &Vec<isize>) -> isize {
    let n = a.len();
    if n == 0 {
        return 0;
    }

    let mut r = 0;
    for i in 0..n - 1 {
        if sign(a[i]) != sign(a[i + 1]) {
            r += 1;
        }
    }
    r
}

fn sign(x: isize) -> isize {
    if x < 0 {
        return -1;
    }
    return 1;
}
