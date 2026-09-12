/*

Implement the methods anyMatch (any_match in PHP) & allMatch (all_match in PHP), which accepts a linked list (head) and a predicate function, and returns true if any / all of the elements apply to the given predicate.

For example:

Given the list: 1 -> 2 -> 3, and the predicate x => x > 1, anyMatch / any_match should return true (both 2 & 3 are valid for this predicate), and allMatch / all_match should return false (1 is not valid for this predicate)

The linked list is defined as follows:

function Node(data, next = null) {
  this.data = data;
  this.next = next;
}
Note: the list may be null and can hold any type of value.

Good luck!

*/

public class Node<T> {
    public var data: T
    public var next: Node<T>?

    public init(_ data: T, _ next: Node<T>? = nil) {
        self.data = data
        self.next = next
    }
}

func anyMatch<T>(_ node: Node<T>?, _ predicate: (T) -> Bool) -> Bool {
    guard var node = node else {
        return false
    }

    while true {
        if predicate(node.data) {
            return true
        }

        if let next = node.next {
            node = next
        } else {
            break
        }
    }
    return false
}

func allMatch<T>(_ node: Node<T>?, _ predicate: (T) -> Bool) -> Bool {
    guard var node = node else {
        return false
    }

    while true {
        if !predicate(node.data) {
            return false
        }

        if let next = node.next {
            node = next
        } else {
            break
        }
    }
    return true
}

func isEven(_ data: Int) -> Bool {
    return data % 2 == 0
}

var list = Node<Int>(1, Node<Int>(2, Node<Int>(3)))
print(anyMatch(list, isEven))
print(allMatch(list, isEven))
