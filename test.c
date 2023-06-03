#include "includes/philo.h"

int x = 0;

typedef struct asd
{
	pthread_mutex_t *lock;
	int 			*x;
} str;

void	*func(void *arg)
{
	pthread_mutex_lock(((str*)arg)->lock);
	printf("%d\n", x);
	if (x == 1)
		x = 1;
	printf("%d\n", x);
	pthread_mutex_unlock(((str*)arg)->lock);
	return (0);
}

int main()
{
	pthread_t *thread;
	pthread_mutex_t *lock;
	str 	str;


	str.x = &x;
	pthread_mutex_init(lock, NULL);
	str.lock = lock;
	pthread_mutex_lock(lock);
	pthread_create(thread, NULL, func, &str);
	printf("x: %d\n", x);
	pthread_mutex_unlock(lock);
	usleep(10 * 1000);
	printf("x: %d\n", x);
	pthread_join(*thread, NULL);
	return (0);
}
