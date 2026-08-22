/*

Background
The newest version of the C standard, C23, adds preprocessor macros like INT_WIDTH, ULONG_WIDTH, and SIZE_WIDTH that tell you the bit width of various integer types (here, int, unsigned long, and size_t, respectively).
However, while the majority of us are stuck with pre-C23 compilers/standard libraries, it would still be nice to have these values available to us.

What we do have easy access to is the numerical limits of the integer types, e.g. INT_MAX, ULONG_MAX, and SIZE_MAX.
For unsigned types, these values are guaranteed to be of the form 2^n-1. If we could extract the n from numbers like this, that would give us the width of every (unsigned) integer type.

Objective
Your goal is to write a C preprocessor macro MAX_TO_WIDTH(m) which converts unsigned _MAX values to the corresponding _WIDTH value. More precisely, MAX_TO_WIDTH(2^n-1)=n for all n in a "reasonable" range (see below). For example, we need MAX_TO_WIDTH(255) == 8, MAX_TO_WIDTH(4294967295) == 32, etc. Your macro will not be called with other values, so MAX_TO_WIDTH(10) can return a garbage value, or even invalid code.

Because macro substitution works by pasting token sequences without evaluating them, fairly succinct macros can have very large expansions. Therefore, instead of golfing the macro itself, we will be golfing its output.

Rules
Your submission should be a C macro definition like

#define MAX_TO_WIDTH(m) ...
You may also define and use any helper macros you want to.

MAX_TO_WIDTH(m) must give the correct result for all m=2^n-1, n∈[1,128]. Most C preprocessors that I know of only handle up to 64-bit integers, but new architectures like CHERI will have 128-bit pointers (and thus MAX_TO_WIDTH(UINTPTR_MAX) == 128. You should verify that your implementation works up to at least 128 bits, for example by translating it to Python.

For valid inputs, your macro should produce an integer constant expression suitable for use in a preprocessor condition. That means things like this must work:

#if MAx_TO_WIDTH(255) == 8
switch (8) {
    case MAX_TO_WIDTH(255):
        break;
    default:
        assert(0);
}
#endif
The C preprocessor has slightly different rules than C itself for evaluating expressions (particularly around overflow). The result should be correct in either context. The test cases attempt to validate this for you.

Your macro must properly parenthesize its input and output. If you're unfamiliar with C, this means that macros like

#define FOO(x) 2 * x + 1
Are bad practice because 2 * FOO(1 + 1) expands to 2 * 2 * 1 + 1 + 1 (a.k.a. 6, not the desired 10). The macro should instead be written

#define FOO(x) (2 * (x) + 1)
The test cases attempt to validate this for you.

Testing
Add the following code after your macro definition to test it:

// Check validity in preprocessor conditions
#if 2 * MAX_TO_WIDTH(1 + 1 + 1) != 4
#error "Expected MAX_TO_WIDTH(3) == 2"
#endif

// Calculate (1 << n) - 1, without overflow
#define WIDTH_TO_MAX(n) ((((1ULL << ((n) - 1)) - 1) << 1) + 1)

// Check that MAX_TO_WIDTH() inverts WIDTH_TO_MAX()
#define ASSERT_WIDTH(n) _Static_assert(MAX_TO_WIDTH(WIDTH_TO_MAX(n)) == (n), "")

// Expands to ASSERT_WIDTH(1); ASSERT_WIDTH(2); ...; ASSERT_WIDTH(64); 
#define ASSERT_WIDTH_2(n)  ASSERT_WIDTH(2 * (n) - 1); ASSERT_WIDTH(2 * (n))
#define ASSERT_WIDTH_4(n)  ASSERT_WIDTH_2(2 * (n) - 1); ASSERT_WIDTH_2(2 * (n))
#define ASSERT_WIDTH_8(n)  ASSERT_WIDTH_4(2 * (n) - 1); ASSERT_WIDTH_4(2 * (n))
#define ASSERT_WIDTH_16(n) ASSERT_WIDTH_8(2 * (n) - 1); ASSERT_WIDTH_8(2 * (n))
#define ASSERT_WIDTH_32(n) ASSERT_WIDTH_16(2 * (n) - 1); ASSERT_WIDTH_16(2 * (n))
#define ASSERT_WIDTH_64()  ASSERT_WIDTH_32(1); ASSERT_WIDTH_32(2)
ASSERT_WIDTH_64();

int main(void) {
    int ret[] = {1, 1, 0};
    switch (2) {
        // Check validity as a constant expression
        case MAX_TO_WIDTH(3):
            // Check parenthesization
            return MAX_TO_WIDTH(3)[ret];
        default:
            return 1;
    }
}
The code should compile without errors (warnings are okay), and run successfully (returning 0), without invoking any undefined behaviour. If you save this code as golf.c, you can check it like this:

user@host$ clang -fsanitize=undefined golf.c -o golf && ./golf || echo FAIL
Scoring
Your score is the number of preprocessing tokens that the test code expands to using your MAX_TO_WIDTH() definition. Lower scores are better. You can use clang's -dump-tokens flag to determine this:

user@host$ clang -fsyntax-only -Xclang -dump-tokens golf.c 2>&1 | wc -l
13877
This score is insensitive to whitespace, comments, and name length, so there's no incentive to golf the implementation in a way that obfuscates it.

Extra credit
If you want, you can calculate the largest n for which your MAX_TO_WIDTH(2^n-1) would behave correctly (assuming a hypothetical C implementation with n-bit integers).
Remember, n must be at least 128, but it may be (significantly) higher.
Each n defines a "weight class" (so to speak) which includes all submissions with equal or greater n values.

*/

