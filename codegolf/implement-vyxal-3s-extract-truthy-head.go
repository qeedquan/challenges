/*

As of its latest pre-release, Vyxal 3 has an element that:

Given a function and a list,
returns the first element in the list that the function returns a truthy value for,
as well as the list with that element removed.

I call it extract-truthy-head, it's useful in situations where you want to iteratively consume elements from a list.

This is code-golf.

Input:

A List, Array, Stack, or any ordered data structure supported by your language. You may choose to specify it only contains type T. It may contain multiple instances of any value. I'm calling it lst for this explanation
A black box monadic function that has the signature f(T) => bool where bool is any type that coerces to a truthy/falsey value in your language. It is total over type T. I'm calling it f for this explanation
Output:

The first element of the list where the function returns a truthy value. lst[i] such that f(lst[i]) == True and i is minimal, AND
lst with that element removed. lst[:i] + lst[i+1:]. You may not remove any but the first instance of that value. The order of the elements must be preserved.
If f(lst[i]) is false for all i, undefined behavior is allowed. The vyxal implementation simply outputs 0 and the original list, but you may wipe the user's hard drive if you want.

Reference implementation:

"κ" ->
    direct(Dyad) {
    pop() match
        case predicate: VFun => pop() match
            case VList(lst) =>
                val ret = lst.find(predicate(_).toBool).getOrElse(null)
                val (before, atAndAfter) = lst.span(_ != ret)
                push(before.appendedAll(atAndAfter.drop(1)))
                push(if ret != null then ret else VNum(0))
    },
Test cases:

[1,2,3,4], {isEven(_)} => 2, [1,3,4]
[4,5,6,7,3], {isPrime(_)} => 5, [4,6,7,3]
[100, 10, 1000], {log10(_) >= 3} => 1000, [100,10]

range(100), {A006666(_) > 50} => 27, range(27)+range(28,100)
[{isEven(_)}, {isOdd(_)}], {_(5) == True} => {isOdd(_)}

*/

package main

import (
	"fmt"
	"math"
	"math/big"
)

func main() {
	fmt.Println(extract_truthy_head([]int{1, 2, 3, 4}, is_even))
	fmt.Println(extract_truthy_head([]int64{4, 5, 6, 7, 3}, is_prime))
	fmt.Println(extract_truthy_head([]float64{100, 10, 1000}, log10_gt_3))
}

func extract_truthy_head[T any](array []T, predicate func(T) bool) (T, []T) {
	var zero T
	for index := range array {
		if predicate(array[index]) {
			value := array[index]
			return value, append(array[:index], array[index+1:]...)
		}
	}
	return zero, array
}

func is_even(x int) bool {
	return x%2 == 0
}

func is_prime(x int64) bool {
	z := big.NewInt(x)
	return z.ProbablyPrime(2)
}

func log10_gt_3(x float64) bool {
	return math.Log10(x) >= 3
}
