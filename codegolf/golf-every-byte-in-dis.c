/*

Write a program in Dis language (Ben Olmstead, 1998) that takes no input and output every byte at least once, in any order. Your program doesn't have to halt. Shortest code wins.

Implementations for Dis
https://web.archive.org/web/20220817101756/https://mirrors.talideon.com/articles/malbolge/dis.html
https://tpaefawzen.github.io/dis.web/
https://iy5dvsjabeev.hatenablog.jp/entry/2026/04/06/130619

*/

#include <stdio.h>

/*

@izzyg

Here's the repository of the code I wrote while creating this answer.

While not required, the program prints all 256 unique bytes in order from 1 to 255, then 0, then halts afterwards.

This program can be divided into the "code region" and the "data region". The "code region" is the first 44 bytes, and only code within that region is executed. The "data region" encodes each output byte from 1 to 255 using 7 bytes of source code, for an overall code length of 44+7*255=1829 bytes. Outputting 0 at the end is free, due to the way that memory is initialized in Dis.

To write this program, I started with the single working Dis program I could find, the cat program written by the language author on the language's Esolangs page.

I was having some trouble understanding how the cat program worked, so I modded the dis.web interpreter to add some console logging, which made things easier. See the repository linked above.

Essentially, the cat program is based around a single indefinite loop which reads and writes characters. This loop is 4 instructions long, ending with a jump instruction. I decided to keep the same overall framework, but modify loop to print out characters that I'd encode in the data section instead of reading from input. However, the loop can't be longer than 9 instructions without major modifications, because that's the offset between the ASCII codepoints for ! (33) and * (42), which we're using as the loop jump label and the data region label, respectively.

So I needed to find a way to print out an arbitrary byte, using at most 9 instructions. The tools that Dis provides to straightforwardly manipulate values in memory or in the accumulator are as follows:

We can initialize a byte of memory to any of 8 possible values: [33, 42, 62, 94, 95, 123, 124, 125], corresponding to the 8 allowed source-code characters: !*>^_{|}.

>: We can load a byte of memory into the accumulator while tritwise-cyclic-right-rotating it as a 10-trit integer. (TCRR).

|: We can tritwise-subtract-without-carry the current byte of memory from the accumulator. (TSWC)

Note that when printing, the accumulator is converted to the range [0, 255] by a mod-256 operation.

My plan was to have the core loop of the program perform a TCRR load with >, then perform a series of TSWC operations |, and then print out the result. My hope was that with my 8 options for each position in memory, I could generate all possible byte values with a small number of TSWC operations.

After a bit of testing with my Rust program in the repository linked above, I found that I could generate all possible output byte values with one TCRR load and 4 TSWC operations. Those 5 instructions plus a print and a jump to complete the loop made a 7 instruction core loop, and 7 source code bytes to encode each output byte. I used the above Rust program to generate the needed source code, which is given above.

With all that said, here's the instruction-by-instruction breakdown of the code, through the first printout (alternate version):

*^||||||||||||||||||||||||||||||||>||||{^||!___!|_!...
*                                                   Move the data pointer to the start of the data region.
 ^                                                  Jump to the start of the code region
  ||||||||||||||||||||||||||||||||                  Padding before the code region
                                  >                 Load and TCRR.
                                   ||||             Perform 4 TSWCs.
                                       {            Print.
                                        ^           Jump back to the start of the main loop.
                                         ||         Padding before the data region
                                           !        Data for the jump location for the start of the main loop.
                                            ___!|   Encoding of the 1 byte.
                                                 _  No-op while printing
                                                  ! Data for the jump location for the start of the main loop.

*/

