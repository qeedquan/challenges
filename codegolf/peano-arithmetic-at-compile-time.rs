/*

Peano numbers represent nonnegative integers as zero or successors of other Peano numbers. For example, 1 would be represented as Succ(Zero) and 3 would be Succ(Succ(Succ(Zero))).

Task
Implement the following operations on Peano numbers, at compile time:

Addition
Subtraction - You will never be required to subtract a greater number from a smaller one.
Multiplication
Division - You will never be required to divide two numbers if the result will not be an integer.
Input/Output
The input and output formats do not have to be the same, but they should be one of these:

A type constructor of kind * -> * to represent S and a type of kind * to represent Z, e.g. S<S<Z>> to represent 2 in Java or int[][] (int for 0, [] for S).
A string with a Z at the middle and 0 or more S(s and )s around it, e.g. "S(S(Z))" to represent 2.
Any other format resembling Peano numbers, where there is a value representing zero at the bottom, and another wrapper that can contain other values.
Rules
You may use type members, implicits, type constructors, whatever you want, as long as a result can be obtained at compile time.
For the purposes of this challenge, any execution phase before runtime counts as compile time.
Since answers must work at compile-time, answers must be in compiled languages. This includes languages like Python, provided you can show that the bytecode contains the result of your computation before you even run the code.
This is code-golf, so shortest code in bytes wins!
Example for just addition in Scala
sealed trait Num {
  //This is like having a method `abstract Num plus(Num n);`
  type Plus[N <: Num] <: Num
}
object Zero extends Num {
  //When we add any n to zero, it's just that n again
  type Plus[N <: Num] = N
}
final class Succ[N <: Num](n: N) extends Num {
  //In Java: `Num plus(Num x) { return new Succ(n.plus(x)) }
  type Plus[X <: Num] = Succ[N#Plus[X]]
}
Usage (Scastie):

//This is just for sugar
type +[A <: Num, B <: Num] = A#Plus[B]

type Zero = Zero.type
type Two = Succ[Succ[Zero]]
type Three = Succ[Two]
type Five = Succ[Succ[Three]]
val five: Five = null
val threePlusTwo: Three + Two = five
val notFivePlusTwo: Five + Two = five //should fail
val zeroPlusFive: Zero + Five = five
Test cases
S is used for successors and Z is used for zero.

S(S(S(Z))) + Z = S(S(S(Z)))                 | 3 + 0 = 3
S(S(Z)) + S(S(S(Z))) = S(S(S(S(S(Z)))))     | 2 + 3 = 5
S(S(S(Z))) - S(S(S(Z))) = Z                 | 3 - 3 = 0
S(S(Z)) * S(S(S(Z))) = S(S(S(S(S(S(Z))))))  | 2 * 3 = 6
S(S(S(S(Z)))) / S(S(Z)) = S(S(Z))           | 4 / 2 = 2
Z / S(S(Z)) = Z                             | 0 / 2 = 0

Some links to help you get started
Type-Level Programming in Scala (a bunch of articles, including ones about Peano arithmetic) (for Scala)
Multiplication at compile time (for Scala)
Peano arithmetic in C++ type system (for C++)
Type arithmetic (for Haskell)

*/

// ported from @corvus_192 solution
struct Zero;
struct Succ<Zero>(Vec<Zero>);

trait Add<B> {
    type R;
}

impl<B> Add<B> for Zero {
    type R = B;
}

impl<B, N: Add<B>> Add<B> for Succ<N> {
    type R = Succ<<N as Add<B>>::R>;
}

trait Sub<B> {
    type R;
}

impl<N> Sub<N> for Zero {
    type R = Zero;
}

impl<N> Sub<Zero> for Succ<N> {
    type R = Succ<N>;
}

impl<P, N: Sub<P>> Sub<Succ<P>> for Succ<N> {
    type R = <N as Sub<P>>::R;
}

trait Mul<B> {
    type R;
}

impl<B> Mul<B> for Zero {
    type R = Zero;
}

impl<B, N: Mul<B>> Mul<B> for Succ<N>
where
    <N as Mul<B>>::R: Add<B>,
{
    type R = <<N as Mul<B>>::R as Add<B>>::R;
}

trait Div<B> {
    type R;
}

impl<P> Div<Succ<P>> for Zero {
    type R = Zero;
}

impl<P, N: Sub<P>> Div<Succ<P>> for Succ<N>
where
    <N as Sub<P>>::R: Div<Succ<P>>,
{
    type R = Succ<<<Succ<N> as Sub<Succ<P>>>::R as Div<Succ<P>>>::R>;
}

type _0 = Zero;
type _1 = Succ<_0>;
type _2 = Succ<_1>;
type _3 = Succ<_2>;
type _4 = Succ<_3>;
type _5 = Succ<_4>;
type _6 = Succ<_5>;
type _7 = Succ<_6>;

// source: https://docs.rs/static_assertions/1.1.0/static_assertions/macro.assert_type_eq_all.html
macro_rules! assert_type_eq_all {
    ($x:ty, $($xs:ty),+ $(,)*) => {
        const _: fn() = || { $({
            trait TypeEq {
                type This: ?Sized;
            }

            impl<T: ?Sized> TypeEq for T {
                type This = Self;
            }

            fn assert_type_eq_all<T, U>()
            where
                T: ?Sized + TypeEq<This = U>,
                U: ?Sized,
            {}

            assert_type_eq_all::<$x, $xs>();
        })+ };
    };
}

fn main() {
    assert_type_eq_all!(_0, _0);
    assert_type_eq_all!(_4, _4);
    assert_type_eq_all!(<_3 as Add<_0>>::R, _3);
    assert_type_eq_all!(<_2 as Add<_3>>::R, _5);
    assert_type_eq_all!(<_4 as Add<_3>>::R, _7);
    assert_type_eq_all!(<_3 as Sub<_3>>::R, _0);
    assert_type_eq_all!(<_2 as Mul<_3>>::R, _6);
    assert_type_eq_all!(<_4 as Div<_2>>::R, _2);
    assert_type_eq_all!(<_0 as Div<_2>>::R, _0);
}
