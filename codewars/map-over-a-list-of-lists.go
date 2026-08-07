/*

Write a function which maps a function over the lists in a list:

gridMap :: (a -> b) -> [[a]] -> [[b]]

Example 1:

x = [[1,2,3],
     [4,5,6]]

gridMap (+1) x
-- returns [[2,3,4],[5,6,7]]

gridMap (^2) x
-- returns [[1,4,9],[16,25,36]]

Example 2

import Data.Char
x = ["hEllO", "wOrLd"]

gridMap toUpper x
-- returns ["HELLO, WORLD"]

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(gridmap(add1, [][]int{{1, 2, 3}, {4, 5, 6}}))
	fmt.Println(gridmap(double, [][]int{{1, 2, 3}, {4, 5, 6}}))
	fmt.Println(gridmap(upper, [][]string{{"h", "E", "l", "l", "O"}, {"w", "O", "r", "L", "d"}}))
}

func add1(x int) int        { return x + 1 }
func double(x int) int      { return x * x }
func upper(x string) string { return strings.ToUpper(x) }

func gridmap[T int | string](f func(T) T, x [][]T) [][]T {
	r := [][]T{}
	for i := range x {
		v := []T{}
		for j := range x[i] {
			v = append(v, f(x[i][j]))
		}
		r = append(r, v)
	}
	return r
}
