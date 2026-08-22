/*

Description

There is a rectangular room, covered with square tiles. Each tile is colored either red or black. A man is standing on a black tile. From a tile, he can move to one of four adjacent tiles. But he can't move on red tiles, he can move only on black tiles.

Write a program to count the number of black tiles which he can reach by repeating the moves described above.

Input

The input consists of multiple data sets. A data set starts with a line containing two positive integers W and H; W and H are the numbers of tiles in the x- and y- directions, respectively. W and H are not more than 20.

There are H more lines in the data set, each of which includes W characters. Each character represents the color of a tile as follows.

'.' - a black tile
'#' - a red tile
'@' - a man on a black tile(appears exactly once in a data set)
The end of the input is indicated by a line consisting of two zeros.

Output

For each data set, your program should output a line which contains the number of tiles he can reach from the initial tile (including itself).

Sample Input

6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0

Sample Output

45
59
6
13

Source

Japan 2004 Domestic

*/

#include <cstdio>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

bool findchar(const vector<string> &level, int ch, int &outx, int &outy, int &outw, int &outh)
{
	if (level.size() == 0 || level[0].size() == 0)
		return false;

	int width = level[0].size();
	int height = level.size();
	for (auto y = 0; y < height; y++)
	{
		for (auto x = 0; x < width; x++)
		{
			if (level[y][x] == ch)
			{
				outx = x;
				outy = y;
				outw = width;
				outh = height;
				return true;
			}
		}
	}

	return false;
}

void floodfill(const vector<string> &level, vector<vector<bool> > &visited, int &count, int x, int y, int width, int height)
{
	visited[y][x] = true;
	count++;

	const int dirs[][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	for (size_t i = 0; i < 4; i++)
	{
		auto nx = x + dirs[i][0];
		auto ny = y + dirs[i][1];
		if (nx < 0 || nx >= width || ny < 0 || ny >= height)
			continue;

		if (level[ny][nx] != '.' || visited[ny][nx])
			continue;

		floodfill(level, visited, count, nx, ny, width, height);
	}
}

int reachable(const vector<string> &level)
{
	int startx, starty, width, height;
	if (!findchar(level, '@', startx, starty, width, height))
		return 0;

	vector<vector<bool> > visited;
	visited.resize(height);
	for (size_t i = 0; i < visited.size(); i++)
		visited[i].resize(width);

	auto count = 0;
	floodfill(level, visited, count, startx, starty, width, height);

	return count;
}

int main()
{
	assert(reachable({
			   "....#.",
			   ".....#",
			   "......",
			   "......",
			   "......",
			   "......",
			   "......",
			   "#@...#",
			   ".#..#.",
		   }) == 45);

	assert(reachable({
			   ".#.........",
			   ".#.#######.",
			   ".#.#.....#.",
			   ".#.#.###.#.",
			   ".#.#..@#.#.",
			   ".#.#####.#.",
			   ".#.......#.",
			   ".#########.",
			   "...........",
		   }) == 59);

	assert(reachable({
			   "..#..#..#..",
			   "..#..#..#..",
			   "..#..#..###",
			   "..#..#..#@.",
			   "..#..#..#..",
			   "..#..#..#..",
		   }) == 6);

	assert(reachable({
			   "..#.#..",
			   "..#.#..",
			   "###.###",
			   "...@...",
			   "###.###",
			   "..#.#..",
			   "..#.#..",
		   }) == 13);

	return 0;
}
