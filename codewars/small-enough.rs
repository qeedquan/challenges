/*

*** No Loops Allowed ***

You will be given an array (a) and a limit value (limit). You must check that all values in the array are below or equal to the limit value. If they are, return true. Else, return false.

You can assume all values in the array are numbers.

Do not use loops. Do not modify input array.

*/

fn main() {
    assert_eq!(small_enough(&vec![66, 101], 200), true);

    assert_eq!(
        small_enough(&vec![78, 117, 110, 99, 104, 117, 107, 115], 100),
        false
    );

    assert_eq!(small_enough(&vec![101, 45, 75, 105, 99, 107], 107), true);

    assert_eq!(
        small_enough(&vec![80, 117, 115, 104, 45, 85, 112, 115], 120),
        true
    );

    assert_eq!(small_enough(&vec![1, 1, 1, 1, 1, 2], 1), false);

    assert_eq!(small_enough(&vec![78, 33, 22, 44, 88, 9, 6], 87), false);

    assert_eq!(small_enough(&vec![1, 2, 3, 4, 5, 6, 7, 8, 9], 10), true);

    assert_eq!(
        small_enough(&vec![12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12], 12),
        true
    );
}

fn small_enough(array: &Vec<isize>, limit: isize) -> bool {
    recurse(array, limit, 0)
}

fn recurse(array: &Vec<isize>, limit: isize, index: usize) -> bool {
    if index >= array.len() {
        return true;
    }
    if array[index] > limit {
        return false;
    }
    return recurse(array, limit, index + 1);
}
