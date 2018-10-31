%option noyywrap

%{
	# include <stdio.h>
	int upperCase = 0, lowerCase = 0;
%}

%%
[A-Z]		{upperCase++;}
[a-z]		{lowerCase++;}
%%

int main(){
	printf("Enter a string: \n" );
	yylex();
	printf ("\nUpperCase = %d, LowerCase = %d", upperCase, lowerCase);
	return 0;
}
