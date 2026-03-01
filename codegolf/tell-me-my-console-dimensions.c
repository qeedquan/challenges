/*

Output terminal dimensions (columns and rows) in any two-number decimal format*. For example, an output could be 80x25.

Inspiration. Prompt.

* Output must have both measures on a single or two consecutive lines, and there may be no more than one leading and/or trailing line of output (optionally followed by a newline). The (up to four) lines must be no longer than max(cols,1+len(str(cols))+len(str(ro‌​ws))).

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <err.h>

int
main(void)
{
	struct winsize ws;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) < 0)
		err(1, "ioctl");

	printf("%d %d\n", ws.ws_col, ws.ws_row);
	return 0;
}
