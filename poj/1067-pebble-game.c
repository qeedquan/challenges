/*

Description

有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。

Input

输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，表示两堆石子的数目，a和b都不大于1,000,000,000。

Output

输出对应也有若干行，每行包含一个数字1或0，如果最后你是胜者，则为1，反之，则为0。

Sample Input

2 1
8 4
4 7
Sample Output

0
1
0

Source

NOI

*/

#include <assert.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

// https://en.wikipedia.org/wiki/Wythoff%27s_game
int
winner(int a, int b)
{
	static const double PHI = 1.61803398875;

	if (a > b)
		swap(&a, &b);
	b = (b - a) * PHI;
	return a != b;
}

int
main(void)
{
	assert(winner(2, 1) == 0);
	assert(winner(8, 4) == 1);
	assert(winner(4, 7) == 0);

	return 0;
}
