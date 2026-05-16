/*

I challenge you to write a code to make an (extended) ASCII-art logic gate diagram for the sum of products form of an equation.

Use the following notation to represent gates:

AND
    INPUT───|&&
            |&&───OUTPUT
    INPUT───|&&
OR
    INPUT───|OR
            |OR───OUTPUT
    INPUT───|OR  
Gates with more than 2 inputs
    INPUT───|OR
            |OR
    INPUT───|OR───OUTPUT
            |OR
    INPUT───|OR
NOT
    INPUT───│>o───OUTPUT
Character set
Note that │ is not an ASCII pipe sign but a box-drawing character. Use box-drawing characters such as ─ │ ┌ ┐ └ ┘ for connections.

Example
Input
    A'*B'+B*C
Output
    A────│>o────│&&
                │&&─────┐
    B────│>o────│&&     └│OR
                         │OR─────A*B+B*C
    B───────────│&&     ┌│OR
                │&&─────┘
    C───────────│&&    
Winner
The winner is the answer with the most up-votes in 5 days

*/

// ported from @curtmack solution
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <valarray>
#include <set>
#include <map>
#include <vector>

using namespace std;

using Input = string;

struct TermInput
{
	Input name;
	int ypos;
	bool neg;
};

using Term = vector<TermInput>;
using Expr = vector<Term>;

enum Direction
{
	RIGHT,
	DOWN
};

constexpr char VERT = '|';
constexpr char HORIZ = '-';
constexpr char RBRANCH = '}';
constexpr char LUP = '\'';
constexpr char LDOWN = '.';
constexpr char RUP = '`';
constexpr char RDOWN = ',';

vector<string> split(const string &input, const string delim)
{
	set<char> seen;
	for (auto symbol : delim)
		seen.insert(symbol);

	vector<string> fields;
	string current;
	for (auto symbol : input)
	{
		if (seen.find(symbol) != seen.end())
		{
			fields.push_back(current);
			current = "";
		}
		else
			current += symbol;
	}
	fields.push_back(current);

	return fields;
}

string repeat(char symbol, int length)
{
	stringstream stream;
	for (auto i = 0; i < length; i++)
		stream << symbol;
	return stream.str();
}

void put(vector<char> &matrix, int width, int height, int x, int y, const string &input, Direction dir)
{
	char *ins = &matrix[(y * width) + x];
	char *end = &matrix[height * width];
	for (auto symbol : input)
	{
		if (ins >= end)
			break;
		*ins = symbol;

		if (dir == Direction::RIGHT)
			ins += 1;
		else
			ins += width;
	}
}

void draw(vector<char> &matrix, int width, int height)
{
	for (auto i = 0; i < (width * height); i++)
	{
		printf("%c", matrix[i]);
		if ((i + 1) % width == 0)
			printf("\n");
	}
}

