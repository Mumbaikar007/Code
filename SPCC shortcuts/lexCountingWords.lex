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
[\t ''\n] 	{words++;}
%%

int main(){
	printf("Enter a string: \n" );
	yylex();
	printf ("\nWords = %d", words);
	return 0;
}
