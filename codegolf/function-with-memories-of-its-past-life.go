/*

Task
I need a function that accept string and return a function f1.

That f1 function should also accept string and return a f2 function, but as a side effect it must print string passed to previous function.

That f2 function should also accept string and return a f3 function, but as a side effect it must print string passed to previous function.

And so on.

For language that require explicit declaration of side effects (like haskell) you may return next best thing (like IO(...) in haskell).

For language that don't have function as first class object (like Java) you may return next best thing (like instance of Function interface in Java).

You need to show function and example of it usage.

This is code golf all standard rules apply. Only function itself is counted in score. Example is for demonstration only.

Reference implementation in Java
    static Function<String, Function> f(String s) {
        class C implements Function<String, Function> {
            String s1;

            public C(String s) {
                s1 = s;
            }

            @Override
            public Function apply(String s) {
                System.out.println(s1);
                return new C(s);
            }
        }
        return new C(s);
    }

Example of usage

        Function<String, Function> t = f("s1");
        t = t.apply("s2"); // Prints "s1"
        t = t.apply("s3"); // Prints "s2"

*/

package main

import "fmt"

type fn func(string) fn

func main() {
	g := f("s1")
	g = g("s2")
	g = g("s3")
	g = g("s4")
}

func f(s string) fn {
	return func(t string) fn {
		fmt.Println(s)
		return f(t)
	}
}
