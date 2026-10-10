/*

Introduction
I began studying the Collatz Conjecture

And noticed these patterns;
0,1,2,2,3,3...A055086, and 0,1,2,0,3,1...A082375,
in the numbers that go to 1 in one odd step,
5,10,20,21,40,42...A062052
Related like so;
A062052()(n) = ( 16*2^A055086(n) - 2^A082375(n) ) /3

The formula for A055086 is
floor(sqrt(4n + 1)) - 1

and the formula for A082375 is
floor(sqrt(4*floor(n) + 1)) - 1 - floor(0.5*(4*floor(x) + 1 - floor(sqrt(4*floor(x) + 1)

So the formula for A062052 most likely is

X=floor(sqrt(4*floor(n) + 1))
Y=floor(sqrt(4*floor(n) + 1)) - 1 - floor(0.5*(4*floor(x) + 1 - floor(sqrt(4*floor(x) + 1)

(8*2^X - 2^Y) / 3
Then I looked at numbers going to 1 in two steps, like 3,6,12,13,24,26...
Where I found another pattern that I could not find a formula for on OEIS

long nth(int n){if(n>241)return -1;return (((1<<Y[n]+5)-(1<<1+Y[n]-((Z[n]&1)+Z[n]*3)))/3-(1<<Y[n]-2*X[n]-(2*(Z[n]&1)+Z[n]*3)))/3;}
With X[],Y[] and Z[] being these lookup-tables

 int[]X=new int[]{
 0,
 0,
 0,  1,
 0,  1,
 0,  1,  2,
 0,  1,  2,                              0,
 0,  1,  2,  3,                          0,                          0,
 0,  1,  2,  3,                          0,  1,                      0,
 0,  1,  2,  3,  4,                      0,  1,                      0,  1,
 0,  1,  2,  3,  4,                      0,  1,  2,                  0,  1,
 0,  1,  2,  3,  4,  5,                  0,  1,  2,                  0,  1,  2,
 0,  1,  2,  3,  4,  5,                  0,  1,  2,  3,              0,  1,  2,                  0,
 0,  1,  2,  3,  4,  5,  6,              0,  1,  2,  3,              0,  1,  2,  3,              0,              0,
 0,  1,  2,  3,  4,  5,  6,              0,  1,  2,  3,  4,          0,  1,  2,  3,              0,  1,          0,
 0,  1,  2,  3,  4,  5,  6,  7,          0,  1,  2,  3,  4,          0,  1,  2,  3,  4,          0,  1,          0,  1,
 0,  1,  2,  3,  4,  5,  6,  7,          0,  1,  2,  3,  4,  5,      0,  1,  2,  3,  4,          0,  1,  2,      0,  1,
 0,  1,  2,  3,  4,  5,  6,  7,  8,      0,  1,  2,  3,  4,  5,      0,  1,  2,  3,  4,  5,      0,  1,  2,      0,  1,  2,
 0,  1,  2,  3,  4,  5,  6,  7,  8,      0,  1,  2,  3,  4,  5,  6,  0,  1,  2,  3,  4,  5,      0,  1,  2,  3,  0,  1,  2,      0,
 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  0,  1,  2,  3,  4,  5,  6,  0,  1,  2,  3,  4,  5,  6,  0,  1,  2,  3,  0,  1,  2,  3,  1, 2
 };
 int[]Y=new int[]{
 0,
 1,
 2,  2,
 3,  3,
 4,  4,  4,
 5,  5,  5,                              5,
 6,  6,  6,  6,                          6,                          6,
 7,  7,  7,  7,                          7,  7,                      7,
 8,  8,  8,  8,  8,                      8,  8,                      8,  8,
 9,  9,  9,  9,  9,                      9,  9,  9,                  9,  9,
10, 10, 10, 10, 10, 10,                 10, 10, 10,                 10, 10, 10,
11, 11, 11, 11, 11, 11,                 11, 11, 11, 11,             11, 11, 11,                 11,
12, 12, 12, 12, 12, 12, 12,             12, 12, 12, 12,             12, 12, 12, 12,             12,             12,
13, 13, 13, 13, 13, 13, 13,             13, 13, 13, 13, 13,         13, 13, 13, 13,             13, 13,         13,
14, 14, 14, 14, 14, 14, 14, 14,         14, 14, 14, 14, 14,         14, 14, 14, 14, 14,         14, 14,         14, 14,
15, 15, 15, 15, 15, 15, 15, 15,         15, 15, 15, 15, 15, 15,     15, 15, 15, 15, 15,         15, 15, 15,     15, 15,
16, 16, 16, 16, 16, 16, 16, 16, 16,     16, 16, 16, 16, 16, 16,     16, 16, 16, 16, 16, 16,     16, 16, 16,     16, 16, 16,
17, 17, 17, 17, 17, 17, 17, 17, 17,     17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,     17, 17, 17, 17, 17, 17, 17,     17,
18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18
};
int[]Z=new int[]{
0,
0,
0,  0,
0,  0,
0,  0,  0,
0,  0,  0,                              1,
0,  0,  0,  0,                          1,                          2,
0,  0,  0,  0,                          1,  1,                      2,
0,  0,  0,  0,  0,                      1,  1,                      2,  2,
0,  0,  0,  0,  0,                      1,  1,  1,                  2,  2,
0,  0,  0,  0,  0,  0,                  1,  1,  1,                  2,  2,  2,
0,  0,  0,  0,  0,  0,                  1,  1,  1,  1,              2,  2,  2,                  3,
0,  0,  0,  0,  0,  0,  0,              1,  1,  1,  1,              2,  2,  2,  2,              3,              4,
0,  0,  0,  0,  0,  0,  0,              1,  1,  1,  1,  1,          2,  2,  2,  2,              3,  3,          4,
0,  0,  0,  0,  0,  0,  0,  0,          1,  1,  1,  1,  1,          2,  2,  2,  2,  2,          3,  3,          4,  4,
0,  0,  0,  0,  0,  0,  0,  0,          1,  1,  1,  1,  1,  1,      2,  2,  2,  2,  2,          3,  3,  3,      4,  4,
0,  0,  0,  0,  0,  0,  0,  0,  0,      1,  1,  1,  1,  1,  1,      2,  2,  2,  2,  2,  2,      3,  3,  3,      4,  4,  4,
0,  0,  0,  0,  0,  0,  0,  0,  0,      1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,      3,  3,  3,  3,  4,  4,  4,      5,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  4,  4,  4,  4,  5, 5
};

Challenge
The challenge is to write a "reasonably fast" function or expression that replaces, and extends these lookup tables to index 719 or more.
Think of the lookup tables as a 3D structure of boxes. Pictured is the top 720 boxes of this structure.

https://i.stack.imgur.com/ZMois.png

Input
An integer which is the index of a cube in the structure. You can assume the input will be in the range 0 to 719 inclusive.

Output
The x,y,z coordinates for the given index. Assuming the input is between 0 and 719 the output ranges are x, 0 to 13 y, 0 to 27 z, 0 to 8

It's fine to accept and return larger indexes correctly just not required.

Examples
    i  ->   x   y   z
    0  ->   0,  0,  0
   12  ->   0,  5,  1
   30  ->   4,  8,  0
   65  ->   2, 11,  1
  100  ->   0, 13,  2
  270  ->   1, 19,  3
  321  ->   1, 20,  6
  719  ->   1, 27,  8
If you collapse the z-coordinate, then the structure is indexed top-down left right like shown below; Examples are marked in square brackets []

Y,Z 0,
 0   | [0]
 1   |  1
 2   |  2   3
 3   |  4   5
 4   |  6   7   8                                1,
 5   |  9  10  11                                 |[12]                           2,
 6   | 13  14  15  16                             | 17                             | 18
 7   | 19  20  21  22                             | 23  24                         | 25
 8   | 26  27  28  29 [30]                        | 31  32                         | 33  34
 9   | 35  36  37  38  39                         | 40  41  42                     | 43  44
10   | 45  46  47  48  49  50                     | 51  52  53                     | 54  55  56                    3,
11   | 57  58  59  60  61  62                     | 63  64 [65] 66                 | 67  68  69                     | 70                4,
12   | 71  72  73  74  75  76  77                 | 78  79  80  81                 | 82  83  84  85                 | 86                 | 87
13   | 88  89  90  91  92  93  94                 | 95  96  97  98  99             [100] 101 102 103                |104 105             |106
14   |107 108 109 110 111 112 113 114             |115 116 117 118 119             |120 121 122 123 124             |125 126             |127 128
15   |129 130 131 132 133 134 135 136             |137 138 139 140 141 142         |143 144 145 146 147             |148 149 150         |151 152
16   |153 154 155 156 157 158 159 160 161         |162 163 164 165 166 167         |168 169 170 171 172 173         |174 175 176         |177 178 179        5,
17   |180 181 182 183 184 185 186 187 188         |189 190 191 192 193 194 195     |196 197 198 199 200 201         |202 203 204 205     |206 207 208         |209    6,
18   |210 211 212 213 214 215 216 217 218 219     |220 221 222 223 224 225 226     |227 228 229 230 231 232 233     |234 235 236 237     |238 239 240 241     |242     |243
19   |244 245 246 247 248 249 250 251 252 253     |254 255 256 257 258 259 260 261 |262 263 264 265 266 267 268     |269[270]271 272 273 |274 275 276 277     |278 279 |280
20   |281 282 283 284 285 286 287 288 289 290 291 |292 293 294 295 296 297 298 299 |300 301 302 303 304 305 306 307 |308 309 310 311 312 |313 314 315 316 317 |318 319 |320[321]
  X->|  0   1   2   3   4   5   6   7   8   9  10 |  0   1   2   3   4   5   6   7 |  0   1   2   3   4   5   6   7 |  0   1   2   3   4 |  0   1   2   3   4 |  0   1 |  0   1
Note that at even y-coordinates the structure expands in the x-direction, and at 0 and 5 mod 6 in the z-direction.

Rules
This is code-golf, the shortest code in bytes wins.

Reasonably fast As an additional requirement although not a competition of fastest code,
the code must still be shown to compute coordinates in a reasonable amount of time.
 O(n)
 or less time-complexity with regards to index is valid by default

Alternatively may for example use try it online or similar website and run a loop through all coordinates under 720 without exceeding the time limit of a minute, printing is optional.
Any time-complexity is valid as long as actual time is reasonably low.

Lookup tables are allowed but included in byte-count so aim to make them sparse if you choose to use them.

Example code
EDIT: Look at Nick Kennedy's solution

Original example;

coord coords(int index){
int a=0,b=0,c=0;
int x=0,y=0,z=0;
long n,k,one;
n = k = 3;
int t=0;
while(t<index){
int s=0;k++;n=k;
while(n>1 && s<4){ n/=n&-n;n=n*3+1; n/=n&-n;s++;}
if(s==2)t++;
}
n=k;
one=n&-n;k = one;while(k>1){k>>=1;c++;} n=3*n+one;
one=n&-n;k = one;while(k>1){k>>=1;b++;} n=3*n+one;
one=n&-n;k = one;while(k>1){k>>=1;a++;}
coord r;
r.x = (b-c-1)>>1;
r.y = a-5;
r.z = (a-b-2)/6 +(a-b-4)/6;
return r;
}

Try it online! Note it's too slow!

*/

