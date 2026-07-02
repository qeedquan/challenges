/*

The span function is a good one to know. It accepts a sequence and a predicate function and returns two sequences. The first sequence contains all the elements of the argument sequence up to the item that caused the first failure of the predicate. The second returned sequence contains the rest of the original sequence. The original sequence is not modified.

For example,


function isEven (x) {
  return Math.abs(x) % 2 === 0;
}

var arr = [2,4,6,1,8,10];

// This is true
span(arr, isEven) === [[2,4,6],[1,8,10]]
Your task is to...wait for it... write your own span function !!!

Hint/Challenge: If you have completed the takeWhile function and the dropWhile function, then you can solve this problem in one line!

*/

fn main() {
    assert_eq!(
        span(&[2, 4, 6, 1, 8, 10], iseven),
        (vec![2, 4, 6], vec![1, 8, 10])
    );
    assert_eq!(
        span(&[2, 4, 6, 1, 4, 8], iseven),
        (vec![2, 4, 6], vec![1, 4, 8])
    );
    assert_eq!(span(&[], istrue), (vec![], vec![]));
    assert_eq!(
        span(&[1, 4, 5, 7, 6], iseven),
        (vec![], vec![1, 4, 5, 7, 6])
    );
    assert_eq!(
        span(&[13, 17, 19, 11, 21], isodd),
        (vec![], vec![13, 17, 19, 11, 21])
    );
}

fn span(array: &[isize], predicate: fn(isize) -> bool) -> (Vec<isize>, Vec<isize>) {
    let mut right = vec![];
    let mut wrong = vec![];
    for &value in array {
        if wrong.len() == 0 && predicate(value) {
            right.push(value);
        } else {
            wrong.push(value);
        }
    }
    (right, wrong)
}

fn iseven(number: isize) -> bool {
    number % 2 == 0
}

fn isodd(number: isize) -> bool {
    number % 2 == 0
}

fn istrue(_: isize) -> bool {
    true
}
