%option noyywrap

%{
	# include <stdio.h>
	# include <stdlib.h>
	int lines = 0;
%}

character [a-zA-Z]
digit [0-9]
line \n
word ({character}|{digit})+

%%
{line}		{lines++;}
%%

int main(){
	printf("Enter a string: \n" );
	yylex();
	printf ("\nLines = %d", lines);
	return 0;
}
