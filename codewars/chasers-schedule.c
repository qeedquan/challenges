/*

A runner, who runs with base speed s with duration t will cover a distances d: d = s * t
However, this runner can sprint for one unit of time with double speed s * 2
After sprinting, base speed s will permanently reduced by 1, and for next one unit of time runner will enter recovery phase and can't sprint again.

Your task, given base speed s and time t, is to find the maximum possible distance d.

Input:
1 <= s < 1000
1 <= t < 1000

Example:
Given s = 2 and t = 4.
We could schedule when runner should sprint so we could get these possible sequences:

Seq.: RRRR
=> s + s + s + s
=> 2 + 2 + 2 + 2 = 8
Seq.: RRRS
=> s + s + s + s*2
=> 2 + 2 + 2 + 2*2 = 10
Seq.: RRSR
=> s + s + s*2 + (s-1)
=> 2 + 2 + 2*2 + (2-1) = 9
Seq.: RSRR
=> s + s*2 + (s-1) + (s-1)
=> 2 + 2*2 + (2-1) + (2-1) = 8
Seq.: RSRS
=> s + s*2 + (s-1) + (s-1)*2
=> 2 + 2*2 + (2-1) + (2-1)*2 = 9
Seq.: SRRR
=> s*2 + (s-1) + (s-1) + (s-1)
=> 2*2 + (2-1) + (2-1) + (2-1) = 7
Seq.: SRRS
=> s*2 + (s-1) + (s-1) + (s-1)*2
=> 2*2 + (2-1) + (2-1) + (2-1)*2 = 8
Seq.: SRSR
=> s*2 + (s-1) + (s-1)*2 + (s-1-1)
=> 2*2 + (2-1) + (2-1)*2 + (2-1-1) = 7

Where:
- R: Normal Run / Recovery
- S: Sprint
Based on above sequences, the maximum possible distance d is 10.

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
solve(int speed, int time)
{
	int boost;

	boost = min((speed / 3) + 1, (time + 1) / 2);
	return ((time + boost) * speed) - (boost * (boost - 1) * 3) / 2;
}

int
main()
{
	assert(solve(1, 1) == 2);
	assert(solve(4, 3) == 17);
	assert(solve(2, 4) == 10);
	assert(solve(22, 10) == 300);
	assert(solve(49, 50) == 2875);
	return 0;
}
