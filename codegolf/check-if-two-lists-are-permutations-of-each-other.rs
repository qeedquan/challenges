/*

Challenge
Given two lists, find if one of them is a permutation of the other. Output truthy or falsy values, or 1 or 0.

Test case Examples
{0,1,2,3,4},{2,4,3,0,1} --> True
{2,4,4,7}{2,7,4,6} --> False
{1},{1} --> True

Other Stuff
This is code golf, so shortest code wins
Standard loopholes and I/O methods apply
Longest test case consists of numbers with at most 16 binary digits and lengths of lists being at most 64.

*/

fn main() {
    assert_eq!(
        permutation(&mut vec![0, 1, 2, 3, 4], &mut vec![2, 4, 3, 0, 1]),
        true
    );

    assert_eq!(
        permutation(&mut vec![2, 4, 4, 7], &mut vec![2, 7, 4, 6]),
        false
    );

    assert_eq!(permutation(&mut vec![1], &mut vec![1]), true);
}

fn permutation(x: &mut Vec<isize>, y: &mut Vec<isize>) -> bool {
    x.sort();
    y.sort();
    if x.len() != y.len() {
        return false;
    }
    for i in 0..x.len() {
        if x[i] != y[i] {
            return false;
        }
    }
    return true;
}
