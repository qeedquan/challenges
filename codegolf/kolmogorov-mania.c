/*

The Kolmogorov complexity of a string s is defined as the length of the shortest program P that outputs s. If the length of P is shorter than the length of s, then s is said to be compressible, otherwise s is incompressible. Most strings are incompressible ...

Write the shortest program that outputs this string (without spaces and without newlines):

d9 a6 b6 33 56 a7 95 4b 29 b0 ac 7f 2a aa 6d 19 b8 4b 4c f8 b6 2a ac 95
a1 4b 4e a5 9d b3 e7 c9 4c 49 59 ec 94 b3 aa 6c 93 8f 11 5a 4d 39 75 82
ec ea 24 cc d3 2d c3 93 38 4e b7 a6 0d d2 b5 37 23 54 ad 1b 79 aa 6e 49
55 52 94 5a a7 3a 6a e9 e4 52 cd 2d 79 ad c6 12 b5 99 5b b4 76 51 17 4e
94 f3 9a a2 e7 15 6a 55 14 4d 4e 4a a3 5c 2f ab 63 cc b5 a6 a4 92 96 8a
2e c3 d8 88 9b 8c a9 16 f5 33 22 5b a2 e2 cc 1b 27 d4 e8 db 17 a4 39 85
ca aa 5b 4f 36 24 d3 c6 f6 94 ad d7 0f 71 24 e1 b1 c5 ef 65 35 6c 8d d7
1a 87 1e 25 df 5d c0 13 b2 6f 5a 57 28 98 bd 41 66 04 ed a2 52 c9 ac 83
b3 6c 56 7e d1 c6 cc 53 4a 62 c5 59 a9 b2 d4 af 22 a5 a9 f4 b2 99 23 32
f8 fb ae 48 6a 8a 9a b5 46 7a 36 59 9f 92 d3 25 b5 19 bd 8a 4a 49 62 a5
e4 59 fb e5 ba a2 35 dd a9 36 1d a9 c9 69 89 77 6a b2 34 2d 1d 22 61 c5
c2 66 1c e2 76 74 52 a5 d9 84 b9 8a a6 b5 14 ec 29 58 b2 bc 96 16 16 48
f5 c5 bd 2f 32 1b 3d 4f 4b 2e b2 6b 9a d9 32 a4 4b 5c bc 92 b7 b3 26 39
fa 42 2d 64 ed 1a 79 49 4c a3 b7 85 b2 a6 e2 8c d9 55 90 e1 a8 87 4b 60
a6 e1 ba c4 bb ec 32 39 76 90 a6 b4 c6 65 79 61 91 aa 3d 54 b7 18 3d 15
4b 06 db 30 8a 4d 4a a1 35 75 5d 3b d9 98 ac 55 5b 10 dd b3 e2 cc f1 5e
b3 2b 53 90 b6 ee 2b ac 8f 88 8d 95 5a 75 df 59 2d 1c 5a 4c e8 f4 ea 48
b9 56 de a0 92 91 a9 15 4c 55 d5 e9 3a 76 8e 04 ba e7 b2 aa e9 ab 2a d6
23 33 45 3d c4 e9 52 e3 6a 47 50 ba af e4 e5 91 a3 14 63 95 26 b3 8b 4c
bc aa 5a 92 7a ab ad a6 db 53 2e 97 06 6d ba 3a 66 49 4d 95 d7 65 c2 aa
c3 1a 92 93 3f ca c2 6c 2b 37 55 13 c9 88 4a 5c 62 6b a6 ae cc de 72 94
The output should look like:

d9a6b63356a7954b29b0ac7f2aaa6d19b84b4cf8b62aac95a14b4e...7294
Note: no user input is allowed, nor web access, nor libraries (except the one required for printing the output).

Edit I: the sequence seems random ... but it turns out to be highly compressible handling a little bit of prime numbers ...

Edit II: Well done! I'll review the answers in the next hours, then assign the bounty. This is my idea on how it could be solved:

If you try to compress the data you don't go far away ...
In internet you can find the (well-known?) On-Line Encyclopedia of Integer Sequences (OEIS) ;
trying the first hexadecimal digits d9, a6, b6, 33, ... (or their decimal representation) give no result;
but if you convert the numbers to binary (1,1,0,1,1,0,0,1,1,0,1,0,0,1,1,0) and searching them on OEIS, you get this result.
As noted by Claudiu, I also gave a little hint in the question (Edit I above) ... :-)
The winner is: Peter Taylor (GolfScript, 50), with a special mention for Claudiu (Python, 92), the first who "solved" it.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char cert[] = "d9a6b63356a7954b29b0ac7f2aaa6d19b84b4cf8b62aac95a14b4ea59db3e7c94c4959ec94b3aa6c938f115a4d397582ecea24ccd32dc393384eb7a60dd2b5372354ad1b79aa6e495552945aa73a6ae9e452cd2d79adc612b5995bb47651174e94f39aa2e7156a55144d4e4aa35c2fab63ccb5a6a492968a2ec3d8889b8ca916f533225ba2e2cc1b27d4e8db17a43985caaa5b4f3624d3c6f694add70f7124e1b1c5ef65356c8dd71a871e25df5dc013b26f5a572898bd416604eda252c9ac83b36c567ed1c6cc534a62c559a9b2d4af22a5a9f4b2992332f8fbae486a8a9ab5467a36599f92d325b519bd8a4a4962a5e459fbe5baa235dda9361da9c96989776ab2342d1d2261c5c2661ce2767452a5d984b98aa6b514ec2958b2bc96161648f5c5bd2f321b3d4f4b2eb26b9ad932a44b5cbc92b7b32639fa422d64ed1a79494ca3b785b2a6e28cd95590e1a8874b60a6e1bac4bbec32397690a6b4c665796191aa3d54b7183d154b06db308a4d4aa135755d3bd998ac555b10ddb3e2ccf15eb32b5390b6ee2bac8f888d955a75df592d1c5a4ce8f4ea48b956dea09291a9154c55d5e93a768e04bae7b2aae9ab2ad62333453dc4e952e36a4750baafe4e591a314639526b38b4cbcaa5a927aabada6db532e97066dba3a66494d95d765c2aac31a92933fcac26c2b375513c9884a5c626ba6aeccde7294";

/*

@Claudiu

Marzio left a clever hint by saying that "it turns out to be highly compressible handling a little bit of prime numbers".
I was sure the "little bit" wasn't italicized by accident, so I converted the hex string to bits and tried to find patterns.
I thought that at first he was representing all the primes as bits and concatenating them together, but that didn't work out.
Then maybe taking only a few digits, or dropping all the zeroes in the bit string - still no.
Maybe it's a bitstring of the least-significant-bit of the first few primes? Not quite.
But eventually I found the one that worked - it's a bitstring of the second-least-significant bit from the first however-many primes.

*/

void
solve(char *s)
{
	int i, n;
	int p, q;

	p = q = 0;
	for (n = 1; q < 4032; n++) {
		i = 2;
		while (i < n && n % i)
			i++;

		if (i == n) {
			p += p + ((n & 2) >> 1);
			if (!(++q & 3)) {
				s += sprintf(s, "%x", p);
				p = 0;
			}
		}
	}
}

int
main()
{
	char s[1024];

	solve(s);
	assert(!strcmp(s, cert));

	return 0;
}
