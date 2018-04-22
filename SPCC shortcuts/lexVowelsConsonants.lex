
%option noyywrap

%{
	# include <stdio.h>
	int vowels = 0, consonants = 0;
%}

%%
[AEIOUaeiou]	{ vowels ++; }
[^AEIOUaeiou\n]	{ consonants ++;}
[\n]		{ printf("Vowels = %d, Consonants = %d\n", vowels, consonants);
			vowels = 0; consonants = 0;}	
%%

int main(){
	printf("Enter string: \n");
	yylex();
	return 0;
}	
