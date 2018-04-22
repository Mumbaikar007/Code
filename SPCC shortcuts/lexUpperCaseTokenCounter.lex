
%option noyywrap

%{
	# include <stdio.h>
	int upperCaseTokens = 0;
%}

%%
[A-Z][A-Za-z0-9]* 	{ printf ("");upperCaseTokens ++; }
[\n]			{ printf ("\nUpper Case Tokens = %d\n", upperCaseTokens); upperCaseTokens = 0; }
%%

int main(){
	printf ("Enter String: ");
	yylex();
	return 0;
}
