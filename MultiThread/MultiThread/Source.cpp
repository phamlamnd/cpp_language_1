#include <iostream>
#include <thread>
#include <unistd.h>

//prag: ex1 - begin
void* ham_1(void* loop)
{
	int *count = (int*)loop;
	for (int i = 0; i < *count; i++)
	{
		std::cout << "ham_1: " << i << std::endl;
	}
}

void* ham_2(void* loop)
{
	int *count = (int*)loop;
	for (int i = 0; i < *count; i++)
	{
		std::cout << "ham_2: " << i << std::endl;
	}
}
//prag //ex1 - end

//prag: ex2 - begin
int running_threads = 0;
pthread_mutex_t running_mutex = PTHREAD_MUTEX_INITIALIZER;

void * threadStart(void* data)
{
	std::cout << "threadStart ..." << std::endl;
	pthread_mutex_lock(&running_mutex);
	running_threads--;
	pthread_mutex_unlock(&running_mutex);
}
//prag: ex2 - end

//prag: ex3 - begin
enum {
	STATE_A,
	STATE_B
} state = STATE_A;

pthread_cond_t condA = PTHREAD_COND_INITIALIZER;
pthread_cond_t condB = PTHREAD_COND_INITIALIZER;
pthread_cond_t condEnd = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *threadA(void *data)
{
	int i = 0, loopNum;

	while (i<5)
	{
		/* Wait for state A */
		pthread_mutex_lock(&mutex);
		while (state != STATE_A)
			pthread_cond_wait(&condA, &mutex);
		pthread_mutex_unlock(&mutex);

		//do stuff
		for (loopNum = 1; loopNum <= 5; loopNum++)
			std::cout << "Hello A " << loopNum << std::endl;

		/* Set state to B and wake up thread B */
		pthread_mutex_lock(&mutex);
		state = STATE_B;
		pthread_cond_signal(&condB);
		pthread_mutex_unlock(&mutex);

		i++;
	}

	return 0;
}

void *threadB(void *data)
{
	int n = 0;

	while (n<5)
	{
		/* Wait for state B */
		pthread_mutex_lock(&mutex);
		while (state != STATE_B)
			pthread_cond_wait(&condB, &mutex);
		pthread_mutex_unlock(&mutex);

		//do stuff
		std::cout << "Goodbye A" << std::endl;

		/* Set state to A and wake up thread A */
		pthread_mutex_lock(&mutex);
		state = STATE_A;
		pthread_cond_signal(&condA);
		pthread_mutex_unlock(&mutex);

		n++;
	}

	//pthread_cond_signal(&condEnd);

	return 0;
}
//prag: ex3 - end

int main() {
	//execute: ex1 - begin ---------------------------------
	pthread_t p_thread_1;
	pthread_t p_thread_2;
	int loop = 10;

	//ham_1((void*) &loop);
	//ham_2((void*) &loop);

	pthread_create(&p_thread_1, NULL, ham_1, (void*)&loop);
	pthread_create(&p_thread_2, NULL, ham_2, (void*)&loop);

	pthread_join(p_thread_1, NULL);
	pthread_join(p_thread_2, NULL);
	//execute: ex1 - end ---------------------------------

	//execute: ex2 - begin ---------------------------------
	/*int numb = 4;
	pthread_t p_thread[numb];
	for( int i = 0; i < numb; i++ )
	{
	pthread_create (&p_thread[i], NULL, threadStart, (void*)NULL);
	pthread_mutex_lock(&running_mutex);
	running_threads++;
	pthread_mutex_unlock(&running_mutex);
	}

	while (running_threads > 0)
	{
	sleep(1);
	std::cout << "thread is running..." << std::endl;
	}
	//execute: ex2 - end ---------------------------------

	//execute: ex1 - begin ---------------------------------
	pthread_t a, b;

	pthread_create(&a, NULL, threadA, NULL);
	pthread_create(&b, NULL, threadB, NULL);

	pthread_join(a, NULL);
	pthread_join(b, NULL);
	//pthread_cond_wait(&condEnd, &mutex);

	std::cout << "Finish" << std::endl;*/
	//execute: ex3 - end ---------------------------------

	return 0;
}