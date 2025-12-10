#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define REAL_PI 3.141592653589793

/*
    PSUEDO CODE
    estimated_pi = 0

    for i in range (1,n)
        num = 4.0
        denom = 1.0 + ( (i - 0.5) / n) )**2
        estimated_pi += num/denom

    estimated_pi = estimated_pi / n
*/

long double estimate_pi(long N )
{

    long double PI = 0;
    for( long i = 1; i <= N; i ++)
    {
        long double num = 4.0;
        long double denom = 1 + ((i - 0.5) / N)*((i - 0.5) / N) ;

        PI += num  / denom;
    }


    return PI/N;

}


// We will only do the comparison against 15 digits of pi, since thats around
// our limit for long double 
int main(int argc, char* argv[])
{
    clock_t start,end;
    double time_used;
    start = clock();

    if (argc != 2)
    {
        printf("Include one argument for number of iterations");
        return 1;
    }

    long num_iterations = strtol(argv[1], NULL, 10);
    long double real_pi = REAL_PI;
    long double our_pi = estimate_pi(num_iterations);
    long double diff = our_pi - real_pi;


    printf("OUR PI: %.15Lf\n", our_pi);
    printf("REAL PI: %.15Lf\n", real_pi);
    printf("DIFFERENCE: %.15Lf\n", diff );


    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU TIME: %f \n", time_used);
    
    return 0;
}

