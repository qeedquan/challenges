/*

The challenge is to write a fake infinite loop in any imperative programming language.

At first sight, the code should seem not to halt at all.

As a naive example:

int f(int x)
{
    return f(4.0);
}

int f(double x)
{
    return 0;
}
But remember
You're not allowed to use overflows:

int f(int x)
{
    if(x < 0) return -1;
    return f(x*x);
}
is illegal. When the number exceeds the integer limit, the function will stop. It's a good trick. But not good enough :)

*/

int f(int);
double f(double);

int f(int x)
{
	return f(x * 2.0);
}

double f(double x)
{
	return (x < 0) ? 0 : f(x - 1);
}

int main()
{
	return f(10);
}
