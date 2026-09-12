%{

If you visit Code Golf often, you may have heard of Kolmogorov complexity. It's usually defined as the amount of bytes required to express some string in a programming language.

Here the Kolmogorov-complexity of a natural number is defined similarly: the number of bytes required to represent it in a programming language.

A number is Kolmogorov-simple if it's more space-efficient to represent it with the programming language, then with simply storing it in binary (base-256).
In other words, if b is the Kolmogorov-complexity of a number n, n is Kolmogorov-simple iff b<log256(n+1).
Every Turing-complete language has infinitely many Kolmogorov-simple numbers.

Your task is to find the smallest Kolmogorov-simple number. In other words, output the smallest number n in b bytes, such that b<log256(n+1).

Rules
If you express the number n, your program has to be at most ceil(log256(n+1))-1 bytes long.
The number has to be a positive whole number
Use a reasonable IO format. These may include: printing to stdout, expressions, functions, storing the number to a variable, pushing the number to stack or taking a number as input and comparing it the represented number.
Try to stick to the convention. Floating point numbers, complex numbers and fractions are allowed, as long as it's exactly an integer.
If you use a text-based format, your output should match this regex: ((\d+(\.\d*)?)|(\d*\.\d+))(e[+-]?\d+)?. That is, it should be a decimal number. Trailing newlines etc. are allowed.
Smallest number outputted (i.e. the value n) per language wins!

%}

8^8
