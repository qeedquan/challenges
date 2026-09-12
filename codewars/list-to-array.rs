/*

Linked lists are data structures composed of nested or chained objects, each containing a single value and a reference to the next object.

Here's an example of a list:

{value: 1, next: {value: 2, next: {value: 3, next: null}}}

Write a function listToArray (or list_to_array in Python) that converts a list to an array, like this:

[1, 2, 3]

Assume all inputs are valid lists with at least one value. For the purpose of simplicity, all values will be either numbers, strings, or Booleans.

*/

use std::collections::LinkedList;

fn main() {
    let mut list1 = LinkedList::new();
    let mut list2 = LinkedList::new();
    list1.push_back('a');
    list1.push_back('b');
    list1.push_back('c');
    for i in 0..10 {
        list2.push_back(i);
    }
    println!("{:?}", list_to_array::<char>(&list1));
    println!("{:?}", list_to_array::<isize>(&list2));
}

fn list_to_array<T: Clone>(list: &LinkedList<T>) -> Vec<T> {
    let mut array = vec![];
    let mut iter = list.iter();
    while let Some(&ref value) = iter.next() {
        array.push(value.clone());
    }
    array
}
