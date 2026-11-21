%{

Converting a color image to grayscale is one of the most fundamental image processing operations. The human eye perceives different colors with varying sensitivity, so a simple average of RGB channels does not produce a perceptually accurate grayscale image. Instead, a weighted sum based on human vision is used.

Given a color image represented as a 3D array (H × W × 3 with RGB channels), convert it to a grayscale image (H × W) using the luminance formula.

Algorithm
For each pixel, compute the grayscale intensity using the ITU-R BT.601 luminance weights:

Y = 0.299*R + 0.587*G + 0.114*B

These weights reflect the human eye's greater sensitivity to green light, moderate sensitivity to red, and lower sensitivity to blue.

Return an H by W list of grayscale floats.

Examples
Input: image = [[[255, 0, 0]]]

Output: [[76.245]]

Explanation: The red channel contributes 0.299 times 255.

Input: image = [[[255, 0, 0], [0, 255, 0]], [[0, 0, 255], [255, 255, 255]]]

Output: [[76.245, 149.685], [29.07, 255.0]]

Hint 1
Unpack each pixel into red, green, and blue channel values.

Hint 2
Append the weighted channel sum to the corresponding grayscale row.

Requirements
Convert each RGB pixel to a single grayscale value using the luminance formula
Use the standard ITU-R BT.601 weights: R=0.299, G=0.587, B=0.114
Return a 2D matrix (H × W) of grayscale values
Preserve the spatial dimensions of the input image
Round numeric outputs to 6 decimal places.
Constraints
image is a 3D list of shape H × W × 3 with integer RGB values in [0, 255]
H >= 1, W >= 1
Return a 2D list of floats
Time limit: 300 ms

%}

function GRAY = grayscale(RGB)
	GRAY = RGB * [0.299 0.587, 0.114]';
end

grayscale([255 0 0])
grayscale([[255 0 0; 0 255 0]; [0 0 255; 255 255 255]])
