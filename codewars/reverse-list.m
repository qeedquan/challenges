%{

Write reverseList function that simply reverses lists.

%}

function result = reverseList(list)
	result = flip(list);
end

reverseList([1 2 3 4])
reverseList(['a' 'b' 'c'])
reverseList([.2 3 .5])
