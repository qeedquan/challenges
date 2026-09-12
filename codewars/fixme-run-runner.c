/*

The code provided is supposed to execute method1 and method2 in different threads.

But it's not working properly.

Task
Fix the bug so we can all go home early.

Notes
This link won't help solve this Kata, but it may explain my choice of class names.

:-)

*/

#include <stdio.h>
#include <threads.h>

int
f1(void *)
{
	printf("%s:%d\n", __func__, __LINE__);
	return 1;
}

int
f2(void *)
{
	printf("%s:%d\n", __func__, __LINE__);
	return 2;
}

int
main()
{
	thrd_t th[2];

	thrd_create(&th[0], f1, NULL);
	thrd_create(&th[1], f2, NULL);
	thrd_join(th[0], NULL);
	thrd_join(th[1], NULL);
	return 0;
}
