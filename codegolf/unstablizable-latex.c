/*

from Latexmk:

If you use cross-references, you often have to run LaTeX more than once ...

Sometimes cross-referenced location changed and you need to run LaTeX again to create the correct reference. Then something else changed again and you need to run another time. This repeats until the output is stable.

Question: Is it possible to create a LaTeX file that cannot become stable?

*/

#include <stdio.h>

/*

@corvus_192

Writes an expanded \DTMnow (the current date and time) to x.tex. Latexmk tracks this dependency and reruns the compiler.

The tikz package is included to make the compile time be longer than one second on an typical machine.

*/

void
output()
{
	puts("\\documentclass{ncc}\\usepackage{tikz,datetime2}\\global\\let~\\dospecials\\gdef\\dospecials{~\\catcode`|=0}");
	puts("\\begin{filecontents}[force]{x.tex}");
	puts("|DTMnow");
	puts("\\end{filecontents}");
	puts("\\begin{document}\\input{x}\\enddocument");
}

int
main()
{
	output();
	return 0;
}
