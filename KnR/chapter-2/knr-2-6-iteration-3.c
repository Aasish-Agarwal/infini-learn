#include <stdio.h>
int setbits(int x , int p , int n , int y)
{
	int mask = 0;
	mask = ~mask;
	mask = mask << p;
	
	int k = ~0;
	k = k << (p-n);
	k = ~k;
	
	mask = mask | k ;

	x = x & mask;

    mask = ~0;
    mask = mask << n;
    mask = ~mask;
    y = y & mask; 
    y = y << (p-n); 
    
    int result = x | y;
	return result;
}


void main ()
{
	int x = 178 , p = 7,  n = 4, y = 219, expected = 218, result = 0;
	result = setbits( x , p , n , y);
	printf("result: %d\n", result);
}


