%{

Let n denote the length of x and x̄ denote the arithmetic mean of x. The sample autocovariance function is defined as

https://i.stack.imgur.com/ModQk.gif

for all -n < h < n. This measures the linear dependence between two points on the same series observed at different times.

The sample autocorrelation function, or ACF, is defined as

https://i.stack.imgur.com/02oJv.gif

This measures the linear predictability of the series x at time t, which we denote xt, using only the value xt+h.

Note that these sample estimates do not match the naïve calculations based on the theoretical properties. That is, the sample autocorrelation function is not equal to the Pearson correlation coefficient of x with the h-step lag of x.

Task
Given an array x and a nonnegative integer h, print or return the first h+1 lag autocorrelations of x, beginning with lag 0. The lag autocorrelations are those corresponding to negative inputs in the above formulas.

You can assume that 0 < h < n, where n is the length of x, and that 2 < n < 256.

Output should be correct to within 1E-4. There are no restrictions on the use of built-in functions or running time.

Examples
h, x -> output
--------------
5, [2.4, 2.4, 2.4, 2.2, 2.1, 1.5, 2.3, 2.3, 2.5, 2] -> [1.00000000,  0.07659298, -0.06007802, -0.51144343, -0.02912874, -0.10468140]
1, [2134, 1863, 1877, 1877, 1492, 1249] -> [1.0000000, 0.3343041]
2, [13067.3, 13130.5, 13198.4] -> [1.0000000000, -0.0002854906, -0.4997145094]

%}

pkg load signal

function r = autocorr(h, x)
	y = xcov(x, 'coeff');
	i = numel(y, x) + (0:h);
	r = y(i);
end

autocorr(5, [2.4, 2.4, 2.4, 2.2, 2.1, 1.5, 2.3, 2.3, 2.5, 2])
autocorr(1, [2134, 1863, 1877, 1877, 1492, 1249])
autocorr(2, [13067.3, 13130.5, 13198.4])
