#include <cassert>
#include <queue>

using namespace std;

int solve(int sx, int sy, int ex, int ey, int px, int py)
{
	static const int dx[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
	static const int dy[] = { 1, -1, 0, 1, -1, 0, 1, -1 };

	int used[16][16] = {};
	int dist[16][16] = {};
	used[px][py] = 1;

	queue<int> X, Y;
	X.push(sx);
	Y.push(sy);
	used[sx][sy] = 1;
	while (!X.empty())
	{
		sx = X.front();
		sy = Y.front();
		X.pop();
		Y.pop();
		if (sx == ex && sy == ey)
			break;
		
		for (auto i = 0; i < 8; i++)
		{
			auto tx = sx + dx[i];
			auto ty = sy + dy[i];
			if (tx <= 0 || tx > 8 || ty <= 0 || ty > 8)
				continue;
	
			if (!used[tx][ty])
			{
				used[tx][ty] = 1;
				dist[tx][ty] = dist[sx][sy] + 1;
				X.push(tx);
				Y.push(ty);
			}
		}
	}
	return dist[ex][ey];
}

int main()
{
	assert(solve(1, 1, 8, 7, 5, 6) == 7);
	assert(solve(1, 1, 3, 3, 2, 2) == 3);

	return 0;
}
