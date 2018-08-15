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

    diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("target: %10ld\tM: %10ld\t%d seconds\t%3d milliseconds\n",target, M, msec/1000, msec%1000);
}

void BruteForceTestSuite()
{
    printf("\n***************\nBrute Force\n**********\n");
    for (long target = 100; target <= 1000000000 ; target = target * 10 )
    {
       BetWinnerBruteForce(target);
    }
}

void BetWinnerOptimized(long target)
{
    long block_size = 3;
    long last_element_of_block = 3;

    clock_t start = clock(), diff;
    while ( target >  last_element_of_block )
    {
        block_size = block_size * 2 ;
        last_element_of_block = last_element_of_block + block_size;
    }

    long M = last_element_of_block - target + 1;

    diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("target: %10ld\tM: %10ld\t%d seconds\t%3d milliseconds\n",target, M, msec/1000, msec%1000);
}

void OptimizedAlgoTestSuite()
{
    printf("\n***************\nOptimized\n**********\n");
    for (long target = 100; target <= 1000000000 ; target = target * 10 )
    {
       BetWinnerOptimized(target);
    }
}

int main ()
{
    BruteForceTestSuite();
    OptimizedAlgoTestSuite();
    return 0;
}
