/*

What's assignable to what?
In this challenge you will be given two types, A and B and determine if A is assignable to B, B is assignable to A, or neither.

The Type System
(I will use t to represent any type)

Basic Types
Basic types are represented by a single capital letter, such as X. They are basically classes.

X is assignable to Y if Y is either the same as, or a parent class of X.
Intersection Types
Intersection types are represented by intersect<X, Y>, and can have any number of types between the <'s (e.g. intersect<X, Y, Z, D, E>).

t is assignable to intersect<X1, X2... Xn> if t is assignable to all X.
intersect<X1, X2... Xn> is assignable to t if any X is assignable to t.
Union Types
Union types are represented by union<X, Y> and can have any number of types between the <'s (e.g. union<X, Y, Z, D, E>).

t is assignable to union<X1, X2... Xn> if t is assignable to any X.
union<X1, X2... Xn> is assignable to t if all X are assignable to t.
Input
You will receive as input:

The class hierarchy. You may choose the method of input for the class hierarchy. You can input a representation of a tree, or each type with a list of its parents, or anything else that accurately represents the class hierarchy.
Two types (input is flexible, as long as the notation is consistent you may receive these types however you like).
Output
You will output one of three consistent and distinct values, call them X, Y, and Z. Given two types A and B, output X if A is assignable to B, output Y if B is assignable to A and output Z otherwise (If A is assignable to B and B is assignable to A, you may output X, Y, both, or a fourth value).

Test Cases
Format:

# of types
[type, parents...]
[type, parents...]
Type a
Type b
2
[A,B]
[B]
A
B
--
A is assignable to B


3
[A,B,C]
[B,C]
[C]
intersect<A,C>
A
--
A is assignable to intersect<A,C>


3
[A,B,C]
[B,C]
[C]
union<A,C>
A
--
A is assignable to union<A,C>


3
[A,B,C]
[B,C]
[C]
intersect<B,C>
A
--
A is assignable to intersect<B,C>


3
[A,B,C]
[X,Y,Z]
[T,U,V]
intersect<union<A,T,X>,intersect<A,B>,Y>
intersect<T,C,X>
--
intersect<T,C,X> and intersect<union<A,T,X>,intersect<A,B>,Y> are not assignable to each other    

1
[A]
A
A
--
A is assignable to A


3
[A,B,C]
[X,Y,Z]
[T,U,V]
intersect<A,intersect<A,B>,Y>
intersect<T,C,X>
--
intersect<T,C,X> and intersect<A,intersect<A,B>,Y> are not assignable to each other


2
[A]
[B]
A
B
--
B and A are not assignable to each other

3
[A,B,C]
[X,Y,Z]
[T,U,V]
intersect<union<A,X>,intersect<A,B>,Y>
intersect<T,C,X>
--
intersect<T,C,X> and intersect<union<A,X>,intersect<A,B>,Y> are not assignable to each other
Here is a link to a working ungolfed Java solution you can use for testing (it takes input in the same way as the test cases)

This is code-golf, so least bytes in each language wins for that language!

*/

#include <iostream>
#include <type_traits>

using namespace std;

/*

Ported from @rahnema1 solution

A variable template f that accepts as input some types and intersection i<...> or union u<...> of them and
returns -1 if A is assignable to B and 1 if B is assignable to A and 0 otherwise.

*/

template <class... T>
class Intersect;

template <class... T>
class Union;

template <class A, class B>
struct is_assignable_to : disjunction<is_base_of<A, B>, is_same<A, B> >
{
};

template <class a, class... A>
struct is_assignable_to<a, Union<A...> > : disjunction<is_assignable_to<a, A>...>
{
};

template <class a, class... A>
struct is_assignable_to<a, Intersect<A...> > : conjunction<is_assignable_to<a, A>...>
{
};

template <class a, class... A>
struct is_assignable_to<Union<A...>, a> : conjunction<is_assignable_to<A, a>...>
{
};

template <class a, class... A>
struct is_assignable_to<Intersect<A...>, a> : disjunction<is_assignable_to<A, a>...>
{
};

template <class... A, class... B>
struct is_assignable_to<Intersect<A...>, Intersect<B...> > : disjunction<is_assignable_to<A, Intersect<B...> >...>
{
};

template <class... A, class... B>
struct is_assignable_to<Union<A...>, Union<B...> > : conjunction<is_assignable_to<A, Union<B...> >...>
{
};

template <class... A, class... B>
struct is_assignable_to<Intersect<A...>, Union<B...> > : disjunction<is_assignable_to<A, Union<B...> >...>
{
};

template <class... A, class... B>
struct is_assignable_to<Union<A...>, Intersect<B...> > : conjunction<is_assignable_to<A, Intersect<B...> >...>
{
};

template <class A, class B>
int f = is_assignable_to<A, B>::value ? -1 : is_assignable_to<B, A>::value ? 1 : 0;

int main()
{
	struct B
	{
	};
	struct C
	{
	};
	struct Y
	{
	};
	struct Z
	{
	};
	struct U
	{
	};
	struct V
	{
	};
	struct A : B, C
	{
	};
	struct X : Y, Z
	{
	};
	struct T : U, V
	{
	};

	cout << f<Intersect<A, Intersect<A, B>, Y>, Union<T, C, X> > << endl;

	return 0;
}
