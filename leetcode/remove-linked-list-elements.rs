/*

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

Constraints:

The number of nodes in the list is in the range [0, 10^4].
1 <= Node.val <= 50
0 <= val <= 50

*/

use std::collections::LinkedList;

fn main() {
    let mut l1 = LinkedList::from([1, 2, 6, 3, 4, 5, 6]);
    let mut l2 = LinkedList::new();
    let mut l3 = LinkedList::from([7, 7, 7, 7]);

    remove(&mut l1, 6);
    remove(&mut l2, 1);
    remove(&mut l3, 7);

    print(&l1);
    print(&l2);
    print(&l3);
}

fn remove(l: &mut LinkedList<isize>, v: isize) {
    let mut p = vec![];
    for x in l.iter() {
        if *x != v {
            p.push(*x);
        }
    }

    l.clear();
    for u in p {
        l.push_back(u);
    }
}

fn print(l: &LinkedList<isize>) {
    for v in l.iter() {
        print!("{} ", *v);
    }
    println!();
}
