#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>

void print(int arr[], unsigned int sz)
{
    printf("{ %d, ");
    for (unsigned int i = 0; i < sz - 1; ++i)
        printf("%d, ", arr[i]);

    puts("}\n");
}

#endif  /// PRINT_H
