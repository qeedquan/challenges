/*

Aztec kings were very rich and they were proud of their wealth. Once an Aztec king ordered some
decoration items to decorate the palace. The decoration items were big cirlces (actually spheres, but
here we will consider them to be circles) of glasses. All the circles had the same radius. But it was
risky to bring the fragile circles to the palace, because the circles could break easily. The minister of
the king suggested that the circles should be packed in the smallest box possible so that they cannot
move inside the box. But the king was too proud to do so. He orderd that the boxes should be as large
as possible ensuring that the circles won’t be able to move inside the boxes, and of course they must
be of square-size. So the royal mathematician had a job in his hands, and he seeks your help. Each
box can have 9 or 10 circles. See the pictures below.

Box with 9 circles Box with 10 circles

Input
Input will consist of several test cases. In each test case, there will be a real number r (0 < r < 10000000)
denoting the radius of the circles. Input ends with EOF.

Output
For each test case print the length of one side of the box with 9 circles, then a space and then the size
of one side of the box with 10 circles, both upto 5-decimal places. A special judge will be used to check
your solution. So you need not worry about small precision errors.

Sample Input
0.00001
0.00002
0.00003

Sample Output
0.00007 0.00008
0.00014 0.00015
0.00021 0.00023

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(0.00001))
	fmt.Println(solve(0.00002))
	fmt.Println(solve(0.00003))
}

func solve(r float64) (float64, float64) {
	const (
		NINE = 7.022509503430381
		TEN  = 7.519130890631598
	)
	return NINE * r, TEN * r
}
