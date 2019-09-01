#include <stdio.h>

void GreetIfStartingWithVowel(char name[]) 
{
	if ( name[0] == 'a' ||
		 name[0] == 'A' ||
		 name[0] == 'e' ||
		 name[0] == 'E' ||
		 name[0] == 'i' ||
		 name[0] == 'I' ||
		 name[0] == 'o' ||
		 name[0] == 'O' ||
		 name[0] == 'u' ||
		 name[0] == 'U'   ) 
	{
		printf("Hello %s\n" , name);
		
		
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
