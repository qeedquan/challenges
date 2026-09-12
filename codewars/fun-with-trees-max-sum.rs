/*

You are given a binary tree. Implement the method maxSum which returns the maximal sum of a route from root to leaf. For example, given the following tree:

    17
   /  \
  3   -10
 /    /  \
2    16   1
         /
        13
The method should return 23, since [17,-10,16] is the route from root to leaf with the maximal sum.

The class TreeNode is available for you:

var TreeNode = function(value, left, right) {
  this.value = value;
  this.left = left;
  this.right = right;
};

*/

use std::cmp::max;

struct Node {
    value: isize,
    left: Option<Box<Node>>,
    right: Option<Box<Node>>,
}

fn main() {
    let tree = Some(Box::new(Node {
        value: 17,
        left: Some(Box::new(Node {
            value: 3,
            left: Some(Box::new(Node {
                value: 2,
                left: None,
                right: None,
            })),
            right: None,
        })),
        right: Some(Box::new(Node {
            value: -10,
            left: Some(Box::new(Node {
                value: 16,
                left: None,
                right: None,
            })),
            right: Some(Box::new(Node {
                value: 1,
                left: Some(Box::new(Node {
                    value: 13,
                    left: None,
                    right: None,
                })),
                right: None,
            })),
        })),
    }));

    assert_eq!(maxsum(tree), 23);
}

fn maxsum(node: Option<Box<Node>>) -> isize {
    match node {
        None => 0,
        Some(n) => n.value + max(maxsum(n.left), maxsum(n.right)),
    }
}
