/*

To write this function, you must be familiar with static arrays and the char primitive datatype.

The DRYAD field encryption forms require that the operator have ready access to pairs of unique pairs of letters.

Write a function that prints rows × columns unique pairs of randomly generated uppercase letters with the signature:

void print_unique_pairs( unsigned int rows, unsigned int columns );
The pairs should be separated by a single space.

For example, given the arguments 20 and 5, your output should look like

BU QC LJ JI VS
WM DK QT BX IX
MV TR RB JL PT
NS NF WZ QF MJ
AF AD RR WS OF
SB CN UV QH FF
BS AQ XW PQ CA
CE HC HZ VF RK
ML NO ZJ KP QP
XR JX KI TZ YX
NW LR BB MQ BH
CJ AR ZO WK KY
HI DD QS CD RX
JM OW FR XS JY
BL DB EF SA RC
BY NE CG YG GX
XP KL OR EL LN
MP AP EQ KX HO
PK MC OQ HN WN
KU EW HS QM GB
You can create a random integer using the std::rand() function, which is automatically included in the standard library. This function returns a value between 0 and MAX_RAND inclusive. This can be mapped onto a random number between 0 and 25 using the remainder operator.

Important: You cannot simply generate the requisite number of random pairs, for as you generate more and more random pairs, it becomes almost certain that there will be a duplicate.

Number
generated	Likelihood
of uniqueness
  10	93.5%
  20	75%
  30	52%
  40	31%
100	  0.044%
200	  0.0000000000005382310765%

Therefore, it would have been very unlikely (one in 2232) to generate the above 100 random pairs without repetition if additional steps were not taken to ensure uniqueness. It would be essentially impossible (one in 186 trillion) to generate 200 random pairs without repetition.

Improving your code
1. You will notice that if you re-run your code, it generates the same random pairs. This is because random number generators are actually pseudo-random number generates that rely on arithmetic operations to come up with the sequence of pseudo-random numbers. You can pass a third argument that becomes an argument to the std::srand function that sets the seed for the function std::rand().

2. The function rand() does not produce very good random numbers, as patterns emerge after many iterations. If you wish, check out the random library for finding better tools for generating random integers.

References
pseudo-random numbers at Wikipedia.
std::rand at cplusplus.com.
std::srand at cplusplus.com.
The random library at cplusplus.com.

*/

#include <iostream>
#include <string>
#include <map>
#include <random>

using namespace std;

int pairs(unsigned rows, unsigned cols)
{
	map<string, bool> seen;
	random_device rng;
	uniform_int_distribution<int> dis('A', 'Z');
	auto status = 0;
	for (unsigned row = 0; row < rows; row++)
	{
		for (unsigned col = 0; col < cols; col++)
		{
			string key;
			key += dis(rng);
			key += dis(rng);
			if (seen.find(key) != seen.end())
				status = -1;
			else
				seen.insert(pair<string, bool>(key, true));

			cout << key << " ";
		}
		cout << endl;
	}
	cout << endl;

	return status;
}

int main()
{
	pairs(20, 5);
	pairs(20, 5);
	return 0;
}
