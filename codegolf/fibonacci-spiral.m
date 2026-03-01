%{

Your goal is to generate a Fibonacci spiral with numbers.

https://i.stack.imgur.com/eHWK9.png

Example Input / Output
1 -> 1

2 -> 1 1

3 -> 1 1
     2 2
     2 2

6 -> 8 8 8 8 8 8 8 8 5 5 5 5 5
     8 8 8 8 8 8 8 8 5 5 5 5 5
     8 8 8 8 8 8 8 8 5 5 5 5 5
     8 8 8 8 8 8 8 8 5 5 5 5 5
     8 8 8 8 8 8 8 8 5 5 5 5 5
     8 8 8 8 8 8 8 8 1 1 3 3 3
     8 8 8 8 8 8 8 8 2 2 3 3 3
     8 8 8 8 8 8 8 8 2 2 3 3 3
Input of 9

Input The input can be taken through STDIN or function argument. It will be a single number

Output The output can be from STDOUT or a function's return value. It should be a single string.

Extra whitespace at the very end of the line is not allowed. The output can contain digits, linefeeds (newlines), and spaces.

Orientation does not matter, this means rotations and reflections. As long as it follows a valid Fibonacci spiral pattern.

Numbers with different amounts of digits (e.g. 1 and 13) should be right-aligned with each other. A space may need to be added to the very beginning of a line so everything can line up.

1   1                          1   1
100 100  should actually be  100 100
You can see an example here

%}

% Based on @Luis Mendo solution
function fibspiral(n)
	a = 0;
	b = 1;
	r = 1;
	for i=2:n
		c = a + b;
		a = b;
		b = c;
		r = [rot90(r) b*ones(b)];
	end;

	if mod(n, 2) == 0
		r = rot90(r, 2);
	else
		r = rot90(r, 1);
	end
	r = flip(r);

	disp(n)
	disp(r)
end

for n=1:6
	fibspiral(n);
end
