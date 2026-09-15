/*

Note: This challenge was inspired by Joe Z's many excellent questions surrounding NAND golfing.

Description
Your goal in this challenge, should you choose to accept it, is to implement a very simple ALU using just NAND gates. The ALU can only perform the the following four operations:

00, meaning increment (wrapping at 15).
01, meaning decrement (wrapping at 0).
10, meaning logical left shift.
11, meaning return zero.
Your circuit should take six inputs and give four outputs. Inputs I0 and I1 denote the operation. Inputs I2 through I5 denote the value to be operated on. Outputs O0 through O3 denote the output value.

Scoring
Your score is the number of gates you utilize to create this circuit. Lower is better.

Test cases
I0-I1	I2-I5	O0-O3
00	0001	0010
01	0000	1111
10	0100	1000
10	0011	0110
11	1100	0000

*/

#include <cassert>

int NAND(int A, int B)
{
	return ~(A & B);
}

int NOT(int A)
{
	return NAND(A, A);
}

int AND(int A, int B)
{
	return NOT(NAND(A, B));
}

int XOR(int A, int B)
{
	auto C = NAND(A, B);
	return NAND(NAND(C, A), NAND(C, B));
}

int XAX(int A, int B, int C)
{
	return NOT(NAND(NAND(NAND(NOT(A), B), NAND(C, A)), NAND(C, B)));
}

/*

@ovs

First define a few additional boolean operations in terms of NAND:

NOT(x)     := NAND(x,x)                           # 1 NAND
AND(a,b)   := NOT(NAND(a,b))                      # 2 NANDs
XOR(a,b)   := NAND(NAND(t=NAND(a,b),a),NAND(t,b)) # 4 NANDs

# AND(XOR(a,b), XOR(c,b)) in 7 NANDs:
XAX(a,b,c) := NOT(NAND(NAND(NAND(NOT(a), b), NAND(c, a)), NAND(c, b)))
Then we can define the ALU with these operations:

ni0    = NOT(i0)
ni1    = NOT(i1)
double = AND(i0,ni1)
o3     = AND(ni0,NOT(i5))
o2     = NAND(NAND(double,i5), NAND(ni0,XOR(XAX(o3,i5,i1),i4)))
o1     = NAND(NAND(double,i4), NAND(ni0,XOR(XAX(o2,i4,i1),i3)))
o0     = NAND(NAND(double,i3), NAND(ni0,XOR(XAX(o1,i3,i1),i2)))

This uses 9 NANDs, 3 NOTs, 2 ANDs, 3 XORs and 3 XAXs for a total of 49 NAND gates.

There is one gate that could be saved by removing some of the abstraction (we could get NOT(o3) for free and use that in the first XAX), but until I find some larger improvement I'd like to keep it simple.

The logic for the three higher bits might seem a bit intimidating, but with some transformations it is actually not bad:
NAND(NAND(...), NAND(...)) is equivalent to OR(AND(...), AND(...)). The left AND reads "operation is double and the bit to right in the input is set",
and the right one flips the bit if XAX(new value of bit to the right, old value of bit to the right, decrement) evaluates to 1. And XAX(a,b,c) is equivalent to a>b if c else a<b.

*/

void ALU(int i0, int i1, int i2, int i3, int i4, int i5, int &o0, int &o1, int &o2, int &o3)
{
	auto ni0 = NOT(i0);
	auto ni1 = NOT(i1);
	auto db = AND(i0, ni1);
	o3 = AND(ni0, NOT(i5)) & 1;
	o2 = NAND(NAND(db, i5), NAND(ni0, XOR(XAX(o3, i5, i1), i4))) & 1;
	o1 = NAND(NAND(db, i4), NAND(ni0, XOR(XAX(o2, i4, i1), i3))) & 1;
	o0 = NAND(NAND(db, i3), NAND(ni0, XOR(XAX(o1, i3, i1), i2))) & 1;
}

void test(int in, int out)
{
	auto i0 = (in >> 5) & 1;
	auto i1 = (in >> 4) & 1;
	auto i2 = (in >> 3) & 1;
	auto i3 = (in >> 2) & 1;
	auto i4 = (in >> 1) & 1;
	auto i5 = (in >> 0) & 1;

	int o0, o1, o2, o3;
	ALU(i0, i1, i2, i3, i4, i5, o0, o1, o2, o3);

	auto val = (o0 << 3) | (o1 << 2) | (o2 << 1) | o3;
	assert(val == out);
}

int main()
{
	test(0b000001, 0b0010);
	test(0b010000, 0b1111);
	test(0b100100, 0b1000);
	test(0b100011, 0b0110);
	test(0b111100, 0b0000);

	return 0;
}
