/*

Brief
Sometimes we need information about the list/arrays we're dealing with. You'll have to write such a function in this kata. Your function must provide the following informations:

Length of the array
Number of integer items in the array
Number of float items in the array
Number of string character items in the array
Number of whitespace items in the array

The informations will be supplied in arrays that are items of another array. Like below:

Output array = [[array length],[no of integer items],[no of float items],[no of string chars items],[no of whitespace items]]

Added Difficulty
If any item count in the array is zero, you'll have to replace it with a None/nil/null value (according to the language). And of course, if the array is empty then return 'Nothing in the array!. For the sake of simplicity, let's just suppose that there are no nested structures.
Output ====== If you're head is spinning (just kidding!) then these examples will help you out-


array_info([1,2,3.33,4,5.01,'bass','kick',' '])--------->[[8],[3],[2],[2],[1]]
array_info([0.001,2,' '])------------------------------>[[3],[1],[1],[None],[1]]
array_info([])----------------------------------------->'Nothing in the array!'
array_info([' '])-------------------------------------->[[1],[None],[None],[None],[1]]

Remarks
The input will always be arrays/lists. So no need to check the inputs.
Hint ==== See the tags!!!
Now let's get going !q

*/

package main

import "fmt"

func main() {
	fmt.Println(arrayinfo([]any{1, 2, 3.33, 4, 5.01, "bass", "kick", ' '}))
	fmt.Println(arrayinfo([]any{0.001, 2, ' '}))
	fmt.Println(arrayinfo([]any{}))
	fmt.Println(arrayinfo([]any{' '}))
}

func arrayinfo(a []any) any {
	if len(a) == 0 {
		return "Nothing in the array!"
	}

	r := make([]any, 5)
	c := [5]int{}
	for _, x := range a {
		switch x := x.(type) {
		case int:
			c[0]++
		case float64:
			c[1]++
		case string:
			c[2]++
		case rune:
			if x == ' ' {
				c[3]++
			}
		}
	}

	r[0] = len(a)
	for i := range c {
		if c[i] > 0 {
			r[i+1] = c[i]
		}
	}
	return r
}