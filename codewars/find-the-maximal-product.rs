/*

Given a non-empty array of integers, find the maximum product of elements from all available sequences.

A sequence here is any pattern in which the elements are equally spaced apart in the array.

The sequence should start at its place in the array: for example, the sequence of 3 elements apart should start at the third element.

Example:

Given the array [11, 6, -2, 0, 5, -4, 2]

When the sequence is 1 element apart: Product = 11 × 6 × (-2) × 0 × 5 × (-4) × 2 = 0.

When the sequence is 2 apart: Product = 6 × 0 × (-4) = 0.

When the sequence is 3 apart: Product = (-2) × (-4) = 8.

When the sequence is 4 apart: Product = 0

When the sequence is 5 apart: Product = 5

When the sequence is 6 apart: Product = -4.

When the sequence is 7 apart: Product = 2.

So, the function should return 8.

*/

fn main() {
    assert_eq!(maximal(&vec![4, 0, -19]), 0);
    assert_eq!(maximal(&vec![11, 6, -2, 0, 5, -4, 2]), 8);
    assert_eq!(maximal(&vec![8, -6, 4, 0, 4, 0, -5, 0]), 4);
    assert_eq!(maximal(&vec![4, 6, 8, 11, 13, 5, 7, 9]), 8648640);
}

fn maximal(a: &Vec<isize>) -> isize {
    let mut r = isize::MIN;
    let n = a.len();
    for i in 0..n {
        let mut p = 1;
        let mut j = i;
        while j < n {
            p *= a[j];
            j += i + 1;
        }
        r = r.max(p);
    }
    r
}
