/*

Given a positive integer millis, write an asyncronous function that sleeps for millis milliseconds. It can resolve any value.

Example 1:

Input: millis = 100
Output: 100
Explanation: It should return a promise that resolves after 100ms.
let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});
Example 2:

Input: millis = 200
Output: 200
Explanation: It should return a promise that resolves after 200ms.


Constraints:

1 <= millis <= 1000

Hint:
In Javascript, you can execute code after some delay with the setTimeout(fn, sleepTime) function.
An async function is defined as function which returns a Promise.
To create a Promise, you can code new Promise((resolve, reject) => {}). When you want the function to return a value, code resolve(value) inside the callback.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <time.h>
#include <errno.h>

int
millisleep(long ms)
{
	struct timespec tp;
	int r;

	tp.tv_sec = ms / 1000;
	tp.tv_nsec = (ms % 1000) * 1000000L;

	do {
		r = clock_nanosleep(CLOCK_MONOTONIC, 0, &tp, &tp);
	} while (r && errno == EINTR);

	return r;
}

int
main(void)
{
	millisleep(100);
	millisleep(200);
	return 0;
}
