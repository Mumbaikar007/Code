%option noyywrap

%{
	# include <stdio.h>
	# include <stdlib.h>
	int words = 0;
%}

character [a-zA-Z]
digit [0-9]
line \n
word ({character}|{digit})+

%%
[A-Z][A-Za-z0-9]+ 	{words++;}
%%

int main(){
	printf("Enter a string: \n" );
	yylex();
	printf ("Words = %d", words);
	return 0;
}
