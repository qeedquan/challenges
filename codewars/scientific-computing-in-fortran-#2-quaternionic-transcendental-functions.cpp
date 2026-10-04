/*

NOTE: All of the instructions necessary for solving the Kata are contained under the heading "Task" - all other sections are purely optional.

About this Kata Series
This Kata Series aims to explore the world of advanced mathematics and numerical algorithms through Fortran which is regarded as the world's first widely used high-level programming language and is especially suited for numerical algorithms and scientific computation.

Prerequisites
Mathematics
You should have a thorough understanding of complex numbers and their properties. Specifically, given any complex number z = x + iy, you should be able to compute its exponential, (natural) logarithm, sine and cosine etc. by hand through (repeated or otherwise) application of the properties of complex numbers and/or related equations/results such as de Moivre's theorem. Without this background knowledge, you may find it exceedingly difficult to complete this Kata as this Kata requires you to extend your knowledge of complex numbers into the realm of quaternions.

Fortran Programming
You should at least have a basic command of Fortran, e.g. how to perform simple arithmetic and perhaps simple conditiona and/or looping constructs. It would also be helpful to know some of the more advanced features of Fortran such as procedure overloading and operator overloading though that is not strictly required in this Kata.

If you haven't programmed in Fortran before, here is a list of Kumite to get you started.

Preloaded
Preloaded is a module Quaternions which defines the Quaternion derived data type as follows:

type Quaternion
  real(8) :: a, b, c, d ! representing a quaternion q = a + bi + cj + dk
end type Quaternion
Task
Five mathematical functions exp, sinh, cosh, sin and cos are overloaded to work with quaternions through the internally defined functions qexp, qsinh, qcosh, qsin and qcos respectively in the QuaternionUtilities module. Your task is to replace the dummy implementations in each of these 5 functions (marked with TODO in the initial solution) with working implementations that compute the correct results as quaternions.

The formula for calculating the quaternionic exponential function is provided on Wikipedia and those of hyperbolic trig functions can be easily derived from their exponential definitions. However, there is no universally accepted definition for the ordinary trig functions in the quaternion realm (according to @Voile) so note that the reference implementation your qsin and qcos functions will be tested against is the Boost C++ Library.

To give you an insight as to how the quaternionic trig functions have been defined in their library, they most likely used the exponential definitions for said functions in the complex plane then generalized them in a manner consistent with the generalized de Moivre's theorem.

You may copy and paste your solution (if any) from the previous Kata in this Series to aid in completing this Kata.

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

void test_transcendental()
{
	auto q1 = Quat{ 1, { 2, 3, 4 } };
	auto q2 = Quat{ -3.5, { 2.1, 0.3, 4.7 } };
	auto q3 = Quat{ 13.1, { -4.4, 10.84, -2.33 } };

	auto e1 = Quat{ 1.693922723683299, { -0.789559624541559, -1.184339436812338, -1.579119249083118 } };
	auto e2 = Quat{ 0.012975808540245, { -0.011104618367121, -0.001586374052446, -0.024853193488318 } };
	auto e3 = Quat{ 392865.258411247166805, { 107363.244218748179264, -264503.992575279611629, 56853.717961291651591 } };

	auto sh1 = Quat{ 0.732337606046343, { -0.448207449980542, -0.672311174970813, -0.896414899961084 } };
	auto sh2 = Quat{ -7.108363047055897, { -6.094398665722635, -0.870628380817519, -13.639844632807804 } };
	auto sh3 = Quat{ 196432.629204801924061, { 53681.622109598640236, -132251.996288193011424, 28426.858980764733133 } };

	auto ch1 = Quat{ 0.961585117636957, { -0.341352174561017, -0.512028261841525, -0.682704349122033 } };
	auto ch2 = Quat{ 7.121338855596142, { 6.083294047355515, 0.869042006765073, 13.614991439319486 } };
	auto ch3 = Quat{ 196432.629206445242744, { 53681.622109149539028, -132251.996287086600205, 28426.858980526918458 } };

	auto s1 = Quat{ 91.783715784034655, { 21.886486853029176, 32.829730279543767, 43.772973706058352 } };
	auto s2 = Quat{ 30.442766629586167, { -33.095144890631275, -4.727877841518753, -74.070086183793805 } };
	auto s3 = Quat{ 38545.940527353355719, { -24065.491810278745106, 59288.620732595809386, -12743.771799533969897 } };

	auto c1 = Quat{ 58.933646167943941, { -34.086183690465596, -51.129275535698397, -68.172367380931192 } };
	auto c2 = Quat{ -81.270511642403321, { -12.396966034998560, -1.770995147856937, -27.745590649758679 } };
	auto c3 = Quat{ 65243.330424373998540, { 14217.959292494444526, -35027.881529690857860, 7529.055716252740240 } };

	assert(allclose(qexp(q1), e1));
	assert(allclose(qexp(q2), e2));
	assert(allclose(qexp(q3), e3));

	assert(allclose(qsinh(q1), sh1));
	assert(allclose(qsinh(q2), sh2));
	assert(allclose(qsinh(q3), sh3));

	assert(allclose(qcosh(q1), ch1));
	assert(allclose(qcosh(q2), ch2));
	assert(allclose(qcosh(q3), ch3));

	assert(allclose(qsin(q1), s1));
	assert(allclose(qsin(q2), s2));
	assert(allclose(qsin(q3), s3));

	assert(allclose(qcos(q1), c1));
	assert(allclose(qcos(q2), c2));
	assert(allclose(qcos(q3), c3));
}

int main()
{
	test_transcendental();
	return 0;
}
