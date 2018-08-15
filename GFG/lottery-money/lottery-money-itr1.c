#include <stdio.h>

int main ()
{
    int target = 15;
    int max_m = 3;
    int N = 1;
    int M = max_m;

    while ( N != target ) {
        N++;
        M--;
        if ( M == 0 ) {
            max_m = max_m * 2;
            M = max_m;
        }
    }
    printf("%d\n",M);
    return 0;
}
