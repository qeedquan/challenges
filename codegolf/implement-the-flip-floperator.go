/*

Ruby has a strange operator, .., called flip-flop (not to be confused with the range operator, which looks the same). Used in a loop, flip-flop takes two conditions as operands and will return false until the first operand is truthy, then return true until the second operand is truthy, whereupon it returns true one more time and restarts the cycle with false.

0.upto 10 do |i|
  if (i==2)..(i==8)
    puts i
  end
end

# Prints 2, 3, 4, 5, 6, 7, and 8
Attempt This Online

Your task is to implement a higher-order function (or something equivalent in your language) that behaves like flip-flop. It must take two predicate functions as arguments and return a new function that takes an argument and returns falsey until the first predicate returns true given the argument, continues to return true until the second predicate returns true, whereupon the flip-flop returns true one more time (think of it like an inclusive range) and thereafter returns false, until the first predicate returns true again and so on.

Below is an example of such a function called make_flip_flop, which takes two predicate lambdas and returns a new lambda, flip_flop, to be used in the following loop.

flip_flop = make_flip_flop(->i{ i==2 }, ->{ i == 8 })

0.upto 10 do |i|
  if flip_flop.(i)
    puts i
  end
end

# Prints 2, 3, 4, 5, 6, 7, and 8
Here's another example with a different set of predicates:

flip_flop = make_flip_flop(->i{ i % 5 == 0 }, ->i{ i % 5 == 2 })

0.upto 10 do |i|
  if flip_flop.(i)
    puts i
  end
end

# Prints 0, 1, 2, 5, 6, 7, and 10

Rules
Please include a brief example or description of how your solution works.

Since not all languages have first-class functions, the definition of "predicate" is loose. You could take the names of previously-defined functions to be called or a string to be eval'd, for example. Your solution may not, however, just take primitive values like true and false. It must be your language’s equivalent of a higher-order function.

Your predicate functions should take at least one argument, of any type that's convenient, as long as it's reasonable. (A predicate that only takes the specific value 1 is not reasonable, for example.)

Built-ins are allowed, but only if they fit the spec (it must be a function or similar, etc.). You can’t post Ruby, 2 bytes, ...

Default I/O rules apply, standard rules apply, and standard loopholes are forbidden.

This is code golf. Shortest answer in bytes wins.

*/

package main

import "fmt"

func main() {
	test(10, eq(2), eq(8))
	test(10, mod(5, 0), mod(5, 2))
}

func test(n int, f, g predicate) {
	p := flipflop(f, g)
	for i := 0; i <= n; i++ {
		if p(i) {
			fmt.Printf("%v ", i)
		}
	}
	fmt.Println()
}

func eq(n int) predicate {
	return func(i int) bool {
		return i == n
	}
}

func mod(m, n int) predicate {
	return func(i int) bool {
		return i%m == n
	}
}

func flipflop(f, g predicate) predicate {
	s := 0
	return func(i int) bool {
		switch s {
		case 0:
			if v := f(i); v {
				s = 1
			}
		case 1:
			if v := g(i); v {
				s = 0
				return true
			}
		}
		return s != 0
	}
}

type predicate func(int) bool
