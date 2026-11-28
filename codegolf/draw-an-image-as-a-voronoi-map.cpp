/*

Credits to Calvin's Hobbies for nudging my challenge idea in the right direction.

Consider a set of points in the plane, which we will call sites, and associate a colour with each site. Now you can paint the entire plane by colouring each point with the colour of the closest site. This is called a Voronoi map (or Voronoi diagram). In principle, Voronoi maps can be defined for any distance metric, but we'll simply use the usual Euclidean distance r = √(x² + y²). (Note: You do not necessarily have to know how to compute and render one of these to compete in this challenge.)

Here is an example with 100 sites:

https://i.stack.imgur.com/9v7DT.png

If you look at any cell, then all points within that cell are closer to the corresponding site than to any other site.

Your task is to approximate a given image with such a Voronoi map. You're given the image in any convenient raster graphics format, as well as an integer N. You should then produce up to N sites, and a colour for each site, such that the Voronoi map based on these sites resembles the input image as closely as possible.

You can use the Stack Snippet at the bottom of this challenge to render a Voronoi map from your output, or you can render it yourself if you prefer.

You may use built-in or third-party functions to compute a Voronoi map from a set of sites (if you need to).

This is a popularity contest, so the answer with the most net votes wins. Voters are encouraged to judge answers by

how well the original images and their colours are approximated.
how well the algorithm works on different kinds of images.
how well the algorithm works for small N.
whether the algorithm adaptively clusters points in regions of the image that require more detail.
Test Images
Here are a few images to test your algorithm on (some of our usual suspects, some new ones). Click the pictures for larger versions.

The beach in the first row was drawn by Olivia Bell, and included with her permission.

If you want an extra challenge, try Yoshi with a white background and get his belly line right.

You can find all of these test images in this imgur gallery where you can download all of them as a zip file. The album also contains a random Voronoi diagram as another test. For reference, here is the data that generated it.

Please include example diagrams for a variety of different images and N, e.g. 100, 300, 1000, 3000 (as well as pastebins to some of the corresponding cell specifications). You may use or omit black edges between the cells as you see fit (this may look better on some images than on others). Do not include the sites though (except in a separate example maybe if you want to explain how your site placement works, of course).

If you want to show a large number of results, you can create a gallery over on imgur.com, to keep the size of the answers reasonable. Alternatively, put thumbnails in your post and make them links to larger images, like I did in my reference answer. You can get the small thumbnails by appending s to the file name in the imgur.com link (e.g. I3XrT.png -> I3XrTs.png). Also, feel free to use other test images, if you find something nice.

Renderer
Paste your output into the following Stack Snippet to render your results. The exact list format is irrelevant, as long as each cell is specified by 5 floating point numbers in the order x y r g b, where x and y are the coordinates of the cell's site, and r g b are the red, green and blue colour channels in the range 0 ≤ r, g, b ≤ 1.

The snippet provides options to specify a line width of the cell edges, and whether or not the cell sites should be shown (the latter mostly for debugging purposes). But note that the output is only re-rendered when the cell specifications change - so if you modify some of the other options, add a space to the cells or something.

Show code snippet

Massive credits to Raymond Hill for writing this really nice JS Voronoi library.

Related Challenges
Paint by Numbers
Photomosaics or: How Many Programmers Does it Take to Replace a Light Bulb?

*/

// https://learnopencv.com/delaunay-triangulation-and-voronoi-diagram-using-opencv-c-python/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

// Draw a single point
static void draw_point(Mat &img, Point2f fp, Scalar color)
{
	circle(img, fp, 2, color, FILLED, LINE_AA, 0);
}

// Draw delaunay triangles
static void draw_delaunay(Mat &img, Subdiv2D &subdiv, Scalar delaunay_color)
{
	vector<Vec6f> triangleList;
	subdiv.getTriangleList(triangleList);
	vector<Point> pt(3);
	Size size = img.size();
	Rect rect(0, 0, size.width, size.height);

	for (size_t i = 0; i < triangleList.size(); i++)
	{
		Vec6f t = triangleList[i];
		pt[0] = Point(cvRound(t[0]), cvRound(t[1]));
		pt[1] = Point(cvRound(t[2]), cvRound(t[3]));
		pt[2] = Point(cvRound(t[4]), cvRound(t[5]));

		// Draw rectangles completely inside the image.
		if (rect.contains(pt[0]) && rect.contains(pt[1]) && rect.contains(pt[2]))
		{
			line(img, pt[0], pt[1], delaunay_color, 1, LINE_AA, 0);
			line(img, pt[1], pt[2], delaunay_color, 1, LINE_AA, 0);
			line(img, pt[2], pt[0], delaunay_color, 1, LINE_AA, 0);
		}
	}
}

// Draw voronoi diagram
static void draw_voronoi(Mat &img, Subdiv2D &subdiv)
{
	vector<vector<Point2f> > facets;
	vector<Point2f> centers;
	subdiv.getVoronoiFacetList(vector<int>(), facets, centers);

	vector<Point> ifacet;
	vector<vector<Point> > ifacets(1);

	for (size_t i = 0; i < facets.size(); i++)
	{
		ifacet.resize(facets[i].size());
		for (size_t j = 0; j < facets[i].size(); j++)
			ifacet[j] = facets[i][j];

		Scalar color;
		color[0] = rand() & 255;
		color[1] = rand() & 255;
		color[2] = rand() & 255;
		fillConvexPoly(img, ifacet, color, 8, 0);

		ifacets[0] = ifacet;
		polylines(img, ifacets, true, Scalar(), 1, LINE_AA, 0);
		circle(img, centers[i], 3, Scalar(), FILLED, LINE_AA, 0);
	}
}

void usage()
{
	fprintf(stderr, "usage: <file> <sites>\n");
	exit(2);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		usage();

	srand(time(NULL));

	const char *file = argv[1];
	int sites = atoi(argv[2]);

	// Define colors for drawing.
	Scalar delaunay_color(255, 255, 255), points_color(0, 0, 255);

	// Read in the image.
	Mat img = imread(file);

	// Keep a copy around
	Mat img_orig = img.clone();

	// Rectangle to be used with Subdiv2D
	Size size = img.size();
	Rect rect(0, 0, size.width, size.height);

	// Create an instance of Subdiv2D
	Subdiv2D subdiv(rect);

	// Create a vector of points.
	vector<Point2f> points;

	// Read in the points from a text file
	for (int i = 0; i < sites; i++)
	{
		points.push_back(Point2f(rand() % size.width, rand() % size.height));
	}

	// Insert points into subdiv
	for (vector<Point2f>::iterator it = points.begin(); it != points.end(); it++)
	{
		subdiv.insert(*it);
	}

	// Draw delaunay triangles
	draw_delaunay(img, subdiv, delaunay_color);

	// Draw points
	for (vector<Point2f>::iterator it = points.begin(); it != points.end(); it++)
	{
		draw_point(img, *it, points_color);
	}

	// Allocate space for Voronoi Diagram
	Mat img_voronoi = Mat::zeros(img.rows, img.cols, CV_8UC3);

	// Draw Voronoi diagram
	draw_voronoi(img_voronoi, subdiv);

	// Show results.
	imwrite("triangulation.png", img);
	imwrite("voronoi.png", img_voronoi);

	destroyAllWindows();

	return 0;
}
