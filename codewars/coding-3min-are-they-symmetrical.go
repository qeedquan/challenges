/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version

Task:
Give you an obj, it can be 3 types: string, number and number array, Check that they are symmetrical or not, return a boolean value.

Example:
```
obj=""    return true   (Empty string should return true)
obj="1"   return true   (one char should return true)
obj="11"  return true
obj="12"  return false
obj="121" return true
obj=1     return true   (number<10  should return true)
obj=-1    return false  (negative number should return false)
obj=10    return false
obj=11    return true
obj=12    return false
obj=121   return true
obj=[]    return true  (Empty array should return true)
obj=[1]   return true  (an array with one element should return true)
obj=[1,2,3,4,5]      return false
obj=[1,2,3,2,1]      return true
obj=[11,12,13,12,11] return true   (left element = right element)
obj=[11,12,21,11]    return false  (not verify them as a string)
```

*/

package main

import "cmp"

func main() {
	assert(symmetrical("") == true)
	assert(symmetrical("1") == true)
	assert(symmetrical("11") == true)
	assert(symmetrical("12") == false)
	assert(symmetrical("121") == true)

	assert(symmetrical(1) == true)
	assert(symmetrical(-1) == false)
	assert(symmetrical(10) == false)
	assert(symmetrical(11) == true)
	assert(symmetrical(12) == false)
	assert(symmetrical(121) == true)

	assert(symmetrical([]int{}) == true)
	assert(symmetrical([]int{1}) == true)
	assert(symmetrical([]int{1, 2, 3, 4, 5}) == false)
	assert(symmetrical([]int{1, 2, 3, 2, 1}) == true)
	assert(symmetrical([]int{11, 12, 13, 12, 11}) == true)
	assert(symmetrical([]int{11, 12, 21, 11}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func symmetrical(x any) bool {
	switch x := x.(type) {
	case string:
		return check([]byte(x))
	case int:
		d := digits(x)
		return len(d) > 0 && check(d)
	case []int:
		return check(x)
	default:
		panic("unsupported type")
	}
}

func digits(x int) []int {
	r := []int{}
	for ; x > 0; x /= 10 {
		r = append(r, x%10)
	}
	return r
}

func check[T cmp.Ordered](x []T) bool {
	for i, n := 0, len(x); i < n/2; i++ {
		if x[i] != x[n-i-1] {
			return false
		}
	}
	return true
}
