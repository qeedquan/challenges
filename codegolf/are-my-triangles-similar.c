/*

Given (in any structure; flat list, two lists of lists, a tuple of matrices, a 3D array, complex numbers,…) the coordinates for two non-degenerate triangles ABC=[[Ax,Ay],[Bx,By],[Cx,Cy]] and PQR=[[Px,Py],[Qx,Qy],[Rx,Ry]], determine if they are similar, that is,

they both have the same shape, or one has the same shape as the mirror image of the other. More precisely, one can be obtained from the other by uniformly scaling (enlarging or reducing), possibly with additional translation, rotation and reflection.[Wikipedia]

You may assume that all coordinates are integers.

You must either return a truthy/falsey value indicating similar/dissimilar respectively, or two consistent values; please state your choice.

Failing on some cases due to limitations in floating point precision is acceptable so long as the algorithm is correct in principle.

Bonus task: Add a comment to this post stating whether you would like the same challenge generalised to polygons in N-space.

Walked-through example case
ABC=[[0,0],[1,0],[0,1]] and PQR=[[1,0],[-1,0],[1,-2]]

Reflect ABC in the x-axis: [[0,0],[-1,0],[0,1]]

Reflect in the y-axis: [[0,0],[-1,0],[0,-1]]

Enlarge by a factor of 2: [[0,0],[-2,0],[0,-2]]

Translate right by 1 unit: [[1,0],[-1,0],[1,-2]]

This gives us PQR.

Test cases

Similar
[[8,4],[5,-5],[0,0]] and [[-4,-1],[5,-1],[-1,5]]

[[-2,1],[4,-2],[6,2]] and [[-1,-1],[2,-1],[-1,1]]

[[-1,0],[1,0],[0,2]] and [[-2,5],[2,5],[0,1]]

Dissimilar
[[0,0],[-1,0],[0,1]] and [[1,0],[-1,0],[2,-3]]

[[2,1],[4,2],[6,2]] and [[-1,-1],[2,-1],[-1,1]]

[[-1,0],[1,0],[0,3]] and [[-2,5],[2,5],[0,1]]

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

Point
sub(Point a, Point b)
{
	return (Point){a.x - b.x, a.y - b.y};
}

int
length2(Point a)
{
	return (a.x * a.x) + (a.y * a.y);
}

/*

@Jitse

Calculates the distances between all points in each set and sorts by magnitude.
Then, it checks for all pairs of distances between the two sets if there is a common scaling factor.
If so, the triangles are similar.

*/

bool
similar(Point ta[3], Point tb[3])
{
	int da[3], db[3];
	size_t i, j;

	for (i = 0; i < nelem(da); i++) {
		j = (i + 1) % nelem(da);
		da[i] = length2(sub(ta[j], ta[i]));
		db[i] = length2(sub(tb[j], tb[i]));
	}
	qsort(da, nelem(da), sizeof(*da), cmp);
	qsort(db, nelem(db), sizeof(*db), cmp);

	for (i = 1; i < nelem(da); i++) {
		if (da[i - 1] * db[i] != da[i] * db[i - 1])
			return false;
	}

	return true;
}

int
main(void)
{
	Point ta1[] = {{0, 0}, {1, 0}, {0, 1}};
	Point tb1[] = {{1, 0}, {-1, 0}, {1, -2}};

	Point ta2[] = {{8, 4}, {5, -5}, {0, 0}};
	Point tb2[] = {{-4, -1}, {5, -1}, {-1, 5}};

	Point ta3[] = {{-2, 1}, {4, -2}, {6, 2}};
	Point tb3[] = {{-1, -1}, {2, -1}, {-1, 1}};

	Point ta4[] = {{-1, 0}, {1, 0}, {0, 2}};
	Point tb4[] = {{-2, 5}, {2, 5}, {0, 1}};

	Point ta5[] = {{0, 0}, {-1, 0}, {0, 1}};
	Point tb5[] = {{1, 0}, {-1, 0}, {2, -3}};

	Point ta6[] = {{2, 1}, {4, 2}, {6, 2}};
	Point tb6[] = {{-1, -1}, {2, -1}, {-1, 1}};

	Point ta7[] = {{-1, 0}, {1, 0}, {0, 3}};
	Point tb7[] = {{-2, 5}, {2, 5}, {0, 1}};

	assert(similar(ta1, tb1) == true);
	assert(similar(ta2, tb2) == true);
	assert(similar(ta3, tb3) == true);
	assert(similar(ta4, tb4) == true);

	assert(similar(ta5, tb5) == false);
	assert(similar(ta6, tb6) == false);
	assert(similar(ta7, tb7) == false);

	return 0;
}
