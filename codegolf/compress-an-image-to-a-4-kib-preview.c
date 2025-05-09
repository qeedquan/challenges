/*

In this challenge you will be creating an image preview compression algorithm. It's goal is to reduce an arbitrary image file to a 4 KiB preview image, that can be used to quickly identify images with very little bandwidth.

You must write two programs (or one combined program): a compressor and a decompressor. Both must take a file or stdin as input, and output to a file or stdout. The compressor must accept one image in a mainstream lossless image format of choice (e.g. PNG, BMP, PPM), and output a file of at most 4096 bytes. The decompressor must accept any file generated by the compressor, and output an image as close as possible to the input. Note that there is no source code size limit for the encoder/decoder, so you can be creative in your algorithm.

Restrictions:

No 'cheating'. Your programs may not use hidden inputs, storing data on the internet, etc. You are also forbidden from including features / data pertaining only to the set of scoring images.

For libraries / tools / built-ins you are allowed to use generic image processing operations (scaling, blurring, color space transformation, etc), but not image decoding / encoding / compression operations (except for compressor input and decompressor output). Generic compression / decompression is also disallowed. It is intended that you implement your own compression for this challenge.

The dimensions of the image output by the decompressor must exactly match those of the original file given to the compressor. You may assume that the image dimensions do not exceed 216 in either direction.

Your compressor must run on an average consumer PC in under 5 minutes, and the decompressor must run in under 10 seconds for any image in the set below.

Scoring
To help quick verification and visual comparison, please include a lossless image album of the test corpus after compression using your answer.

Your compressor will be tested using the following corpus of images:

starry source room rainbow
margin llama kid julia

You can download all images in a zip file here.

Your score will be the average structural similarity index for your compressor on all the images. We will be using the open source dssim for this challenge. It is easily built from source, or if you're on Ubuntu it also has a PPA. It is preferred if you score your own answer, but if you do not know how to build C applications and you do not run Debian/Ubuntu, you can let someone else score for you. dssim expects input/output in PNG, so convert your output to PNG first if you output in a different format.

To make scoring painless, here's a quick helper Python script, usage python score.py corpus_dir compressed_dir:

import glob, sys, os, subprocess

scores = []
for img in sorted(os.listdir(sys.argv[1])):
    ref, preview = (os.path.join(sys.argv[i], img) for i in (1, 2))
    sys.stdout.write("Comparing {} to {}... ".format(ref, preview))
    out = subprocess.check_output(["dssim", ref, preview]).decode("utf-8").split()[0]
    print(out)
    scores.append(float(out))

print("Average score: {:.6f}".format(sum(scores) / len(scores)))
Lowest score wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "stb_image_resize2.h"

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

void
usage(void)
{
	fprintf(stderr, "usage: [options] <in> <out>\n");
	exit(2);
}

int
writefile(const char *name, void *data, size_t len)
{
	FILE *fp;

	fp = fopen(name, "wb");
	if (!fp)
		return -errno;

	fwrite(data, len, 1, fp);
	fclose(fp);
	return 0;
}

int
main(int argc, char *argv[])
{
	int maxlen;

	unsigned char *pixels;
	int width, height, bpp;

	unsigned char *newpixels;
	int newwidth, newheight;
	double ratio;

	unsigned char *png;
	int pnglen;

	maxlen = 4096;
	if (argc != 3)
		usage();

	pixels = stbi_load(argv[1], &width, &height, &bpp, 4);
	if (!pixels)
		fatal("Failed to load image %s", argv[1]);

	newwidth = width;
	newheight = height;
	bpp = 4;
	newpixels = malloc(newwidth * newheight * bpp);
	if (!newpixels)
		fatal("Failed to allocate memory for pixel buffer");
	memcpy(newpixels, pixels, width * height * bpp);

	ratio = 1;
	for (;;) {
		png = stbi_write_png_to_mem(newpixels, 0, newwidth, newheight, bpp, &pnglen);
		if (!png)
			fatal("Failed to generate png");

		if (pnglen < maxlen)
			break;
		free(png);

		newwidth = width * ratio;
		newheight = height * ratio;
		if (newwidth < 1 || newheight < 1)
			fatal("Failed to generate size small enough");

		newpixels = stbir_resize_uint8_linear(pixels, width, height, 0, newpixels, newwidth, newheight, 0, STBIR_RGBA);
		if (!newpixels)
			fatal("Failed to resize image");

		if (ratio >= 0.5)
			ratio -= 0.10;
		else if (ratio >= 0.25)
			ratio -= 0.05;
		else
			ratio -= 0.01;
	}

	if (writefile(argv[2], png, pnglen) < 0)
		fatal("Failed to write image %s", argv[2]);

	printf("Resized to %dx%d (ratio: %.4f) with length %d\n", newwidth, newheight, ratio, pnglen);

	free(png);
	free(pixels);
	free(newpixels);

	return 0;
}
