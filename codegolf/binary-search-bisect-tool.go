/*

Implement the binary search algorithm as used to identify the source code revision that breaks a computer software program. Your tool should take two arguments specifying the earliest and latest numbered revision to search (both positive integers), and you have two options for making comparisons:

Execute the shell command ./test N, where N is the revision number. If the test passes (i.e. the revision is good), it will return exit code 0.

Call the function test(N), which will return true if the test passes, false otherwise.

Standard output must be the number of the first bad revision, and try to make your tool's source code as short as possible. Enjoy!

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(sort.Search(1000, test))
}

func test(n int) bool {
	fmt.Println("testing", n)
	return n >= 13
}
