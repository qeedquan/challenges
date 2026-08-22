#!/usr/bin/env python3

"""

This is a nice exercise for becoming more fluent in that programming language you've been meaning to learn, but have only tinkered with lightly. This involves working with objects, using or simulating closures, and stretching the type system.

Your task is to write code to manage lazy lists, then use it to implement this algorithm for generating Fibonacci numbers:

Code samples are in Haskell

let fibs = 0 : 1 : zipWith (+) fibs (tail fibs)
 in take 40 fibs
Result:

[0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986]
Your lazy list implementation should meet these guidelines:

A List node is one of three things:
Nil - Empty list.
[]
Cons - A single item, paired with a List of the remaining items:
1 : [2,3,4,5]
(: is the cons operator in Haskell)
Thunk - A deferred computation that produces a List node when needed.
It supports the following operations:
nil - Construct an empty list.
cons - Construct a cons cell.
thunk - Construct a Thunk, given a function that takes no arguments and returns a Nil or Cons.
force - Given a List node:
If it's a Nil or Cons, simply return it.
If it's a Thunk, call its function to get a Nil or Cons. Replace the thunk with that Nil or Cons, and return it.
Note: Replacing the thunk with its forced value is an important part of the definition of "lazy". If this step is skipped, the Fibonacci algorithm above will be too slow.
empty - See if a List node is Nil (after forcing it).
head (a.k.a. "car") - Get the first item of a list (or throw a fit if it's Nil).
tail (a.k.a. "cdr") - Get the elements after the head of a list (or throw a fit if it's Nil).
zipWith - Given a binary function (e.g. (+)) and two (possibly infinite) lists, apply the function to corresponding items of the lists. Example:
zipWith (+) [1,2,3] [1,1,10] == [2,3,13]
take - Given a number N and a (possibly infinite) list, grab the first N items of the list.
print - Print all the items in a list. This should work incrementally when given a long or infinite list.
fibs uses itself in its own definition. Setting up lazy recursion is a tad tricky; you'll need to do something like this:

Allocate a thunk for fibs. Leave it in a dummy state for now.
Define the thunk function, which depends on a reference to fibs.
Update the thunk with its function.
You may want to hide this plumbing by defining a function fix which calls a List-returning function with its own return value. Consider taking a short nap so this idea can set in.

Polymorphism (the ability to work with lists of any type of item) is not required, but see if you can find a way to do it that's idiomatic in your language.

Don't worry about memory management. Even languages with garbage collection have a tendency to carry around objects you'll never use again (e.g. on the call stack), so don't be surprised if your program leaks memory while traversing an infinite list.
Feel free to deviate slightly from these guidelines to accommodate the particulars of your language, or to explore alternative approaches to lazy lists.

Rules:

Pick a language you don't know well. I can't "require" this, hence the "honor-system" tag. However, voters can check your history to see what languages you've been posting in.
Don't use your language's built-in lazy list support to do everything. Post something substantial or at least interesting.

Haskell is pretty much out. That is, unless you do something like this:

data List a = IORef (ListNode a)
data ListNode a = Nil | Cons !a !(List a) | Thunk !(IO (ListNode a))
Note: Haskell's non-strict evaluation isn't off-limits, but your lazy list implementation shouldn't derive its capability directly from there. In fact, it'd be interesting to see an efficient, purely functional solution that doesn't require laziness.

Python:

Don't use itertools.
Generators are fine, but you use them, you'll have to find some way to memoize forced values.

"""

# ported from @Lowjacker solution
class Node(object):
    def __init__(self, head, tail):
        self.__head__ = head
        self.__tail__ = tail

    def force(self):
        return self

    def empty(self):
        return False

    def head(self):
        return self.__head__

    def tail(self):
        return self.__tail__

    def zip_with(self, func, other):
        def gen_func():
            if other.empty():
                return other
            return Node(func(self.head(), other.head()), self.tail().zip_with(func, other.tail()))
        return Thunk(gen_func)

    def __iter__(self):
        while not self.empty():
            yield self.head()
            self = self.tail()

    def append(self, other):
        while not self.tail().empty():
            self = self.tail()
        self.__tail__ = other

    def take(self, n):
        if n == 0:
            return NullNode()
        else:
            return Node(self.__head__, self.__tail__.take(n - 1))

    def _print(self):
        for item in self:
            print(item)

class NullNode(Node):
    def __init__(self):
        pass

    def empty(self):
        return True

    def head(self):
        raise TypeError("cannot get head of nil")

    def tail(self):
        raise TypeError("cannot get tail of nil")

    def zip_with(self, func, other):
        return self

    def append(self, other):
        raise TypeError("cannot append to nil")

    def take(self, n):
        return self

class Thunk(Node):
    def __init__(self, func):
        self.func = func

    def force(self):
        node = self.func()
        self.__class__ = node.__class__
        if not node.empty():
            self.__head__ = node.head()
            self.__tail__ = node.tail()
        return self

    def empty(self):
        return self.force().empty()

    def head(self):
        return self.force().head()

    def tail(self):
        return self.force().tail()

    def take(self, n):
        return self.force().take(n)

def main():
    fib = Node(0, Node(1, NullNode()))
    fib.append(fib.zip_with(lambda a, b: a + b, fib.tail()))
    print(list(fib.take(64)))

main()
