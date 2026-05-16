#include <cassert>
#include <queue>
#include <vector>

using namespace std;

enum
{
	BLACK = 0,
	WHITE,
	UNKNOWN
};

bool bipartite(size_t size, int edges[][2], size_t nedges)
{
	vector<vector<int> > graph(size);
	vector<int> color(size, UNKNOWN);

	for (size_t i = 0; i < nedges; i++)
	{
		auto u = edges[i][0];
		auto v = edges[i][1];

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<int> queue;
	queue.push(0);
	color[0] = BLACK;
	while (!queue.empty())
	{
		auto u = queue.front();
		queue.pop();

		for (auto v : graph[u])
		{
			if (color[v] == color[u])
				return false;

			if (color[v] == UNKNOWN)
			{
				color[v] = 1 - color[u];
				queue.push(v);
			}
		}
	}
	return true;
}

int main()
{
	int edges1[][2] = {
		{ 0, 1 },
		{ 1, 2 },
		{ 2, 0 },
	};

	int edges2[][2] = {
		{ 0, 1 },
		{ 1, 2 },
	};

	int edges3[][2] = {
		{ 0, 1 },
		{ 0, 2 },
		{ 0, 3 },
		{ 0, 4 },
		{ 0, 5 },
		{ 0, 6 },
		{ 0, 7 },
		{ 0, 8 },
	};

	assert(bipartite(3, edges1, size(edges1)) == false);
	assert(bipartite(3, edges2, size(edges2)) == true);
	assert(bipartite(9, edges3, size(edges3)) == true);

	return 0;
}
