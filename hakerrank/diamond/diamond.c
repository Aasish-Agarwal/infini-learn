#include <stdio.h>
void PrintNSpaces(int n) 
{
	while( n-- > 0 )
		printf(" ");
}

void PrintNChars(int n, char symbol) 
{
	while( n-- > 0 )
		printf("%c ",symbol);
	printf("\n");
}

void PrintStar(int starSize, char symbol)
{
	for ( int i = 0 ; i < starSize ; i++) 
	{
		PrintNSpaces(starSize -i -1);
		PrintNChars(i + 1, symbol);
	}

	for ( int i = starSize-1 ; i >= 1 ; i--) 
	{
		PrintNSpaces(starSize -i);
		PrintNChars(i, symbol);
	}
}

void main () 
{
	PrintStar(10,'O');
}
