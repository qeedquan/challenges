#!/usr/bin/env python3

"""

K-means is a standard unsupervised clustering algorithm, which, given a set of "points" and a number of clusters K, will assign each "point" to one of K clusters.

Pseudo-Code of K-means
Note that there are many variants of K-means. You have to implement the algorithm I am describing below. You may have some variation on the algorithm or use built-ins as long as you would get the same result as this algorithm given the same initial points.

In this challenge, all inputs will be points on the 2D plane (each point is represented by its coordinates in x and y).

Inputs: K, the number of clusters
        P, the set of points

Choose K points of P uniformly at random
Each chosen point is the initial centroid of its cluster

Loop:
     For each point in P:
         Assign to the cluster whose centroid is the nearest (Euclidean distance)
         In case of a tie, any of the tied cluster can be chosen

     Recompute the centroid of each cluster:
         Its x coordinate is the average of all x's of the points in the cluster
         Its y coordinate is the average of all y's of the points in the cluster

Until the clusters don't change from one iteration to the next

Output: the set of clusters
Inputs and Outputs
You may take K and P through STDIN, or as a function argument, etc.
P and the points in P can be represented using any structure that is natural for set/lists in your language of choice.
K is a strictly positive integer.
You may assume that inputs are valid.
There will always be at least K points in P.
You may output the clusters to STDOUT, return them from a function, etc.
The ordering of the clusters and the ordering inside the clusters is unimportant. -You can either return groups of points to represent clusters, or each point labeled with an identifier for the cluster (e.g. an integer).
Test cases
Since the resulting clusters depend on which points were initially chosen, you may not all get the same results (or the same result each time you run your code).

Therefore, only take the output as an example output.

Input:
  K = 1
  P = [[1,2.5]]
Output:
  [[[1,2.5]]]

Input:
  K = 3
  P = [[4,8], [15,16], [23,42], [-13.37,-12.1], [666,-666]]
Output:
  [[[666,-666]],[[-13.37,-12.1],[4,8]],[[15,16],[23,42]]]

Input:
  K = 2
  P = [[1,1], [1,1], [1,1]]
Output:
  [[[1,1]],[[1,1],[1,1]]]

Scoring
This is code-golf, so the shortest answer in bytes wins.

"""

from sklearn.cluster import KMeans

def kmeans(n, p):
    km = KMeans(n_clusters=n, random_state=8, n_init="auto")
    l = km.fit_predict(p)
    m = {}
    for i in range(len(l)):
        k = l[i]
        if k not in m:
            m[k] = []
        m[k].append(p[i])
    return m

def main():
    print(kmeans(1, [[1, 2.5]]))
    print(kmeans(3, [[4, 8], [15, 16], [23, 42], [-13.37, -12.1], [666, -666]]))
    print(kmeans(2, [[1, 1], [1, 1], [1, 1]]))

main()
