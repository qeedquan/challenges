/*

Write a function that doubles every second integer in a list, starting from the left.

Example:

For input array/list :

[1,2,3,4]
the function should return :

[1,4,3,8]

*/

fn main() {
    assert_eq!(double_every_other(&mut [1, 2, 3, 4]), &[1, 4, 3, 8]);
}

fn double_every_other(x: &mut [isize]) -> &[isize] {
    for i in (1..x.len()).step_by(2) {
        x[i] *= 2;
    }
    x
}
