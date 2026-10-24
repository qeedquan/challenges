/*

Write a function last that accepts a list and returns the last element in the list.

If the list is empty:

In languages that have a built-in option or result type (like OCaml or Haskell), return an empty option

In languages that do not have an empty option, just return nullq

*/

fn main() {
    assert_eq!(last(&[1, 2, 3]), Some(3));
    assert_eq!(last(&[]), None);
}

fn last(array: &[isize]) -> Option<isize> {
    if array.len() == 0 {
        return None;
    }
    return Some(array[array.len() - 1]);
}
