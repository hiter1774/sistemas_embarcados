#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
long int max1=0, max2=0, max3=0, max4=0;

void* thread1 (void *p)
{
	long int *v = p;
	for(int i = 0 ; i < 12500 ; i++)
		if(max1 < v[i])
			max1 = v[i];
	return NULL;
}
void* thread2 (void *p)
{
	long int *v = p;
	for(int i = 12500 ; i < 2*12500 ; i++)
		if(max2 < v[i])
			max2 = v[i];
	return NULL;
}
void* thread3 (void *p)
{
	long int *v = p;
	for(int i = 2*12500 ; i < 3*12500 ; i++)
		if(max3 < v[i])
			max3 = v[i];
	return NULL;
}
void* thread4 (void *p)
{
	long int *v = p;
	for(int i = 3*12500 ; i < 50000 ; i++)
		if(max4 < v[i])
			max4 = v[i];
	return NULL;
}
int main ()
{
	long int v[50000], max = 0;
	
	for(int i = 0 ; i < 50000 ; i++)
		v[i] = random();

	clock_t begin = clock();

	for(int i = 0 ; i < 50000 ; i++)
		if(v[i]>max)
			max = v[i];

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Valor maximo: %ld em %f segundos\n", max, time_spent);

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

	if(max2 > max1)
		max1 = max2;
	if(max4 > max3)
		max3 = max4;
	if(max3>max1)
		max1 = max3;

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Valor maximo: %ld em %f segundos\n", max1, time_spent);

return 0;
}
