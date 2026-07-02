/*

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

Example 1:
https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png

Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.

Example 2:
https://assets.leetcode.com/uploads/2022/02/02/ex2-1.png

Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation:
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.

Constraints:

    The number of nodes in the list is in the range [3, 2 * 10^5].
    0 <= Node.val <= 1000
    There are no two consecutive nodes with Node.val == 0.
    The beginning and end of the linked list have Node.val == 0.

Hint 1
How can you use two pointers to modify the original list into the new list?

Hint 2
Have a pointer traverse the entire linked list, while another pointer looks at a node that is currently being modified.

Hint 3
Keep on summing the values of the nodes between the traversal pointer and the modifying pointer until the former comes across a ‘0’. In that case, the modifying pointer is incremented to modify the next node.

Hint 4
Do not forget to have the next pointer of the final node of the modified list point to null.

*/

package main

import "fmt"

func main() {
	list1 := mklist(0, 3, 1, 0, 4, 5, 2, 0)
	list2 := mklist(0, 1, 0, 3, 0, 2, 2, 0)

	list1 = mergezero(list1)
	list2 = mergezero(list2)

	printlist(list1)
	printlist(list2)
}

type List struct {
	value int
	next  *List
}

func mklist(values ...int) *List {
	var head *List
	previous := &head
	for _, value := range values {
		next := &List{value: value}
		*previous, previous = next, &next.next
	}
	return head
}

func mergezero(head *List) *List {
	if head == nil {
		return head
	}

	zero := head
	for current := head.next; current != nil; current = current.next {
		if current.value != 0 {
			zero.value += current.value
		} else {
			if current.next != nil {
				zero.next = current
			} else {
				zero.next = nil
			}
			zero = current
		}
	}
	return head
}

func printlist(head *List) {
	if head == nil {
		fmt.Println("(nil)")
		return
	}
	for ; head != nil; head = head.next {
		fmt.Printf("%d", head.value)
		if head.next != nil {
			fmt.Printf(" -> ")
		}
	}
	fmt.Println()
}
