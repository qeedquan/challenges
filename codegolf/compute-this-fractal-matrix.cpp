/*

The unique-disjointness matrix ( UDISJ(n) ) is a matrix on all pairs of subsets of {1...,n} with entries

U(A, B) = 0, if |A intersect B| = 1
          1, otherwise

Or a bit less mathematical, it is the 2n times 2n matrix with a 0 in all entries where both indices have exactly one common 1 bit in their binary representation and a 1 in all other entries.

Example:
      0   1  10  11  100 101 110 111
     _______________________________
0   | 1   1   1   1   1   1   1   1
1   | 1   0   1   0   1   0   1   0
10  | 1   1   0   0   1   1   0   0
11  | 1   0   0   1   1   0   0   1
100 | 1   1   1   1   0   0   0   0
101 | 1   0   1   0   0   1   0   1
110 | 1   1   0   0   0   0   1   1
111 | 1   0   0   1   0   1   1   1
Write a program or function that takes an integer n as input and outputs the corresponding 2^n×2^n matrix.

Rules:

The values in the matrix can either be 0 / 1 (as numbers) or truthy/falsey
You are not allowed to permute the rows/columns of the matrix
This is code-golf the shortest solution (per language) wins
Your solution only needs to handle n between 2 and 10 (inclusive)
First 4 elements:

n=1:
1 1
1  

n=2:

1 1 1 1
1   1  
1 1    
1     1

n=3:

1 1 1 1 1 1 1 1
1   1   1   1  
1 1     1 1    
1     1 1     1
1 1 1 1  
1   1     1   1     
1 1         1 1
1     1   1 1 1

n=4:
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1   1   1   1   1   1   1   1   
1 1     1 1     1 1     1 1     
1     1 1     1 1     1 1     1 
1 1 1 1         1 1 1 1         
1   1     1   1 1   1     1   1 
1 1         1 1 1 1         1 1 
1     1   1 1 1 1     1   1 1 1 
1 1 1 1 1 1 1 1                 
1   1   1   1     1   1   1   1 
1 1     1 1         1 1     1 1 
1     1 1     1   1 1 1   1 1 1 
1 1 1 1                 1 1 1 1 
1   1     1   1   1   1 1 1 1 1 
1 1         1 1     1 1 1 1 1 1 
1     1   1 1 1   1 1 1 1 1 1 1 

*/

#include <cstdio>
#include <bit>

using namespace std;

typedef unsigned long long uvlong;

void matrix(uvlong n)
{
	uvlong s = 1ULL << n;
	printf("n=%llu\n", n);
	for (uvlong y = 0; y < s; y++)
	{
		for (uvlong x = 0; x < s; x++)
		{
			if (popcount(x & y) == 1)
				printf("  ");
			else
				printf("1 ");
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	for (uvlong i = 1; i <= 4; i++)
		matrix(i);

	return 0;
}
