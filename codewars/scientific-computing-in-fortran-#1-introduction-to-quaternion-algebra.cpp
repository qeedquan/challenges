/*

NOTE: All of the instructions necessary for solving the Kata are contained under the heading "Task" - all other sections are purely optional.

About this Kata Series
This Kata Series aims to explore the world of advanced mathematics and numerical algorithms through Fortran which is regarded as the world's first widely used high-level programming language and is especially suited for numerical algorithms and scientific computation.

A Brief History of Fortran
Content adapted from https://en.wikipedia.org/wiki/Fortran

Fortran, short for "Formula Transformation" and formerly known as FORTRAN, was originally conceived in 1953 and finally realized in 1957. It is generally considered the world's first ever widely used high-level programming language. The conception of Fortran lead to the birth of multiple major and novel disciplines in the field of Computer Science, most notably compiler theory. It also set the example for and served as the cornerstone of countless modern programming languages, including but not limited to arguably one of the most successful and influential programming languages of all time, C.

One of the major goals of Fortran when it was initially conceived was to make the input of complex mathematical formulae much easier, much more straightforward and in a human-readable way. As a result, Fortran was highly geared towards numeric and scientific computation; therefore, it was highly revered within the scientific and engineering community. In fact, for decades, Fortran was the go-to programming language for science and engineering students in colleges and universities worldwide, insomuch that "physics and astronomy students simply had to learn FORTRAN". This trend seems to have subsided in recent years but Fortran will always occupy a unique place in the hearts of countless programmers.

Prerequisites
Mathematics
There are no hard prerequisites apart from a basic command of high school mathematics but it would certainly help if you have at least heard of complex numbers and know some of its basic properties / operations.

Fortran Programming
In order to complete this Kata successfully, you will be required to have a basic command of Fortran - how to declare/define variables, procedures, conditional statements and looping statements etc. Fortunately, if you happen to have absolutely no background knowledge of Fortran, you should be ready for this Kata after a good look at some of the Fortran Kumite available on CW.

Preloaded
A module Quaternions is included for you which defines the following derived data types for the purposes of this Kata:

type Quaternion
  ! A quaternion of the form a + bi + cj + dk
  real(8) :: a, b, c, d
end type Quaternion
Task
Content adapted from https://en.wikipedia.org/wiki/Quaternion

Quaternions are a number system invented by Hamilton that extends the complex numbers. It consists of one real component and three orthogonal imaginary components, namely i, j and k. This system preceded vector analysis and was widely used to describe translations, transformations and rotations in three-dimensional space before vector analysis took over (because it was considered simpler and cleaner conceptually). Nevertheless, it still remains an interesting topic in mathematics and still finds its applications in computer graphics since it has the ability to describe rotations in 3D space using only 4 components instead of 9 (as in a 3 by 3 rotation matrix) and does not encounter the issue of gimbal lock in any situation provided that it is implemented correctly.

Cayley-Dickson Construction
Suggested reading: Cayley-Dickson construction

Define a function cdinit which constructs a quaternion (a + bi) + (c + di)j = a + bi + cj + dk from a pair of complex numbers a + bi and c + di (in order) in the form of two arguments, both double-precision complex numbers (i.e. complex(8)).

Extracting Real and Imaginary Components
To mirror the complex number datatype intrinsic in Fortran and for convenience/readability of our code, overload the realpart and imagpart functions to work with quaternions:

The realpart function should accept a quaternion as its one and only argument and return the real component a of our quaternion as a double precision real number.
The imagpart function should:
Accept exactly one quaternion a + bi + cj + dk and return a quaternion of the form bi + cj + dk
Accept one quaternion a + bi + cj + dk followed by an integer of the default type n which can be either 1, 2 or 3 and returns the nth imaginary component of the quaternion as a double precision real number. For example, imagpart(Quaternion(1.0_8, 2.0_8, 3.0_8, 4.0_8), 2) should evaluate to 3.0_8 (the coefficient of the "j" component which can be said to be the second imaginary component of our quaternion). You may assume all inputs are valid.
NOTE: Please hide your implementation details of overloading procedure(s)/operator(s) from the test cases if possible; otherwise, I won't be responsible for any potential identifier clashes in the Sample/Submit tests ;)

Quaternion Addition
Overload the + operator to work with quaternions:

The binary + operator should:
Accept two quaternions and add them together. Remember that quaternion addition is performed component-wise, e.g. (a + bi + cj + dk) + (f + gi + hj + lk) = (a + f) + (b + g)i + (c + h)j + (d + l)k (where a, b, c, d, f, g, h, l are real constants)
"Type-promote" double-precision real and complex numbers (i.e. real(8), complex(8)) to quaternions when one of the operands is a real/complex number (and the other a quaternion). For example, Quaternion(1.0_8, 2.0_8, 3.0_8, 4.0_8) + 5.0_8 should work. Remember that real/complex numbers are a subset of the quaternions so any components that they do not possess are simply considered to be 0, e.g. a + bi = a + bi + 0j + 0k.
The unary + operator should simply return the operand provided, e.g. if q is a quaternion then +q should evaluate to q.
Quaternion Subtraction
Overload the - operator to allow for quaternion subtraction, e.g. p - q (where p, q are quaternions) should evaluate the difference between p and q. If one of the operands is a double-precision real/complex number, "type-promote" it to a quaternion before performing the subtraction like you did with +. As should be obvious, quaternion subtraction is also performed component-wise. Also overload the unary - operator to return the additive inverse of a quaternion, e.g. -(a + bi + cj + dk) = -a - bi - cj - dk.

Hamilton Product
Overload * like you did for + and - (as a binary operator only) to work with quaternions, "type-promoting" double-precision real/complex numbers to quaternions when necessary. The Hamilton product can be computed by applying the distributive law then simplified by manipulating the fundamental quaternion formula i^2 = j^2 = k^2 = ijk = -1 into the form a + bi + cj + dk.

Hint: As an example, to simplify something such as an ij compound component into a simple component such as k, you can manipulate the fundamental formula for quaternions by noting that k^2 = -1 and ijk = -1, note that quaternion multiplication is associative so ijk can be interpreted as (ij)k, and then note that k^2 = k * k by definition so it follows that k = ij.

Beware! The Hamilton product is NOT commutative so if you try something like p * q = q * p at any stage of setting up your equations, you will probably fail most, if not all, of the tests.

Conjugation
Similar to complex numbers, the conjugate of a quaternion q = a + bi + cj + dk is defined as q* = a - bi - cj - dk. Define a new unary operator .conj. for computing the conjugate of a quaternion.

N.B. The * operator cannot be overloaded to act as a unary operator in Fortran; hence, we must define a new operator.

Norm
Again, similar to complex numbers (and vectors), the norm / absolute value of a quaternion is defined as the sum of squares of the coefficients of each component, squarerooted. Overload the abs intrinsic function to work with quaternions for this purpose. The result should be returned as a double-precision real number.

Thinking Task: Quaternion Division?
Congratulations, you have implemented all that is required in this Kata. However, if you are really interested in this subject, you can think of the following question: is it possible to define a division operation on quaternions? If so, how would it be defined? Would it be a good idea to overload the / operator for quaternion division and what are the potential advantages/drawbacks of doing so?

Coming Up
The next Kata in this Series will also be about quaternions - however, the focus will significantly shift away from Fortran programming and language features towards advanced quaternion algebra, how it serves as a generalization of complex numbers in multiple aspects and how related formulae and quaternion behavior can be manipulated to derive formulae for some rather interesting functions (in the context of quaternions). If you are really into math then this next Kata is for you! Stay tuned :D

Kata in this Series
Scientific Computing in Fortran #1 - Introduction to Quaternion Algebra
Scientific Computing in Fortran #2 - Quaternionic Transcendental Functions
Scientific Computing in Fortran #3 - Discrete Fourier Transform
Scientific Computing in Fortran #4 - Fast Fourier Transform

*/

