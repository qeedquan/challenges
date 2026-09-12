/*

If you want to skip the lesson on recursion and go straight to the task, scroll to the bottom of this page.

The definition
The definition of a recursive function is rather simple: A function that calls itself, until something causes it not to.

This means that to write a recursive function two elements must be present:


Somewhere within your function, the function must call itself.
function recursive(n){recursive(m)}

As you can see in the example above, the function recursive calls itself again.
I have given it a different parameter when it calls itself again to demonstrate that you can feed a different value to the function if you wish, for example m ==n+1.
However, it is possible that m == n and thus the function calls itself again with the same parameter.

There must be a reason for the function to stop calling itself, and return the result.
function recursive(n){(if x == y) return z;  recursive(m)}


Without the if statement, the function would keep calling itself and eventually your codewars solution would crash.
In this example, you could have x == m so that once a certain parameter is fed in to the solution, the recursion stops. This is often used to stop a function multiplying itself by 0.

A working example of recursion
Imagine you want to print an array of numbers from a ... b. You could do this iteratively using a for loop.
However, you could also do it via recursion as per below.


let output = [];//An output is created outside the function to store our result
function recursive(a,b){ // The function is called with a and b as parameters
output.push(a);//We are pushing the current value of a to our output array
if(a == b) return output;//We have an if statement that will stop the function from calling itself on the next line
recursive(a+1,b);//We call the recursive function again , except we call it with the parameter a being 1 higher than before
}
recursive(1,3) //Here we call the function to being the process and give it two values to count to.

How would this run?

First call:
function recursive(1,3){ // The function is called with 1 and 3 as parameters
output.push(1);//The current value of a, 1, is pushed to our output array. Now output == [1]
if(1 == 3) return output;//1 does not equal 3 so the code after the if statement is not executed
recursive(1+1,3);//We call the recursive function again , except we call it with the parameter a being 1 higher than before
}

Second call:
function recursive(2,3){ // The function is called with 2 and 3 as parameters
output.push(2);//The current value of a, 2, is pushed to our output array. Now output == [1,2]
if(2 == 3) return output;//2 does not equal 3 so the code after the if statement is not executed
recursive(2+1,3);//We call the recursive function again , except we call it with the parameter a being 1 higher than before
}

Third call:
function recursive(3,3){ // The function is called with 3 and 3 as parameters
output.push(2);//The current value of a, 3, is pushed to our output array. Now output == [1,2,3]
if(2 == 3) return output;//3 does equal 3 so output is returned
recursive(2+1,3);//This line of code is not executed because the function has returned a value so the recursive function no longer calls itself
}

Your Task
You are on a set of stairs that are numbered 0 - 100 from top to bottom. You are given your starting stair number, a stride width (meaning how many stairs you step down at a time) and being walking down. Return an array containing every stair you step on, beginning from the lowest stair. Don't step below 0, it's Lava and you'll burn/fail the Kata.
A test is in place to check for the presence of for/while to ensure recursion is used so avoid using these terms in your solution.

If width is 0, clearly you're not going anywhere so please return an empty array.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(10, 1, []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
	test(80, 10, []int{0, 10, 20, 30, 40, 50, 60, 70, 80})
	test(49, 10, []int{9, 19, 29, 39, 49})
	test(5, 7, []int{5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(stair, width int, expected []int) {
	result := stepdown(stair, width)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func stepdown(stair, width int) []int {
	switch {
	case width < 1 || stair < 0:
		return []int{}
	case stair < width:
		return []int{stair}
	default:
		return append(stepdown(stair-width, width), stair)
	}
}
