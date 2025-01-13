#!/usr/bin/env Rscript

comment <- "

We are putting balls into a fixed number a bins. These bins begin empty.

Empty bin (a=4): 0 0 0 0
And one by one we add balls to the bins.

0 0 0 1  or
0 0 1 0  or
0 1 0 0  or
1 0 0 0
We need a quick way to loop over all the possible states the bins take, without duplicates and without missing any and we don't want to enumerate all the possible bins. So instead we assign each bin-configuration an index.

We assign the index by sorting the possible configurations in a specific way:

Sort ascending by sum: so first 0 0 0 0, then the possible configurations with 1 ball added, then 2, etc.

Then sort within each sum in ascending order, from the first bin to the last:

0 0 0 2
0 0 1 1
0 0 2 0
0 1 0 1
0 1 1 0
0 2 0 0
etc
The index is then assigned ascending through this list:

0 0 0 0  -> 1
0 0 0 1  -> 2
0 0 1 0  -> 3
0 1 0 0  -> 4
1 0 0 0  -> 5
0 0 0 2  -> 6
0 0 1 1  -> 7
0 0 2 0  -> 8
0 1 0 1  -> 9
0 1 1 0  -> 10
0 2 0 0  -> 11
Rules
Create a function or program that takes a list of any size with non-negative integers and print or output its index. You can assume a to be at least 2. Shortest code wins. You may use 0-indexed output or 1-indexed, but specify which you use. NB: all examples here are 1-indexed.

Example code
Not golfed, in R:

nodetoindex <- function(node){
  a <- length(node)
  t <- sum(node)
  if(t == 0) return(1)

  index <- choose(t-1 + a, a)

  while(sum(node) != 0){
    x <- node[1]
    sumrest <- sum(node)
    if(x == 0){
      node <- node[-1]
      next
    }
    a <- length(node[-1])
    index <- index + choose(sumrest + a, a) - choose(sumrest - x + a, a)
    node <- node[-1]
  }
  return(index + 1)
}
Test cases
10 10 10 10 -> 130571
3 1 4 1 5 9 -> 424407
2 9 -> 69
0 0 0 -> 1
0 0 1 -> 2
0 0 0 0 0 0 -> 1
1 0 0 0 0 1 -> 23

"

nodetoindex <- function(node) {
	a <- length(node)
	t <- sum(node)
	if (t == 0)
		return (1)

	index <- choose(t-1 + a, a)
	while (sum(node) != 0) {
		x <- node[1]
		sumrest <- sum(node)

		if (x == 0) {
			node <- node[-1]
			next
		}

		a <- length(node[-1])
		index <- index + choose(sumrest + a, a) - choose(sumrest - x + a, a)
		node <- node[-1]
	}

	return (index + 1)
}

nodetoindex(c(10, 10, 10, 10))
nodetoindex(c(3, 1, 4, 1, 5, 9))
nodetoindex(c(2, 9))
nodetoindex(c(0, 0, 0))
nodetoindex(c(0, 0, 1))
nodetoindex(c(0, 0, 0, 0, 0, 0))
nodetoindex(c(1, 0, 0, 0, 0, 1))

