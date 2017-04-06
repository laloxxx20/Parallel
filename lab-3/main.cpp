// Exercises
/*1.- If we use strlen(greeting) instead strlen(greeting) + 1 we going to lose one last element.
    If we use MAX_LENGH instead strlen(greeting) + 1 we going to get garbage of rest of array because strlen function just get the text inside Char **/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void integral()
{
    /*
    int my_rank, comm_sz, n = 1024, local_n;
    double a = 0.0, b = 3.0, h, local_a, local_b;
    double local_int, total_int;
    int source;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    h = (b − a)/n;
    int local_n = n/comm_sz;

    int local_a = a + my_rank ∗ local n∗h;
    int local_b = local_a + local_n∗h;
    int local_int = Trap(local_a, local_b, local_n, h);
    if (my_rank != 0) {
    MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0,
    MPI_COMM_WORLD);
    } else {
        int total_int = local_int;
        for (source = 1; source < comm_sz; source++) {
            MPI_Recv(&local int, 1, MPI_DOUBLE, source, 0,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_int += local_int;
        }
    }
    if (my_rank == 0) {
    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.15e\n", a, b, total_int);
    }

    MPI_Finalize();
    */
}

int main(void) {
    
    // integral();
    return 0;
}
