/*

Linked Lists - Get Nth
Implement a GetNth() function that takes a linked list and an integer index and returns the node stored at the Nth index position. GetNth() uses the C numbering convention that the first node is index 0, the second is index 1, ... and so on.

So for the list 42 -> 13 -> 666, GetNth(1) should return Node(13);

getNth(1 -> 2 -> 3 -> null, 0).data === 1
getNth(1 -> 2 -> 3 -> null, 1).data === 2
The index should be in the range [0..length-1]. If it is not, or if the list is empty, GetNth() should throw/raise an exception (ArgumentException in C#, InvalidArgumentException in PHP, Exception in Java).

*/

use std::collections::LinkedList;
use std::panic;

fn main() {
    let list1 = LinkedList::from([42, 13, 666]);
    let list2 = LinkedList::from([1, 2, 3]);

    assert_eq!(nth(&list1, 1), 13);
    assert_eq!(nth(&list2, 0), 1);
    assert_eq!(nth(&list2, 1), 2);
}

fn nth(list: &LinkedList<isize>, index: usize) -> isize {
    let mut iter = list.iter();
    let mut cursor = 0;
    while let Some(element) = iter.next() {
        if cursor == index {
            return *element;
        }
        cursor += 1;
    }
    panic!("ArgumentException");
}
