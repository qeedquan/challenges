%{

Create a function or program that takes any continuous, well-defined, single-input function (f(x)=...) and returns an approximate integration from -1 to 1. (at least 3 significant digits or more of precision)

Functions will be treated as programs, with arguments as inputs and returns as outputs.

As always, smallest byte length wins.

EXAMPLES:
y=x^2: ~0.6667
y=e^x: ~2.3504
y=πx^2+ex+1: ~4.0944

For languages where a function isn't a passable value (e.x. c, c++, etc.) the input function DOES NOT count towards character count.

%}

integral(@(x) x.^2, -1, 1)
integral(@(x) e.^x, -1, 1)
integral(@(x) pi*x.^2 + e*x + 1, -1, 1)
