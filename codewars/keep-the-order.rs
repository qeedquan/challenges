/*

Task:
Your job here is to write a function (keepOrder in JS/CoffeeScript, keep_order in Ruby/Crystal/Python, keeporder in Julia), which takes a sorted array ary and a value val, and returns the lowest index where you could insert val to maintain the sorted-ness of the array. The input array will always be sorted in ascending order. It may contain duplicates.

Do not modify the input.

Some examples:
keepOrder([1, 2, 3, 4, 7], 5) //=> 4
                      ^(index 4)
keepOrder([1, 2, 3, 4, 7], 0) //=> 0
          ^(index 0)
keepOrder([1, 1, 2, 2, 2], 2) //=> 2
                ^(index 2)

*/

use std::cmp::Ordering;

fn main() {
    assert_eq!(keep_order(&[1, 2, 3, 4, 7], 5), 4);
    assert_eq!(keep_order(&[1, 2, 3, 4, 7], 0), 0);
    assert_eq!(keep_order(&[1, 1, 2, 2, 2], 2), 2);
}

fn keep_order(array: &[isize], value: isize) -> usize {
    array
        .binary_search_by(|element| match element.cmp(&value) {
            Ordering::Equal => Ordering::Greater,
            ord => ord,
        })
        .unwrap_err()
}
