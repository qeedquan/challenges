/*

Aspect-oriented programming (AOP) is programming that adds additional behavior (advice) to existing functionality without actually modifying that functionality.

Create a method called adviseBefore. This method will take two arguments, a function (target) and the advising function (advice).

adviseBefore should return a function that, when executed, will first execute the advising function and then the original method with the following conditions:

The arguments passed to the function that adviseBefore returns should be passed to the advising function.
If the advising function returns an array, the array should replace the arguments passed to the original method.
If the advising function does not return an array, the original arguments should be passed to the original method.
The return value of the original method should be returned.

*/

package main

import (
	"fmt"
	"math/rand"
	"reflect"
)

type fn func(any) any

func main() {
	f := advise(print1, print2)
	f(2)
}

func advise(target, advice fn) fn {
	return func(args any) any {
		ret := advice(args)
		rt := reflect.TypeOf(ret)
		switch rt.Kind() {
		case reflect.Slice, reflect.Array:
			return target(ret)
		}
		return target(args)
	}
}

func print1(x any) any {
	fmt.Println("print1:", x)
	return 0
}

func print2(x any) any {
	fmt.Println("print2:", x)
	if rand.Intn(2) == 0 {
		return []int{4, 5, 6}
	}
	return 5
}
