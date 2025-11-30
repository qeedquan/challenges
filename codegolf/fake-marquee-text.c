/*

In this challenge fake marquee text is text that is shown part by part, in a scrolling-like fashion.

Some examples:

testing 4

   t
  te
 tes
test
esti
stin
ting
ing
ng
g


hello 2

 h
he
el
ll
lo
o


foobarz 3

  f
 fo
foo
oob
oba
bar
arz
rz
z


Something a bit longer 10

         S
        So
       Som
      Some
     Somet
    Someth
   Somethi
  Somethin
 Something
Something
omething a
mething a
ething a b
thing a bi
hing a bit
ing a bit
ng a bit l
g a bit lo
 a bit lon
a bit long
 bit longe
bit longer
it longer
t longer
 longer
longer
onger
nger
ger
er
r


small 15

              s
             sm
            sma
           smal
          small
         small
        small
       small
      small
     small
    small
   small
  small
 small
small
mall
all
ll
l


aaa 3

  a
 aa
aaa
aa
a


brace yourself 6

     b
    br
   bra
  brac
 brace
brace
race y
ace yo
ce you
e your
 yours
yourse
oursel
urself
rself
self
elf
lf
f
You have to write a program or a function that takes in two input and prints the output as described above. You may or may not output trailing spaces in your output. This is code-golf so shortest code in bytes wins.

If your program is standalone (i.e. when run actually prints the lines) (Input can be hard-coded but easy to change) and sleeps a bit between each line of output you get a -10 bonus.

*/

#include <stdio.h>

void
marquee(const char *s, int n)
{
	int i;

	if (n < 1)
		return;

	printf("%s %d\n", s, n);
	for (i = n; *s;) {
		printf("%*s%.*s\n", i, "", n - i, s);
		if (i != 0)
			i -= 1;
		else
			s += 1;
	}
	printf("\n");
}

int
main(void)
{
	marquee("testing", 4);
	marquee("hello", 2);
	marquee("foobarz", 3);
	marquee("Something a bit longer", 10);
	marquee("small", 15);
	marquee("aaa", 3);
	marquee("brace yourself", 6);

	return 0;
}
