/*

--- Day 24: Never Tell Me The Odds ---
It seems like something is going wrong with the snow-making process. Instead of forming snow, the water that's been absorbed into the air seems to be forming hail!

Maybe there's something you can do to break up the hailstones?

Due to strong, probably-magical winds, the hailstones are all flying through the air in perfectly linear trajectories. You make a note of each hailstone's position and velocity (your puzzle input). For example:

19, 13, 30 @ -2,  1, -2
18, 19, 22 @ -1, -1, -2
20, 25, 34 @ -2, -2, -4
12, 31, 28 @ -1, -2, -1
20, 19, 15 @  1, -5, -3
Each line of text corresponds to the position and velocity of a single hailstone. The positions indicate where the hailstones are right now (at time 0). The velocities are constant and indicate exactly how far each hailstone will move in one nanosecond.

Each line of text uses the format px py pz @ vx vy vz. For instance, the hailstone specified by 20, 19, 15 @ 1, -5, -3 has initial X position 20, Y position 19, Z position 15, X velocity 1, Y velocity -5, and Z velocity -3. After one nanosecond, the hailstone would be at 21, 14, 12.

Perhaps you won't have to do anything. How likely are the hailstones to collide with each other and smash into tiny ice crystals?

To estimate this, consider only the X and Y axes; ignore the Z axis. Looking forward in time, how many of the hailstones' paths will intersect within a test area? (The hailstones themselves don't have to collide, just test for intersections between the paths they will trace.)

In this example, look for intersections that happen with an X and Y position each at least 7 and at most 27; in your actual data, you'll need to check a much larger test area. Comparing all pairs of hailstones' future paths produces the following results:

Hailstone A: 19, 13, 30 @ -2, 1, -2
Hailstone B: 18, 19, 22 @ -1, -1, -2
Hailstones' paths will cross inside the test area (at x=14.333, y=15.333).

Hailstone A: 19, 13, 30 @ -2, 1, -2
Hailstone B: 20, 25, 34 @ -2, -2, -4
Hailstones' paths will cross inside the test area (at x=11.667, y=16.667).

Hailstone A: 19, 13, 30 @ -2, 1, -2
Hailstone B: 12, 31, 28 @ -1, -2, -1
Hailstones' paths will cross outside the test area (at x=6.2, y=19.4).

Hailstone A: 19, 13, 30 @ -2, 1, -2
Hailstone B: 20, 19, 15 @ 1, -5, -3
Hailstones' paths crossed in the past for hailstone A.

Hailstone A: 18, 19, 22 @ -1, -1, -2
Hailstone B: 20, 25, 34 @ -2, -2, -4
Hailstones' paths are parallel; they never intersect.

Hailstone A: 18, 19, 22 @ -1, -1, -2
Hailstone B: 12, 31, 28 @ -1, -2, -1
Hailstones' paths will cross outside the test area (at x=-6, y=-5).

Hailstone A: 18, 19, 22 @ -1, -1, -2
Hailstone B: 20, 19, 15 @ 1, -5, -3
Hailstones' paths crossed in the past for both hailstones.

Hailstone A: 20, 25, 34 @ -2, -2, -4
Hailstone B: 12, 31, 28 @ -1, -2, -1
Hailstones' paths will cross outside the test area (at x=-2, y=3).

Hailstone A: 20, 25, 34 @ -2, -2, -4
Hailstone B: 20, 19, 15 @ 1, -5, -3
Hailstones' paths crossed in the past for hailstone B.

Hailstone A: 12, 31, 28 @ -1, -2, -1
Hailstone B: 20, 19, 15 @ 1, -5, -3
Hailstones' paths crossed in the past for both hailstones.
So, in this example, 2 hailstones' future paths cross inside the boundaries of the test area.

However, you'll need to search a much larger test area if you want to see if any hailstones might collide. Look for intersections that happen with an X and Y position each at least 200000000000000 and at most 400000000000000. Disregard the Z axis entirely.

Considering only the X and Y axes, check all pairs of hailstones' future paths for intersections. How many of these intersections occur within the test area?

--- Part Two ---
Upon further analysis, it doesn't seem like any hailstones will naturally collide. It's up to you to fix that!

You find a rock on the ground nearby. While it seems extremely unlikely, if you throw it just right, you should be able to hit every hailstone in a single throw!

You can use the probably-magical winds to reach any integer position you like and to propel the rock at any integer velocity. Now including the Z axis in your calculations, if you throw the rock at time 0, where do you need to be so that the rock perfectly collides with every hailstone? Due to probably-magical inertia, the rock won't slow down or change direction when it collides with a hailstone.

In the example above, you can achieve this by moving to position 24, 13, 10 and throwing the rock at velocity -3, 1, 2. If you do this, you will hit every hailstone as follows:

Hailstone: 19, 13, 30 @ -2, 1, -2
Collision time: 5
Collision position: 9, 18, 20

Hailstone: 18, 19, 22 @ -1, -1, -2
Collision time: 3
Collision position: 15, 16, 16

Hailstone: 20, 25, 34 @ -2, -2, -4
Collision time: 4
Collision position: 12, 17, 18

Hailstone: 12, 31, 28 @ -1, -2, -1
Collision time: 6
Collision position: 6, 19, 22

Hailstone: 20, 19, 15 @ 1, -5, -3
Collision time: 1
Collision position: 21, 14, 12
Above, each hailstone is identified by its initial position and its velocity. Then, the time and position of that hailstone's collision with your rock are given.

After 1 nanosecond, the rock has exactly the same position as one of the hailstones, obliterating it into ice dust! Another hailstone is smashed to bits two nanoseconds after that. After a total of 6 nanoseconds, all of the hailstones have been destroyed.

So, at time 0, the rock needs to be at X position 24, Y position 13, and Z position 10. Adding these three coordinates together produces 47. (Don't add any coordinates from the rock's velocity.)

Determine the exact position and velocity the rock needs to have at time 0 so that it perfectly collides with every hailstone. What do you get if you add up the X, Y, and Z coordinates of that initial position?

*/

