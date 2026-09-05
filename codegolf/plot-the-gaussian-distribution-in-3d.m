%{

In probability theory, the normal (or Gaussian) distribution is a very common continuous probability distribution.
Normal distributions are important in statistics and are often used in the natural and social sciences to represent real-valued random variables whose distributions are not known.

The challenge
Your challenge is to plot the probability density of the Gaussian Distribution on a 3-dimensional plane. This function is defined as:

f(x, y) = A*exp(-(a*(x-x0)^2 - 2*b*(x-x0)*(y-y0) + c*(y-y0)^2))

Where:

a = cos(t)^2 / (2*sigma_x^2) + sin(t)^2 / (2*sigma_y^2)
b = -sin(2*t) / (4*sigma_x^2) + sin(2*t) / (4*sigma_y^2)
c = sin(t)^2 / (2*sigma_x)^2 + cos(t)^2 / (2*sigma_y^2)

A = 1
sigma_x = sigma_y = sigma

Rules
Your program must take one input σ, the standard deviation.
Your program must print a 3D plot of the Gaussian Distribution in the highest quality as your language/system allows.
Your program may not use a direct Gaussian Distribution or probability density builtin.
Your program does not have to terminate.
Your plot may be in black and white or color.
Your plot must have grid lines on the bottom. Grid lines on the sides (as shown in the examples) are unnecessary.
Your plot does not need to have line numbers next to the grid lines.
Scoring
As usual in code-golf, the submission with the least bytes wins! I may never "accept" an answer using the button, unless one is incredibly small and intuitive.

Example output
Your output could look something like this:

https://upload.wikimedia.org/wikipedia/commons/thumb/3/3e/Gaussian_2d.svg/300px-Gaussian_2d.svg.png

Or it could look like this:

https://homepages.inf.ed.ac.uk/rbf/HIPR2/figs/gauss2.gif

%}

function gauss3d(sigma)
	A = 1;
	x0 = 0;
	y0 = 0;
	sigma_X = sigma;
	sigma_Y = sigma;

	[X, Y] = meshgrid(-5:.1:5, -5:.1:5);
	for theta = 0:pi/100:pi
		a = cos(theta)^2/(2*sigma_X^2) + sin(theta)^2 / (2*sigma_Y^2);
		b = sin(2 * theta)/(4*sigma_X^2) - sin(2*theta) / (4*sigma_Y^2);
		c = sin(theta)^2/(2*sigma_X^2) + cos(theta)^2 / (2*sigma_Y^2);
		Z = A * exp(-(a*(X-x0).^2 + 2*b*(X-x0).*(Y-y0) + c*(Y-y0).^2));

		surf(X, Y, Z);
		shading interp;
		view(-36, 36);
		pause(0.01);
	end
end

gauss3d(1);
pause(-1);

