%{

Write a function to shuffle an array.

Ex.:

Input: [1,2,3,4]
Output: [3,1,4,2]

Assume input is array.

Hint: Math.random()

http://devdocs.io/javascript/global_objects/math/random

%}

function v = shuffle(v)
	v = v(randperm(length(v)));
end

for i=1:10
	shuffle([1 2 3 4])
end

