/*

You have the four functions:

printFizz that prints the word "fizz" to the console,
printBuzz that prints the word "buzz" to the console,
printFizzBuzz that prints the word "fizzbuzz" to the console, and
printNumber that prints a given integer to the console.
You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

Thread A: calls fizz() that should output the word "fizz".
Thread B: calls buzz() that should output the word "buzz".
Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

"fizzbuzz" if i is divisible by 3 and 5,
"fizz" if i is divisible by 3 and not 5,
"buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.
Implement the FizzBuzz class:

FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
void fizz(printFizz) Calls printFizz to output "fizz".
void buzz(printBuzz) Calls printBuzz to output "buzz".
void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
void number(printNumber) Calls printnumber to output the numbers.


Example 1:

Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
Example 2:

Input: n = 5
Output: [1,2,"fizz",4,"buzz"]


Constraints:

1 <= n <= 50

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
	int n;
	sem_t sem_f;
	sem_t sem_b;
	sem_t sem_fb;
	sem_t sem_n;
} fizzbuzz_t;

void
init(fizzbuzz_t *p, int n)
{
	p->n = n;
	sem_init(&p->sem_f, 0, 0);
	sem_init(&p->sem_b, 0, 0);
	sem_init(&p->sem_fb, 0, 0);
	sem_init(&p->sem_n, 0, 1);
}

void *
fizz(void *ud)
{
	fizzbuzz_t *p;
	int i;

	p = ud;
	for (i = 1; i <= p->n; i++) {
		if (i % 3 == 0 && i % 15 != 0) {
			sem_wait(&p->sem_f);
			printf("fizz\n");
			sem_post(&p->sem_n);
		}
	}
	return NULL;
}

void *
buzz(void *ud)
{
	fizzbuzz_t *p;
	int i;

	p = ud;
	for (i = 1; i <= p->n; ++i) {
		if (i % 5 == 0 && i % 15 != 0) {
			sem_wait(&p->sem_b);
			printf("buzz\n");
			sem_post(&p->sem_n);
		}
	}
	return NULL;
}

void *
fizzbuzz(void *ud)
{
	fizzbuzz_t *p;
	int i;

	p = ud;
	for (i = 1; i <= p->n; ++i) {
		if (i % 15 == 0) {
			sem_wait(&p->sem_fb);
			printf("fizzbuzz\n");
			sem_post(&p->sem_n);
		}
	}
	return NULL;
}

void *
number(void *ud)
{
	fizzbuzz_t *p;
	int i;

	p = ud;
	for (i = 1; i <= p->n; ++i) {
		sem_wait(&p->sem_n);
		if (i % 15 == 0)
			sem_post(&p->sem_fb);
		else if (i % 3 == 0)
			sem_post(&p->sem_f);
		else if (i % 5 == 0)
			sem_post(&p->sem_b);
		else {
			printf("%d\n", i);
			sem_post(&p->sem_n);
		}
	}
	return NULL;
}

int
main(int argc, char *argv[])
{
	pthread_t th[4];
	fizzbuzz_t p;
	int i, n;

	n = 15;
	if (argc >= 2)
		n = atoi(argv[1]);

	init(&p, n);
	pthread_create(th + 0, NULL, fizz, &p);
	pthread_create(th + 1, NULL, buzz, &p);
	pthread_create(th + 2, NULL, fizzbuzz, &p);
	pthread_create(th + 3, NULL, number, &p);
	for (i = 0; i < 4; i++)
		pthread_join(th[i], NULL);

	return 0;
}
