/*

You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:
https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample0.png

Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:
https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample1.png

Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:
https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample2.png

No node has value 5.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
All elements in nums are unique.
The number of nodes in the given list is in the range [1, 10^5].
1 <= Node.val <= 10^5
The input is generated such that there is at least one node in the linked list that has a value not present in nums.

Hint 1
Add all elements of nums into a Set.

Hint 2
Scan the list to check if the current element should be deleted by checking the Set.

*/

package main

import "fmt"

func main() {
	list1 := modify([]int{1, 2, 3}, mklist(1, 2, 3, 4, 5))
	list2 := modify([]int{1}, mklist(1, 2, 1, 2, 1, 2))
	list3 := modify([]int{5}, mklist(1, 2, 3, 4))

	printlist(list1)
	printlist(list2)
	printlist(list3)
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

func modify(numbers []int, head *List) *List {
	seen := make(map[int]bool)
	for _, number := range numbers {
		seen[number] = true
	}

	dummy := List{next: head}
	current := &dummy
	for current.next != nil {
		if !seen[current.next.value] {
			current = current.next
		} else {
			current.next = current.next.next
		}
	}
	return dummy.next
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
