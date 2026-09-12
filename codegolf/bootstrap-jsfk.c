/*

In Javascript you can recover the complete language using only the symbols ()[]!+. Here's the basics:

false       =>  ![]
true        =>  !![]
undefined   =>  [][[]]
NaN         =>  +[![]]
0           =>  +[]
1           =>  +!+[]
2           =>  !+[]+!+[]
10          =>  [+!+[]]+[+[]]
Array       =>  []
Number      =>  +[]
String      =>  []+[]
Boolean     =>  ![]
Function    =>  []["filter"]
eval        =>  []["filter"]["constructor"]( CODE )()
window      =>  []["filter"]["constructor"]("return this")()
That's great and all, but where did they get those first 6 characters from? I think it's best we help them out.

Simply write a program or function that outputs (at least) the 6 characters []()!+ in any order you want, as many times as you want, with as many other characters in between as you want. Shortest code wins. Gold star if you use less than 6 unique characters to do so.

*/

#include <stdio.h>

int
main(void)
{
	puts("[]()!+");
	return 0;
}
