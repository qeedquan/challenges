/*

You are provided with the kernels of six popular convolution filters. Which of these filters will leave the image unchanged upon convolution?

Only enter the integer corresponding to the appropriate filter (1-6) in the text box. Do not leave any leading or trailing spaces or newlines.

1

    0   0   0
    0   1   0
    0   0   0
2

    -1  -1  -1
    -1   8  -1
    -1  -1  -1
3

     0  -1   0
    -1   5  -1
     0  -1   0
4

    1/16    1/8     1/16
    1/8     1/4     1/8
    1/16    1/8     1/16  
5

    -1  0   1
    -2  0   2
    -1  0   1
6

    -1  -2  -1
     0   0   0
     1   2   1

*/

#include <cstdio>
#include <cstdlib>
#include <opencv2/opencv.hpp>

using namespace cv;

[[noreturn]] void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

[[noreturn]] void usage()
{
	fprintf(stderr, "usage: <file>\n");
	exit(2);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		usage();

	auto image = imread(argv[1]);
	if (image.empty())
		fatal("Could not open image");

	// kernel #1 is the identity filter
	Mat kernel1 = (Mat_<double>(3, 3) << 0, 0, 0, 0, 1, 0, 0, 0, 0);
	Mat kernel2 = (Mat_<double>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
	Mat kernel3 = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	Mat kernel4 = (Mat_<double>(3, 3) << 1.0 / 16, 1.0 / 8, 1.0 / 16, 1.0 / 8, 1.0 / 4, 1.0 / 8, 1.0 / 16, 1.0 / 8, 1.0 / 16);
	Mat kernel5 = (Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	Mat kernel6 = (Mat_<double>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

	auto kernels = { kernel1, kernel2, kernel3, kernel4, kernel5, kernel6 };
	auto ddepth = -1;
	auto index = 1;
	for (auto &kernel : kernels)
	{
		char filename[32];
		snprintf(filename, sizeof(filename), "kernel%d.png", index);

		auto output = Mat();
		filter2D(image, output, ddepth, kernel);

		imwrite(filename, output);
		index += 1;
	}

	return 0;
}
