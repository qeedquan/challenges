/*

Given a finite arithmetic sequence of positive integers with some terms removed from the middle, reconstruct the whole sequence.

The task
Consider an arithmetic sequence: a list of positive integers in which the difference between any two successive elements is the same.

2 5 8 11 14 17
Now suppose one or more integers is removed from the sequence, subject to the following constraints:

The integers removed will be consecutive terms of the sequence.
The first and last integers in the sequence will not be removed.
At least three integers will remain in the sequence.
For the above sequence, possible removals include:

2 5 8 14 17  (removed 11)
2 5 17       (removed 8 11 14)
2 14 17      (removed 5 8 11)
Your task: Given one of these partial sequences, reconstruct the original full sequence.

Details
You may assume input is valid (has a solution) and is missing at least one term. All numbers in the sequence will be positive (> 0) integers. The sequence may have a positive or negative difference between terms (i.e. it may be increasing or decreasing). It will not be a constant sequence (e.g. 5 5 5).

Your solution may be a full program or a function. Any of the default input and output methods are acceptable.

Your input and output may be a string (with any reasonable delimiter), a list of strings, or a list of numbers. You may represent the numbers in whatever base is convenient for your language.

Please mention any unusual I/O methods/formats in your submission, so others will be able to test your code more easily.

Test cases
In: 2 5 8 14 17
Out: 2 5 8 11 14 17
In: 2 5 17
Out: 2 5 8 11 14 17
In: 2 14 17
Out: 2 5 8 11 14 17
In: 21 9 6 3
Out: 21 18 15 12 9 6 3
In: 10 9 5
Out: 10 9 8 7 6 5
In: 1 10 91 100
Out: 1 10 19 28 37 46 55 64 73 82 91 100
This is code-golf; the shortest answer in each language wins.

*/

fn main() {
    assert_eq!(
        reconstruct(&vec![2, 5, 8, 14, 17]),
        vec![2, 5, 8, 11, 14, 17]
    );
    assert_eq!(reconstruct(&vec![2, 5, 17]), vec![2, 5, 8, 11, 14, 17]);
    assert_eq!(reconstruct(&vec![2, 14, 17]), vec![2, 5, 8, 11, 14, 17]);
    assert_eq!(
        reconstruct(&vec![21, 9, 6, 3]),
        vec![21, 18, 15, 12, 9, 6, 3]
    );
    assert_eq!(reconstruct(&vec![10, 9, 5]), vec![10, 9, 8, 7, 6, 5]);
    assert_eq!(
        reconstruct(&vec![1, 10, 91, 100]),
        vec![1, 10, 19, 28, 37, 46, 55, 64, 73, 82, 91, 100]
    );
    assert_eq!(reconstruct(&vec![0, 0, 0, 0, 0]), vec![0, 0, 0, 0, 0]);
    assert_eq!(reconstruct(&vec![2, 2, 2]), vec![2, 2, 2]);
    assert_eq!(reconstruct(&vec![23]), vec![23]);
}

fn reconstruct(a: &Vec<isize>) -> Vec<isize> {
    let mut r = vec![];
    let n = a.len();
    if n < 1 {
        return r;
    }

    let mut d = 0;
    let mut s = 1;
    for i in 1..n {
        let x = isize::abs(a[i] - a[i - 1]);
        if d == 0 {
            d = x;
        }
        d = isize::min(d, x);

        if a[i] > a[i - 1] {
            s = 1;
        } else if a[i] < a[i - 1] {
            s = -1;
        } else {
            s = 0;
        }
    }
    d *= s;

    let mut i = 1;
    r.push(a[0]);
    loop {
        if s < 0 && r[i - 1] <= a[n - 1] {
            break;
        }
        if s > 0 && r[i - 1] >= a[n - 1] {
            break;
        }
        if s == 0 && i >= n {
            break;
        }

        r.push(r[i - 1] + d);
        i += 1;
    }
    return r;
}
