/*

Background
Blue Scuti became the first ever human to beat the classic game of Tetris on NES.

Here's the Tetris kill screen

https://i.stack.imgur.com/vVwak.jpg

Challenge
Output the following Tetris kill screen board (10x20 blocks)

EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEEEEEEE
EEEEGGEEEE
EEEEBGGEEE
EBEEBBGGEE
EBEGBBBGBE
EEEEEEEEEE
BBGEBBGGBB
BBBEBBEGBB
BBBBBBBGBE
GGEBBBBBBB
GGEGBGGBBB
BBEBBGGGBB

Code	Color
B	Blue
G	Green
E	Black

Rules
No strict requirement to use the B, G and E characters as long as the kill screen concept is preserved. For example,

██████████
██████████
██████████
██████████
██████████
██████████
██████████
██████████
██████████
████☻☻████
████♥☻☻███
█♥██♥♥☻☻██
█♥█☻♥♥♥☻♥█
██████████
♥♥☻█♥♥☻☻♥♥
♥♥♥█♥♥█☻♥♥
♥♥♥♥♥♥♥☻♥█
☻☻█♥♥♥♥♥♥♥
☻☻█☻♥☻☻♥♥♥
♥♥█♥♥☻☻☻♥♥

*/

#include <stdio.h>

void
killscreen(void)
{
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"████☻☻████");
	printf("%s\n", u8"████♥☻☻███");
	printf("%s\n", u8"█♥██♥♥☻☻██");
	printf("%s\n", u8"█♥█☻♥♥♥☻♥█");
	printf("%s\n", u8"██████████");
	printf("%s\n", u8"♥♥☻█♥♥☻☻♥♥");
	printf("%s\n", u8"♥♥♥█♥♥█☻♥♥");
	printf("%s\n", u8"♥♥♥♥♥♥♥☻♥█");
	printf("%s\n", u8"☻☻█♥♥♥♥♥♥♥");
	printf("%s\n", u8"☻☻█☻♥☻☻♥♥♥");
	printf("%s\n", u8"♥♥█♥♥☻☻☻♥♥");
}

int
main(void)
{
	killscreen();
	return 0;
}
