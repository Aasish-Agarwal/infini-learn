#include <stdio.h>

char ToLowerCase( char c ) 
{
	if ( c >= 'A' && c <= 'Z')
		c = c + 32;
	return c;
}

void GreetIfStartingWithVowel(char name[]) 
{
	char firstChar = ToLowerCase(name[0]);
	switch ( firstChar ) 
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("Hello %s\n" , name);
			break;
	}
}

void RunTests()
{
	// this must print
	GreetIfStartingWithVowel("amit");
	GreetIfStartingWithVowel("Amit");
	GreetIfStartingWithVowel("elina");
	GreetIfStartingWithVowel("Elina");
	GreetIfStartingWithVowel("isha");
	GreetIfStartingWithVowel("Isha");
	GreetIfStartingWithVowel("omi");
	GreetIfStartingWithVowel("Omi");
	GreetIfStartingWithVowel("udai");
	GreetIfStartingWithVowel("Udai");

	// this must not print
	GreetIfStartingWithVowel(" ajay");
	GreetIfStartingWithVowel("");
	GreetIfStartingWithVowel("Vikas");
}
int main()
{
	RunTests();
	return 0;
}
