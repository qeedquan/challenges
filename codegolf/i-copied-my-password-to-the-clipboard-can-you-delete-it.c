/*

Following the best security practices, I keep a plain text file with my passwords on my hard drive. In fact, I just copied and pasted one of them to access my PPCG account.

In a lucid moment, I decide that the password should better not remain in the clipboard after its use. Since this happens to me often, I could use a program to remove the clipboard contents.
Challenge

Write a program or function that deletes or overwrites any text contained in the clipboard, using a programming language of your choice.

Additional details:

    If your system has several clipboards, you can write the program for any one of them. The only requirement is that it must be possible for the user to copy and paste text using that clipboard.

    If your clipboard keeps a history of recent copied entries, assume the most recent entry.

    If your answer is specific to an operating system or clipboard, indicate it in the title of your post, together with the used language.

    The clipboard is guaranteed to contain text when your program is run. You can either delete the contents from the clipboard, or overwrite it with something else (not necessarily text). The only requirement is that after running the program, pasting from the clipboard will not produce the original text.

    If you choose to overwrite with some fixed or randomly chosen text, you can assume that the previous clipboard contents are different from that text, so the password is effectively removed. In other words, disregard the possibility that the filler text coincides with the password.

    The program should not have any side-effects like restarting the system, closing programs, shutting down the computer, or freezing it. After your program is run, the user should be able to keep using the computer as normal, only with the password removed from the clipboard. Also, standard loopholes are forbidden.

Shortest code in bytes wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <SDL3/SDL.h>

void
fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

int
main(void)
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		fatal("Failed to init SDL");

	if (!SDL_SetClipboardText(""))
		fatal("Failed to set clipboard text");

	return 0;
}
