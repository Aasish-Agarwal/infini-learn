#include <stdio.h>

int isVowel( char c )
{
	int vowel = 0;
	char vowels[] = "aeiouAEIOU";
	
	for ( int i = 0 ; i < 10 ; i++ )
	{
		if ( vowels[i] == c )
			vowel = 1;
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
