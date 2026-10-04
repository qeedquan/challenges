/*

A JAPH is a grand tradition of making a program that prints "Just another Perl hacker,". We already have a question about JAPH on this site but they seem more concerned with hiding the text, but JAPH has always been more about hiding the method by which it does what it does. Therefore I challenge you to show off your favorite language's cool features, and don't worry too much about hiding the text (unless you want to).

Here's mine, in Perl, which shouldn't be to hard for an experienced velociraptor to understand, but may be interesting for others.

(*STORE,*TIESCALAR)=map{eval"sub{$_}"}qw'map{print&&sleep$|}split//,pop bless\$|++';tie$t,main;$t="Just another Perl hacker,\n"
Judged subjectively on votes by you guys, lets see some mind-benders!

*/

#include <stdio.h>

int
main()
{
	puts("Just another C hacker");
	return 0;
}
