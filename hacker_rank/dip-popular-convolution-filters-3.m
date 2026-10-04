#!/usr/bin/env -S octave -qf

%{

You are provided with the kernels of six popular convolution filters. Which of these filters will detect horizontal, vertical and diagonal edges?

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

%}

pkg load image;

args = argv();
if length(args) != 1
	printf("usage: <image>\n");
	quit(2);
end

% kernel #2, #5, #6 detects edges, though each detect sharpness of edges
kernel1 = [0 0 0; 0 1 0; 0 0 0];
kernel2 = [-1 -1 -1; -1 8 -1; -1 -1 -1];
kernel3 = [0, -1, 0; -1, 5, -1; 0, -1, 0];
kernel4 = [1/16, 1/8, 1/16; 1/8, 1/4, 1/8; 1/16, 1/8, 1/16];
kernel5 = [-1, 0, 1; -2, 0, 2; -1, 0, 1];
kernel6 = [-1, -2, -1; 0, 0, 0; 1, 2, 1];
kernels = {kernel1, kernel2, kernel3, kernel4, kernel5, kernel6};

image = imread(args{1});
for i=1:length(kernels)
	output = imfilter(image, kernels{i});
	filename = sprintf("kernel%d.png", i);
	imwrite(output, filename);
end

