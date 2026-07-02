%{

Task
Your task is to output a single integer, with one restriction: its digits must be a permutation of [1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6].

For example, you could output 653443653152432, 413265345463352, or any of the other 15-digit integers whose digits are a permutation of the list.

Rules
Your code must terminate in a reasonable amount of time (do not just enumerate every integer until you get to 122333344455566).

If your language doesn't support 15-digit integers, or if there is no meaningful distinction between strings and integers in your language, you may output a string.

This is code-golf, shortest answer in bytes wins.

%}

function r = digperm()
	A = [1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6];
	x = A(randperm(length(A)));
	r = polyval(x, 10);
end

for i=1:100
	printf("%d\n", digperm);
end
