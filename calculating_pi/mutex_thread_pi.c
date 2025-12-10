#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Strategy: Global + Mutex Lock
*/

long chunk_length, num_threads, num_iterations;
long double undivided_partial_sum;


pthread_mutex_t amutex = PTHREAD_MUTEX_INITIALIZER;

void* worker(void * arg)
{
    long id = *(long*)arg;

    long start = id * chunk_length;
    long end = start + chunk_length;


    if (id == num_threads - 1)
    {
        end = num_iterations;
    }

    for (long i = start; i < end; i ++ )
    {
        long double num = 4.0;
        long double denom = 1.0 + ((i - 0.5) / num_iterations)*((i - 0.5) / num_iterations);

        pthread_mutex_lock(&amutex);
        undivided_partial_sum += (num / denom);
        pthread_mutex_unlock(&amutex);


    }

    return NULL;
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage ./prog [num_threads] [num_iterations]");
        return 1;
    }


    num_threads = strtol(argv[1], NULL, 10);
    num_iterations = strtol(argv[2], NULL, 10);
    chunk_length = num_iterations / num_threads;

    // DYNAMICALLY allocate the space for the threads & ids
    pthread_t *thread_arr = malloc(num_threads * sizeof(pthread_t));
    long* thread_ids = malloc( num_threads * sizeof(long));

    // Iterate to create each thread
    for (long i = 0; i < num_threads; i++)
    {
        thread_ids[i] = i;
        pthread_create(&thread_arr[i], NULL, worker, &thread_ids[i]);
    }

    
    // Join them
    for (long i = 0; i < num_threads; i++)
    {
        pthread_join(thread_arr[i], NULL);
    }

    long double sum = undivided_partial_sum / num_iterations;
    printf("OUR PI: %.15Lf\n", sum);


    // Free stuff
    free(thread_arr);
    free(thread_ids);

    pthread_mutex_destroy(&amutex);



    return 0;

}



