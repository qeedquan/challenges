/*

You will receive train set which should be used to build a model.
After you build a model tests will call function predict and pass x to it.

Error is going to be calculated with RMSE.

Blocked libraries: sklearn, pandas, tensorflow, numpy, scipy

Explanation
[1] A mining model is created by applying an algorithm to data, but it is more than an algorithm or a metadata container:
it is a set of data, statistics, and patterns that can be applied to new data to generate predictions and make inferences about relationships.

*/

package main

import "fmt"

func main() {
	data := [][2]float64{
		{0, 1},
		{2, 2},
		{4, 3},
		{9, 8},
		{3, 5},
	}
	datamine := Datamining{}
	datamine.Train(data)
	for _, val := range data {
		fmt.Println(val[0], datamine.Predict(val[0]), val[1])
	}
}

type Datamining struct {
	a, b float64
}

func (z *Datamining) Train(data [][2]float64) {
	n := float64(len(data))
	sum_x := 0.0
	sum_y := 0.0
	sum_xx := 0.0
	sum_xy := 0.0
	for _, val := range data {
		sum_x += val[0]
		sum_y += val[1]
		sum_xx += val[0] * val[0]
		sum_xy += val[0] * val[1]
	}

	z.a = (n*sum_xy - sum_x*sum_y) / (n*sum_xx - sum_x*sum_x)
	z.b = (sum_y - z.a*sum_x) / n
}

func (z *Datamining) Predict(x float64) float64 {
	return z.a*x + z.b
}
