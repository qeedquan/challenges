%{

Build a function that can get all the integers between two given numbers.

Example:

(2,9)

Should give you this output back:

[ 3, 4, 5, 6, 7, 8 ]

If startNum is the same as endNum, return an empty array.

%}

function result = range(from, to)
	result = linspace(from, to, to - from + 1);
end

range(2, 9)
range(10, 15)
