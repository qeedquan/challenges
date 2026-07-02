/*

Olympic vine-swingers perform their routines in standard trees. In particular, Standard Tree n has vertices for 0 up through n-1 and edges linking each nonzero vertex a to the vertex n % a below it. So, for example, Standard Tree 5 looks like this:

3
|
2   4
 \ /
  1
  |
  0
because the remainder when 5 is divided by 3 is 2, the remainder when 5 is divided by 2 or by 4 is 1, and the remainder when 5 is divided by 1 is 0.

This year, Tarzan will be defending his gold with new routines, each of which begins at vertex n - 1, swings to vertex n - 2, continues to vertex n - 3, etc., until finally he dismounts to vertex 0.

The score for a routine is the sum of the scores for each swing (including the dismount), and the score for a swing is the distance within the tree between its start and end points. Thus, Tarzan's routine on Standard Tree 5 has a score of 6:

a swing from 4 to 3 scores three points (down, up, up),
a swing from 3 to 2 scores one point (down),
a swing from 2 to 1 scores one point (down), and
a dismount from 1 to 0 scores one point (down).
Write a program or function that, given a positive integer n, computes the score of Tarzan's routine on Standard Tree n. Sample inputs and outputs:

 1 ->  0
 2 ->  1
 3 ->  2
 4 ->  6
 5 ->  6
 6 -> 12
 7 -> 12
 8 -> 18
 9 -> 22
10 -> 32
11 -> 24
12 -> 34
13 -> 34
14 -> 36
15 -> 44
16 -> 58
17 -> 50
18 -> 64
19 -> 60
20 -> 66
21 -> 78
22 -> 88
23 -> 68
24 -> 82

Rules and code scoring are as usual for code-golf.

*/

package main

func main() {
	tab := []int{0, 1, 2, 6, 6, 12, 12, 18, 22, 32, 24, 34, 34, 36, 44, 58, 50, 64, 60, 66, 78, 88, 68, 82}
	for i := range tab {
		assert(tarzan(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Dave

This calculates the distance between each pair of points with the following formula:

Add the distance from the root to node A
Add the distance from the root to node B
Subtract 2* the length of the common root of A and B
This has the advantage that when applied to all pairs, it's the same as:

Add 2* the distance from the root to each node
Subtract 2* the length of the common root of each node pair
Subtract the distance from the root to the first node
Subtract the distance from the root to the last node
To make the logic simpler, we assume we're going from node 0 to node n-1, rather than n-1 to 0 as the question states. The distance from the root node to node 0 is obviously 0 (they're the same). And we can see that for (most) trees, the distance from the last node to the root is 2:

                    n+1 % n = 1  for all n > 1
and:                  n % 1 = 0  for all n >= 0
therefore:  n % (n % (n-1)) = 0  for all n > 2
This means we have some special cases (n<2) but we can account for those easily enough.

Breakdown:

F(i){                               // Types default to int
    int c[i],                       // Buffer for storing paths
        t=i-2,                      // Running total score
        n=0,                        // Loop index
        p;                          // Inner loop variable
    for(;++n<i;)                    // Loop through all node pairs (n-1, n)
        for(p=c[n]=n;p=i%p;c[p]=n)  //  Recurse from current node (n) to root
            t+=c[p]<n-1;            //   Increase total unless this is a common
                                    //   node with the previous path
    return i>2?   :i-1;             // Account for special cases at 1 and 2
               t*2                  // For non-special cases, multiply total by 2
}

*/

func tarzan(n int) int {
	if n < 2 {
		return 0
	}
	if n == 2 {
		return 1
	}

	c := make([]int, n)
	r := n - 2
	for i := 1; i < n; i++ {
		c[i] = i
		for p := c[i]; n%p != 0; c[p] = i {
			p = n % p
			if c[p] < i-1 {
				r += 1
			}
		}
	}
	return r * 2
}
