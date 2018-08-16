#include <stdio.h>
#include <time.h>
#define FIRST_BLOCK_SIZE 3 
#define BLOCK_SIZE_MULTIPLIER 2 

long bettingOnNumber = 0;
long amountWon = 0;
long block_size = 0;
long last_element_of_block = 0;

int NumberToBetIsNotInCurrentBlock() {
    int status = 0;
    if ( bettingOnNumber >  last_element_of_block ) {
        status = 1;
    }
    return status;
}

void MoveToNextBlock() {
    block_size = block_size * BLOCK_SIZE_MULTIPLIER ;
    last_element_of_block = last_element_of_block + block_size;
}

void InitializeFirstBlock() {
    block_size = FIRST_BLOCK_SIZE;
    last_element_of_block = block_size;
}

void CalculateWinningAmount() {
    InitializeFirstBlock();
    while ( NumberToBetIsNotInCurrentBlock() )
    {
        MoveToNextBlock();
    }

    amountWon = last_element_of_block - bettingOnNumber + 1;
}

long GetWinningAmount() {
    return amountWon;
}

void SetTheNumberToBet(long target) {
    bettingOnNumber = target;
}

void OptimizedAlgoTestSuite() {
    printf("%10s\t%10s\t%6s\n","Bet", "Money", "Time" );
    for (long target = 100; target <= 1000000000 ; target = target * 10 )
    {
       SetTheNumberToBet(target); 
       clock_t start = clock(), diff;
       CalculateWinningAmount();
       diff = clock() - start;
       int msec = diff * 1000 / CLOCKS_PER_SEC;
       printf("%10ld\t%10ld\t%3d.%d\n", target, GetWinningAmount(),msec/1000, msec%1000 );
       //printf("target:\t%10ld\tmoney\t%10ld\ttime: %3d sec %3d msec\n", target, GetWinningAmount(),msec/1000, msec%1000 );
    }
}

void ExecuteGFGTestSuite() {
    int T = 0 ;
    long N = 0;
    scanf("%d",&T);

    while ( T-- ) {
        scanf("%ld",&N);
        SetTheNumberToBet(N);
        CalculateWinningAmount();
        printf("%ld\n",GetWinningAmount());
    }
}

int main ()
{
    OptimizedAlgoTestSuite();
    ExecuteGFGTestSuite();
    return 0;
}
