/*

You have to create a method "compoundArray" which should take as input two int arrays of different length and return one int array with numbers of both arrays shuffled one by one.

Input - {1,2,3,4,5,6} and {9,8,7,6} 
Output - {1,9,2,8,3,7,4,6,5,6}

*/

fn main() {
    assert_eq!(
        compound(&[1, 2, 3, 4, 5, 6], &[9, 8, 7, 6]),
        vec![1, 9, 2, 8, 3, 7, 4, 6, 5, 6]
    );
}

fn compound(a: &[isize], b: &[isize]) -> Vec<isize> {
    let (mut r, mut i, mut j) = (vec![], 0, 0);
    while i < a.len() || j < b.len() {
        if i < a.len() {
            r.push(a[i]);
            i += 1;
        }
        if j < b.len() {
            r.push(b[j]);
            j += 1;
        }
    }
    r
}
