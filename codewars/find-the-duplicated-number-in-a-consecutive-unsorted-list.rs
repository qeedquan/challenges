/*

You are given an array of n+1 integers 1 through n. In addition there is a single duplicate integer.

The array is unsorted.

An example valid array would be [3, 2, 5, 1, 3, 4]. It has the integers 1 through 5 and 3 is duplicated. [1, 2, 4, 5, 5] would not be valid as it is missing 3.

You should return the duplicate value as a single integer.

*/

fn main() {
    assert_eq!(dup(&[3, 2, 5, 1, 3, 4]), 3);
    assert_eq!(dup(&[1, 2, 3, 1]), 1);
    assert_eq!(dup(&[5, 4, 3, 2, 1, 1]), 1);
    assert_eq!(dup(&[1, 3, 2, 5, 4, 5, 7, 6]), 5);
    assert_eq!(dup(&[8, 2, 6, 3, 7, 2, 5, 1, 4]), 2);
    assert_eq!(dup(&[1, 1]), 1);
}

fn dup(a: &[usize]) -> usize {
    let n = a.len();
    if n == 0 {
        return 0;
    }
    return a.iter().sum::<usize>() - triangular(n - 1);
}

fn triangular(n: usize) -> usize {
    n * (n + 1) / 2
}
