/*

If you consider the following PHP+C polyglot snippet, there is a problem regarding class property access in the printf call:

#include <stdio.h>
#include <stdlib.h>
#define class struct
#define function 

class Point {
#define public int
    public $x;
    public $y;
};

int
function main()
{
    struct Point*
    $p = alloca(sizeof(struct Point));
    printf("%d", $p->x);  // PHP expects $p->x, but C expects $p->$x
    return 0;
}
My question is, how to resolve this in a neat manner? Possible solutions:

Remove all $ via sed before compiling with gcc
Define public $x as int x using #if __PHP__
Edit: Use getters, maybe? (works in C by passing self as first argument with function pointers)
Trying to define dollar sign as empty space does not work:

#define $ 
Any other ideas? I am also considering using m4 in the C Makefile. Thank you. :)

*/

#include <stdio.h>
#include <stdlib.h>

#define class struct
#define function
#define public int
#define x $x

class Point
{
	public $x;
	public $y;
};

int
function main()
{
	struct Point $p[1];

	$p->x = 0;
	printf("%d\n", $p->x);
	return 0;
}
