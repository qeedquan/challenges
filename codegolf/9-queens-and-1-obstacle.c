/*

Position 9 queens and 1 obstacle on an 8×8 chessb so that no two queens threaten each other. Obstacles between two queens prevent them from threatening each other.

For example here is a solution (Q is a queen, X is the obstacle, . is empty):

......Q.
...Q....
Q.......
..QXQ...
.......Q
.....Q..
...Q....
.Q......
There's more than one solution. Output all of them. Reflections/rotations are treated different solutions.

Shortest code in each language wins. You can choose any 3 symbol/number to mean space, queen and obstacle. Output multiline string, 2D array or whatever.

Here is a valid ungolfed solution.

#include <stdio.h>

#include <bitset>
typedef std::bitset<128> btt;
btt blk;
void search(btt board, btt banned, const signed char* pos) {
    // printf("dbg %016lX %016lX,%016lX %016lX\n", board, banned);
    if (*pos == -1) {
        for (int i = 0; i < 72; ++i)
            putchar(i % 9 == 8 ? '\n' : blk[i] ? 'X' : board[i] ? 'Q' : '.');
        putchar('\n');
        return;
    }
    for (int i = *pos; i != pos[1]; ++i)
        if (!banned[i]) {
            btt bo2 = board;
            btt ba2 = banned;
            bo2[i] = 1;
            for (int d : {1, 8, 9, 10}) {
                int np = i;
                do {
                    ba2[np] = 1;
                    np += d;
                } while (!blk[np]);
            }
            search(bo2, ba2, pos + 2);
        }
}
int main() {
    for (int i = 1; i < 4; ++i)
        for (int j = 1; j <= i; ++j) {
            signed char buf[64];
            int w = 0;
            for (int k = 0; k < 8; ++k)
                if (k != i)
                    buf[w++] = 9 * k, buf[w++] = 9 * k + 8;
                else
                    buf[w++] = 9 * k, buf[w++] = 9 * k + j,
                    buf[w++] = 9 * k + j + 1, buf[w++] = 9 * k + 8;
            buf[w] = -1;
            for (int k = 0; k < 81; ++k)
                blk[k] = k % 9 == 8 || k / 9 == 8 || k == i * 9 + j;
            search(0, 0, buf);
        }
}

Sandbox Notes
If 9 queen strategy differ enough from 10 queen strat, then I'll later pt a 10 queen question

*/

#include <stdio.h>
#include <string.h>

typedef signed char schar;

typedef schar Board[128];

void
show(Board blk, Board brd)
{
	int i;

	for (i = 0; i < 72; i++) {
		if (i % 9 == 8)
			printf("\n");
		else if (blk[i])
			printf("X");
		else if (brd[i])
			printf("Q");
		else
			printf(".");
	}
	printf("\n");
}

void
gen(Board blk, schar pos[], int i, int j)
{
	int k;

	for (k = 0; k < 8; k++) {
		if (i != k) {
			*pos++ = 9 * k;
			*pos++ = (9 * k) + 8;
		} else {
			*pos++ = 9 * k;
			*pos++ = (9 * k) + j,
			*pos++ = (9 * k) + j + 1;
			*pos++ = (9 * k) + 8;
		}
	}
	*pos = -1;

	for (k = 0; k < 81; k++) {
		blk[k] = 0;
		if (k % 9 == 8 || k / 9 == 8 || k == (i * 9) + j)
			blk[k] = 1;
	}
}

void
search(Board blk, Board brd, Board ban, schar pos[])
{
	static const int dir[] = { 1, 8, 9, 10 };

	Board brd2, ban2;
	int i, j;
	int d, p;

	if (pos[0] < 0) {
		show(blk, brd);
		return;
	}

	for (i = pos[0]; i != pos[1]; i++) {
		if (ban[i])
			continue;

		memcpy(brd2, brd, sizeof(brd2));
		memcpy(ban2, ban, sizeof(ban2));
		brd2[i] = 1;

		for (j = 0; j < 4; j++) {
			d = dir[j];
			p = i;
			do {
				ban2[p] = 1;
				p += d;
			} while (!blk[p]);
		}
		search(blk, brd2, ban2, pos + 2);
	}
}

int
main()
{
	Board brd, ban, blk;
	schar pos[64];
	int i, j;

	memset(blk, 0, sizeof(blk));
	memset(pos, 0, sizeof(pos));
	for (i = 1; i < 4; i++) {
		for (j = 1; j <= i; j++) {
			memset(brd, 0, sizeof(brd));
			memset(ban, 0, sizeof(ban));
			gen(blk, pos, i, j);
			search(blk, brd, ban, pos);
		}
	}
	return 0;
}