void tree(string expression)
{
	expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());

	Expr expr = {};
	auto inputs = set<Input>();
	auto termInputs = multimap<Input, TermInput>();

	int inputYPos = 0;

	auto e = split(expression, "+");
	for (string term : e)
	{
		Term currTerm{};

		auto t = split(term, "*");
		for (string in : t)
		{
			bool neg = false;
			if (in.back() == '\'')
			{
				in.pop_back();
				neg = true;
			}

			Input currInput{ in };
			inputs.insert(currInput);

			TermInput ti{ currInput, inputYPos, neg };
			currTerm.push_back(ti);

			termInputs.insert(pair<Input, TermInput>{ in, ti });
			inputYPos++;
		}

		expr.push_back(currTerm);
		inputYPos++;
	}

	int height = inputs.size() + termInputs.size() + expr.size() - 1;
	int width = 0;
	width += max_element(inputs.begin(), inputs.end(), [](Input a, Input b) { return a.length() < b.length(); })->length() + 2;
	
	int inputWidth = width;
	width += inputs.size() * 2;

	int notAndStart = width;
	width += 7;
	width += expr.size() + 1;

	int orStart = width;
	width += 4;
	width += 4;
	width += expression.length();

	vector<char> matrix;
	matrix.resize((width * height) + 1);
	for (int i = 0; i < height * width; i++)
		matrix[i] = ' ';

	int baseY = inputs.size();

	{
		int x = width - 4 - expression.length();
		int y = baseY + ((height - baseY) / 2);
		put(matrix, width, height, x, y, repeat(HORIZ, 4) + expression, Direction::RIGHT);
	}

	{
		int x = orStart;
		int y = baseY + (height - baseY) / 2 - expr.size() / 2;
		if (expr.size() == 1)
			put(matrix, width, height, x, y, repeat(HORIZ, 4), Direction::RIGHT);
		else
		{
			put(matrix, width, height, x, y, repeat(HORIZ, expr.size()), Direction::DOWN);
			put(matrix, width, height, x + 1, y, repeat(VERT, expr.size()), Direction::DOWN);
			put(matrix, width, height, x + 2, y, repeat('O', expr.size()), Direction::DOWN);
			put(matrix, width, height, x + 3, y, repeat('R', expr.size()), Direction::DOWN);
		}
	}

	{
		int x = notAndStart;
		int y = baseY;
		for (Term t : expr)
		{
			string layer[7];
			for (TermInput ti : t)
			{
				layer[0] += HORIZ;
				layer[1] += (ti.neg ? '>' : HORIZ);
				layer[2] += (ti.neg ? 'o' : HORIZ);
				layer[3] += HORIZ;
				layer[4] += (t.size() > 1 ? VERT : HORIZ);
				layer[5] += (t.size() > 1 ? '&' : HORIZ);
				layer[6] += (t.size() > 1 ? '&' : HORIZ);
			}

			for (auto i = 0; i < 7; i++)
				put(matrix, width, height, x + i, y, layer[i], Direction::DOWN);

			y += t.size() + 1;
		}
	}

	{
		int x = 0;
		int y = 0;
		for (Input i : inputs)
		{
			string str = i + ": ";
			str += repeat(HORIZ, inputWidth - str.length());
			put(matrix, width, height, x, y, str, Direction::RIGHT);

			y++;
		}
	}

	{
		int x = inputWidth;
		int num = 0;
		int offset = inputs.size() * 2 - 1;
		for (Input in : inputs)
		{
			int y = 0;
			int len = inputs.size() * 2 - 1;
			auto it = inputs.find(in);
			while (it != inputs.begin())
			{
				it--;
				y++;
				len -= 2;
			}
			put(matrix, width, height, x, y, repeat(HORIZ, len) + LDOWN, Direction::RIGHT);
		}

		for (Input in : inputs)
		{
			auto yBreakRange = termInputs.equal_range(in);
			valarray<int> yBreaks(termInputs.count(in));
			int idx = 0;
			for (auto ti = yBreakRange.first; ti != yBreakRange.second; ti++)
				yBreaks[idx++] = baseY + ti->second.ypos;

			for (int y : yBreaks)
				put(matrix, width, height, x + offset, y, repeat(HORIZ, inputs.size() * 2 - offset), Direction::RIGHT);

			int y = num + 1;
			int maxBreak = yBreaks.max();
			string branch = repeat(VERT, maxBreak - y + 1);

			for (int i : yBreaks)
				branch[i - y] = RBRANCH;
			branch.back() = RUP;

			put(matrix, width, height, x + offset, y, branch, Direction::DOWN);

			offset -= 2;
			num++;
		}
	}

	{
		int x = notAndStart + 7;
		int outY = baseY + (height - baseY) / 2 - expr.size() / 2;
		int breakx = expr.size() / 2;

		for (Term t : expr)
		{
			int inY = baseY + (t.front().ypos + t.back().ypos) / 2;
			put(matrix, width, height, x, inY, repeat(HORIZ, abs(breakx) + 1), Direction::RIGHT);
			put(matrix, width, height, x + abs(breakx) + 1, outY, repeat(HORIZ, expr.size() - abs(breakx)), Direction::RIGHT);

			if (inY < outY)
			{
				string branch = LDOWN + repeat(VERT, outY - inY - 1) + RUP;
				put(matrix, width, height, x + abs(breakx) + 1, inY, branch, Direction::DOWN);
			}
			else if (inY > outY)
			{
				string branch = RDOWN + repeat(VERT, inY - outY - 1) + LUP;
				put(matrix, width, height, x + abs(breakx) + 1, outY, branch, Direction::DOWN);
			}

			outY++;
			breakx--;
		}
	}

	draw(matrix, width, height);
}

int main()
{
	tree("A'*B'+B*C");
	return 0;
}
