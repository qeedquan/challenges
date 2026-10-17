%{

Though challenges involving magic squares abound on this site, none I can find so far ask the golfer to print / output all normal magic squares of a certain size. To be clear, a normal magic square of order n
 is:

An n×n array of numbers.
Each positive integer up to and including n^2 appears in exactly one position in the array, and
Each row, column, and both main- and anti-diagonals of the array sum to the same "magic number".
Your challenge is to write the shortest program that prints all normal magic squares of order 3. There are 8 such squares. For the purposes of this challenge, the characters surrounding the output array, such as braces or brackets that accompany arrays in many languages, are allowed. For a non-optimized example in python, see here. Happy golfing!

%}

% ported from @138 Aspen solution
p = perms([1 2 3 4 6 7 8 9]);
m = zeros(3, 3, 0);
for i=1:size(p, 1)
    r = [p(i, 1:4), 5, p(i, 5:8)];
    r = reshape(r, [3, 3]);
    if isequal(sum(r), [15 15 15]) && isequal(sum(r.'), [15 15 15]) && isequal(sum(diag(r)), 15) && isequal(sum(diag(rot90(r))), 15)
        m = cat(3, m, r);
        r
    end
end
