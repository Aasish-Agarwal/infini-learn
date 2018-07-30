#include <stdio.h>
int setbits(int x , int p , int n , int y)
{
    int mask = (~0) << p;
    int k = ~((~0) << (p-n));

    mask = mask | k ;
    x = x & mask;

    mask = ~((~0) << n);
    y = (y & mask) << (p-n); 

    return x | y;
}


void main ()
{
	int x = 178 , p = 7,  n = 4, y = 219, expected = 218, result = 0;
	result = setbits( x , p , n , y);
	printf("result: %d\n", result);
}


