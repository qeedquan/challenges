/*

For a given DAG (directed acyclic graph), each of its topological sorts is a permutation of all vertices, where for every edges (u,v) in the DAG, u appears before v in the permutation.

Your task is to calculate the total number of topological sorts of a given DAG.

Rules
You can use any format to represent the graph, like adjacency matrix, adjacency list or edge list, as long as you don't do useful computations in your encoding. You can also have things like vertex count or vertex list in the input, if those are useful.
You can assume the graph in the input is always a DAG (doesn't have any cycles).
Your program should work in theory for any input. But it can fail if it overflows the basic integer type in your language.
The names of vertices can be any consecutive values in any type. For example: numbers starting at 0 or 1. (And only if you are not storing code in this number, of course.)
This is code-golf. Shortest code wins.
Example
This is the same input in different formats. Your program don't have to accept all of them. Vertices are always integers starting at 0.

Adjacency list:
[ [1 2 3 5] [2 4] [] [2] [] [3] ]
Adjacency matrix:
[ [0 1 1 1 0 1] [0 0 1 0 1 0] [0 0 0 0 0 0] [0 0 1 0 0 0] [0 0 0 0 0 0] [0 0 0 1 0 0] ]
Edge list:
6 [ [0 1] [0 2] [0 3] [0 5] [1 2] [1 4] [3 2] [5 3] ]
It's the graph shown in this image:

https://i.sstatic.net/V6SWq.png

The output should be:

9
The topological sorts are:

[0 1 4 5 3 2]
[0 1 5 4 3 2]
[0 1 5 3 4 2]
[0 1 5 3 2 4]
[0 5 1 4 3 2]
[0 5 1 3 4 2]
[0 5 1 3 2 4]
[0 5 3 1 4 2]
[0 5 3 1 2 4]

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int toposorts(int num_vertices, int num_edges, int *groups, int *vertices)
{
	vector<int> graph(num_vertices);
	for (auto i = 0; i < num_vertices; i++)
		graph[i] = i;

	auto total = 0;
	do
	{
		auto count = 1;
		for (auto i = num_edges - 1; i >= 0; i--)
		{
			if (graph[groups[i]] >= graph[vertices[i]])
			{
				count = 0;
				break;
			}
		}
		total += count;
	} while (next_permutation(graph.begin(), graph.end()));

	return total;
}

int main()
{
	int groups_1[] = { 0, 0, 0, 0, 1, 1, 3, 5 };
	int vertices_1[] = { 1, 2, 3, 5, 2, 4, 2, 3 };

	int groups_2[] = { 0, 0, 0, 0, 1, 1, 2 };
	int vertices_2[] = { 1, 2, 3, 4, 3, 4, 4 };

	assert(toposorts(6, 8, groups_1, vertices_1) == 9);
	assert(toposorts(6, 7, groups_2, vertices_2) == 30);

	return 0;
}
