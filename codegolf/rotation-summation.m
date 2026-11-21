%{

Take a square matrix containing positive integers as input, and calculate the "rotated sum" of the matrix.

Rotated sum:

Take the sum of the original matrix and the same matrix rotated 90, 180 and 270 degrees.

Suppose the matrix is:

 2    5    8
 3   12    8
 6    6   10
then the rotated sum will be:

2    5    8     8    8   10    10    6    6     6    3    2
3   12    8  +  5   12    6  +  8   12    3  +  6   12    5  = 
6    6   10     2    3    6     8    5    2    10    8    8   

26   22   26
22   48   22
26   22   26

Test cases:
Input and output separated by dashes, different test cases separated by a newline. Test cases in more convenient formats can be found here.

1
-------------
4

1 3
2 4
-------------
10   10 
10   10    

14    6    7   14
 6   12   13   13
 6    2    3   10
 5    1   12   12
-------------
45   37   24   45
24   30   30   37
37   30   30   24
45   24   37   45    

14    2    5   10    2
18    9   12    1    9
 3    1    5   11   14
13   20    7   19   12
 2    1    9    5    6
-------------
24   29   31   41   24
41   49   31   49   29
31   31   20   31   31
29   49   31   49   41
24   41   31   29   24
Shortest code in bytes in each language wins. Explanations are highly encouraged!

%}

function r = rotate(m)
	y = m + rot90(m);
	r = y + rot90(y, 2);
end

rotate([1])
rotate([1 3; 2 4])
rotate([14 6 7 14; 6 12 13 13; 6 2 3 10; 5 1 12 12])
rotate([14 2 5 10 2; 18 9 12 1 9; 3 1 5 11 14; 13 20 7 19 12; 2 1 9 5 6])
rotate([2 5 8; 3 12 8; 6 6 10])

