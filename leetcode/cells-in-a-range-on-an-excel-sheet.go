/*

A cell (r, c) of an excel sheet is represented as a string "<col><row>" where:

<col> denotes the column number c of the cell. It is represented by alphabetical letters.
For example, the 1st column is denoted by 'A', the 2nd by 'B', the 3rd by 'C', and so on.
<row> is the row number r of the cell. The rth row is represented by the integer r.
You are given a string s in the format "<col1><row1>:<col2><row2>", where <col1> represents the column c1,
<row1> represents the row r1, <col2> represents the column c2, and <row2> represents the row r2, such that r1 <= r2 and c1 <= c2.

Return the list of cells (x, y) such that r1 <= x <= r2 and c1 <= y <= c2.
The cells should be represented as strings in the format mentioned above and be sorted in non-decreasing order first by columns and then by rows.

Example 1:
https://assets.leetcode.com/uploads/2022/02/08/ex1drawio.png

Input: s = "K1:L2"
Output: ["K1","K2","L1","L2"]
Explanation:
The above diagram shows the cells which should be present in the list.
The red arrows denote the order in which the cells should be presented.

Example 2:

https://assets.leetcode.com/uploads/2022/02/09/exam2drawio.png

Input: s = "A1:F1"
Output: ["A1","B1","C1","D1","E1","F1"]
Explanation:
The above diagram shows the cells which should be present in the list.
The red arrow denotes the order in which the cells should be presented.

Constraints:

s.length == 5
'A' <= s[0] <= s[3] <= 'Z'
'1' <= s[1] <= s[4] <= '9'
s consists of uppercase English letters, digits and ':'.

Hint 1
From the given string, find the corresponding rows and columns.

Hint 2
Iterate through the columns in ascending order and for each column, iterate through the rows in ascending order to obtain the required cells in sorted order.

*/

package main

import "fmt"

func main() {
	fmt.Println(cells("K1:L2"))
	fmt.Println(cells("A1:F1"))
}

func cells(s string) []string {
	r := []string{}
	if len(s) != 5 {
		return r
	}

	for x := s[0]; x <= s[3]; x++ {
		for y := s[1]; y <= s[4]; y++ {
			r = append(r, fmt.Sprintf("%c%c", x, y))
		}
	}
	return r
}