#include <cassert>
#include <cstdio>
#include <cmath>

/*

https://en.wikipedia.org/wiki/Quaternion
https://math.stackexchange.com/questions/1499095/how-to-calculate-sin-cos-tan-of-a-quaternion
https://math.stackexchange.com/questions/3788924/trigonometric-functions-of-quaternions

*/

struct Vec3;
struct Quat;

double dot(Vec3, Vec3);
Vec3 cross(Vec3, Vec3);

Quat qinv(Quat);

struct Vec3
{
	double x, y, z;

	Vec3 operator-()
	{
		return { -x, -y, -z };
	}

	Vec3 operator+(Vec3 v)
	{
		return { x + v.x, y + v.y, z + v.z };
	}

	Vec3 operator-(Vec3 v)
	{
		return { x - v.x, y - v.y, z - v.z };
	}

	Vec3 operator*(double s)
	{
		return { x * s, y * s, z * s };
	}

	Vec3 operator/(double s)
	{
		return { x / s, y / s, z / s };
	}
};

struct Quat
{
	double s;
	Vec3 v;

	Quat operator-()
	{
		return Quat{ -s, -v };
	}

	Quat operator+(Quat q)
	{
		return { s + q.s, v + q.v };
	}

	Quat operator-(Quat q)
	{
		return { s - q.s, v - q.v };
	}

