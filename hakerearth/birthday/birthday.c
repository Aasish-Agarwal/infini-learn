#include <stdio.h>

int getSumOfnSquares(int squares[] , int startingPosition , int numSquares) 
{
    int sum = 0;
    for ( int i = 0 ; i < numSquares ; i++ ) 
    {
        sum += squares[startingPosition + i];
    }
    return sum;
}

int getPossibleCombinatios(int squares[], int n, int d , int m)
{
    int sum = 0 ;

    for ( int startingPosition = 0 ; startingPosition <= n-m ; startingPosition++ )
    {
        if ( getSumOfnSquares( squares , startingPosition , m) == d ) 
        {
            sum++;
        }
    }
    return sum;
}

void executeTest( char *testname , int squares[], int n, int d , int m, int expected)
{
    int actual = getPossibleCombinatios(squares, n, d ,  m);
    
    if ( expected == actual ) {
        printf("%s: Success\n", testname);
    } else {
        printf("%s: Fail\tExpected: %d\tActual: %d\n",testname, expected, actual);
    }
    
}

void runTest2()
{
    int squares[] = {1,2,1,3,2};
    int n = sizeof(squares) / sizeof(int);

    int d = 3;
    int m = 2;
    
    int expected = 2;
    executeTest( "Test 2" ,  squares,  n,  d ,  m, expected);
}

void runTest3()
{
    int squares[] = {1,1,1,1,1};
    int n = sizeof(squares) / sizeof(int);

    int d = 3;
    int m = 2;
    
    int expected = 0;
    executeTest( "Test 3" ,  squares,  n,  d ,  m, expected);
}

void runTest1()
{
    int squares[] = {2,2,5,1,3,4,3,4,5,4};
    int n = sizeof(squares) / sizeof(int);

    int d = 11;
    int m = 4;
    
    int expected = 2;
    executeTest( "Test 1" ,  squares,  n,  d ,  m, expected);
}

int getPossibleCombinatiosFromCmdInput()
{
    int squares[100] = {};
    int n = 0, d = 0, m = 0, possibleCombinations = 0 ;
    // Read Square Count
    scanf("%d", &n);
    // Populate Squares Array
    for (int i = 0 ; i < n ; i++ ) {
        scanf("%d", &squares[i]);
        if ( squares[i] < 1 || squares[i] > 5 ){
            return -1;
        } 
    }
    // Read Birth Day
    scanf("%d", &d);
    // Read Birth Month
    scanf("%d", &m);
    possibleCombinations = getPossibleCombinatios(squares,  n, d ,  m);
    return possibleCombinations;
}



void runTestSuite()
{
    runTest1();
    runTest2();
    runTest3();
}

void main ()
{
    printf( "%d\n", 
        getPossibleCombinatiosFromCmdInput());

}

