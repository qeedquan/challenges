/*

Implement your own Semaphore using Mutex and cond variables

*/

#include <stdio.h>
#include <pthread.h>

enum {
	THREADS = 128,
};

typedef struct {
	int value;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} Sem;

Sem sem;
int shared;

void
seminit(Sem *s, int value)
{
	s->value = value;
	pthread_mutex_init(&s->mutex, NULL);
	pthread_cond_init(&s->cond, NULL);
}

void
semup(Sem *s)
{
	if (++s->value <= 0)
		pthread_cond_signal(&s->cond);
	pthread_mutex_unlock(&s->mutex);
}

void
semdown(Sem *s)
{
	pthread_mutex_lock(&s->mutex);
	if (--s->value < 0)
		pthread_cond_wait(&s->cond, &s->mutex);
}

void *
handler(void *arg)
{
	semdown(&sem);
	shared++;
	printf("thread #%d: %d\n", *(int *)arg + 1, shared);
	semup(&sem);
	return NULL;
}

int
main()
{
	pthread_t tid[THREADS];
	int arg[THREADS];
	int i;

	seminit(&sem, 1);
	for (i = 0; i < THREADS; i++) {
		arg[i] = i;
		pthread_create(&tid[i], NULL, handler, &arg[i]);
	}
	for (i = 0; i < THREADS; i++)
		pthread_join(tid[i], NULL);

	return 0;
}