const char *
code()
{
	return "*^||||||||||||||||||||||||||||||||>||||{^||!___!|_!___>^_!__>^^_!____>_!|!>>*_!!_{{*_!!_{}*_!!_{|*_!!__}>_!!__|>_!!__{>_!}__>^_!_!>**_!|!!>>_!!_!{{_!!_!{}_!___{*_!___}*_!___|*_!}!>**_!>_{{>_!_!!>*_!__{>*_!__}>*_!__|>*_!{!!**_!!__|*_!!__{*_!_!{|*_!_!{{*_!_!{}*_!__!{>_!__!}>_!__!|>_!__>>^_!_>>^^_!___>>_!_!!{|_!_!!{{_!_!!{}_!!_>^^_!}_!{>_!{!!>>_!}__>>_!}_>>^_!}>>^^_!_{|**_!_{{**_!_{}**_!__!}*_!__!|*_!__!{*_!_>^^*_!___>*_!__>^*_!>_}>>_!!__^*_!!_^^*_!__!!}_!__!!|_!__!!{_!_!>^^_!___!>_!__!>^_!_{{>>_!_{}>>_!_{|>>_!__}**_!__|**_!__{**_!!_{}>_!}!>^^_!}__!>_!}{|>>_!}{{>>_!}{}>>_!!!!**_!{!>**_!|_{**_!___!*_!__!^*_!_!^^*_!_{}>*_!_{|>*_!_{{>*_!__|>>_!__{>>_!__}>>_!___!!_!__!!^_!_!!^^_!_!{}>_!_!{|>_!_!{{>_!}_}>>_!!_!{*_!!_!}*_!___**_!__^**_!_^^**_!!__!>_!!{|>>_!!{{>>_!__>**_!_>^**_!!_!!}_!!_!!|_!!^^**_!!__**_!_!|**_!_!{**_!_!}**_!__!>*_!_!>^*_!}>^**_!>!|>>_!!!^^*_!!__!*_!_!!|*_!_!!{*_!_!!}*_!__!!>_!_!!>^_!}!>^*_!|_|>>_!!!!^^_!!__!!_!____|_!____{_!____}_!_!^**_!!_}>>_!__!**_!!_{>>_!|!!>^_!>!|>*_!}!|>>_!!{}**_!!{|**_!_!!^*_!}!^**_!__!!*_!|_>**_!|>^**_!>!!|>_!_{>>*_!_}>>*_!_|>>*_!____^_!___^^_!______!!_}>*_!!__>>_!!_>>^_!_!{>>_!_!}>>_!_!|>>_!!!!{{_!!_!|>_!!_!{>_!!_!}>_!}__{{_!{_!!>_!_}>**_!_|>**_!_{>**_!!!}>>_!__>>*_!_>>^*_!!__^^_!>___|_!{_>**_!_!}>*_!_!|>*_!_!{>*_!}>>^*_!__!>>_!_!>>^_!___{{_!___{}_!___{|_!_!!}>_!_!!|>_!_!!{>_!!}>>*_!!_!!*_!!!!^*_!{!!{*_!!__{|_!!__{{_!!__{}_!!!!{>_!!!!}>_!!!!|>_!!!>>^_!{!{>>_!!_!>>_!__{{>_!__{}>_!__{|>_!!{>**_!!}>**_!!|>**_!__!^^_!____!_!___!^_!{_!!*_!{!!^*_!}_{}>_!!!{>*_!!!}>*_!!!|>*_!!>>^*_!_!!**_!!_>>*_!{!>>^_!>__|>_!{_!>>_!!___}_!!___|_!!___{_!__^^*_!____*_!___^*_!__!{}_!__!{|_!__!{{_!___|>_!___{>_!___}>_!_!!>>_!!_>**_!!>^**_!{>>^*_!}_!{}_!{_>>*_!!!!}*_!!!!|*_!!!!{*_!_>>**_!!_!>*_!!!>^*_!__{}*_!__{|*_!__{{*_!>___>_!>__>^_!>_>^^_!_!>>*_!}>>**_!^_^^*_!^___*_!|!!**_!|_{{*_!___!{_!";
}

int
main()
{
	puts(code());
	return 0;
}
