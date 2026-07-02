/*

Our nuclear missile manager system is coded in Node.js. We are currently testing the system and it seems that the launchAll function does not work as expected. It should launch 5 missiles each 1 second apart. The current code tries to launch the missile #5 five times...

Can you fix this for us? You know, it's pretty critical code...

Note: There are 5 missiles labeled i which is a number in {0, 1, 2, 3, 4}. The missile i should be launched after i seconds.

*/

#include <stdio.h>
#include <threads.h>

void
launchone(int missile)
{
	printf("Launching: %d\n", missile);
}

void
launchall(void (*launch)(int))
{
	int missile;

	for (missile = 0; missile < 5; missile++) {
		launch(missile);
		thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
	}
}

int
main()
{
	launchall(launchone);
	return 0;
}
