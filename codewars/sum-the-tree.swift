/*

Given a node object representing a binary tree:

Node:
  value: <int>,
  left: <Node> or null,
  right: <Node> or null
write a function that returns the sum of all values, including the root. Absence of a node will be indicated with a null value.

Examples:

10
| \
1  2
=> 13

1
| \
0  0
    \
     2
=> 3

*/

import Foundation

public class Node<T: Numeric> {
    public var value: T
    public var left: Node<T>?
    public var right: Node<T>?

    public init(_ value: T, _ left: Node<T>? = nil, _ right: Node<T>? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

func sumTheTreeValues<T: Numeric>(_ node: Node<T>?) -> T {
    if node == nil {
        return 0
    }

    let node = node!
    return node.value + sumTheTreeValues(node.left) + sumTheTreeValues(node.right)
}

var node = Node(10, Node(1), Node(2))
assert(sumTheTreeValues(node) == 13)

node = Node(1, Node(0), Node(0, nil, Node(2)))
assert(sumTheTreeValues(node) == 3)
