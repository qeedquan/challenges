/*

There are exactly eight ways to map a square onto itself by rotation or reflection. We can take its mirror image (reflection in horizontal, vertical, or either of two 45-degree diagonal lines); rotate it (by 90 degrees clockwise, 90 degrees anti-clockwise, or 180 degrees); or just leave it alone.

https://www.stat.auckland.ac.nz/~geoff/codewars/dihedral4.png

These eight transformations together comprise the dihedral group Dih(4).

In this kata we're going to write a class Dih4 that represents this collection of rotations and reflections. An object (instance) of this class will have one of eight possible values, corresponding to the eight transformations.

The Dih4 class will need to include at least the following features:

Names or constants for the possible values:

IDENTITY
ROTATE_90_ANTICLOCKWISE
ROTATE_180
ROTATE_90_CLOCKWISE
REFLECT_VERTICAL
REFLECT_FORWARD_DIAGONAL
REFLECT_HORIZONTAL
REFLECT_REVERSE_DIAGONAL
(these are in the same order as in the picture above).

A function then() that works out the effect of performing transformations successively. For example, if r is the 90-degree clockwise rotation and f is the reflection with vertical mirror line, r.then(f) should equal the reflection with reverse-diagonal mirror line.

A function inv() that gives the inverse (opposite) of a transformation. For example, if r is the 90-degree clockwise rotation, then r.inv() should equal the 90-degree anticlockwise rotation.

Functions is_rotation() and is_reflection() that test whether a transformation is a rotation or a reflection. (The identity transformation is considered to be a rotation (by 0 degrees) but not a reflection.)

Tests for equality and inequality: an equals() method (Java) or == and != operators (C++).

See the example tests for more examples of how the syntax of Dih4 objects should go.

Note to C++ codewarriors: some of the test cases use const Dih4 objects -- plan accordingly.

*/

#include <cassert>
#include <iostream>

using namespace std;

struct Dih4
{
	enum Value
	{
		IDENTITY,
		ROTATE_90_ANTICLOCKWISE,
		ROTATE_180,
		ROTATE_90_CLOCKWISE,
		REFLECT_VERTICAL,
		REFLECT_FORWARD_DIAGONAL,
		REFLECT_HORIZONTAL,
		REFLECT_REVERSE_DIAGONAL,
		MAX_VALUE,
	};

	Value value;

	Dih4(Value value = IDENTITY)
		: value(value)
	{
	}

	bool operator==(Dih4 rhs)
	{
		return value == rhs.value;
	}

	bool is_rotation()
	{
		switch (value)
		{
		case IDENTITY:
		case ROTATE_90_ANTICLOCKWISE:
		case ROTATE_180:
		case ROTATE_90_CLOCKWISE:
			return true;
		default:
			return false;
		}
	}

	bool is_reflection()
	{
		switch (value)
		{
		case REFLECT_VERTICAL:
		case REFLECT_FORWARD_DIAGONAL:
		case REFLECT_HORIZONTAL:
		case REFLECT_REVERSE_DIAGONAL:
			return true;
		default:
			return false;
		}
	}

	Dih4 inv()
	{
		for (auto index = 0; index < MAX_VALUE; index++)
		{
			if (CAYLEY[value][index] == IDENTITY)
				return Dih4((Value) index);
		}
		return Dih4(value);
	}

	Dih4 then(Value next)
	{
		return Dih4(CAYLEY[value][next]);
	}

	Dih4 then(Dih4 next)
	{
		return Dih4(CAYLEY[value][next.value]);
	}

private:
	// https://math.libretexts.org/Courses/Mount_Royal_University/Abstract_Algebra_I/Chapter_3%3A_Permutation_Groups/3.3%3A_Dihedral_Groups_(Group_of_Symmetries)
	static constexpr Value R0 = IDENTITY;
	static constexpr Value R90 = ROTATE_90_ANTICLOCKWISE;
	static constexpr Value R180 = ROTATE_180;
	static constexpr Value R270 = ROTATE_90_CLOCKWISE;
	static constexpr Value H = REFLECT_HORIZONTAL;
	static constexpr Value V = REFLECT_VERTICAL;
	static constexpr Value D = REFLECT_REVERSE_DIAGONAL;
	static constexpr Value P = REFLECT_FORWARD_DIAGONAL;

	static constexpr Value CAYLEY[MAX_VALUE][MAX_VALUE] = {
		{ R0, R90, R180, R270, H, V, D, P },
		{ R90, R180, R270, R0, P, D, H, V },
		{ R180, R270, R0, R90, V, H, P, D },
		{ R270, R0, R90, R180, D, P, V, H },
		{ H, D, V, P, R0, R180, R90, R270 },
		{ V, P, H, D, R180, R0, R270, R90 },
		{ D, V, P, H, R270, R90, R0, R180 },
		{ P, H, D, V, R90, R270, R180, R0 },
	};
};

ostream &operator<<(ostream &os, Dih4 dih4)
{
	const char *str = "(unknown Dih4 value)";
	switch (dih4.value)
	{
	case Dih4::IDENTITY:
		str = "(identity transformation)";
		break;
	case Dih4::ROTATE_90_ANTICLOCKWISE:
		str = "(rotation 90 degrees anticlockwise)";
		break;
	case Dih4::ROTATE_180:
		str = "(rotation 180 degrees)";
		break;
	case Dih4::ROTATE_90_CLOCKWISE:
		str = "(rotation 90 degrees clockwise)";
		break;
	case Dih4::REFLECT_VERTICAL:
		str = "(reflection in vertical line)";
		break;
	case Dih4::REFLECT_FORWARD_DIAGONAL:
		str = "(reflection in forward-diagonal line)";
		break;
	case Dih4::REFLECT_HORIZONTAL:
		str = "(reflection in horizontal line)";
		break;
	case Dih4::REFLECT_REVERSE_DIAGONAL:
		str = "(reflection in reverse-diagonal line)";
		break;
	default:
		break;
	}
	return os << str;
}

int main()
{
	auto d = Dih4(Dih4::ROTATE_180);
	assert(d.is_rotation());

	d = Dih4(Dih4::REFLECT_VERTICAL);
	assert(d.is_reflection());

	auto r = Dih4(Dih4::ROTATE_90_CLOCKWISE);
	auto f = Dih4(Dih4::ROTATE_90_ANTICLOCKWISE);
	assert(r.inv() == f);

	r = Dih4(Dih4::REFLECT_HORIZONTAL);
	f = Dih4(Dih4::REFLECT_HORIZONTAL);
	assert(r.inv() == f);

	r = Dih4(Dih4::ROTATE_90_CLOCKWISE).then(Dih4::REFLECT_VERTICAL);
	f = Dih4(Dih4::REFLECT_REVERSE_DIAGONAL);
	assert(r == f);

	r = Dih4(Dih4::ROTATE_90_ANTICLOCKWISE);
	f = Dih4(Dih4::REFLECT_HORIZONTAL);
	assert(r.then(r).then(r) == r.inv());
	assert(r.inv().then(f) == f.then(r));

	r = Dih4(Dih4::ROTATE_90_CLOCKWISE);
	f = Dih4(Dih4::ROTATE_90_CLOCKWISE);
	assert(r == f);
	f = Dih4(Dih4::ROTATE_90_ANTICLOCKWISE);
	assert(r != f);

	r = Dih4(Dih4::ROTATE_90_CLOCKWISE);
	f = Dih4(Dih4::ROTATE_180).then(Dih4::ROTATE_90_ANTICLOCKWISE);
	assert(r == f);

	return 0;
}
