/*

Similar:
Display words using 7-segment display
Seven Slash Display

My first challenge

Using the box drawing symbols (─│┌┐└┘├┤┬┴┼╴╵╶╷ or ━┃┏┓┗┛┣┫┳┻╋╸╹╺╻) and space ( ), make a display capable of displaying digits 0-9. Note that digit 1 should take up the same amount of space as the others.

The program should be capable of outputting multiple digits. There should be no space between numbers.

Input can be through STDIN or nearest equivalent or through a function. Assume input is an integer. Output the display displaying the input. Trailing whitespace at the end of lines are allowed.

Every digit
(you may use any alternative, but in a single output you may only use 1 alternative)

(your font might make it look misaligned)

 ╷     ┐     ┐
 │ or  │ or  │
 ╵    ╶┴     ╵
╶┐
┌┘
└╴
╶┐
╶┤
╶┘
╷╷
└┤
 ╵
┌╴
└┐
╶┘
┌╴
├┐
└┘
╶┐    ╶┐    ┌┐    ┌┐
 │ or  ┼ or  │ or  ┼
 ╵     ╵     ╵     ╵
┌┐
├┤
└┘
┌┐    ┌┐
└┤ or └┤
 ╵    ╶┘
┌┐
││
└┘
Multidigit example
 ┐╶┐╶┐╷╷
 │┌┘╶┤└┤
╶┴└╴╶┘ ╵
Criteria
This is code-golf, so shortest answer wins.

Bonus
Bonus of 25% bytes removed if program takes two inputs (separated by anything, or in a function); the first is either 0 or 1, and 0 makes it not bold (─│┌┐└┘├┤┬┴┼╴╵╶╷) and 1 makes it bold (━┃┏┓┗┛┣┫┳┻╋╸╹╺╻)

*/

#include <stdio.h>
#include <uchar.h>

void
display(const char *s)
{
	static const char8_t *lut[10][3] = {
		{
		    u8"┌┐",
		    u8"││",
		    u8"└┘",
		},
		{
		    u8" ┐",
		    u8" │",
		    u8" ╵",
		},
		{
		    u8"╶┐",
		    u8"┌┘",
		    u8"└╴",
		},
		{
		    u8"╶┐",
		    u8"╶┤",
		    u8"╶┘",
		},
		{
		    u8"╷╷",
		    u8"└┤",
		    u8" ╵",
		},
		{
		    u8"┌╴",
		    u8"└┐",
		    u8"╶┘",
		},
		{
		    u8"┌╴",
		    u8"├┐",
		    u8"└┘",
		},
		{
		    u8"┌┐",
		    u8" ┼",
		    u8" ╵",
		},
		{
		    u8"┌┐",
		    u8"├┤",
		    u8"└┘",
		},
		{
		    u8"┌┐",
		    u8"└┤",
		    u8"╶┘",
		},
	};

	size_t x, y;

	for (y = 0; y < 3; y++) {
		for (x = 0; s[x]; x++) {
			if ('0' <= s[x] && s[x] <= '9')
				printf("%s", lut[s[x] - '0'][y]);
		}
		printf("\n");
	}
}

int
main()
{
	display("0123456789");
	return 0;
}
