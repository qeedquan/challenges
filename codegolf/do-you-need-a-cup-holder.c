/*

You're going to replicate the 90's cup holder joke software.

Here's what's it did, and you have to do:

Display the message Do you need a cup holder?
If the user confirms, enter an infinite loop that keeps opening the CDROM drive.
If the user doesn't confirm, silently exit.
You may display the message using either a console message (confirmation is y, decline is n), or display a message window with the two options "Yes" and "No". You can assume the default (or most common) CDROM drive (D: on Windows, /cdrom on linux etc.). Standard loopholes (except built-ins) are forbidden. No additional input nor output may be involved. If your PC has no physical drive, or another "style" of tray, make sure the program is valid.

code-golf, so shortest program in bytes wins.

Trivia: The loop is there to prevent anyone from closing the drive. On desktop drives, the re-open command will be sent while the drive is closing, therefore staying open and not "spilling the coffee".

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int
main()
{
	char choice;

	printf("Do you need a cup holder? ");
	scanf("%c", &choice);
	if (tolower(choice) != 'y')
		return 1;
	system("eject");
	return 0;
}
