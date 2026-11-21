/*

A user-item rating matrix is often sparse, with zero representing a missing rating. Mean imputation fills each missing entry using observed ratings from either the same user or the same item.

In user mode, replace each zero in a row with the mean of that row's nonzero ratings. In item mode, replace each zero in a column with the mean of that column's nonzero ratings. If a user or item has no observed ratings, use 0.0 as its mean. Return a new matrix and leave ratings_matrix unchanged.

Examples
Input: ratings_matrix = [[5, 3, 0], [4, 0, 2], [0, 1, 5]], mode = "user"

Output: [[5, 3, 4.0], [4, 3.0, 2], [3.0, 1, 5]]

Explanation: Each zero is replaced by the mean of the nonzero ratings in its row.

Input: ratings_matrix = [[5, 3, 0], [4, 0, 2], [0, 1, 5]], mode = "item"

Output: [[5, 3, 3.5], [4, 2.0, 2], [4.5, 1, 5]]

Hint 1
For user mode, compute one mean from each row before replacing its zeros.

Hint 2
For item mode, compute all column means before filling the copied matrix.

Requirements
Treat zero as a missing rating.
In user mode, impute each zero with its user mean.
In item mode, impute each zero with its item mean.
Use 0.0 when the corresponding user or item has no observed ratings.
Return a new matrix with the same shape.
Constraints
ratings_matrix is a nonempty rectangular matrix.
mode is either user or item.
Ratings are nonnegative numbers.
Time limit: 300 ms.

*/

package main

import "fmt"

func main() {
	fmt.Println(imputation(
		[][]float64{{5, 3, 0}, {4, 0, 2}, {0, 1, 5}},
		"user",
	))

	fmt.Println(imputation(
		[][]float64{{5, 3, 0}, {4, 0, 2}, {0, 1, 5}},
		"item",
	))
}

func imputation(ratings [][]float64, mode string) [][]float64 {
	size := len(ratings)
	output := make([][]float64, size)
	for i := range size {
		output[i] = make([]float64, size)
		copy(output[i], ratings[i])
	}

	switch mode {
	case "user":
		for i := range size {
			sum := 0.0
			length := 0.0
			for j := range size {
				if ratings[i][j] != 0 {
					sum += ratings[i][j]
					length += 1
				}
			}

			mean := sum / length
			for j := range size {
				if output[i][j] == 0 {
					output[i][j] = mean
				}
			}
		}

	case "item":
		for i := range size {
			sum := 0.0
			length := 0.0
			for j := range size {
				if ratings[j][i] != 0 {
					sum += ratings[j][i]
					length += 1
				}
			}

			mean := sum / length
			for j := range size {
				if output[j][i] == 0 {
					output[j][i] = mean
				}
			}
		}
	}

	return output
}
