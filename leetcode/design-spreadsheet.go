/*

A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
void resetCell(String cell) Resets the specified cell to 0.
int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.

Example 1:

Input:
["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
[[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]

Output:
[null, 12, null, 16, null, 25, null, 15]

Explanation

Spreadsheet spreadsheet = new Spreadsheet(3); // Initializes a spreadsheet with 3 rows and 26 columns
spreadsheet.getValue("=5+7"); // returns 12 (5+7)
spreadsheet.setCell("A1", 10); // sets A1 to 10
spreadsheet.getValue("=A1+6"); // returns 16 (10+6)
spreadsheet.setCell("B2", 15); // sets B2 to 15
spreadsheet.getValue("=A1+B2"); // returns 25 (10+15)
spreadsheet.resetCell("A1"); // resets A1 to 0
spreadsheet.getValue("=A1+B2"); // returns 15 (0+15)

Constraints:

1 <= rows <= 10^3
0 <= value <= 10^5
The formula is always in the format "=X+Y", where X and Y are either valid cell references or non-negative integers with values less than or equal to 10^5.
Each cell reference consists of a capital letter from 'A' to 'Z' followed by a row number between 1 and rows.
At most 10^4 calls will be made in total to setCell, resetCell, and getValue.

Hint 1
Use a hashmap to represent the cells, where the key is the cell reference (e.g., "A1") and the value is the integer stored in the cell.

Hint 2
For setCell, simply assign the given value to the specified cell in the hashmap.

Hint 3
For resetCell, set the value of the specified cell to 0 in the hashmap.

Hint 4
For getValue, find the values of the operands from the hashmap and return their sum.

*/

package main

import (
	"go/ast"
	"go/parser"
	"go/token"
	"strconv"
	"strings"
)

func main() {
	s := NewSpreadsheet(3)
	assert(s.GetValue("=5+7") == 12)
	s.SetCell("A1", 10)
	assert(s.GetValue("=A1+6") == 16)
	s.SetCell("B2", 15)
	assert(s.GetValue("=A1+B2") == 25)
	s.ResetCell("A1")
	assert(s.GetValue("=A1+B2") == 15)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Spreadsheet struct {
	lookup map[string]int
}

func NewSpreadsheet(int) *Spreadsheet {
	return &Spreadsheet{
		lookup: make(map[string]int),
	}
}

func (s *Spreadsheet) SetCell(cell string, value int) {
	s.lookup[cell] = value
}

func (s *Spreadsheet) ResetCell(cell string) {
	delete(s.lookup, cell)
}

func (s *Spreadsheet) GetValue(formula string) int {
	formula = strings.TrimPrefix(formula, "=")
	node, err := parser.ParseExpr(formula)
	if err != nil {
		return 0
	}
	return s.walk(node)
}

func (s *Spreadsheet) walk(node ast.Expr) int {
	switch node := node.(type) {
	case *ast.Ident:
		return s.lookup[node.Name]

	case *ast.BinaryExpr:
		lhs := s.walk(node.X)
		rhs := s.walk(node.Y)
		switch node.Op {
		case token.ADD:
			return lhs + rhs
		}

	case *ast.BasicLit:
		value, _ := strconv.Atoi(node.Value)
		return value
	}

	return 0
}
