%{

Challenge
Given a nonempty list of real numbers, compute its median.

Definitions
The median is computed as follows: First sort the list,

if the number of entries is odd, the median is the value in the center of the sorted list,
otherwise the median is the arithmetic mean of the two values closest to the center of the sorted list.

Examples
[1,2,3,4,5,6,7,8,9] -> 5
[1,4,3,2] -> 2.5
[1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,-5,100000,1.3,1.4] -> 1.5
[1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,-5,100000,1.3,1.4] -> 1.5

%}

median([1, 2, 3, 4, 5, 6, 7, 8, 9])
median([1, 4, 3, 2])
median([1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, -5, 100000, 1.3, 1.4])
median([1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, -5, 100000, 1.3, 1.4])
