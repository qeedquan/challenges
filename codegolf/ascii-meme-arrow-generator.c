/*

Specifications
Given a number n, output an ASCII "meme arrow" (greater-than symbol, >) of size n.

n will always be a positive integer, greater than 0.

Examples
n = 2

\
 \
 /
/
n = 5

\
 \
  \
   \
    \
    /
   /
  /
 /
/
Sample code
Here is a sample program, written in Crystal, that returns the correct results. Run it as ./arrow 10.

arrow.cr:

def f(i)
        i.times { |j|
                j.times { print ' ' }
                puts "\\"
        }
        i.times { |j|
                (i-j-1).times { print ' ' }
                puts '/'
        }
end

f(ARGV[0].to_i)

Rules
This is code-golf. The shortest answer wins. However, I will not select an answer, because the shortest answer may change over time.
Standard loopholes are not allowed.

*/

#include <stdio.h>

void
arrow(int n)
{
	int i, j;

	printf("n=%d\n", n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			putchar(' ');
		puts("\\");
	}

	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < i; j++)
			putchar(' ');
		puts("/");
	}
	puts("");
}

int
main(void)
{
	arrow(2);
	arrow(5);

	return 0;
}
