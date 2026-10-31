/*

Each snake in the group has its name inscribed on it, using lowercase Latin letters from head to tail.
The snakes crawl in a line, one after another, as this makes it easier for them to move.
Occasionally, the leader will issue a "Reverse" command.
When this happens, each snake in the group turns around, and the entire group begins crawling in the opposite direction.
The group's name can be read by starting at the head of the first snake and continuing to the tail of the last one.
This name may change after the "Reverse" command, but the individual names of the snakes remain unchanged.

Input
The first line contains a single integer N (1≤N≤100000), representing the number of snakes.
The following N lines list the names of the snakes in the order they are crawling.
Each snake's name is a string of no more than 10 lowercase Latin letters.

Output
Print a single line containing the name of the group after the "Reverse" command.

Examples
Input #1
3
abc
def
ghi

Answer #1
ghidefabc

*/

package main

import "fmt"

func main() {
	solve([]string{
		"abc",
		"def",
		"ghi",
	})
}

func solve(s []string) {
	for i := len(s) - 1; i >= 0; i-- {
		fmt.Printf("%s", s[i])
	}
	fmt.Println()
}
