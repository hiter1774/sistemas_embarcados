#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
long double Soma1=0, Soma2=0, Soma3=0, Soma4=0;

void* thread1 (void *p)
{
	long int *v = p;
	for(int i = 0 ; i < 12500 ; i++)
		Soma1 += v[i];
	return NULL;
}
void* thread2 (void *p)
{
	long int *v = p;
	for(int i = 12500 ; i < 2*12500 ; i++)
		Soma2 += v[i];
	return NULL;
}
void* thread3 (void *p)
{
	long int *v = p;
	for(int i = 2*12500 ; i < 3*12500 ; i++)
		Soma3 += v[i];
	return NULL;
}
void* thread4 (void *p)
{
	long int *v = p;
	for(int i = 3*12500 ; i < 50000 ; i++)
		Soma4 += v[i];
	return NULL;
}
int main ()
{
	long int v[50000];
	long double Soma = 0;
	
	for(int i = 0 ; i < 50000 ; i++)
		v[i] = random();

	clock_t begin = clock();

	for(int i = 0 ; i < 50000 ; i++)
		Soma += v[i];

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Media: %Le em %f segundos\n", Soma/50000, time_spent);

	begin = clock();

	pthread_t thread_id1;
	pthread_t thread_id2;
	pthread_t thread_id3;
	pthread_t thread_id4;
	pthread_create (&thread_id1, NULL, &thread1, v);
	pthread_create (&thread_id2, NULL, &thread2, v);
	pthread_create (&thread_id3, NULL, &thread3, v);
	pthread_create (&thread_id4, NULL, &thread4, v);
	pthread_join (thread_id1, NULL);
	pthread_join (thread_id2, NULL);
	pthread_join (thread_id3, NULL);
	pthread_join (thread_id4, NULL);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Media: %Le em %f segundos\n", (Soma1+Soma2+Soma3+Soma4)/50000, time_spent);

return 0;
}
