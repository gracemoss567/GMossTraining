#include <stdio.h>
//add code here

//
#include <unistd.h>
#include <time.h>

int main() {

    int array[20];
    time_t start;
    time_t end;

    start = time(NULL);
    // add code here
        
    //          
    for(int i=0; i<sizeof(array)/sizeof(int); ++i) 
    {
        array[i] = i;
        printf("%d\n", array[i]);
        sleep(1);
    }  
    end = time(NULL); 

    printf("took %ld seconds to process\n", end - start);    
    return 0;
}