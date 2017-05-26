#include "stdio.h" 
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <omp.h>

using namespace std;

typedef unsigned long long int unlong;

unlong number_in_circle = 0;
unlong number_of_tosses_per_thread;


unlong calculate(){

    unlong number_in_circle_in_thread = 0;
    unsigned int rand_state = rand();

    for (unlong i = 0; i < number_of_tosses_per_thread; i++) {
        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y <= 1) 
            number_in_circle_in_thread++;
    }

    /*number_in_circle += number_in_circle_in_thread;*/
    return number_in_circle_in_thread;

}

int main(int argc, char *argv[])
{

    int thread_count = strtol(argv[1], NULL, 10);
    cout<<"thread_count: "<<thread_count<<endl;
    int number_of_tosses = 20;
    number_of_tosses_per_thread = number_of_tosses / thread_count;

    #pragma omp parallel num_threads(thread_count) reduction(+:number_in_circle)
    {
        number_in_circle += calculate();
    }

    cout<<"number_in_circle: "<<number_in_circle<<endl;
    double pi_estimate = (4.0 * (unlong)number_in_circle) / ((unlong)number_of_tosses_per_thread * thread_count); 
    cout<<"pi_estimate: "<<pi_estimate<<endl;

    return(0);
}
