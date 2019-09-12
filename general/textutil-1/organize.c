#include <stdio.h>
#include <ctype.h>

int main ()
{
	char c;
	int inNumber = 0;
	while ( (c = getchar()) != EOF ) 
	{
		if ( !isdigit(c) ) inNumber = 0;
		else if ( !inNumber ) putchar('\n'), inNumber = 1;
		putchar(c);
	}
	return 0;
}

