#include <stdio.h>
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

void FindWinningAmount() {
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
    for (long target = 100; target <= 1000000000 ; target = target * 10 )
    {
       SetTheNumberToBet(target); 
       FindWinningAmount();
       printf("target:\t%10ld\tmoney\t%10ld\n", target, GetWinningAmount() );
    }
}

void ExecuteGFGTestSuite()
{
    int T = 0 ;
    long N = 0;
    scanf("%d",&T);

    while ( T-- ) {
        scanf("%ld",&N);
        SetTheNumberToBet(N);
        FindWinningAmount();
        printf("%ld\n",GetWinningAmount());
    }
}

int main ()
{
    //OptimizedAlgoTestSuite();
    ExecuteGFGTestSuite();
    return 0;
}
