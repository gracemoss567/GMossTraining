#include <stdio.h>
//add code here


//
#include <unistd.h>
#include <time.h>

int main() {

    int array[20];
    time_t start;
    time_t end;
    int x;
    int sum = 0;

    start = time(NULL);
    //add code here
    
    //              
    for(int i=0; i<sizeof(array)/sizeof(int); ++i) 
    {
        array[i] = i;
        sleep(1);

        //add code here
        x = pow(array[i],2);
        
        //
    }  
    printf("sum of the array is %d\n", sum); 
    if (sum == 2470)
    {
        printf("correct\n");
    }
    else
    {
        printf("wrong answer\n");
    }
    
    end = time(NULL); 

    printf("took %ld seconds to process\n", end - start);    
    return 0;
}