	Quat operator*(Quat q)
	{
		return {
			s * q.s - dot(v, q.v),
			(q.v * s) + (v * q.s) + cross(v, q.v)
		};
	}

	Quat operator/(Quat q)
	{
		return *this * qinv(q);
	}

	Quat operator*(double x)
	{
		return { s * x, v * x };
	}

	Quat operator/(double x)
	{
		return { s / x, v / x };
	}
};

double dot(Vec3 a, Vec3 b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vec3 cross(Vec3 a, Vec3 b)
{
	return Vec3{
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
	};
}

double length(Vec3 v)
{
	return sqrt(dot(v, v));
}

Quat qconj(Quat q)
{
	return Quat{ q.s, -q.v };
}

Quat qinv(Quat q)
{
	auto d = (q.s * q.s) + dot(q.v, q.v);
	return qconj(q) / d;
}

Quat qsin(Quat q)
{
	auto l = length(q.v);
	auto s = sin(q.s) * cosh(l);
	auto v = (q.v / l) * sinh(l) * cos(q.s);
	return Quat{ s, v };
}

Quat qcos(Quat q)
{
	auto l = length(q.v);
	auto s = cos(q.s) * cosh(l);
	auto v = (q.v / l) * sin(q.s) * sinh(l);
	return Quat{ s, -v };
}

Quat qtan(Quat q)
{
	return qsin(q) / qcos(q);
}

Quat qexp(Quat q)
{
	auto l = length(q.v);
	auto e = exp(q.s);
	auto s = e * cos(l);
	auto v = (q.v / l) * sin(l) * e;
	return { s, v };
}

Quat qsinh(Quat q)
{
	return (qexp(q) - qexp(-q)) / 2;
}

Quat qcosh(Quat q)
{
	return (qexp(q) + qexp(-q)) / 2;
}

Quat qtanh(Quat q)
{
	return qsinh(q) / qcosh(q);
}

bool allclose(Quat q1, Quat q2, double eps = 1e-12)
{
	return fabs(q1.s - q2.s) < eps &&
		   fabs(q2.v.x - q2.v.x) < eps &&
		   fabs(q2.v.y - q2.v.y) < eps &&
		   fabs(q2.v.z - q2.v.z) < eps;
}

void test_arithmetic()
{
	auto q1 = Quat{ 1, { 2, 3, 4 } };
	auto q2 = q1;
	assert(allclose(q1, q2));

	q1 = Quat{ 1, { 2, 3, 4 } };
	q2 = Quat{ 5, { 6, 7, 8 } };
	auto qa = Quat{ 6, { 8, 10, 12 } };
	auto qm = Quat{ -60, { 12, 30, 24 } };
	auto qmr = Quat{ -60, { 20, 14, 32 } };
	auto qd = Quat{ 0.402299, { 0.045977, 0, 0.091954 } };
	auto qc1 = Quat{ 1, { -2, -3, -4 } };
	assert(allclose(q1 + q2, qa));
	assert(allclose(q1 * q2, qm));
	assert(allclose(q2 * q1, qmr));
	assert(allclose(q1 / q2, qd, 1e-6));
	assert(allclose(qconj(q1), qc1));
}

int main()
{
	test_arithmetic();
	return 0;
}
