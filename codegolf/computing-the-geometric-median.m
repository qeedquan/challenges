%{

Given a list of integer points in an n-dimensional space, output the geometric median. Note that the output is not necessarily integer. Your answer must be precise to at least two digits after the decimal point.

You may assume that n < 16 and that every component of each point fits in a 32-bit signed integer.

You may write a program or a function. You may take input and give output in any reasonable format. You may optionally pass n as a separate argument, instead of having to deduce it.

You must implement an algorithm to compute the geometric median, and not brute force over the output domain.

Examples:

(5), (14), (10), (7)                         -> any 7 <= x <= 10 is valid
(2, 3), (8, 4), (12, -3), (0, 0), (0, 0)     -> (2.17, 1.29)
(0, 0, 3), (20, 7, 3), (13, 14, 15)          -> (13.18, 7.94, 7.23)
(2, 20, 3, 30), (20, 2, 20, 2), (1, 2, 3, 4) -> (5.46, 5.12, 6.84, 8.06)
The answer is only unique if the set of points do not lie on a line. If the answer is not unique, you may return any valid answer.

%}

%{

ported from @flawr solution

I just use the definition of the geometric median with a numerical minimization.
In this case I make use of the Nelder-Mead simplex algorithm.
It sould always converge as we try to find the minimum of a convex function (according to Wikipedia).

%}

distance = @(m) trace((m'*m).^.5);
geometric_median = @(m) fminsearch(@(y) distance (bsxfun(@minus, m, y)), m(:,1));

geometric_median([[5], [14], [10], [7]])
geometric_median([[2; 3], [8; 4], [12; -3], [0; 0], [0; 0]])
geometric_median([[0; 0; 3], [20; 7; 3], [13; 14; 15]])
geometric_median([[2; 20; 3; 30], [20; 2; 20; 2], [1; 2; 3; 4]])

