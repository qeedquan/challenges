/*

An interval [a,b] is an ordered pair of values such that a≤b.
This is a reasonably straight-forward class that you can implement.
The constructor should take two arguments and store these two values.

class Interval;

class Interval {
	public:
		// Constructor
		Interval( double a, double b );
		// Copy constructor
		Interval( Interval const &copy );

		// Member functions
		double lhs() const;
		double rhs() const;
		std::string to_string() const;

	private:
		double left;
		double right;
};

std::string Interval::to_string() const {
	std::string return_value{"["};
	return_value += std::to_string( left );
	return_value += ",";
	return_value += std::to_string( right );
	return_value += "]";

	return return_value;
}
The member functions lhs() and rhs() return the left- and right-hand end-points of the interval.

Design questions
We will look at two simple design questions.

A single-argument constructor?
Should you provide a constructor that takes a single argument a and constructs the interval [a,a]?

While it may seem easy enough to provide such a constructor, the question is, does this really make any sense?
Most of the time, if you are using interval arithmetic, you do not intend for an interval to be a single point.
This is likely a logical error, so if a trivial interval is required, it is better to require the user to explicitly construct such an interval using Interval( a, a ).

How do we deal with b<a?
You have two options if the arguments to the constructor are not in order:

Assume the user meant to construct the interval [b,a], or
throw a std::invalid_argument exception.
It may seem friendlier to make an assumption that the user meant to construct the interval [b,a];
however, isn't this more likely a sign that the user made a logical error?
By implicitly assuming the user meant something when it would have been trivial for the user to check the arguments may actually hide either a design or implementation error.

Note: Allowing for what should be invalid arguments may make life more difficult for a novice user,
who may benefit from not having to check the order of the arguments or deal with exceptions;
however, this is more likely going to accidentally hide issues with more experienced developers.

Questions and practice:
1. Why does this class not require a destructor?

2. An alternative to always throwing an exception if the arguments are out of order is to allow a third argument bool swap_if_necessary that has a default value of false.
By default, an exception is thrown; however, if the user explicitly provides a third argument true,
the constructor will swap the arguments if necessary and create the interval [b,a].

Is this a reasonable approach?

*/

package main

import "fmt"

func main() {
	fmt.Println(NewInterval(1, 20))
}

type Interval struct {
	left, right float64
}

func NewInterval(left, right float64) Interval {
	if right < left {
		panic("invalid argument")
	}
	return Interval{left, right}
}

func (i Interval) String() string {
	return fmt.Sprintf("[%v, %v]", i.left, i.right)
}
