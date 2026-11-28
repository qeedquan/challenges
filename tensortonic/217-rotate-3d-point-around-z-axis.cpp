/*

Rotate one 3D point or a batch of points around the z-axis by angle θ radians. Compute each transformed coordinate separately:

x' = x*cos(t) - y*sin(t)
y' = x*sin(t) + y*cos(t)
z' = z

Here (x, y, z) is an input point. Preserve the input shape and return a floating-point NumPy array.

Examples
Input: points = [1, 0, 0], theta = 1.5707963267948966

Output: [0, 1, 0]

Explanation: A positive quarter-turn maps the positive x-axis onto the positive y-axis.

Input: points = [[1, 0, 0], [0, 1, 2]], theta = 1.5707963267948966

Output: [[0, 1, 0], [-1, 0, 2]]

Hint 1
Read coordinates with values[..., 0], values[..., 1], and values[..., 2].

Hint 2
Stack the transformed coordinates with np.stack(..., axis=-1).

Requirements
Apply the rotation to every point without looping over batch rows
Leave each z-coordinate unchanged
Accept shape (3,) or (N, 3)
Return a NumPy array with the input shape
Constraints
theta is measured in radians
Use NumPy only

*/

#include <cmath>
#include <print>

using namespace std;

struct Point
{
	double x, y, z;
};

template <>
struct formatter<Point>
{
	constexpr auto parse(format_parse_context &ctx)
	{
		return ctx.begin();
	}

	auto format(const Point &p, format_context &ctx) const
	{
		return format_to(ctx.out(), "Point({:.3f}, {:.3f}, {:.3f})", p.x, p.y, p.z);
	}
};

Point rotate_z(Point p, double t)
{
	auto c = cos(t);
	auto s = sin(t);
	return Point{
		(p.x * c) - (p.y * s),
		(p.x * s) + (p.y * c),
		p.z,
	};
}

int main()
{
	println("{}", rotate_z({ 1, 0, 0 }, 1.5707963267948966));
	println("{}", rotate_z({ 0, 1, 2 }, 1.5707963267948966));
	return 0;
}
