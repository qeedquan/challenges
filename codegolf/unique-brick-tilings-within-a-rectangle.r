#!/usr/bin/env Rscript

comment <- "
I was browsing Stackoverflow and saw this question about tiling an MxN rectangle, and I thought it would be great for golfing. Here is the task.

Given the dimension M and N, write a program that outputs how many unique ways a MxN rectangle (N is the number of rows, not columns. Not that it really matters) can be tiled given these constraints.

All tiles are 2x1 or 3x1
All tiles stay within their row (ie they are all horizontal)
Between every two adjacent rows tiles should not be aligned, except on the two ends
M and N are guaranteed to be at least 1
For example, a valid tiling of a 8x3 matrix would be

  2    3     3
  |    |     |
  v    v     v
 _______________
|___|_____|_____|
|_____|_____|___|
|___|_____|_____|
But the following would be invalid, because the rows align

  2    3     3
  |    |     |
  v    v     v
 _______________
|___|_____|_____|
|_____|___|_____|
|_____|_____|___|
Test cases:

8x3: 4

3x1: 1

1x1: 0

9x4: 10

Code golf, so shortest answer wins.
"
 
comment <- "

Ported from @Nick Kennedy Solution

The method for taking a matrix and repeatedly multiplying it by itself is from a question on stackoverflow. This approach works here because it effectively calculates the cumulative number of branches through the different possible rows of bricks.

https://stackoverflow.com/questions/9459421/ak-for-matrix-multiplication-in-r/9459540#9459540

"

f <- function(m,n) {
  # First work out what potential combinations of 2s and 3s add up to m
  i <- 2*0:(m %/% 6) + m %% 2 # Vector with numbers of possible 3s
  j <- i + (m - 3 * i) / 2 # Vector with total number of 2s and 3s
  if (m < 2) {
    0 # If wall less than 2 wide, no point in continuing because answer is 0
  } else {
    # Work out all possible positions of threes for each set
    positions_of_threes <- Map(combn, j, i, simplify = FALSE)
    # Function to work out the cumulative distance along the wall for a given
    # Set of three positions and number of bricks
    make_cumulative_bricks <- function(pos_threes, n_bricks) {
      bricks <- 1:n_bricks %in% pos_threes
      cumsum(2 + bricks)
    }
    # Find all possible rows with cumulative width of wall
    # Note because this is a `Map` with depth two that needs to be vectorised
    # for both `positions_of_threes` and `j`, and we're using base R, the
    # function `make_cumulative_bricks` needs to be placed in a list
    cum_bricks <- Map(Map, list(make_cumulative_bricks), positions_of_threes, j)
    # Finally we have the list of possible rows of bricks as a flat list
    cum_bricks_unlisted <- unlist(cum_bricks, recursive = FALSE)
    # Vectorise the intersect function
    intersect_v <- Vectorize(intersect, SIMPLIFY = FALSE)
    # Find the length of all possible intersects between rows
    intersections <- outer(cum_bricks_unlisted, cum_bricks_unlisted, intersect_v)
    n_intersections <- lengths(intersections)
    # The ones not lined up will only have a single intersect at `m`
    not_lined_up <- n_intersections == 1
    # Now use method described at https://stackoverflow.com/a/9459540/4998761
    # to calculate the (matrix of TRUE/FALSE for lined-up) to the power of `n`
    eigen_nlu <- eigen(not_lined_up)
    final_mat <- eigen_nlu$vectors %*%
      diag(eigen_nlu$values ^ (n - 1)) %*%
      solve(eigen_nlu$vectors)
    # The sum of this matrix is what we're looking for
    sum(final_mat)
  }
}

f(8, 3)
f(3, 1)
f(1, 1)
f(9, 4)
