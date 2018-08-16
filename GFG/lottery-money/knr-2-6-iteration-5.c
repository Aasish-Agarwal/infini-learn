#include <stdio.h>
int setbits(int x , int p , int n , int y)
{
    return (x & ((~0 << p) | ~(~0 << p-n))) | ((y & ~(~0 << n)) << (p-n)) ;
}

void testSetBits(const char* testname ,int x ,int  p ,int  n ,int y ,int expected )
{
	int result = setbits( x , p , n , y);

    if ( result != expected )
    {
        printf("%s: FAIL\n", testname);    
    	printf("\tx = %d , p = %d,  n = %d, y = %d, expected = %d: actual: %d\n",x,p,n,y,expected, result);
    } else 
    {
        printf("%s: SUCCESS\n", testname);
    }
}

void testForSmallNumbers()
{
    int x = 178 , p = 7,  n = 4, y = 219, expected = 218, result = 0;
    testSetBits("Small Numbers <= 8 Bits" ,x , p , n , y, expected);
}

void testForLargeNumbers()
{
    int x = 26421; // 110 0111 0011 0101 
    int y = 9737261; // 1001 0100 1001 0100 0010 1101 
    int p = 12;
    int n = 9;
    int expected = 24941; // 110 0001 0110 1101
    testSetBits("Large Numbers > 8 Bits" ,x , p , n , y, expected);
}

void runTestSuite() 
{
    testForSmallNumbers();
    testForLargeNumbers();
}

void main ()
{
    runTestSuite();
}


