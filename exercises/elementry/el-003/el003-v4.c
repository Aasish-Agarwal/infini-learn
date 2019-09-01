#include <stdio.h>

int isVowel( char c )
{
	int vowel = 0;
	char vowels[] = "aeiouAEIOU";
	char *p = vowels;
	
	while ( *p ) 
	{
		if ( *p == c )
			vowel = 1;
		p++;
	}
	return vowel;
}

void GreetIfStartingWithVowel(char name[]) 
{
	if ( isVowel(name[0]) ) 
		printf("Hello %s\n" , name);	
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
