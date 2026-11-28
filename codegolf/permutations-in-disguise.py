#!/usr/bin/env python3

"""

Given a n-dimensional vector v with real entries, find a closest permutation p of (1,2,...,n) with respect to the  l1-distance.

Details
If it is more convenient, you can use permutations of  (0,1,...,n−1) instead.
If there are multiple closest permutations, you can output any one or alternatively all of them.

The l1 distance between two vectors u,v is defined as
d(u, v) = Sum[i] |u[i] - v[i]|

If you want, you can assume that the input solely consists of integers.
Examples
[0.5  1] -> [1 2], [2 1]
c*[1 1 ... 1] -> any permutation
[1 4 2 6 2] -> [1 4 3 5 2], [1 4 2 5 3]
[1 3 5 4 1] -> [2 3 5 4 1], [1 3 5 4 2]
[7 7 3 2 5 6 4 2] -> [8 7 3 2 5 6 4 1], [8 7 3 1 5 6 4 2], [7 8 3 2 5 6 4 1], [7 8 3 1 5 6 4 2]
[-2 4 5 7 -1 9 3] -> [1 4 5 6 2 7 3], [2 4 5 6 1 7 3], [1 4 5 7 2 6 3], [2 4 5 7 1 6 3]
[0 4 2 10 -1 10 5] -> [1 4 2 6 3 7 5], [1 4 3 6 2 7 5], [2 4 3 6 1 7 5], [3 4 2 6 1 7 5], [1 4 2 7 3 6 5], [1 4 3 7 2 6 5], [2 4 3 7 1 6 5], [3 4 2 7 1 6 5]
Octave script for generating more examples.

M = 6;
x = randi(M,1,M);
disp(mat2str(x))
N = length(x);
p = perms(1:N);
norms = sum(abs(p-x),2);
m=min(norms);
i = find(norms==m);
disp('->')
for k=i'
    disp(mat2str(p(k,:)));
end
disp(numel(i))

"""

"""

Ported from @xnor solution

Uses zero-indexing.

A fast algorithm with a simple idea. If we instead need to permute the input list to make it as close to  (1,2,...,n) as possible,
we should just sort it, as proven below. Since we're instead permuting (1,2,...,n), we choose the permutation that's ordered the same way as the input list, like in my challenge Imitate an ordering (except the input may have repeats). (Edit: miles pointed out this more identical challenge, where Dennis has this same answer.)

Claim: A permutation of the list l that minimizes its distance to (1,2,...,n) is  l sorted.

Proof: Consider some other permutation l′ of  l. We'll prove it can't be better than l sorted.

Pick two indices i,j that l′ has out-of-order, that is where i<j but l′i>l′j.
We show that swapping them can't increase the distance to  (1,2,...,n).
We note that swap changes the contribution these two elements as follows:
|l′i−i|+|l′j−j|→|l′i−j|+|l′j−i|.


Here's a neat way to show this can't be an increase. Consider two people walking on a number line, one going from  l′i to i and the other from  l′j to j.
The total distance they walk is the expression on the left.
Since i<j but l′i>l′j, they switch who is higher on the number line, which means they must cross at some point during their walks, call it p.
But when they reach p, they could then swap their destinations and walk the same total distance.
And then, it can't be worse for them to have walked to their swapped destinations from the start rather than using p as a waypoint,
which gives the total distance on the right-hand side.

So, sorting two out-of-order elements in  l′ makes its distance to  (1,2,...,n) smaller or the same.
Repeating this process will sort l eventually. So, l sorted is at least as good as l′ for any choice of l′, which means it as optimal or tied for optimal.

Note that the only property of  (1,2,...,n) that we used is that it's sorted, so the same algorithm would work to permute any given list to minimize its distance to any fixed list.

In the code, the only purpose of z=zip(l,range(len(l))) is to make the input elements distinct, that is to avoid ties, while keeping the same comparisons between unequal elements. If the input we guaranteed to have no repeats, we could remove this and just have lambda l:map(sorted(l).index,l).

"""

def find(items):
    indexed = list(zip(items, range(len(items))))
    ordered = sorted(indexed)
    result = []
    for value in indexed:
        result.append(ordered.index(value))
    return result

def main():
    print(find([1, 4, 2, 6, 2]))
    print(find([7, 7, 3, 2, 5, 6, 4, 2]))
    print(find([6, 6, 2, 1, 4, 5, 3, 1]))
    print(find([0, 4, 2, 10, -1, 10, 5]))

main()
