%{

Given a number n, Output an ordered list of 1-based indices falling on either of the diagonals of an n*n square matrix.

Example:
For an input of 3:

The square shall be:

1 2 3
4 5 6
7 8 9
Now we select all the indices represented by \, / or X (# or non-diagonal positions are rejected)

\ # /
# X #
/ # \

The output shall be:

[1,3,5,7,9]
Test cases:
1=>[1]
2=>[1,2,3,4]
3=>[1,3,5,7,9]
4=>[1,4,6,7,10,11,13,16]
5=>[1,5,7,9,13,17,19,21,25]
There will be no accepted answer. I want to know the shortest code for each language.

%}

function r = diagonal_square(n)
	I = eye(n);
	r = find(I + flip(I));
end

for i = 1:5
	diagonal_square(i)
end
