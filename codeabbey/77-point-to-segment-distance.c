/*

Very common problem in computational geometry is to find distance between the point and the line segment. It is heavily exploited in programming 3D video games when recalculating visibility of walls for player while redrawing each frame (i.e it is could be solved for 1000 wall fragments in each frame and about 50 frames are completely recalculated during each second).

The definition of the distance between point and segment is like following:

draw a line through both ends of a segment (i.e. the line to which this segment belongs);
from our point cast a perpendicular to this line - the length of this perpendicular is the distance between the point and the line;
if the other end of the perpendicular belongs to our segment (i.e. lays between its ends), then the distance to this segment equals to distance to this line;
otherwise distance from point to segment equals to distance to nearest of its ends.
For example, see the picture above - line segment is drawn with blue and perpendiculars from 2nd and 3rd points fall directly onto this segment, so they represent the distance from these points. On other hand perpendiculars from 1st and 4th points fall out of segment (and they are not shown), so that distances are defined simply by the nearest end of a segment (distances from all points are represented with grey lines). The line on which the segment lays is shown with light-green.

Input data will contain the number of test-cases in first line.
The following lines contain six values each: x1 y1 x2 y2 xp yp - denoting the segment between points (x1,y1) and (x2,y2) and the point (xp,yp) to which a distance should be calculated.
Answer should contain distances from points to segments for each test-case, separated with spaces.

Example:

input data:
3
1 1 5 5 2 3
2 3 7 8 2 0
12 8 18 3 5 7

answer:
0.707106781 3 7.07106781187
Note that in the second test-case the shortest distance from point is to the end of a segment, not to a line to which the segment belongs.

Please, provide answers with accuracy of 1e-7 or better.

*/

#include <stdio.h>
#include <math.h>

#define sqr(x) ((x) * (x))

double
point_to_segment(double x1, double y1, double x2, double y2, double xp, double yp)
{
	double closest_x;
	double closest_y;
	double dx, dy;
	double dpx, dpy;
	double t;

	// Vector AB
	dx = x2 - x1;
	dy = y2 - y1;

	// If the segment is just a point
	if (dx == 0 && dy == 0)
		return hypot(xp - x1, yp - y1);

	// Vector AP
	dpx = xp - x1;
	dpy = yp - y1;

	// Dot product (AP . AB) normalized by length squared of AB
	t = ((dpx * dx) + (dpy * dy)) / (sqr(dx) + sqr(dy));

	// Clamp t to the range[0, 1] to find the closest point on the segment
	t = fmax(0, fmin(1, t));

	// Closest point coordinates
	closest_x = x1 + (t * dx);
	closest_y = y1 + (t * dy);

	// Distance from P to the closest point
	return hypot(xp - closest_x, yp - closest_y);
}

int
main()
{
	printf("%f\n", point_to_segment(1, 1, 5, 5, 2, 3));
	printf("%f\n", point_to_segment(2, 3, 7, 8, 2, 0));
	printf("%f\n", point_to_segment(12, 8, 18, 3, 5, 7));

	return 0;
}
