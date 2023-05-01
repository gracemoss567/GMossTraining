#include <math.h>
#include <stdlib.h>

#define OFFSET(x, y, m) (((x)*(m)) + (y))

void initialize(double *restrict A, double *restrict Anew, int m, int n) {
    memset(A, 0, n * m * sizeof(double));
    memset(Anew, 0, n * m * sizeof(double));

    // Can you parallelize this loop?
    for (int i = 0; i < m; i++) {
        A[i] = 100.0;
        Anew[i] = 100.0;
    }
}

double calcNext(double *restrict A, double *restrict Anew, int m, int n) {
    double error = 0.0;

    // Implementation here

    return error;
}

void swap(double *restrict A, double *restrict Anew, int m, int n) {
    // Implementation here
}

void deallocate(double *restrict A, double *restrict Anew) {
    free(A);
    free(Anew);
}