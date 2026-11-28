/*

Implement a generic Stack.

Implement the interface Stackable<T>.

Implement the class MyStack<T> based on the Stack data structure, such that it implements the interface Stackable<T>.

Java

interface Stackable<T>
{
  void push(T value); // push an element to the top of the stack
  T pop();            // remove and return the element from the top of the stack
  T peek();           // return the element at the top of the stack
  boolean Empty();    // check if the stack is empty
  int size();         // return the size of the stack
}

class MyStack<T> implements Stackable<T>
{
  public Stack<T> s;
   ...
}

C++

template <class T>
class Stackable
{
public:
  void push(T value); // push an element to the top of the stack
  T pop();            // remove and return the element from the top of the stack
  T peek();           // return the element at the top of the stack
  bool Empty();       // check if the stack is empty
  int size();         // return the size of the stack
};

template <class T>
class MyStack : public Stackable<T>
{
public:
  stack<T> s;

};

Input
This problem does not require input.

Output
This problem does not require output.

*/

package main

import "fmt"

func main() {
	var (
		stackint Stack[int]
		stackstr Stack[string]
		stackflt Stack[float64]
	)
	test(&stackint)
	test(&stackstr)
	test(&stackflt)
}

func test[T any](stack Stackable[T]) {
	var value T
	stack.Push(value)
	fmt.Println(stack.Peek())
	fmt.Println(stack.Pop())
	fmt.Println(stack.Empty())
	fmt.Println(stack.Size())
}

type Stackable[T any] interface {
	Push(T)
	Pop() T
	Peek() T
	Empty() bool
	Size() int
}

type Stack[T any] []T

func (s *Stack[T]) Push(v T) {
	*s = append(*s, v)
}

func (s *Stack[T]) Pop() T {
	n := len(*s)
	v := (*s)[n-1]
	*s = (*s)[:n-1]
	return v
}

func (s Stack[T]) Peek() T {
	return (s)[len(s)-1]
}

func (s Stack[T]) Empty() bool {
	return len(s) == 0
}

func (s Stack[T]) Size() int {
	return len(s)
}