/*

@Tavian Barnes

This idea is due to Hallvard B. Furuseth on a comp.lang.c post in 2003. It uses this helper function

#define CHUNK(m, mask) (m) / ((m) % mask + 1) / mask % mask

Which is used to make a repeating sequence like this:

a[i, j]                       = CHUNK(2^i -1, 2^j -1)
a[0, j], a[1, j], a[2, j] ... = (0 ... 0 j times) (1 ... 1 j times) (2^j - 2 ... 2^j - 2 j times), 0, ...

You can play around with it in Python to see:

>>> def CHUNK(m, mask):
...     return (m) // ((m) % mask + 1) // mask % mask
...
>>> def a(i, j):
...     return CHUNK(2**i - 1, 2**j - 1)
...
>>> [a(i, 2) for n in range(10)]
[0, 0, 1, 1, 2, 2, 0, 0, 1, 1]
>>> [a(i, 3) for n in range(10)]
[0, 0, 0, 1, 1, 1, 2, 2, 2, 3]
>>> [a(i, 4) for n in range(10)]
[0, 0, 0, 0, 1, 1, 1, 1, 2, 2]
>>> [a(n, 5) for n in range(5 * (2**5 - 1))] == \
... [i for i in range(2**5 - 1) for j in range(5)]
True
This sequence has j(2^j-1) values before it wraps, meaning

CHUNK(2^i-1, 2^j-1) = ⌊i/j⌋ for all i<j (2^j - 1).

This is almost enough—what we want is j⌊i/j⌋+(i mod j)=i. We can get (i mod j) in various ways. For now, let's fix j=8. We know that 2^i(mod 2^8 - 1) will have period 8:

>>> [(2**i - 1) % 255 for i in range(16)]
[0, 1, 3, 7, 15, 31, 63, 127, 0, 1, 3, 7, 15, 31, 63, 127]
And we can brute force a linear interpolation of these that maps them to [0, 1, 2, ...]:

>>> [(7 - 86 // ((2**i - 1) % 255 + 12)) for i in range(16)]
[0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7]

*/

#define CHUNK(m, mask) ((m) / ((m) % (mask) + 1) / (mask) % (mask))
#define INTERP(m) (7 - 86 / ((m) % 255 + 12))
#define MAX_TO_WIDTH(m) (CHUNK(m, 255) * 8 + INTERP(m))

#if (2 * MAX_TO_WIDTH(1 + 1 + 1)) != 4
#error "Expected MAX_TO_WIDTH(3) == 2"
#endif

/* Calculate (1 << n) - 1, without overflow */
#define WIDTH_TO_MAX(n) ((((1ULL << ((n)-1)) - 1) << 1) + 1)

/* Check that MAX_TO_WIDTH() inverts WIDTH_TO_MAX() */
#define ASSERT_WIDTH(n) _Static_assert(MAX_TO_WIDTH(WIDTH_TO_MAX(n)) == (n), "")

/* Expands to ASSERT_WIDTH(1); ASSERT_WIDTH(2); ...; ASSERT_WIDTH(64); */
#define ASSERT_WIDTH_2(n)  ASSERT_WIDTH(2 * (n)-1); ASSERT_WIDTH(2 * (n))
#define ASSERT_WIDTH_4(n)  ASSERT_WIDTH_2(2 * (n)-1); ASSERT_WIDTH_2(2 * (n))
#define ASSERT_WIDTH_8(n)  ASSERT_WIDTH_4(2 * (n)-1); ASSERT_WIDTH_4(2 * (n))
#define ASSERT_WIDTH_16(n) ASSERT_WIDTH_8(2 * (n)-1); ASSERT_WIDTH_8(2 * (n))
#define ASSERT_WIDTH_32(n) ASSERT_WIDTH_16(2 * (n)-1); ASSERT_WIDTH_16(2 * (n))
#define ASSERT_WIDTH_64()  ASSERT_WIDTH_32(1); ASSERT_WIDTH_32(2)

ASSERT_WIDTH_64();

int
main(void)
{
	int ret[] = {1, 1, 0};
	switch (2) {
	/* Check validity as a constant expression */
	case MAX_TO_WIDTH(3):
		/* Check parenthesization */
		return MAX_TO_WIDTH(3)[ret];
	}
	return 1;
}
