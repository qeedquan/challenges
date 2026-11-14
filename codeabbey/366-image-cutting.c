/*

TV screens have a fixed width to height ratio. This is usually 16:9. Images that are shown in the television have to have this exact aspect ratio.

If you want to show your image in a device which accepts images with a fixed aspect ratio, you must first cut it to the requested ratio. But you do not want to lose too much of your image. What is the biggest area of the image you can cut for a given aspect ratio, in pixel squares if your image has a certain width and height in pixels?

Input data: First line will contain number of images to be cut. Other lines will contain width and height of the image WxH and the aspect ratio of the display W:H separated by space.
Answer: You should output the area of the fitting part of the image.

Example:

input data:
3
4702x3938 1:1
3739x5070 16:9
4572x4166 2:1

answer:
15507844 7817616 10451592

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef long long vlong;

vlong
solve(const char *input)
{
	vlong scale;
	vlong width;
	vlong height;
	vlong aspect_width;
	vlong aspect_height;

	if (sscanf(input, "%lldx%lld %lld:%lld", &width, &height, &aspect_width, &aspect_height) != 4)
		return -1;

	scale = min(width / aspect_width, height / aspect_height);
	return scale * scale * aspect_width * aspect_height;
}

int
main()
{
	assert(solve("4702x3938 1:1") == 15507844);
	assert(solve("3739x5070 16:9") == 7817616);
	assert(solve("4572x4166 2:1") == 10451592);

	return 0;
}
