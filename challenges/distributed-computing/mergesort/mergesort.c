#include "check.h"
#include "read.h"

#include <mpi.h>
#include <stdio.h>

#define N 1000000

int world_size = 0;
int world_rank = 0;

double input[N] = { 0.0 };

int main()
{
    MPI_Init(NULL, NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    read_input("./unsorted.txt", &input[0], N);

    // Implementation

    MPI_Finalize();

    if (check("sorted.txt", &input[0], N))
        puts("Mergsort ran successfully!");
    else
        puts("Mergsort failed!");

    return 0;
}