/*

Write funcion lenR which returns the length of a given list. Try no to cheat and provide recursive solution.

*/

fn main() {
    assert_eq!(length(&[1, 2, 3, 4, 5]), 5);
    assert_eq!(length(&[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]), 10);
}

fn length(a: &[isize]) -> isize {
    if a.len() == 0 {
        return 0;
    }
    return 1 + length(&a[1..]);
}
