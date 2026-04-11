/*

Write a program that will remove all duplicates from a sequence of integers and print the list of unique
integers occuring in the input sequence, along with the number of occurences of each.

Input
The input file will contain a sequence of integers (positive, negative, and/or zero). The input file may
be arbitrarily long.

Output
The output for this program will be a sequence of ordered pairs, separated by newlines. The first
element of the pair must be an integer from the input file. The second element must be the number
of times that that particular integer appeared in the input file. The elements in each pair are to be
separated by space characters. The integers are to appear in the order in which they were contained in
the input file.

Sample Input
3 1 2 2 1 3 5 3 3 2

Sample Output
3 4
1 2
2 3
5 1

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([]int{3, 1, 2, 2, 1, 3, 5, 3, 3, 2}))
}

func solve(values []int) [][2]int {
	order := [][2]int{}
	count := make(map[int]int)
	for _, value := range values {
		if count[value] == 0 {
			order = append(order, [2]int{value, 0})
		}
		count[value] += 1
	}
	for index := range order {
		order[index][1] = count[order[index][0]]
	}
	return order
}
