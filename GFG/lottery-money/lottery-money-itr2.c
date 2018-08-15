#include <stdio.h>
#include <time.h>

void BetWinnerBruteForce(long target)
{
    //long target = 1000000;
    long max_m = 3;
    long N = 1;
    long M = max_m;

    clock_t start = clock(), diff;
    while ( N != target ) {
        N++;
        M--;
        if ( M == 0 ) {
            max_m = max_m * 2;
            M = max_m;
        }
    }
    printf("target: %ld\tM: %ld\n",target, M);

    diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds\n", msec/1000, msec%1000);
}

void BruteForceTestSuite()
{
    for (long target = 100; target <= 1000000000 ; target = target * 10 )
    {
       BetWinnerBruteForce(target);
    }
}

int main ()
{
    long block_size = 3;
    long last_element_of_block = 3;
    long target = 15 ;

    while ( target >  last_element_of_block )
    {
        block_size = block_size * 2 ;
        last_element_of_block = last_element_of_block + block_size;
    }

    long M = last_element_of_block - target + 1;
    printf("target: %ld\tM: %ld\n",target, M);    

    return 0;
}