#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>

typedef long long vlong;

using namespace std;
using namespace boost::multiprecision;

typedef vector<array<int256_t, 6> > Hailstones;

struct Vec3
{
	int256_t x, y, z;

	Vec3 operator+(Vec3 v)
	{
		return Vec3{ x + v.x, y + v.y, z + v.z };
	}

	Vec3 operator-(Vec3 v)
	{
		return Vec3{ x - v.x, y - v.y, z - v.z };
	}
};

Vec3 cross(Vec3 a, Vec3 b)
{
	return Vec3{
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x),
	};
}

int256_t sum(Vec3 v)
{
	return v.x + v.y + v.z;
}

ostream &operator<<(ostream &os, Vec3 const &v)
{
	return os << "Vec3 { " << v.x << ", " << v.y << ", " << v.z << " }";
}

void load(const char *name, Hailstones &H)
{
	auto fp = fopen(name, "rb");
	if (!fp)
	{
		cout << "Failed to load file: " << strerror(errno) << endl;
		exit(1);
	}

	vlong x, y, z, vx, vy, vz;
	for (;;)
	{
		if (fscanf(fp, "%lld, %lld, %lld @ %lld, %lld, %lld\n", &x, &y, &z, &vx, &vy, &vz) != 6)
			break;

		H.push_back({ x, y, z, vx, vy, vz });
	}
	fclose(fp);
}

int256_t part1(const Hailstones &H)
{
	static const int256_t lo = 200000000000000;
	static const int256_t hi = 400000000000000;

	int256_t r = 0;
	for (size_t i = 1; i < H.size(); i++)
	{
		auto [a, b, _, c, d, _] = H[i];
		for (size_t j = 0; j < i; j++)
		{
			auto [e, f, _, g, h, _] = H[j];
			auto det = (d * g) - (c * h);
			if (det == 0)
				continue;

			auto t = (g * (f - b) - h * (e - a)) / det;
			auto u = (c * (f - b) - d * (e - a)) / det;

			auto x = a + (t * c);
			auto y = b + (t * d);

			if (t >= 0 && u >= 0 && lo <= x && x <= hi && lo <= y && y <= hi)
				r += 1;
		}
	}
	return r;
}

int256_t part2(const Hailstones &H)
{
	if (H.size() < 3)
		return 0;

	Vec3 p0 = { H[0][0], H[0][1], H[0][2] };
	Vec3 v0 = { H[0][3], H[0][4], H[0][5] };
	Vec3 p1 = { H[1][0], H[1][1], H[1][2] };
	Vec3 v1 = { H[1][3], H[1][4], H[1][5] };
	Vec3 p2 = { H[2][0], H[2][1], H[2][2] };
	Vec3 v2 = { H[2][3], H[2][4], H[2][5] };

	auto p3 = p1 - p0;
	auto p4 = p2 - p0;
	auto v3 = v1 - v0;
	auto v4 = v2 - v0;

	auto q = cross(v3, p3);
	auto r = cross(v4, p4);
	auto s = cross(q, r);

	auto t = (p3.y * s.x - p3.x * s.y) / (v3.x * s.y - v3.y * s.x);
	auto u = (p4.y * s.x - p4.x * s.y) / (v4.x * s.y - v4.y * s.x);
	if (t == u)
		return -1;

	auto a = sum(p0 + p3);
	auto b = sum(p0 + p4);
	auto c = sum(v3 - v4);

	return ((u * a) - (t * b) + (u * t * c)) / (u - t);
}

int main()
{
	Hailstones H;

	load("24.txt", H);
	cout << part1(H) << endl;
	cout << part2(H) << endl;

	return 0;
}
