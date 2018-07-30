// Kerninghan & Ritchie/C Programming/2.6

// Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged. 


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