package main

type Coord struct {
	x, y, z int
}

func main() {
	tab := [][4]int{
		{0, 0, 0, 0},
		{12, 0, 5, 1},
		{30, 4, 8, 0},
		{65, 2, 11, 1},
		{100, 0, 13, 2},
		{270, 1, 19, 3},
		{321, 1, 20, 6},
		{719, 1, 27, 8},
	}
	for _, v := range tab {
		assert(coords(v[0]) == Coord{v[1], v[2], v[3]})
	}

	for i := 0; i <= 250; i++ {
		assert(coords(i) == coordsbf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func coordsbf(index int) Coord {
	var a, b, c, one int
	n, k := 3, 3
	for t := 0; t < index; {
		s := 0
		k++
		for n = k; n > 1 && s < 4; s++ {
			n /= n & -n
			n = n*3 + 1
			n /= n & -n
		}
		if s == 2 {
			t++
		}
	}

	n = k
	one = n & -n
	for k = one; k > 1; c++ {
		k >>= 1
	}

	n = 3*n + one
	one = n & -n
	for k = one; k > 1; b++ {
		k >>= 1
	}

	n = 3*n + one
	one = n & -n
	for k = one; k > 1; a++ {
		k >>= 1
	}

	return Coord{
		(b - c - 1) >> 1,
		a - 5,
		(a-b-2)/6 + (a-b-4)/6,
	}
}

// Ported from @Nick Kennedy solution
func coords(n int) Coord {
	var x, y, z int
	for i := 0; i < n; i++ {
		a := truth(2*x+1 < y-(z+1)/2*6+(z&1))
		b := truth(z < y/6+(y+1)/6)
		x = (x + 1) * a
		y += not(a | b)
		z += truth(b > a)
		z *= a | b
	}
	return Coord{x, y, z}
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}

func not(x int) int {
	return truth(x == 0)
}
