#include <pthread.h>
	#include <stdio.h>
	#include <unistd.h>

	void* print_xs (void *p)
	{
		int *v = p;

		for(int i = 0 ; i < 10 ; i++)
			printf("%d ", v[i]);

		return NULL;
	}
	int main ()
	{
		int v[10];

		for(int i = 0 ; i < 10 ; i++)
		{
			v[i] = i + 1;
			sleep(1);
		}
		pthread_t thread_id;
		pthread_create (&thread_id, NULL, &print_xs, v);
		pthread_join (thread_id, NULL);

	return 0;
	}
