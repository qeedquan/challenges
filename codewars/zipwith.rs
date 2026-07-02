/*

Implement zipWith
zipWith takes a function and two arrays and zips the arrays together, applying the function to every pair of values.
The function value is one new array.

If the arrays are of unequal length, the output will only be as long as the shorter one.
(Values of the longer array are simply not used.)

Inputs should not be modified.

Examples
zipWith( Math.pow, [10,10,10,10], [0,1,2,3] )      =>  [1,10,100,1000]
zipWith( Math.max, [1,4,7,1,4,7], [4,7,1,4,7,1] )  =>  [4,7,7,4,7,7]

zipWith( function(a,b) { return a+b; }, [0,1,2,3], [0,1,2,3] )  =>  [0,2,4,6]  Both forms are valid.
zipWith( (a,b) => a+b,                  [0,1,2,3], [0,1,2,3] )  =>  [0,2,4,6]  Both are functions.
Input validation
Assume all input is valid.

*/

use std::cmp::min;

fn main() {
    assert_eq!(
        zipwith(pow, vec![10, 10, 10, 10], vec![0, 1, 2, 3]),
        vec![1, 10, 100, 1000]
    );
    assert_eq!(
        zipwith(isize::max, vec![1, 4, 7, 1, 4, 7], vec![4, 7, 1, 4, 7, 1]),
        vec![4, 7, 7, 4, 7, 7]
    );
    assert_eq!(
        zipwith(add, vec![0, 1, 2, 3], vec![0, 1, 2, 3]),
        vec![0, 2, 4, 6],
    );
}

fn zipwith(f: fn(isize, isize) -> isize, a: Vec<isize>, b: Vec<isize>) -> Vec<isize> {
    let mut r = vec![];
    let n = min(a.len(), b.len());
    for i in 0..n {
        r.push(f(a[i], b[i]));
    }
    r
}

fn add(x: isize, y: isize) -> isize {
    x + y
}

fn pow(x: isize, y: isize) -> isize {
    x.pow(y as u32)
}
