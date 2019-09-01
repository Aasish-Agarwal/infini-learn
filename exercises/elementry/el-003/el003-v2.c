
#include <stdio.h>

void GreetIfStartingWithVowel(char name[]) 
{
	switch ( name[0] ) 
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
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
